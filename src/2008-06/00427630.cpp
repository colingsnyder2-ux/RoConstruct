// from server: 100% by colin
// from server: 84% by king_originala
// roc 2008-06 00427630  unit: CSelectionTreeCtrl  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00427630
//
// 00427630  8b442404             mov eax, dword ptr [esp + 4]
// 00427634  56                   push esi
// 00427635  8b30                 mov esi, dword ptr [eax]
// 00427637  83ec1c               sub esp, 0x1c
// 0042763a  8d5604               lea edx, [esi + 4]
// 0042763d  8bcc                 mov ecx, esp
// 0042763f  89642424             mov dword ptr [esp + 0x24], esp
// 00427643  52                   push edx
// 00427644  ff155c248000         call dword ptr [0x80245c]
// 0042764a  8b06                 mov eax, dword ptr [esi]
// 0042764c  ffd0                 call eax
// 0042764e  83c41c               add esp, 0x1c
// 00427651  5e                   pop esi
// 00427652  c3                   ret 

struct String;
extern void (__thiscall *G1_func_0080245c)(String *, const String *);

struct String {
    char data[28];
    __declspec(dllimport) String(const String &other);
    __declspec(dllimport) ~String();
};


struct Entry {
    void (__cdecl *callback)(String);
    String value;
};

void __cdecl f(Entry **p)
{
    Entry *q = *p;
    q->callback(q->value);
}
