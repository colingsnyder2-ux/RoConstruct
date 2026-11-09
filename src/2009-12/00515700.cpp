// from server: 100% by nuck16
// roc 2009-12 00515700  unit: boost::X::V?$function0::?$thread_data  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00515700
//
// 00515700  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00515704  83f804               cmp eax, 4
// 00515707  7409                 je 0x515712
// 00515709  8944240c             mov dword ptr [esp + 0xc], eax
// 0051570d  e93ed9ffff           jmp 0x513050
// 00515712  8b442408             mov eax, dword ptr [esp + 8]
// 00515716  32c9                 xor cl, cl
// 00515718  c7009086b100         mov dword ptr [eax], 0xb18690
// 0051571e  884804               mov byte ptr [eax + 4], cl
// 00515721  884805               mov byte ptr [eax + 5], cl
// 00515724  c3                   ret 

// 0xb18690 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b18690[];
extern "C" void func_513050(int, int, int);

void func_00515700(int a, int b, int c)
{
    if (c != 4)
    {
        func_513050(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b18690;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
