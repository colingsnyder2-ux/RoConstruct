// from server: 100% by nuck16
// roc 2009-12 00682e90  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00682e90
//
// 00682e90  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00682e94  83f804               cmp eax, 4
// 00682e97  7409                 je 0x682ea2
// 00682e99  8944240c             mov dword ptr [esp + 0xc], eax
// 00682e9d  e96efaffff           jmp 0x682910
// 00682ea2  8b442408             mov eax, dword ptr [esp + 8]
// 00682ea6  32c9                 xor cl, cl
// 00682ea8  c700f860b300         mov dword ptr [eax], 0xb360f8
// 00682eae  884804               mov byte ptr [eax + 4], cl
// 00682eb1  884805               mov byte ptr [eax + 5], cl
// 00682eb4  c3                   ret 

// 0xb360f8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b360f8[];
extern "C" void func_682910(int, int, int);

void func_00682e90(int a, int b, int c)
{
    if (c != 4)
    {
        func_682910(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b360f8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
