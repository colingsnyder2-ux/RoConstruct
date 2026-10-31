// from server: 100% by EspClaude
// roc 2009-06 00457b20  unit: LockPlayModeVerb  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00457b20
//
// 00457b20  e8d1112c00           call 0x718cf6
// 00457b25  8b4004               mov eax, dword ptr [eax + 4]
// 00457b28  8b4020               mov eax, dword ptr [eax + 0x20]
// 00457b2b  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00457b2e  6a00                 push 0
// 00457b30  68ff800000           push 0x80ff
// 00457b35  6811010000           push 0x111
// 00457b3a  51                   push ecx
// 00457b3b  ff159cee8900         call dword ptr [0x89ee9c]
// 00457b41  c20400               ret 4
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
