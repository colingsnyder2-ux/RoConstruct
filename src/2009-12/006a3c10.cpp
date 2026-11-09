// from server: 100% by nuck16
// roc 2009-12 006a3c10  unit: RBX::Lua::VLiveThreadRef::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006a3c10
//
// 006a3c10  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006a3c14  83f804               cmp eax, 4
// 006a3c17  7409                 je 0x6a3c22
// 006a3c19  8944240c             mov dword ptr [esp + 0xc], eax
// 006a3c1d  e93ec6ffff           jmp 0x6a0260
// 006a3c22  8b442408             mov eax, dword ptr [esp + 8]
// 006a3c26  32c9                 xor cl, cl
// 006a3c28  c700a89bb300         mov dword ptr [eax], 0xb39ba8
// 006a3c2e  884804               mov byte ptr [eax + 4], cl
// 006a3c31  884805               mov byte ptr [eax + 5], cl
// 006a3c34  c3                   ret 

// 0xb39ba8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b39ba8[];
extern "C" void func_6a0260(int, int, int);

void func_006a3c10(int a, int b, int c)
{
    if (c != 4)
    {
        func_6a0260(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b39ba8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
