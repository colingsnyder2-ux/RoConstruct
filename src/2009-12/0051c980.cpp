// from server: 100% by nuck16
// roc 2009-12 0051c980  unit: RBX::Network::Players::W4ChatOption::?$EnumDesc  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0051c980
//
// 0051c980  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0051c984  83f804               cmp eax, 4
// 0051c987  7409                 je 0x51c992
// 0051c989  8944240c             mov dword ptr [esp + 0xc], eax
// 0051c98d  e9aec7ffff           jmp 0x519140
// 0051c992  8b442408             mov eax, dword ptr [esp + 8]
// 0051c996  32c9                 xor cl, cl
// 0051c998  c700308fb100         mov dword ptr [eax], 0xb18f30
// 0051c99e  884804               mov byte ptr [eax + 4], cl
// 0051c9a1  884805               mov byte ptr [eax + 5], cl
// 0051c9a4  c3                   ret 

// 0xb18f30 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b18f30[];
extern "C" void func_519140(int, int, int);

void func_0051c980(int a, int b, int c)
{
    if (c != 4)
    {
        func_519140(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b18f30;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
