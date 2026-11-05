// from server: 100% by Yeetserama
// roc 2010-06 004115f0  unit: CChildFrame  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004115f0
//
// 004115f0  6aff                 push -1
// 004115f2  68da209800           push 0x9820da
// 004115f7  64a100000000         mov eax, dword ptr fs:[0]
// 004115fd  50                   push eax
// 004115fe  64892500000000       mov dword ptr fs:[0], esp
// 00411605  51                   push ecx
// 00411606  56                   push esi
// 00411607  68f0000000           push 0xf0
// 0041160c  e88f633900           call 0x7a79a0
// 00411611  8bf0                 mov esi, eax
// 00411613  83c404               add esp, 4
// 00411616  89742404             mov dword ptr [esp + 4], esi
// 0041161a  33c0                 xor eax, eax
// 0041161c  89442410             mov dword ptr [esp + 0x10], eax
// 00411620  3bf0                 cmp esi, eax
// 00411622  740f                 je 0x411633
// 00411624  8bce                 mov ecx, esi
// 00411626  e8016b3900           call 0x7a812c
// 0041162b  c706d428a000         mov dword ptr [esi], 0xa028d4
// 00411631  8bc6                 mov eax, esi
// 00411633  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00411637  5e                   pop esi
// 00411638  64890d00000000       mov dword ptr fs:[0], ecx
// 0041163f  83c410               add esp, 0x10
// 00411642  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000000_00433280@@YAPAUCBrowserFrameWnd@@XZ)

// from server: 100% by tester
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*) throw();

struct FrameBase
{
    FrameBase();
    virtual ~FrameBase();
    char storage[236];
};

struct CBrowserFrameWnd : FrameBase
{
    virtual ~CBrowserFrameWnd();
};

CBrowserFrameWnd* func_00433280()
{
    return new CBrowserFrameWnd;
}