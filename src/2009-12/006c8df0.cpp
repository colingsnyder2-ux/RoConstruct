// from server: 100% by nuck16
// roc 2009-12 006c8df0  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::slot  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006c8df0
//
// 006c8df0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006c8df4  83f804               cmp eax, 4
// 006c8df7  7409                 je 0x6c8e02
// 006c8df9  8944240c             mov dword ptr [esp + 0xc], eax
// 006c8dfd  e9aefaffff           jmp 0x6c88b0
// 006c8e02  8b442408             mov eax, dword ptr [esp + 8]
// 006c8e06  32c9                 xor cl, cl
// 006c8e08  c700e0d2b300         mov dword ptr [eax], 0xb3d2e0
// 006c8e0e  884804               mov byte ptr [eax + 4], cl
// 006c8e11  884805               mov byte ptr [eax + 5], cl
// 006c8e14  c3                   ret 

// 0xb3d2e0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b3d2e0[];
extern "C" void func_6c88b0(int, int, int);

void func_006c8df0(int a, int b, int c)
{
    if (c != 4)
    {
        func_6c88b0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b3d2e0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
