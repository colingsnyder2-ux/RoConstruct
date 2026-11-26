// from server: 100% by Xemicl
// from server: 100% by tester
// roc 2012-06 007fac60  unit: RBX::VInsertService::?$FactoryProduct  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007fac60
//
// 007fac60  6870ab7f00           push 0x7fab70
// 007fac65  68c4f4e400           push 0xe4f4c4
// 007fac6a  e83169c0ff           call 0x4015a0
// 007fac6f  b801000000           mov eax, 1
// 007fac74  83c408               add esp, 8
// 007fac77  8405a4f4e400         test byte ptr [0xe4f4a4], al
// 007fac7d  751f                 jne 0x7fac9e
// 007fac7f  0905a4f4e400         or dword ptr [0xe4f4a4], eax
// 007fac85  33c0                 xor eax, eax
// 007fac87  68e0dbb100           push 0xb1dbe0
// 007fac8c  a39cf4e400           mov dword ptr [0xe4f49c], eax
// 007fac91  a3a0f4e400           mov dword ptr [0xe4f4a0], eax
// 007fac96  e85a851800           call 0x9831f5
// 007fac9b  83c404               add esp, 4
// 007fac9e  b89cf4e400           mov eax, 0xe4f49c
// 007faca3  c3                   ret 

extern "C" void __cdecl sub_4015A0(void*, void*);
extern "C" void __cdecl sub_9831F5(void*);

extern unsigned char byte_E4F4A4;
extern unsigned int dword_E4F4A4;
extern unsigned int dword_E4F49C;
extern unsigned int dword_E4F4A0;

struct S {
    unsigned int* f();
};

unsigned int* S::f()
{
    sub_4015A0((void*)0x7FAB70, (void*)0xE4F4C4);
    if ((byte_E4F4A4 & 1) == 0) {
        dword_E4F4A4 |= 1;
        dword_E4F49C = 0;
        dword_E4F4A0 = 0;
        sub_9831F5((void*)0xB1DBE0);
    }
    return &dword_E4F49C;
}
