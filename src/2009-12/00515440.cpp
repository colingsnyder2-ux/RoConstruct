// from server: 100% by nuck16
// roc 2009-12 00515440  unit: RakNet::VBitStream::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00515440
//
// 00515440  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00515444  83f804               cmp eax, 4
// 00515447  7409                 je 0x515452
// 00515449  8944240c             mov dword ptr [esp + 0xc], eax
// 0051544d  e95ed8ffff           jmp 0x512cb0
// 00515452  8b442408             mov eax, dword ptr [esp + 8]
// 00515456  32c9                 xor cl, cl
// 00515458  c700f882b100         mov dword ptr [eax], 0xb182f8
// 0051545e  884804               mov byte ptr [eax + 4], cl
// 00515461  884805               mov byte ptr [eax + 5], cl
// 00515464  c3                   ret 

// 0xb182f8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b182f8[];
extern "C" void func_512cb0(int, int, int);

void func_00515440(int a, int b, int c)
{
    if (c != 4)
    {
        func_512cb0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b182f8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
