// from server: 100% by nuck16
// roc 2009-12 00697740  unit: RBX::VIAdornableCollector::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00697740
//
// 00697740  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00697744  83f804               cmp eax, 4
// 00697747  7409                 je 0x697752
// 00697749  8944240c             mov dword ptr [esp + 0xc], eax
// 0069774d  e9eeeaffff           jmp 0x696240
// 00697752  8b442408             mov eax, dword ptr [esp + 8]
// 00697756  32c9                 xor cl, cl
// 00697758  c7009088b300         mov dword ptr [eax], 0xb38890
// 0069775e  884804               mov byte ptr [eax + 4], cl
// 00697761  884805               mov byte ptr [eax + 5], cl
// 00697764  c3                   ret 

// 0xb38890 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b38890[];
extern "C" void func_696240(int, int, int);

void func_00697740(int a, int b, int c)
{
    if (c != 4)
    {
        func_696240(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b38890;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
