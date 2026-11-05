// from server: 100% by nuck16
// roc 2009-12 007a47b0  unit: seg_007a0000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007a47b0
//
// 007a47b0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007a47b4  83f804               cmp eax, 4
// 007a47b7  7409                 je 0x7a47c2
// 007a47b9  8944240c             mov dword ptr [esp + 0xc], eax
// 007a47bd  e97effffff           jmp 0x7a4740
// 007a47c2  8b442408             mov eax, dword ptr [esp + 8]
// 007a47c6  32c9                 xor cl, cl
// 007a47c8  c700a82eb600         mov dword ptr [eax], 0xb62ea8
// 007a47ce  884804               mov byte ptr [eax + 4], cl
// 007a47d1  884805               mov byte ptr [eax + 5], cl
// 007a47d4  c3                   ret 

// 0xb62ea8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b62ea8[];
extern "C" void func_7a4740(int, int, int);

void func_007a47b0(int a, int b, int c)
{
    if (c != 4)
    {
        func_7a4740(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b62ea8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
