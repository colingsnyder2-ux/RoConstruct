// from server: 100% by nuck16
// roc 2009-12 006f5720  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f5720
//
// 006f5720  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006f5724  83f804               cmp eax, 4
// 006f5727  7409                 je 0x6f5732
// 006f5729  8944240c             mov dword ptr [esp + 0xc], eax
// 006f572d  e91ef5ffff           jmp 0x6f4c50
// 006f5732  8b442408             mov eax, dword ptr [esp + 8]
// 006f5736  32c9                 xor cl, cl
// 006f5738  c700d066b400         mov dword ptr [eax], 0xb466d0
// 006f573e  884804               mov byte ptr [eax + 4], cl
// 006f5741  884805               mov byte ptr [eax + 5], cl
// 006f5744  c3                   ret 

// 0xb466d0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b466d0[];
extern "C" void func_6f4c50(int, int, int);

void func_006f5720(int a, int b, int c)
{
    if (c != 4)
    {
        func_6f4c50(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b466d0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
