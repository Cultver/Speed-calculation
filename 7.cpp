#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include"9.h"
using namespace std;
void creatloginmenu()
{
cout <<"  加减乘除速算系统  " << endl;
cout <<"=================" << endl;
cout <<"     1 登录      " << endl;
cout <<"     2 注册      " << endl;
cout <<"=================" << endl;
cout <<"     请选择      " <<endl;
}
struct User//class User
{
public:
	char username[30];
	char p[30];
};
void Derator::displaySpace(int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<" "<<flush;
	}
}
MenuItem::MenuItem()
{
	id=0;
	this->content=0;
}

MenuItem::MenuItem(char *p)
{
	int len = strlen(p);
	content = new char[len+1];
	strcpy(content,p);
	content[len]='\0';
}
void MenuItem::setId(int i)
{
	this->id=i;
}
int MenuItem::getId()const
{
	return id;
}
void MenuItem::setContents(char *p)
{
	if(content!=NULL)
	{
		delete []content;
	}
	int len =strlen(p);
	content = new char[len+1];
	strcpy(content,p);
	content[len]='\0';
}
const char* MenuItem::getContents()const
{
	return this->content;
}
void MenuItem::display()
{
	cout<<id<<"."<<content<<endl;
}
MenuItem::~MenuItem()
{
	if(content!=NULL)
	{
		delete []content;
	}
}
MenuItem::MenuItem()
{
	id = 0;
	this->content = 0;
}
void MenuItem::setHandler(Handler* p)
{
	this->handler=p;
}
Handler* MenuItem::getHandler()const
{
	return this->handler;
}
Menu::Menu(int spaces,int width,char *title,int size):list(size)
{	
	this->spaces=spaces;
	this->width=width;
	this->size=size;

	int len = strlen(title);
	this->content = new char[len+1];
	strcpy(this->content,title);
	this->content[len]='\0';
	this->Hander = new MenuHander();
}
void Menu::addItem(MenuItem *p)
{ 
	list.addItem(p);
}
int Menu::display()
{
	system("cls");
	Derator::displaySpace(spaces+(width - strlen(content))/2);
	cout<<content<<endl;
	Derator::displaySpace(spaces);
	Derator::displayLine(width,'=');
	cout<<endl;
	for(int i=0;i<list.getPos();i++)
	{
		Derator::displaySpace(spaces+4);
		pContents[i]->display();
	}
	Derator::displaySpace(spaces);
	Derator::displayLine(width,"=");
	cout<<endl;
	Derator::displaySpace(spaces+4);
	cout<<"Please choose"<<flush;
	int sel;
	cin>>sel;
	int flag =1;
	if(this->pContents[sel-1]->getHandler!=NULL)
	{
		flag =(this->pContents[sel-1]->getHandler())->excute(pContents[sel-1]);
	}
	return flag;
}
Menu::~Menu()
{
	if(this->pContents!=NULL)
	{
		for(int i=0;i<size;i++)
		{
			delete pContents[i];
		}
	}
	delete []pContents;
}
Menu* MenuFactory::createMainMenu(int spaces,int width)
{

	Menu *p = new Menu(spaces,width,"加减乘除速算系统",4);
	MenuItem* p1 = new MenuItem("登录")；
	p->addItem(p1);
	p1 = new MenuItem("注册")；
	p->addItem(p1);
	p1 = createEditMenu(spaces,width);
	p->addItem(p1);
	p1 = new MenuItem("退出")；
	p1->setHandler(new ExitHander());
	p->addItem(p1);
	return p;
}
Menu* MenuFactory::createQueryMenu(int spaces,int width)
{

	Menu *p = new Menu(spaces,width,"查询用户",3);
	p1 = new MenuItem("返回");
	p1->setHander(new ReturnHander());
	p->addItem(p1);
	renturn p;
}
MenuList::MenuList(int size)
{
	this->size = size;
	this->pos = 0;
	this->list = new MenuItem*[size];
}
void MenuList::addItem(MenuItem* p)
{
	if(pos < size)
	{
		list[pos] = p;
		p-> setId(pos);
		pos++;
	}
	else
	{
		MenuItem** temp = new MenuItem*[size+5];
		size+=5;
		for(int i = 0;i<pos;i++)
		{
			temp[i] = list[i];
		}
		clear();
		list = temp;
		pos++;
	}
}
MenuItem* MenuList::getItems(int index)
{
	if(index >-0 &&index <pos)
		return list[index];
	else
		return NULL;
}
int MenuList::is Empty()
{
	if(pos == 0)
		return 1;
	else
		return 0;
}
void MenuList::removeItem(int index)
{
	if (index >= 0 && index < pos)
	{
		MenuItem *p = list[index];
		for(int i = index;i < pos - 1;i++)
		{
			list[i] = list[i+1];
			list[i]->setId(i);
		}
		delete p;
	}
}
MenuList::~MenuList()
{
	if(list !=NULL)
	{
		for(int i=0;i<pos;i++)
			delete list[i];
	}
	delete []list;
}
struct User
{
public:
	string username;
	string password;
};

void Derator::displayLine(int width,char *c)
{
	for(int i=0;i<width;i++)
	{
		cout<<c;
	}
	cout<<flush;
}
void showMenu(int spaces,int width,char *title, char *contents[],int size)
{
	displaySpace(spaces+(width - strlen(title)/2));
	cout<<title<<endl;
	displaySpace(spaces);
	displayLine(width,"=");
	cout<<endl;
	for(int i=0;i<size;i++)
	{
		displaySpace(spaces+4);
		cout<<i<<"."<<contents[i]<<endl;
	}
	displaySpace(spaces);
	displayLine(width,"=");
	cout<<endl;
	displaySpace(spaces+4);
	cout<<"Please choose"<<flush;
}
void m()
{
	if(num1 >= num2)
	{
		key = num1 - num2;
		cout << "num1 - num2 = " << key << endl;
			else if(num1 + num2 > mathnum[i])
		{
			random1();
			s();
		}
	}
	else
	{
		key = num1 +num2;
		cout << "num1 + num2 = " << key << endl;
	}
}
void mh()
{
	key = num1 * num2;
	cout << "num1 * num2 = " << key << endl;
}
void mhzd()
{
	if(num2!=0 && num1 % num2 == 0)
	{
		key = num1 / num2;
		cout << " num1%num2=" << key << endl;
	}
	else
	{
		random2();
		mhzd();
	}
}


void add1()
{
	char mathnum[50] ;
	system("cls");
	srand((unsigned)time(NULL));
	cout << "请输入题数:" << endl;
	cin >> count;
	count1 =count;
	while(count
	{
		random1();
		m();
		cin >> answer;
		if(key == answer)
		{
			cout << "答对了！" << endl;
			score++;
		}
		else
		{
			cout << "答错咯T^T <<'\b';
			cout << "正确答案是:" << key <<endl;
		}
	}
	cout << "共答对" << count1     << "共答错" <<  count1score[i]   <<"正确率为:" << (float)(score/count1)*100   << endl;
	flush
	getchar();
}
void add2()
{
	system("cls");
	srand((unsigned)time(NULL));
	cout << "请输入题数:" << endl;
	cin >> count;
	count1 =count;
	int q = count/2;
	int w = (count-q)/2;
	int e = count-q-w;
	while(q
	{
		char mathnum[100];
		random1();
		s();
		cin >> answer;
		if(key == answer)
		{
			cout << "答对了！" << endl;
			score++;
		}
		else
		{
			cout << "答错咯T^T <<'\b';
			cout << "正确答案是:" << key <<endl;
		}
	}
	while(e
	{
		char mathnum[50];
		random1();
		mh();
		cin >> answer;
		if(key == answer)
		{
			cout << "答对了！" << endl;
			score++;
		}
		else
		{
			cout << "答错咯T^T <<'\b';
			cout << "正确答案是:" << key <<endl;
		}
	}
	while(w
	{
		char mathnum1[100];
		char mathnum2[10];
		random2();
		mhzd();
		cin >> answer;
		if(key == answer)
		{
			cout << "答对了！" << endl;
			score++;
		}
		else
		{
			cout << "答错咯T^T <<'\b';
			cout << "正确答案是:" << key <<endl;
		}
	}
	cout << "共答对" << count1     << "共答错" <<  count1score[i]   <<"正确率为:" << (float)(score/count1)*100   << endl;
	flush
	getchar();
}
void add3()
{
	system("cls");
	srand((unsigned)time(NULL));
	cout << "请输入题数:" << endl;
	cin >> count;
	count1 =count;
	int q = count/2;
	int w = (count-q)/2;
	int e = count-q-w;
	while(q-->0)
	{
		char mathnum[100];
		random1();
		s();
		cin >> answer;
		if(key == answer)
		{
			cout << "答对了！" << endl;
			score++;
		}
		else
		{
			cout << "答错咯T^T <<'\b';
			cout << "正确答案是:" << key <<endl;
		}
	}
	while(e-->0)
	{
		char mathnum[50];
		random1();
		mh();
		cin >> answer;
		if(key == answer)
		{
			cout << "答对了！" << endl;
			score++;
		}
		else
		{
			cout << "答错咯T^T <<'\b';
			cout << "正确答案是:" << key <<endl;
		}
	}
	while(w-->0)
	{
		char mathnum1[100];
		char mathnum2[10];
		random2();
		mhzd();
		cin >> answer;
		if(key == answer)
		{
			cout << "答对了！" << endl;
			score++;
		}
		else
		{
			cout << "答错咯T^T <<'\b';
			cout << "正确答案是:" << key <<endl;
		}
	}
	cout << "共答对" << count1     << "共答错" <<  count1score[i]   <<"正确率为:" << (float)(score/count1)*100   << endl;
	flush
	getchar();
}

void main()
{
	ofstream fout("users.dat",ios::app);、
	string username;
	string p;
	if(fout == 0)
	{
		cerr << "输出文件创建失败" << endl;
		exit(1);
	}
	while(1)
	{
		cout << endl <<  "用户名:" << flush;
		if(!(cin >> username))
		{
			break;
		}
		cout << endl << "密码:" <<flush;
		char c;
		for(int i = 0;i<5;i++)
		{
			c=getch();
			if(c=='\b')
			{
				 if(i == 0)
				{
					i = -1;
					continue;
				}
				putch('\b');
				putch(' ');
				putch('\b');
				i = i-2;
				p.erase(i+1); 
				continue;
			}
			p += c;
			putch('*');
		}
		cout << endl;
		fout << username << '\t' << password << '\n';
	}
	fout.close();


	ifstream fin("users.dat",ios::in);
	string p;
	string username;
	while(fin >> username >> p)
	{
		cout << username << "\t" << p <<endl;
	}

	char *contents[3];
	contents[0]="enter";
	contents[1]="register";
	contents[2]="exit";
	showMenu(20,30,"Grade Menu",contents,3);
	system("cls");

	char c;
	cout << " 输入"0"退出，按其他键重新选择！" << endl;
	while((getchar())!='0')
	{
	system("cls");
	cout << "请选择您要挑战的难度!" << endl;
	cout << "1" << "简单" << endl;
	cout << "2" << "一般" << endl;
	cout << "3" << "困难" << endl;
	c = getchar();
	system("cls");
		switch(c)
	{
	case '1':add1;
		break;
	case'2':add2;
		break;
	case'3':add3;
		break;
	default:cout << "输入错误，请重新输入:" << endl;
		break;
	}
}

	ofstream fout("users1.dat",ios::out);
	User user;
	if(fout == 0)
	{
		cerr << "输出文件创建失败" << endl;
		exit(1);
	}
	int index = 0;
	while(1)
	{
		cout << endl <<  "用户名:" << flush;
		if(!(cin >> user.username))
		{
			break;
		}
		cout << endl << "密码:" <<flush;
		char c;
		for(int i = 0;i<5;i++)
		{
			c=getch();
			if(c=='\b')
			{
				 if(i == 0)
				{
					i = -1;
					continue;
				}
				putch('\b');
				putch(' ');
				putch('\b');
				i = i-2;
			
				continue;
			}
			user.p[i] = c;
			putch('*');
		}
		user.p[i] ='\0';
		cout << endl;
		fout.seekp(index * sizeof(user));
		fout.write(reinterpret_cast<const char*> (&user),sizeof(User));
		index++;
	}
	fout.close();
}


	ifstream fin("users1.dat",ios::in);
	User user;
	if(fin == 0)
	{
		cerr << "输入文件读取失败" << endl;
		exit(1);
	}
	int i = 0;
	while(fin != 0 && ! fin.eof())
	{
		fin.seekg(i *sizeof(user));
		fin.read(reinterpret_cast<char*>(&user),sizeof(User));
		cout << user.username << "\t" << user.p << endl;
		i++;
	}
while(1)
	{
		fin.seekg(i *sizeof(user));
		if((fin.read(reinterpret_cast<char*>(&user),sizeof(User))).eof())
		{
			break;
		}
		cout << user.username << "\t" << user.p << endl;
		i++;
	}
	fin.seekg( 1 *sizeof(user));
	fin.read(reinterpret_cast<char*>(&user),sizeof(User));
	cout << user.username << "\t" << user.p << endl;




}


}

