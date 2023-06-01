#include"Functions.h"

int start_Qmake(vector<string>& wordList)//��ʼ����
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
    cout << "\t/* ��ʼ����! ����'#'�������� */" << endl;
    cin >> Qmaker_word;
    while (Qmaker_word != "#")
    {
        vector<string>::iterator word_iterator = wordList.begin();
        for (; word_iterator != wordList.end(); word_iterator++)//����һ�����ʺ��ڵ��ʱ�����һ��
        {
            if (Qmaker_word == *word_iterator)
                break;
        }
        if (word_iterator == wordList.end())
        {
            wordList.push_back(Qmaker_word);
            fp_word << Qmaker_word << endl;
            newword++;
            cout << "\t/* ���ʳ���ɹ�! */" << endl;
        }
        else//�����Ѵ���
        {
            cout << "\t/* �����Ѿ�����! */" << endl;
        }
        cin >> Qmaker_word;
    }
    fp_word.close();
    cout << "\t/* �˳�����! */" << endl;
    cout << "\t/* ������: " << newword << " */" << endl;
    return newword;
}

void upgrade_Qmaker(vector<Qmaker>& QmakerList, int offset, int newword)//����������
{
    //����QmakerList��
    Qmaker temp_Qmaker = QmakerList[offset];
    temp_Qmaker.Qmaker_updata(newword);
    QmakerList[offset] = temp_Qmaker;
    //����QmakerList.csv�ļ�
    string temp1 = to_string(temp_Qmaker.get_level());
    string temp2 = to_string(temp_Qmaker.get_questionNum());
    string merge = temp_Qmaker.get_name() + "," + temp_Qmaker.get_password() + "," + temp1 + "," + temp2;
    alter_file("QmakerList.csv", offset, merge);
}