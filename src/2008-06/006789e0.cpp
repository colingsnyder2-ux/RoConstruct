// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// VS2008 <algorithm> std::sort on float*: target fcomp/fstp swaps on 4-byte elements,
// caller 006791e0 (_Sort) and callee 00678880 (_Median).
#include <algorithm>

template std::pair<float*, float*> std::_Unguarded_partition<float*>(float*, float*);
