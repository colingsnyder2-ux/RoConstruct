// from server: 100% by nuck16
// roc 2009-12 0076de20  unit: RBX::VFrame::?$FactoryProduct  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0076de20
//
// 0076de20  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0076de24  83f804               cmp eax, 4
// 0076de27  7409                 je 0x76de32
// 0076de29  8944240c             mov dword ptr [esp + 0xc], eax
// 0076de2d  e9aefaffff           jmp 0x76d8e0
// 0076de32  8b442408             mov eax, dword ptr [esp + 8]
// 0076de36  32c9                 xor cl, cl
// 0076de38  c700a00ab600         mov dword ptr [eax], 0xb60aa0
// 0076de3e  884804               mov byte ptr [eax + 4], cl
// 0076de41  884805               mov byte ptr [eax + 5], cl
// 0076de44  c3                   ret 

// 0xb60aa0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b60aa0[];
extern "C" void func_76d8e0(int, int, int);

void func_0076de20(int a, int b, int c)
{
    if (c != 4)
    {
        func_76d8e0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b60aa0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
