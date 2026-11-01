// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 0045b0d0  unit: CRobloxWnd  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045b0d0
//
// 0045b0d0  e851582400           call 0x6a0926
// 0045b0d5  8b4004               mov eax, dword ptr [eax + 4]
// 0045b0d8  8b4020               mov eax, dword ptr [eax + 0x20]
// 0045b0db  80b8f800000000       cmp byte ptr [eax + 0xf8], 0
// 0045b0e2  7416                 je 0x45b0fa
// 0045b0e4  8b4020               mov eax, dword ptr [eax + 0x20]
// 0045b0e7  6a00                 push 0
// 0045b0e9  68f4800000           push 0x80f4
// 0045b0ee  6811010000           push 0x111
// 0045b0f3  50                   push eax
// 0045b0f4  ff150c2e8000         call dword ptr [0x802e0c]
// 0045b0fa  c3                   ret 

struct Window {
    char padding0[32];
    void* handle;
    char padding1[216];
    unsigned char enabled;
};
struct State {
    char padding[32];
    Window* window;
};
struct Context {
    char padding[4];
    State* state;
};
extern Context* __cdecl getContext();
extern "C" __declspec(dllimport) int __stdcall PostMessageA(void*, unsigned int, unsigned int, long);
void func_0045b0d0()
{
    State* s = getContext()->state;
    if (s->window->enabled)
        PostMessageA(s->window->handle, 0x111, 0x80f4, 0);
}
