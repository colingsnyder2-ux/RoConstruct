// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_filteredfind_800f54b41660255a.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <algorithm>
typedef bool(__cdecl* Pred)(int);struct S{char padding[316];std::vector<int> items;int f(Pred);};int S::f(Pred pred){std::vector<int>::iterator found=std::find_if(items.begin(),items.end(),pred);if(found!=items.end())return *found;return 0;}
