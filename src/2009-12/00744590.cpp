// from server: 100% by nuck16
// roc 2009-12 00744590  unit: RBX::Flag  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00744590
//
// 00744590  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00744594  83f804               cmp eax, 4
// 00744597  7409                 je 0x7445a2
// 00744599  8944240c             mov dword ptr [esp + 0xc], eax
// 0074459d  e95efdffff           jmp 0x744300
// 007445a2  8b442408             mov eax, dword ptr [esp + 8]
// 007445a6  32c9                 xor cl, cl
// 007445a8  c700d85bb500         mov dword ptr [eax], 0xb55bd8
// 007445ae  884804               mov byte ptr [eax + 4], cl
// 007445b1  884805               mov byte ptr [eax + 5], cl
// 007445b4  c3                   ret 

// 0xb55bd8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b55bd8[];
extern "C" void func_744300(int, int, int);

void func_00744590(int a, int b, int c)
{
    if (c != 4)
    {
        func_744300(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b55bd8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
