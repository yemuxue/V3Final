#include"Functions.h"

void selection_graph()//ѡ���
{
    cout << endl;
    cout << "\t/****  ����������Ϸ  ****/" << endl;
    cout << "\t/*   �û�ע��-------1   */" << endl;
    cout << "\t/*   �����ߵ�¼-----2   */" << endl;
    cout << "\t/*   �����ߵ�¼-----3   */" << endl;
    cout << "\t/*   �û�����-------4   */" << endl;
    cout << "\t/*   �û���ѯ-------5   */" << endl;
    cout << "\t/*   �˳���Ϸ-------6   */" << endl;
    cout << "\t/************************/" << endl;
}

void Inital_word(vector<string>& wordList)//��ʼ�����ʿ�
{
    string temp;
    fstream fp_word;
    fp_word.open("wordList.csv", ios::out | ios::in);
    if (!fp_word)
    {
        cout << "\t/* �� wordList.csv ʧ��! */" << endl;
        abort();
    }
    while (fp_word.peek() != EOF)
    {
        fp_word >> temp;
        wordList.push_back(temp);
    }
    sort(wordList.begin(), wordList.end(), comp_word);//����,�������������ַ����Ƚϲ���
    fp_word.close();
}

void Inital_player(vector<player>& playerList)//��ʼ����������
{
    string player_Infofull;//����
    vector<string> player_Infodiv;//�ֶ�
    fstream fp_player;
    fp_player.open("playerList.csv", ios::out | ios::in);
    if (!fp_player)
    {
        cout << "\t/* �� playerList.csv ʧ��! */" << endl;
        abort();
    }
    while (fp_player.peek() != EOF)
    {
        fp_player >> player_Infofull;
        extract_full(player_Infofull, ",", player_Infodiv);//�ָ�
        player temp_player(player_Infodiv[0], player_Infodiv[1], stoi(player_Infodiv[2]), stoi(player_Infodiv[3]), stoi(player_Infodiv[4]));//stoi()Ϊ�ַ���ת����
        playerList.push_back(temp_player);//����ں�
        //player_Infofull.clear();
        player_Infodiv.clear();
    }
    fp_player.close();
}

void Inital_Qmaker(vector<Qmaker>& QmakerList)//��ʼ����������
{
    string Qmaker_Infofull;
    vector<string> Qmaker_Infodiv;
    fstream fp_Qmaker;
    fp_Qmaker.open("QmakerList.csv", ios::out | ios::in);
    if (!fp_Qmaker)
    {
        cout << "\t/* �� QmakerList.csv ʧ��! */" << endl;
        abort();
    }
    while (fp_Qmaker.peek() != EOF)
    {
        fp_Qmaker >> Qmaker_Infofull;
        extract_full(Qmaker_Infofull, ",", Qmaker_Infodiv);
        Qmaker temp_Qmaker(Qmaker_Infodiv[0], Qmaker_Infodiv[1], stoi(Qmaker_Infodiv[2]), stoi(Qmaker_Infodiv[3]));//stoi()Ϊ�ַ���ת����
        QmakerList.push_back(temp_Qmaker);
        //Qmaker_Infofull.clear();
        Qmaker_Infodiv.clear();
    }
    fp_Qmaker.close();
}
