#include"Functions.h"

int player_Login(vector<player>& playerList)//答题者登录,返回名称在列表中的对应位置(或者-1)
{
	int offset = -1;
	char c;//密码字符
	string name;
	string password;
	cout << "\t/* 答题者登录 */" << endl << "请输入名字: " << endl;
	cin >> name;
	for (vector<player>::iterator player_iterator = playerList.begin(); player_iterator != playerList.end(); player_iterator++)
	{
		if (player_iterator->get_name() == name)
		{
			cout << "\t/* 请输入密码: */" << endl;
			while ((c = _getch()) != 13)
			{
				if (c == 8)
				{
					password = password.substr(0, password.length() - 1);
					cout << "\b \b";
				}
				else
				{
					password += c;
					cout << '*';
				}
			}
			cout << endl;
			if (player_iterator->get_password() == password)
				offset = player_iterator - playerList.begin();
			break;
		}
	}
	if (offset == -1)
		cout << "\t/* 登陆失败 */" << endl;
	else
		cout << "\t/* 成功登录! */" << endl;
	return offset;//返回偏移量
}

int Qmaker_Login(vector<Qmaker>& QmakerList)////出题者登录,返回名称在列表中的对应位置(或者-1)
{
	int offset = -1;
	char c;//密码字符
	string name;
	string password;
	cout << "\t/* 出题者登录 */" << endl << "请输入名字: " << endl;
	cin >> name;
	for (vector<Qmaker>::iterator Qmaker_iterator = QmakerList.begin(); Qmaker_iterator != QmakerList.end(); Qmaker_iterator++)
	{
		if (Qmaker_iterator->get_name() == name)
		{
			cout << "\t/* 请输入密码: */" << endl;
			while ((c = _getch()) != 13)
			{
				if (c == 8)
				{
					password = password.substr(0, password.length() - 1);
					cout << "\b \b";
				}
				else
				{
					password += c;
					cout << '*';
				}
			}
			cout << endl;
			if (Qmaker_iterator->get_password() == password)
				offset = Qmaker_iterator - QmakerList.begin();
			break;
		}
	}
	if (offset == -1)
		cout << "\t/* 登陆失败 */" << endl;
	else
		cout << "\t/* 成功登录! */" << endl;
	return offset;
}