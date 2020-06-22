#pragma once

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;
	pair<K, V> _kv;

	AVLTreeNode(const pair<K,V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_bf(0)
		,_kv(kv)
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<const K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		//按搜索树规则插入值
		if (root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}

			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return fasle;
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		//更新平衡因子
		//a.右树平衡因子变化，父节点+1，左树变化，父节点-1
		//b.父节点平衡因子更新完1/-1，说明父节点平衡因子变化，继续向上更新
		//c.父节点平衡因子更新完成2/-2，说明父亲所在的树已经不平衡，需要旋转
		//d.父节点平衡因子更新完成0，说明父亲所在的树高度没有变化

		while (parent)
		{
			if (cur == parent->_right)
				parent->_bf++;
			else if (cur == parent->_left)
				parent->_bf--;
			if (parent->_bf == 0)
			{
				break;
			}
			else if (abs(parent->_bf) == 1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				//说明树已经不平衡需要旋转
				if (cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (cur->_bf == 1)
				{
					RotateL(parent);
				}
			}
			break;
			else
			{
				assert(false);
			}
		}
		return true;
	}
	//左单旋
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

		if (parent == _root)//说明parent就是根节点
			_root = subR;
			subR->_parent = nullptr;
		else
		{
			if (ppNode->left == parent)
				ppNode->_left = subR;
			else
				ppNode->_right = subR;

			subR->_parent = ppNode;
		}
		//将平衡因子重置
		subR->_bf = parent->_bf = 0;
	}

	//右单旋
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* ppNode = parent->_parent;
		if (parent = _root)
			_root = subL;
			subL->_parent = nullptr;
		else
		{
			if (ppNode->_left = parent)
				ppNode->_left = subL;
			else
				ppNode->_right = subL;

			subL->_parent = ppNode;
		}
		parent->_bf = subL->_bf = 0;
	}

	//双旋，新插入节点在较高左子树的右侧 左右
	void RotateLR(Node* parent)
	{
		RotateL(parent->_left);
		RotateR(parent);
	}

	//双旋，新插入节点在较高右子树的左侧 右左
	void RotateLR(Node* parent)
	{
		RotateR(parent->_right);
		RotateL(parent);
	}
private:
	Node* _root = nullptr;
};
