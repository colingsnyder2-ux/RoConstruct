// from server: 100% by nuck16
// roc 2009-12 007411e0  unit: RBX::VDebrisService::?$FactoryProduct  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007411e0
//
// 007411e0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007411e4  83f804               cmp eax, 4
// 007411e7  7409                 je 0x7411f2
// 007411e9  8944240c             mov dword ptr [esp + 0xc], eax
// 007411ed  e9fefdffff           jmp 0x740ff0
// 007411f2  8b442408             mov eax, dword ptr [esp + 8]
// 007411f6  32c9                 xor cl, cl
// 007411f8  c700404bb500         mov dword ptr [eax], 0xb54b40
// 007411fe  884804               mov byte ptr [eax + 4], cl
// 00741201  884805               mov byte ptr [eax + 5], cl
// 00741204  c3                   ret 

// 0xb54b40 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b54b40[];
extern "C" void func_740ff0(int, int, int);

void func_007411e0(int a, int b, int c)
{
    if (c != 4)
    {
        func_740ff0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b54b40;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
