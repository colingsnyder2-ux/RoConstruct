// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_vectorthreemaps7694adb94d5131f7.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <map>
#include <string>
struct S {std::vector<void*> values;std::map<int,int> a;std::map<void*,void*> b;std::map<std::string,int> c;int value;S(int);};
S::S(int n):value(n){}
