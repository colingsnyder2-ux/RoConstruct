// from server: 100% by EspClaude
// roc-flags: /O2 /Ob0 /GS /MD /EHsc
// from server: 55% by colin
// roc 2007-08 00438430  unit: CStandardOutputView  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00438430
//
// 00438430  6aff                 push -1
// 00438432  6848e67300           push 0x73e648
// 00438437  64a100000000         mov eax, dword ptr fs:[0]
// 0043843d  50                   push eax
// 0043843e  56                   push esi
// 0043843f  a188518b00           mov eax, dword ptr [0x8b5188]
// 00438444  33c4                 xor eax, esp
// 00438446  50                   push eax
// 00438447  8d442408             lea eax, [esp + 8]
// 0043844b  64a300000000         mov dword ptr fs:[0], eax
// 00438451  8bf1                 mov esi, ecx
// 00438453  8b442440             mov eax, dword ptr [esp + 0x40]
// 00438457  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0043845b  50                   push eax
// 0043845c  51                   push ecx
// 0043845d  8d4c2428             lea ecx, [esp + 0x28]
// 00438461  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00438469  ff15a8e67700         call dword ptr [0x77e6a8]
// 0043846f  8b542424             mov edx, dword ptr [esp + 0x24]
// 00438473  50                   push eax
// 00438474  52                   push edx
// 00438475  8d8ef0feffff         lea ecx, [esi - 0x110]
// 0043847b  e820fdffff           call 0x4381a0
// 00438480  8d4c2420             lea ecx, [esp + 0x20]
// 00438484  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0043848c  ff15ace67700         call dword ptr [0x77e6ac]
// 00438492  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00438496  64890d00000000       mov dword ptr fs:[0], ecx
// 0043849d  59                   pop ecx
// 0043849e  5e                   pop esi
// 0043849f  83c40c               add esp, 0xc
// 004384a2  c22c00               ret 0x2c
#include <string>

// Primary base occupies 0x110 bytes: the target calls the sibling method with
// ecx = this - 0x110 (lea ecx, [esi - 0x110]).
struct OutputBase0 {
    virtual void v0();
    int pad[0x43];
};

struct OutputBase1 {
    virtual void output(int a0, int a1, std::string s, int a3, int a4) = 0;
};

struct CStandardOutputView : OutputBase0, OutputBase1 {
    void append(int a1, const char* text, int a3, int a4);   // 0x4381a0, ret 0x10
    virtual void output(int a0, int a1, std::string s, int a3, int a4);
};

void CStandardOutputView::output(int a0, int a1, std::string s, int a3, int a4)
{
    append(a1, s.c_str(), a3, a4);
}
