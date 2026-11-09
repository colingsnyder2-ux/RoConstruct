// from server: 100% by nuck16
// roc 2009-12 0074d710  unit: RBX::VArcHandles::?$FactoryProduct  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0074d710
//
// 0074d710  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0074d714  83f804               cmp eax, 4
// 0074d717  7409                 je 0x74d722
// 0074d719  8944240c             mov dword ptr [esp + 0xc], eax
// 0074d71d  e95efcffff           jmp 0x74d380
// 0074d722  8b442408             mov eax, dword ptr [esp + 8]
// 0074d726  32c9                 xor cl, cl
// 0074d728  c700d08bb500         mov dword ptr [eax], 0xb58bd0
// 0074d72e  884804               mov byte ptr [eax + 4], cl
// 0074d731  884805               mov byte ptr [eax + 5], cl
// 0074d734  c3                   ret 

// 0xb58bd0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b58bd0[];
extern "C" void func_74d380(int, int, int);

void func_0074d710(int a, int b, int c)
{
    if (c != 4)
    {
        func_74d380(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b58bd0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
