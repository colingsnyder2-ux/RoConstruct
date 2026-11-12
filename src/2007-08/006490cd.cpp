// from server: 72% by EspClaude
// from server: 67% by colin
// roc 2007-08 006490cd  unit: CXTPCommandBar  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006490cd
//
// 006490cd  83ff02               cmp edi, 2
// 006490d0  742f                 je 0x649101
// 006490d2  33c0                 xor eax, eax
// 006490d4  85db                 test ebx, ebx
// 006490d6  0f94c0               sete al
// 006490d9  8bf0                 mov esi, eax
// 006490db  85f6                 test esi, esi
// 006490dd  740a                 je 0x6490e9
// 006490df  ff1500d37700         call dword ptr [0x77d300]
// 006490e5  8bf8                 mov edi, eax
// 006490e7  eb02                 jmp 0x6490eb
// 006490e9  33ff                 xor edi, edi
// 006490eb  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 006490ee  51                   push ecx
// 006490ef  6a00                 push 0
// 006490f1  e8426efeff           call 0x62ff38
// 006490f6  85f6                 test esi, esi
// 006490f8  7407                 je 0x649101
// 006490fa  57                   push edi
// 006490fb  ff1590d27700         call dword ptr [0x77d290]
// 00649101  c3                   ret 

extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();
extern "C" __declspec(dllimport) void __stdcall SetLastError(unsigned long);

extern "C" void __stdcall func_0062ff38(int, int);

void __fastcall func_006490cd(int edi, int ebx, int arg)
{
    if (edi == 2)
        return;

    int esi = (ebx == 0) ? 1 : 0;
    int saved = 0;
    if (esi != 0)
        saved = (int)GetLastError();

    func_0062ff38(0, arg);

    if (esi != 0)
        SetLastError((unsigned long)saved);
}
