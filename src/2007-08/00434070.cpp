// from server: 100% by Yeetserama
// roc 2007-08 00434070  unit: CNullDoc  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00434070
//
// 00434070  6aff                 push -1
// 00434072  68fad87300           push 0x73d8fa
// 00434077  64a100000000         mov eax, dword ptr fs:[0]
// 0043407d  50                   push eax
// 0043407e  51                   push ecx
// 0043407f  56                   push esi
// 00434080  a188518b00           mov eax, dword ptr [0x8b5188]
// 00434085  33c4                 xor eax, esp
// 00434087  50                   push eax
// 00434088  8d44240c             lea eax, [esp + 0xc]
// 0043408c  64a300000000         mov dword ptr fs:[0], eax
// 00434092  6a54                 push 0x54
// 00434094  e85dbe1f00           call 0x62fef6
// 00434099  8bf0                 mov esi, eax
// 0043409b  83c404               add esp, 4
// 0043409e  89742408             mov dword ptr [esp + 8], esi
// 004340a2  33c0                 xor eax, eax
// 004340a4  3bf0                 cmp esi, eax
// 004340a6  89442414             mov dword ptr [esp + 0x14], eax
// 004340aa  740f                 je 0x4340bb
// 004340ac  8bce                 mov ecx, esi
// 004340ae  e8a9be1f00           call 0x62ff5c
// 004340b3  c706a4557800         mov dword ptr [esi], 0x7855a4
// 004340b9  8bc6                 mov eax, esi
// 004340bb  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004340bf  64890d00000000       mov dword ptr fs:[0], ecx
// 004340c6  59                   pop ecx
// 004340c7  5e                   pop esi
// 004340c8  83c410               add esp, 0x10
// 004340cb  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000000_00433280@@YAPAUCBrowserFrameWnd@@XZ)

// from server: 100% by tester
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