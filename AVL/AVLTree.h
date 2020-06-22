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
		//���������������ֵ
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

		//����ƽ������
		//a.����ƽ�����ӱ仯�����ڵ�+1�������仯�����ڵ�-1
		//b.���ڵ�ƽ�����Ӹ�����1/-1��˵�����ڵ�ƽ�����ӱ仯���������ϸ���
		//c.���ڵ�ƽ�����Ӹ������2/-2��˵���������ڵ����Ѿ���ƽ�⣬��Ҫ��ת
		//d.���ڵ�ƽ�����Ӹ������0��˵���������ڵ����߶�û�б仯

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
				//˵�����Ѿ���ƽ����Ҫ��ת
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
	//����
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

		if (parent == _root)//˵��parent���Ǹ��ڵ�
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
		//��ƽ����������
		subR->_bf = parent->_bf = 0;
	}

	//�ҵ���
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

	//˫�����²���ڵ��ڽϸ����������Ҳ� ����
	void RotateLR(Node* parent)
	{
		RotateL(parent->_left);
		RotateR(parent);
	}

	//˫�����²���ڵ��ڽϸ������������ ����
	void RotateLR(Node* parent)
	{
		RotateR(parent->_right);
		RotateL(parent);
	}
private:
	Node* _root = nullptr;
};
