// from server: 100% by nuck16
// roc 2009-12 0041e680  unit: CSelectionTreeCtrl  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041e680
//
// 0041e680  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041e684  83f804               cmp eax, 4
// 0041e687  7409                 je 0x41e692
// 0041e689  8944240c             mov dword ptr [esp + 0xc], eax
// 0041e68d  e9aef1ffff           jmp 0x41d840
// 0041e692  8b442408             mov eax, dword ptr [esp + 8]
// 0041e696  32c9                 xor cl, cl
// 0041e698  c700683fb000         mov dword ptr [eax], 0xb03f68
// 0041e69e  884804               mov byte ptr [eax + 4], cl
// 0041e6a1  884805               mov byte ptr [eax + 5], cl
// 0041e6a4  c3                   ret 

// 0xb03f68 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b03f68[];
extern "C" void func_41d840(int, int, int);

void func_0041e680(int a, int b, int c)
{
    if (c != 4)
    {
        func_41d840(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b03f68;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
