// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_threadstatevector_50483b440166ac6f.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern unsigned long __cdecl getValue();
struct S {std::vector<void*> state;unsigned long threadId,value;S();virtual ~S();};
S::S(){threadId=GetCurrentThreadId();value=getValue();}
