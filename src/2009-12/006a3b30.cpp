// from server: 100% by nuck16
// roc 2009-12 006a3b30  unit: RBX::Lua::VLiveThreadRef::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006a3b30
//
// 006a3b30  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006a3b34  83f804               cmp eax, 4
// 006a3b37  7409                 je 0x6a3b42
// 006a3b39  8944240c             mov dword ptr [esp + 0xc], eax
// 006a3b3d  e99ec4ffff           jmp 0x69ffe0
// 006a3b42  8b442408             mov eax, dword ptr [esp + 8]
// 006a3b46  32c9                 xor cl, cl
// 006a3b48  c7009097b300         mov dword ptr [eax], 0xb39790
// 006a3b4e  884804               mov byte ptr [eax + 4], cl
// 006a3b51  884805               mov byte ptr [eax + 5], cl
// 006a3b54  c3                   ret 

// 0xb39790 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b39790[];
extern "C" void func_69ffe0(int, int, int);

void func_006a3b30(int a, int b, int c)
{
    if (c != 4)
    {
        func_69ffe0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b39790;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
