// from server: 100% by EspClaude
// roc 2009-06 00411800  unit: std::logic_error  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00411800
//
// 00411800  6aff                 push -1
// 00411802  687aef8400           push 0x84ef7a
// 00411807  64a100000000         mov eax, dword ptr fs:[0]
// 0041180d  50                   push eax
// 0041180e  64892500000000       mov dword ptr fs:[0], esp
// 00411815  51                   push ecx
// 00411816  56                   push esi
// 00411817  68f0000000           push 0xf0
// 0041181c  e817723000           call 0x718a38
// 00411821  8bf0                 mov esi, eax
// 00411823  83c404               add esp, 4
// 00411826  89742404             mov dword ptr [esp + 4], esi
// 0041182a  33c0                 xor eax, eax
// 0041182c  89442410             mov dword ptr [esp + 0x10], eax
// 00411830  3bf0                 cmp esi, eax
// 00411832  740f                 je 0x411843
// 00411834  8bce                 mov ecx, esi
// 00411836  e889793000           call 0x7191c4
// 0041183b  c7060cf38a00         mov dword ptr [esi], 0x8af30c
// 00411841  8bc6                 mov eax, esi
// 00411843  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00411847  5e                   pop esi
// 00411848  64890d00000000       mov dword ptr fs:[0], ecx
// 0041184f  83c410               add esp, 0x10
// 00411852  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000000_00433280@@YAPAUCBrowserFrameWnd@@XZ)

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