// from server: 100% by nuck16
// roc 2009-12 005094c0  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::?$signal::slot  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005094c0
//
// 005094c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005094c4  83f804               cmp eax, 4
// 005094c7  7409                 je 0x5094d2
// 005094c9  8944240c             mov dword ptr [esp + 0xc], eax
// 005094cd  e9eedfffff           jmp 0x5074c0
// 005094d2  8b442408             mov eax, dword ptr [esp + 8]
// 005094d6  32c9                 xor cl, cl
// 005094d8  c700f05eb100         mov dword ptr [eax], 0xb15ef0
// 005094de  884804               mov byte ptr [eax + 4], cl
// 005094e1  884805               mov byte ptr [eax + 5], cl
// 005094e4  c3                   ret 

// 0xb15ef0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b15ef0[];
extern "C" void func_5074c0(int, int, int);

void func_005094c0(int a, int b, int c)
{
    if (c != 4)
    {
        func_5074c0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b15ef0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
