#include"Functions.h"

int main()
{
    //准备
    vector<string> wordList;//单词库容器
    vector<player> playerList;//答题者容器
    vector<Qmaker> QmakerList;//出题者容器
    Inital_word(wordList);
    Inital_player(playerList);
    Inital_Qmaker(QmakerList);
    //开始游戏
    int option = -1;
    while (option != 0)
    {
        selection_graph();
        cin >> option;
        if (option == 1)//注册
            Register(playerList, QmakerList);
        else if (option == 2 || option == 3)//登录
        {
            int offset = -1;
            int newword = 0;
            player_newInfo p_newInfo;
            if (option == 2)//答题者
            {
                offset = player_Login(playerList);
                if (offset != -1)
                {
                    p_newInfo = start_play(wordList);
                    upgrade_player(playerList, offset, p_newInfo);//获得用户成绩，刷新用户数据
                }
            }
            else//出题者
            {
                offset = Qmaker_Login(QmakerList);
                if (offset != -1)
                {
                    newword = start_Qmake(wordList);
                    upgrade_Qmaker(QmakerList, offset, newword);//获得用户贡献，刷新用户数据
                }
            }
        }
        else if (option == 4)//排序
        {
            rank_user(playerList, QmakerList);
        }
        else if (option == 5)//查询
        {
            query_data(playerList, QmakerList);
        }
        else if (option == 6)//退出程序
        {
            end_game();
            break;
        }
    }

    system("pause");
    return 0;
}