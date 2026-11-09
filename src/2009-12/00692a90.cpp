// from server: 100% by nuck16
// roc 2009-12 00692a90  unit: RBX::Tool  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00692a90
//
// 00692a90  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00692a94  83f804               cmp eax, 4
// 00692a97  7409                 je 0x692aa2
// 00692a99  8944240c             mov dword ptr [esp + 0xc], eax
// 00692a9d  e91efaffff           jmp 0x6924c0
// 00692aa2  8b442408             mov eax, dword ptr [esp + 8]
// 00692aa6  32c9                 xor cl, cl
// 00692aa8  c700e07eb300         mov dword ptr [eax], 0xb37ee0
// 00692aae  884804               mov byte ptr [eax + 4], cl
// 00692ab1  884805               mov byte ptr [eax + 5], cl
// 00692ab4  c3                   ret 

// 0xb37ee0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b37ee0[];
extern "C" void func_6924c0(int, int, int);

void func_00692a90(int a, int b, int c)
{
    if (c != 4)
    {
        func_6924c0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b37ee0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
