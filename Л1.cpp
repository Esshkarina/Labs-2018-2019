#include <iostream>
#include <string>
#include<ctime>
#include<cstdlib>
#include <algorithm>
#include <iomanip>
using namespace std;

struct book {
	int id = 0;
	string from, to, date, time, duration;
	
	void add () {
		for (int i=0; i<=5; i++)
			id= rand()%10000;
			
		cout << "Enter from:" << endl;
		cin >> from;
		cout << "Enter to:" << endl;
		cin >> to;
		cout << "Enter data:" << endl;
		cin >> date;
		cout << "Enter start time:" << endl;
		cin >> time;
		cout << "Enter duration:" << endl;
		cin >> duration;	
	}
	string dateequally(string date);	
	void getString() {
		cout <<  id<< "\t"  << from << "\t" << to << "\t" << date << "\t" << time << "\t" << duration << endl;
	}
	int outID() {
	return id;
	}
	string outFROM() {
	return from;
	}
	string outTO() {
	return to;
	}
	string outDATE() {
	return dateequally(date);
	}
	string outTIME() {
	return time;
	}
	string outD() {
	return duration;
	}
};

string Date (string date) {
		string k;
		k = date[0] + date[1] + date[2] + date[3] + '.' + date[5] + date[6] + '.' + date[8] + date[9];
return k;
}

int main (){
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int avail = 4, option = 8, iID;
	book str[100];
	str[0].add("David", "Ann", "2018.11.15", "14:41", "22");
	str[1].add("Kate", "Betty", "2018.11.10", "23:05", "37");
	str[2].add("Arche", "David", "2018.11.24", "12:24", "30");
	str[3].add("Betty", "Arche", "2018.11.24", "11:32", "56");	
	
	while (option != 0) {
		system("cls");
		for (int i = 0; i < avail; i++) {
			str[i].getString();
		}
		cout << "\n\nOperations:\n1)add\n2)delete\n3)show\n4)from date to date\n5)from dur to dur\n6)from\n7)to\n0)exit" << endl;
		cin >> option;
		switch (option)
		{
			case 1:{
				str[avail].add();
				avail++; 
				break;
			}
			case 2:{
				cout << "Input id\n";
				cin >> iID;
				for (int i = 0; i < avail; i++) {
					if (str[i].outID == iID) {
						if (avail == i) {
							avail--;
						}
						else {
							for (int j = i; j < avail - 1; j++) {
								str[j] = str[j + 1];
							}
							avail--;
						}
					}
				};
				break;
			}
			case 3:{
				for (int i = 0; i < avail; i++) {
					str[i].getSrting();
				}
				break;
			}
			case 4:{
				system("cls");
				string FROM, TO;
				cout << "Input: from"<< endl;
				cin >> FROM;
				cout << "Input: to"<< endl;
				cin >> TO;
				system("cls");
				for (int i = 0; i < avail; i++) {
					if (Data(FROM) <= str[i].outDATE() && Data(TO) >= str[i].outDATE()) {
						std[i].getString();
					}
				}
				break;
			}		
			case 5:{
				system("cls");
				string fd, td;
				cout << "Input: from duration"<< endl;
				cin >> fd;
				cout << "Input: to duration"<< endl;
				cin >> td;
				system("cls");
				for (int i = 0; i < avail; i++) {
					if (str[i].outD() >= fd && str[i].outD() <= td) {
						str[i].getString();
					}
				}; 
				break;
			}
			case 6:{
				system("cls");
				string name;
				cout << "Input name\n";
				cin >> name;
				system("cls");
				for (int i = 0; i < avail; i++) {
					if (name == str[i].outFROM()) {
						str[i].getString();
					}
				}
				break;
			}
			case 7:{
				system("cls");
				string name;
				cout << "Input name\n";
				cin >> name;
				system("cls");
				for (int i = 0; i < avail; i++) {
					if (name == str[i].outTO()) {
						str[i].getString();
						}
					}
				break;
			}
		}
	}
	return 0;
}
}
