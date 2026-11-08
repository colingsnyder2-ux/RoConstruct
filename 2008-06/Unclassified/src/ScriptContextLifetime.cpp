// >>> native-status (generated) -- do not edit >>>
// ScriptContextLifetime | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src fa545853 | roc native-status --write
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
