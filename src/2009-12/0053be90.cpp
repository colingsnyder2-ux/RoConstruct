// from server: 100% by nuck16
// roc 2009-12 0053be90  unit: G3D::VRay::?$holder  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0053be90
//
// 0053be90  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0053be94  83f804               cmp eax, 4
// 0053be97  7409                 je 0x53bea2
// 0053be99  8944240c             mov dword ptr [esp + 0xc], eax
// 0053be9d  e98ec1ffff           jmp 0x538030
// 0053bea2  8b442408             mov eax, dword ptr [esp + 8]
// 0053bea6  32c9                 xor cl, cl
// 0053bea8  c70050dbb100         mov dword ptr [eax], 0xb1db50
// 0053beae  884804               mov byte ptr [eax + 4], cl
// 0053beb1  884805               mov byte ptr [eax + 5], cl
// 0053beb4  c3                   ret 

// 0xb1db50 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b1db50[];
extern "C" void func_538030(int, int, int);

void func_0053be90(int a, int b, int c)
{
    if (c != 4)
    {
        func_538030(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b1db50;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
