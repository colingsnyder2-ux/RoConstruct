// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD /Oy- /hotpatch
typedef int (__stdcall *Fn)(int);
extern "C" int __cdecl check_820471();
extern "C" int __stdcall impl_82097c(int);
extern "C" int __stdcall impl_820766(int);
extern "C" int __stdcall impl_820890(int);
extern Fn g_a3183c;
extern Fn g_a31840;
extern "C" int __stdcall dispatch_820ad0(int a)
{
    if (check_820471()) {
        g_a3183c = impl_82097c;
        g_a31840 = impl_82097c;
    } else {
        g_a3183c = impl_820766;
        g_a31840 = impl_820890;
    }
    return g_a31840(a);
}
