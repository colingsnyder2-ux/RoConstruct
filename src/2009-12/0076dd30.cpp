// from server: 100% by nuck16
// roc 2009-12 0076dd30  unit: RBX::VFrame::?$FactoryProduct  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0076dd30
//
// 0076dd30  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0076dd34  83f804               cmp eax, 4
// 0076dd37  7409                 je 0x76dd42
// 0076dd39  8944240c             mov dword ptr [esp + 0xc], eax
// 0076dd3d  e98ef5ffff           jmp 0x76d2d0
// 0076dd42  8b442408             mov eax, dword ptr [esp + 8]
// 0076dd46  32c9                 xor cl, cl
// 0076dd48  c7000800b600         mov dword ptr [eax], 0xb60008
// 0076dd4e  884804               mov byte ptr [eax + 4], cl
// 0076dd51  884805               mov byte ptr [eax + 5], cl
// 0076dd54  c3                   ret 

// 0xb60008 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b60008[];
extern "C" void func_76d2d0(int, int, int);

void func_0076dd30(int a, int b, int c)
{
    if (c != 4)
    {
        func_76d2d0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b60008;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
