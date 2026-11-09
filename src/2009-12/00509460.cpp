// from server: 100% by nuck16
// roc 2009-12 00509460  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::?$signal::slot  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00509460
//
// 00509460  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00509464  83f804               cmp eax, 4
// 00509467  7409                 je 0x509472
// 00509469  8944240c             mov dword ptr [esp + 0xc], eax
// 0050946d  e92ebaffff           jmp 0x504ea0
// 00509472  8b442408             mov eax, dword ptr [esp + 8]
// 00509476  32c9                 xor cl, cl
// 00509478  c700e050b100         mov dword ptr [eax], 0xb150e0
// 0050947e  884804               mov byte ptr [eax + 4], cl
// 00509481  884805               mov byte ptr [eax + 5], cl
// 00509484  c3                   ret 

// 0xb150e0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b150e0[];
extern "C" void func_504ea0(int, int, int);

void func_00509460(int a, int b, int c)
{
    if (c != 4)
    {
        func_504ea0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b150e0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
