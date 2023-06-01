#pragma once
#include"Include.h"

struct player_newInfo
{
    int newpass;
    int extraexp;
};

class user//用户类,共同部分
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

class player : public user//答题者类
{
private:
    int exp;//经验值
    int level;//等级
    int pass;//通关数
public:
    player(string player_Name, string player_Password, int player_Level = 0, int player_Exp = 0, int player_Pass = 0);
    ~player();
    int get_level();
    int get_exp();
    int get_pass();
    void player_updata(player_newInfo p_newInfo);//改变数据
};

class Qmaker : public user//出题者类
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