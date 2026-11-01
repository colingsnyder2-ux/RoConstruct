// from server: 100% by Yeetserama
// roc 2010-06 004413c0  unit: _NVCXTPPropertyGridItemBool::?$XItem  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004413c0
//
// 004413c0  6aff                 push -1
// 004413c2  6819119800           push 0x981119
// 004413c7  64a100000000         mov eax, dword ptr fs:[0]
// 004413cd  50                   push eax
// 004413ce  64892500000000       mov dword ptr fs:[0], esp
// 004413d5  83ec08               sub esp, 8
// 004413d8  56                   push esi
// 004413d9  8bf1                 mov esi, ecx
// 004413db  51                   push ecx
// 004413dc  8d442420             lea eax, [esp + 0x20]
// 004413e0  8bcc                 mov ecx, esp
// 004413e2  8964240c             mov dword ptr [esp + 0xc], esp
// 004413e6  50                   push eax
// 004413e7  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004413ef  ff15c4ce9e00         call dword ptr [0x9ecec4]
// 004413f5  8bce                 mov ecx, esi
// 004413f7  e8847e3d00           call 0x819280
// 004413fc  8b16                 mov edx, dword ptr [esi]
// 004413fe  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 00441404  8bce                 mov ecx, esi
// 00441406  ffd0                 call eax
// 00441408  8d4c2407             lea ecx, [esp + 7]
// 0044140c  51                   push ecx
// 0044140d  8bce                 mov ecx, esi
// 0044140f  8844240b             mov byte ptr [esp + 0xb], al
// 00441413  e838ccffff           call 0x43e050
// 00441418  8d4c241c             lea ecx, [esp + 0x1c]
// 0044141c  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00441422  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00441426  64890d00000000       mov dword ptr fs:[0], ecx
// 0044142d  5e                   pop esi
// 0044142e  83c414               add esp, 0x14
// 00441431  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX000010@@QAEXUString@2@@Z)

namespace ns_ROCX000010 {
// from server: 100% by colin
struct String;


struct String
{
    void* data;

    __declspec(dllimport) String(const String&);
    __declspec(dllimport) ~String() throw();
};





struct S
{
    typedef bool (__thiscall *Query)(S*);
    Query* vtable;

    void f(String value);
    void set(String value);
    void update(const bool& value);
};

void S::f(String value)
{
    set(value);
    bool result = vtable[60](this);
    update(result);
}
}
