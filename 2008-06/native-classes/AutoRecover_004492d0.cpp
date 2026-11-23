// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

extern "C" int __fastcall fn_004490c0(void* self, int unusedEdx, float a1);
extern "C" int __fastcall fn_00449060(void* self, int unusedEdx, float a1);
extern "C" int __fastcall fn_00448fd0(void* self, int unusedEdx, float a1);
extern "C" int __fastcall fn_00448f40(void* self, int unusedEdx, float a1);

// INFERRED: globals at fixed addresses
extern const char* g_defaultString;   // 0x9317fc
extern const float g_floatConst;      // 0x8163a4

// INFERRED: interface object with virtual at slot 3 (+0xc)
struct IDispatcher {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(void* obj, const std::string& s);
};
extern IDispatcher* g_dispatcher;     // 0x96d52c

extern "C" void __fastcall fn_004492d0(void* self, int unusedEdx, bool force)
{
    if (!force) {
        const std::string& cur = *reinterpret_cast<std::string*>(reinterpret_cast<char*>(self) + 0x158);
        if (!(cur != g_defaultString))
            return;
    }

    fn_004490c0(self, 0, g_floatConst);
    fn_00449060(self, 0, g_floatConst);
    fn_004490c0(self, 0, g_floatConst);
    fn_00448fd0(self, 0, g_floatConst);
    fn_00448f40(self, 0, g_floatConst);
    fn_00448fd0(self, 0, g_floatConst);

    std::string s(g_defaultString);
    void* sub = self ? reinterpret_cast<char*>(self) + 0x14 : 0;
    g_dispatcher->slot3(sub, s);
}
