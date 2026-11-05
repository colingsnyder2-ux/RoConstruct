// from server: 100% by nuck16
// roc 2009-12 0045ce80  unit: CRobloxReportView::CStatsItemRecord::CNameItem  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0045ce80
//
// 0045ce80  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0045ce84  83f804               cmp eax, 4
// 0045ce87  7409                 je 0x45ce92
// 0045ce89  8944240c             mov dword ptr [esp + 0xc], eax
// 0045ce8d  e93eeeffff           jmp 0x45bcd0
// 0045ce92  8b442408             mov eax, dword ptr [esp + 8]
// 0045ce96  32c9                 xor cl, cl
// 0045ce98  c700989eb000         mov dword ptr [eax], 0xb09e98
// 0045ce9e  884804               mov byte ptr [eax + 4], cl
// 0045cea1  884805               mov byte ptr [eax + 5], cl
// 0045cea4  c3                   ret 

// 0xb09e98 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b09e98[];
extern "C" void func_45bcd0(int, int, int);

void func_0045ce80(int a, int b, int c)
{
    if (c != 4)
    {
        func_45bcd0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b09e98;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
