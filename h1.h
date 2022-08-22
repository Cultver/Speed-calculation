#include<iostream>
using namespace std;
class Users
{
public:
	Users();
	void zpm();
	char username[50]
	char password[50]
private:
	void choose();//选择
	void logo();//菜单
	void dl();//登录
	void register();//注册
	void cy_e();//测验_简单
	void cy_m();//测验_一般
	void cy_d();//测验_困难
	void gxsj();//更新数据
	void choose_level();//选择难度
	string username;
	string password;
	string password2;
	int n,num,score;
	int score0[100];
	string username0[50];
	string password0[50];



};