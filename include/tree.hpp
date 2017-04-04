
#include <fstream>
#include <iostream>

using namespace std;

template <class T>
class Tree
{
private:
	struct Node

	{

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
template <class T>
void  Tree<T>::print(ostream &out) const
{
	tree->show(out, 0);
}
template <class T>
void Tree<T>::Node::show(ostream &out, const int level) const
{
	const Node *tr = this;
	if (tr) tr->right->show(out, level + 1);
	for (int i = 0; i<level; i++)
		out << "   ";
	if (tr) out << tr->value_ << endl;
	else out << "End" << endl;
	if (tr) tr->left->show(out, level + 1);
}
template <class T>
bool Tree<T>::add(const T value)
{
	Node *tr = add_(value);
	if (tr) return true;
	else    return false;
}
template <class T>
void Tree<T>::file_tree(char* name)
{
	ifstream file(name);
	if (file.is_open())
	{
		int i_max;
		file >> i_max;
		for (int i = 0; i < i_max; ++i)
		{
			T node;
			file >> node;
			add(node);
		}
		file.close();
	}
}
template <class T>
bool Tree<T>::find(const T value)
{
	Node *tr = find_(value);
	if (tr) return true;
	else    return false;
}
