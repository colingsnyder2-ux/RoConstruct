// from server: 100% by nuck16
// roc 2009-12 0076dd00  unit: RBX::VFrame::?$FactoryProduct  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0076dd00
//
// 0076dd00  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0076dd04  83f804               cmp eax, 4
// 0076dd07  7409                 je 0x76dd12
// 0076dd09  8944240c             mov dword ptr [esp + 0xc], eax
// 0076dd0d  e94ef5ffff           jmp 0x76d260
// 0076dd12  8b442408             mov eax, dword ptr [esp + 8]
// 0076dd16  32c9                 xor cl, cl
// 0076dd18  c70028ffb500         mov dword ptr [eax], 0xb5ff28
// 0076dd1e  884804               mov byte ptr [eax + 4], cl
// 0076dd21  884805               mov byte ptr [eax + 5], cl
// 0076dd24  c3                   ret 

// 0xb5ff28 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b5ff28[];
extern "C" void func_76d260(int, int, int);

void func_0076dd00(int a, int b, int c)
{
    if (c != 4)
    {
        func_76d260(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b5ff28;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
