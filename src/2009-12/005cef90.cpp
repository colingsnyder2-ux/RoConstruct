// from server: 100% by nuck16
// roc 2009-12 005cef90  unit: RBX::PartChunk  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005cef90
//
// 005cef90  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005cef94  83f804               cmp eax, 4
// 005cef97  7409                 je 0x5cefa2
// 005cef99  8944240c             mov dword ptr [esp + 0xc], eax
// 005cef9d  e9ded8ffff           jmp 0x5cc880
// 005cefa2  8b442408             mov eax, dword ptr [esp + 8]
// 005cefa6  32c9                 xor cl, cl
// 005cefa8  c700f05cb200         mov dword ptr [eax], 0xb25cf0
// 005cefae  884804               mov byte ptr [eax + 4], cl
// 005cefb1  884805               mov byte ptr [eax + 5], cl
// 005cefb4  c3                   ret 

// 0xb25cf0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b25cf0[];
extern "C" void func_5cc880(int, int, int);

void func_005cef90(int a, int b, int c)
{
    if (c != 4)
    {
        func_5cc880(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b25cf0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
