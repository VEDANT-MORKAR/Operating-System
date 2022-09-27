#include"common.h"

int UTC = 0; // Universal Time Counter;
int sim_flag = 0;

std::ifstream fin;
std::ofstream fout;
int SI, PI, TI;
bool occupied_pages[30];
int IOI, ch[4] = { 0,5,5,2 };