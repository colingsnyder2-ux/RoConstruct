// from server: 100% by nuck16
// roc 2009-12 00747ba0  unit: RBX::Handles  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00747ba0
//
// 00747ba0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00747ba4  83f804               cmp eax, 4
// 00747ba7  7409                 je 0x747bb2
// 00747ba9  8944240c             mov dword ptr [esp + 0xc], eax
// 00747bad  e92efcffff           jmp 0x7477e0
// 00747bb2  8b442408             mov eax, dword ptr [esp + 8]
// 00747bb6  32c9                 xor cl, cl
// 00747bb8  c700a86fb500         mov dword ptr [eax], 0xb56fa8
// 00747bbe  884804               mov byte ptr [eax + 4], cl
// 00747bc1  884805               mov byte ptr [eax + 5], cl
// 00747bc4  c3                   ret 

// 0xb56fa8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b56fa8[];
extern "C" void func_7477e0(int, int, int);

void func_00747ba0(int a, int b, int c)
{
    if (c != 4)
    {
        func_7477e0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b56fa8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
