// from server: 100% by nuck16
// roc 2009-12 0041e6b0  unit: CSelectionTreeCtrl  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041e6b0
//
// 0041e6b0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041e6b4  83f804               cmp eax, 4
// 0041e6b7  7409                 je 0x41e6c2
// 0041e6b9  8944240c             mov dword ptr [esp + 0xc], eax
// 0041e6bd  e9eef1ffff           jmp 0x41d8b0
// 0041e6c2  8b442408             mov eax, dword ptr [esp + 8]
// 0041e6c6  32c9                 xor cl, cl
// 0041e6c8  c7002840b000         mov dword ptr [eax], 0xb04028
// 0041e6ce  884804               mov byte ptr [eax + 4], cl
// 0041e6d1  884805               mov byte ptr [eax + 5], cl
// 0041e6d4  c3                   ret 

// 0xb04028 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b04028[];
extern "C" void func_41d8b0(int, int, int);

void func_0041e6b0(int a, int b, int c)
{
    if (c != 4)
    {
        func_41d8b0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b04028;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
