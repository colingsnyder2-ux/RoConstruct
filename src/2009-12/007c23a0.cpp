// from server: 100% by nuck16
// roc 2009-12 007c23a0  unit: RBX::VChatLine::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c23a0
//
// 007c23a0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007c23a4  83f804               cmp eax, 4
// 007c23a7  7409                 je 0x7c23b2
// 007c23a9  8944240c             mov dword ptr [esp + 0xc], eax
// 007c23ad  e99efcffff           jmp 0x7c2050
// 007c23b2  8b442408             mov eax, dword ptr [esp + 8]
// 007c23b6  32c9                 xor cl, cl
// 007c23b8  c700e839b600         mov dword ptr [eax], 0xb639e8
// 007c23be  884804               mov byte ptr [eax + 4], cl
// 007c23c1  884805               mov byte ptr [eax + 5], cl
// 007c23c4  c3                   ret 

// 0xb639e8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b639e8[];
extern "C" void func_7c2050(int, int, int);

void func_007c23a0(int a, int b, int c)
{
    if (c != 4)
    {
        func_7c2050(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b639e8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
