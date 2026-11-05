// from server: 100% by nuck16
// roc 2009-12 00505660  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::?$signal::slot  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00505660
//
// 00505660  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00505664  83f804               cmp eax, 4
// 00505667  7409                 je 0x505672
// 00505669  8944240c             mov dword ptr [esp + 0xc], eax
// 0050566d  e93efeffff           jmp 0x5054b0
// 00505672  8b442408             mov eax, dword ptr [esp + 8]
// 00505676  32c9                 xor cl, cl
// 00505678  c7007853b100         mov dword ptr [eax], 0xb15378
// 0050567e  884804               mov byte ptr [eax + 4], cl
// 00505681  884805               mov byte ptr [eax + 5], cl
// 00505684  c3                   ret 

// 0xb15378 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b15378[];
extern "C" void func_5054b0(int, int, int);

void func_00505660(int a, int b, int c)
{
    if (c != 4)
    {
        func_5054b0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b15378;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
