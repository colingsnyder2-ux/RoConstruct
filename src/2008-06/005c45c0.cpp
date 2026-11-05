// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_visitdeadline_46db66ed1d73fba8.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/thread/thread.hpp>
#include <boost/thread/xtime.hpp>
#include <string>
struct Parser {
    std::string first;
    std::string second;

    Parser(const std::string&);
    ~Parser();
    void parse(std::string&);
};

__forceinline Parser::Parser(const std::string& source)
    : first(source), second()
{
}

__forceinline Parser::~Parser()
{
}

int process(std::string source, int duration)
{
    try {
        std::string result;
        Parser parser(source);
        parser.parse(result);
    } catch (...) {
    }
    boost::xtime deadline;
    boost::xtime_get(&deadline, boost::TIME_UTC);
    deadline.sec += duration;
    boost::thread::sleep(deadline);
    return 1;
}
