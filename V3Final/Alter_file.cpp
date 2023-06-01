#include"Functions.h"

void alter_file(string file_name, int offset, string content)//修改文件
{
    char c;
    int lines = 0, count = 0;
    ifstream count_fp, prime;//统计行数,修改前文件
    ofstream final;//修改后文件
    char message[200] = { '\0' };//临时字符串
    //获取行数
    count_fp.open(file_name);
    while (count_fp.get(c))
    {
        if (c == '\n')
            count++;
    }
    count_fp.close();
    //读出
    prime.open(file_name);
    if (!prime)
    {
        cout << "\t/* 打开 " << file_name << " 失败! */" << endl;
        abort();
    }
    string temp_str;//内容字符串
    while (prime.getline(message, sizeof(message)))
    {
        if (offset != lines)
            temp_str += message;
        else
            temp_str += content;
        if (lines != count)
            temp_str += "\n";
        lines++;
    }
    prime.close();
    //写入
    final.open(file_name);
    if (!final)
    {
        cout << "\t/* 打开 " << file_name << " 失败! */" << endl;
        abort();
    }
    final.flush();//清空所有
    final << temp_str;//输入最新
    final.close();
}