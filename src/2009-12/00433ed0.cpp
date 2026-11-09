// from server: 100% by nuck16
// roc 2009-12 00433ed0  unit: CPropGrid::UpdateItemsJob  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00433ed0
//
// 00433ed0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00433ed4  83f804               cmp eax, 4
// 00433ed7  7409                 je 0x433ee2
// 00433ed9  8944240c             mov dword ptr [esp + 0xc], eax
// 00433edd  e97ef1ffff           jmp 0x433060
// 00433ee2  8b442408             mov eax, dword ptr [esp + 8]
// 00433ee6  32c9                 xor cl, cl
// 00433ee8  c700a855b000         mov dword ptr [eax], 0xb055a8
// 00433eee  884804               mov byte ptr [eax + 4], cl
// 00433ef1  884805               mov byte ptr [eax + 5], cl
// 00433ef4  c3                   ret 

// 0xb055a8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b055a8[];
extern "C" void func_433060(int, int, int);

void func_00433ed0(int a, int b, int c)
{
    if (c != 4)
    {
        func_433060(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b055a8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
