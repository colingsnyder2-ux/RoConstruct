// from server: 100% by nuck16
// roc 2009-12 004208f0  unit: CRobloxTreeCtrlNode  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004208f0
//
// 004208f0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004208f4  83f804               cmp eax, 4
// 004208f7  7409                 je 0x420902
// 004208f9  8944240c             mov dword ptr [esp + 0xc], eax
// 004208fd  e98efeffff           jmp 0x420790
// 00420902  8b442408             mov eax, dword ptr [esp + 8]
// 00420906  32c9                 xor cl, cl
// 00420908  c7008842b000         mov dword ptr [eax], 0xb04288
// 0042090e  884804               mov byte ptr [eax + 4], cl
// 00420911  884805               mov byte ptr [eax + 5], cl
// 00420914  c3                   ret 

// 0xb04288 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b04288[];
extern "C" void func_420790(int, int, int);

void func_004208f0(int a, int b, int c)
{
    if (c != 4)
    {
        func_420790(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b04288;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
