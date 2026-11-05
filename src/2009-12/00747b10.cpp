// from server: 100% by nuck16
// roc 2009-12 00747b10  unit: RBX::Handles  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00747b10
//
// 00747b10  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00747b14  83f804               cmp eax, 4
// 00747b17  7409                 je 0x747b22
// 00747b19  8944240c             mov dword ptr [esp + 0xc], eax
// 00747b1d  e9bef9ffff           jmp 0x7474e0
// 00747b22  8b442408             mov eax, dword ptr [esp + 8]
// 00747b26  32c9                 xor cl, cl
// 00747b28  c700e068b500         mov dword ptr [eax], 0xb568e0
// 00747b2e  884804               mov byte ptr [eax + 4], cl
// 00747b31  884805               mov byte ptr [eax + 5], cl
// 00747b34  c3                   ret 

// 0xb568e0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b568e0[];
extern "C" void func_7474e0(int, int, int);

void func_00747b10(int a, int b, int c)
{
    if (c != 4)
    {
        func_7474e0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b568e0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
