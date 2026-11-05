// from server: 100% by nuck16
// roc 2009-12 0053bec0  unit: G3D::VRay::?$holder  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0053bec0
//
// 0053bec0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0053bec4  83f804               cmp eax, 4
// 0053bec7  7409                 je 0x53bed2
// 0053bec9  8944240c             mov dword ptr [esp + 0xc], eax
// 0053becd  e9cec1ffff           jmp 0x5380a0
// 0053bed2  8b442408             mov eax, dword ptr [esp + 8]
// 0053bed6  32c9                 xor cl, cl
// 0053bed8  c700b8dbb100         mov dword ptr [eax], 0xb1dbb8
// 0053bede  884804               mov byte ptr [eax + 4], cl
// 0053bee1  884805               mov byte ptr [eax + 5], cl
// 0053bee4  c3                   ret 

// 0xb1dbb8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b1dbb8[];
extern "C" void func_5380a0(int, int, int);

void func_0053bec0(int a, int b, int c)
{
    if (c != 4)
    {
        func_5380a0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b1dbb8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
