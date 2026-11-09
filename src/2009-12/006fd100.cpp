// from server: 100% by nuck16
// roc 2009-12 006fd100  unit: RBX::P8PartInstance::?$GetSetImpl  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006fd100
//
// 006fd100  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006fd104  83f804               cmp eax, 4
// 006fd107  7409                 je 0x6fd112
// 006fd109  8944240c             mov dword ptr [esp + 0xc], eax
// 006fd10d  e99efcffff           jmp 0x6fcdb0
// 006fd112  8b442408             mov eax, dword ptr [esp + 8]
// 006fd116  32c9                 xor cl, cl
// 006fd118  c700107bb400         mov dword ptr [eax], 0xb47b10
// 006fd11e  884804               mov byte ptr [eax + 4], cl
// 006fd121  884805               mov byte ptr [eax + 5], cl
// 006fd124  c3                   ret 

// 0xb47b10 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b47b10[];
extern "C" void func_6fcdb0(int, int, int);

void func_006fd100(int a, int b, int c)
{
    if (c != 4)
    {
        func_6fcdb0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b47b10;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
