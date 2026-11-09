// from server: 100% by nuck16
// roc 2009-12 005de020  unit: RBX::ViewG3D  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005de020
//
// 005de020  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005de024  83f804               cmp eax, 4
// 005de027  7409                 je 0x5de032
// 005de029  8944240c             mov dword ptr [esp + 0xc], eax
// 005de02d  e90efdffff           jmp 0x5ddd40
// 005de032  8b442408             mov eax, dword ptr [esp + 8]
// 005de036  32c9                 xor cl, cl
// 005de038  c7005864b200         mov dword ptr [eax], 0xb26458
// 005de03e  884804               mov byte ptr [eax + 4], cl
// 005de041  884805               mov byte ptr [eax + 5], cl
// 005de044  c3                   ret 

// 0xb26458 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b26458[];
extern "C" void func_5ddd40(int, int, int);

void func_005de020(int a, int b, int c)
{
    if (c != 4)
    {
        func_5ddd40(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b26458;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
