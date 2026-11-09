// from server: 100% by nuck16
// roc 2009-12 00575350  unit: RBX::ViewRbxGfx  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00575350
//
// 00575350  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00575354  83f804               cmp eax, 4
// 00575357  7409                 je 0x575362
// 00575359  8944240c             mov dword ptr [esp + 0xc], eax
// 0057535d  e9befcffff           jmp 0x575020
// 00575362  8b442408             mov eax, dword ptr [esp + 8]
// 00575366  32c9                 xor cl, cl
// 00575368  c7003840b200         mov dword ptr [eax], 0xb24038
// 0057536e  884804               mov byte ptr [eax + 4], cl
// 00575371  884805               mov byte ptr [eax + 5], cl
// 00575374  c3                   ret 

// 0xb24038 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b24038[];
extern "C" void func_575020(int, int, int);

void func_00575350(int a, int b, int c)
{
    if (c != 4)
    {
        func_575020(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b24038;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
