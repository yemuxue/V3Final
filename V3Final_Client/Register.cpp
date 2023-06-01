#include"Functions.h"

void Register(vector<player>& playerList, vector<Qmaker>& QmakerList)//用户注册
{
    int choice, Flag = 1;
    char c;//密码字符
    string name, password;
    cout << "\t/* 请输入注册类型: */" << endl;
    cout << "\t/* 答题者---1 */" << endl;
    cout << "\t/* 出题者---2 */" << endl;
    cin >> choice;
    while (cin.fail() || (choice != 1 && choice != 2))
    {
        cin.clear();
        cout << "\t/* 请重新输入注册类型: */" << endl;
        cout << "\t/* 答题者---1 */" << endl;
        cout << "\t/* 出题者---2 */" << endl;
        cin >> choice;
    }
    while (Flag == 1)
    {
        cout << "\t/* 请设置用户名: */" << endl;
        cin >> name;
        if (choice == 1)
        {
            vector<player>::iterator player_iterator = playerList.begin();//迭代器
            for (; player_iterator != playerList.end(); player_iterator++)
            {
                if (player_iterator->get_name() == name)
                {
                    cout << "\t/* 名字已被占用! */" << endl;
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
                    cout << "\t/* 名字已被占用! */" << endl;
                    break;
                }
            }
            if (Qmaker_iterator == QmakerList.end())
                Flag = 0;
        }
    }
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
    if (choice == 1)
    {
        player new_player(name, password);
        fstream fp_player;
        fp_player.open("playerList.csv", ios::app);
        if (!fp_player)
        {
            cout << "\t/* 打开 playerList.csv 失败! */" << endl;
            abort();
        }
        fp_player << "\n" << name << "," << password << ",0,0,0";
        fp_player.close();
        playerList.push_back(new_player);
        cout << "\t/* 注册成功！*/" << endl;
    }
    else
    {
        Qmaker new_Qmaker(name, password);
        fstream fp_Qmaker;
        fp_Qmaker.open("QmakerList.csv", ios::app);
        if (!fp_Qmaker)
        {
            cout << "\t/* 打开 QmakerList.csv 失败! */" << endl;
            abort();
        }
        fp_Qmaker << "\n" << name << "," << password << ",0,0";
        fp_Qmaker.close();
        QmakerList.push_back(new_Qmaker);
        cout << "\t/* 注册成功！*/" << endl;
    }
}