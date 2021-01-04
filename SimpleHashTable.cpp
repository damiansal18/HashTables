#include <iostream> 

using namespace std;

static const int tableSize=101;

class HashTable{
private: 

  struct Student{
    string Name;
    int ID;
    int GPA;
    int Age;
    Student* next;
  };

  Student* HashArray[tableSize];
public:
  HashTable();
  int HashFunc(int key); //ID
  void HashInsert(string name,int id,int gpa,int age);

};

HashTable::HashTable()
{
  for(int i=0; i < tableSize; i++)
    {
      HashArray[i]=new Student;
      HashArray[i]->ID=0000000000;
      HashArray[i]->GPA=0.0;
      HashArray[i]->Name= "N/A";
      HashArray[i]->Age=00;
      HashArray[i]->next=NULL;
  }
}

int HashTable::HashFunc(int key)
{
  return key % tableSize;
}

void HashTable::HashInsert(string name,int id,int gpa,int age)
{
  int hash=HashFunc(id);

  if(HashArray[hash]->Name== "N/A")
    {
      HashArray[hash]->Name = name;
      HashArray[hash]->ID = id;
      HashArray[hash]->GPA = gpa;
      HashArray[hash]->Age = age;
    }
  else
    {
      Student* ptr= HashArray[hash];
      Student* newStu= new Student;
      newStu->Name = name;
      newStu->ID = id;
      newStu->GPA = gpa;
      newStu->Age = age;
      newStu->next = NULL;

      while(ptr->next != NULL)
	{
	  ptr=ptr->next;
	}
      ptr->next = newStu;
    }
}

int main()
{
  HashTable Table;
  cout << " Enter the Student's Information:"<< endl;
  cout << " Student's name: ";

  string name;
  cin >> name;

  cout << " Student's ID (10 digits): ";

  int id;
  cin >> id;

  cout << " Student's GPA: ";

  int gpa;
  cin >> gpa;

  cout << " Student's Age: ";

  int age;
  cin >> age;

  Table.HashInsert(name,id,gpa,age);



  return 0;
}
