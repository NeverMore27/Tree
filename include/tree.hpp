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
		void show(ostream &out, int level) const;
	};

	Node *root;
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
	Node *  find_(const T &value) const
	{

		Node *tr = root;
		while (tr)
		{
			if (tr->value_ != value)
			{
				if (value < tr->value_)
					tr = tr->left;
				else tr = tr->right;
			}
			else break;
		}
		if (!tr) return nullptr;
		else return tr;
	}
	void add_node(Node *&add_n, T value)
	{
		add_n = new Node(value);
		add_n->left = nullptr;
		add_n->right = nullptr;

	}
	Node* add_(const T &value, Node * tr = 0)
	{
		
		if (!root)
		{
			root = new Node(value);
			root->left = nullptr;
			root->right = nullptr;
			return root;
		}
		if (!tr) tr = root;
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
	int count(Node* tr) const
	{
		if (!tr) return 0;
		int l = 0, r = 0;
		if (tr->left) l = count(tr->left);
		if (tr->right) r = count(tr->right);
		return l + r + 1;
	}
	void print_pre(const Node * tr, std::ofstream &file) const
	{
		try
		{
			if (!tr) throw 1;
		}
		catch (int)
		{
			return;
		}
		file << tr->value_ << "  ";
		if (tr->left)
			print_pre(tr->left, file);
		if (tr->right)
			print_pre(tr->right, file);
	}
	bool Delete(Node **Tree, T &value)
	{
		Node *tr;

		if (*Tree == nullptr) return false;
		if (find(value)==0) return false;
		else
			if (value<(**Tree).value_) Delete(&((**Tree).left), value);
			else
				if (value>(**Tree).value_) Delete(&((**Tree).right), value);
				else {
					tr = *Tree;
					if ((*tr).right ==nullptr) { *Tree = (*tr).left; delete tr; }
					else
						if ((*tr).left == nullptr) { *Tree = (*tr).right; delete tr; }
						else Delete_(&((*tr).left), &tr);
				}
		return true;
	}
	void Delete_(Node **r, Node **tr)
	{
		
		if ((**tr).right != nullptr)
		{
			Node* min; T val_;
			min = (*tr)->right;
			while (min->left)
				min = min->left;
			val_ = min->value_;
			del( min->value_);
			(**tr).value_ = val_;
		}
	}
	bool isEqual(Node* root2, const Node* root1)
	{
		return (root2&&root1 ? root2->value_ == root1->value_&&isEqual(root2->left, root1->left) && isEqual(root2->right, root1->right) : !root2 && !root1);
	};

public:
	Tree()
	{
		root = nullptr;
	};
	Tree(std::initializer_list<T> list)
	{
		root = nullptr;
		for (auto& item : list)
		{
			add(item);
		}

	}
	~Tree()
	{
		null_tree(root);
	};
	Node* tree_one()
	{
		return root;
	};
	void file_tree(char* name);
	bool add(const T &value);
	bool find(const T &value);
	void print(ostream &out) const;
	int count_() const;
	bool isEmpty()
	{
		Node* root1 = nullptr;
		return isEqual(root, root1);
	}
	bool operator ==(const Tree<T> &a)
	{
		
		return isEqual(root, a.root);
	}
	bool del(T value) 
	{

		return Delete(&root, value);
	}
	void pr(char* name) const;
};
	template <class T>
	void Tree<T>::pr(char* name) const
	{
		ofstream file(name);
		if (file.is_open())
		{
			file << count_() << " ";
			print_pre(root, file);

			file.close();
		}
	}
	template <class T>
	int Tree<T>::count_() const
	{
		return count(root);
	}
	template <class T>
	void  Tree<T>::print(ostream &out) const
	{
		root->show(out, 0);
	}
	template <class T>
	void Tree<T>::Node::show(ostream &out, int level) const
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
	bool Tree<T>::add(const T &value)
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
		else {
			throw "";
		}
	}	
	template <class T>
	bool Tree<T>::find(const T &value)
	{
		Node *tr = find_(value);
		if (tr) return true;
		else    return false;
}
