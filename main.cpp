#include <iostream>

using namespace std;

class BST {

public:


	void Inserare(int n);
	void Afisare();
	BST() {
		root = NULL;
	}

	void Stergere(int s);

private:

	struct Tree {
		int numar;
		Tree* left;
		Tree* right;
	};
	typedef Tree* pointer;
	pointer root,aux;
	void InserarePrivate(int n, pointer ptr);
	pointer Make(int a);
	void AfisarePrivate(pointer aux);
	void StergerePrivate(int s, pointer ptr,pointer temp);



};

int main() {
	BST bst;
	int v[16] = { 50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};

	for (int i = 0; i < 16; ++i) {
		bst.Inserare(v[i]);
	}
	bst.Afisare();
	//bst.Inserare();
	bst.Stergere(50);
	cout << endl;
	bst.Afisare();
	cin.sync(); cin.ignore();
}
void BST::Inserare(int n) {
	InserarePrivate(n, root);
}

void BST::InserarePrivate(int n,pointer ptr) {
	pointer c = new Tree;
	if (ptr == NULL) {
		ptr = c;
		ptr->numar = n;
		ptr->right = NULL;
		ptr->left = NULL;
		root = ptr;

	}
	else if (n > ptr->numar) {
		if (ptr->right != NULL) {
			InserarePrivate(n, ptr->right);
		}
		else {
			ptr->right = Make(n);
		}
	}
	else {
		if (ptr->left != NULL) {
			InserarePrivate(n, ptr->left);
		}
		else {
			ptr->left = Make(n);
		}
	}

}

BST::pointer BST::Make(int a){
	pointer c = new Tree;
	c->numar = a;
	c->left = NULL;
	c->right = NULL;

	return c;
}

void BST::Afisare() {
	AfisarePrivate(root);
}

void BST::AfisarePrivate(pointer aux) {

	if (aux != NULL) {
		if (aux->left != NULL) {
			AfisarePrivate(aux->left);
		}
		cout << aux->numar << " ";
		if (aux->right != NULL) {
			AfisarePrivate(aux->right);
		}
	}
	else {
		cout << "[Arborele este gol]";
	}
}

void BST::Stergere(int s) {
	StergerePrivate(s, root,root);
}

void BST::StergerePrivate(int s, pointer ptr, pointer temp) {

	pointer aux = ptr, del = NULL, tempa = temp,tempb=NULL,tempc=NULL;

	if ((s > aux->numar) && (aux->right != NULL)) {

		StergerePrivate(s, aux->right, aux);

	}
	else if ((s < aux->numar) && (aux->left != NULL)) {

		StergerePrivate(s, aux->left, aux);
	}
	else if (s == aux->numar) {
		if (aux->left == NULL && aux->right == NULL) {

			del = aux;

			if (temp->right == aux) {
				delete del;
				tempa->right = NULL;
			}
			else {
				delete del;
				tempa->left = NULL;
			}

		}
		else if (aux->left != NULL && aux->right == NULL) {
			del = aux;
			if (tempa->right == aux) {
				tempa->right = aux->left;
				delete del;
			}
			else if (tempa->left == aux) {
				tempa->left = aux->left;
				delete del;
			}
			else if (aux->left == NULL && aux->right != NULL) {
				del = aux;
				if (tempa->right == aux) {
					tempa->right = aux->right;
					delete del;
				}
				else if (tempa->left == aux) {
					tempa->left = aux->right;
					delete del;
				}
			}

		}
		else if (aux->left != NULL && aux->right != NULL) {

			tempb = ptr->right;
			while (tempb->left != NULL) {
				tempc = tempb;
				tempb = tempb->left;
				//cout << "tempc= " << tempc->numar << "tempb= " << tempb->numar << endl;
			}

			aux->numar = tempb->numar;

			del = tempb;
			delete del;
			tempc->left = NULL;

		}
	}
}
