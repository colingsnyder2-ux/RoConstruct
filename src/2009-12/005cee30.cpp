// from server: 100% by nuck16
// roc 2009-12 005cee30  unit: RBX::PartChunk  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005cee30
//
// 005cee30  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005cee34  83f804               cmp eax, 4
// 005cee37  7409                 je 0x5cee42
// 005cee39  8944240c             mov dword ptr [esp + 0xc], eax
// 005cee3d  e95ed9ffff           jmp 0x5cc7a0
// 005cee42  8b442408             mov eax, dword ptr [esp + 8]
// 005cee46  32c9                 xor cl, cl
// 005cee48  c700a85bb200         mov dword ptr [eax], 0xb25ba8
// 005cee4e  884804               mov byte ptr [eax + 4], cl
// 005cee51  884805               mov byte ptr [eax + 5], cl
// 005cee54  c3                   ret 

// 0xb25ba8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b25ba8[];
extern "C" void func_5cc7a0(int, int, int);

void func_005cee30(int a, int b, int c)
{
    if (c != 4)
    {
        func_5cc7a0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b25ba8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
