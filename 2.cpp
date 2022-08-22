
/*
Сѧ������ϵͳ

��¼���û���pass�������ס/����סno��ע��pass
ѡ���Ѷ�   �����ͻ���
Ĭ��100�ڿ�ѡ��pass
��ʱ������ϰpass
ʱ��5��������
���žų˷����ѡ����ʾ���no
�������pass
��ʾ׼ȷ��pass  ����pass ʱ��pass
��������no  ����no
������һ����no
�û���ʷ��¼����pass
��ģ��pass
*/
#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include"2.h"
using namespace std;
void MenuItem::setHandler(Handler *p)
{
	this->handler = p;
}
Handler* MenuItem::getHandler()
{
	return this->handler;
}
MenuItem::MenuItem( const char *title,int id)
{
	this->id=id;
	this->title=new char[strlen(title)+1];
	strcpy(this->title,title);
	this->title[strlen(title)]='\0';
}
void MenuItem::showMenuItem(int s)
{
	Menu::showSpaces(s+4);
	cout<<id<<"."<<this->title<<endl;
}
void MenuItem::setId(int i)
{
	id=i;
}
int MenuItem::getId()
{
	return this->id;
}
MenuItem::~MenuItem()
{
	delete []                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    this->title;
}
Menu::Menu(int spaces,int width,int id,char *title):MenuItem(title,id)
{
	this->spaces=spaces;
	this->width=width;
	this->handler = new MenuHanler();
}
Menu::~Menu()
{
	//list.clear();
}
void Menu::setSpaces(int s)
{
	this->spaces=s;
}
void Menu::setWidth(int w)
{
	this->width=w;
}
int Menu::getSpaces()
{
	return this->spaces;
}
int Menu::getWidth()
{
	return this->width;
}
void Menu::showSpaces(int s)//��ʾÿ�пո� ����δ֪
{
	for(int i=0;i<s;i++)
	{
		cout<<" ";
	}
}
void Menu::showEdge()
{
	showSpaces(spaces);
	for(int i=0;i<width;i++)
	{
		cout<<"=";
	}
	cout<<endl;
}
void Menu::showHead()
{
	showSpaces(spaces+(width-strlen(title))/2);
	cout<<title<<endl;
	showEdge();
}
void Menu::showContent()
{
	for(int i=0;i<=list.getPos();i++)
	{
		list.getItem(i)->showMenuItem(this->spaces);
	}
}
void Menu::showTail()
{
	showEdge();
	showSpaces(spaces+3);
	cout<<"��ѡ��";
}
void Menu::addMenuItem(MenuItem *p)
{
	list.addMenuItem(p);
}
void Menu::showMenu()
{
	showHead();
	showContent();
	showTail();
}
template<class T>
MenuList<T>::MenuList(int size)
{
	this->size=size;
	this->pos=-1;
	this->contents=new T*[size];
}
template<class T>
MenuList<T>::~MenuList()
{
	for(int i=0;i<=pos;i++)
	{
		delete[] contents[i];
	}
	delete []contents;
}
template<class T>
void MenuList<T>::addMenuItem(T *mi)
{
	if(pos<size-1)
	{
		pos++;
		mi->setId(pos+1);
		contents[pos]=mi;
	}
	else
	{
		throw("�б�����");
	}
}
template<class T>
void MenuList<T>::removeMenuItem(int index)
{
	if(index>=0 && index<size)
	{
		delete contents[index];
		for(int i=index;i<size-1;i++)
		{
			contents[i]=contents[i+1];
		}
		pos--;
	}
	else
	{
		throw"�޷�ɾ��";
	}
}
template<class T>
T *MenuList<T>::getItem(int index)
{
	if(index>=0 && index<size)
	{
		return contents[index];
	}
	else
	{
		throw"�޷����";
	}
}
template<class T>
int MenuList<T>::getSize()
{
	return size;
}
template<class T>
int MenuList<T>::getPos()
{
	return pos;
}
template<class T>
int MenuList<T>::isEmpty()
{
	if(pos<0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

User::User(const char*pName,const char*pPassword)
{
	strcpy(username,pName);
	username[strlen(username)]='\0';
	strcpy(password,pPassword);
	password[strlen(password)]='\0';
}
void User::setUsername(const char*pName)
{
	strcpy(username,pName);
	username[strlen(username)]='\0';
}
void User::setPassword(const char*pPassword)
{
	strcpy(password,pPassword);
	password[strlen(password)]='\0';
}
const char *User::getUsername() const
{
	return username;
}
const char *User::getPassword() const
{
	return password;
}
int User::operator ==(const User&user)
{
	int flag=strcmp(username,user.username);
	if(flag==0)
		return 1;
	else
		return 0;
}
int User::operator !=(const User&user)
{
	return!(*this==user);
}
template<class Tm>
UserArray<Tm>::UserArray(int amount)
{
	size=amount;
	pPUser=new Tm*[size];
	pos=0;
}
template<class Tm>
UserArray<Tm>::~UserArray()
{
	if(pPUser!=0)
	{
		for(int i=0;i<pos;i++)
		{
			delete pPUser[i];
		}
		delete []pPUser;
	}
}
template<class Tm>
int UserArray<Tm>::addUser(Tm*pUser)
{
	if(pos>=size)
	{
		return 0;
	}
	else
	{
		pPUser[pos]=pUser;
		pos++;
		return 1;
	}
}
template<class Tm>
int UserArray<Tm>::remove(int index)
{
	if(index<0||index>=pos)
	{
		return 0;
	}
	else
	{
		User *currentuser=pPUser[index];
		for(int i=index;i<pos;i++)
		{
			pPUser[i]=pPUser[i+1];
		}
		pos--;
		delete currentuser;
		return 1;
	}
}
template<class Tm>
int UserArray<Tm>::searchUser(char*pName)
{
	int flag=0;
	for(int i=0;i<pos;i++)
	{
		if(strcmp(pPUser[i]->getUsername(),pName)==0)
		{
			flag=1;
			break;
		}
	}
	return flag;
}
template<class Tm>
int UserArray<Tm>::isExist(char*username,char*password)
{
	int flag=0;
	for(int i=0;i<pos;i++)
	{
		if((strcmp(pPUser[i]->getUsername(),username)==0)&&(strcmp(pPUser[i]->getPassword(),password)==0))
		{
			flag=1;
			break;
		}
	}
	return flag;
}
LoginRegiste::LoginRegiste(StartMenu*p)
{
	pMenu=p;
}
char *LoginRegiste::inputPassword(int min,int max)
{
	char password[12];
	ofstream out("password.dat",ios::out);
	out<<"���룺";
	int value=0;
	int count=0;
	int invalid=0;
	char *p=new char[max+1];
	while((value=getch())!='\r')
	{
		while(1)
		{
			out<<password;
			break;
		}
		if(value=='\b')
		{
			cout<<'\b';
			cout<<' ';
			cout<<'\b';
			count--;
			continue;
		}
		cout<<'*';
		p[count]=value;
		if(!((value>='0'&&value<='9')||(value>='A'&&value<='Z')||(value>='a'&&value<='z')))
		{
			invalid=1;
		}
		count++;
	}
	if(count>max||count<min)
	{
		cout<<"\n�ַ�����������"<<min<<"��"<<max<<"֮��"<<endl;
		delete[]p;
		return 0;
	}
	if(invalid==1)
	{
		cout<<"\n���������Ӣ�Ļ������ַ����"<<endl;
		delete[]p;
		return 0;
	}
	p[count]='\0';
	return p;
}
//�û���¼
int LoginRegiste::login()
{
	char username[12];
	char password[12];
	while(1)
	{
		cout<<"�û���:";
		cin>>username;
		const char* p=LoginRegiste::validateName(username,6,12);
		if(p == 0)
			cout<<"��������!"<<endl;
		else
			break;
	}
	while(1)
	{
		cout<<"����:"<<flush;
		char* p=LoginRegiste::inputPassword(6,12);
		if(p == 0)
			cout<<"����������!"<<endl;
		else
		{
			strcpy(password,p);
			password[strlen(password)]='\0';
			delete [] (void*)p;
			break;
		}
	}
	return pMenu->users.isExist(username,password);
}
//�û�ע��
int LoginRegiste::registe()
{
	char username[12];
	char password[12];
	ofstream fout("username.dat",ios::out);
	char confirmPassword[12];
	while(1)
	{
		cout<<"�û���:";
		if(!fout)
		{
			cerr<<"�ļ����ܽ���"<<endl;
			exit(1);
		}
		while(cin>>username)
		{
			fout<<"�û�����"<<username;
			break;
		}
		const char* p=validateName(username,6,12);
		if(p == 0)
			cout<<"��������!"<<endl;
		else
			break;
	}
	while(1)
	{
		cout<<"����:"<<flush;
		const char* p=inputPassword(6,12);
		if(p == 0)
			cout<<"����������!"<<endl;
		else
		{
			strcpy(password,p);
			password[strlen(password)]='\0';
			delete [] (void*)p;
			break;
		}
	}
	while(1)
	{
		cout<<"\nȷ������:"<<flush;
		const char* p=inputPassword(6,12);
		if(p == 0)
			cout<<"����������!"<<flush;
		else
		{
			strcpy(confirmPassword,p);
			confirmPassword[strlen(confirmPassword)]='\0';
			delete [] (void*)p;
			if(strcmp(password,confirmPassword) != 0)
			{
				cout<<"\n������ȷ�����벻��,����������"<<flush;
				continue;
			}
			else
			{
				break;
			}
		}
	}
	if(pMenu->users.searchUser(username))
		return 0;
	User* pUser=new User(username,password);
	pMenu->users.addUser(pUser);
	return 1;
}
const char *LoginRegiste::validateName(const char*p,int min,int max)
{
	int invalid=0;
	int len=strlen(p);		
	if(len > max || len < min)
	{
		cout<<"�ַ�����������"<<min<<"��"<<max<<"֮��"<<endl;
		return 0;
	}
	for(int i=0;i<len;i++)
	{
		if(i == 0)
		{
			if(!((p[0] >= 'A' && p[0] <= 'Z')|| (p[0] >= 'a' && p[0] <= 'z')))
			{
				invalid=1;
				break;
			}
		}
		else
		{
			if(!((p[i] >= '0' && p[i] <= '9')|| (p[i] >= 'A' && p[i] <= 'Z')|| (p[i] >= 'a' && p[i] <= 'z')))
			{
				invalid=1;
				break;
			}
		}
	}	
	if(invalid)
	{
		cout<<"�û���������Ӣ�Ļ������ַ����,�����ַ�ΪӢ���ַ�"<<endl;
		return 0;
	}
	return p;
}
StartMenu::StartMenu(int amount):users(amount)
{
}
void StartMenu::startmenu()
{
	system("cls");
	ExeMenu exemenu(20);
	LoginRegiste loginRegiste(this);
	int option=0;
	int count=0;
	do
	{
		try
		{
			Menu pmenu(20,30,0,"��¼ ע�� ϵͳ");
			MenuItem *pItem= new MenuItem("��¼");
			pmenu.addMenuItem(pItem);
			pItem = new MenuItem("ע��");
			pmenu.addMenuItem(pItem);
			pItem = new MenuItem("�˳�");
			pmenu.addMenuItem(pItem);
			ExitHandler *exitHandler = new ExitHandler();
			pItem->setHandler(exitHandler);
			pmenu.showMenu();
		}
		catch(const char* msg)
		{
			cout << msg << endl;
		}
		while(1)
		{
			
			cin>>option;
			if(option<1||option>3)
			{
				system("cls");
				cout<<"\n�����ѡ����Ч,����������!"<<endl;	
			}
			else
				break;
		}
		system("cls");
		switch(option)
		{
			case 1:
				if(!loginRegiste.login())
				{
					cout<<"\n�û������������"<<flush<<'\n';
					count++;
					system("pause");
					system("cls");
				}
				else
				{
					cout<<"\n��¼�ɹ�"<<endl;
					system("pause");
					system("cls");
					cout<<"�������������ϰϵͳ"<<endl;
					system("pause");
					exemenu.exeMenu();
				}	
				break;
			case 2:
				if(!loginRegiste.registe())
				{
					cout<<"\n������û����Ѿ�����"<<endl;
					system("pause");
					system("cls");
				}
				else
				{
					cout<<"\nע��ɹ�"<<endl;
					system("pause");
					system("cls");
				}	
				break;	
		}
		if(count >= 3)
		{
			cout<<"�����������Σ�ϵͳ�Զ��˳�"<<endl;
			break;
		}
	}while(option != 3);
}
ExeMenu::ExeMenu(int amount):users(amount)
{
}
void ExeMenu::exeMenu()
{
	system("cls");
	StartMenu menu(20);
	try
	{
		Menu pmenu(20,30,0,"��ϰϵͳ");
		MenuItem *pItem= new MenuItem("������ϰ");
		pmenu.addMenuItem(pItem);
		pItem = new MenuItem("��ʱ��ϰ");
		pmenu.addMenuItem(pItem);
		pItem = new MenuItem("�˳�ϵͳ");
		pmenu.addMenuItem(pItem);
		ExitHandler *exitHandler = new ExitHandler();
		pItem->setHandler(exitHandler);
		pmenu.showMenu();
	}
	catch(const char* msg)
	{
		cout << msg << endl;
	}
	ExeMenu dmenu(20);
	int choice;
	do
	{
		while(1)
		{
			cin>>choice;
			if(choice<1||choice>3)
			{
				system("cls");
				cout<<"\n�����ѡ����Ч,����������!"<<endl;	
			}
			else
				break;
		}
		switch(choice)
		{
			case 1:
				dmenu.degreeMenu();
				dmenu.choose();
				break;
			case 2:
				dmenu.degreeMenu();
				dmenu.tchoose();
				break;
			case 3:
				menu.startmenu();
				break;
		};
	}while(choice!=3);
}
void ExeMenu::choose()
{
	Exercise exercise(100);
	ExeMenu menu(20);
	int sel;
	do
	{
		while(1)
		{
			
			cin>>sel;
			if(sel<1||sel>3)
			{
				system("cls");
				cout<<"\n�����ѡ����Ч,����������!"<<endl;	
			}
			else
				break;
		}
		switch(sel)
		{
		case 1:
			system("cls");
			exercise.main();
			system("pause");
			cout<<"����1�����Ѷ�ѡ��";
			break;
		case 2:
			system("cls");
			exercise.kmain();
			system("pause");
			cout<<"����1�����Ѷ�ѡ��";
			break;
		case 3:
			menu.exeMenu();
			break;
		}
		break;
	}while(sel!=3);
}
void ExeMenu::tchoose()
{
	Exercise exercise(100);
	ExeMenu menu(20);
	int select;
	do
	{
		while(1)
		{
			
			cin>>select;
			if(select<1||select>3)
			{
				system("cls");
				cout<<"\n�����ѡ����Ч,����������!"<<endl;	
			}
			else
				break;
		}
		switch(select)
		{
		case 1:
			system("cls");
			exercise.timeExe();
			system("pause");
			cout<<"����2�����Ѷ�ѡ��";
			break;
		case 2:
			system("cls");
			exercise.ktimeExe();
			system("pause");
			cout<<"����2�����Ѷ�ѡ��";
			break;
		case 3:
			menu.exeMenu();
			break;
		}
		break;
	}while(select!=3);
}
void ExeMenu::degreeMenu()
{
	system("cls");
	try
	{
		Menu pmenu(20,30,0,"�Ѷȵȼ�");
		MenuItem *pItem= new MenuItem("��");
		pmenu.addMenuItem(pItem);
		pItem = new MenuItem("����");
		pmenu.addMenuItem(pItem);
		pItem = new MenuItem("����");
		pmenu.addMenuItem(pItem);
		ExitHandler *exitHandler = new ExitHandler();
		pItem->setHandler(exitHandler);
		pmenu.showMenu();
	}
	catch(const char* msg)
	{
		cout << msg << endl;
	}
	
}
Exercise::Exercise(int number)
{
	this->number=number;
}
int Exercise::main()
{
	int num;
	int sum;
	int a,b,c,ch,l,h;
	int size=0,right=0;
	cout<<"������Ҫ��ϰ����Ŀ������:";
	cin>>num;
	srand((unsigned)time(NULL));
	for(int i=0;i<num;i++)
	{
		size++;
		cout<<"  "<<size<<"."<<flush;
		a= rand() % 100 + 1;
		b= rand() % 100 + 1;
		cout<<a<<"+"<<b<<"=";
		cin>>sum;
		c=a+b;
		if (sum == a + b)
		{
			cout << "right!" << '\n' << "��һ��" << endl;
			right++;
		}
		else
		{
			cout << "������" << endl;
			cout << "�Ƿ������ȷ�𰸣�(Y,y��N,n)" << endl;
			cin >> ch;
			if (ch == 'Y' || ch == 'y')
			{
				cout << "��ȷ��Ϊ:" << a + b << endl;
			}
			else if (ch == 'N' || ch == 'n')
			{
				cout << "�����������:" << endl;
				cin >> l;
				if (l == a+ b)
				{
					cout << "right!" << '\n' << "��һ��" << endl;
					h++;
				}
				else
					cout << "��ȷ��Ϊ:" << a + b << endl;
			}
		}
	}
	grade=(right*100.0)/num;
	cout << "�ܷ֣�" << grade << '\n';
	cout << "һ����ȷ��Ϊ" << right * 10 << "%";
	cout << "������ȷ��Ϊ" << h * 10 << "%";
	return 0;
}
int Exercise::kmain()
{
	int num;
	int remain;
	int a,b;
	int size=0,right=0;
	cout<<"������Ҫ��ϰ����Ŀ������:";
	cin>>num;
	srand((unsigned)time(NULL));
	for(int i=0;i<num;i++)
	{
		size++;
		cout<<"  "<<size<<"."<<flush;
		a = rand() % 9 + 1;
		b = (rand() % 9 + 1) * a;
		cout << a<< "/" << b << "=";
		cin>>remain;
		
		if (remain == a / b)
		{
			cout << "right!" << '\n' << "��һ��" << endl;
			right++;
		}
	}
	grade=(right*100.0)/num;
	cout<<"�ܷ֣�"<<grade<<'\n';
	return 0;
}
int Exercise::timeExe()
{
	int sum;
	int a,b;
	int size=0,right=0;
	time_t start,end;
	int times;
	cout<<"�����붨ʱ��ʱ�䣺";
	cin>>times;
	srand((unsigned)time(NULL));
	time(&start);
	do
	{
		time(&end);
		if(difftime(end,start)<=times)
		{
			size++;
			cout<<"  "<<size<<"."<<flush;
			a=rand();
			b=rand();
			cout<<a<<'+'<<b<<'=';
			cin>>sum;
			if(sum==a+b)
				right++;
		}
	}while(difftime(end,start)<=times);
	cout<<"ʱ�䵽��"<<'\n';
	system("pause");
	grade=(right*100.0)/size;
	cout<<"�ܷ֣�"<<grade<<'\n';
	return 0;
}
int Exercise::ktimeExe()
{
	int remain;
	int a;
	int size=0,right=0;
	time_t start,end;
	int times;
	cout<<"�����붨ʱ��ʱ�䣺";
	cin>>times;
	srand((unsigned)time(NULL));
	time(&start);
	do
	{
		time(&end);
		if(difftime(end,start)<=times)
		{
			size++;
			cout<<"  "<<size<<"."<<flush;
			a=rand();
			cout<<rand()<<"%4"<<'=';
			cin>>remain;
			if(remain==a%4)
				right++;
		}
	}while(difftime(end,start)<=times);
	cout<<"ʱ�䵽��"<<'\n';
	system("pause");
	grade=(right*100.0)/size;
	cout<<"�ܷ֣�"<<grade<<'\n';
	return 0;	
}
void main()
{
	StartMenu menu(25);
	menu.startmenu();
}