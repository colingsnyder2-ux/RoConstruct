// from server: 100% by nuck16
// roc 2009-12 00682ec0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00682ec0
//
// 00682ec0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00682ec4  83f804               cmp eax, 4
// 00682ec7  7409                 je 0x682ed2
// 00682ec9  8944240c             mov dword ptr [esp + 0xc], eax
// 00682ecd  e9aefaffff           jmp 0x682980
// 00682ed2  8b442408             mov eax, dword ptr [esp + 8]
// 00682ed6  32c9                 xor cl, cl
// 00682ed8  c700c061b300         mov dword ptr [eax], 0xb361c0
// 00682ede  884804               mov byte ptr [eax + 4], cl
// 00682ee1  884805               mov byte ptr [eax + 5], cl
// 00682ee4  c3                   ret 

// 0xb361c0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b361c0[];
extern "C" void func_682980(int, int, int);

void func_00682ec0(int a, int b, int c)
{
    if (c != 4)
    {
        func_682980(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b361c0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
