// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <vector>

// INFERRED: RTTI types at 0x936908 (source) and 0x936980 (target) unknown; placeholder polymorphic classes.
struct SrcBase { virtual ~SrcBase() {} };
struct DstDerived : SrcBase {};

// INFERRED: object layout from offsets only; vector at 0x1f4 (first 0x1f8, last 0x1fc), unknown field at 0x1ec.
struct Owner {
    char pad[0x1f4];
    std::vector<SrcBase*> items;
};

extern "C" DstDerived* __fastcall fn_004e7ff0(Owner* self, int unusedEdx)
{
    std::vector<SrcBase*>::iterator it = self->items.begin();
    std::vector<SrcBase*>::iterator end = self->items.end();
    for (; it != end; ++it) {
        DstDerived* r = dynamic_cast<DstDerived*>(*it);
        if (r)
            return r;
    }
    return 0;
}
