#include"Functions.h"

void alter_file(string file_name, int offset, string content)//�޸��ļ�
{
    char c;
    int lines = 0, count = 0;
    ifstream count_fp, prime;//ͳ������,�޸�ǰ�ļ�
    ofstream final;//�޸ĺ��ļ�
    char message[200] = { '\0' };//��ʱ�ַ���
    //��ȡ����
    count_fp.open(file_name);
    while (count_fp.get(c))
    {
        if (c == '\n')
            count++;
    }
    count_fp.close();
    //����
    prime.open(file_name);
    if (!prime)
    {
        cout << "\t/* �� " << file_name << " ʧ��! */" << endl;
        abort();
    }
    string temp_str;//�����ַ���
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
    //д��
    final.open(file_name);
    if (!final)
    {
        cout << "\t/* �� " << file_name << " ʧ��! */" << endl;
        abort();
    }
    final.flush();//�������
    final << temp_str;//��������
    final.close();
}