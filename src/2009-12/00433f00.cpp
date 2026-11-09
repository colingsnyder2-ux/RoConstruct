// from server: 100% by nuck16
// roc 2009-12 00433f00  unit: CPropGrid::UpdateItemsJob  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00433f00
//
// 00433f00  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00433f04  83f804               cmp eax, 4
// 00433f07  7409                 je 0x433f12
// 00433f09  8944240c             mov dword ptr [esp + 0xc], eax
// 00433f0d  e9bef1ffff           jmp 0x4330d0
// 00433f12  8b442408             mov eax, dword ptr [esp + 8]
// 00433f16  32c9                 xor cl, cl
// 00433f18  c7005856b000         mov dword ptr [eax], 0xb05658
// 00433f1e  884804               mov byte ptr [eax + 4], cl
// 00433f21  884805               mov byte ptr [eax + 5], cl
// 00433f24  c3                   ret 

// 0xb05658 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b05658[];
extern "C" void func_4330d0(int, int, int);

void func_00433f00(int a, int b, int c)
{
    if (c != 4)
    {
        func_4330d0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b05658;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
