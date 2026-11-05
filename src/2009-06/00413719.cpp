// from server: 70% by atomic.potato
extern "C" unsigned long __stdcall GetLastError();
extern "C" void __stdcall SetLastError(unsigned long);

void __cdecl sub_718CFC(unsigned long, unsigned long);

void __fastcall sub_413719(int edi, int ebx)
{
    if (edi == 2)
        return;

    int esi = (ebx == -1) ? 1 : 0;

    int saved;
    if (esi) {
        saved = (int)GetLastError();
    } else {
        saved = 0;
    }

    sub_718CFC(0, *(unsigned long *)((char *)0 + 0));

    if (esi) {
        SetLastError((unsigned long)saved);
    }
}
