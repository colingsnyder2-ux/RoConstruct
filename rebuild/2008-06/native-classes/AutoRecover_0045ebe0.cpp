// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
#include "stats/Stats.h"

// INFERRED: the earlier compiler errors (C2084 "already has a body", C2614 "'value' is not
// a member") show that stats/Stats.h already defines RBX::Stats::Item::Item() inline. That
// body holds the +0x130 double zero-init, the vtable stores and the std::string member
// construction. So this file does not redefine the constructor.
//
// Instead it forces the compiler to emit the inline constructor out of line as
// ??0Item@Stats@RBX@@QAE@XZ. It does this with a file-local, explicitly instantiated
// template that constructs an Item, while inline expansion is disabled.
#pragma inline_depth(0)

namespace {

template <class T>
T* constructInPlace(void* mem)
{
    return new (mem) T();
}

// INFERRED: explicit instantiation forces the template body to be emitted. With inlining
// disabled, that body makes an out-of-line call to the Item constructor, so the
// constructor gets emitted too.
template RBX::Stats::Item* constructInPlace<RBX::Stats::Item>(void*);

} // namespace
