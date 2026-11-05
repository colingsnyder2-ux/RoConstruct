// from server: 100% by nuck16
// roc 2009-12 00697770  unit: RBX::VIAdornableCollector::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00697770
//
// 00697770  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00697774  83f804               cmp eax, 4
// 00697777  7409                 je 0x697782
// 00697779  8944240c             mov dword ptr [esp + 0xc], eax
// 0069777d  e92eebffff           jmp 0x6962b0
// 00697782  8b442408             mov eax, dword ptr [esp + 8]
// 00697786  32c9                 xor cl, cl
// 00697788  c7001889b300         mov dword ptr [eax], 0xb38918
// 0069778e  884804               mov byte ptr [eax + 4], cl
// 00697791  884805               mov byte ptr [eax + 5], cl
// 00697794  c3                   ret 

// 0xb38918 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b38918[];
extern "C" void func_6962b0(int, int, int);

void func_00697770(int a, int b, int c)
{
    if (c != 4)
    {
        func_6962b0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b38918;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
