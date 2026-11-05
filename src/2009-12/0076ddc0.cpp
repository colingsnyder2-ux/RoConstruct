// from server: 100% by nuck16
// roc 2009-12 0076ddc0  unit: RBX::VFrame::?$FactoryProduct  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0076ddc0
//
// 0076ddc0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0076ddc4  83f804               cmp eax, 4
// 0076ddc7  7409                 je 0x76ddd2
// 0076ddc9  8944240c             mov dword ptr [esp + 0xc], eax
// 0076ddcd  e99ef9ffff           jmp 0x76d770
// 0076ddd2  8b442408             mov eax, dword ptr [esp + 8]
// 0076ddd6  32c9                 xor cl, cl
// 0076ddd8  c7004808b600         mov dword ptr [eax], 0xb60848
// 0076ddde  884804               mov byte ptr [eax + 4], cl
// 0076dde1  884805               mov byte ptr [eax + 5], cl
// 0076dde4  c3                   ret 

// 0xb60848 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b60848[];
extern "C" void func_76d770(int, int, int);

void func_0076ddc0(int a, int b, int c)
{
    if (c != 4)
    {
        func_76d770(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b60848;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
