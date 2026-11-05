// from server: 100% by nuck16
// roc 2009-12 00730d20  unit: G3D::$$A6AXVColor3::?$signal::slot  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00730d20
//
// 00730d20  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00730d24  83f804               cmp eax, 4
// 00730d27  7409                 je 0x730d32
// 00730d29  8944240c             mov dword ptr [esp + 0xc], eax
// 00730d2d  e92efeffff           jmp 0x730b60
// 00730d32  8b442408             mov eax, dword ptr [esp + 8]
// 00730d36  32c9                 xor cl, cl
// 00730d38  c7009010b500         mov dword ptr [eax], 0xb51090
// 00730d3e  884804               mov byte ptr [eax + 4], cl
// 00730d41  884805               mov byte ptr [eax + 5], cl
// 00730d44  c3                   ret 

// 0xb51090 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b51090[];
extern "C" void func_730b60(int, int, int);

void func_00730d20(int a, int b, int c)
{
    if (c != 4)
    {
        func_730b60(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b51090;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
