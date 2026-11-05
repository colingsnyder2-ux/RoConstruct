// from server: 100% by nuck16
// roc 2009-12 00697860  unit: RBX::VIAdornableCollector::?$sp_counted_impl_p  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00697860
//
// 00697860  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00697864  83f804               cmp eax, 4
// 00697867  7409                 je 0x697872
// 00697869  8944240c             mov dword ptr [esp + 0xc], eax
// 0069786d  e99eecffff           jmp 0x696510
// 00697872  8b442408             mov eax, dword ptr [esp + 8]
// 00697876  32c9                 xor cl, cl
// 00697878  c700708db300         mov dword ptr [eax], 0xb38d70
// 0069787e  884804               mov byte ptr [eax + 4], cl
// 00697881  884805               mov byte ptr [eax + 5], cl
// 00697884  c3                   ret 

// 0xb38d70 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b38d70[];
extern "C" void func_696510(int, int, int);

void func_00697860(int a, int b, int c)
{
    if (c != 4)
    {
        func_696510(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b38d70;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
