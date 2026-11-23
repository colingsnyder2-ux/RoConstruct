// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <intrin.h>

// INFERRED: layout from the disassembly. Only the touched offsets are modeled.
struct SpCountedBase {
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long useCount;
    long weakCount;
};

struct ViewNewDerived {
    void* vtbl;
    char pad0[0xdc - 4];
    SpCountedBase* pn;
    char connB[0x14];
    char connA[0x14];
};

extern "C" void __fastcall fn_005954b0(void* self, int unusedEdx); // boost::signals::scoped_connection::~scoped_connection
extern "C" void __fastcall fn_004e8250(void* self, int unusedEdx); // RBX::ViewNew::PartChunk::~PartChunk
extern "C" char g_00826f2c[]; // INFERRED: derived-class vtable

extern "C" void __fastcall fn_004e85f0(ViewNewDerived* self, int unusedEdx)
{
    // INFERRED: SEH unwind (states 2..0) comes from member dtors in the original; modeled as plain calls.
    self->vtbl = g_00826f2c;
    fn_005954b0(self->connA, 0);
    fn_005954b0(self->connB, 0);

    SpCountedBase* p = self->pn;
    if (p) {
        if (_InterlockedDecrement(&p->useCount) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weakCount) == 0)
                p->destroy();
        }
    }
    fn_004e8250(self, 0);
}
