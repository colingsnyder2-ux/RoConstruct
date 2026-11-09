// from server: 100% by nuck16
// roc 2009-12 006b4e00  unit: RBX::VContentId::?$TypedPropertyDescriptor  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006b4e00
//
// 006b4e00  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006b4e04  83f804               cmp eax, 4
// 006b4e07  7409                 je 0x6b4e12
// 006b4e09  8944240c             mov dword ptr [esp + 0xc], eax
// 006b4e0d  e9aeeeffff           jmp 0x6b3cc0
// 006b4e12  8b442408             mov eax, dword ptr [esp + 8]
// 006b4e16  32c9                 xor cl, cl
// 006b4e18  c70008acb300         mov dword ptr [eax], 0xb3ac08
// 006b4e1e  884804               mov byte ptr [eax + 4], cl
// 006b4e21  884805               mov byte ptr [eax + 5], cl
// 006b4e24  c3                   ret 

// 0xb3ac08 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b3ac08[];
extern "C" void func_6b3cc0(int, int, int);

void func_006b4e00(int a, int b, int c)
{
    if (c != 4)
    {
        func_6b3cc0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b3ac08;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
