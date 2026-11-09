// from server: 100% by nuck16
// roc 2009-12 006f5660  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f5660
//
// 006f5660  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006f5664  83f804               cmp eax, 4
// 006f5667  7409                 je 0x6f5672
// 006f5669  8944240c             mov dword ptr [esp + 0xc], eax
// 006f566d  e9eef2ffff           jmp 0x6f4960
// 006f5672  8b442408             mov eax, dword ptr [esp + 8]
// 006f5676  32c9                 xor cl, cl
// 006f5678  c700f05eb400         mov dword ptr [eax], 0xb45ef0
// 006f567e  884804               mov byte ptr [eax + 4], cl
// 006f5681  884805               mov byte ptr [eax + 5], cl
// 006f5684  c3                   ret 

// 0xb45ef0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b45ef0[];
extern "C" void func_6f4960(int, int, int);

void func_006f5660(int a, int b, int c)
{
    if (c != 4)
    {
        func_6f4960(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b45ef0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
