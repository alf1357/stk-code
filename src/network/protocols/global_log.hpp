//your_custom_name.hpp: My header file
//lalala
#include <fstream>

#ifndef STK_PROTO_LOGGING_GLOBAL_H_
#define STK_PROTO_LOGGING_GLOBAL_H_

enum class GlobalLogTypes { POS_LOG, GOAL_LOG };

//now proceed here
class GlobalLog
{
    public:
        static void writeLog(std::string text, GlobalLogTypes log_name);
        static void openLog(GlobalLogTypes log_name);
        static void closeLog(GlobalLogTypes log_name);
    private:
        static std::ofstream outfile_posLog;
        static std::ofstream outfile_goalLog;
};
#endif /* STK_PROTO_LOGGING_GLOBAL_H_ */
