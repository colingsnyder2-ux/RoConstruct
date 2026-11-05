// from server: 100% by nuck16
// roc 2009-12 00509490  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::?$signal::slot  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00509490
//
// 00509490  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00509494  83f804               cmp eax, 4
// 00509497  7409                 je 0x5094a2
// 00509499  8944240c             mov dword ptr [esp + 0xc], eax
// 0050949d  e91ed9ffff           jmp 0x506dc0
// 005094a2  8b442408             mov eax, dword ptr [esp + 8]
// 005094a6  32c9                 xor cl, cl
// 005094a8  c700905ab100         mov dword ptr [eax], 0xb15a90
// 005094ae  884804               mov byte ptr [eax + 4], cl
// 005094b1  884805               mov byte ptr [eax + 5], cl
// 005094b4  c3                   ret 

// 0xb15a90 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b15a90[];
extern "C" void func_506dc0(int, int, int);

void func_00509490(int a, int b, int c)
{
    if (c != 4)
    {
        func_506dc0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b15a90;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
