#pragma once
#include"Include.h"

struct player_newInfo
{
    int newpass;
    int extraexp;
};

class user//�û���,��ͬ����
{
private:
    string name;
    string password;
public:
    user(string newName, string newPassword);
    ~user() ;
    string get_name();
    string get_password();
};

class player : public user//��������
{
private:
    int exp;//����ֵ
    int level;//�ȼ�
    int pass;//ͨ����
public:
    player(string player_Name, string player_Password, int player_Level = 0, int player_Exp = 0, int player_Pass = 0);
    ~player();
    int get_level();
    int get_exp();
    int get_pass();
    void player_updata(player_newInfo p_newInfo);//�ı�����
};

class Qmaker : public user//��������
{
private:
    int questionNum;
    int level;
public:
    Qmaker(string Qmaker_Name, string Qmaker_Password, int Qmaker_Level = 0, int Qmaker_questionNum = 0);
    ~Qmaker() ;
    int get_level();
    int get_questionNum();
    void Qmaker_updata(int newword);
};