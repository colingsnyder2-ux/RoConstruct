// from server: 100% by nuck16
// roc 2009-12 00742a60  unit: RBX::VHole::?$FactoryProduct  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00742a60
//
// 00742a60  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00742a64  83f804               cmp eax, 4
// 00742a67  7409                 je 0x742a72
// 00742a69  8944240c             mov dword ptr [esp + 0xc], eax
// 00742a6d  e97ef2ffff           jmp 0x741cf0
// 00742a72  8b442408             mov eax, dword ptr [esp + 8]
// 00742a76  32c9                 xor cl, cl
// 00742a78  c700204fb500         mov dword ptr [eax], 0xb54f20
// 00742a7e  884804               mov byte ptr [eax + 4], cl
// 00742a81  884805               mov byte ptr [eax + 5], cl
// 00742a84  c3                   ret 

// 0xb54f20 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b54f20[];
extern "C" void func_741cf0(int, int, int);

void func_00742a60(int a, int b, int c)
{
    if (c != 4)
    {
        func_741cf0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b54f20;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
