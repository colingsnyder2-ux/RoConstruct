// from server: 100% by Xemicl
// roc 2012-06 004924e0  unit: CRobloxReportPaneView  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004924e0
//
// 004924e0  6aff                 push -1
// 004924e2  686a21aa00           push 0xaa216a
// 004924e7  64a100000000         mov eax, dword ptr fs:[0]
// 004924ed  50                   push eax
// 004924ee  64892500000000       mov dword ptr fs:[0], esp
// 004924f5  51                   push ecx
// 004924f6  56                   push esi
// 004924f7  68bc030000           push 0x3bc
// 004924fc  e819fc4e00           call 0x98211a
// 00492501  8bf0                 mov esi, eax
// 00492503  83c404               add esp, 4
// 00492506  89742404             mov dword ptr [esp + 4], esi
// 0049250a  33c0                 xor eax, eax
// 0049250c  89442410             mov dword ptr [esp + 0x10], eax
// 00492510  3bf0                 cmp esi, eax
// 00492512  740f                 je 0x492523
// 00492514  8bce                 mov ecx, esi
// 00492516  e8b5e5ffff           call 0x490ad0
// 0049251b  c70664dfb500         mov dword ptr [esi], 0xb5df64
// 00492521  8bc6                 mov eax, esi
// 00492523  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00492527  5e                   pop esi
// 00492528  64890d00000000       mov dword ptr fs:[0], ecx
// 0049252f  83c410               add esp, 0x10
// 00492532  c3                   ret 
// copied from an identical function in another client (function ?CreateObject@Derived@@SGPAUBase@@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Base {
    Base();
    virtual ~Base();
    char pad[0x3bc - 4];
};
struct Derived : Base {
    virtual ~Derived();
    static Base* __stdcall CreateObject();
};
Base* __stdcall Derived::CreateObject()
{
    return new Derived;
}