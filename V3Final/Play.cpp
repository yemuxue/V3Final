#include"Functions.h"

player_newInfo start_play(vector<string>& wordList)//��ʼ����
{
    vector<string> alread_apperad;
    player_newInfo p_newInfo;
    string word, player_word = "\0";
    int newpass = 0, count = 0, extraexp = 0, option, health = 2;//ͨ������,�������,���⾭��,ѡ��,����ֵ
    int time_interval = 2000;//ʱ����,���Ը����Ѷȵ���
    int passnum;//������������
    int random_num = 0;//�����
    int range_start, range_end;
    cout << "\t/* ѡ���Ѷ�ģʽ */" << endl;
    cout << "\t/* ��������---1 */" << endl;
    cout << "\t/* ʱ������---2 */" << endl;
    cin >> option;
    if (option == 1)//������������
    {
        cout << "\t/* ��ʼ��Ϸ! ����'#'������Ϸ */" << endl;
        while (player_word != "#" && health >= 0)
        {
            if (newpass < 3)
                passnum = 1;
            else if (newpass < 6)
                passnum = 2;
            else
                passnum = 3;
            while (1)
            {
                range_start = newpass * passnum;
                /* ��ʱ�����,���յȼ���ͬ
                range_end = range_start + passnum - 1;
                default_random_engine e{(unsigned int)time(NULL)};//ʹ�����������,timeΪlong long����
                uniform_int_distribution <unsigned>u(range_start,range_end);//������ֲ���:��Χ��min_Num��max_Num
                random_num = u(e);//���ɷ�Χ��range_start��range_end�������
                */
                random_num = rand() % (passnum * 10) + range_start;
                word = wordList[random_num];//�������������ɵ���(���յȼ���ͬ)
                vector<string>::iterator apperad_iterator = alread_apperad.begin();
                for (; apperad_iterator != alread_apperad.end(); apperad_iterator++)//����һ�����ʺ��ڵ��ʱ�����һ��
                {
                    if (word == *apperad_iterator)
                        break;
                }
                if (apperad_iterator == alread_apperad.end())
                {
                    alread_apperad.push_back(word);
                    break;
                }
            }
            cout << word;
            Sleep(time_interval);
            cout << "\r                 \r";
            cout << "������: " << endl;
            time_t timer = time(NULL);//��¼�ķ�ʱ��
            cin >> player_word;
            if (word == player_word)
            {
                if (time(NULL) - timer < time_interval)//���⾭�齱��
                    extraexp += 10;
                count++;
                cout << "\t/* �ٽ�������*/" << endl;
            }
            else if (player_word != "#")
            {
                health--;
                cout << "\t/* ʣ�����: " << health + 1 << " */" << endl;
                while (health >= 0)
                {
                    cout << "\t/* ������! */" << endl;
                    cout << word;
                    Sleep(time_interval);
                    cout << "\r                 \r";
                    cout << "������: " << endl;
                    cin >> player_word;
                    if (player_word != word)
                    {
                        health--;
                        cout << "\t/* ʣ�����: " << health + 1 << " */" << endl;
                    }
                    else
                    {
                        count++;
                        cout << "\t/* �ٽ�������*/" << endl;
                        break;
                    }

                }
            }
            if (count == passnum)//����
            {
                newpass++;
                count = 0;
                cout << "\t/* ��ϲ����! */" << endl;
            }
        }
    }
    else if (option == 2)//��ʾʱ������
    {
        cout << "\t/* ��ʼ��Ϸ! ����'#'������Ϸ */" << endl;
        passnum = 2;
        while (player_word != "#" && health >= 0)
        {
            if (newpass < 3)
                time_interval = 3000;
            else if (newpass < 6)
                time_interval = 2000;
            else
                time_interval = 1000;
            while (1)
            {
                range_start = newpass * passnum;
                random_num = rand() % (passnum * 10) + range_start;
                word = wordList[random_num];//�������������ɵ���(���յȼ���ͬ)
                vector<string>::iterator apperad_iterator = alread_apperad.begin();
                for (; apperad_iterator != alread_apperad.end(); apperad_iterator++)//����һ�����ʺ��ڵ��ʱ�����һ��
                {
                    if (word == *apperad_iterator)
                        break;
                }
                if (apperad_iterator == alread_apperad.end())
                {
                    alread_apperad.push_back(word);
                    break;
                }
            }
            cout << word;
            Sleep(time_interval);
            cout << "\r                 \r";
            cout << "������: " << endl;
            time_t timer = time(NULL);//��¼�ķ�ʱ��
            cin >> player_word;
            if (word == player_word)
            {
                if (time(NULL) - timer < time_interval)//���⾭�齱��
                    extraexp += 10;
                count++;
                cout << "\t/* �ٽ�������*/" << endl;
            }
            else if (player_word != "#")
            {
                health--;
                cout << "\t/* ʣ�����: " << health + 1 << " */" << endl;
                while (health >= 0)
                {
                    cout << "\t/* ������! */" << endl;
                    cout << word;
                    Sleep(time_interval);
                    cout << "\r                 \r";
                    cout << "������: " << endl;
                    cin >> player_word;
                    if (player_word != word)
                    {
                        health--;
                        cout << "\t/* ʣ�����: " << health + 1 << " */" << endl;
                    }
                    else
                    {
                        count++;
                        cout << "\t/* �ٽ�������*/" << endl;
                        break;
                    }

                }
            }
            if (count == passnum)//����
            {
                newpass++;
                count = 0;
                cout << "\t/* ��ϲ����! */" << endl;
            }
        }
    }
    else
        cout << "\t/* ѡ����� */" << endl;
    cout << "\t/* �˳���Ϸ! */" << endl;
    cout << "\t/* ͨ���ؿ�: " << newpass << " */" << endl;
    p_newInfo.newpass = newpass;
    p_newInfo.extraexp = extraexp;
    return p_newInfo;
}

void upgrade_player(vector<player>& playerList, int offset, player_newInfo p_newInfo)//����������
{
    //����playerList��
    player temp_player = playerList[offset];
    temp_player.player_updata(p_newInfo);
    playerList[offset] = temp_player;
    //����playerList.csv�ļ�
    string temp1 = to_string(temp_player.get_level());//����ת�ַ���
    string temp2 = to_string(temp_player.get_exp());
    string temp3 = to_string(temp_player.get_pass());
    string merge = temp_player.get_name() + "," + temp_player.get_password() + "," + temp1 + "," + temp2 + "," + temp3;
    alter_file("playerList.csv", offset, merge);
}