// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.35.0 roc_espeon_scriptargumentbind135bf95ed9e0b65612b.cpp

// Candidate translation unit (score above; library headers required).
#include <memory>
#include <boost/function.hpp>
#include <boost/bind.hpp>
struct lua_State;
struct Values{~Values();};
unsigned pushArguments(const Values&,lua_State*);void readResults(std::auto_ptr<Values>&,lua_State*,unsigned);
struct ScriptContext{typedef boost::function1<unsigned,lua_State*> Push;typedef boost::function2<void,lua_State*,unsigned> Read;void execute(int,const char*,const char*,Push,Read);std::auto_ptr<Values> execute(int,const char*,const char*,const Values&);};
std::auto_ptr<Values> ScriptContext::execute(int identity,const char* script,const char* name,const Values& arguments){std::auto_ptr<Values> result;execute(identity,script,name,boost::bind(&pushArguments,boost::cref(arguments),_1),boost::bind(&readResults,boost::ref(result),_1,_2));return result;}
