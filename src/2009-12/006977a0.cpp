// from server: 100% by nuck16
// roc 2009-12 006977a0  unit: RBX::VIAdornableCollector::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006977a0
//
// 006977a0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006977a4  83f804               cmp eax, 4
// 006977a7  7409                 je 0x6977b2
// 006977a9  8944240c             mov dword ptr [esp + 0xc], eax
// 006977ad  e96eebffff           jmp 0x696320
// 006977b2  8b442408             mov eax, dword ptr [esp + 8]
// 006977b6  32c9                 xor cl, cl
// 006977b8  c7009089b300         mov dword ptr [eax], 0xb38990
// 006977be  884804               mov byte ptr [eax + 4], cl
// 006977c1  884805               mov byte ptr [eax + 5], cl
// 006977c4  c3                   ret 

// 0xb38990 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b38990[];
extern "C" void func_696320(int, int, int);

void func_006977a0(int a, int b, int c)
{
    if (c != 4)
    {
        func_696320(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b38990;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
