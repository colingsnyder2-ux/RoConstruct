// from server: 100% by nuck16
// roc 2009-12 00542a50  unit: RBX::VMotor::?$FactoryProduct::Creator  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00542a50
//
// 00542a50  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00542a54  83f804               cmp eax, 4
// 00542a57  7409                 je 0x542a62
// 00542a59  8944240c             mov dword ptr [esp + 0xc], eax
// 00542a5d  e97eccffff           jmp 0x53f6e0
// 00542a62  8b442408             mov eax, dword ptr [esp + 8]
// 00542a66  32c9                 xor cl, cl
// 00542a68  c70070e1b100         mov dword ptr [eax], 0xb1e170
// 00542a6e  884804               mov byte ptr [eax + 4], cl
// 00542a71  884805               mov byte ptr [eax + 5], cl
// 00542a74  c3                   ret 

// 0xb1e170 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b1e170[];
extern "C" void func_53f6e0(int, int, int);

void func_00542a50(int a, int b, int c)
{
    if (c != 4)
    {
        func_53f6e0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b1e170;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
