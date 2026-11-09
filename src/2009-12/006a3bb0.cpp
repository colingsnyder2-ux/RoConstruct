// from server: 100% by nuck16
// roc 2009-12 006a3bb0  unit: RBX::Lua::VLiveThreadRef::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006a3bb0
//
// 006a3bb0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006a3bb4  83f804               cmp eax, 4
// 006a3bb7  7409                 je 0x6a3bc2
// 006a3bb9  8944240c             mov dword ptr [esp + 0xc], eax
// 006a3bbd  e9fec4ffff           jmp 0x6a00c0
// 006a3bc2  8b442408             mov eax, dword ptr [esp + 8]
// 006a3bc6  32c9                 xor cl, cl
// 006a3bc8  c7002099b300         mov dword ptr [eax], 0xb39920
// 006a3bce  884804               mov byte ptr [eax + 4], cl
// 006a3bd1  884805               mov byte ptr [eax + 5], cl
// 006a3bd4  c3                   ret 

// 0xb39920 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b39920[];
extern "C" void func_6a00c0(int, int, int);

void func_006a3bb0(int a, int b, int c)
{
    if (c != 4)
    {
        func_6a00c0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b39920;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
