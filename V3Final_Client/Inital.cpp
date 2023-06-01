#include"Functions.h"

void selection_graph()//选项表
{
    cout << endl;
    cout << "\t/****  单词消除游戏  ****/" << endl;
    cout << "\t/*   用户注册-------1   */" << endl;
    cout << "\t/*   答题者登录-----2   */" << endl;
    cout << "\t/*   出题者登录-----3   */" << endl;
    cout << "\t/*   用户排序-------4   */" << endl;
    cout << "\t/*   用户查询-------5   */" << endl;
    cout << "\t/*   退出游戏-------6   */" << endl;
    cout << "\t/************************/" << endl;
}

void Inital_word(vector<string>& wordList)//初始化单词库
{
    string temp;
    fstream fp_word;
    fp_word.open("wordList.csv", ios::out | ios::in);
    if (!fp_word)
    {
        cout << "\t/* 打开 wordList.csv 失败! */" << endl;
        abort();
    }
    while (fp_word.peek() != EOF)
    {
        fp_word >> temp;
        wordList.push_back(temp);
    }
    sort(wordList.begin(), wordList.end(), comp_word);//排序,第三个参数是字符串比较参数
    fp_word.close();
}

void Inital_player(vector<player>& playerList)//初始化答题者类
{
    string player_Infofull;//整行
    vector<string> player_Infodiv;//分段
    fstream fp_player;
    fp_player.open("playerList.csv", ios::out | ios::in);
    if (!fp_player)
    {
        cout << "\t/* 打开 playerList.csv 失败! */" << endl;
        abort();
    }
    while (fp_player.peek() != EOF)
    {
        fp_player >> player_Infofull;
        extract_full(player_Infofull, ",", player_Infodiv);//分割
        player temp_player(player_Infodiv[0], player_Infodiv[1], stoi(player_Infodiv[2]), stoi(player_Infodiv[3]), stoi(player_Infodiv[4]));//stoi()为字符串转整数
        playerList.push_back(temp_player);//添加在后
        //player_Infofull.clear();
        player_Infodiv.clear();
    }
    fp_player.close();
}

void Inital_Qmaker(vector<Qmaker>& QmakerList)//初始化出题者类
{
    string Qmaker_Infofull;
    vector<string> Qmaker_Infodiv;
    fstream fp_Qmaker;
    fp_Qmaker.open("QmakerList.csv", ios::out | ios::in);
    if (!fp_Qmaker)
    {
        cout << "\t/* 打开 QmakerList.csv 失败! */" << endl;
        abort();
    }
    while (fp_Qmaker.peek() != EOF)
    {
        fp_Qmaker >> Qmaker_Infofull;
        extract_full(Qmaker_Infofull, ",", Qmaker_Infodiv);
        Qmaker temp_Qmaker(Qmaker_Infodiv[0], Qmaker_Infodiv[1], stoi(Qmaker_Infodiv[2]), stoi(Qmaker_Infodiv[3]));//stoi()为字符串转整数
        QmakerList.push_back(temp_Qmaker);
        //Qmaker_Infofull.clear();
        Qmaker_Infodiv.clear();
    }
    fp_Qmaker.close();
}
