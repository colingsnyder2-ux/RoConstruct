// from server: 100% by nuck16
// roc 2009-12 007c2370  unit: RBX::VChatLine::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c2370
//
// 007c2370  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007c2374  83f804               cmp eax, 4
// 007c2377  7409                 je 0x7c2382
// 007c2379  8944240c             mov dword ptr [esp + 0xc], eax
// 007c237d  e95efcffff           jmp 0x7c1fe0
// 007c2382  8b442408             mov eax, dword ptr [esp + 8]
// 007c2386  32c9                 xor cl, cl
// 007c2388  c7004839b600         mov dword ptr [eax], 0xb63948
// 007c238e  884804               mov byte ptr [eax + 4], cl
// 007c2391  884805               mov byte ptr [eax + 5], cl
// 007c2394  c3                   ret 

// 0xb63948 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b63948[];
extern "C" void func_7c1fe0(int, int, int);

void func_007c2370(int a, int b, int c)
{
    if (c != 4)
    {
        func_7c1fe0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b63948;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
