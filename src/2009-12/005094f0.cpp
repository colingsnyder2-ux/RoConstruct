// from server: 100% by nuck16
// roc 2009-12 005094f0  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::?$signal::slot  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005094f0
//
// 005094f0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005094f4  83f804               cmp eax, 4
// 005094f7  7409                 je 0x509502
// 005094f9  8944240c             mov dword ptr [esp + 0xc], eax
// 005094fd  e9cee4ffff           jmp 0x5079d0
// 00509502  8b442408             mov eax, dword ptr [esp + 8]
// 00509506  32c9                 xor cl, cl
// 00509508  c700d863b100         mov dword ptr [eax], 0xb163d8
// 0050950e  884804               mov byte ptr [eax + 4], cl
// 00509511  884805               mov byte ptr [eax + 5], cl
// 00509514  c3                   ret 

// 0xb163d8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b163d8[];
extern "C" void func_5079d0(int, int, int);

void func_005094f0(int a, int b, int c)
{
    if (c != 4)
    {
        func_5079d0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b163d8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
