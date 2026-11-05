// from server: 100% by nuck16
// roc 2009-12 006a51a0  unit: RBX::VScriptContext::?$FactoryProduct  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006a51a0
//
// 006a51a0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006a51a4  83f804               cmp eax, 4
// 006a51a7  7409                 je 0x6a51b2
// 006a51a9  8944240c             mov dword ptr [esp + 0xc], eax
// 006a51ad  e9aef5ffff           jmp 0x6a4760
// 006a51b2  8b442408             mov eax, dword ptr [esp + 8]
// 006a51b6  32c9                 xor cl, cl
// 006a51b8  c700589db300         mov dword ptr [eax], 0xb39d58
// 006a51be  884804               mov byte ptr [eax + 4], cl
// 006a51c1  884805               mov byte ptr [eax + 5], cl
// 006a51c4  c3                   ret 

// 0xb39d58 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b39d58[];
extern "C" void func_6a4760(int, int, int);

void func_006a51a0(int a, int b, int c)
{
    if (c != 4)
    {
        func_6a4760(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b39d58;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
