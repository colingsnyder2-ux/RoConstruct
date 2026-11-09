// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_contentidexpression62d914713cdedfa6.cpp

// Candidate translation unit (score above; library headers required).
#include "util/ContentProvider.h"
struct Temporary {void* value;__declspec(dllimport) ~Temporary() throw();};
extern const char* (__thiscall* text_access)(Temporary*);
struct X {char padding[0xa4];Temporary copy();RBX::ContentId get();};
RBX::ContentId X::get(){return RBX::ContentId(text_access(&copy()));}
