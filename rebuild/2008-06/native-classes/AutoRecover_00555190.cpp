// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <intrin.h>

namespace G3D { struct Stopwatch { void tick(); void tock(); }; }
namespace RBX { double getRealTime(); }

// INFERRED: boost-style sp_counted_base: use count at +4, weak at +8, vtable[1]=dispose, [2]=destroy
struct SpCounted {
    virtual void d0();
    virtual void dispose();
    virtual void destroy();
    volatile long use;
    volatile long weak;
};
struct SpArg { void* p; SpCounted* c; };

extern "C" int __fastcall fn_00554880(void* self, int unusedEdx, SpArg a);
extern "C" int __fastcall fn_00554ed0(void* self, int unusedEdx);
extern "C" int __fastcall fn_005550a0(void* self, int unusedEdx, double a);
extern "C" int __fastcall fn_00554e10(void* self, int unusedEdx, double a);

extern bool g_useLastTime; // 0x946790
extern const double g_scale; // 0x81e738

// INFERRED: unnamed class, thiscall, one by-value shared_ptr argument
struct Runner {
    char pad0[0x1c0];
    float lastTime;
    char pad1[0x1d8 - 0x1c4];
    double prevAccum;
    double curAccum;
    G3D::Stopwatch watch;
    char pad2[0x248 - 0x1e8 - 1];
    bool stop;
    void run(SpArg arg);
};

void Runner::run(SpArg arg)
{
    double accum = 0.0;
    for (;;) {
        double t = RBX::getRealTime();
        if (g_useLastTime) {
            double x = RBX::getRealTime() - lastTime;
            t = lastTime + (x < t ? t : x);
        } else {
            t = RBX::getRealTime();
        }
        if (stop)
            break;
        if (arg.c)
            _InterlockedExchangeAdd(&arg.c->use, 1);
        fn_00554880(this, 0, arg);
        if (stop)
            break;
        fn_00554ed0(this, 0);
        if (stop)
            break;
        accum = (t - RBX::getRealTime() + accum) * g_scale;
        fn_005550a0(this, 0, accum);
        if (accum > 0.0)
            fn_00554e10(this, 0, accum);
        if (stop)
            break;
        watch.tock();
        watch.tick();
        prevAccum = curAccum;
        curAccum = 0.0;
    }
    if (arg.c && _InterlockedExchangeAdd(&arg.c->use, -1) == 1) {
        arg.c->dispose();
        if (_InterlockedExchangeAdd(&arg.c->weak, -1) == 1)
            arg.c->destroy();
    }
}
