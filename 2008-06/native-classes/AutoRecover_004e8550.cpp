// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <intrin.h>

// INFERRED: layout from disassembly offsets only; no native header found.
extern "C" void __fastcall fn_005954b0(void* self, int unusedEdx); // scoped_connection::~scoped_connection
extern "C" void __fastcall fn_004e8250(void* self, int unusedEdx); // PartChunk::~PartChunk

struct ScopedConn {
    char pad[0x14];
    ~ScopedConn() { fn_005954b0(this, 0); }
};

// INFERRED: boost sp_counted_base (use count +4, weak count +8, vtbl[1]=dispose, vtbl[2]=destroy)
struct CountedBase {
    virtual void unused() {}
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long use;
    long weak;
};

struct SpPtr {
    void* px;
    CountedBase* pn;
    ~SpPtr() {
        if (pn && _InterlockedDecrement(&pn->use) == 0) {
            pn->dispose();
            if (_InterlockedDecrement(&pn->weak) == 0)
                pn->destroy();
        }
    }
};

struct PartChunkBase {
    virtual ~PartChunkBase() { fn_004e8250(this, 0); }
    char pad[0xdc - 4];
};

struct PartChunkDerived : PartChunkBase {
    SpPtr ptr;        // +0xdc
    ScopedConn connA; // +0xe0
    ScopedConn connB; // +0xf4
    virtual ~PartChunkDerived() {}
};

// Target body is the destructor above (vtable 0x826ef8); this extern "C" entry
// forwards for the fn_ naming convention.
extern "C" void __fastcall fn_004e8550(PartChunkDerived* self, int unusedEdx)
{
    self->~PartChunkDerived();
}
