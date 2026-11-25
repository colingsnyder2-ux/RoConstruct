// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_large_tree_c038c7cd2fa8574a.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <set>
template class std::set<int>;
std::pair<std::set<int>::iterator,bool> ins(std::set<int>& s,int v){ return s.insert(v); }
std::set<int>::iterator insh(std::set<int>& s,std::set<int>::iterator w,int v){ return s.insert(w,v); }
std::set<int>::iterator era(std::set<int>& s,std::set<int>::iterator w){ return s.erase(w); }
std::set<int>::iterator era2(std::set<int>& s,std::set<int>::iterator a,std::set<int>::iterator b){ return s.erase(a,b); }
std::set<int>::size_type era3(std::set<int>& s,int k){ return s.erase(k); }
