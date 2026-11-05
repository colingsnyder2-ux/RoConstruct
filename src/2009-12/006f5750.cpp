// from server: 100% by nuck16
// roc 2009-12 006f5750  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f5750
//
// 006f5750  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006f5754  83f804               cmp eax, 4
// 006f5757  7409                 je 0x6f5762
// 006f5759  8944240c             mov dword ptr [esp + 0xc], eax
// 006f575d  e95ef5ffff           jmp 0x6f4cc0
// 006f5762  8b442408             mov eax, dword ptr [esp + 8]
// 006f5766  32c9                 xor cl, cl
// 006f5768  c7003068b400         mov dword ptr [eax], 0xb46830
// 006f576e  884804               mov byte ptr [eax + 4], cl
// 006f5771  884805               mov byte ptr [eax + 5], cl
// 006f5774  c3                   ret 

// 0xb46830 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b46830[];
extern "C" void func_6f4cc0(int, int, int);

void func_006f5750(int a, int b, int c)
{
    if (c != 4)
    {
        func_6f4cc0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b46830;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
