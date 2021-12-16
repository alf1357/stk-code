#include "global_log.hpp"
#include <network/server_config.hpp>
#include <fstream>
#include <iostream>

std::ofstream GlobalLog::outfile_posLog = std::ofstream(ServerConfig::m_pos_log_path);
std::ofstream GlobalLog::outfile_goalLog = std::ofstream(ServerConfig::m_logfile_name) ;

void GlobalLog::open_Log(std::string log_name)
{
    if (log_name=="posLog")
    {
        if (GlobalLog::outfile_posLog.is_open()) return;
        else GlobalLog::outfile_posLog.open(ServerConfig::m_pos_log_path,std::ios_base::app);
    }
    else if (log_name=="goalLog")
    {
        if (GlobalLog::outfile_goalLog.is_open()) return;
        else GlobalLog::outfile_goalLog.open(ServerConfig::m_logfile_name,std::ios_base::app);
    }
}

void GlobalLog::write_Log(std::string text , std::string log_name)
{
    open_Log(log_name); //test
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
