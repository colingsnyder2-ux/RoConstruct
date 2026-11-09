// from server: 100% by nuck16
// roc 2009-12 007308e0  unit: G3D::$$A6AXVCoordinateFrame::?$signal::slot  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007308e0
//
// 007308e0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007308e4  83f804               cmp eax, 4
// 007308e7  7409                 je 0x7308f2
// 007308e9  8944240c             mov dword ptr [esp + 0xc], eax
// 007308ed  e94efeffff           jmp 0x730740
// 007308f2  8b442408             mov eax, dword ptr [esp + 8]
// 007308f6  32c9                 xor cl, cl
// 007308f8  c700c00db500         mov dword ptr [eax], 0xb50dc0
// 007308fe  884804               mov byte ptr [eax + 4], cl
// 00730901  884805               mov byte ptr [eax + 5], cl
// 00730904  c3                   ret 

// 0xb50dc0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b50dc0[];
extern "C" void func_730740(int, int, int);

void func_007308e0(int a, int b, int c)
{
    if (c != 4)
    {
        func_730740(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b50dc0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
