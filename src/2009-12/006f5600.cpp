// from server: 100% by nuck16
// roc 2009-12 006f5600  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f5600
//
// 006f5600  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006f5604  83f804               cmp eax, 4
// 006f5607  7409                 je 0x6f5612
// 006f5609  8944240c             mov dword ptr [esp + 0xc], eax
// 006f560d  e96ef2ffff           jmp 0x6f4880
// 006f5612  8b442408             mov eax, dword ptr [esp + 8]
// 006f5616  32c9                 xor cl, cl
// 006f5618  c700b85cb400         mov dword ptr [eax], 0xb45cb8
// 006f561e  884804               mov byte ptr [eax + 4], cl
// 006f5621  884805               mov byte ptr [eax + 5], cl
// 006f5624  c3                   ret 

// 0xb45cb8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b45cb8[];
extern "C" void func_6f4880(int, int, int);

void func_006f5600(int a, int b, int c)
{
    if (c != 4)
    {
        func_6f4880(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b45cb8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
