#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<queue>
#include"pcb.h"
#include "common.h"

class memory
{
public:
	char mem[300][4];
	char ch;
	int page_table_ptr;
	//PCB process;

	//memory(){}
	//memory(PCB process_given):process(process_given){}

	void reset()//ok
	{
		//reset the memory by replacing every symbol in 2D array by $
		memset(mem, '$', sizeof(char) * 300 * 4);
		memset(occupied_pages, false, sizeof(bool) * 30);
		page_table_ptr = process.get_page_table_ptr();
		page_table_ptr = rand() % 30;
		occupied_pages[page_table_ptr] = true;
		page_table_ptr *= 10;
		process.set_page_table_ptr(page_table_ptr);
		SI = PI = TI = 0;
	}
	std::string get_mem(int pos)//get word form memory
	{
		//get the memory contents of given position
		std::string temp = "";
		for (int i = 0; i < 4; i++)
			temp += mem[pos][i];
		return temp;
	}
	void set_mem(std::string s, int pos)//store word in mem
	{
		//set the memory for the recieved value at postion 
		for (int i = 0; i < 4; i++)
			mem[pos][i] = s[i];
	}
	void set_page_table(int row_num, int page_no)
	{
		//set page table
		page_table_ptr = process.get_page_table_ptr();
		std::ostringstream temp;
		temp << page_no;
		std::string table_entry;
		if (page_no < 10)
			table_entry = "$00" + temp.str();
		else
			table_entry = "$0" + temp.str();
		set_mem(table_entry, page_table_ptr + row_num);
	}
	int allocate_page()
	{
		//allocate page logic goes here
		int page_no = rand() % 30;
		while (occupied_pages[page_no] == true)
			page_no = rand() % 30;
		occupied_pages[page_no] = true;
		return page_no;
	}

	void store_card(std::string s, int mem_cnt)
	{
		//extract the words and call the setmem function
		std::string word = "";
		int page_no = allocate_page();
		set_page_table(mem_cnt, page_no);
		page_no *= 10;
		for (int i = 0; i < s.length(); i += 4)
		{
			for (int j = 0; j < 4; j++)
			{
				if (i != (s.length() - 1))
					word += s[i + j];
				else
					word += s[i + 1];
			}
			set_mem(word, page_no);
			page_no++;
			word = "";
		}
	}
	void print_mem()
	{
		int flag = 0;
		for (int i = 0; i < 300; i++)
		{
			if (i % 10 == 0)
				std::cout << "----------Block " << i / 10 << "----------\n";
			for (int j = 0; j < 4; j++)
			{
				std::cout << mem[i][j];
			}
			std::cout << "\n";
		}
	}
}m_obj;

class supervisory_storage
{
private:
	std::queue < std::string > ibq, obq;
	int ebc, ibc, obc;
public:
	supervisory_storage()
	{
		ebc = 10;
	}
	void inc_ebc()
	{
		ebc++;
	}
	void dec_ebc()
	{
		ebc--;
	}
	int get_ebc()
	{
		return ebc;
	}
	void fill_ibq(std::string temp)
	{
		ibq.push(temp);
	}
	std::string get_cards_from_ib()
	{
		std::string s = ibq.front();
		ibq.pop();
		return s;
	}
}super;

class aux_drum
{
private:
	std::string drum[500];
	int curr;
public:
	aux_drum()
	{
		curr = 0;
	}
	void set_drum(std::string s)
	{
		drum[curr] = s;
		++curr;
	}
	std::string get_drum_entry(int i)
	{
		return drum[i];
	}
	int get_curr()
	{
		return curr;
	}
}drum_obj;