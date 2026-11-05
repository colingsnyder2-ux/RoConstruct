// from server: 100% by nuck16
// from server: 94% by atomic.potato
// roc 2009-12 00635d70  unit: RBX::Reflection::PBVPropertyDescriptor::?$holder  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00635d70
//
// 00635d70  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00635d74  83f804               cmp eax, 4
// 00635d77  7409                 je 0x635d82
// 00635d79  8944240c             mov dword ptr [esp + 0xc], eax
// 00635d7d  e9bef8ffff           jmp 0x635640
// 00635d82  8b442408             mov eax, dword ptr [esp + 8]
// 00635d86  32c9                 xor cl, cl
// 00635d88  c700609eb200         mov dword ptr [eax], 0xb29e60
// 00635d8e  884804               mov byte ptr [eax + 4], cl
// 00635d91  884805               mov byte ptr [eax + 5], cl
// 00635d94  c3                   ret 

// 0xb29e60 is the RTTI type descriptor of the stored boost::bind_t functor (functor_manager type tag)
extern "C" const char type_descriptor_b29e60[];
extern "C" void func_00635640(int, int, int);

void func_00635d70(int a, int b, int c)
{
    if (c != 4)
    {
        func_00635640(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b29e60;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
