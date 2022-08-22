#pragma once
#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std; 
class MenuItem;//����
class Handler
{
public:
	virtual void action(MenuItem *p) = 0;
};
class MenuItem
{
protected:
	char *title;
	int id;
	Handler *handler;
public:
	MenuItem(const char *title,int id=0);
	void showMenuItem(int s);
	char* getTile();
	int getId();
	void setId(int id);
	virtual ~MenuItem();
	void setHandler(Handler *p);
	Handler* getHandler();
};
template<class T>//��ģ��1
class MenuList
{
private:
	T **contents;
	int size;
	int pos;
public:
	MenuList(int size=3);
	~MenuList();
	void addMenuItem(T *mi);
	void removeMenuItem(int index);
	T *getItem(int index);
	int getSize();
	int getPos();
	int isEmpty();
};
class Menu:public MenuItem
{
private:
	int spaces;
	int width;
	MenuList<MenuItem> list;	
public:
	Menu(int spaces,int width,int id,char *title);
	virtual ~Menu();
	void showMenu();
	static void showSpaces(int s);
	void showEdge();
	void showHead();
	void showContent();
	void showTail();
	void setSpaces(int s);
	void setWidth(int w);
	int getSpaces();
	int getWidth();
	void addMenuItem(MenuItem *pi);
};
class ExitHandler :public Handler
{
	void action(MenuItem *p)
	{
		exit(0);
	}
};
class ReturntHandler :public Handler
{
	void action(MenuItem *p)
	{
		return;
	}
};
class MenuHanler : public Handler
{
	void action(MenuItem *p)
	{
		((Menu*)(p))->showMenu();
	}
};
class User//struct User
{
private:
	char username[12];
	char password[12];
public:
	User(const char*,const char*);
	void setUsername(const char*);
	void setPassword(const char*);
	const char *getUsername() const;
	const char *getPassword() const;
	int operator ==(const User&);
	int operator !=(const User&);
};
template<class Tm>//��ģ��2
class UserArray
{
private:
	Tm **pPUser;
	int pos;
	int size;
public:
	UserArray(int);
	~UserArray();
	//�����û�����
	int addUser(Tm*);
	//ɾ��ָ��λ�õ��û�����
	int remove(int);
	//��ѯ�Ƿ������ͬ�û������û�����
	//�û�ע��ʱʹ��
	int searchUser(char*);
	//�ж��Ƿ�Ϊ�Ϸ��û�
	int isExist(char*,char*);
};
class StartMenu
{
public:
	UserArray<User> users;
	StartMenu(int);
	void startmenu();
};
class LoginRegiste
{
private:
	User *currentuser;
	StartMenu *pMenu;
public:
	LoginRegiste(StartMenu*);
	//�û���¼
	int login();
	//�û�ע��
	int registe();
	static const char *validateName(const char*,int,int);
	char *inputPassword(int,int);
};
class ExeMenu//ѡ����
{
public:
	UserArray<User> users;
	ExeMenu(int);
	void exeMenu();
	void choose();
	void tchoose();
	void degreeMenu();
};
class Exercise//���Ժ���
{
private:
	int number;
	double grade;
public:
	Exercise(int);
	int main();
	int kmain();
	int timeExe();
	int ktimeExe();
};
