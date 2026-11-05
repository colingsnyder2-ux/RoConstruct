// from server: 100% by nuck16
// roc 2009-12 0078cf60  unit: VYieldFunctionStateObject::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078cf60
//
// 0078cf60  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0078cf64  83f804               cmp eax, 4
// 0078cf67  7409                 je 0x78cf72
// 0078cf69  8944240c             mov dword ptr [esp + 0xc], eax
// 0078cf6d  e98ef8ffff           jmp 0x78c800
// 0078cf72  8b442408             mov eax, dword ptr [esp + 8]
// 0078cf76  32c9                 xor cl, cl
// 0078cf78  c7008828b600         mov dword ptr [eax], 0xb62888
// 0078cf7e  884804               mov byte ptr [eax + 4], cl
// 0078cf81  884805               mov byte ptr [eax + 5], cl
// 0078cf84  c3                   ret 

// 0xb62888 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b62888[];
extern "C" void func_78c800(int, int, int);

void func_0078cf60(int a, int b, int c)
{
    if (c != 4)
    {
        func_78c800(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b62888;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
