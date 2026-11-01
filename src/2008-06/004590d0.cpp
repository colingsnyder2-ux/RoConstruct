// from server: 100% by king_originala
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
