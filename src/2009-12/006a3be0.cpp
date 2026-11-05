// from server: 100% by nuck16
// roc 2009-12 006a3be0  unit: RBX::Lua::VLiveThreadRef::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006a3be0
//
// 006a3be0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006a3be4  83f804               cmp eax, 4
// 006a3be7  7409                 je 0x6a3bf2
// 006a3be9  8944240c             mov dword ptr [esp + 0xc], eax
// 006a3bed  e93ec5ffff           jmp 0x6a0130
// 006a3bf2  8b442408             mov eax, dword ptr [esp + 8]
// 006a3bf6  32c9                 xor cl, cl
// 006a3bf8  c700709ab300         mov dword ptr [eax], 0xb39a70
// 006a3bfe  884804               mov byte ptr [eax + 4], cl
// 006a3c01  884805               mov byte ptr [eax + 5], cl
// 006a3c04  c3                   ret 

// 0xb39a70 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b39a70[];
extern "C" void func_6a0130(int, int, int);

void func_006a3be0(int a, int b, int c)
{
    if (c != 4)
    {
        func_6a0130(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b39a70;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
