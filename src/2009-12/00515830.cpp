// from server: 100% by nuck16
// roc 2009-12 00515830  unit: boost::X::V?$function0::?$thread_data  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00515830
//
// 00515830  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00515834  83f804               cmp eax, 4
// 00515837  7409                 je 0x515842
// 00515839  8944240c             mov dword ptr [esp + 0xc], eax
// 0051583d  e9eed8ffff           jmp 0x513130
// 00515842  8b442408             mov eax, dword ptr [esp + 8]
// 00515846  32c9                 xor cl, cl
// 00515848  c7000088b100         mov dword ptr [eax], 0xb18800
// 0051584e  884804               mov byte ptr [eax + 4], cl
// 00515851  884805               mov byte ptr [eax + 5], cl
// 00515854  c3                   ret 

// 0xb18800 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b18800[];
extern "C" void func_513130(int, int, int);

void func_00515830(int a, int b, int c)
{
    if (c != 4)
    {
        func_513130(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b18800;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
