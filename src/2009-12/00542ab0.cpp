// from server: 100% by nuck16
// roc 2009-12 00542ab0  unit: RBX::VMotor::?$FactoryProduct::Creator  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00542ab0
//
// 00542ab0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00542ab4  83f804               cmp eax, 4
// 00542ab7  7409                 je 0x542ac2
// 00542ab9  8944240c             mov dword ptr [esp + 0xc], eax
// 00542abd  e9fecdffff           jmp 0x53f8c0
// 00542ac2  8b442408             mov eax, dword ptr [esp + 8]
// 00542ac6  32c9                 xor cl, cl
// 00542ac8  c70058e3b100         mov dword ptr [eax], 0xb1e358
// 00542ace  884804               mov byte ptr [eax + 4], cl
// 00542ad1  884805               mov byte ptr [eax + 5], cl
// 00542ad4  c3                   ret 

// 0xb1e358 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b1e358[];
extern "C" void func_53f8c0(int, int, int);

void func_00542ab0(int a, int b, int c)
{
    if (c != 4)
    {
        func_53f8c0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b1e358;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
