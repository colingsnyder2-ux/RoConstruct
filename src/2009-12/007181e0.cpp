// from server: 100% by nuck16
// roc 2009-12 007181e0  unit: RBX::JointsService  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007181e0
//
// 007181e0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007181e4  83f804               cmp eax, 4
// 007181e7  7409                 je 0x7181f2
// 007181e9  8944240c             mov dword ptr [esp + 0xc], eax
// 007181ed  e92ef9ffff           jmp 0x717b20
// 007181f2  8b442408             mov eax, dword ptr [esp + 8]
// 007181f6  32c9                 xor cl, cl
// 007181f8  c70020d1b400         mov dword ptr [eax], 0xb4d120
// 007181fe  884804               mov byte ptr [eax + 4], cl
// 00718201  884805               mov byte ptr [eax + 5], cl
// 00718204  c3                   ret 

// 0xb4d120 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b4d120[];
extern "C" void func_717b20(int, int, int);

void func_007181e0(int a, int b, int c)
{
    if (c != 4)
    {
        func_717b20(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b4d120;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
