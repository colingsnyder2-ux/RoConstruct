// from server: 100% by nuck16
// roc 2009-12 0055e8e0  unit: RBX::Network::NetworkOwnerJob  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0055e8e0
//
// 0055e8e0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0055e8e4  83f804               cmp eax, 4
// 0055e8e7  7409                 je 0x55e8f2
// 0055e8e9  8944240c             mov dword ptr [esp + 0xc], eax
// 0055e8ed  e91eedffff           jmp 0x55d610
// 0055e8f2  8b442408             mov eax, dword ptr [esp + 8]
// 0055e8f6  32c9                 xor cl, cl
// 0055e8f8  c7004803b200         mov dword ptr [eax], 0xb20348
// 0055e8fe  884804               mov byte ptr [eax + 4], cl
// 0055e901  884805               mov byte ptr [eax + 5], cl
// 0055e904  c3                   ret 

// 0xb20348 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b20348[];
extern "C" void func_55d610(int, int, int);

void func_0055e8e0(int a, int b, int c)
{
    if (c != 4)
    {
        func_55d610(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b20348;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
