// from server: 100% by nuck16
// roc 2009-12 0042b6a0  unit: VCProcessPerfCounter::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0042b6a0
//
// 0042b6a0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0042b6a4  83f804               cmp eax, 4
// 0042b6a7  7409                 je 0x42b6b2
// 0042b6a9  8944240c             mov dword ptr [esp + 0xc], eax
// 0042b6ad  e90ed5ffff           jmp 0x428bc0
// 0042b6b2  8b442408             mov eax, dword ptr [esp + 8]
// 0042b6b6  32c9                 xor cl, cl
// 0042b6b8  c700c84cb000         mov dword ptr [eax], 0xb04cc8
// 0042b6be  884804               mov byte ptr [eax + 4], cl
// 0042b6c1  884805               mov byte ptr [eax + 5], cl
// 0042b6c4  c3                   ret 

// 0xb04cc8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b04cc8[];
extern "C" void func_428bc0(int, int, int);

void func_0042b6a0(int a, int b, int c)
{
    if (c != 4)
    {
        func_428bc0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b04cc8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
