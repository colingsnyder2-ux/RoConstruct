// from server: 100% by nuck16
// roc 2009-12 004fe7a0  unit: RBX::Network::Player::W4BuildPermission::?$EnumDesc  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004fe7a0
//
// 004fe7a0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004fe7a4  83f804               cmp eax, 4
// 004fe7a7  7409                 je 0x4fe7b2
// 004fe7a9  8944240c             mov dword ptr [esp + 0xc], eax
// 004fe7ad  e9aed1ffff           jmp 0x4fb960
// 004fe7b2  8b442408             mov eax, dword ptr [esp + 8]
// 004fe7b6  32c9                 xor cl, cl
// 004fe7b8  c700c833b100         mov dword ptr [eax], 0xb133c8
// 004fe7be  884804               mov byte ptr [eax + 4], cl
// 004fe7c1  884805               mov byte ptr [eax + 5], cl
// 004fe7c4  c3                   ret 

// 0xb133c8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b133c8[];
extern "C" void func_4fb960(int, int, int);

void func_004fe7a0(int a, int b, int c)
{
    if (c != 4)
    {
        func_4fb960(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b133c8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
