// from server: 100% by Xemicl
// roc 2012-06 00492850  unit: LockPlayModeVerb  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00492850
//
// 00492850  e87dfb4e00           call 0x9823d2
// 00492855  8b4004               mov eax, dword ptr [eax + 4]
// 00492858  8b4020               mov eax, dword ptr [eax + 0x20]
// 0049285b  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0049285e  6a00                 push 0
// 00492860  68ff800000           push 0x80ff
// 00492865  6811010000           push 0x111
// 0049286a  51                   push ecx
// 0049286b  ff15243cb200         call dword ptr [0xb23c24]
// 00492871  c20400               ret 4
// copied from an identical function in another client (function ?f@ToggleFullscreenVerb@ns_ROCX00001a@@QAEHPAX@Z)

namespace ns_ROCX00001a {
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
    return PostMessageA(w->h, 0x111, 0x80ff, 0);
}
}