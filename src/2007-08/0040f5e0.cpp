// from server: 100% by EspClaude
// from server: 54% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: boost-1.34.1 roc_claude_6d8f53b9136e41cc.cpp

// Candidate translation unit (score above; library headers required).
// Library units are preprocessed (/EP) without the grid's /MD /EHsc, so restore the
// client build's CRT-DLL and exception macros (the target calls msvcp80 through the IAT).
#ifndef _DLL
#define _DLL
#endif
#ifndef _MT
#define _MT
#endif
#ifndef _CPPUNWIND
#define _CPPUNWIND
#endif
// 0x0040f5e0: RBX::DeleteSelectionVerb ctor (vtable 0x786d60 RTTI .?AVDeleteSelectionVerb@RBX@@).
// ret 0x24 = two pointer args + std::string by value (0x1c); the base ctor at 0x562130 is the
// stored exact ??0DuplicateSelectionVerb@@QAE@PAX0V?$basic_string...@Z (void*, void*, std::string).
#include <string>

struct DuplicateSelectionVerb
{
    DuplicateSelectionVerb(void*, void*, std::string);
    virtual ~DuplicateSelectionVerb();
};

namespace RBX
{
    struct DeleteSelectionVerb : DuplicateSelectionVerb
    {
        DeleteSelectionVerb(void*, void*, std::string);
        virtual ~DeleteSelectionVerb();
    };

    DeleteSelectionVerb::DeleteSelectionVerb(void* first, void* second, std::string name)
        : DuplicateSelectionVerb(first, second, name)
    {
    }
}
