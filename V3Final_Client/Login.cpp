#include"Functions.h"

int player_Login(vector<player>& playerList)//�����ߵ�¼,�����������б��еĶ�Ӧλ��(����-1)
{
	int offset = -1;
	char c;//�����ַ�
	string name;
	string password;
	cout << "\t/* �����ߵ�¼ */" << endl << "����������: " << endl;
	cin >> name;
	for (vector<player>::iterator player_iterator = playerList.begin(); player_iterator != playerList.end(); player_iterator++)
	{
		if (player_iterator->get_name() == name)
		{
			cout << "\t/* ����������: */" << endl;
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
		cout << "\t/* ��½ʧ�� */" << endl;
	else
		cout << "\t/* �ɹ���¼! */" << endl;
	return offset;//����ƫ����
}

int Qmaker_Login(vector<Qmaker>& QmakerList)////�����ߵ�¼,�����������б��еĶ�Ӧλ��(����-1)
{
	int offset = -1;
	char c;//�����ַ�
	string name;
	string password;
	cout << "\t/* �����ߵ�¼ */" << endl << "����������: " << endl;
	cin >> name;
	for (vector<Qmaker>::iterator Qmaker_iterator = QmakerList.begin(); Qmaker_iterator != QmakerList.end(); Qmaker_iterator++)
	{
		if (Qmaker_iterator->get_name() == name)
		{
			cout << "\t/* ����������: */" << endl;
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
		cout << "\t/* ��½ʧ�� */" << endl;
	else
		cout << "\t/* �ɹ���¼! */" << endl;
	return offset;
}