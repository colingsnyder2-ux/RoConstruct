// from server: 100% by nuck16
// roc 2009-12 0078cf30  unit: VYieldFunctionStateObject::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078cf30
//
// 0078cf30  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0078cf34  83f804               cmp eax, 4
// 0078cf37  7409                 je 0x78cf42
// 0078cf39  8944240c             mov dword ptr [esp + 0xc], eax
// 0078cf3d  e9def7ffff           jmp 0x78c720
// 0078cf42  8b442408             mov eax, dword ptr [esp + 8]
// 0078cf46  32c9                 xor cl, cl
// 0078cf48  c700b027b600         mov dword ptr [eax], 0xb627b0
// 0078cf4e  884804               mov byte ptr [eax + 4], cl
// 0078cf51  884805               mov byte ptr [eax + 5], cl
// 0078cf54  c3                   ret 

// 0xb627b0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b627b0[];
extern "C" void func_78c720(int, int, int);

void func_0078cf30(int a, int b, int c)
{
    if (c != 4)
    {
        func_78c720(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b627b0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
