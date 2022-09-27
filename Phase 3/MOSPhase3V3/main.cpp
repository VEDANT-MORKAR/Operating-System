#include<sstream>
#include<iostream>
#include<string.h>
#include<string>
#include<fstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<queue>
#include"common.h"
#include"memory.h"
#include"cpu.h"
#include"pcb.h"

using namespace std;

void simulation()
{
	for (int i = 1; i < 4; i++)
	{

        if (ch[1] == 5)
        {
        sim_flag = 1;
        }

            if (ch[i] != 0)
                ch[i]--;

        else if (sim_flag == 1)
        {
        IOI = 1;
        sim_flag = 0;
        }
		else
		{
			IOI += i;
			if (i == 3)
				IOI += 1;
		}
	}
        if (IOI == 1)
        {
            UTC += 5;
        }

        else if (IOI == 2)
        {
            UTC += 5;
        }
	    
        else if (IOI == 3)
        {
            UTC += 10;
        }

        else if (IOI == 4)
        {
            UTC += 2;
        }
    
        else if (IOI == 5)
        {
            UTC += 7;
        }

        else if (IOI == 6)
        {
            UTC += 7;
        }

        else if (IOI == 7)
        {
            UTC += 12;
        }

        cout << "________________________" << endl;
		cout << "UTC : " << UTC << endl;
		cout << "________________________" << endl;
  }

int main()
{

	//open two files one input and one output
	//create memory and cpu object

	fin.open("job1.txt");
	fout.open("job2_Output2.txt");

	cpu exe;

	string s, s1;
	int mem_cnt = 0;
	m_obj.reset();
	while (true)
	{
		simulation();
		exe.MOS();
	}
	fin.close();
	fout.close();
	return 0;
}
