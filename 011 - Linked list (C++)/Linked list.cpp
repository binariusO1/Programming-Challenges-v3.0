/*
Programing challenge
2020-05-10 binariusO1
Linked-list
With implement "The rule of three"

Warning	C26444	Avoid unnamed objects with custom construction and destruction (es.84)

*/
#pragma once

//#define DEBUG

#ifdef DEBUG
#include <iostream>
using namespace std;
#endif // DEBUG

template <class T>
class Linked_list
{
private:
	struct node
	{
		T value;
		node* next;
		//node() : next(nullptr) , value(NULL)
		//{}
	};
public:
	//#############################################################################################
	//										CONSTRUCTORS
	//#############################################################################################
	Linked_list();
	Linked_list(const size_t s);
	Linked_list(const Linked_list<T>& obj);
	~Linked_list();

	//#############################################################################################
	//										ADDON, DELETE
	//#############################################################################################
	void AddNode();
	void AddNode(const T& val);
	void InsertStart(const T& val);
	void InsertPosition(const unsigned pos , const T& val);
	void DeleteStart(const T& val);
	void DeleteEnd(const T& val);
	void DeletePosition(const unsigned pos, const T& val);
	//#############################################################################################
	//										GET
	//#############################################################################################
	T & GetValue() const;
	node* Begin() const{
		return this->head;
	}
	node* End() const{
		return this->tail;
	}
	unsigned Size() const;

	//#############################################################################################
	//										SET
	//#############################################################################################
	void SetValue(const T& val);
	void SetStart();
	void SetEnd();

	//#############################################################################################
	//										OPERATORS
	//#############################################################################################
	
	Linked_list<T>& operator=(const Linked_list<T>& obj);
	Linked_list<T>& operator=(const T& val);
	Linked_list<T>& operator++();
	Linked_list<T>  operator++(int dummy);
	Linked_list<T>& operator+(const int& val);
	
private:
	size_t size;
	node* head;
	node* tail;
	node* select;
};

//#############################################################################################
//										CONSTRUCTORS
//#############################################################################################
template <class T>
Linked_list<T>::Linked_list() : size(0)
{
#ifdef DEBUG
	cout << "Constructor" << endl;
#endif // DEBUG

	this->head = this->tail = this->select = nullptr;
}

template <class T>
Linked_list<T>::Linked_list(const size_t s) : size(0)
{
#ifdef DEBUG
	cout << "Constructor" << endl;
#endif // DEBUG

	this->head = this->tail = this->select = nullptr;

	for (size_t i = 0; i < s; i++)
	{
		(void)this->AddNode();
	}
}

template <class T>
Linked_list<T>::Linked_list(const Linked_list<T>& obj) :size(0)
{
#ifdef DEBUG
	cout << "Copy constructor" << endl;
#endif // DEBUG

	this->head = this->tail = this->select = nullptr;

	//copy section
	node* p = obj.head;
	while (p) {
		(void)this->AddNode(p->value);
		p = p->next;
	}
}

template <class T>
Linked_list<T>::~Linked_list()
{
#ifdef DEBUG
	cout << "Destructor" << endl;
#endif // DEBUG

	if(this->select!=nullptr && this->head != nullptr)
	{
		for (this->select = this->head ; this->select ; )
		{
			node* temp;
			temp = this->select->next;
			delete this->select;
			this->select = temp;
		}
	}
}

//#############################################################################################
//										ADDON, DELETE
//#############################################################################################

template <class T>
void Linked_list<T>::AddNode()
{
	node* temp = new node;
	temp->next = nullptr;
	size++;
	if (head == nullptr)
	{
		select = head = tail = temp;
	}
	else
	{
		tail->next = temp;
		select = tail = temp;
	}
}
template <class T>
void Linked_list<T>::AddNode(const T& val)
{
	node* temp = new node;
	temp->value = val;
	temp->next = nullptr;
	this->size++;
	if (this->head == nullptr)
	{
		this->select = this->head = this->tail = temp;
	}
	else
	{
		this->tail->next = temp;
		this->select = this->tail = temp;
	}
}
template <class T>
void Linked_list<T>::InsertStart(const T& val)
{
	node* temp = new node;
	temp->value = val;
	temp->next = this->head;
	this->head = temp;
	this->size++;
}
template <class T>
void Linked_list<T>::InsertPosition(const unsigned pos , const T& val) 
{
	node* pre = new node;
	node* cur = new node;
	node* temp = new node;
	cur = this->head;
	for (size_t i = 0; i < pos; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	temp->value = val;
	pre->next = temp;
	temp->next = cur;
	this->size++;
	this->select = temp;
}
template <class T>
void Linked_list<T>::DeleteStart(const T& val) {
	node* temp = new node;
	temp = this->head;
	this->head = this->head->next;
	delete temp;
}
template <class T>
void Linked_list<T>::DeleteEnd(const T& val)
{
	node* cur = new node;
	node* pre = new node;
	cur = this->head;
	while (cur->next != nullptr)
	{
		pre = cur;
		cur = cur->next;
	}
	this->tail = pre;
	pre->next = nullptr;
	delete cur;
}
template <class T>
void Linked_list<T>::DeletePosition(const unsigned pos, const T& val)
{
	node* cur = new node;
	node* pre = new node;
	cur = this->head;
	for (int i = 1; i < pos; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	pre->next = cur->next;
}

//#############################################################################################
//										GET
//#############################################################################################

template <class T>
T & Linked_list<T>::GetValue() const
{
	return (this->select->value);
}

template <class T>
unsigned Linked_list<T>::Size() const
{
	return this->size;
}

//#############################################################################################
//										SET
//#############################################################################################

template <class T>
void Linked_list<T>::SetValue(const T& val)
{
	if (this->select == nullptr)
	{

	}
	else
		this->select->value = val;
}
template <class T>
void Linked_list<T>::SetStart()
{
	this->select = this->head;
}
template <class T>
void Linked_list<T>::SetEnd()
{
	this->select = this->tail;
}


//#############################################################################################
//										OPERATORS
//#############################################################################################

template <class T>
Linked_list<T>& Linked_list<T>::operator=(const Linked_list<T> & obj)
{	
	//check section
	if (&obj == this) return *this;
	//delete section
	if (this->select != nullptr && this->head != nullptr){
		for (this->select = this->head; this->select; )
		{
			node* temp;
			temp = this->select->next;

			delete this->select;
			this->select = temp;
		}
	}
	//copy section
	node* p = obj.head;
	while (p) {
		(void)this->AddNode(p->value);
		p = p->next;
	}
	return *this;
}

template <class T>
Linked_list<T>& Linked_list<T>::operator=(const T& val)
{
	this->select->value = val;
	return *this;
}

template<typename T>
Linked_list <T> & Linked_list<T>::operator++() {
	this->select = this->select->next;
	return *this;
}

template<typename T>
Linked_list <T> Linked_list<T>::operator++(int dummy) {
	const Linked_list <T> temp = *this;
	this->operator++();
	//++(*this);
	return temp;
}

template<typename T>
Linked_list <T> & Linked_list<T>::operator+(const int& val)
{
	for (int i = 0; i < val; i++){
		this->select = this->select->next;
	}
	return *this;
}
