#pragma once
#pragma once

enum Colour
{
	BLACK,
	RED,
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;

	T _data;

	Colour _col;

	RBTreeNode(const T& data)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(RED)
	{}
};

template<class T, class Ref, class Ptr>
struct __TreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __TreeIterator<T, Ref, Ptr> Self;
	Node* _node;

	__TreeIterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	Self& operator++()
	{
		// 1、如果右不为空，中序的下一个就是右子树的最左节点
		// 2、如果右为空，表示_node所在的子树已经访问完成,在一个节点在他的祖先中找
		//  沿着路径往上找孩子是它的左的那个祖先
		if (_node->_right)
		{
			Node* subLeft = _node->_right;
			while (subLeft->_left)
			{
				subLeft = subLeft->_left;
			}

			_node = subLeft;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}

			_node = parent;
		}

		return *this;
	}

	Self& operator--()
	{
		// ...
		return *this;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

	bool operator==(const Self& s)
	{
		return _node == s._node;
	}
};

template<class K, class T, class KOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef __TreeIterator<T, T&, T*> iterator;
	typedef __TreeIterator<T, const T&, const T*> const_iterator;

	iterator begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}

		return iterator(cur);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	pair<iterator, bool> Insert(const T& data)
	{
		// 1、按搜索树的规则进行插入
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}

		KOfT koft;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (koft(cur->_data) < koft(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (koft(cur->_data) > koft(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(iterator(cur), false);
			}
		}

		cur = new Node(data);
		Node* newnode = cur;
		if (koft(parent->_data) < koft(cur->_data))
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		// 新增节点红的
		cur->_col = RED;
		while (parent && parent->_col == RED)
		{
			// 红黑色的条件关键看叔叔
			Node* grandfther = parent->_parent;
			if (grandfther->_left == parent)
			{
				Node* uncle = grandfther->_right;
				// 情况1：uncle存在，且为红
				// 情况2 or 情况3：uncle不存在 or uncle存在，且为黑
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfther->_col = RED;

					// 继续往上处理
					cur = grandfther;
					parent = cur->_parent;
				}
				else
				{
					// 情况三：双旋 -> 变为单旋
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(parent, cur);
					}

					// 第二中情况(ps：有可能是第三种变过来的)
					RotateR(grandfther);
					grandfther->_col = RED;
					parent->_col = BLACK;

					break;
				}
			}
			else
			{
				Node* uncle = grandfther->_left;
				// 情况1：uncle存在，且为红
				// 情况2 or 情况3：uncle不存在 or uncle存在，且为黑
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfther->_col = RED;

					cur = grandfther;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(parent, cur);
					}

					RotateL(grandfther);
					grandfther->_col = RED;
					parent->_col = BLACK;
				}
			}
		}

		_root->_col = BLACK;

		return make_pair(iterator(newnode), true);
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subR;

		// 1、原来parent是这颗树的跟，现在subR是根
		// 2、parent为根的树只是整颗树中的子树，改变链接关系，那么subR要顶替他的位置
		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subR;
			else
				ppNode->_right = subR;

			subR->_parent = ppNode;
		}
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subL;

		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subL;
			else
				ppNode->_right = subL;

			subL->_parent = ppNode;
		}
	}


	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		//cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	bool IsValidRBTree()
	{
		Node* pRoot = _root;
		// 空树也是红黑树
		if (nullptr == pRoot)
			return true;

		// 检测根节点是否满足情况
		if (BLACK != pRoot->_col)
		{
			cout << "违反红黑树性质二：根节点必须为黑色" << endl;
			return false;
		}

		// 获取任意一条路径中黑色节点的个数
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->_col)
				blackCount++;

			pCur = pCur->_left;
		}

		// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}

	bool _IsValidRBTree(Node* pRoot, size_t k, const size_t blackCount)
	{
		//走到null之后，判断k和black是否相等
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
				return false;
			}
			return true;
		}

		// 统计黑色节点的个数
		if (BLACK == pRoot->_col)
			k++;

		// 检测当前节点与其双亲是否都为红色
		Node* pParent = pRoot->_parent;
		if (pParent && RED == pParent->_col && RED == pRoot->_col)
		{
			cout << "违反性质三：没有连在一起的红色节点" << endl;
			return false;
		}

		return _IsValidRBTree(pRoot->_left, k, blackCount) &&
			_IsValidRBTree(pRoot->_right, k, blackCount);
	}

	iterator Find(const K& key)
	{
		KOfT koft;
		Node* cur = _root;
		while (cur)
		{
			if (koft(cur->_data) < koft(data))
			{
				cur = cur->_right;
			}
			else if (koft(cur->_data) > koft(data))
			{
				cur = cur->_left;
			}
			else
			{
				return iterator(cur);
			}
		}

		return iterator(nullptr);
	}

private:
	Node* _root = nullptr;
};
