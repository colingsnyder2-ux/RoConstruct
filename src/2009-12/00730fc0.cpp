// from server: 100% by nuck16
// roc 2009-12 00730fc0  unit: G3D::$$A6AXVColor3::?$signal::slot  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00730fc0
//
// 00730fc0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00730fc4  83f804               cmp eax, 4
// 00730fc7  7409                 je 0x730fd2
// 00730fc9  8944240c             mov dword ptr [esp + 0xc], eax
// 00730fcd  e93efeffff           jmp 0x730e10
// 00730fd2  8b442408             mov eax, dword ptr [esp + 8]
// 00730fd6  32c9                 xor cl, cl
// 00730fd8  c700c012b500         mov dword ptr [eax], 0xb512c0
// 00730fde  884804               mov byte ptr [eax + 4], cl
// 00730fe1  884805               mov byte ptr [eax + 5], cl
// 00730fe4  c3                   ret 

// 0xb512c0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b512c0[];
extern "C" void func_730e10(int, int, int);

void func_00730fc0(int a, int b, int c)
{
    if (c != 4)
    {
        func_730e10(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b512c0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
