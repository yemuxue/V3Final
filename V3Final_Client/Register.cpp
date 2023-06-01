#include"Functions.h"

void Register(vector<player>& playerList, vector<Qmaker>& QmakerList)//�û�ע��
{
    int choice, Flag = 1;
    char c;//�����ַ�
    string name, password;
    cout << "\t/* ������ע������: */" << endl;
    cout << "\t/* ������---1 */" << endl;
    cout << "\t/* ������---2 */" << endl;
    cin >> choice;
    while (cin.fail() || (choice != 1 && choice != 2))
    {
        cin.clear();
        cout << "\t/* ����������ע������: */" << endl;
        cout << "\t/* ������---1 */" << endl;
        cout << "\t/* ������---2 */" << endl;
        cin >> choice;
    }
    while (Flag == 1)
    {
        cout << "\t/* �������û���: */" << endl;
        cin >> name;
        if (choice == 1)
        {
            vector<player>::iterator player_iterator = playerList.begin();//������
            for (; player_iterator != playerList.end(); player_iterator++)
            {
                if (player_iterator->get_name() == name)
                {
                    cout << "\t/* �����ѱ�ռ��! */" << endl;
                    break;
                }
            }
            if (player_iterator == playerList.end())
                Flag = 0;
        }
        else
        {
            vector<Qmaker>::iterator Qmaker_iterator = QmakerList.begin();
            for (; Qmaker_iterator != QmakerList.end(); Qmaker_iterator++)
            {
                if (Qmaker_iterator->get_name() == name)
                {
                    cout << "\t/* �����ѱ�ռ��! */" << endl;
                    break;
                }
            }
            if (Qmaker_iterator == QmakerList.end())
                Flag = 0;
        }
    }
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
    if (choice == 1)
    {
        player new_player(name, password);
        fstream fp_player;
        fp_player.open("playerList.csv", ios::app);
        if (!fp_player)
        {
            cout << "\t/* �� playerList.csv ʧ��! */" << endl;
            abort();
        }
        fp_player << "\n" << name << "," << password << ",0,0,0";
        fp_player.close();
        playerList.push_back(new_player);
        cout << "\t/* ע��ɹ���*/" << endl;
    }
    else
    {
        Qmaker new_Qmaker(name, password);
        fstream fp_Qmaker;
        fp_Qmaker.open("QmakerList.csv", ios::app);
        if (!fp_Qmaker)
        {
            cout << "\t/* �� QmakerList.csv ʧ��! */" << endl;
            abort();
        }
        fp_Qmaker << "\n" << name << "," << password << ",0,0";
        fp_Qmaker.close();
        QmakerList.push_back(new_Qmaker);
        cout << "\t/* ע��ɹ���*/" << endl;
    }
}