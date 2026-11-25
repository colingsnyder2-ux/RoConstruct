// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no headers were available, so the Lighting-like object is a local struct
// with padding to reproduce the member offsets used by the original code.

struct LightingLike {
    char pad0[0x14];
    char signalSource[0x130 - 0x14];    // this+0x14 (SignalSource)
    char lightingParams[0x268 - 0x130]; // this+0x130 (G3D::LightingParameters)
    long long timeMicro;                // this+0x268
};

// INFERRED: by-value one-dword structs are passed on the stack under __fastcall, which
// reproduces the thiscall callees (only ecx set, no edx) without a dummy edx argument.
struct StackPtr { void* p; };
struct StackInt { int v; };

extern char g_0097a91c[]; // property descriptor
extern char g_0097a88c[]; // signal descriptor

extern "C" void __fastcall fn_007b59b0(void* self, double t);                      // LightingParameters::setTime
extern "C" void __fastcall fn_0040db00(void* self, StackPtr desc);                 // Instance::raisePropertyChanged
extern "C" void* __fastcall fn_0056b620(void* self, StackPtr src);                 // SignalDescriptor::findSignalInstance
extern "C" void __fastcall fn_005e1f00(void* self, StackPtr arg, StackInt zero);   // signal1::operator()
extern "C" int fn_004651c0(int a1);
extern "C" void __fastcall fn_00555350(void* self);                                // RunService::invalidateRunViews

extern "C" void __fastcall fn_005e2570(LightingLike* self, int unusedEdx, const long long* arg)
{
    int secs = (int)(*arg / 1000000);
    secs = secs % 86400;

    if ((int)(self->timeMicro / 1000000) == secs)
        return;

    long long v;
    if (secs < 0)
        v = (long long)(-secs) * -1000000LL;
    else
        v = (long long)secs * 1000000LL;
    self->timeMicro = v;

    int t = (int)(v / 1000000);
    fn_007b59b0(self->lightingParams, (double)t);
    StackPtr d = { g_0097a91c };
    fn_0040db00(self, d);

    StackPtr s = { self->signalSource };
    void* sig = fn_0056b620(g_0097a88c, s);
    if (sig) {
        StackPtr a = { &t };
        StackInt z = { 0 };
        fn_005e1f00((char*)sig + 0x10, a, z);
    }

    int rs = fn_004651c0((int)self);
    if (rs) {
        fn_00555350((void*)rs);
    }
}
