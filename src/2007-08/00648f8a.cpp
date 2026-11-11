// from server: 72% by EspClaude
// from server: 70% by colin
// roc 2007-08 00648f8a  unit: CXTPCommandBar  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00648f8a
//
// 00648f8a  83ff02               cmp edi, 2
// 00648f8d  742f                 je 0x648fbe
// 00648f8f  33c0                 xor eax, eax
// 00648f91  85db                 test ebx, ebx
// 00648f93  0f94c0               sete al
// 00648f96  8bf0                 mov esi, eax
// 00648f98  85f6                 test esi, esi
// 00648f9a  740a                 je 0x648fa6
// 00648f9c  ff1500d37700         call dword ptr [0x77d300]
// 00648fa2  8bf8                 mov edi, eax
// 00648fa4  eb02                 jmp 0x648fa8
// 00648fa6  33ff                 xor edi, edi
// 00648fa8  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 00648fab  51                   push ecx
// 00648fac  6a00                 push 0
// 00648fae  e8856ffeff           call 0x62ff38
// 00648fb3  85f6                 test esi, esi
// 00648fb5  7407                 je 0x648fbe
// 00648fb7  57                   push edi
// 00648fb8  ff1590d27700         call dword ptr [0x77d290]
// 00648fbe  c3                   ret 

extern "C" unsigned long __stdcall GetLastError();
extern "C" void __stdcall SetLastError(unsigned long);

extern "C" void __stdcall sub_62FF38(int, int);

void __fastcall sub_648F8A(int edi, int ebx, int ebp_minus_20)
{
    if (edi == 2)
        return;

    int esi = (ebx == 0) ? 1 : 0;
    int saved;
    if (esi) {
        saved = (int)GetLastError();
    } else {
        saved = 0;
    }

    sub_62FF38(0, ebp_minus_20);

    if (esi) {
        SetLastError((unsigned long)saved);
    }
}
