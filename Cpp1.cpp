/*����ϵͳ
��¼���û����������ס/����ס��ע��
ѡ���Ѷ�   �����ͻ���
Ĭ��100�ڿ�ѡ��
��ʱ������ϰ       
ʱ��5��������    
���žų˷����ѡ����ʾ���
�������
��ʾ׼ȷ��  ���� ʱ��   
��������  ����  ĳ���͹���
������һ����
�û���ʷ��¼����
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
	void choose();//ѡ��
	void logo();//�˵�
	void dl();//��¼
	void register();//ע��
	void cy_e();
	void cy_m();
	void cy_d();
	void gxsj();//��������
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

	cout <<"  �Ӽ��˳�����ϵͳ  " << endl;
	cout << "���������'\n'1.����Ҫ�������û�����������ܵ�¼������������û�������ע��'\n'" << "2.���鿪ʼ��ϵͳ���������һ��0~99����������⣬��������ѡ��������ʱ�����������'\n'" <<"3.����������ϵͳ����ʾ�������'\n'" << "4.������ȷÿ�μ�10���ֻ�20���ֻ�40����'\n'";
	cout <<"=================" << endl;
	cout <<"     1 ��¼      " << endl;
	cout <<"     2 ע��      " << endl;
	cout <<"=================" << endl;
	choose();

}
	
void Users::choose()
{
	int cho;
	cout << "���������ѡ��:\n1.ֱ�ӵ�¼\n2.ע��\n\n";
	cout <<"     ��ѡ��:      " << endl;
	do 
	{
		cin >> cho;
		if(cho!=1&&cho!=2)
			cerr << "��������������\n����������:";
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
	cout << "\n��¼\n\n";
	char c;
	int i = 0;
	bool p =false;//��¼ʧ��
	ifstream fin("users1.dat");
	if(!fin)
	{
		cerr << "�Բ��𣬶�ȡ�û���Ϣʧ�ܣ�" << endl;
		logo();
	}
	fin >> n;//��ȡ�û�����
	cout << " �����������û���:";
	cin >> username;
	cout <<"��������������:";
	cin >>password;
	cout << "�밴�س�����¼\n";
	system("pause>nul");
	for(num = 0;num<6;num++)
	{

		fin >> username0[num] >> password0[num] >> score0[num];//��ȡ������û���Ϣ
		if(username == username0[num]&&p == password0[num])
		{
			p = true;//�ɹ�
			score = score0[num];//��ȡ����
			cout << "��¼�ɹ�!\n";
			cout << endl << username << ",��Ŀǰ����Ϊ:" << score << endl;
			cout << "�밴�س�����ʼ��ϰ\n";
			system("pause>nul");
			fin.close();
			choose_level();
			break;
		}
	}
	if(p = false)
	{
		fin.close();
		cerr << "�û������������\n\n";
		cout << "���Ƿ���Ҫ���µ�¼��(Y/N)\n������Y��N:";
		do
		{
			cin >> c;
			if(c!='y'&&c!='Y'&&c!='n'&&c!='N')
				cerr << "������������\n����������:";
		}while(c!='y'&&c!='Y'&&c!='n'&&c!='N');
		if(c=='y'||c=='Y')
		{
			cout << endl;
			dl();
		}
		else
		{
			cout << "\n���Ƿ���Ҫ����ע�᣿(Y/N)\n������Y��N:";
			do
			{
				cin >> c;
				if(c!='y'&&c!='Y'&&c!='n'&&c!='N')
				{
					cerr << "������������\n����������:";
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
	cout << "\nע��\n\n";
	char c;
	int i;
	ifstream fin("users1.dat",ios::in);
	if(!fin)
	{
		cerr << "��ȡ�ļ�ʧ�ܣ�\n";
		logo();
	}
	fin >> n;//��ȡ�û�����
	for(i=0;i<n;i++)
	{
		fin >> username0[i] >> password0[i] >> score0[i];
	}
	ofstream fout("users1.dat");
	if(!fout)
	{
		cerr << "��ȡ�ļ�ʧ�ܣ�\n";
		logo();
	}
	fin.close();
	cout << "�����������û���:";
	cin >> username;
	do 
	{
		cout << "��������������:";
		cin >> password;
		cout << "���ٴ�������������:";
		cin >> password2;
		if(password!=password2)
		{
			cerr << "�����������벻һ�£���������д:\n";
		}
	}
	while(password != password2);
	cout << "ע��ɹ���\n";
	username0[n] = username;
	password0[n] = password;
	score0[n] = score;
	n++;
	fout << i <<'\n';
	for(i=0;i<n;i++)
	{
		fout << username0[i] << " " << password0[i] << " " << score0[i] << '\n';//ע����Ϣ�����ļ�
	}
	fout.close();
	cout << "\n���Ƿ���������¼��(Y/N)\n������Y��N:";
	do
	{
		cin >> c;
		if(c!='y'&&c!='Y'&&c!='n'&&c!='N')
				cerr << "������������\n����������:";
	}while(c!='y'&&c!='Y'&&c!='n'&&c!='N');
	if(c=='y'||c=='Y')
		dl();
	else exit(1);
}*/
/*void Users::choose_level()
{
	int cho;
	system("cls");
	cout << "\n�������\n\n";
	cout << "��ѡ������:\n" << "1.�Ӽ�\n" << "2.�˷�\n" << "3.����\n" << endl;
	cout << "���������ѡ��:";
	do
	{
		cin >> cho;
		if(cho < 1||cho>3)
			cerr << "��������������\n����������:";
	}while(cho < 1||cho>3);
	switch(cho)
	{
	case 1:cy_e();break;
	case 2:cy_m();break;
	case 3:cy_d();break;
	default:cout << " �����������������:" << endl;break;

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
	cout << "����������:" << endl;
	cin >> count;
	count1 =count;
	while(count>=0)
	{
		random1();
		cy_e();
		cin >> answer;
		if(key == answer)
		{
			cout << "����ˣ�" << endl;
			score++;
		}
		else
		{
			cout << "���T^T <<'\b';
			cout << "��ȷ����:" << key <<endl;
		}
	}
	cout << "�����" << count1     << "�����" <<  count1score[i]   <<"��ȷ��Ϊ:" << (float)(score/count1)*100   << endl;
	flush
	getchar();
}
void Users::add2()
{
	system("cls");
	srand((unsigned)time(NULL));
	cout << "����������:" << endl;
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
			cout << "����ˣ�" << endl;
			score++;
		}
		else
		{
			cout << "���T^T <<'\b';
			cout << "��ȷ����:" << key <<endl;
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
			cout << "����ˣ�" << endl;
			score++;
		}
		else
		{
			cout << "���T^T <<'\b';
			cout << "��ȷ����:" << key <<endl;
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
			cout << "����ˣ�" << endl;
			score++;
		}
		else
		{
			cout << "���T^T <<'\b';
			cout << "��ȷ����:" << key <<endl;
		}
	}
	cout << "�����" << count1     << "�����" <<  count1score[i]   <<"��ȷ��Ϊ:" << (float)(score/count1)*100   << endl;
	flush
	getchar();
}
void Users::add3()
{
	system("cls");
	srand((unsigned)time(NULL));
	cout << "����������:" << endl;
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
			cout << "����ˣ�" << endl;
			score++;
		}
		else
		{
			cout << "���T^T <<'\b';
			cout << "��ȷ����:" << key <<endl;
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
			cout << "����ˣ�" << endl;
			score++;
		}
		else
		{
			cout << "���T^T <<'\b';
			cout << "��ȷ����:" << key <<endl;
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
			cout << "����ˣ�" << endl;
			score++;
		}
		else
		{
			cout << "���T^T <<'\b';
			cout << "��ȷ����:" << key <<endl;
		}
	}
	cout << "�����" << count1     << "�����" <<  count1score[i]   <<"��ȷ��Ϊ:" << (float)(score/count1)*100   << endl;
	flush
	getchar();
}
void Users::gxsj ()
{	
	ifstream fin("users1.dat",ios::in);
	Users users;
	if(fin == 0)
	{
		cerr << "�����ļ���ȡʧ��" << endl;
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
		cerr << "����ļ�����ʧ��" << endl;
		exit(1);
	}
	int index = 0;
	while(1)
	{
		cout << endl <<  "�û���:" << flush;
		if(!(cin >> users.username))
		{
			break;
		}
		cout << endl << "����:" <<flush;
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






	

	
			
	
