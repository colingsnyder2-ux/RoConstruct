// from server: 100% by nuck16
// roc 2009-12 00754fb0  unit: RBX::VVehicleSeat::?$FactoryProduct  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00754fb0
//
// 00754fb0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00754fb4  83f804               cmp eax, 4
// 00754fb7  7409                 je 0x754fc2
// 00754fb9  8944240c             mov dword ptr [esp + 0xc], eax
// 00754fbd  e90ef6ffff           jmp 0x7545d0
// 00754fc2  8b442408             mov eax, dword ptr [esp + 8]
// 00754fc6  32c9                 xor cl, cl
// 00754fc8  c70088a0b500         mov dword ptr [eax], 0xb5a088
// 00754fce  884804               mov byte ptr [eax + 4], cl
// 00754fd1  884805               mov byte ptr [eax + 5], cl
// 00754fd4  c3                   ret 

// 0xb5a088 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b5a088[];
extern "C" void func_7545d0(int, int, int);

void func_00754fb0(int a, int b, int c)
{
    if (c != 4)
    {
        func_7545d0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b5a088;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
