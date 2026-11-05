// from server: 100% by nuck16
// roc 2009-12 00635da0  unit: RBX::Reflection::PBVPropertyDescriptor::?$holder  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00635da0
//
// 00635da0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00635da4  83f804               cmp eax, 4
// 00635da7  7409                 je 0x635db2
// 00635da9  8944240c             mov dword ptr [esp + 0xc], eax
// 00635dad  e99efbffff           jmp 0x635950
// 00635db2  8b442408             mov eax, dword ptr [esp + 8]
// 00635db6  32c9                 xor cl, cl
// 00635db8  c70030a1b200         mov dword ptr [eax], 0xb2a130
// 00635dbe  884804               mov byte ptr [eax + 4], cl
// 00635dc1  884805               mov byte ptr [eax + 5], cl
// 00635dc4  c3                   ret 

// 0xb2a130 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b2a130[];
extern "C" void func_635950(int, int, int);

void func_00635da0(int a, int b, int c)
{
    if (c != 4)
    {
        func_635950(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b2a130;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
