/*速算系统
登录（用户名，密码记住/不记住）注册
选择难度   单题型或混合
默认100内可选择
定时定量练习       
时间5秒内提醒    
（九九乘法表可选择显示与否）
数字随机
显示准确率  题数 时间   
奖励积分  评价  某题型过关
提醒下一题型
用户历史记录保存
*/

#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<conio.h>
# define A  rand()%100
using namespace std;
class Users
{
public:
	Users();
	char username0[50];
	char password0[50];
	char score0[100];
	string username;
	string password;
	string password2;
	int n,num,score;
private:
	void choose();//选择
	void logo();//菜单
	void dl();//登录
	void register();//注册
	void cy_e();
	void cy_m();
	void cy_d();
	void gxsj();//更新数据
	void choose_level();
	
};
void Users::users()
{
	int score = 0;
	int num = 0;
	ifstream fin("users1.dat");
	if(!fin)
	{
		ofstream fout("users1.dat");
		fout << 0 <<'\n';
		fout.close();
	}
	fin.close();
}

void Users::logo()
{
	system("cls");

	cout <<"  加减乘除速算系统  " << endl;
	cout << "软件声明：'\n'1.您需要有您的用户名及密码才能登录，如果您是新用户，请先注册'\n'" << "2.测验开始后，系统将随机产生一道0~99的随机算术题，根据您的选择您将有时间或题数的限'\n'" <<"3.如果计算错误，系统将提示结果错误'\n'" << "4.计算正确每次加10积分或20积分或40积分'\n'";
	cout <<"=================" << endl;
	cout <<"     1 登录      " << endl;
	cout <<"     2 注册      " << endl;
	cout <<"=================" << endl;
	choose();

}
	
void Users::choose()
{
	int cho;
	cout << "请输入序号选择:\n1.直接登录\n2.注册\n\n";
	cout <<"     请选择:      " << endl;
	do 
	{
		cin >> cho;
		if(cho!=1&&cho!=2)
			cerr << "您输入的序号有误！\n请重新输入:";
	}while(cho!=1&&cho!=2);
	switch(cho)
	{
	case 1:dl();break;
	default:register();break;
	}
}
void Users::dl()
{
	logo();
	cout << "\n登录\n\n";
	char c;
	int i = 0;
	bool p =false;//登录失败
	ifstream fin("users1.dat");
	if(!fin)
	{
		cerr << "对不起，读取用户信息失败！" << endl;
		logo();
	}
	fin >> n;//读取用户个数
	cout << " 请输入您的用户名:";
	cin >> username;
	cout <<"请输入您的密码:";
	cin >>password;
	cout << "请按回车键登录\n";
	system("pause>nul");
	for(num = 0;num<6;num++)
	{

		fin >> username0[num] >> password0[num] >> score0[num];//读取并存放用户信息
		if(username == username0[num]&&p == password0[num])
		{
			p = true;//成功
			score = score0[num];//读取分数
			cout << "登录成功!\n";
			cout << endl << username << ",您目前积分为:" << score << endl;
			cout << "请按回车键开始练习\n";
			system("pause>nul");
			fin.close();
			choose_level();
			break;
		}
	}
	if(p = false)
	{
		fin.close();
		cerr << "用户名或密码错误！\n\n";
		cout << "您是否需要重新登录？(Y/N)\n请输入Y或N:";
		do
		{
			cin >> c;
			if(c!='y'&&c!='Y'&&c!='n'&&c!='N')
				cerr << "您的输入有误！\n请重新输入:";
		}while(c!='y'&&c!='Y'&&c!='n'&&c!='N');
		if(c=='y'||c=='Y')
		{
			cout << endl;
			dl();
		}
		else
		{
			cout << "\n您是否需要立即注册？(Y/N)\n请输入Y或N:";
			do
			{
				cin >> c;
				if(c!='y'&&c!='Y'&&c!='n'&&c!='N')
				{
					cerr << "您的输入有误！\n请重新输入:";
				}
			}while(c!='y'&&c!='Y'&&c!='n'&&c!='N');
			if(c=='y'||c=='Y')
			{
				cout << endl;
				register();
			}
			else exit(1);
		}
	}
}
/*void Users::register()
{
	logo();
	cout << "\n注册\n\n";
	char c;
	int i;
	ifstream fin("users1.dat",ios::in);
	if(!fin)
	{
		cerr << "读取文件失败！\n";
		logo();
	}
	fin >> n;//读取用户数量
	for(i=0;i<n;i++)
	{
		fin >> username0[i] >> password0[i] >> score0[i];
	}
	ofstream fout("users1.dat");
	if(!fout)
	{
		cerr << "读取文件失败！\n";
		logo();
	}
	fin.close();
	cout << "请输入您的用户名:";
	cin >> username;
	do 
	{
		cout << "请输入您的密码:";
		cin >> password;
		cout << "请再次输入您的密码:";
		cin >> password2;
		if(password!=password2)
		{
			cerr << "两次密码输入不一致！请重新填写:\n";
		}
	}
	while(password != password2);
	cout << "注册成功！\n";
	username0[n] = username;
	password0[n] = password;
	score0[n] = score;
	n++;
	fout << i <<'\n';
	for(i=0;i<n;i++)
	{
		fout << username0[i] << " " << password0[i] << " " << score0[i] << '\n';//注册信息存入文件
	}
	fout.close();
	cout << "\n您是否想立即登录？(Y/N)\n请输入Y或N:";
	do
	{
		cin >> c;
		if(c!='y'&&c!='Y'&&c!='n'&&c!='N')
				cerr << "您的输入有误！\n请重新输入:";
	}while(c!='y'&&c!='Y'&&c!='n'&&c!='N');
	if(c=='y'||c=='Y')
		dl();
	else exit(1);
}*/
/*void Users::choose_level()
{
	int cho;
	system("cls");
	cout << "\n速算测验\n\n";
	cout << "请选择类型:\n" << "1.加减\n" << "2.乘法\n" << "3.除法\n" << endl;
	cout << "请输入序号选择:";
	do
	{
		cin >> cho;
		if(cho < 1||cho>3)
			cerr << "您输入的序号有误！\n请重新输入:";
	}while(cho < 1||cho>3);
	switch(cho)
	{
	case 1:cy_e();break;
	case 2:cy_m();break;
	case 3:cy_d();break;
	default:cout << " 输入错误，请重新输入:" << endl;break;

	}
}
void Users::cy_e ()
{
	system("cls");
	num1 = A;
	num2 = A;
	if(num1 >= num2)
	{
		key = num1 - num2;
		cout << "num1 - num2 = " << key << endl;
			else if(num1 + num2 > mathnum[i])
		{
			random1();
			cy_m
	}
		}
	else
	{
		key = num1 +num2;
		cout << "num1 + num2 = " << key << endl;
	}
} 
void Users::cy_m()
{
	key = num1 * num2;
	cout << "num1 * num2 = " << key << endl;
}
void Users::cy_d()
{
	if(num2!=0 && num1 % num2 == 0)
	{
		key = num1 / num2;
		cout << " num1%num2=" << key << endl;
	}
	else
	{
		random2();
		cy_d();
	}
}
void Users::add1()
{
	system("cls");
	char mathnum[50] ;
	srand((unsigned)time(NULL));
	cout << "请输入题数:" << endl;
	cin >> count;
	count1 =count;
	while(count>=0)
	{
		random1();
		cy_e();
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
void Users::add2()
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
		cy_m();
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
		cy_d();
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
void Users::add3()
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
		cy_e();
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
		cy_d();
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
void Users::gxsj ()
{	
	ifstream fin("users1.dat",ios::in);
	Users users;
	if(fin == 0)
	{
		cerr << "输入文件读取失败" << endl;
		exit(1);
	}
	int i = 0;
	while(fin != 0 && ! fin.eof())
	{
		fin.seekg(i *sizeof(users));
		fin.read(reinterpret_cast<char*>(&users),sizeof(Users));
		cout << users.username << "\t" << users.password << "\t" << users.score << endl;
		i++;
	}
	while(1)
	{
		fin.seekg(i *sizeof(users));
		if((fin.read(reinterpret_cast<char*>(&users),sizeof(Users))).eof())
		{
			break;
		}
		cout << users.username << "\t" << users.password <<  "\t" << users.score << endl;
		i++;
	}
	fin.close();
	fin.seekg( 1 *sizeof(users));
	fin.read(reinterpret_cast<char*>(&users),sizeof(Users));
	cout << users.username << "\t" << users.password <<  "\t" << users.score << endl;


	ofstream fout("users1.dat",ios::out);
	if(fout == 0)
	{
		cerr << "输出文件创建失败" << endl;
		exit(1);
	}
	int index = 0;
	while(1)
	{
		cout << endl <<  "用户名:" << flush;
		if(!(cin >> users.username))
		{
			break;
		}
		cout << endl << "密码:" <<flush;
		char c;
		for(int i = 0;i<6;i++)
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
			users.password0[i] = c;
			putch('*');
		}
		users.password0[i] ='\0';
		cout << endl;
		fout.seekp(index * sizeof(users));
		fout.write(reinterpret_cast<const char*> (&users),sizeof(Users));
		index++;
	}
	fout.close();
	
}

void main()
{
srand((unsigned)time(0));
Users.logo();
}/*






	

	
			
	
