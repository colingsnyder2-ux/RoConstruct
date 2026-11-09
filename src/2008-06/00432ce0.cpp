// from server: 100% by EspClaude
// from server: 95% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_03b9162679b3b420.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
extern "C" {
__declspec(dllimport) void __stdcall EnterCriticalSection(void*);
__declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
__declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
}
struct Object {char reserved[36];unsigned references;char remaining[28];Object(unsigned long);};
typedef std::map<unsigned int,Object*> Map;
extern Map objects;
extern unsigned char criticalSection[24];
struct Lock {void* section;bool locked;Lock(void* p):section(p){EnterCriticalSection(section);locked=true;}void release(){LeaveCriticalSection(section);locked=false;}~Lock(){if(locked)LeaveCriticalSection(section);}};
Object* getObject() {
 Lock lock(criticalSection);
 unsigned int thread=GetCurrentThreadId();
 Map::iterator it=objects.find(thread);
 if(it!=objects.end()) {
  ++it->second->references;
  Object* result=it->second;
  lock.release();return result;
 }
 Object* object=new Object(thread);
 objects[thread]=object;
 ++object->references;
 lock.release();return object;
}

