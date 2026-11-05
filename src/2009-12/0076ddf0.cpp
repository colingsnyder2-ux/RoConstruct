// from server: 100% by nuck16
// roc 2009-12 0076ddf0  unit: RBX::VFrame::?$FactoryProduct  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0076ddf0
//
// 0076ddf0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0076ddf4  83f804               cmp eax, 4
// 0076ddf7  7409                 je 0x76de02
// 0076ddf9  8944240c             mov dword ptr [esp + 0xc], eax
// 0076ddfd  e96efaffff           jmp 0x76d870
// 0076de02  8b442408             mov eax, dword ptr [esp + 8]
// 0076de06  32c9                 xor cl, cl
// 0076de08  c7008009b600         mov dword ptr [eax], 0xb60980
// 0076de0e  884804               mov byte ptr [eax + 4], cl
// 0076de11  884805               mov byte ptr [eax + 5], cl
// 0076de14  c3                   ret 

// 0xb60980 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b60980[];
extern "C" void func_76d870(int, int, int);

void func_0076ddf0(int a, int b, int c)
{
    if (c != 4)
    {
        func_76d870(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b60980;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
