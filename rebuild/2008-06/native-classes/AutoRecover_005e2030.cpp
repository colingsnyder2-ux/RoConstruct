// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header is available, so the object is modelled as a
// struct with a first base of 0x14 bytes, a SignalSource sub-object at 0x14,
// and four floats at 0x254..0x260.
struct BaseA {
    int pad[5];
};
struct SignalSource {
    int x;
};
struct Self : BaseA, SignalSource {
    char pad1[0x254 - 0x18];
    float v0;
    float v1;
    float v2;
    float v3;
};

// INFERRED: unknown globals (a PropertyDescriptor and a SignalDescriptor), declared by address.
extern "C" char g_0097aa58[];
extern "C" char g_0097a88c[];

// INFERRED: callees are __thiscall in the original code; modelled as __fastcall with dummy edx.
extern "C" void __fastcall fn_0040db00(Self* self, int unusedEdx, void* propertyDescriptor);       // Instance::raisePropertyChanged
extern "C" void* __fastcall fn_0056b620(void* sigDesc, int unusedEdx, SignalSource* signalSource); // SignalDescriptor::findSignalInstance
extern "C" void __fastcall fn_005e1f00(void* sig, int unusedEdx, bool* arg, int extra);            // signal1<void,bool>::operator()
extern "C" int fn_004651c0(int a1);
extern "C" void __fastcall fn_00555350(int runService, int unusedEdx);                             // RunService::invalidateRunViews

extern "C" void __fastcall fn_005e2030(Self* self, int unusedEdx, float a, float b, float c, float d)
{
    if (self->v0 != a || self->v1 != b || self->v2 != c || self->v3 != d) {
        self->v0 = a;
        self->v1 = b;
        self->v2 = c;
        self->v3 = d;

        fn_0040db00(self, 0, g_0097aa58);

        SignalSource* src = self;
        void* sig = fn_0056b620(g_0097a88c, 0, src);
        if (sig) {
            // INFERRED: the disassembly passes the address of an uninitialised bool local.
            bool flag;
            fn_005e1f00((char*)sig + 0x10, 0, &flag, 0);
        }

        int rs = fn_004651c0((int)self);
        if (rs)
            fn_00555350(rs, 0);
    }
}
