// from server: 100% by nuck16
// roc 2009-12 007190d0  unit: RBX::VProtectedString::?$TypedPropertyDescriptor  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007190d0
//
// 007190d0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007190d4  83f804               cmp eax, 4
// 007190d7  7409                 je 0x7190e2
// 007190d9  8944240c             mov dword ptr [esp + 0xc], eax
// 007190dd  e96efeffff           jmp 0x718f50
// 007190e2  8b442408             mov eax, dword ptr [esp + 8]
// 007190e6  32c9                 xor cl, cl
// 007190e8  c700d8d2b400         mov dword ptr [eax], 0xb4d2d8
// 007190ee  884804               mov byte ptr [eax + 4], cl
// 007190f1  884805               mov byte ptr [eax + 5], cl
// 007190f4  c3                   ret 

// 0xb4d2d8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b4d2d8[];
extern "C" void func_718f50(int, int, int);

void func_007190d0(int a, int b, int c)
{
    if (c != 4)
    {
        func_718f50(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b4d2d8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
