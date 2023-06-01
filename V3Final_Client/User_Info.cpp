#include"User_Info.h"

user::user(string newName, string newPassword)
{
    name = newName;
    password = newPassword;
}
user::~user() {}
string user::get_name()
{
    return name;
}
string user::get_password()
{
    return password;
}
//
player::player(string player_Name, string player_Password, int player_Level , int player_Exp , int player_Pass ) : user(player_Name, player_Password)
    {
        exp = player_Exp;
        level = player_Level;
        pass = player_Pass;
    }
player::~player() {};
    int player::get_level()
    {
        return level;
    };
    int player::get_exp()
    {
        return exp;
    }
    int player::get_pass()
    {
        return pass;
    }
    void player::player_updata(player_newInfo p_newInfo)//改变数据
    {
        if (pass < p_newInfo.newpass)
        {
            exp += pow(p_newInfo.newpass - pass, 2) * 10;
            exp += p_newInfo.newpass * 10;
            pass = p_newInfo.newpass;//更新通关数
        }
        exp += p_newInfo.extraexp;//加上额外经验
        level = exp / 100;
    }
//
    Qmaker::Qmaker(string Qmaker_Name, string Qmaker_Password, int Qmaker_Level , int Qmaker_questionNum ) : user(Qmaker_Name, Qmaker_Password)
    {
        level = Qmaker_Level;
        questionNum = Qmaker_questionNum;
    }
    Qmaker::~Qmaker() {};
    int Qmaker::get_level()
    {
        return level;
    }
    int Qmaker::get_questionNum()
    {
        return questionNum;
    }
    void Qmaker::Qmaker_updata(int newword)
    {
        int tempnum;
        level = 0;//重置0
        questionNum = questionNum + newword;//更新出题数
        tempnum = questionNum;
        while (tempnum / 2)
        {
            level++;
            tempnum /= 2;
        }
    }
