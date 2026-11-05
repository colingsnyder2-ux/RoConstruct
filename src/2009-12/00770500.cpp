// from server: 100% by nuck16
// roc 2009-12 00770500  unit: RBX::VGuiImageButton::?$FactoryProduct  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00770500
//
// 00770500  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00770504  83f804               cmp eax, 4
// 00770507  7409                 je 0x770512
// 00770509  8944240c             mov dword ptr [esp + 0xc], eax
// 0077050d  e9defcffff           jmp 0x7701f0
// 00770512  8b442408             mov eax, dword ptr [esp + 8]
// 00770516  32c9                 xor cl, cl
// 00770518  c700d010b600         mov dword ptr [eax], 0xb610d0
// 0077051e  884804               mov byte ptr [eax + 4], cl
// 00770521  884805               mov byte ptr [eax + 5], cl
// 00770524  c3                   ret 

// 0xb610d0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b610d0[];
extern "C" void func_7701f0(int, int, int);

void func_00770500(int a, int b, int c)
{
    if (c != 4)
    {
        func_7701f0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b610d0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
