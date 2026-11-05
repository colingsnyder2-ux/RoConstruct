// from server: 100% by nuck16
// roc 2009-12 0046e420  unit: CScriptDoc  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0046e420
//
// 0046e420  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0046e424  83f804               cmp eax, 4
// 0046e427  7409                 je 0x46e432
// 0046e429  8944240c             mov dword ptr [esp + 0xc], eax
// 0046e42d  e9befaffff           jmp 0x46def0
// 0046e432  8b442408             mov eax, dword ptr [esp + 8]
// 0046e436  32c9                 xor cl, cl
// 0046e438  c70098b6b000         mov dword ptr [eax], 0xb0b698
// 0046e43e  884804               mov byte ptr [eax + 4], cl
// 0046e441  884805               mov byte ptr [eax + 5], cl
// 0046e444  c3                   ret 

// 0xb0b698 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b0b698[];
extern "C" void func_46def0(int, int, int);

void func_0046e420(int a, int b, int c)
{
    if (c != 4)
    {
        func_46def0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b0b698;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
