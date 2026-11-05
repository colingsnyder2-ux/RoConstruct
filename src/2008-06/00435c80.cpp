// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_declarationviewnative5f28cccaa2e0ec62.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/object.h"
#include <boost/bind.hpp>
#include <boost/thread/recursive_mutex.hpp>
#include <algorithm>
#include <windows.h>
#include <commctrl.h>
using namespace RBX::Reflection;
extern boost::recursive_mutex&getMutex();
struct First{virtual ~First();};struct Second{virtual ~Second();};
struct View:First,Second{char prefix[0x18];HWND window;char gap[0x88];const ClassDescriptor*source;void update(const ClassDescriptor*);void addProperty(PropertyDescriptor*);void addFunction(FunctionDescriptor*);void addSignal(SignalDescriptor*);static int __stdcall compare(LPARAM,LPARAM,LPARAM);};
void View::update(const ClassDescriptor*p){::SendMessageA(window,TVM_DELETEITEM,0,(LPARAM)TVI_ROOT);source=p;boost::recursive_mutex::scoped_lock lock(getMutex());std::for_each(p->PropertyContainer::descriptors_begin(),p->PropertyContainer::descriptors_end(),boost::bind(&View::addProperty,this,_1));std::for_each(p->FunctionContainer::descriptors_begin(),p->FunctionContainer::descriptors_end(),boost::bind(&View::addFunction,this,_1));std::for_each(p->SignalContainer::descriptors_begin(),p->SignalContainer::descriptors_end(),boost::bind(&View::addSignal,this,_1));TVSORTCB sort;sort.hParent=TVI_ROOT;sort.lpfnCompare=&View::compare;::SendMessageA(window,TVM_SORTCHILDRENCB,0,(LPARAM)&sort);}
