#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List {
public:
	List();
	~List();
	
	void conclude(List<T> A);
	void input_list();
	void push_front(T data);
	void pop_front();
	void clear();
	int GetSize() { return Size; }
	T& operator[](const int index);

private:
	template<typename T>
	class Node {
	public:
		Node *pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T> *Head;
};

template<typename T>
List<T>::List() {
	Size = 0;
	Head = nullptr;
}
template<typename T>
List<T>::~List() {
}

template<typename T>
void List<T>::conclude(List<T> A)
{
	Node<T>* current = this->Head;
	while (current->pNext != nullptr) {
		current = current->pNext;
	}
	Node<T>* end_list1 = current;
	
	end_list1->pNext = A.Head;
	this->Size = this->Size + A.Size;
}

template<typename T>
void List<T>::input_list()
{
	int numb;
	int value;
	cout << "Enter number of Nodes in list: "; cin >> numb;
	for (int i = 0; i < numb; i++) {
		cout << "Enter value to put in Node Data: "; cin >> value;
		push_front(value);
	}
	cout << endl;
}

template<typename T>
void List<T>::push_front(T data)
{
	Head = new Node<T>(data, Head);
	Size++;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = Head;
	Head = Head->pNext;
	delete temp;

	Size--;
}

template<typename T>
void List<T>::clear()
{
	while (Size) {
		pop_front();
	}
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T> *current = this->Head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void print_nodes(List<T> A) {
	for (int i = 0; i < A.GetSize(); i++) {
		cout << "\t" << A[i] << endl;
	}
	cout << endl;
}



int main() {
	List<int> lst;
	List<int> lst2;
	lst.input_list();
	cout << "This is List1 of Nodes before adding element: \n" << endl;
	print_nodes(lst);
	lst2.input_list();
	cout << "This is List2 of Nodes before adding element: \n" << endl;
	print_nodes(lst2);
	lst.conclude(lst2);
	cout << "This is List1 connected with List2: \n" << endl;
	print_nodes(lst);
	lst.push_front(100);
	lst.push_front(86);
	cout << "This is List1 of Nodes after adding elements: \n" << endl;
	print_nodes(lst);
	lst.pop_front();
	cout << "This is List1 of Nodes after deleting top element: \n" << endl;
	print_nodes(lst);

	return 0;
}