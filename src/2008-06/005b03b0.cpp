// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.35.0 roc_espeon_scriptdefaultbind1358c320093deaa2206.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/function.hpp>
#include <boost/bind.hpp>
struct lua_State;
unsigned noArguments();void noResults();
struct ScriptContext{typedef boost::function1<unsigned,lua_State*> Push;typedef boost::function2<void,lua_State*,unsigned> Read;void execute(int,const char*,const char*,Push,Read);void execute(int,const char*,const char*);};
void ScriptContext::execute(int identity,const char* script,const char* name){execute(identity,script,name,boost::bind(&noArguments),boost::bind(&noResults));}
