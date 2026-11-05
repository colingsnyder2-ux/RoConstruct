// from server: 100% by nuck16
// roc 2009-12 006a3ae0  unit: RBX::Lua::VLiveThreadRef::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006a3ae0
//
// 006a3ae0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006a3ae4  83f804               cmp eax, 4
// 006a3ae7  7409                 je 0x6a3af2
// 006a3ae9  8944240c             mov dword ptr [esp + 0xc], eax
// 006a3aed  e97ec4ffff           jmp 0x69ff70
// 006a3af2  8b442408             mov eax, dword ptr [esp + 8]
// 006a3af6  32c9                 xor cl, cl
// 006a3af8  c7003097b300         mov dword ptr [eax], 0xb39730
// 006a3afe  884804               mov byte ptr [eax + 4], cl
// 006a3b01  884805               mov byte ptr [eax + 5], cl
// 006a3b04  c3                   ret 

// 0xb39730 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b39730[];
extern "C" void func_69ff70(int, int, int);

void func_006a3ae0(int a, int b, int c)
{
    if (c != 4)
    {
        func_69ff70(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b39730;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
