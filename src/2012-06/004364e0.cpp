// from server: 100% by Xemicl
// roc 2012-06 004364e0  unit: CPatchedControlComboBox  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004364e0
//
// 004364e0  6aff                 push -1
// 004364e2  686a21aa00           push 0xaa216a
// 004364e7  64a100000000         mov eax, dword ptr fs:[0]
// 004364ed  50                   push eax
// 004364ee  64892500000000       mov dword ptr fs:[0], esp
// 004364f5  51                   push ecx
// 004364f6  56                   push esi
// 004364f7  68cc000000           push 0xcc
// 004364fc  e819bc5400           call 0x98211a
// 00436501  8bf0                 mov esi, eax
// 00436503  83c404               add esp, 4
// 00436506  89742404             mov dword ptr [esp + 4], esi
// 0043650a  33c0                 xor eax, eax
// 0043650c  89442410             mov dword ptr [esp + 0x10], eax
// 00436510  3bf0                 cmp esi, eax
// 00436512  740f                 je 0x436523
// 00436514  8bce                 mov ecx, esi
// 00436516  e875cd5600           call 0x9a3290
// 0043651b  c706ccf7b400         mov dword ptr [esi], 0xb4f7cc
// 00436521  8bc6                 mov eax, esi
// 00436523  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00436527  5e                   pop esi
// 00436528  64890d00000000       mov dword ptr fs:[0], ecx
// 0043652f  83c410               add esp, 0x10
// 00436532  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000000_00433280@@YAPAUCBrowserFrameWnd@@XZ)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*) throw();

struct FrameBase
{
    FrameBase();
    virtual ~FrameBase();
    char storage[200];
};

struct CBrowserFrameWnd : FrameBase
{
    virtual ~CBrowserFrameWnd();
};

CBrowserFrameWnd* func_00433280()
{
    return new CBrowserFrameWnd;
}