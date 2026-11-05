// from server: 100% by nuck16
// roc 2009-12 006f5690  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f5690
//
// 006f5690  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006f5694  83f804               cmp eax, 4
// 006f5697  7409                 je 0x6f56a2
// 006f5699  8944240c             mov dword ptr [esp + 0xc], eax
// 006f569d  e92ef3ffff           jmp 0x6f49d0
// 006f56a2  8b442408             mov eax, dword ptr [esp + 8]
// 006f56a6  32c9                 xor cl, cl
// 006f56a8  c700c05fb400         mov dword ptr [eax], 0xb45fc0
// 006f56ae  884804               mov byte ptr [eax + 4], cl
// 006f56b1  884805               mov byte ptr [eax + 5], cl
// 006f56b4  c3                   ret 

// 0xb45fc0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b45fc0[];
extern "C" void func_6f49d0(int, int, int);

void func_006f5690(int a, int b, int c)
{
    if (c != 4)
    {
        func_6f49d0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b45fc0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
