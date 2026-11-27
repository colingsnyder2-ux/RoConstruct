// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern unsigned char g_assertEnabled;
extern bool (__cdecl *g_assertHandler)(const char*, const char*, int);
void __cdecl assertFail(int, const char*);
struct Inner { int a; int b; int value; };
struct CRobloxTreeCtrl {
    char pad[0x84];
    Inner* object;
    void f(int* out);
};
void CRobloxTreeCtrl::f(int* out) {
    if (g_assertEnabled && !object) {
        if (!g_assertHandler || !g_assertHandler("object.get() != 0", "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\util/utilities.h", 0x3d))
            assertFail(g_assertEnabled, "object.get() != 0 file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\util/utilities.h line: 61");
    }
    *out = object->value;
}
