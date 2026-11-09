// from server: 100% by nuck16
// roc 2009-12 00754fe0  unit: RBX::VVehicleSeat::?$FactoryProduct  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00754fe0
//
// 00754fe0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00754fe4  83f804               cmp eax, 4
// 00754fe7  7409                 je 0x754ff2
// 00754fe9  8944240c             mov dword ptr [esp + 0xc], eax
// 00754fed  e92eeaffff           jmp 0x753a20
// 00754ff2  8b442408             mov eax, dword ptr [esp + 8]
// 00754ff6  32c9                 xor cl, cl
// 00754ff8  c700989db500         mov dword ptr [eax], 0xb59d98
// 00754ffe  884804               mov byte ptr [eax + 4], cl
// 00755001  884805               mov byte ptr [eax + 5], cl
// 00755004  c3                   ret 

// 0xb59d98 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b59d98[];
extern "C" void func_753a20(int, int, int);

void func_00754fe0(int a, int b, int c)
{
    if (c != 4)
    {
        func_753a20(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b59d98;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
