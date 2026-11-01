// from server: 100% by Yeetserama
// roc 2010-06 00411650  unit: CChildFrame  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00411650
//
// 00411650  6aff                 push -1
// 00411652  68da209800           push 0x9820da
// 00411657  64a100000000         mov eax, dword ptr fs:[0]
// 0041165d  50                   push eax
// 0041165e  64892500000000       mov dword ptr fs:[0], esp
// 00411665  51                   push ecx
// 00411666  56                   push esi
// 00411667  68f0000000           push 0xf0
// 0041166c  e82f633900           call 0x7a79a0
// 00411671  8bf0                 mov esi, eax
// 00411673  83c404               add esp, 4
// 00411676  89742404             mov dword ptr [esp + 4], esi
// 0041167a  33c0                 xor eax, eax
// 0041167c  89442410             mov dword ptr [esp + 0x10], eax
// 00411680  3bf0                 cmp esi, eax
// 00411682  740f                 je 0x411693
// 00411684  8bce                 mov ecx, esi
// 00411686  e8a16a3900           call 0x7a812c
// 0041168b  c706542ba000         mov dword ptr [esi], 0xa02b54
// 00411691  8bc6                 mov eax, esi
// 00411693  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00411697  5e                   pop esi
// 00411698  64890d00000000       mov dword ptr fs:[0], ecx
// 0041169f  83c410               add esp, 0x10
// 004116a2  c3                   ret 
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