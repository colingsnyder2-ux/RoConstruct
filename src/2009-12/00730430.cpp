// from server: 100% by nuck16
// roc 2009-12 00730430  unit: G3D::$$A6AXVRay::?$signal::slot  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00730430
//
// 00730430  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00730434  83f804               cmp eax, 4
// 00730437  7409                 je 0x730442
// 00730439  8944240c             mov dword ptr [esp + 0xc], eax
// 0073043d  e94efeffff           jmp 0x730290
// 00730442  8b442408             mov eax, dword ptr [esp + 8]
// 00730446  32c9                 xor cl, cl
// 00730448  c700b00ab500         mov dword ptr [eax], 0xb50ab0
// 0073044e  884804               mov byte ptr [eax + 4], cl
// 00730451  884805               mov byte ptr [eax + 5], cl
// 00730454  c3                   ret 

// 0xb50ab0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b50ab0[];
extern "C" void func_730290(int, int, int);

void func_00730430(int a, int b, int c)
{
    if (c != 4)
    {
        func_730290(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b50ab0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
