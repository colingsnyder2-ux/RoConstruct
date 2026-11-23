// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header was provided, so the layout below is local and minimal.
#include <windows.h>

extern "C" void* fn_006a0920(unsigned size);                        // operator new
extern "C" void* __fastcall fn_004dbbe0(void* self, int unusedEdx, void* dmPtr, long* dmRef); // ViewG3D ctor
extern "C" void* __fastcall fn_0047e400(void* self, int unusedEdx, unsigned bytes);          // TextureManager ctor

// INFERRED: boost::shared_ptr<DataModel> by value (ptr + refcount block, atomic use-count increment)
struct SharedDM {
    void* px;
    long* pn;
    SharedDM(const SharedDM& o) : px(o.px), pn(o.pn) {
        if (pn) InterlockedIncrement(pn + 1);
    }
};

// INFERRED: ref-counted objects with a virtual deleting destructor in slot 0
struct Deletable {
    virtual void destroy(int del) = 0;
};

struct TextureManagerHolder : Deletable {
    void* owner;
    char textureManager[0x18];
};

struct CRobloxWnd {
    char pad0[0x70];
    SharedDM dataModel;       // +0x70
    char pad1[0xac - 0x78];
    void* owner;              // +0xac
    Deletable* view;          // +0xb0
    Deletable* texMgr;        // +0xb4
};

extern "C" void fn_0045d850(CRobloxWnd* self)
{
    void* mem = fn_006a0920(0x6c);
    Deletable* v = 0;
    if (mem)
        v = (Deletable*)fn_004dbbe0(mem, 0, self->dataModel.px, self->dataModel.pn);
    if (v != self->view && self->view)
        self->view->destroy(1);
    self->view = v;

    TextureManagerHolder* t = (TextureManagerHolder*)fn_006a0920(0x20);
    if (t) {
        t->owner = self->owner;
        fn_0047e400(t->textureManager, 0, 0xa00000);
    }
    Deletable* old = self->texMgr;
    if ((Deletable*)t != old && old)
        old->destroy(1);
    self->texMgr = t;
}
