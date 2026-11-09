// from server: 100% by nuck16
// roc 2009-12 00747b40  unit: RBX::Handles  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00747b40
//
// 00747b40  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00747b44  83f804               cmp eax, 4
// 00747b47  7409                 je 0x747b52
// 00747b49  8944240c             mov dword ptr [esp + 0xc], eax
// 00747b4d  e9fef9ffff           jmp 0x747550
// 00747b52  8b442408             mov eax, dword ptr [esp + 8]
// 00747b56  32c9                 xor cl, cl
// 00747b58  c700d069b500         mov dword ptr [eax], 0xb569d0
// 00747b5e  884804               mov byte ptr [eax + 4], cl
// 00747b61  884805               mov byte ptr [eax + 5], cl
// 00747b64  c3                   ret 

// 0xb569d0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b569d0[];
extern "C" void func_747550(int, int, int);

void func_00747b40(int a, int b, int c)
{
    if (c != 4)
    {
        func_747550(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b569d0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
