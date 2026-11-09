// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_declarationviewvector0294042db3ce9230.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <algorithm>
#include <boost/bind.hpp>
#pragma pointers_to_members(full_generality,multiple_inheritance)
extern "C" long (__stdcall *SendMessageA)(void*,unsigned int,unsigned int,long);
struct Mutex {void*handle;bool criticalSection;unsigned count;void lock();void unlock();};
extern Mutex* getMutex();
struct Lock {Mutex*mutex;bool held;Lock(Mutex*p):mutex(p),held(false){mutex->lock();held=true;}~Lock(){if(held)mutex->unlock();}};
struct Range {char padding[16];std::vector<void*> values;};
extern void compareCallback();
struct SortInfo {unsigned parent;void(*compare)();unsigned parameter;};
struct View {char padding[32];void*window;char remainder[136];Range*range;void visit(void*);void update(Range*);};
void View::update(Range*value){SendMessageA(window,0x1101,0,0xffff0000);range=value;Lock guard(getMutex());std::for_each(value->values.begin(),value->values.end(),boost::bind(&View::visit,this,_1));SortInfo sort;sort.parent=0xffff0000;sort.compare=compareCallback;SendMessageA(window,0x1115,0,(long)&sort);}
