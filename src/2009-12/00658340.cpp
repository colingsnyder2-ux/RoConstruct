// from server: 100% by nuck16
// roc 2009-12 00658340  unit: RBX::VBasicPartInstance::?$SeatImpl  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00658340
//
// 00658340  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00658344  83f804               cmp eax, 4
// 00658347  7409                 je 0x658352
// 00658349  8944240c             mov dword ptr [esp + 0xc], eax
// 0065834d  e9cefaffff           jmp 0x657e20
// 00658352  8b442408             mov eax, dword ptr [esp + 8]
// 00658356  32c9                 xor cl, cl
// 00658358  c70068f2b200         mov dword ptr [eax], 0xb2f268
// 0065835e  884804               mov byte ptr [eax + 4], cl
// 00658361  884805               mov byte ptr [eax + 5], cl
// 00658364  c3                   ret 

// 0xb2f268 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b2f268[];
extern "C" void func_657e20(int, int, int);

void func_00658340(int a, int b, int c)
{
    if (c != 4)
    {
        func_657e20(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b2f268;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
