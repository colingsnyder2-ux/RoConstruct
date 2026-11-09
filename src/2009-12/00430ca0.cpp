// from server: 100% by nuck16
// roc 2009-12 00430ca0  unit: COutputView  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00430ca0
//
// 00430ca0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00430ca4  83f804               cmp eax, 4
// 00430ca7  7409                 je 0x430cb2
// 00430ca9  8944240c             mov dword ptr [esp + 0xc], eax
// 00430cad  e98efbffff           jmp 0x430840
// 00430cb2  8b442408             mov eax, dword ptr [esp + 8]
// 00430cb6  32c9                 xor cl, cl
// 00430cb8  c7009053b000         mov dword ptr [eax], 0xb05390
// 00430cbe  884804               mov byte ptr [eax + 4], cl
// 00430cc1  884805               mov byte ptr [eax + 5], cl
// 00430cc4  c3                   ret 

// 0xb05390 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b05390[];
extern "C" void func_430840(int, int, int);

void func_00430ca0(int a, int b, int c)
{
    if (c != 4)
    {
        func_430840(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b05390;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
