// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <intrin.h>

// INFERRED: boost-style sp_counted_base layout (vptr, use_count @+4, weak_count @+8)
struct SpCountedBase {
    virtual void dispose() = 0;   // vtable slot 1 (+4)
    virtual void destroy() = 0;   // vtable slot 2 (+8)
    volatile long use_count;
    volatile long weak_count;
};

// INFERRED: by-value shared_ptr-like parameter (px, pn); released by the callee
struct SpArg {
    void* px;
    SpCountedBase* pn;
    ~SpArg()
    {
        if (pn) {
            if (_InterlockedDecrement(&pn->use_count) == 0) {
                pn->dispose();
                if (_InterlockedDecrement(&pn->weak_count) == 0)
                    pn->destroy();
            }
        }
    }
};

namespace RBX { double getRealTime(); }

namespace G3D {
class Stopwatch {
    double data[12];   // 0x60 bytes
public:
    void tick();
    void tock();
};
}

extern bool g_flag_00946790;

extern "C" int __fastcall fn_00554880(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_00554ed0(void* self, int unusedEdx);
extern "C" int __fastcall fn_005550a0(void* self, int unusedEdx, double a1);
extern "C" int __fastcall fn_00554e10(void* self, int unusedEdx, double a1);

struct Obj_00555190 {
    char pad0[0x1c0];
    float f1c0;
    char pad1[0x1d8 - 0x1c4];
    double d1d8;
    double d1e0;
    G3D::Stopwatch watch;      // 0x1e8, size 0x60 -> next member at 0x248
    bool stop;                 // 0x248
};

extern "C" void __fastcall fn_00555190(Obj_00555190* self, int unusedEdx, SpArg arg)
{
    const double kScale = 0.5; // INFERRED: constant at 0x81e738 (value unknown)
    double a = 0.0;
    double t = RBX::getRealTime();

    for (;;) {
        if (g_flag_00946790) {
            double r = RBX::getRealTime() - self->f1c0;
            const double* p = (r > t) ? &r : &t;
            t = (double)self->f1c0 + *p;
        } else {
            t = RBX::getRealTime();
        }

        if (self->stop)
            break;

        if (arg.pn)
            _InterlockedIncrement(&arg.pn->use_count);
        fn_00554880(self, 0, (int)arg.px, (int)arg.pn);
        if (self->stop)
            break;

        fn_00554ed0(self, 0);
        if (self->stop)
            break;

        a = ((t - RBX::getRealTime()) + a) * kScale;
        fn_005550a0(self, 0, a);

        if (a > 0.0)
            fn_00554e10(self, 0, a);

        if (self->stop)
            break;

        self->watch.tock();
        self->watch.tick();
        self->d1d8 = self->d1e0;
        self->d1e0 = 0.0;
    }
}
