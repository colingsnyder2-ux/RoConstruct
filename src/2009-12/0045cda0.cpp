// from server: 100% by nuck16
// roc 2009-12 0045cda0  unit: CRobloxReportView::CStatsItemRecord::CNameItem  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0045cda0
//
// 0045cda0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0045cda4  83f804               cmp eax, 4
// 0045cda7  7409                 je 0x45cdb2
// 0045cda9  8944240c             mov dword ptr [esp + 0xc], eax
// 0045cdad  e9aeeeffff           jmp 0x45bc60
// 0045cdb2  8b442408             mov eax, dword ptr [esp + 8]
// 0045cdb6  32c9                 xor cl, cl
// 0045cdb8  c700a89db000         mov dword ptr [eax], 0xb09da8
// 0045cdbe  884804               mov byte ptr [eax + 4], cl
// 0045cdc1  884805               mov byte ptr [eax + 5], cl
// 0045cdc4  c3                   ret 

// 0xb09da8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b09da8[];
extern "C" void func_45bc60(int, int, int);

void func_0045cda0(int a, int b, int c)
{
    if (c != 4)
    {
        func_45bc60(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b09da8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
