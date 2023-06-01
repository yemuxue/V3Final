#include"Functions.h"

bool comp_word(string& x, string& y)
{
    return x.length() < y.length();//从短至长排序
}

void extract_full(string& s, const string& c, vector<string>& v)//提取","分割函数
{
    int pos1, pos2;
    pos1 = 0;
    pos2 = s.find(c, pos1);//每次都从pos1开始
    while (string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2 - pos1));//后者为长度
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length())
        v.push_back(s.substr(pos1));//接上剩下
}

bool rank_pass(player& player_1, player& player_2)//按通关数排名
{
    return player_1.get_level() > player_2.get_level();
}

bool rank_exp(player& player_1, player& player_2)//按经验排名
{
    return player_1.get_exp() > player_2.get_exp();
}

bool rank_level_player(player& player_1, player& player_2)//按答题者等级排名
{
    return player_1.get_level() > player_2.get_level();
}

bool rank_level_Qmaker(Qmaker& Qmaker_1, Qmaker& Qmaker_2)//按出题者等级排名
{
    return Qmaker_1.get_level() > Qmaker_2.get_level();
}

bool rank_questionNum(Qmaker& Qmaker_1, Qmaker& Qmaker_2)//按出题数排名
{
    return Qmaker_1.get_questionNum() > Qmaker_2.get_questionNum();
}

void rank_user(vector<player>& playerList, vector<Qmaker>& QmakerList)//对用户排名
{
    vector<player> temp_playerList = playerList;
    vector<Qmaker> temp_QmakerList = QmakerList;
    int classifi = 0;
    int according = 0;
    int Flag = 0;
    while (classifi != 1 && classifi != 2)
    {
        cout << "\t/* 请输入排序类别 */" << endl;
        cout << "\t/* 答题者---1 */" << endl;
        cout << "\t/* 出题者---2 */" << endl;
        cin >> classifi;
        while (classifi == 1)
        {
            cout << "\t/* 请输入排序依据 */" << endl;
            cout << "\t/* 关卡数---1 */" << endl;
            cout << "\t/* 经验-----2 */" << endl;
            cout << "\t/* 等级-----3 */" << endl;
            cin >> according;
            if (according == 1)
                sort(temp_playerList.begin(), temp_playerList.end(), rank_pass);
            else if (according == 2)
                sort(temp_playerList.begin(), temp_playerList.end(), rank_exp);
            else if (according == 3)
                sort(temp_playerList.begin(), temp_playerList.end(), rank_level_player);
            if (according == 1 || according == 2 || according == 3)
            {
                Flag = 1;
                cout << "名字\t\t等级\t经验\t关卡" << endl;
                for (int i = 0; i < playerList.size(); i++)
                    cout << temp_playerList[i].get_name() << "\t\t" << temp_playerList[i].get_level() << "\t" << temp_playerList[i].get_exp() << "\t" << temp_playerList[i].get_pass() << endl;
                break;
            }
        }
        while (classifi == 2)
        {
            cout << "\t/* 请输入排序依据 */" << endl;
            cout << "\t/* 等级-----1 */" << endl;
            cout << "\t/* 出题数---2 */" << endl;
            cin >> according;
            if (according == 1)
                sort(temp_QmakerList.begin(), temp_QmakerList.end(), rank_level_Qmaker);
            else if (according == 2)
                sort(temp_QmakerList.begin(), temp_QmakerList.end(), rank_questionNum);
            if (according == 1 || according == 2)
            {
                Flag = 1;
                cout << "名字\t\t等级\t出题数 " << endl;
                for (int i = 0; i < temp_QmakerList.size(); i++)
                    cout << temp_QmakerList[i].get_name() << "\t\t" << temp_QmakerList[i].get_level() << "\t" << temp_QmakerList[i].get_questionNum() << endl;
                break;
            }
        }
        if (Flag == 1)
            break;
    }
}

void query_data(vector<player>& playerList, vector<Qmaker>& QmakerList)//查询
{
    int classifi = 0;//类别
    int according = 0;//依据
    int query_level;//查询等级
    int query_questionNum;//查询出题数
    int query_exp;//查询经验
    int query_pass;//查询关卡数
    int Flag = 0;//标志位
    int count = 0;//计数
    string query_name;
    while (classifi != 1 && classifi != 2)
    {
        cout << "\t/* 请输入查询类别 */" << endl;
        cout << "\t/* 答题者---1 */" << endl;
        cout << "\t/* 出题者---2 */" << endl;
        cin >> classifi;
        while (classifi == 1)
        {
            cout << "\t/* 请输入查询依据 */" << endl;
            cout << "\t/* 名字-----1 */" << endl;
            cout << "\t/* 经验-----2 */" << endl;
            cout << "\t/* 等级-----3 */" << endl;
            cout << "\t/* 关卡数---4 */" << endl;
            cin >> according;
            if (according == 1)
            {
                cout << "\t/* 输入查询名字 */" << endl;
                cin >> query_name;
                vector<player>::iterator player_iterator = playerList.begin();
                for (; player_iterator != playerList.end(); player_iterator++)
                {
                    if (player_iterator->get_name() == query_name)
                    {
                        cout << "名字\t\t等级\t经验\t关卡" << endl;
                        cout << player_iterator->get_name() << "\t\t" << player_iterator->get_level() << "\t" << player_iterator->get_exp() << "\t" << player_iterator->get_pass() << endl;
                        break;
                    }
                }
                if (player_iterator == playerList.end())
                    cout << "\t/* 查无此人! */" << endl;
            }
            else if (according == 2)
            {
                count = 0;
                cout << "\t/* 输入查询经验 */" << endl;
                cin >> query_exp;
                vector<player>::iterator player_iterator = playerList.begin();
                for (; player_iterator != playerList.end(); player_iterator++)
                {
                    if (player_iterator->get_exp() == query_exp)
                    {
                        if (count == 0)
                            cout << "名字\t\t等级\t经验\t关卡" << endl;
                        cout << player_iterator->get_name() << "\t\t" << player_iterator->get_level() << "\t" << player_iterator->get_exp() << "\t" << player_iterator->get_pass() << endl;
                        count++;
                    }
                }
                if (count == 0)
                    cout << "\t/* 无人该经验! */" << endl;
            }
            else if (according == 3)
            {
                count = 0;
                cout << "\t/* 输入查询等级 */" << endl;
                cin >> query_level;
                vector<player>::iterator player_iterator = playerList.begin();
                for (; player_iterator != playerList.end(); player_iterator++)
                {
                    if (player_iterator->get_level() == query_level)
                    {
                        if (count == 0)
                            cout << "名字\t\t等级\t经验\t关卡" << endl;
                        cout << player_iterator->get_name() << "\t\t" << player_iterator->get_level() << "\t" << player_iterator->get_exp() << "\t" << player_iterator->get_pass() << endl;
                        count++;
                    }
                }
                if (count == 0)
                    cout << "\t/* 无人该等级! */" << endl;
            }
            else if (according == 4)
            {
                count = 0;
                cout << "\t/* 输入查询关卡数 */" << endl;
                cin >> query_pass;
                vector<player>::iterator player_iterator = playerList.begin();
                for (; player_iterator != playerList.end(); player_iterator++)
                {
                    if (player_iterator->get_pass() == query_pass)
                    {
                        if (count == 0)
                            cout << "名字\t\t等级\t经验\t关卡" << endl;
                        cout << player_iterator->get_name() << "\t\t" << player_iterator->get_level() << "\t" << player_iterator->get_exp() << "\t" << player_iterator->get_pass() << endl;
                        count++;
                    }
                }
                if (count == 0)
                    cout << "\t/* 无人该关卡数! */" << endl;
            }
            if (according == 1 || according == 2 || according == 3 || according == 4)
            {
                Flag = 1;
                break;
            }
        }
        while (classifi == 2)
        {
            cout << "\t/* 请输入查询依据 */" << endl;
            cout << "\t/* 名字-----1 */" << endl;
            cout << "\t/* 等级-----2 */" << endl;
            cout << "\t/* 出题数---3 */" << endl;
            cin >> according;
            if (according == 1)
            {
                cout << "\t/* 输入查询名字 */" << endl;
                cin >> query_name;
                vector<Qmaker>::iterator Qmaker_iterator = QmakerList.begin();
                for (; Qmaker_iterator != QmakerList.end(); Qmaker_iterator++)
                {
                    if (Qmaker_iterator->get_name() == query_name)
                    {
                        cout << "名字\t\t等级\t出题数 " << endl;
                        cout << Qmaker_iterator->get_name() << "\t\t" << Qmaker_iterator->get_level() << "\t" << Qmaker_iterator->get_questionNum() << endl;
                        break;
                    }
                }
                if (Qmaker_iterator == QmakerList.end())
                    cout << "\t/* 查无此人! */" << endl;
            }
            else if (according == 2)
            {
                count = 0;
                cout << "\t/* 输入查询等级 */" << endl;
                cin >> query_level;
                vector<Qmaker>::iterator Qmaker_iterator = QmakerList.begin();
                for (; Qmaker_iterator != QmakerList.end(); Qmaker_iterator++)
                {
                    if (Qmaker_iterator->get_level() == query_level)
                    {
                        if (count == 0)
                            cout << "名字\t\t等级\t出题数 " << endl;
                        cout << Qmaker_iterator->get_name() << "\t\t" << Qmaker_iterator->get_level() << "\t" << Qmaker_iterator->get_questionNum() << endl;
                        count++;
                    }
                }
                if (count == 0)
                    cout << "\t/* 无人该等级! */" << endl;
            }
            else if (according == 3)
            {
                count = 0;
                cout << "\t/* 输入查询出题数 */" << endl;
                cin >> query_questionNum;
                vector<Qmaker>::iterator Qmaker_iterator = QmakerList.begin();
                for (; Qmaker_iterator != QmakerList.end(); Qmaker_iterator++)
                {
                    if (Qmaker_iterator->get_questionNum() == query_questionNum)
                    {
                        if (count == 0)
                            cout << "名字\t\t等级\t出题数 " << endl;
                        cout << Qmaker_iterator->get_name() << "\t\t" << Qmaker_iterator->get_level() << "\t" << Qmaker_iterator->get_questionNum() << endl;
                        count++;
                    }
                }
                if (count == 0)
                    cout << "\t/* 无人该出题数! */" << endl;
            }
            if (according == 1 || according == 2 || according == 3)
            {
                Flag = 1;
                break;
            }
        }
        if (Flag == 1)
            break;
    }
}