// from server: 72% by EspClaude
// from server: 71% by tajop
// roc 2007-08 00648e57  unit: CXTPCommandBar  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00648e57
//
// 00648e57  83ff02               cmp edi, 2
// 00648e5a  7430                 je 0x648e8c
// 00648e5c  33c0                 xor eax, eax
// 00648e5e  83fbff               cmp ebx, -1
// 00648e61  0f94c0               sete al
// 00648e64  8bf0                 mov esi, eax
// 00648e66  85f6                 test esi, esi
// 00648e68  740a                 je 0x648e74
// 00648e6a  ff1500d37700         call dword ptr [0x77d300]
// 00648e70  8bf8                 mov edi, eax
// 00648e72  eb02                 jmp 0x648e76
// 00648e74  33ff                 xor edi, edi
// 00648e76  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 00648e79  51                   push ecx
// 00648e7a  6a00                 push 0
// 00648e7c  e8b770feff           call 0x62ff38
// 00648e81  85f6                 test esi, esi
// 00648e83  7407                 je 0x648e8c
// 00648e85  57                   push edi
// 00648e86  ff1590d27700         call dword ptr [0x77d290]
// 00648e8c  c3                   ret 


extern "C" unsigned long __stdcall GetLastError(void);
extern "C" void __stdcall SetLastError(unsigned long);

extern "C" void __stdcall sub_62FF38(unsigned long, unsigned long);

void __fastcall sub_648E57(int edi, int ebx, int ebp_minus_20)
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
