// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern bool g_assertsOn;
extern bool (__cdecl *g_assertHook)(const char*, const char*, int);
extern void __cdecl logMsg(int, const char*);
struct Sub { void go(int); };
struct K { char pad[0x10]; bool inStep; char pad2[3]; Sub* sub; void f(int a); };
void K::f(int a) {
  if (g_assertsOn && inStep) {
    if (!g_assertHook || !g_assertHook("!inStepCode", "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\V8Kernel\\Kernel.cpp", 133))
      logMsg(g_assertsOn, "!inStepCode file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\V8Kernel\\Kernel.cpp line: 133");
  }
  ((Sub*)((char*)sub + 0x40))->go(a);
}