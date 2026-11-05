// from server: 100% by nuck16
// roc 2009-12 007e66d0  unit: RBX::VCEvent::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007e66d0
//
// 007e66d0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e66d4  83f804               cmp eax, 4
// 007e66d7  7409                 je 0x7e66e2
// 007e66d9  8944240c             mov dword ptr [esp + 0xc], eax
// 007e66dd  e9def7ffff           jmp 0x7e5ec0
// 007e66e2  8b442408             mov eax, dword ptr [esp + 8]
// 007e66e6  32c9                 xor cl, cl
// 007e66e8  c700904cb600         mov dword ptr [eax], 0xb64c90
// 007e66ee  884804               mov byte ptr [eax + 4], cl
// 007e66f1  884805               mov byte ptr [eax + 5], cl
// 007e66f4  c3                   ret 

// 0xb64c90 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b64c90[];
extern "C" void func_7e5ec0(int, int, int);

void func_007e66d0(int a, int b, int c)
{
    if (c != 4)
    {
        func_7e5ec0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b64c90;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
