// from server: 100% by nuck16
// roc 2009-12 006582e0  unit: RBX::VBasicPartInstance::?$SeatImpl  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006582e0
//
// 006582e0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006582e4  83f804               cmp eax, 4
// 006582e7  7409                 je 0x6582f2
// 006582e9  8944240c             mov dword ptr [esp + 0xc], eax
// 006582ed  e9aefaffff           jmp 0x657da0
// 006582f2  8b442408             mov eax, dword ptr [esp + 8]
// 006582f6  32c9                 xor cl, cl
// 006582f8  c700b0f1b200         mov dword ptr [eax], 0xb2f1b0
// 006582fe  884804               mov byte ptr [eax + 4], cl
// 00658301  884805               mov byte ptr [eax + 5], cl
// 00658304  c3                   ret 

// 0xb2f1b0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b2f1b0[];
extern "C" void func_657da0(int, int, int);

void func_006582e0(int a, int b, int c)
{
    if (c != 4)
    {
        func_657da0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b2f1b0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
