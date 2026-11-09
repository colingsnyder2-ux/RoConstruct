// from server: 100% by nuck16
// roc 2009-12 006a3b80  unit: RBX::Lua::VLiveThreadRef::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006a3b80
//
// 006a3b80  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006a3b84  83f804               cmp eax, 4
// 006a3b87  7409                 je 0x6a3b92
// 006a3b89  8944240c             mov dword ptr [esp + 0xc], eax
// 006a3b8d  e9bec4ffff           jmp 0x6a0050
// 006a3b92  8b442408             mov eax, dword ptr [esp + 8]
// 006a3b96  32c9                 xor cl, cl
// 006a3b98  c7000098b300         mov dword ptr [eax], 0xb39800
// 006a3b9e  884804               mov byte ptr [eax + 4], cl
// 006a3ba1  884805               mov byte ptr [eax + 5], cl
// 006a3ba4  c3                   ret 

// 0xb39800 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b39800[];
extern "C" void func_6a0050(int, int, int);

void func_006a3b80(int a, int b, int c)
{
    if (c != 4)
    {
        func_6a0050(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b39800;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
