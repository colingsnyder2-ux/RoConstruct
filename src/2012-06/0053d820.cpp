// from server: 100% by Xemicl
// from server: 100% by atomic.potato
// roc 2012-06 0055fa70  unit: RBX::VHint::?$FactoryProduct  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0055fa70
//
// 0055fa70  83ec08               sub esp, 8
// 0055fa73  b81f85eb51           mov eax, 0x51eb851f
// 0055fa78  f7a1ac000000         mul dword ptr [ecx + 0xac]
// 0055fa7e  c1ea05               shr edx, 5
// 0055fa81  83fa01               cmp edx, 1
// 0055fa84  56                   push esi
// 0055fa85  89542404             mov dword ptr [esp + 4], edx
// 0055fa89  c744240801000000     mov dword ptr [esp + 8], 1
// 0055fa91  8d742404             lea esi, [esp + 4]
// 0055fa95  7f04                 jg 0x55fa9b
// 0055fa97  8d742408             lea esi, [esp + 8]
// 0055fa9b  e800121200           call 0x680ca0
// 0055faa0  0306                 add eax, dword ptr [esi]
// 0055faa2  5e                   pop esi
// 0055faa3  83c408               add esp, 8
// 0055faa6  c3                   ret 

extern "C" int __cdecl sub_00680ca0();

struct S_0055fa70 {
    char pad_0[0x94];
    unsigned int f_ac;
    int get();
};

int S_0055fa70::get() {
    unsigned int q = f_ac / 100;
    int a = (int)q;
    int b = 1;
    int* p;
    if (a > 1) {
        p = &a;
    } else {
        p = &b;
    }
    return sub_00680ca0() + *p;
}
