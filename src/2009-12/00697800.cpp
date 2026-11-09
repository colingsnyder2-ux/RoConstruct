// from server: 100% by nuck16
// roc 2009-12 00697800  unit: RBX::VIAdornableCollector::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00697800
//
// 00697800  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00697804  83f804               cmp eax, 4
// 00697807  7409                 je 0x697812
// 00697809  8944240c             mov dword ptr [esp + 0xc], eax
// 0069780d  e9eeebffff           jmp 0x696400
// 00697812  8b442408             mov eax, dword ptr [esp + 8]
// 00697816  32c9                 xor cl, cl
// 00697818  c700c88ab300         mov dword ptr [eax], 0xb38ac8
// 0069781e  884804               mov byte ptr [eax + 4], cl
// 00697821  884805               mov byte ptr [eax + 5], cl
// 00697824  c3                   ret 

// 0xb38ac8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b38ac8[];
extern "C" void func_696400(int, int, int);

void func_00697800(int a, int b, int c)
{
    if (c != 4)
    {
        func_696400(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b38ac8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
