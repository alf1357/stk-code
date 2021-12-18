#include "global_log.hpp"
#include <network/server_config.hpp>
#include <fstream>
#include <iostream>
#include <utils/log.hpp>

std::ofstream GlobalLog::outfile_posLog;  
std::ofstream GlobalLog::outfile_goalLog; 

void GlobalLog::open_Log(std::string log_name)
{
    if (log_name=="posLog")
    {
        if (GlobalLog::outfile_posLog.is_open()) return;
        else GlobalLog::outfile_posLog.open(ServerConfig::m_pos_log_path,std::ios_base::app);
	Log::info("!!!!","open_Log succeded");
    }
    else if (log_name=="goalLog")
    {
	Log::info("!!!!","open_Log called");
        if (GlobalLog::outfile_goalLog.is_open()) return;
        else GlobalLog::outfile_goalLog.open(ServerConfig::m_logfile_name,std::ios_base::app);
	Log::info("!!!!","open_Log succeded");
    }
}

void GlobalLog::write_Log(std::string text , std::string log_name)
{
    open_Log(log_name);
    if (log_name=="posLog")
    {
        GlobalLog::outfile_posLog << text;
    }
    else if (log_name=="goalLog")
    {
        GlobalLog::outfile_goalLog << text;
    }
}

void GlobalLog::close_Log(std::string log_name)
{
    std::string msg= "CL called" + log_name;
    Log::info("!!!!",msg.c_str());
    if (log_name=="posLog")
    {
        if (!GlobalLog::outfile_posLog.is_open()) return;
        else GlobalLog::outfile_posLog.close();
    }
    else if (log_name=="goalLog")
    {
        if (!GlobalLog::outfile_goalLog.is_open()) return;
        else GlobalLog::outfile_goalLog.close();
    }
}
