// from server: 90% by atomic.potato
typedef unsigned long DWORD;
typedef int BOOL;
typedef void* HWND;
typedef unsigned int UINT;
typedef unsigned int WPARAM;
typedef long LPARAM;

extern "C" BOOL __stdcall PostMessageA(HWND, UINT, WPARAM, LPARAM);

struct InsertModelFromRobloxVerb {
    char pad[12];
    struct State {
        char pad[32];
        HWND window;
    };
    State* state;
    void f();
};

void InsertModelFromRobloxVerb::f()
{
    PostMessageA(state->window, 0x111, 0x80fe, 0);
}
