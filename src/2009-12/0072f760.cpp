// from server: 100% by nuck16
// roc 2009-12 0072f760  unit: rbx::signals::Z::$$A6AXH::?$signal::slot  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0072f760
//
// 0072f760  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0072f764  83f804               cmp eax, 4
// 0072f767  7409                 je 0x72f772
// 0072f769  8944240c             mov dword ptr [esp + 0xc], eax
// 0072f76d  e93efeffff           jmp 0x72f5b0
// 0072f772  8b442408             mov eax, dword ptr [esp + 8]
// 0072f776  32c9                 xor cl, cl
// 0072f778  c700d000b500         mov dword ptr [eax], 0xb500d0
// 0072f77e  884804               mov byte ptr [eax + 4], cl
// 0072f781  884805               mov byte ptr [eax + 5], cl
// 0072f784  c3                   ret 

// 0xb500d0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b500d0[];
extern "C" void func_72f5b0(int, int, int);

void func_0072f760(int a, int b, int c)
{
    if (c != 4)
    {
        func_72f5b0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b500d0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
