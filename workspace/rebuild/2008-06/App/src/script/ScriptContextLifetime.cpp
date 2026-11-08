#include "script/ScriptContext.h"
#include <boost/date_time/posix_time/posix_time.hpp>
RBX::ScriptContext::ScriptContext()
    : globalState(NULL), scripts(std::less<Script*>()),
      nextPendingScripts(boost::posix_time::second_clock::local_time()),
      scriptsDisabled(false), exeTime0(0), exeTime1(0), exeState(0)
{
    setName("Script Context");
}
RBX::ScriptContext::~ScriptContext() {}
