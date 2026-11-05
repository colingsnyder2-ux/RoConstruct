// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_singletonvector_a107cb99bdfaee91.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
typedef std::vector<int> Buffer;extern int __cdecl sub_615940(int,int,Buffer*,int,int,float);int __cdecl sub_6160b0(int a,int b,int source,int c,int d,float e){Buffer buffer;buffer.push_back(source);return sub_615940(a,b,&buffer,c,d,e);}
