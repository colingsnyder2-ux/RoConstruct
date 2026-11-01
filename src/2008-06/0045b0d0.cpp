// from server: 100% by colin
struct Window {
    char padding0[32];
    void* handle;
    char padding1[212];
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
