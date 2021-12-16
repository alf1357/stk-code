//your_custom_name.hpp: My header file
//lalala
#include <fstream>

#ifndef STK_PROTO_LOGGING_GLOBAL_H_
#define STK_PROTO_LOGGING_GLOBAL_H_

//now proceed here
class GlobalLog
{
    public:
        static void write_Log(std::string text, std::string log_name); 
        static void open_Log(std::string log_name);
        static void close_Log(std::string log_name);
    private:
        static std::ofstream outfile_posLog;
        static std::ofstream outfile_goalLog;
};
#endif /* STK_PROTO_LOGGING_GLOBAL_H_ */
