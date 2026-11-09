// from server: 100% by nuck16
// roc 2009-12 007496d0  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007496d0
//
// 007496d0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007496d4  83f804               cmp eax, 4
// 007496d7  7409                 je 0x7496e2
// 007496d9  8944240c             mov dword ptr [esp + 0xc], eax
// 007496dd  e93efeffff           jmp 0x749520
// 007496e2  8b442408             mov eax, dword ptr [esp + 8]
// 007496e6  32c9                 xor cl, cl
// 007496e8  c7006879b500         mov dword ptr [eax], 0xb57968
// 007496ee  884804               mov byte ptr [eax + 4], cl
// 007496f1  884805               mov byte ptr [eax + 5], cl
// 007496f4  c3                   ret 

// 0xb57968 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b57968[];
extern "C" void func_749520(int, int, int);

void func_007496d0(int a, int b, int c)
{
    if (c != 4)
    {
        func_749520(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b57968;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
