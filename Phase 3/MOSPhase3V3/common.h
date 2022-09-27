#pragma once
#include<fstream>

extern int UTC; // Universal Time Counter;
extern int sim_flag;

extern std::ifstream fin;
extern std::ofstream fout;
extern int SI, PI, TI;
extern bool occupied_pages[30];
extern int IOI, ch[4];

//extern PCB process;
//extern memory m_obj;
//static supervisory_storage super;
//extern aux_drum drum_obj;