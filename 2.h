#pragma once
#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std; 
class MenuItem;//声明
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
template<class T>//类模板1
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
template<class Tm>//类模板2
class UserArray
{
private:
	Tm **pPUser;
	int pos;
	int size;
public:
	UserArray(int);
	~UserArray();
	//增加用户对象
	int addUser(Tm*);
	//删除指定位置的用户对象
	int remove(int);
	//查询是否存在相同用户名的用户对象
	//用户注册时使用
	int searchUser(char*);
	//判断是否为合法用户
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
	//用户登录
	int login();
	//用户注册
	int registe();
	static const char *validateName(const char*,int,int);
	char *inputPassword(int,int);
};
class ExeMenu//选择函数
{
public:
	UserArray<User> users;
	ExeMenu(int);
	void exeMenu();
	void choose();
	void tchoose();
	void degreeMenu();
};
class Exercise//测试函数
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
