// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS /EHsc /MD
#include <string>
struct Info { int type; };
class Logger {
public:
    virtual Logger* get();
    void write(int level, const char* msg);
};
extern Logger* gLogger;
static inline Logger* logger() { return gLogger ? gLogger->get() : 0; }
std::string describe(Info* info, int a, int b, int c);
bool __stdcall onEvent(Info* info, int a, int b, int c)
{
    if (info->type != 1)
        return false;
    if (logger())
        logger()->write(0, describe(info, a, b, c).c_str());
    return true;
}
