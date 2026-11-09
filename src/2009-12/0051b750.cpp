// from server: 100% by nuck16
// roc 2009-12 0051b750  unit: RBX::VInstance::V?$shared_ptr::V?$vector::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0051b750
//
// 0051b750  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0051b754  83f804               cmp eax, 4
// 0051b757  7409                 je 0x51b762
// 0051b759  8944240c             mov dword ptr [esp + 0xc], eax
// 0051b75d  e98ecfffff           jmp 0x5186f0
// 0051b762  8b442408             mov eax, dword ptr [esp + 8]
// 0051b766  32c9                 xor cl, cl
// 0051b768  c700e88db100         mov dword ptr [eax], 0xb18de8
// 0051b76e  884804               mov byte ptr [eax + 4], cl
// 0051b771  884805               mov byte ptr [eax + 5], cl
// 0051b774  c3                   ret 

// 0xb18de8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b18de8[];
extern "C" void func_5186f0(int, int, int);

void func_0051b750(int a, int b, int c)
{
    if (c != 4)
    {
        func_5186f0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b18de8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
