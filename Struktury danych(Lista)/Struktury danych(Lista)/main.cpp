#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <list>

using namespace std;

template<typename T>
struct Node
{
	Node(T d, Node<T>* n) : data(d), next(n) {};
	
	T data;
	Node* next = nullptr;
};

template<typename T>
class List
{
public:
	void PushTop(T elem);
	void PopTop();
	int Find(T elem);
	void Remove(T elem);
	void PushBack(T elem);
	void PopBack();
	int Size();
	void Display();

private:
	Node<T>* m_head = nullptr;
	int size = 0;
};

int main()
{
	List<int> MyList;

	MyList.PushTop(1);
	MyList.PushTop(2);
	MyList.PushTop(3);

	MyList.Display();

	MyList.PopTop();
	MyList.PopTop();
	MyList.Display();

	MyList.PopTop();
	MyList.PopTop();
	MyList.Display();

	MyList.Size();

	return 0;
}

template<typename T>
void List<T>::PushTop(T elem)
{
	Node<T>* NewElem = new Node<T>(elem, m_head);
	m_head = NewElem;
	size++;
}

template<typename T>
void List<T>::PopTop()
{
	if (m_head != nullptr)
	{
		Node<T>* temp = m_head->next;
		delete m_head;
		m_head = temp;
		size--;
	}
	
	
}

template<typename T>
int List<T>::Size()
{
	return size;
}

template<typename T>
void List<T>::Display()
{
	Node<T>* current = m_head;

	while (current != nullptr)
	{
		cout << current->data << endl;
		current = current->next;
	}
}
