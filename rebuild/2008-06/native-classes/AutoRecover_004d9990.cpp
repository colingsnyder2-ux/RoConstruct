// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header was available, so this is the constructor of a ViewBase-derived
// class. Types are minimal local stand-ins and unknown callees use the fn_<addr> convention.
#include <intrin.h>

struct SpCountedBase {
    virtual void dispose() = 0;   // vtbl[0]
    virtual void destroy() = 0;   // vtbl[1]
    int use_count;                // +4
    int weak_count;               // +8
};

struct IDeletable {
    virtual void* scalarDelete(int flags) = 0;
};

typedef void (__fastcall *SceneInitFn)(void* self, int edx, float a, float b, int c, float d);

struct NativeView {
    void* vtbl;                   // +0x00
    char* obj4;                   // +0x04
    void** scene;                 // +0x08
    void** textureMgr;            // +0x0c
    void* materialFactory;        // +0x10
    char pad14[0x1c - 0x14];
    char conn1[0x14];             // +0x1c scoped_connection
    char conn2[0x14];             // +0x30 scoped_connection
    char pad44[4];
    unsigned char flag48;         // +0x48
};

extern "C" {
    extern char vtbl_00826c70[];
    extern char vtbl_00826b64[];
    extern char vtbl_00819cd8[];
    extern char signalDesc_0097a88c[];
    extern char signalDesc_00973e40[];

    int  fn_006a0920(int size);                      // operator new
    void fn_006a067a(void* p);                       // operator delete
    void* __fastcall fn_004d8a20(void* self, int edx, void* px, SpCountedBase* pn);   // ViewBase ctor
    void* __fastcall fn_007aae40(void* self, int edx);                                // RenderScene ctor
    void* __fastcall fn_0047e400(void* self, int edx, unsigned size);                 // TextureManager ctor
    void  __fastcall fn_0045c680(void* self, int edx);                                // Table::freeMemory
    int   __fastcall fn_004f0920(void* self, int edx, int a1);
    void  __fastcall fn_004d7460(void* self, int edx);                                // ~MaterialFactory
    int   __fastcall fn_004b3870(void* self, int edx);
    int   __fastcall fn_004d9610(void* self, int edx, int a1);
    int   __fastcall fn_004d8390(void* self, int edx, int a1, int a2, int a3, int a4);
    int   __fastcall fn_004d7c00(void* self, int edx, int a1, int a2);
    int   __fastcall fn_004d96b0(void* self, int edx, int a1);
    void* __fastcall fn_00595540(void* self, int edx, void* conn);                    // scoped_connection::operator=
    void  __fastcall fn_00595370(void* self, int edx);                                // ~connection
    void  __fastcall fn_0049f710(void* self, int edx);                                // ~slot
    int   __fastcall fn_004a3340(void* self, int edx, int a1, int a2, int a3, int a4);// TSignalDesc::connect

    void* __fastcall fn_004d9990(NativeView* self, int unusedEdx, void* dmPx, SpCountedBase* dmPn);
}

struct SlotBinder {
    int target;
    void* owner;
};

extern "C" void* __fastcall fn_004d9990(NativeView* self, int unusedEdx, void* dmPx, SpCountedBase* dmPn)
{
    if (dmPn)
        _InterlockedExchangeAdd((volatile long*)&dmPn->use_count, 1);
    fn_004d8a20(self, 0, dmPx, dmPn);

    self->vtbl = vtbl_00826c70;
    self->flag48 = 0;

    // render scene
    {
        void* mem = (void*)fn_006a0920(0x590);
        void** scene = mem ? (void**)fn_007aae40(mem, 0) : 0;
        void** old = self->scene;
        if (scene != old && old) {
            typedef void (__fastcall *DelFn)(void*, int, int);
            ((DelFn)(*(void***)old)[0])(old, 0, 1);
        }
        self->scene = scene;
    }

    // texture manager
    {
        void* mem = (void*)fn_006a0920(0x18);
        void** tm = mem ? (void**)fn_0047e400(mem, 0, 0xa00000) : 0;
        void** old = self->textureMgr;
        if (tm != old && old) {
            *(void**)old = vtbl_00819cd8;
            fn_0045c680(old, 0);
            fn_006a067a(old);
        }
        self->textureMgr = tm;
    }

    // small object referencing the scene
    {
        void** mem = (void**)fn_006a0920(8);
        void** obj = 0;
        if (mem) {
            mem[1] = self->scene;
            mem[0] = vtbl_00826b64;
            obj = mem;
        }
        char* old = self->obj4;
        if ((char*)obj != old && old) {
            typedef void (__fastcall *DelFn)(void*, int, int);
            ((DelFn)(*(void***)old)[6])(old, 0, 1);
        }
        self->obj4 = (char*)obj;
    }

    // material factory
    {
        void* mem = (void*)fn_006a0920(0x10);
        void* mf = mem ? (void*)fn_004f0920(mem, 0, (int)self->textureMgr) : 0;
        void* old = self->materialFactory;
        if (mf != old && old) {
            fn_004d7460(old, 0);
            fn_006a067a(old);
        }
        self->materialFactory = mf;
    }

    // scene init (virtual slot 2)
    {
        void** scene = self->scene;
        SceneInitFn fn = (SceneInitFn)(*(void***)scene)[2];
        fn(scene, 0, 0.0f, 0.0f, 0, 0.0f);
    }

    // first connection
    int edi = dmPx ? fn_004b3870(dmPx, 0) : 0;
    {
        SlotBinder binder;
        char slot[0x14];
        char conn[0x10];
        binder.target = 0x4db600;
        binder.owner = self;
        fn_004d9610(slot, 0, (int)&binder);
        int sigObj = edi ? edi + 0x14 : 0;
        int c = fn_004d8390(signalDesc_0097a88c, 0, (int)conn, sigObj, (int)slot, 10);
        fn_00595540(self->conn1, 0, (void*)c);
        fn_00595370(conn, 0);
        fn_0049f710(slot, 0);
    }

    // second connection
    {
        int dm204 = *(int*)((char*)dmPx + 0x204);
        fn_004d7c00((void*)dm204, 0, 0x4db5f0, (int)self);

        SlotBinder binder;
        char slot[0x14];
        char conn[0x10];
        binder.target = 0x4db5f0;
        binder.owner = self;
        fn_004d96b0(slot, 0, (int)&binder);
        int p = *(int*)((char*)dmPx + 0x204);
        int sigObj = p ? p + 0x14 : 0;
        int c = fn_004a3340(signalDesc_00973e40, 0, (int)conn, sigObj, (int)slot, 10);
        fn_00595540(self->conn2, 0, (void*)c);
        fn_00595370(conn, 0);
        fn_0049f710(slot, 0);
    }

    // release the by-value shared_ptr argument
    if (dmPn) {
        if (_InterlockedExchangeAdd((volatile long*)&dmPn->use_count, -1) == 1) {
            dmPn->dispose();
            if (_InterlockedExchangeAdd((volatile long*)&dmPn->weak_count, -1) == 1)
                dmPn->destroy();
        }
    }
    return self;
}
