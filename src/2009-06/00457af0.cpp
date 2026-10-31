// from server: 100% by EspClaude
// roc 2009-06 00457af0  unit: ToggleIDEModeVerb  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00457af0
//
// 00457af0  8b01                 mov eax, dword ptr [ecx]
// 00457af2  8b5008               mov edx, dword ptr [eax + 8]
// 00457af5  ffd2                 call edx
// 00457af7  84c0                 test al, al
// 00457af9  7421                 je 0x457b1c
// 00457afb  e8f6112c00           call 0x718cf6
// 00457b00  8b4004               mov eax, dword ptr [eax + 4]
// 00457b03  8b4020               mov eax, dword ptr [eax + 0x20]
// 00457b06  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00457b09  6a00                 push 0
// 00457b0b  68f5800000           push 0x80f5
// 00457b10  6811010000           push 0x111
// 00457b15  51                   push ecx
// 00457b16  ff159cee8900         call dword ptr [0x89ee9c]
// 00457b1c  c20400               ret 4
// copied from an identical function in another client (function ?toggle@ToggleIDEModeVerb@@QAEXH@Z)

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