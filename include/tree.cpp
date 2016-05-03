#include "tree.h"  
template <class T>
Tree<T>::der::der(T x) : D(x), l(nullptr), r(nullptr){}
template <class T>
void Tree<T>::der::Insert(T x){
	if (x < D){
		if (l != nullptr) l->Insert(x);
		if (l == nullptr) l = new der(x);
	}
	if (x>D){
		if (r != nullptr) r->Insert(x);
		if (r == nullptr) r = new der(x);
	}
}
template <class T>
bool Tree<T>::der::Search(T x){
	if (x == D) { return true; }
	if (x > D) if (r != nullptr) return(r->Search(x));
	if (x < D) if (l != nullptr) return(l->Search(x));
	return false;
}
template <class T>
bool Tree<T>::der::print_console(){
	if (this != nullptr){
		if (l != nullptr) l->print_console();
		cout << D << " ";
		if (r != nullptr) r->print_console();
		return true;
	}
	else return false;
}
template <class T>
bool Tree<T>::der::print_file(ofstream &fout){
	if (this != nullptr){
		if (fout.is_open()){
			if (l != nullptr) l->print_file(fout);
			fout << D << " ";
			if (r != nullptr) r->print_file(fout);
		}
		return true;
	}
	return false;
}

template <class T>
Tree<T>::Tree() : root(nullptr){}
template <class T>
bool Tree<T>::Insert(T x){
	if (root != nullptr) if (Search(x)) throw Exist();
	if (root == nullptr) { root = new der(x); return true; }
	else { root->Insert(x); return true; }
	return false;
}
template <class T>
bool Tree<T>::Search(T x){
	if (root == nullptr) throw Empty();
	return(root->Search(x));
}


template <class T>	
	ostream & operator <<(ostream & os, Tree<T> & x) {
		if (x.root == nullptr) {
			throw Empty();
		}
		x.root->print_file(os);

		return os;
	}

	template <class T>	
	istream & operator >>(istream & input, Tree<T> & x) {
		T temp;
		if (x.count == 0) {
			throw Empty();
		}
		else {
			for (size_t i = 0; i < x.count; ++i) {
				if (input >> temp) {
					x.Insert(temp);
				}
				else {
					throw File_Not_Open();
				}
			}
			return input;
		}
	}

	template <class T>	
	fstream & operator <<(fstream &file, Tree<T> & x) {
		if (x.count == 0) {
			throw Empty();
		}
		x.root->print_file(file);

		return file;
	}

	template <class T>	
	fstream & operator >>(fstream &file, Tree<T> & x) {
		T temp;
		if (x.count == 0) {
			throw Empty();
		}
		else {
			for (size_t i = 0; i < x.count; ++i) {
				if (file >> temp) {
					x.Insert(temp);
				}
				else {
					throw File_Not_Open();
				}
			}
			return file;
		}
	}
