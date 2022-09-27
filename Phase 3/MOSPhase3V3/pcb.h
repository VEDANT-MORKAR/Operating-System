#pragma once
#include<iostream>
#include<string>
#include"common.h"

class PCB
{
private:
	int TLL, TTL, LLC, TLC, page_table_ptr, terminate_code;
	std::string p_id;
public:
	void initialize_PCB(std::string limits)
	{
		//initialize the contents of PCB
		p_id = limits.substr(0, 4);
		TTL = s_to_i(limits.substr(4, 2)) * 100 + s_to_i(limits.substr(6, 2));
		TLL = s_to_i(limits.substr(8, 2)) * 100 + s_to_i(limits.substr(10, 2));
		LLC = 0; TLC = 0; terminate_code = 0;
	}
	int s_to_i(std::string operand)//ok
	{
		//return the integer no for the given std::string
		if (operand[0] >= '0' && operand[0] <= '9' && operand[1] >= '0' && operand[1] <= '9')
			return ((int)operand[0] - 48) * 10 + ((int)operand[1] - 48);
		return -1;
	}
	int get_page_table_ptr()
	{
		//reterieve page table pointer
		return page_table_ptr;
	}
	int set_page_table_ptr(int ptr)
	{
		//set the page table pointer
		page_table_ptr = ptr;
		return page_table_ptr;
	}
	void increment_TLC()
	{
		//increment the TLC
		TLC++;
	}
	void increment_LLC()
	{
		//increment LLC
		LLC++;
	}
	int get_TLC()
	{
		//get the time limit counter
		return TLC;
	}
	std::string get_pid()
	{
		//get the process id
		return p_id;
	}
	int get_terminate_code()
	{
		//get the terminate code
		return terminate_code;
	}
	void set_terminate_code(int t_c)
	{
		//set the terminate code
		terminate_code = t_c;
	}
	int get_LLC()
	{
		//get the LLC
		return LLC;
	}
	int TLC_is_greater_than_TTL()
	{
		//compare TLC anf TTL
		if (TLC > TTL)
			return 1;
		else
			return 0;
	}
	int LLC_is_greater_than_TLL()
	{
		//compare LLC and TLL
		if (LLC > TLL)
			return 1;
		else
			return 0;
	}
}process;