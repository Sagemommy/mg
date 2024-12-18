#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class Student
{
	char name[30];
	int roll;
	char division;
	string address;;
public:
	void createdatabase(int);
	void display();
	void addrecord(int);
	int Delete();
	void search();
};

void Student::createdatabase(int n)
{
	Student temp;
	ofstream fout;
	fout.open("StudentData.txt");
	for(int i=1;i<=n;i++)
	{
		cout<<"Enter Name\n";
		cin>>temp.name;
		cout<<"Enter Roll No\n";
		cin>>temp.roll;
		cout<<"Enter Division\n";
		cin>>temp.division;
		cout<<"Enter address\n";
		cin>>temp.address;
		fout.write((char*)&temp,sizeof(temp));
	}
	fout.close();
}

void Student::display()
{
	Student temp;
	ifstream fin;
	fin.open("StudentData.txt");
	cout<<"Roll No\tName\tDivision\tAddress\n";
	while(fin.read((char*)&temp,sizeof(temp)))
	{
		cout<<temp.roll<<"\t\t"<<temp.name<<"\t\t"<<temp.division<<"\t\t"<<temp.address<<"\n";
	}
	fin.close();
}

void Student::addrecord(int n)
{
	Student temp;
	ofstream fout;
	fout.open("StudentData.txt",ios::app);
	for(int i=1;i<=n;i++)
	{
		cout<<"Enter Name\n";
		cin>>temp.name;
		cout<<"Enter Roll No\n";
		cin>>temp.roll;
		cout<<"Enter Division\n";
		cin>>temp.division;
		cout<<"Enter address\n";
		cin>>temp.address;
		fout.write((char*)&temp,sizeof(temp));
	}
	fout.close();
}
int Student::Delete()
{   Student temp;
    cout<<"\nEnter roll no. of the student : ";
    int rno, flag = 0;
    cin>>rno;
    fstream read_file("StudentData.txt", ios::in);  //open file in read mode
    fstream newFile("temp.txt", ios::out);  //create new temp file for temporary data storage
    read_file.read((char*)&temp, sizeof(temp));
    while(!read_file.eof())
        {
            if(temp.roll != rno)  
            {
                newFile.write((char*)&temp, sizeof(temp));  //write to the temp file
            }
            else  
            {
                cout<<"\nRecord Found and Deleted!\n";
                flag = 1;
            }
            read_file.read((char*)&temp, sizeof(temp));  //read next record from the
        }
        read_file.close();
        newFile.close();
        remove("StudentData.txt");
        rename("temp.txt", "StudentData.txt");
return flag;
   }

void Student::search()
{
	fstream read_file("StudentData.txt", ios::in);  //open file in reading mode
    Student temp;
    if(!read_file)
    {
        cout<<"\nFile Not Found !\nCheck local directory, or try creating the file first from Menu option\n";
        return;
    }
    else
    {
        bool flag = false;
        cout<<"\nEnter roll no. to be searched : ";
        int key;
        cin>>key;
        read_file.read((char*)&temp, sizeof(temp)); //read first record
        while(!read_file.eof())  //search till end of file
        {
            if(temp.roll == key)  //if key is equal to correct roll number
            {
                cout<<"\nRecord found !\n";
                flag = true;  //set flag
                cout<<"\nRoll No.\tName\t\tDivision\t\tAddress\n---------------------------------------------------------------------------";
                cout<<"\n"<<temp.roll<<"\t\t"<<temp.name<<"\t"<<temp.division<<"/"<<"\t\t"<<temp.address;  //display student details
                break;
            }
            else
            {
                read_file.read((char*)&temp, sizeof(temp)); //read next record
            }
        }
        if(!flag)  //if roll no. is not found
            cout<<"\nRecord not found !\n";
    }
}
int main()
{
	int n,ch,x,z=0;
	Student obj;
	cout<<"\nEnter how many records you want to enter\n";
	cin>>n;
	do
	{
		cout<<"\nEnter\n1.Create Database \n2.Display Database \n3.Add New Record \n4.Delete  a record \n5.Search a Record\n6.End\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
			obj.createdatabase(n);
			break;
			case 2:
			obj.display();
			break;
			case 3:
			cout<<"\nEnter how many records you want to Add\n";
			cin>>x;
			obj.addrecord(x);
			break;
			case 4:
			z=obj.Delete();
			if(z)
				cout<<"\nData has been deleted\n";
			else
				cout<<"\nRoll No not found\n";
			break;
			case 5:
			   obj.search();
			    break;
			case 6:
			break;
			default:
			cout<<"\nWrong value entered\n";
		}
	}while(ch!=6);
	return 0;
}
