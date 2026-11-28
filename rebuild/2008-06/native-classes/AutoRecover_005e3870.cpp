// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no native headers were shown, so the types below are local stand-ins.
// INFERRED: the [vtbl+4] / [vtbl+8] calls and the +4/+8 counters match a boost 1.33 style
// sp_counted_base (vptr, use_count, weak_count). The array members are weak_ptr<PartInstance>
// (weak_count add/release on assignment from a temporary shared_ptr).
#include <intrin.h>

namespace boost {

struct sp_counted_base {
    virtual void slot0() = 0;      // dtor slot
    virtual void dispose() = 0;    // [vtbl+4]
    virtual void destroy() = 0;    // [vtbl+8]
    long use_count_;               // +4
    long weak_count_;              // +8

    void weak_add_ref() { _InterlockedExchangeAdd(&weak_count_, 1); }
    void weak_release() {
        if (_InterlockedExchangeAdd(&weak_count_, -1) == 1) destroy();
    }
    void release() {
        if (_InterlockedExchangeAdd(&use_count_, -1) == 1) {
            dispose();
            weak_release();
        }
    }
};

template<class T> class shared_ptr {
public:
    T* px;
    sp_counted_base* pi;
    ~shared_ptr() { if (pi) pi->release(); }
};

template<class T> class weak_ptr {
public:
    T* px;
    sp_counted_base* pi;
    __declspec(noinline) weak_ptr() : px(0), pi(0) {}
    __declspec(noinline) ~weak_ptr() { if (pi) pi->weak_release(); }
    weak_ptr& operator=(shared_ptr<T> const& r) {
        px = r.px;
        sp_counted_base* t = r.pi;
        if (t) t->weak_add_ref();
        if (pi) pi->weak_release();
        pi = t;
        return *this;
    }
};

} // namespace boost

namespace RBX {
    class Primitive;
    class PartInstance {
    public:
        static PartInstance* fromPrimitive(Primitive* p);
    };
    template<class T> boost::shared_ptr<T> shared_from(T* p);
}

// INFERRED: the argument holds two Primitive* at +0xc and +0x10.
struct JointArg {
    char pad[0xc];
    RBX::Primitive* prim0;
    RBX::Primitive* prim1;
};

extern "C" char g_0083e354[];
extern "C" char g_0083e344[];
extern "C" char g_0083e33c[];
extern "C" char g_0083e334[];
extern "C" char g_0083e324[];
extern "C" char g_0083e314[];
extern "C" char g_0083e304[];
extern "C" char g_0083e2f4[];
extern "C" char g_0083e2e4[];
extern "C" char g_0083e2d4[];
extern "C" char g_0083e2bc[];

extern "C" int __fastcall fn_006454a0(void* self, int unusedEdx, int a1);

// INFERRED: DescribedCreatable<Script,Instance,sScript> base (size 0x134), ctor is fn_005e37d0.
struct ScriptBase {
    char pad[0x134];
    ScriptBase();
    __declspec(noinline) ~ScriptBase() {}
};
#pragma comment(linker, "/alternatename:??0ScriptBase@@QAE@XZ=@fn_005e37d0@4")

static __forceinline void setVt(char* p, int off, const void* v)
{
    *(const void**)(p + off) = v;
}

static __forceinline int initVtables(char* p)
{
    setVt(p, 0x00, g_0083e354);
    setVt(p, 0x10, g_0083e344);
    setVt(p, 0x14, g_0083e33c);
    setVt(p, 0x20, g_0083e334);
    setVt(p, 0x24, g_0083e324);
    setVt(p, 0x44, g_0083e314);
    setVt(p, 0x64, g_0083e304);
    setVt(p, 0x84, g_0083e2f4);
    setVt(p, 0xa4, g_0083e2e4);
    setVt(p, 0xc4, g_0083e2d4);
    setVt(p, 0x130, g_0083e2bc);
    return 0;
}

struct JointInstance : ScriptBase {
    int f134;
    int f138;
    int f13c;
    boost::weak_ptr<RBX::PartInstance> parts[2]; // 0x140, 0x148
    JointArg* link;                              // 0x150

    static void* operator new(unsigned int, void* p) { return p; }

    __forceinline JointInstance(JointArg* arg)
        : f134(-1), f138(-1), f13c(initVtables((char*)this)), link(arg)
    {
        fn_006454a0((void*)arg, 0, (int)&parts[0]);

        RBX::PartInstance* p0 = RBX::PartInstance::fromPrimitive(arg->prim0);
        RBX::PartInstance* p1 = RBX::PartInstance::fromPrimitive(arg->prim1);

        parts[0] = RBX::shared_from<RBX::PartInstance>(p0);
        parts[1] = RBX::shared_from<RBX::PartInstance>(p1);
    }
};

extern "C" JointInstance* __fastcall fn_005e3870(JointInstance* self, int unusedEdx, JointArg* arg)
{
    return new (self) JointInstance(arg);
}
