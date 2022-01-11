#include "global_log.hpp"
#include <network/server_config.hpp>
#include <fstream>
#include <iostream>
#include <utils/log.hpp>

std::ofstream GlobalLog::outfile_posLog;  
std::ofstream GlobalLog::outfile_goalLog; 

void GlobalLog::openLog(GlobalLogTypes log_name)
{
    if (log_name == GlobalLogTypes::POS_LOG)
    {
        if (GlobalLog::outfile_posLog.is_open()) return;
        else GlobalLog::outfile_posLog.open(ServerConfig::m_pos_log_path,std::ios_base::app);
        Log::info("!!!!","openLog succeded");
    }
    else if (log_name == GlobalLogTypes::GOAL_LOG)
    {
        Log::info("!!!!","openLog called");
        if (GlobalLog::outfile_goalLog.is_open()) return;
        else GlobalLog::outfile_goalLog.open(ServerConfig::m_logfile_name,std::ios_base::app);
        Log::info("!!!!","openLog succeded");
    }
}

void GlobalLog::writeLog(std::string text, GlobalLogTypes log_name)
{
    openLog(log_name);
    if (log_name == GlobalLogTypes::POS_LOG)
    {
        GlobalLog::outfile_posLog << text;
    }
    else if (log_name == GlobalLogTypes::GOAL_LOG)
    {
        GlobalLog::outfile_goalLog << text;
        GlobalLog::outfile_goalLog.flush();
    }
}

void GlobalLog::closeLog(GlobalLogTypes log_name)
{
    std::string msg = "closeLog called " + (log_name == GlobalLogTypes::POS_LOG) ? "posLog" : "goalLog";
    Log::info("!!!!", msg.c_str());
    if (log_name == GlobalLogTypes::POS_LOG)
    {
        if (!GlobalLog::outfile_posLog.is_open()) return;
        else GlobalLog::outfile_posLog.close();
    }
    else if (log_name == GlobalLogTypes::GOAL_LOG)
    {
        if (!GlobalLog::outfile_goalLog.is_open()) return;
        else GlobalLog::outfile_goalLog.close();
    }
}
