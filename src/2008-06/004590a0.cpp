// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) int __stdcall PostMessageA(void*, unsigned int, unsigned int, int);
extern "C" void* __cdecl sub_6A0926();

struct Chain1 {
    char pad[4];
    struct Chain2* f4;
};

struct Chain2 {
    char pad[0x20];
    struct Chain3* f20;
};

struct Chain3 {
    char pad[0x20];
    void* hwnd;
};

struct ToggleIDEModeVerb {
    virtual void pad1();
    virtual void pad2();
    virtual bool check();
    void toggle(int);
};

void ToggleIDEModeVerb::toggle(int arg) {
    if (this->check()) {
        Chain3* c = ((Chain1*)sub_6A0926())->f4->f20;
        PostMessageA(c->hwnd, 0x111, 0x80f5, 0);
    }
}
