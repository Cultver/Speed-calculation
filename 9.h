#include<iostream>
using namespace std;
class MenuItem;
class Menu;

class Handler{
public:
	virtual int excute(MenuItem *p)=0;
};

class ExitHandler:public Handler{
	int excute(MenuItem *p){
		exit(0);
	}
};
class ReturnHandler:public Handler{
	int excute(MenuItem *p){
		return 0;
	}
};
class LoginHandler:public Handler{
	int excute(MenuItem *p){
		cout << "µÇÂ¼" << '\n';
		return 1;
	}
};

class MenuList
{
private:
	MenuItem* *List;
	int size,pos;
public:
	MenuList(int size = 5);
	void addItem(MenuItem* p);
	MenuItem* getItems(int index);
	int is Empty();
	void removeItem(int index);
	~MenuList();
};
class MenuItem{
protected:	
	int id;
	char *content;
	Handler *handler;
public:
	MenuItem();
	MenuItem(int i,char *p);
	MenuItem(MenuItem &item);

	void setId(int i);
	int getId()const;
	void setContents(char *p);
	const char* getContents()const;
	void display();
	virtual ~MenuItem();
	void setHandler(Handler *p);
	Handler* getHandler()const;
	friend class MenuFactory;
};

class Menu:public MenuItem{
private:
	int spaces;
	int width;
	MenuList lis;
	int size;
public:
	Menu(int spaces,int width,char *title, int size);
	void addItem(MenuItem *p);
	int display();
	virtual ~Menu();
	friend class MenuFactory;
};

class MenuHandler:public Handler{
	int excute(MenuItem *p){
		int flag=1;
		while(1){
			system("cls");
			flag=((Menu*)(p))->display();
			if(flag==0){
				break;
			}
		}
		return 1;
	}
};
class Derator
{
public:
	static void displaySpace(int n);
	static void displayLine(int width,char c);
};
class MenuFactory
{
public:
	static Menu* createMainMenu(int spaces,int width);
	static Menu* createEditMenu(int spaces,int width);
	static Menu* createQueryMenu(int spaces,int width);
};