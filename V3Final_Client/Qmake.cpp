#include"Functions.h"

int start_Qmake(vector<string>& wordList)//开始出题
{
    int newword = 0;
    string Qmaker_word = "\0";
    fstream fp_word;
    fp_word.open("wordList.csv", ios::app);
    if (!fp_word)
    {
        cout << "Open wordList.csv Failed!" << endl;
        abort();
    }
    cout << "\t/* 开始出题! 输入'#'结束出题 */" << endl;
    cin >> Qmaker_word;
    while (Qmaker_word != "#")
    {
        vector<string>::iterator word_iterator = wordList.begin();
        for (; word_iterator != wordList.end(); word_iterator++)//输入一个单词后，在单词表里检查一遍
        {
            if (Qmaker_word == *word_iterator)
                break;
        }
        if (word_iterator == wordList.end())
        {
            wordList.push_back(Qmaker_word);
            fp_word << Qmaker_word << endl;
            newword++;
            cout << "\t/* 单词出题成功! */" << endl;
        }
        else//单词已存在
        {
            cout << "\t/* 单词已经存在! */" << endl;
        }
        cin >> Qmaker_word;
    }
    fp_word.close();
    cout << "\t/* 退出出题! */" << endl;
    cout << "\t/* 出题数: " << newword << " */" << endl;
    return newword;
}

void upgrade_Qmaker(vector<Qmaker>& QmakerList, int offset, int newword)//出题者升级
{
    //更新QmakerList表
    Qmaker temp_Qmaker = QmakerList[offset];
    temp_Qmaker.Qmaker_updata(newword);
    QmakerList[offset] = temp_Qmaker;
    //更新QmakerList.csv文件
    string temp1 = to_string(temp_Qmaker.get_level());
    string temp2 = to_string(temp_Qmaker.get_questionNum());
    string merge = temp_Qmaker.get_name() + "," + temp_Qmaker.get_password() + "," + temp1 + "," + temp2;
    alter_file("QmakerList.csv", offset, merge);
}