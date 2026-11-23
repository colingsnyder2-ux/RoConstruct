// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header was supplied, so layouts and types below are guesses taken from the disassembly.
// Offsets used: +4 MaterialFactory-owner, +8 RenderScene, +0xC TextureManager, +0x10 factory, +0x1C and +0x30 scoped_connections.

extern "C" {
int fn_006a0920(int size);
int __fastcall fn_004f0920(void* self, int unusedEdx, int a1);
int __fastcall fn_004b3870(void* self, int unusedEdx);
int __fastcall fn_004d9610(void* self, int unusedEdx, int a1);
int __fastcall fn_004d8390(void* self, int unusedEdx, int a1, int a2, int a3, int a4);
int __fastcall fn_004d7c00(void* self, int unusedEdx, int a1, int a2);
int __fastcall fn_004d96b0(void* self, int unusedEdx, int a1);
}

struct Releasable {
    virtual void v0(int) = 0;
};

struct ViewBaseLike {
    void* vtbl;
    Releasable* owner;      // +4
    Releasable* scene;      // +8
    Releasable* textures;   // +0xC
    void* factory;          // +0x10
    char pad[0x48 - 0x14];
    bool flag;              // +0x48
};

struct SharedCount {
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    int use;
    int weak;
};

extern "C" ViewBaseLike* __fastcall fn_004d9990(ViewBaseLike* self, int unusedEdx, void* dmPx, SharedCount* dmPn)
{
    // INFERRED: full body (ViewBase ctor call at 0x4d8a20, RenderScene/TextureManager/MaterialFactory
    // construction, two signal connections to DataModel) needs the real headers; the helpers
    // above are called in disassembly order.
    int scene = fn_006a0920(0x590);
    int tm = fn_006a0920(0x18);
    int owner = fn_006a0920(8);
    int fac = fn_006a0920(0x10);
    fn_004f0920((void*)fac, 0, (int)self->textures);
    void* dm = dmPx ? (void*)fn_004b3870(dmPx, 0) : 0;
    fn_004d9610(self, 0, (int)dm);
    fn_004d8390((void*)0x97a88c, 0, (int)dm, 0, 0, 10);
    fn_004d7c00(self, 0, 0x4db5f0, (int)self);
    fn_004d96b0(self, 0, 0);
    (void)scene; (void)tm; (void)owner; (void)dmPn;
    return self;
}
