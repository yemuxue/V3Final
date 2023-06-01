#include"Functions.h"

player_newInfo start_play(vector<string>& wordList)//开始答题
{
    vector<string> alread_apperad;
    player_newInfo p_newInfo;
    string word, player_word = "\0";
    int newpass = 0, count = 0, extraexp = 0, option, health = 2;//通过关数,答对题数,额外经验,选项,生命值
    int time_interval = 2000;//时间间隔,可以根据难度调整
    int passnum;//升级所需题数
    int random_num = 0;//随机数
    int range_start, range_end;
    cout << "\t/* 选择难度模式 */" << endl;
    cout << "\t/* 轮数增多---1 */" << endl;
    cout << "\t/* 时间缩短---2 */" << endl;
    cin >> option;
    if (option == 1)//进行轮数增多
    {
        cout << "\t/* 开始游戏! 输入'#'结束游戏 */" << endl;
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
                /* 按时间随机,按照等级不同
                range_end = range_start + passnum - 1;
                default_random_engine e{(unsigned int)time(NULL)};//使用随机数种子,time为long long类型
                uniform_int_distribution <unsigned>u(range_start,range_end);//随机数分布类:范围在min_Num到max_Num
                random_num = u(e);//生成范围在range_start到range_end的随机数
                */
                random_num = rand() % (passnum * 10) + range_start;
                word = wordList[random_num];//按随机数随机生成单词(按照等级不同)
                vector<string>::iterator apperad_iterator = alread_apperad.begin();
                for (; apperad_iterator != alread_apperad.end(); apperad_iterator++)//输入一个单词后，在单词表里检查一遍
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
            cout << "请输入: " << endl;
            time_t timer = time(NULL);//记录耗费时间
            cin >> player_word;
            if (word == player_word)
            {
                if (time(NULL) - timer < time_interval)//额外经验奖励
                    extraexp += 10;
                count++;
                cout << "\t/* 再接再厉！*/" << endl;
            }
            else if (player_word != "#")
            {
                health--;
                cout << "\t/* 剩余次数: " << health + 1 << " */" << endl;
                while (health >= 0)
                {
                    cout << "\t/* 再试试! */" << endl;
                    cout << word;
                    Sleep(time_interval);
                    cout << "\r                 \r";
                    cout << "请输入: " << endl;
                    cin >> player_word;
                    if (player_word != word)
                    {
                        health--;
                        cout << "\t/* 剩余次数: " << health + 1 << " */" << endl;
                    }
                    else
                    {
                        count++;
                        cout << "\t/* 再接再厉！*/" << endl;
                        break;
                    }

                }
            }
            if (count == passnum)//升级
            {
                newpass++;
                count = 0;
                cout << "\t/* 恭喜升级! */" << endl;
            }
        }
    }
    else if (option == 2)//显示时间缩短
    {
        cout << "\t/* 开始游戏! 输入'#'结束游戏 */" << endl;
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
                word = wordList[random_num];//按随机数随机生成单词(按照等级不同)
                vector<string>::iterator apperad_iterator = alread_apperad.begin();
                for (; apperad_iterator != alread_apperad.end(); apperad_iterator++)//输入一个单词后，在单词表里检查一遍
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
            cout << "请输入: " << endl;
            time_t timer = time(NULL);//记录耗费时间
            cin >> player_word;
            if (word == player_word)
            {
                if (time(NULL) - timer < time_interval)//额外经验奖励
                    extraexp += 10;
                count++;
                cout << "\t/* 再接再厉！*/" << endl;
            }
            else if (player_word != "#")
            {
                health--;
                cout << "\t/* 剩余次数: " << health + 1 << " */" << endl;
                while (health >= 0)
                {
                    cout << "\t/* 再试试! */" << endl;
                    cout << word;
                    Sleep(time_interval);
                    cout << "\r                 \r";
                    cout << "请输入: " << endl;
                    cin >> player_word;
                    if (player_word != word)
                    {
                        health--;
                        cout << "\t/* 剩余次数: " << health + 1 << " */" << endl;
                    }
                    else
                    {
                        count++;
                        cout << "\t/* 再接再厉！*/" << endl;
                        break;
                    }

                }
            }
            if (count == passnum)//升级
            {
                newpass++;
                count = 0;
                cout << "\t/* 恭喜升级! */" << endl;
            }
        }
    }
    else
        cout << "\t/* 选项错误 */" << endl;
    cout << "\t/* 退出游戏! */" << endl;
    cout << "\t/* 通过关卡: " << newpass << " */" << endl;
    p_newInfo.newpass = newpass;
    p_newInfo.extraexp = extraexp;
    return p_newInfo;
}

void upgrade_player(vector<player>& playerList, int offset, player_newInfo p_newInfo)//答题者升级
{
    //更新playerList表
    player temp_player = playerList[offset];
    temp_player.player_updata(p_newInfo);
    playerList[offset] = temp_player;
    //更新playerList.csv文件
    string temp1 = to_string(temp_player.get_level());//整型转字符串
    string temp2 = to_string(temp_player.get_exp());
    string temp3 = to_string(temp_player.get_pass());
    string merge = temp_player.get_name() + "," + temp_player.get_password() + "," + temp1 + "," + temp2 + "," + temp3;
    alter_file("playerList.csv", offset, merge);
}