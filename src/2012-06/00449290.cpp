// from server: 100% by Xemicl
// roc 2012-06 00449290  unit: CNullDoc  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00449290
//
// 00449290  6aff                 push -1
// 00449292  686a21aa00           push 0xaa216a
// 00449297  64a100000000         mov eax, dword ptr fs:[0]
// 0044929d  50                   push eax
// 0044929e  64892500000000       mov dword ptr fs:[0], esp
// 004492a5  51                   push ecx
// 004492a6  56                   push esi
// 004492a7  6a54                 push 0x54
// 004492a9  e86c8e5300           call 0x98211a
// 004492ae  8bf0                 mov esi, eax
// 004492b0  83c404               add esp, 4
// 004492b3  89742404             mov dword ptr [esp + 4], esi
// 004492b7  33c0                 xor eax, eax
// 004492b9  89442410             mov dword ptr [esp + 0x10], eax
// 004492bd  3bf0                 cmp esi, eax
// 004492bf  740f                 je 0x4492d0
// 004492c1  8bce                 mov ecx, esi
// 004492c3  e834915300           call 0x9823fc
// 004492c8  c7060451b400         mov dword ptr [esi], 0xb45104
// 004492ce  8bc6                 mov eax, esi
// 004492d0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004492d4  5e                   pop esi
// 004492d5  64890d00000000       mov dword ptr fs:[0], ecx
// 004492dc  83c410               add esp, 0x10
// 004492df  c3                   ret 
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