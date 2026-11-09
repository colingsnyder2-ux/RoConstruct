// from server: 100% by nuck16
// roc 2009-12 0063c170  unit: rbx::signals::Z::$$A6AXNN::?$signal::slot  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0063c170
//
// 0063c170  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0063c174  83f804               cmp eax, 4
// 0063c177  7409                 je 0x63c182
// 0063c179  8944240c             mov dword ptr [esp + 0xc], eax
// 0063c17d  e9defbffff           jmp 0x63bd60
// 0063c182  8b442408             mov eax, dword ptr [esp + 8]
// 0063c186  32c9                 xor cl, cl
// 0063c188  c700b8aab200         mov dword ptr [eax], 0xb2aab8
// 0063c18e  884804               mov byte ptr [eax + 4], cl
// 0063c191  884805               mov byte ptr [eax + 5], cl
// 0063c194  c3                   ret 

// 0xb2aab8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b2aab8[];
extern "C" void func_63bd60(int, int, int);

void func_0063c170(int a, int b, int c)
{
    if (c != 4)
    {
        func_63bd60(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b2aab8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
