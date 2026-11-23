// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <intrin.h>
#include <new>

// INFERRED: no class header was available, so the layout below is guessed from the offsets in the disassembly.
struct SpCount { int vtbl; int use; };

// INFERRED: minimal boost::shared_ptr-like value (px, pn). Its copy constructor does the lock xadd on pn+4.
struct SharedPtrLike {
    void*    px;
    SpCount* pn;
    SharedPtrLike() : px(0), pn(0) {}
    SharedPtrLike(const SharedPtrLike& o) : px(o.px), pn(o.pn) {
        if (pn) _InterlockedExchangeAdd((volatile long*)&pn->use, 1);
    }
};

struct RefObj {
    virtual ~RefObj();
};

// INFERRED: the 0x20-byte object with vtable 0x819d24 (the vtable itself is emitted by this TU).
struct TexMgrHolder : RefObj {
    int  owner;
    char tm[0x18];
    TexMgrHolder(int o);
    virtual ~TexMgrHolder() {}
};

extern "C" void* fn_006a0920(int size); // operator new, cdecl
extern "C" void* __fastcall fn_004dbbe0(void* self, int unusedEdx, SharedPtrLike dm); // ViewG3D::ViewG3D(shared_ptr<DataModel>)
extern "C" void  __fastcall fn_0047e400(void* self, int unusedEdx, unsigned size);     // G3D::TextureManager::TextureManager(uint)

RefObj::~RefObj() {}

TexMgrHolder::TexMgrHolder(int o) : owner(o) {
    fn_0047e400(tm, 0, 0xa00000);
}

struct RobloxWndLike {
    char          pad0[0x70];
    SharedPtrLike dataModel;   // +0x70
    char          pad1[0xac - 0x80 + 0x8];
    int           field_ac;    // +0xac
    RefObj*       view;        // +0xb0
    RefObj*       texMgr;      // +0xb4
};

extern "C" void __fastcall fn_0045d850(RobloxWndLike* self, int unusedEdx)
{
    void* mem = fn_006a0920(0x6c);
    RefObj* v;
    if (mem) {
        v = (RefObj*)fn_004dbbe0(mem, 0, self->dataModel);
    } else {
        v = 0;
    }
    RefObj* old = self->view;
    if (v != old && old) {
        delete old;
    }
    self->view = v;

    void* t = fn_006a0920(0x20);
    RefObj* tm;
    if (t) {
        tm = new (t) TexMgrHolder(self->field_ac);
    } else {
        tm = 0;
    }
    RefObj* oldTm = self->texMgr;
    if (tm != oldTm && oldTm) {
        delete oldTm;
    }
    self->texMgr = tm;
}
