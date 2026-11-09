// from server: 100% by EspClaude
// roc 2009-06 0044da10  unit: ReportAbuseVerb  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044da10
//
// 0044da10  e8e1b22c00           call 0x718cf6
// 0044da15  8b4004               mov eax, dword ptr [eax + 4]
// 0044da18  8b4020               mov eax, dword ptr [eax + 0x20]
// 0044da1b  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0044da1e  6a00                 push 0
// 0044da20  6800810000           push 0x8100
// 0044da25  6811010000           push 0x111
// 0044da2a  51                   push ecx
// 0044da2b  ff159cee8900         call dword ptr [0x89ee9c]
// 0044da31  c20400               ret 4
// copied from an identical function in another client (function ?f@ToggleFullscreenVerb@@QAEHPAX@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef void* HWND;
typedef int BOOL;

struct W { char p[0x20]; HWND h; };
struct V { char p[0x20]; W* w; };
struct U { char p[4]; V* v; };
extern "C" U* __cdecl sub_6A0926();
extern "C" __declspec(dllimport) BOOL __stdcall PostMessageA(HWND, unsigned int, unsigned int, long);

struct ToggleFullscreenVerb
{
    BOOL f(void*);
};

BOOL ToggleFullscreenVerb::f(void*)
{
    W* w = sub_6A0926()->v->w;
    return PostMessageA(w->h, 0x111, 0x8100, 0);
}