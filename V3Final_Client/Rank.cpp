#include"Functions.h"

bool comp_word(string& x, string& y)
{
    return x.length() < y.length();//�Ӷ���������
}

void extract_full(string& s, const string& c, vector<string>& v)//��ȡ","�ָ��
{
    int pos1, pos2;
    pos1 = 0;
    pos2 = s.find(c, pos1);//ÿ�ζ���pos1��ʼ
    while (string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2 - pos1));//����Ϊ����
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length())
        v.push_back(s.substr(pos1));//����ʣ��
}

bool rank_pass(player& player_1, player& player_2)//��ͨ��������
{
    return player_1.get_level() > player_2.get_level();
}

bool rank_exp(player& player_1, player& player_2)//����������
{
    return player_1.get_exp() > player_2.get_exp();
}

bool rank_level_player(player& player_1, player& player_2)//�������ߵȼ�����
{
    return player_1.get_level() > player_2.get_level();
}

bool rank_level_Qmaker(Qmaker& Qmaker_1, Qmaker& Qmaker_2)//�������ߵȼ�����
{
    return Qmaker_1.get_level() > Qmaker_2.get_level();
}

bool rank_questionNum(Qmaker& Qmaker_1, Qmaker& Qmaker_2)//������������
{
    return Qmaker_1.get_questionNum() > Qmaker_2.get_questionNum();
}

void rank_user(vector<player>& playerList, vector<Qmaker>& QmakerList)//���û�����
{
    vector<player> temp_playerList = playerList;
    vector<Qmaker> temp_QmakerList = QmakerList;
    int classifi = 0;
    int according = 0;
    int Flag = 0;
    while (classifi != 1 && classifi != 2)
    {
        cout << "\t/* ������������� */" << endl;
        cout << "\t/* ������---1 */" << endl;
        cout << "\t/* ������---2 */" << endl;
        cin >> classifi;
        while (classifi == 1)
        {
            cout << "\t/* �������������� */" << endl;
            cout << "\t/* �ؿ���---1 */" << endl;
            cout << "\t/* ����-----2 */" << endl;
            cout << "\t/* �ȼ�-----3 */" << endl;
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
                cout << "����\t\t�ȼ�\t����\t�ؿ�" << endl;
                for (int i = 0; i < playerList.size(); i++)
                    cout << temp_playerList[i].get_name() << "\t\t" << temp_playerList[i].get_level() << "\t" << temp_playerList[i].get_exp() << "\t" << temp_playerList[i].get_pass() << endl;
                break;
            }
        }
        while (classifi == 2)
        {
            cout << "\t/* �������������� */" << endl;
            cout << "\t/* �ȼ�-----1 */" << endl;
            cout << "\t/* ������---2 */" << endl;
            cin >> according;
            if (according == 1)
                sort(temp_QmakerList.begin(), temp_QmakerList.end(), rank_level_Qmaker);
            else if (according == 2)
                sort(temp_QmakerList.begin(), temp_QmakerList.end(), rank_questionNum);
            if (according == 1 || according == 2)
            {
                Flag = 1;
                cout << "����\t\t�ȼ�\t������ " << endl;
                for (int i = 0; i < temp_QmakerList.size(); i++)
                    cout << temp_QmakerList[i].get_name() << "\t\t" << temp_QmakerList[i].get_level() << "\t" << temp_QmakerList[i].get_questionNum() << endl;
                break;
            }
        }
        if (Flag == 1)
            break;
    }
}

void query_data(vector<player>& playerList, vector<Qmaker>& QmakerList)//��ѯ
{
    int classifi = 0;//���
    int according = 0;//����
    int query_level;//��ѯ�ȼ�
    int query_questionNum;//��ѯ������
    int query_exp;//��ѯ����
    int query_pass;//��ѯ�ؿ���
    int Flag = 0;//��־λ
    int count = 0;//����
    string query_name;
    while (classifi != 1 && classifi != 2)
    {
        cout << "\t/* �������ѯ��� */" << endl;
        cout << "\t/* ������---1 */" << endl;
        cout << "\t/* ������---2 */" << endl;
        cin >> classifi;
        while (classifi == 1)
        {
            cout << "\t/* �������ѯ���� */" << endl;
            cout << "\t/* ����-----1 */" << endl;
            cout << "\t/* ����-----2 */" << endl;
            cout << "\t/* �ȼ�-----3 */" << endl;
            cout << "\t/* �ؿ���---4 */" << endl;
            cin >> according;
            if (according == 1)
            {
                cout << "\t/* �����ѯ���� */" << endl;
                cin >> query_name;
                vector<player>::iterator player_iterator = playerList.begin();
                for (; player_iterator != playerList.end(); player_iterator++)
                {
                    if (player_iterator->get_name() == query_name)
                    {
                        cout << "����\t\t�ȼ�\t����\t�ؿ�" << endl;
                        cout << player_iterator->get_name() << "\t\t" << player_iterator->get_level() << "\t" << player_iterator->get_exp() << "\t" << player_iterator->get_pass() << endl;
                        break;
                    }
                }
                if (player_iterator == playerList.end())
                    cout << "\t/* ���޴���! */" << endl;
            }
            else if (according == 2)
            {
                count = 0;
                cout << "\t/* �����ѯ���� */" << endl;
                cin >> query_exp;
                vector<player>::iterator player_iterator = playerList.begin();
                for (; player_iterator != playerList.end(); player_iterator++)
                {
                    if (player_iterator->get_exp() == query_exp)
                    {
                        if (count == 0)
                            cout << "����\t\t�ȼ�\t����\t�ؿ�" << endl;
                        cout << player_iterator->get_name() << "\t\t" << player_iterator->get_level() << "\t" << player_iterator->get_exp() << "\t" << player_iterator->get_pass() << endl;
                        count++;
                    }
                }
                if (count == 0)
                    cout << "\t/* ���˸þ���! */" << endl;
            }
            else if (according == 3)
            {
                count = 0;
                cout << "\t/* �����ѯ�ȼ� */" << endl;
                cin >> query_level;
                vector<player>::iterator player_iterator = playerList.begin();
                for (; player_iterator != playerList.end(); player_iterator++)
                {
                    if (player_iterator->get_level() == query_level)
                    {
                        if (count == 0)
                            cout << "����\t\t�ȼ�\t����\t�ؿ�" << endl;
                        cout << player_iterator->get_name() << "\t\t" << player_iterator->get_level() << "\t" << player_iterator->get_exp() << "\t" << player_iterator->get_pass() << endl;
                        count++;
                    }
                }
                if (count == 0)
                    cout << "\t/* ���˸õȼ�! */" << endl;
            }
            else if (according == 4)
            {
                count = 0;
                cout << "\t/* �����ѯ�ؿ��� */" << endl;
                cin >> query_pass;
                vector<player>::iterator player_iterator = playerList.begin();
                for (; player_iterator != playerList.end(); player_iterator++)
                {
                    if (player_iterator->get_pass() == query_pass)
                    {
                        if (count == 0)
                            cout << "����\t\t�ȼ�\t����\t�ؿ�" << endl;
                        cout << player_iterator->get_name() << "\t\t" << player_iterator->get_level() << "\t" << player_iterator->get_exp() << "\t" << player_iterator->get_pass() << endl;
                        count++;
                    }
                }
                if (count == 0)
                    cout << "\t/* ���˸ùؿ���! */" << endl;
            }
            if (according == 1 || according == 2 || according == 3 || according == 4)
            {
                Flag = 1;
                break;
            }
        }
        while (classifi == 2)
        {
            cout << "\t/* �������ѯ���� */" << endl;
            cout << "\t/* ����-----1 */" << endl;
            cout << "\t/* �ȼ�-----2 */" << endl;
            cout << "\t/* ������---3 */" << endl;
            cin >> according;
            if (according == 1)
            {
                cout << "\t/* �����ѯ���� */" << endl;
                cin >> query_name;
                vector<Qmaker>::iterator Qmaker_iterator = QmakerList.begin();
                for (; Qmaker_iterator != QmakerList.end(); Qmaker_iterator++)
                {
                    if (Qmaker_iterator->get_name() == query_name)
                    {
                        cout << "����\t\t�ȼ�\t������ " << endl;
                        cout << Qmaker_iterator->get_name() << "\t\t" << Qmaker_iterator->get_level() << "\t" << Qmaker_iterator->get_questionNum() << endl;
                        break;
                    }
                }
                if (Qmaker_iterator == QmakerList.end())
                    cout << "\t/* ���޴���! */" << endl;
            }
            else if (according == 2)
            {
                count = 0;
                cout << "\t/* �����ѯ�ȼ� */" << endl;
                cin >> query_level;
                vector<Qmaker>::iterator Qmaker_iterator = QmakerList.begin();
                for (; Qmaker_iterator != QmakerList.end(); Qmaker_iterator++)
                {
                    if (Qmaker_iterator->get_level() == query_level)
                    {
                        if (count == 0)
                            cout << "����\t\t�ȼ�\t������ " << endl;
                        cout << Qmaker_iterator->get_name() << "\t\t" << Qmaker_iterator->get_level() << "\t" << Qmaker_iterator->get_questionNum() << endl;
                        count++;
                    }
                }
                if (count == 0)
                    cout << "\t/* ���˸õȼ�! */" << endl;
            }
            else if (according == 3)
            {
                count = 0;
                cout << "\t/* �����ѯ������ */" << endl;
                cin >> query_questionNum;
                vector<Qmaker>::iterator Qmaker_iterator = QmakerList.begin();
                for (; Qmaker_iterator != QmakerList.end(); Qmaker_iterator++)
                {
                    if (Qmaker_iterator->get_questionNum() == query_questionNum)
                    {
                        if (count == 0)
                            cout << "����\t\t�ȼ�\t������ " << endl;
                        cout << Qmaker_iterator->get_name() << "\t\t" << Qmaker_iterator->get_level() << "\t" << Qmaker_iterator->get_questionNum() << endl;
                        count++;
                    }
                }
                if (count == 0)
                    cout << "\t/* ���˸ó�����! */" << endl;
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