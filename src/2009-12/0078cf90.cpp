// from server: 100% by nuck16
// roc 2009-12 0078cf90  unit: VYieldFunctionStateObject::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078cf90
//
// 0078cf90  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0078cf94  83f804               cmp eax, 4
// 0078cf97  7409                 je 0x78cfa2
// 0078cf99  8944240c             mov dword ptr [esp + 0xc], eax
// 0078cf9d  e93ef9ffff           jmp 0x78c8e0
// 0078cfa2  8b442408             mov eax, dword ptr [esp + 8]
// 0078cfa6  32c9                 xor cl, cl
// 0078cfa8  c7007029b600         mov dword ptr [eax], 0xb62970
// 0078cfae  884804               mov byte ptr [eax + 4], cl
// 0078cfb1  884805               mov byte ptr [eax + 5], cl
// 0078cfb4  c3                   ret 

// 0xb62970 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b62970[];
extern "C" void func_78c8e0(int, int, int);

void func_0078cf90(int a, int b, int c)
{
    if (c != 4)
    {
        func_78c8e0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b62970;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
