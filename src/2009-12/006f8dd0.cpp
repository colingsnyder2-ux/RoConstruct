// from server: 100% by nuck16
// roc 2009-12 006f8dd0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f8dd0
//
// 006f8dd0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006f8dd4  83f804               cmp eax, 4
// 006f8dd7  7409                 je 0x6f8de2
// 006f8dd9  8944240c             mov dword ptr [esp + 0xc], eax
// 006f8ddd  e91ee8ffff           jmp 0x6f7600
// 006f8de2  8b442408             mov eax, dword ptr [esp + 8]
// 006f8de6  32c9                 xor cl, cl
// 006f8de8  c700c06ab400         mov dword ptr [eax], 0xb46ac0
// 006f8dee  884804               mov byte ptr [eax + 4], cl
// 006f8df1  884805               mov byte ptr [eax + 5], cl
// 006f8df4  c3                   ret 

// 0xb46ac0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b46ac0[];
extern "C" void func_6f7600(int, int, int);

void func_006f8dd0(int a, int b, int c)
{
    if (c != 4)
    {
        func_6f7600(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b46ac0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
