// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class headers were available, so the object is accessed by raw offsets
// and the callees are declared as fn_ externs.

struct Adorn;

struct IAdornSink {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void render(Adorn* a); // vtable slot 3
};

extern "C" void* __fastcall fn_004b34c0(void* self, int unusedEdx);                 // ServiceProvider::find<JointsService>
extern "C" void  __fastcall fn_005dd360(void* self, int unusedEdx, Adorn* a);       // IRenderableBucket::render3dAdornItems
extern "C" int   __fastcall fn_00578c20(void* self, int unusedEdx, int a1);
extern "C" int   __fastcall fn_00608890(void* self, int unusedEdx, int a1);
extern "C" void  __cdecl    fn_00507d20(void* p);                                   // G3D::System::alignedFree

extern bool g_flag_00974e61; // INFERRED: global flags
extern bool g_flag_00974e62;

// INFERRED: G3D-array-like local with a destructor that frees its buffer
struct LocalArray {
    void* data;
    int   size;
    int   alloc;
    bool  b0;
    bool  b1;
    LocalArray() : data(0), size(0), alloc(0), b0(false), b1(true) {}
    ~LocalArray() { fn_00507d20(data); }
};

struct RenderSelf;

extern "C" void __fastcall fn_0057a6c0(RenderSelf* self, int unusedEdx, Adorn* adorn)
{
    char* base = reinterpret_cast<char*>(self);
    if (*(bool*)(base + 0x259)) {
        ++*(int*)(base + 0x250);
        if (adorn) {
            char* p204 = *(char**)(base + 0x204);
            IAdornSink* sink = (IAdornSink*)(p204 + 0x1a0);
            sink->render(adorn);

            void* joints = fn_004b34c0(self, 0);
            if (joints)
                fn_005dd360((char*)joints + 0x138, 0, adorn);

            if (!*(bool*)(base + 0x230)) {
                char* o = *(char**)(*(char**)(base + 0x204) + 0x3b0);
                IAdornSink* s2 = (IAdornSink*)(o + 4);
                s2->render(adorn);
            }

            if (g_flag_00974e61 && g_flag_00974e62) {
                LocalArray arr;
                fn_00578c20(self, 0, (int)&arr);
                fn_00608890(&arr, 0, (int)adorn);
            }
        }
    }
}
