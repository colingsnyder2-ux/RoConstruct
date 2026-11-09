// from server: 100% by nuck16
// roc 2009-12 007851c0  unit: RBX::ToolMouseCommand  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007851c0
//
// 007851c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007851c4  83f804               cmp eax, 4
// 007851c7  7409                 je 0x7851d2
// 007851c9  8944240c             mov dword ptr [esp + 0xc], eax
// 007851cd  e99efcffff           jmp 0x784e70
// 007851d2  8b442408             mov eax, dword ptr [esp + 8]
// 007851d6  32c9                 xor cl, cl
// 007851d8  c700f020b600         mov dword ptr [eax], 0xb620f0
// 007851de  884804               mov byte ptr [eax + 4], cl
// 007851e1  884805               mov byte ptr [eax + 5], cl
// 007851e4  c3                   ret 

// 0xb620f0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b620f0[];
extern "C" void func_784e70(int, int, int);

void func_007851c0(int a, int b, int c)
{
    if (c != 4)
    {
        func_784e70(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b620f0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
