#pragma once
#include"Include.h"
#include"User_Info.h"

void end_game();//������Ϸ
void selection_graph();//ѡ���
void Inital_word(vector<string>& wordList);//��ʼ�����ʿ�
void Inital_player(vector<player>& playerList);//��ʼ����������
void Inital_Qmaker(vector<Qmaker>& QmakerList);//��ʼ����������
int player_Login(vector<player>& playerList);//�����ߵ�¼,�����������б��еĶ�Ӧλ��(����-1)
int Qmaker_Login(vector<Qmaker>& QmakerList);////�����ߵ�¼,�����������б��еĶ�Ӧλ��(����-1)
player_newInfo start_play(vector<string>& wordList);//��ʼ����
void alter_file(string file_name, int offset, string content);//�޸��ļ�
void upgrade_player(vector<player>& playerList, int offset, player_newInfo p_newInfo);//����������
int start_Qmake(vector<string>& wordList);//��ʼ����
void upgrade_Qmaker(vector<Qmaker>& QmakerList, int offset, int newword);//����������
bool comp_word(string& x, string& y);
void extract_full(string& s, const string& c, vector<string>& v);//��ȡ","�ָ��
bool rank_pass(player& player_1, player& player_2);//��ͨ��������
bool rank_exp(player& player_1, player& player_2);//����������
bool rank_level_player(player& player_1, player& player_2);//�������ߵȼ�����
bool rank_level_Qmaker(Qmaker& Qmaker_1, Qmaker& Qmaker_2);//�������ߵȼ�����
bool rank_questionNum(Qmaker& Qmaker_1, Qmaker& Qmaker_2);//������������
void rank_user(vector<player>& playerList, vector<Qmaker>& QmakerList);//���û�����
void query_data(vector<player>& playerList, vector<Qmaker>& QmakerList);//��ѯ
void Register(vector<player>& playerList, vector<Qmaker>& QmakerList);//�û�ע��
void alter_file(string file_name, int offset, string content);//�޸��ļ�