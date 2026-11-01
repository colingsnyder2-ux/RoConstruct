// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.35.0 roc_espeon_scriptthreadbind1357faa61c775a47f40.cpp

// Candidate translation unit (score above; library headers required).
#include <memory>
#include <boost/function.hpp>
#include <boost/bind.hpp>
struct lua_State;
struct Values{~Values();};
unsigned pushArguments(const Values&,lua_State*);void readResults(std::auto_ptr<Values>&,lua_State*,unsigned);
struct ScriptContext{typedef boost::function1<unsigned,lua_State*> Push;typedef boost::function2<void,lua_State*,unsigned> Read;void execute(lua_State*,Push,Read);std::auto_ptr<Values> execute(lua_State*,const Values&);};
std::auto_ptr<Values> ScriptContext::execute(lua_State* thread,const Values& arguments){std::auto_ptr<Values> result;execute(thread,boost::bind(&pushArguments,boost::cref(arguments),_1),boost::bind(&readResults,boost::ref(result),_1,_2));return result;}
