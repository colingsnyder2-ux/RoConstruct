// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no native headers were available for this class, so every type is a local
// layout stand-in and every unknown callee is declared as an extern "C" fn_<addr>.
#include <intrin.h>

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct SConn {              // boost::signals::scoped_connection, 0x14 bytes
    int  a;
    int  b;
    int  c;
    char d; char pad0[3];
    char e; char pad1[3];
};

struct InstanceLike;
struct SharedInstance {     // boost::shared_ptr<Instance> layout
    InstanceLike* p;
    int*          cnt;
};

struct ViewChunk {
    void*          vptr;       // 0x00
    long           refCount;   // 0x04
    char           chunkRest[0x28 - 8];
    char           cframe[0x30];   // 0x28, G3D::CoordinateFrame
    SConn          conn[5];    // 0x58, 0x6c, 0x80, 0x94, 0xa8
    SharedInstance inst;       // 0xbc
    int            f_c4;       // 0xc4
    char           f_c8;       // 0xc8
    char           padC8[3];
    int            f_cc;       // 0xcc
    void*          arg3;       // 0xd0
    int            f_d4;       // 0xd4
};

// INFERRED: unknown globals (vtable and signal descriptors)
extern "C" char g_00826ec4[];
extern "C" char g_00973e90[];
extern "C" char g_00973c6c[];
extern "C" char g_00973c38[];
extern "C" char g_00973f48[];

// INFERRED: slot callbacks whose addresses are bound into the slots
extern "C" void __fastcall fn_004ea5e0(void* self, int unusedEdx, void* a);
extern "C" void __fastcall fn_004e73b0(void* self, int unusedEdx, void* a);
extern "C" void __fastcall fn_004e6520(void* self, int unusedEdx, void* a);
extern "C" void __fastcall fn_004e5f10(void* self, int unusedEdx, void* a);

extern "C" int  __fastcall fn_004e8160(void* self, int unusedEdx, float a);          // Chunk::Chunk(float)
extern "C" void __fastcall fn_004782d0(void* self, int unusedEdx);                   // CoordinateFrame::CoordinateFrame
extern "C" void __fastcall fn_0045ad90(void* self, int unusedEdx);                   // zeroWeakPointers
extern "C" int  __fastcall fn_004ea720(void* self, int unusedEdx, int a1);
extern "C" int  __fastcall fn_004ea7c0(void* self, int unusedEdx, int a1);
extern "C" int  __fastcall fn_0042b680(void* self, int unusedEdx, int a1, int a2, int a3, int a4);
extern "C" int  __fastcall fn_004a3340(void* self, int unusedEdx, int a1, int a2, int a3, int a4);
extern "C" void __fastcall fn_00595540(void* self, int unusedEdx, void* conn);       // scoped_connection::operator=
extern "C" void __fastcall fn_00595370(void* self, int unusedEdx);                   // connection::~connection
extern "C" void __fastcall fn_0049f710(void* self, int unusedEdx);                   // slot::~slot
extern "C" void __fastcall fn_004e7ed0(void* self, int unusedEdx, int fnPtr, void* bound); // Instance::visitChildren

struct ConnTmp {
    char buf[0x10];
    ~ConnTmp() { fn_00595370(buf, 0); }
};
struct SlotTmp {
    char buf[0x20];
    ~SlotTmp() { fn_0049f710(buf, 0); }
};
struct Bound {
    int   fn;
    void* self;
};

struct WeakRel {   // temporary shared_ptr-like returned by virtual call
    int* p;
    ~WeakRel() {
        if (p) {
            if (InterlockedDecrement((volatile long*)(p + 1)) == 0) {
                fn_0045ad90(p, 0);
                if (p) {
                    void** vt = *(void***)p;
                    typedef void (__thiscall *Dtor)(void*, int);
                    ((Dtor)vt[0])(p, 1);
                }
            }
        }
    }
};

static inline int instSub(SharedInstance* s)
{
    return s->p ? (int)((char*)s->p + 0x14) : 0;
}

extern "C" ViewChunk* __fastcall fn_004eaae0(ViewChunk* self, int unusedEdx, float arg1, SharedInstance* arg2, void* arg3)
{
    fn_004e8160(self, 0, arg1);
    self->vptr = (void*)g_00826ec4;   // INFERRED: vtable
    fn_004782d0(self->cframe, 0);

    for (int i = 0; i < 5; ++i) {
        self->conn[i].b = 0;
        self->conn[i].c = 0;
        self->conn[i].d = 0;
        self->conn[i].e = 0;
    }

    self->inst.p   = arg2->p;
    self->inst.cnt = arg2->cnt;
    if (self->inst.cnt)
        _InterlockedExchangeAdd((volatile long*)(self->inst.cnt + 1), 1);
    self->f_c4 = 0;
    self->f_c8 = 1;
    self->f_cc = 0;
    self->arg3 = arg3;
    self->f_d4 = 0;

    InterlockedIncrement(&self->refCount);

    {
        // INFERRED: result of a virtual call on a sub-object of arg3, released immediately
        WeakRel rel;
        void* obj = *(void**)((char*)arg3 + 4);
        void** vt = *(void***)obj;
        typedef void (__thiscall *Fn)(void*, void*);
        ((Fn)vt[1])(obj, &rel.p);
    }

    {
        Bound b; b.fn = (int)(void*)&fn_004ea5e0; b.self = self;
        SlotTmp slot;
        fn_004ea720(slot.buf, 0, (int)&b);
        ConnTmp c;
        fn_004a3340((void*)g_00973e90, 0, (int)c.buf, instSub(arg2), (int)slot.buf, 10);
        fn_00595540(&self->conn[0], 0, c.buf);
    }
    {
        Bound b; b.fn = (int)(void*)&fn_004e73b0; b.self = self;
        SlotTmp slot;
        fn_004ea720(slot.buf, 0, (int)&b);
        ConnTmp c;
        fn_004a3340((void*)g_00973c6c, 0, (int)c.buf, instSub(arg2), (int)slot.buf, 10);
        fn_00595540(&self->conn[1], 0, c.buf);
    }
    {
        Bound b; b.fn = (int)(void*)&fn_004e6520; b.self = self;
        SlotTmp slot;
        fn_004ea720(slot.buf, 0, (int)&b);
        ConnTmp c;
        fn_004a3340((void*)g_00973c38, 0, (int)c.buf, instSub(arg2), (int)slot.buf, 10);
        fn_00595540(&self->conn[2], 0, c.buf);
    }
    {
        Bound b; b.fn = (int)(void*)&fn_004e5f10; b.self = self;
        SlotTmp slot;
        fn_004ea7c0(slot.buf, 0, (int)&b);
        ConnTmp c;
        fn_0042b680((void*)g_00973f48, 0, (int)c.buf, instSub(arg2), (int)slot.buf, 10);
        fn_00595540(&self->conn[3], 0, c.buf);
    }

    if (arg2->p)
        fn_004e7ed0(arg2->p, 0, (int)(void*)&fn_004ea5e0, self);

    return self;
}
