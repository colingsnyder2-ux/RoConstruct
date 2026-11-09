// from server: 100% by EspClaude
// from server: 97% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_576de34493420f37.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <set>
#include <boost/thread/recursive_mutex.hpp>
extern "C" __declspec(dllimport) int __stdcall PostMessageA(void*,unsigned int,unsigned int,long);
struct S {
 int reserved;boost::recursive_mutex mutex;char lockTail[28];std::map<unsigned int,int> tree;char padding[32];bool pending,disabled;char alignment[2];std::set<int> collection;
struct Ev{int key;int other;};
 void f(const void*,Ev);
};
void S::f(const void*,Ev ev) {
 boost::recursive_mutex::scoped_lock guard(mutex);
 if(!disabled) {
  std::map<unsigned int,int>::const_iterator found=tree.find(ev.key);
  if(found!=tree.end())collection.insert(found->second);
  boost::detail::thread::lock_ops<boost::recursive_mutex>::lock(mutex);
  if(!pending) {
   void* window=*reinterpret_cast<void**>(reinterpret_cast<char*>(this)-360);
   if(window)PostMessageA(window,0x465,0,0);
   pending=true;
  }
  boost::detail::thread::lock_ops<boost::recursive_mutex>::unlock(mutex);
 }
}

