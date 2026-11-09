// from server: 100% by EspClaude
// roc 2009-06 0042c900  unit: CNullDoc  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042c900
//
// 0042c900  6aff                 push -1
// 0042c902  687aef8400           push 0x84ef7a
// 0042c907  64a100000000         mov eax, dword ptr fs:[0]
// 0042c90d  50                   push eax
// 0042c90e  64892500000000       mov dword ptr fs:[0], esp
// 0042c915  51                   push ecx
// 0042c916  56                   push esi
// 0042c917  6a54                 push 0x54
// 0042c919  e81ac12e00           call 0x718a38
// 0042c91e  8bf0                 mov esi, eax
// 0042c920  83c404               add esp, 4
// 0042c923  89742404             mov dword ptr [esp + 4], esi
// 0042c927  33c0                 xor eax, eax
// 0042c929  89442410             mov dword ptr [esp + 0x10], eax
// 0042c92d  3bf0                 cmp esi, eax
// 0042c92f  740f                 je 0x42c940
// 0042c931  8bce                 mov ecx, esi
// 0042c933  e8fac32e00           call 0x718d32
// 0042c938  c706dcdc8a00         mov dword ptr [esi], 0x8adcdc
// 0042c93e  8bc6                 mov eax, esi
// 0042c940  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0042c944  5e                   pop esi
// 0042c945  64890d00000000       mov dword ptr fs:[0], ecx
// 0042c94c  83c410               add esp, 0x10
// 0042c94f  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000000_00433280@@YAPAUCBrowserFrameWnd@@XZ)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*) throw();

struct FrameBase
{
    FrameBase();
    virtual ~FrameBase();
    char storage[80];
};

struct CBrowserFrameWnd : FrameBase
{
    virtual ~CBrowserFrameWnd();
};

CBrowserFrameWnd* func_00433280()
{
    return new CBrowserFrameWnd;
}