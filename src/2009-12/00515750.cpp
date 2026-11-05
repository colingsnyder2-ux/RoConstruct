// from server: 100% by nuck16
// roc 2009-12 00515750  unit: boost::X::V?$function0::?$thread_data  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00515750
//
// 00515750  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00515754  83f804               cmp eax, 4
// 00515757  7409                 je 0x515762
// 00515759  8944240c             mov dword ptr [esp + 0xc], eax
// 0051575d  e95ed9ffff           jmp 0x5130c0
// 00515762  8b442408             mov eax, dword ptr [esp + 8]
// 00515766  32c9                 xor cl, cl
// 00515768  c7003087b100         mov dword ptr [eax], 0xb18730
// 0051576e  884804               mov byte ptr [eax + 4], cl
// 00515771  884805               mov byte ptr [eax + 5], cl
// 00515774  c3                   ret 

// 0xb18730 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b18730[];
extern "C" void func_5130c0(int, int, int);

void func_00515750(int a, int b, int c)
{
    if (c != 4)
    {
        func_5130c0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b18730;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
