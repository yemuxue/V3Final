#include"Functions.h"

int main()
{
    //׼��
    vector<string> wordList;//���ʿ�����
    vector<player> playerList;//����������
    vector<Qmaker> QmakerList;//����������
    Inital_word(wordList);
    Inital_player(playerList);
    Inital_Qmaker(QmakerList);
    //��ʼ��Ϸ
    int option = -1;
    while (option != 0)
    {
        selection_graph();
        cin >> option;
        if (option == 1)//ע��
            Register(playerList, QmakerList);
        else if (option == 2 || option == 3)//��¼
        {
            int offset = -1;
            int newword = 0;
            player_newInfo p_newInfo;
            if (option == 2)//������
            {
                offset = player_Login(playerList);
                if (offset != -1)
                {
                    p_newInfo = start_play(wordList);
                    upgrade_player(playerList, offset, p_newInfo);//����û��ɼ���ˢ���û�����
                }
            }
            else//������
            {
                offset = Qmaker_Login(QmakerList);
                if (offset != -1)
                {
                    newword = start_Qmake(wordList);
                    upgrade_Qmaker(QmakerList, offset, newword);//����û����ף�ˢ���û�����
                }
            }
        }
        else if (option == 4)//����
        {
            rank_user(playerList, QmakerList);
        }
        else if (option == 5)//��ѯ
        {
            query_data(playerList, QmakerList);
        }
        else if (option == 6)//�˳�����
        {
            end_game();
            break;
        }
    }

    system("pause");
    return 0;
}