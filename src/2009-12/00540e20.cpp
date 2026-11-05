// from server: 100% by nuck16
// roc 2009-12 00540e20  unit: RBX::Network::Replicator::NewInstanceItem  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00540e20
//
// 00540e20  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00540e24  83f804               cmp eax, 4
// 00540e27  7409                 je 0x540e32
// 00540e29  8944240c             mov dword ptr [esp + 0xc], eax
// 00540e2d  e9eed4ffff           jmp 0x53e320
// 00540e32  8b442408             mov eax, dword ptr [esp + 8]
// 00540e36  32c9                 xor cl, cl
// 00540e38  c70090e0b100         mov dword ptr [eax], 0xb1e090
// 00540e3e  884804               mov byte ptr [eax + 4], cl
// 00540e41  884805               mov byte ptr [eax + 5], cl
// 00540e44  c3                   ret 

// 0xb1e090 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b1e090[];
extern "C" void func_53e320(int, int, int);

void func_00540e20(int a, int b, int c)
{
    if (c != 4)
    {
        func_53e320(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b1e090;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
