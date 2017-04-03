#include "tree.hpp"

template <class T>
void  Tree<T>::print(ostream &out) const
{
	tree->show(out);
}
template <class T>
void Tree<T>::Node::show(ostream &out, const int level = 0) const
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