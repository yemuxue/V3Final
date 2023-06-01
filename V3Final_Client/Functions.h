#pragma once
#include"Include.h"
#include"User_Info.h"

void end_game();//结束游戏
void selection_graph();//选项表
void Inital_word(vector<string>& wordList);//初始化单词库
void Inital_player(vector<player>& playerList);//初始化答题者类
void Inital_Qmaker(vector<Qmaker>& QmakerList);//初始化出题者类
int player_Login(vector<player>& playerList);//答题者登录,返回名称在列表中的对应位置(或者-1)
int Qmaker_Login(vector<Qmaker>& QmakerList);////出题者登录,返回名称在列表中的对应位置(或者-1)
player_newInfo start_play(vector<string>& wordList);//开始答题
void alter_file(string file_name, int offset, string content);//修改文件
void upgrade_player(vector<player>& playerList, int offset, player_newInfo p_newInfo);//答题者升级
int start_Qmake(vector<string>& wordList);//开始出题
void upgrade_Qmaker(vector<Qmaker>& QmakerList, int offset, int newword);//出题者升级
bool comp_word(string& x, string& y);
void extract_full(string& s, const string& c, vector<string>& v);//提取","分割函数
bool rank_pass(player& player_1, player& player_2);//按通关数排名
bool rank_exp(player& player_1, player& player_2);//按经验排名
bool rank_level_player(player& player_1, player& player_2);//按答题者等级排名
bool rank_level_Qmaker(Qmaker& Qmaker_1, Qmaker& Qmaker_2);//按出题者等级排名
bool rank_questionNum(Qmaker& Qmaker_1, Qmaker& Qmaker_2);//按出题数排名
void rank_user(vector<player>& playerList, vector<Qmaker>& QmakerList);//对用户排名
void query_data(vector<player>& playerList, vector<Qmaker>& QmakerList);//查询
void Register(vector<player>& playerList, vector<Qmaker>& QmakerList);//用户注册
void alter_file(string file_name, int offset, string content);//修改文件