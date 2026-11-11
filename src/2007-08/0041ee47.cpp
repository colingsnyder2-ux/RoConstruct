// from server: 72% by EspClaude
// from server: 70% by colin
// roc 2007-08 0041ee47  unit: CSettingsExplorer  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041ee47
//
// 0041ee47  83ff02               cmp edi, 2
// 0041ee4a  7430                 je 0x41ee7c
// 0041ee4c  33c0                 xor eax, eax
// 0041ee4e  83fbff               cmp ebx, -1
// 0041ee51  0f94c0               sete al
// 0041ee54  8bf0                 mov esi, eax
// 0041ee56  85f6                 test esi, esi
// 0041ee58  740a                 je 0x41ee64
// 0041ee5a  ff1500d37700         call dword ptr [0x77d300]
// 0041ee60  8bf8                 mov edi, eax
// 0041ee62  eb02                 jmp 0x41ee66
// 0041ee64  33ff                 xor edi, edi
// 0041ee66  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 0041ee69  51                   push ecx
// 0041ee6a  6a00                 push 0
// 0041ee6c  e8c7102100           call 0x62ff38
// 0041ee71  85f6                 test esi, esi
// 0041ee73  7407                 je 0x41ee7c
// 0041ee75  57                   push edi
// 0041ee76  ff1590d27700         call dword ptr [0x77d290]
// 0041ee7c  c3                   ret 

extern "C" unsigned long __stdcall GetLastError(void);
extern "C" void __stdcall SetLastError(unsigned long);

extern "C" void __stdcall sub_62FF38(unsigned long, unsigned long);

void __fastcall sub_41EE47(int edi, int ebx, int ebp_minus_20)
{
    if (edi == 2)
        return;

    unsigned long esi = (ebx == -1) ? 1 : 0;
    unsigned long edi_saved;
    if (esi != 0)
        edi_saved = GetLastError();
    else
        edi_saved = 0;

    sub_62FF38(0, ebp_minus_20);

    if (esi != 0)
        SetLastError(edi_saved);
}
