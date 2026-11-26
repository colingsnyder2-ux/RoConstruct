// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc 2012-06 00418650  unit: CRbxChildFrame  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00418650
//
// 00418650  6aff                 push -1
// 00418652  686a21aa00           push 0xaa216a
// 00418657  64a100000000         mov eax, dword ptr fs:[0]
// 0041865d  50                   push eax
// 0041865e  64892500000000       mov dword ptr fs:[0], esp
// 00418665  51                   push ecx
// 00418666  56                   push esi
// 00418667  68f0000000           push 0xf0
// 0041866c  e8a99a5600           call 0x98211a
// 00418671  8bf0                 mov esi, eax
// 00418673  83c404               add esp, 4
// 00418676  89742404             mov dword ptr [esp + 4], esi
// 0041867a  33c0                 xor eax, eax
// 0041867c  89442410             mov dword ptr [esp + 0x10], eax
// 00418680  3bf0                 cmp esi, eax
// 00418682  740f                 je 0x418693
// 00418684  8bce                 mov ecx, esi
// 00418686  e8dfa15600           call 0x98286a
// 0041868b  c7066467b400         mov dword ptr [esi], 0xb46764
// 00418691  8bc6                 mov eax, esi
// 00418693  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00418697  5e                   pop esi
// 00418698  64890d00000000       mov dword ptr fs:[0], ecx
// 0041869f  83c410               add esp, 0x10
// 004186a2  c3                   ret 

// copied from an identical function in another client (function ?fn_ROCX000000_00433280@@YAPAUCBrowserFrameWnd@@XZ)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*) throw();

struct FrameBase
{
    FrameBase();
    virtual ~FrameBase();
    char storage[0x3b0];
};

struct CBrowserFrameWnd : FrameBase
{
    virtual ~CBrowserFrameWnd();
};

CBrowserFrameWnd* func_00433280()
{
    return new CBrowserFrameWnd;
}
