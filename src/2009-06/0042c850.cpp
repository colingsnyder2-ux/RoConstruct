// from server: 100% by EspClaude
// roc 2009-06 0042c850  unit: VCFrameWnd::?$CXTPFrameWndBase  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042c850
//
// 0042c850  6aff                 push -1
// 0042c852  687aef8400           push 0x84ef7a
// 0042c857  64a100000000         mov eax, dword ptr fs:[0]
// 0042c85d  50                   push eax
// 0042c85e  64892500000000       mov dword ptr fs:[0], esp
// 0042c865  51                   push ecx
// 0042c866  56                   push esi
// 0042c867  68ec000000           push 0xec
// 0042c86c  e8c7c12e00           call 0x718a38
// 0042c871  8bf0                 mov esi, eax
// 0042c873  83c404               add esp, 4
// 0042c876  89742404             mov dword ptr [esp + 4], esi
// 0042c87a  33c0                 xor eax, eax
// 0042c87c  89442410             mov dword ptr [esp + 0x10], eax
// 0042c880  3bf0                 cmp esi, eax
// 0042c882  740f                 je 0x42c893
// 0042c884  8bce                 mov ecx, esi
// 0042c886  e835d93200           call 0x75a1c0
// 0042c88b  c7068c278b00         mov dword ptr [esi], 0x8b278c
// 0042c891  8bc6                 mov eax, esi
// 0042c893  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0042c897  5e                   pop esi
// 0042c898  64890d00000000       mov dword ptr fs:[0], ecx
// 0042c89f  83c410               add esp, 0x10
// 0042c8a2  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000000_00433280@@YAPAUCBrowserFrameWnd@@XZ)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*) throw();

struct FrameBase
{
    FrameBase();
    virtual ~FrameBase();
    char storage[232];
};

struct CBrowserFrameWnd : FrameBase
{
    virtual ~CBrowserFrameWnd();
};

CBrowserFrameWnd* func_00433280()
{
    return new CBrowserFrameWnd;
}