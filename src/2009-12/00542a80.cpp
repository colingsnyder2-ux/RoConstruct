// from server: 100% by nuck16
// roc 2009-12 00542a80  unit: RBX::VMotor::?$FactoryProduct::Creator  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00542a80
//
// 00542a80  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00542a84  83f804               cmp eax, 4
// 00542a87  7409                 je 0x542a92
// 00542a89  8944240c             mov dword ptr [esp + 0xc], eax
// 00542a8d  e93ecdffff           jmp 0x53f7d0
// 00542a92  8b442408             mov eax, dword ptr [esp + 8]
// 00542a96  32c9                 xor cl, cl
// 00542a98  c70048e2b100         mov dword ptr [eax], 0xb1e248
// 00542a9e  884804               mov byte ptr [eax + 4], cl
// 00542aa1  884805               mov byte ptr [eax + 5], cl
// 00542aa4  c3                   ret 

// 0xb1e248 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b1e248[];
extern "C" void func_53f7d0(int, int, int);

void func_00542a80(int a, int b, int c)
{
    if (c != 4)
    {
        func_53f7d0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b1e248;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
