// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: layout from stores at +8,+0xc,+0x10,+0x18,+0x1c,+0x20; size 0x28 from allocation.
struct Local_005fdcf0 {
    virtual ~Local_005fdcf0() {}
    int a8, aC, a10, pad14, a18, a1C, a20, pad24;
    Local_005fdcf0(int p0, int p1, int p2, int p3, int p4, int p5) {
        a8 = p0; aC = p1; a10 = p2; a18 = p3; a1C = p4; a20 = p5;
    }
};

// INFERRED: static cdecl PropDescriptor::getset returning auto_ptr<GetSet> via hidden pointer
// (first stack arg), followed by five stack args; ecx is unused.
extern "C" Local_005fdcf0** fn_005fdcf0(Local_005fdcf0** self, int p0, int p1, int p2, int p3, int p4)
{
    Local_005fdcf0* obj = 0;
    obj = new Local_005fdcf0(p0, p1, p2, p3, p4, 0);
    *self = obj;
    return self;
}
