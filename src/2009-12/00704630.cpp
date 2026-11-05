// from server: 100% by nuck16
// roc 2009-12 00704630  unit: RBX::Reflection::VValue::$$CBV?$vector::V?$shared_ptr::?$holder  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00704630
//
// 00704630  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00704634  83f804               cmp eax, 4
// 00704637  7409                 je 0x704642
// 00704639  8944240c             mov dword ptr [esp + 0xc], eax
// 0070463d  e91ee8ffff           jmp 0x702e60
// 00704642  8b442408             mov eax, dword ptr [esp + 8]
// 00704646  32c9                 xor cl, cl
// 00704648  c7005091b400         mov dword ptr [eax], 0xb49150
// 0070464e  884804               mov byte ptr [eax + 4], cl
// 00704651  884805               mov byte ptr [eax + 5], cl
// 00704654  c3                   ret 

// 0xb49150 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b49150[];
extern "C" void func_702e60(int, int, int);

void func_00704630(int a, int b, int c)
{
    if (c != 4)
    {
        func_702e60(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b49150;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
