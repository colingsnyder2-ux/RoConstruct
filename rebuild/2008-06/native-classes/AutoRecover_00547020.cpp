// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <set>

// INFERRED: the owning class is unknown. The disassembly only shows a std::set<int>
// at offset 0xc, whose _Tree destructor is called; the 12 bytes before it are padding.
struct Holder547020 {
    int pad[3];
    std::set<int> items;
};

extern "C" void __fastcall fn_00547020(Holder547020* self, int unusedEdx)
{
    typedef std::set<int> IntSet;
    self->items.~IntSet();
}
