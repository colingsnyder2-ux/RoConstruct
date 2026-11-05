// from server: 100% by nuck16
// roc 2009-12 0057c6c0  unit: std::Vlength_error::?$error_info_injector  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057c6c0
//
// 0057c6c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0057c6c4  83f804               cmp eax, 4
// 0057c6c7  7409                 je 0x57c6d2
// 0057c6c9  8944240c             mov dword ptr [esp + 0xc], eax
// 0057c6cd  e95ef4ffff           jmp 0x57bb30
// 0057c6d2  8b442408             mov eax, dword ptr [esp + 8]
// 0057c6d6  32c9                 xor cl, cl
// 0057c6d8  c700104fb200         mov dword ptr [eax], 0xb24f10
// 0057c6de  884804               mov byte ptr [eax + 4], cl
// 0057c6e1  884805               mov byte ptr [eax + 5], cl
// 0057c6e4  c3                   ret 

// 0xb24f10 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b24f10[];
extern "C" void func_57bb30(int, int, int);

void func_0057c6c0(int a, int b, int c)
{
    if (c != 4)
    {
        func_57bb30(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b24f10;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
