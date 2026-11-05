// from server: 100% by nuck16
// roc 2009-12 006b4dd0  unit: RBX::VContentId::?$TypedPropertyDescriptor  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006b4dd0
//
// 006b4dd0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006b4dd4  83f804               cmp eax, 4
// 006b4dd7  7409                 je 0x6b4de2
// 006b4dd9  8944240c             mov dword ptr [esp + 0xc], eax
// 006b4ddd  e96eeeffff           jmp 0x6b3c50
// 006b4de2  8b442408             mov eax, dword ptr [esp + 8]
// 006b4de6  32c9                 xor cl, cl
// 006b4de8  c70050abb300         mov dword ptr [eax], 0xb3ab50
// 006b4dee  884804               mov byte ptr [eax + 4], cl
// 006b4df1  884805               mov byte ptr [eax + 5], cl
// 006b4df4  c3                   ret 

// 0xb3ab50 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b3ab50[];
extern "C" void func_6b3c50(int, int, int);

void func_006b4dd0(int a, int b, int c)
{
    if (c != 4)
    {
        func_6b3c50(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b3ab50;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
