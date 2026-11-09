// from server: 100% by nuck16
// roc 2009-12 0076dd90  unit: RBX::VFrame::?$FactoryProduct  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0076dd90
//
// 0076dd90  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0076dd94  83f804               cmp eax, 4
// 0076dd97  7409                 je 0x76dda2
// 0076dd99  8944240c             mov dword ptr [esp + 0xc], eax
// 0076dd9d  e95ef9ffff           jmp 0x76d700
// 0076dda2  8b442408             mov eax, dword ptr [esp + 8]
// 0076dda6  32c9                 xor cl, cl
// 0076dda8  c700d006b600         mov dword ptr [eax], 0xb606d0
// 0076ddae  884804               mov byte ptr [eax + 4], cl
// 0076ddb1  884805               mov byte ptr [eax + 5], cl
// 0076ddb4  c3                   ret 

// 0xb606d0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b606d0[];
extern "C" void func_76d700(int, int, int);

void func_0076dd90(int a, int b, int c)
{
    if (c != 4)
    {
        func_76d700(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b606d0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
