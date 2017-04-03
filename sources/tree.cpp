#include "tree.hpp"


template <class T>
void  Tree<T>::print(ostream &out) const
{
	tree->show(out);
}
template <class T>
void Tree<T>::Node:: show(ostream &out, const int level = 0) const
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
void Tree<T>:: add(const T d)

{
	Node* t = new Node;
	Node* parent;
	t->value_ = d;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;
	if (isEmpty()) tree = t;
	else
	{
	
		Node* curr;
		curr = tree;
	
		while (curr)
		{
			parent = curr;
			if (t->value_ > curr->value_) curr = curr->right;
			else curr = curr->left;
		}

		if (t->value_ < parent->value_)
			parent->left = t;
		else
			parent->right = t;
	}
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
bool Tree<T>::find(const T d) 

{
	bool found = false;
	Node* curr;
	Node* parent;
	curr = tree;
	parent = (Node*)NULL;
	while (curr != NULL)
	{
		if (curr->value_ == d)
		{
			found = true;
			break;
		}
		else
		{
			parent = curr;
			if (d>curr->value_) curr = curr->right;
			else curr = curr->left;
		}
	}
	return found;

}
