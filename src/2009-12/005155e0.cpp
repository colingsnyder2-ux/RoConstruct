// from server: 100% by nuck16
// roc 2009-12 005155e0  unit: boost::X::V?$function0::?$thread_data  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005155e0
//
// 005155e0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005155e4  83f804               cmp eax, 4
// 005155e7  7409                 je 0x5155f2
// 005155e9  8944240c             mov dword ptr [esp + 0xc], eax
// 005155ed  e90ed9ffff           jmp 0x512f00
// 005155f2  8b442408             mov eax, dword ptr [esp + 8]
// 005155f6  32c9                 xor cl, cl
// 005155f8  c700a883b100         mov dword ptr [eax], 0xb183a8
// 005155fe  884804               mov byte ptr [eax + 4], cl
// 00515601  884805               mov byte ptr [eax + 5], cl
// 00515604  c3                   ret 

// 0xb183a8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b183a8[];
extern "C" void func_512f00(int, int, int);

void func_005155e0(int a, int b, int c)
{
    if (c != 4)
    {
        func_512f00(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b183a8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
