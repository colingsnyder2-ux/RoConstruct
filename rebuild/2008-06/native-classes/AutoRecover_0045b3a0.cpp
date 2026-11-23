// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
#include <intrin.h>

extern "C" void* fn_006a0920(int size);
extern "C" void* __fastcall fn_004d9990(void* self, int unusedEdx, int a1, int a2);

namespace RBX {
    class AdornContextView;
    // INFERRED: minimal declaration; real class lives in a header not shown
    class AdornRbxGfx {
    public:
        AdornRbxGfx(AdornContextView* view);
        virtual ~AdornRbxGfx();
    };
}

// INFERRED: object created at 0x4c bytes with a virtual deleting destructor
struct Gfx4c {
    virtual ~Gfx4c() {}
};

// INFERRED: self is a window/view object; offsets taken from the disassembly
extern "C" void __fastcall fn_0045b3a0(char* self, int unusedEdx)
{
    void* mem = fn_006a0920(0x4c);
    Gfx4c* obj;
    if (mem) {
        int ptr = *(int*)(self + 0x70);
        int ctrl = *(int*)(self + 0x74);
        // shared_ptr copy: bump refcount
        if (ctrl)
            _InterlockedExchangeAdd((volatile long*)(ctrl + 4), 1);
        obj = (Gfx4c*)fn_004d9990(mem, 0, ptr, ctrl);
    } else {
        obj = 0;
    }

    Gfx4c* old = *(Gfx4c**)(self + 0xb0);
    if (obj != old && old)
        delete old;
    *(Gfx4c**)(self + 0xb0) = obj;

    void* mem2 = fn_006a0920(0x144);
    RBX::AdornRbxGfx* gfx;
    if (mem2)
        gfx = new (mem2) RBX::AdornRbxGfx(*(RBX::AdornContextView**)(self + 0xb8));
    else
        gfx = 0;

    RBX::AdornRbxGfx* old2 = *(RBX::AdornRbxGfx**)(self + 0xb4);
    if (gfx != old2 && old2)
        delete old2;
    *(RBX::AdornRbxGfx**)(self + 0xb4) = gfx;
}
