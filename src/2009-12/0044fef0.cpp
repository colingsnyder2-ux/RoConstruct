// from server: 100% by nuck16
// roc 2009-12 0044fef0  unit: ErrorUploader::Udata::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0044fef0
//
// 0044fef0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0044fef4  83f804               cmp eax, 4
// 0044fef7  7409                 je 0x44ff02
// 0044fef9  8944240c             mov dword ptr [esp + 0xc], eax
// 0044fefd  e96eefffff           jmp 0x44ee70
// 0044ff02  8b442408             mov eax, dword ptr [esp + 8]
// 0044ff06  32c9                 xor cl, cl
// 0044ff08  c7000892b000         mov dword ptr [eax], 0xb09208
// 0044ff0e  884804               mov byte ptr [eax + 4], cl
// 0044ff11  884805               mov byte ptr [eax + 5], cl
// 0044ff14  c3                   ret 

// 0xb09208 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b09208[];
extern "C" void func_44ee70(int, int, int);

void func_0044fef0(int a, int b, int c)
{
    if (c != 4)
    {
        func_44ee70(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b09208;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
