// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00552860  unit: RBX::RenderBase::AggregateChunk  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00552860
//
// 00552860  55                   push ebp
// 00552861  8bec                 mov ebp, esp
// 00552863  51                   push ecx
// 00552864  894dfc               mov dword ptr [ebp - 4], ecx
// 00552867  33c0                 xor eax, eax
// 00552869  75fc                 jne 0x552867
// 0055286b  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 0055286e  51                   push ecx
// 0055286f  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00552872  52                   push edx
// 00552873  6a02                 push 2
// 00552875  8b4508               mov eax, dword ptr [ebp + 8]
// 00552878  50                   push eax
// 00552879  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0055287c  e8cf8bf2ff           call 0x47b450
// 00552881  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00552884  e8a773f2ff           call 0x479c30
// 00552889  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0055288c  51                   push ecx
// 0055288d  8b5508               mov edx, dword ptr [ebp + 8]
// 00552890  52                   push edx
// 00552891  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00552894  e86756f2ff           call 0x477f00
// 00552899  8be5                 mov esp, ebp
// 0055289b  5d                   pop ebp
// 0055289c  c20c00               ret 0xc

struct S
{
    void func_00552860(int, int, int);
    void func_0047b450(int, int, int, int);
    void func_00479c30();
    void func_00477f00(int, int);
};

#pragma optimize("", off)
void S::func_00552860(int a, int b, int c)
{
    do {} while (0);
    func_0047b450(a, 2, b, c);
    func_00479c30();
    func_00477f00(a, b);
}
#pragma optimize("", on)
