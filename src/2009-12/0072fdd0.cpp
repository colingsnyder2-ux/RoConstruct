// from server: 100% by nuck16
// roc 2009-12 0072fdd0  unit: G3D::$$A6AXVVector3::?$signal::slot  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0072fdd0
//
// 0072fdd0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0072fdd4  83f804               cmp eax, 4
// 0072fdd7  7409                 je 0x72fde2
// 0072fdd9  8944240c             mov dword ptr [esp + 0xc], eax
// 0072fddd  e92efeffff           jmp 0x72fc10
// 0072fde2  8b442408             mov eax, dword ptr [esp + 8]
// 0072fde6  32c9                 xor cl, cl
// 0072fde8  c7000808b500         mov dword ptr [eax], 0xb50808
// 0072fdee  884804               mov byte ptr [eax + 4], cl
// 0072fdf1  884805               mov byte ptr [eax + 5], cl
// 0072fdf4  c3                   ret 

// 0xb50808 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b50808[];
extern "C" void func_72fc10(int, int, int);

void func_0072fdd0(int a, int b, int c)
{
    if (c != 4)
    {
        func_72fc10(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b50808;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
