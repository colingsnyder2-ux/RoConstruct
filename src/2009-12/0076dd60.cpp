// from server: 100% by nuck16
// roc 2009-12 0076dd60  unit: RBX::VFrame::?$FactoryProduct  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0076dd60
//
// 0076dd60  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0076dd64  83f804               cmp eax, 4
// 0076dd67  7409                 je 0x76dd72
// 0076dd69  8944240c             mov dword ptr [esp + 0xc], eax
// 0076dd6d  e9cef5ffff           jmp 0x76d340
// 0076dd72  8b442408             mov eax, dword ptr [esp + 8]
// 0076dd76  32c9                 xor cl, cl
// 0076dd78  c700e000b600         mov dword ptr [eax], 0xb600e0
// 0076dd7e  884804               mov byte ptr [eax + 4], cl
// 0076dd81  884805               mov byte ptr [eax + 5], cl
// 0076dd84  c3                   ret 

// 0xb600e0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b600e0[];
extern "C" void func_76d340(int, int, int);

void func_0076dd60(int a, int b, int c)
{
    if (c != 4)
    {
        func_76d340(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b600e0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
