// from server: 100% by intel
// from server: 99% by atomic.potato
// roc 2012-06 0042c1b0  unit: CSelectionTreeCtrl  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0042c1b0
//
// 0042c1b0  803db380e50000       cmp byte ptr [0xe580b3], 0
// 0042c1b7  7442                 je 0x42c1fb
// 0042c1b9  813db082e1009a020000 cmp dword ptr [0xe182b0], 0x29a
// 0042c1c3  7436                 je 0x42c1fb
// 0042c1c5  a19c80e500           mov eax, dword ptr [0xe5809c]
// 0042c1ca  85c0                 test eax, eax
// 0042c1cc  7418                 je 0x42c1e6
// 0042c1ce  68cf000000           push 0xcf
// 0042c1d3  68a82fb400           push 0xb42fa8
// 0042c1d8  68902fb400           push 0xb42f90
// 0042c1dd  ffd0                 call eax
// 0042c1df  83c40c               add esp, 0xc
// 0042c1e2  84c0                 test al, al
// 0042c1e4  7515                 jne 0x42c1fb
// 0042c1e6  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 0042c1ed  68202fb400           push 0xb42f20
// 0042c1f2  50                   push eax
// 0042c1f3  e898605400           call 0x972290
// 0042c1f8  83c408               add esp, 8
// 0042c1fb  833dbc32ba0000       cmp dword ptr [0xba32bc], 0
// 0042c202  7505                 jne 0x42c209
// 0042c204  e977322500           jmp 0x67f480
// 0042c209  6870b24200           push 0x42b270
// 0042c20e  68e082e100           push 0xe182e0
// 0042c213  e88853fdff           call 0x4015a0
// 0042c218  83c408               add esp, 8
// 0042c21b  e920eaffff           jmp 0x42ac40

// Use absolute addresses directly to match target codegen
#define ADDR_e580b3  0x00e580b3
#define ADDR_e182b0  0x00e182b0
#define ADDR_e5809c  0x00e5809c
#define ADDR_ba32bc  0x00ba32bc
#define ADDR_e182e0  0x00e182e0
#define ADDR_b42f20  0x00b42f20
#define ADDR_b42f90  0x00b42f90
#define ADDR_b42fa8  0x00b42fa8
#define ADDR_972290  0x00972290
#define ADDR_4015a0  0x004015a0
#define ADDR_67f480  0x0067f480
#define ADDR_42ac40  0x0042ac40
#define ADDR_42b270  0x0042b270

extern "C" {
    void __cdecl sub_972290(unsigned int, void*);
    void __cdecl sub_4015a0(void*, void*);
    void __cdecl sub_67f480();
    void __cdecl sub_42ac40();
    void __cdecl sub_42b270();
}

void __cdecl func_42c1b0()
{
    if (*(unsigned char*)ADDR_e580b3 != 0 && *(unsigned int*)ADDR_e182b0 != 0x29a) {
        int (__cdecl *fn)(int, int, int) = *(int (__cdecl **)(int, int, int))ADDR_e5809c;
        if (fn != 0) {
            // Match target: test al, al after call
            if ((unsigned char)fn((int)ADDR_b42f90, (int)ADDR_b42fa8, 0xcf) != 0)
                goto L_42c1fb;
        }
        sub_972290(*(unsigned char*)ADDR_e580b3, (void*)ADDR_b42f20);
    }
L_42c1fb:
    if (*(unsigned int*)ADDR_ba32bc == 0) {
        sub_67f480();
        return;
    }
    sub_4015a0((void*)ADDR_e182e0, (void*)ADDR_42b270);
    sub_42ac40();
}