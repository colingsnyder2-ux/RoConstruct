// from server: 100% by nuck16
// roc 2009-12 00747b70  unit: RBX::Handles  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00747b70
//
// 00747b70  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00747b74  83f804               cmp eax, 4
// 00747b77  7409                 je 0x747b82
// 00747b79  8944240c             mov dword ptr [esp + 0xc], eax
// 00747b7d  e95efbffff           jmp 0x7476e0
// 00747b82  8b442408             mov eax, dword ptr [esp + 8]
// 00747b86  32c9                 xor cl, cl
// 00747b88  c700f06db500         mov dword ptr [eax], 0xb56df0
// 00747b8e  884804               mov byte ptr [eax + 4], cl
// 00747b91  884805               mov byte ptr [eax + 5], cl
// 00747b94  c3                   ret 

// 0xb56df0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b56df0[];
extern "C" void func_7476e0(int, int, int);

void func_00747b70(int a, int b, int c)
{
    if (c != 4)
    {
        func_7476e0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b56df0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
