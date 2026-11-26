// from server: 100% by Xemicl
// roc 2012-06 004491e0  unit: VCFrameWnd::?$CXTPFrameWndBase  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004491e0
//
// 004491e0  6aff                 push -1
// 004491e2  686a21aa00           push 0xaa216a
// 004491e7  64a100000000         mov eax, dword ptr fs:[0]
// 004491ed  50                   push eax
// 004491ee  64892500000000       mov dword ptr fs:[0], esp
// 004491f5  51                   push ecx
// 004491f6  56                   push esi
// 004491f7  68ec000000           push 0xec
// 004491fc  e8198f5300           call 0x98211a
// 00449201  8bf0                 mov esi, eax
// 00449203  83c404               add esp, 4
// 00449206  89742404             mov dword ptr [esp + 4], esi
// 0044920a  33c0                 xor eax, eax
// 0044920c  89442410             mov dword ptr [esp + 0x10], eax
// 00449210  3bf0                 cmp esi, eax
// 00449212  740f                 je 0x449223
// 00449214  8bce                 mov ecx, esi
// 00449216  e8e59c5700           call 0x9c2f00
// 0044921b  c7066c21b500         mov dword ptr [esi], 0xb5216c
// 00449221  8bc6                 mov eax, esi
// 00449223  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00449227  5e                   pop esi
// 00449228  64890d00000000       mov dword ptr fs:[0], ecx
// 0044922f  83c410               add esp, 0x10
// 00449232  c3                   ret 
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