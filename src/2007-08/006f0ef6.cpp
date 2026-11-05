// from server: 64% by colin
// roc 2007-08 006f0ef6  unit: CXTPImageEditorPicker  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006f0ef6

extern "C" unsigned long __stdcall GetLastError();
extern "C" void __stdcall SetLastError(unsigned long);

extern "C" void __stdcall sub_62FF38(int, int);

void __fastcall sub_6F0EF6(int edi, int ebx, int ebp_minus_20)
{
    if (edi != 2)
    {
        int esi = (ebx == 0) ? 1 : 0;
        int saved;
        if (esi != 0)
        {
            saved = (int)GetLastError();
        }
        else
        {
            saved = 0;
        }
        sub_62FF38(ebp_minus_20, 0);
        if (esi != 0)
        {
            SetLastError((unsigned long)saved);
        }
    }
}
