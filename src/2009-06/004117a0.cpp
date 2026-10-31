// from server: 100% by EspClaude
// roc 2009-06 004117a0  unit: std::logic_error  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004117a0
//
// 004117a0  6aff                 push -1
// 004117a2  687aef8400           push 0x84ef7a
// 004117a7  64a100000000         mov eax, dword ptr fs:[0]
// 004117ad  50                   push eax
// 004117ae  64892500000000       mov dword ptr fs:[0], esp
// 004117b5  51                   push ecx
// 004117b6  56                   push esi
// 004117b7  68f0000000           push 0xf0
// 004117bc  e877723000           call 0x718a38
// 004117c1  8bf0                 mov esi, eax
// 004117c3  83c404               add esp, 4
// 004117c6  89742404             mov dword ptr [esp + 4], esi
// 004117ca  33c0                 xor eax, eax
// 004117cc  89442410             mov dword ptr [esp + 0x10], eax
// 004117d0  3bf0                 cmp esi, eax
// 004117d2  740f                 je 0x4117e3
// 004117d4  8bce                 mov ecx, esi
// 004117d6  e8e9793000           call 0x7191c4
// 004117db  c70684f08a00         mov dword ptr [esi], 0x8af084
// 004117e1  8bc6                 mov eax, esi
// 004117e3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004117e7  5e                   pop esi
// 004117e8  64890d00000000       mov dword ptr fs:[0], ecx
// 004117ef  83c410               add esp, 0x10
// 004117f2  c3                   ret 
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