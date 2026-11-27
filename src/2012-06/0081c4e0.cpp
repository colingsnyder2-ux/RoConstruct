// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern unsigned char g_flag;
extern char (__cdecl *g_handler)(const char*, const char*, int);
void __cdecl failAssert(unsigned char, const char*);
struct Iface { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(int a); };
struct S { char pad[0x28]; bool inStep; char pad2[0x68 - 0x29]; int count; char pad3[0xac - 0x6c]; Iface* target; void f(int a); };
void S::f(int a)
{
    if (g_flag) {
        if (inStep) {
            if (!g_handler || !g_handler("!inStepCode", "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\V8World\\World.cpp", 0x290))
                failAssert(g_flag, "!inStepCode file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\V8World\\World.cpp line: 656");
        }
    }
    target->v3(a);
    ++count;
}
