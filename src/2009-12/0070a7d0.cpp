// from server: 100% by nuck16
// roc 2009-12 0070a7d0  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::?$signal::slot  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0070a7d0
//
// 0070a7d0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0070a7d4  83f804               cmp eax, 4
// 0070a7d7  7409                 je 0x70a7e2
// 0070a7d9  8944240c             mov dword ptr [esp + 0xc], eax
// 0070a7dd  e99ef8ffff           jmp 0x70a080
// 0070a7e2  8b442408             mov eax, dword ptr [esp + 8]
// 0070a7e6  32c9                 xor cl, cl
// 0070a7e8  c70018a0b400         mov dword ptr [eax], 0xb4a018
// 0070a7ee  884804               mov byte ptr [eax + 4], cl
// 0070a7f1  884805               mov byte ptr [eax + 5], cl
// 0070a7f4  c3                   ret 

// 0xb4a018 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b4a018[];
extern "C" void func_70a080(int, int, int);

void func_0070a7d0(int a, int b, int c)
{
    if (c != 4)
    {
        func_70a080(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b4a018;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
