// from server: 100% by nuck16
// roc 2009-12 00515640  unit: boost::X::V?$function0::?$thread_data  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00515640
//
// 00515640  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00515644  83f804               cmp eax, 4
// 00515647  7409                 je 0x515652
// 00515649  8944240c             mov dword ptr [esp + 0xc], eax
// 0051564d  e98ed9ffff           jmp 0x512fe0
// 00515652  8b442408             mov eax, dword ptr [esp + 8]
// 00515656  32c9                 xor cl, cl
// 00515658  c7009085b100         mov dword ptr [eax], 0xb18590
// 0051565e  884804               mov byte ptr [eax + 4], cl
// 00515661  884805               mov byte ptr [eax + 5], cl
// 00515664  c3                   ret 

// 0xb18590 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b18590[];
extern "C" void func_512fe0(int, int, int);

void func_00515640(int a, int b, int c)
{
    if (c != 4)
    {
        func_512fe0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b18590;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
