// from server: 100% by nuck16
// roc 2009-12 006e7340  unit: RBX::Humanoid::$$A6AXW4Status::?$signal::slot  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006e7340
//
// 006e7340  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006e7344  83f804               cmp eax, 4
// 006e7347  7409                 je 0x6e7352
// 006e7349  8944240c             mov dword ptr [esp + 0xc], eax
// 006e734d  e93efeffff           jmp 0x6e7190
// 006e7352  8b442408             mov eax, dword ptr [esp + 8]
// 006e7356  32c9                 xor cl, cl
// 006e7358  c700c03cb400         mov dword ptr [eax], 0xb43cc0
// 006e735e  884804               mov byte ptr [eax + 4], cl
// 006e7361  884805               mov byte ptr [eax + 5], cl
// 006e7364  c3                   ret 

// 0xb43cc0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b43cc0[];
extern "C" void func_6e7190(int, int, int);

void func_006e7340(int a, int b, int c)
{
    if (c != 4)
    {
        func_6e7190(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b43cc0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
