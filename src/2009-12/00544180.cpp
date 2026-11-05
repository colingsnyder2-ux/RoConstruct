// from server: 100% by nuck16
// roc 2009-12 00544180  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::?$signal::slot  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00544180
//
// 00544180  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00544184  83f804               cmp eax, 4
// 00544187  7409                 je 0x544192
// 00544189  8944240c             mov dword ptr [esp + 0xc], eax
// 0054418d  e91efbffff           jmp 0x543cb0
// 00544192  8b442408             mov eax, dword ptr [esp + 8]
// 00544196  32c9                 xor cl, cl
// 00544198  c700a0edb100         mov dword ptr [eax], 0xb1eda0
// 0054419e  884804               mov byte ptr [eax + 4], cl
// 005441a1  884805               mov byte ptr [eax + 5], cl
// 005441a4  c3                   ret 

// 0xb1eda0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b1eda0[];
extern "C" void func_543cb0(int, int, int);

void func_00544180(int a, int b, int c)
{
    if (c != 4)
    {
        func_543cb0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b1eda0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
