// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_selectionmap_db932fc2d59f81ca.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <set>
#include <boost/thread/recursive_mutex.hpp>
struct CSelectionTreeCtrl {
 char padding[152];std::map<int,int> source;char tail[12];boost::recursive_mutex mutex;char gap[52];std::set<int> destination;
 void func_00424600(int);
};
void CSelectionTreeCtrl::func_00424600(int key) {
 boost::recursive_mutex::scoped_lock guard(mutex);
 std::map<int,int>::iterator found=source.find(key);
 if(found!=source.end())destination.insert(found->second);
}
