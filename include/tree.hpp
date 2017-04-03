
#include <fstream>
#include <iostream>

using namespace std;

template <class T>
class Tree
{
private:
	struct Node

	{
		friend class B_tree;

		T value_;
		Node *left;
		Node *right;
		Node() {};
		Node(const T value) : value_(value) { };
		~Node() {};
		void show(ostream &out, const int level) const;
	};

	Node *tree, *null_tr;
	void null_tree(Node *tr_)
	{
		if (!tr_) return;
		if (tr_->left)
		{
			null_tree(tr_->left);
			tr_->left = nullptr;
		}
		if (tr_->right)
		{
			null_tree(tr_->right);
			tr_->right = nullptr;
		}
		delete tr_;
	}
	Node * & find_(const T value)
	{

		Node *tr = tree;
		while ((tr) && (tr->value_ != value))
		{
			if (value < tr->value_)
				tr = tr->left;
			else tr = tr->right;
		}
		if (!tr) return null_tr;
		else return tr;
	}
	void add_node(Node *&add_n, T value)
	{
		add_n = new Node(value);
		add_n->left = nullptr;
		add_n->right = nullptr;

	}
	Node* add_(const T value, Node * tr = 0)
	{
		if (!tree)
		{
			tree = new Node(value);
			tree->left = nullptr;
			tree->right = nullptr;
			return tree;
		}
		if (!tr) tr = tree;
		if ((tr) && (tr->value_ != value))

		{
			if (value < tr->value_)

			{
				if (tr->left)
					add_(value, tr->left);
				else
				{
					add_node(tr->left, value);
					return tr->left;
				}
			}

			else
			{
				if (tr->right)
					add_(value, tr->right);
				else
				{
					add_node(tr->right, value);
					return tr->right;
				}
			}
		}
		return 0;
	}
public:
	Tree()
	{
		tree = NULL;
		null_tr = nullptr;
	};

	void file_tree(char* name);
	Node* tree_one ()
	{
		return tree;
	};
	bool add(const T value);
	bool find(const T value);
	void print(ostream &out) const;
	~Tree()
	{
		null_tree(tree);
		null_tree(null_tr);
	};
};
