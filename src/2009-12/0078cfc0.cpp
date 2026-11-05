// from server: 100% by nuck16
// roc 2009-12 0078cfc0  unit: VYieldFunctionStateObject::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078cfc0
//
// 0078cfc0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0078cfc4  83f804               cmp eax, 4
// 0078cfc7  7409                 je 0x78cfd2
// 0078cfc9  8944240c             mov dword ptr [esp + 0xc], eax
// 0078cfcd  e9fef9ffff           jmp 0x78c9d0
// 0078cfd2  8b442408             mov eax, dword ptr [esp + 8]
// 0078cfd6  32c9                 xor cl, cl
// 0078cfd8  c700482ab600         mov dword ptr [eax], 0xb62a48
// 0078cfde  884804               mov byte ptr [eax + 4], cl
// 0078cfe1  884805               mov byte ptr [eax + 5], cl
// 0078cfe4  c3                   ret 

// 0xb62a48 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b62a48[];
extern "C" void func_78c9d0(int, int, int);

void func_0078cfc0(int a, int b, int c)
{
    if (c != 4)
    {
        func_78c9d0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b62a48;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
