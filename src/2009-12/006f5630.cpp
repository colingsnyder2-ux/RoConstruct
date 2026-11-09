// from server: 100% by nuck16
// roc 2009-12 006f5630  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f5630
//
// 006f5630  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006f5634  83f804               cmp eax, 4
// 006f5637  7409                 je 0x6f5642
// 006f5639  8944240c             mov dword ptr [esp + 0xc], eax
// 006f563d  e9aef2ffff           jmp 0x6f48f0
// 006f5642  8b442408             mov eax, dword ptr [esp + 8]
// 006f5646  32c9                 xor cl, cl
// 006f5648  c700985db400         mov dword ptr [eax], 0xb45d98
// 006f564e  884804               mov byte ptr [eax + 4], cl
// 006f5651  884805               mov byte ptr [eax + 5], cl
// 006f5654  c3                   ret 

// 0xb45d98 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b45d98[];
extern "C" void func_6f48f0(int, int, int);

void func_006f5630(int a, int b, int c)
{
    if (c != 4)
    {
        func_6f48f0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b45d98;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
