// from server: 100% by EspClaude
// from server: 81% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_7bf15eba1888c175.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <string>
#include <boost/thread/recursive_mutex.hpp>
typedef std::string Text;
struct Record {int number;Text text;Record(int n,const char* p):number(n),text(p){}};
typedef std::map<Text,Record*> StringMap;
typedef std::map<int,Record*> NumberMap;
typedef boost::recursive_mutex Mutex;
extern void __cdecl initialize(void (__cdecl*)(),int*);
extern void __cdecl initializeEmpty();
extern void __cdecl initializeNames();
extern int emptyFlag,namesFlag;
extern Record* emptyRecord;
extern Mutex& __cdecl getMutex();
extern StringMap* __cdecl getStringMap();
extern NumberMap* __cdecl getNumberMap();
Record* __cdecl f(const char* name,int number){
 if(!name){initialize(initializeEmpty,&emptyFlag);return emptyRecord;}
 initialize(initializeNames,&namesFlag);
 Mutex::scoped_lock guard(getMutex());
 StringMap::iterator current=getStringMap()->find(Text(name));
 if(current!=getStringMap()->end()){
  if(number!=-1){current->second->number=number;(*getNumberMap())[number]=current->second;}
  return current->second;
 }
 Record* result=new Record(number,name);
 (*getStringMap())[name]=result;
 (*getNumberMap())[number]=result;
 return result;
}
