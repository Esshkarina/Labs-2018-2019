#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
using namespace std;

template <class T> class list
{
	private:
	class node // The node class contains the data for the list
	{
		friend class list<T>;
		private:
		node *next; // Pointer to the next item in the list
		T val; // List data
		node(): next(NULL){}
		node(T data): next(NULL), val(data){}
		~node(){}
	};
	node *head; // Pointer to the top of the list
	int count; // Number of items in the list
	public:
	list(): head(NULL), count(0){}
	~list()
	{
		clear(); // Free occupied memory
	}
	int getCount() // Returns the number of items in the list
	{
		return count;
	}
	int add(T data) // Add an item to the end of the list
	{
		node *to_add = new node(data);
		if (head==NULL) // If there are no items in the list
			head=to_add;
		else
		{
			node *current;
			for (current==head; current->next!=0; current=current->next);
			current->next=to_add;
		}
		count++;
		return count;
	}
	int del (int x) // Remove an item from the list.
	// Returns the number of items in the list or -1 on error
	{
		if (x>count) return -1;
			node *to_del=head;
		if (x==1) //If you want to delete the first item
		{
			head=head->next;
			delete to_del;
		}
		else
		{
			node *current=head;
			for (int i=1; i<x-1; i++) current=current->next;
			to_del=current->next;
			current->next=current->next->next;
			delete to_del;
		}
		count--;
		return count;
	}
	void clear() // Clearing the list
	{
		node *current = head;
		node *to_del = head;
		while (to_del!=NULL)
		{
			current=current->next;
			delete to_del;
			to_del=current;
		}
		head=NULL;
		count=0;
	}
	T getData(int x) // Returns data from the list
	{
		node *current;
		for (current=head; x>1; x--) current=current->next;
		return current->val;
	}
};

struct cardIndex
{	
	char *abonent;
	char *number;
};


list<cardIndex> my_list;
void print()
{
	system("cls");
	for (int i=1; i<=my_list.getCount(); i++)
	cout << my_list.getData(i).abonent << " " << my_list.getData(i).number << endl;
	while (!kbhit()) {;}
}

void find()
{
	system("cls");
	char *abonent;
	cout << "Vvedite abonenta: "; gets(abonent);
	for (int i=1; i<=my_list.getCount(); i++)
		if (my_list.getData(i).abonent == abonent)
			cout << my_list.getData(i).number << endl;
	while (!kbhit()) {;}
}

void add()
{
	char* abonent;
	char* number;
	cardIndex *my = new cardIndex;
	cout << "abonent: ";
	cin >> abonent;
	cout << "number: ";
	cin >> number;
	my->abonent=abonent;
	my->number=number;
	my_list.add(*my);
}

int main()
{   
	int choice = 0;
	while (choice!=5)
	{
		system("cls");
		cout << "1. Add abonent" << endl;
		cout << "2. Print list" << endl;
		cout << "3. Clear" << endl;
		cout << "4. Find abonent" << endl;
		cout << "5. Exit" << endl;
		cin >> choice;
		switch (choice)
		{
			case 1: add(); break;
			case 2: print(); break;
			case 3: my_list.clear(); break;
			case 4: find(); break;
		}
	}
	return 0;
}

