// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>
#include <math.h>

// INFERRED: opaque layouts; only offsets used by the disassembly are modelled.
struct RenderSettingsLike {
    char pad0[0x144];
    float minA;   // 0x144
    float maxA;   // 0x148
    float minB;   // 0x14c
    float maxB;   // 0x150
};

struct ViewIface {   // object at self+0xb0 (vtable only)
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual float getA() = 0;                          // +8
    virtual float getB() = 0;                          // +0xc
    virtual void set(float a, float b, bool f, float c) = 0; // +0x10
};

struct CameraHolder {
    char pad[0x288];
    void* camProvider;    // 0x288 (vtable pointer of embedded iface)
};

struct WorkspaceLike {
    char pad[0x204];
    CameraHolder* holder; // 0x204
};

struct ViewSelf {
    char pad0[0x5c];
    int mode;              // 0x5c
    char pad1[0x70 - 0x60];
    WorkspaceLike* ws;     // 0x70
    void* wsCount;         // 0x74
    char pad2[0x90 - 0x78];
    double pending;        // 0x90
    char pad3[0xb0 - 0x98];
    ViewIface* view;       // 0xb0
};

struct DMLock { char data[8]; };
struct Vec3 { float x, y, z; };

extern CRITICAL_SECTION g_viewCs;       // 0x96df6c
extern const double kPendingIdle;       // 0x8199d0
extern bool g_flag;                     // 0x96de64
extern void* g_ogreRoot;                // 0x97db48

extern "C" void __fastcall fn_00411b40(DMLock* lock, int unusedEdx, void* sp0, void* sp1);
extern "C" RenderSettingsLike& fn_00412d50();
extern "C" void* __fastcall fn_0045af00(void* camera, int unusedEdx);
extern "C" Vec3* __fastcall fn_0045ac40(Vec3* out, int unusedEdx, Vec3* a, Vec3* b);
extern "C" void __fastcall fn_005773c0(DMLock* lock, int unusedEdx);

extern "C" void __fastcall fn_0045c890(ViewSelf* self, int unusedEdx)
{
    EnterCriticalSection(&g_viewCs);
    if (self->pending == kPendingIdle) {
        LeaveCriticalSection(&g_viewCs);
        return;
    }
    double dt = self->pending;
    self->pending = kPendingIdle;
    LeaveCriticalSection(&g_viewCs);

    if (self->view && self->ws) {
        DMLock lock;
        fn_00411b40(&lock, 0, self->ws, self->wsCount);

        float a = self->view->getA();
        float b = self->view->getB();
        // INFERRED: scale a/b by dt-dependent factors (constants at 0x819b38..0x819b50)
        if (dt > 0.0) {
            a *= 1.0f; b *= 1.0f;
        }

        RenderSettingsLike& rs = fn_00412d50();
        a = rs.maxA < a ? rs.maxA : a;
        a = rs.minA > a ? rs.minA : a;
        b = rs.maxB < b ? rs.maxB : b;
        b = rs.minB > b ? rs.minB : b;

        if (self->ws->holder) {
            Vec3 d = { 0, 0, 0 };
            float len = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
            if ((self->mode == 4 || self->mode == 3) && g_ogreRoot) {
                g_flag = false;
            }
            self->view->set(a, b, g_flag, len);
        }
        fn_005773c0(&lock, 0);
    }
}
