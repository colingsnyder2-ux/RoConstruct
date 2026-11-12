// from server: 97% by EspClaude
// from server: 50% by colin
// roc 2007-08 005609d0  unit: RBX::VModelInstance::?$FilteredSelection  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005609d0
//
// 005609d0  64a100000000         mov eax, dword ptr fs:[0]
// 005609d6  6aff                 push -1
// 005609d8  68683f7500           push 0x753f68
// 005609dd  50                   push eax
// 005609de  64892500000000       mov dword ptr fs:[0], esp
// 005609e5  8b442414             mov eax, dword ptr [esp + 0x14]
// 005609e9  83ec24               sub esp, 0x24
// 005609ec  56                   push esi
// 005609ed  8bf1                 mov esi, ecx
// 005609ef  8b4804               mov ecx, dword ptr [eax + 4]
// 005609f2  85c9                 test ecx, ecx
// 005609f4  746b                 je 0x560a61
// 005609f6  8b5008               mov edx, dword ptr [eax + 8]
// 005609f9  2bd1                 sub edx, ecx
// 005609fb  c1fa02               sar edx, 2
// 005609fe  7461                 je 0x560a61
// 00560a00  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00560a03  51                   push ecx
// 00560a04  50                   push eax
// 00560a05  6a00                 push 0
// 00560a07  8d4c2410             lea ecx, [esp + 0x10]
// 00560a0b  e840030800           call 0x5e0d50
// 00560a10  8d4c2404             lea ecx, [esp + 4]
// 00560a14  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00560a1c  e83ffc0700           call 0x5e0660
// 00560a21  8b442438             mov eax, dword ptr [esp + 0x38]
// 00560a25  50                   push eax
// 00560a26  8d4c2408             lea ecx, [esp + 8]
// 00560a2a  e841010800           call 0x5e0b70
// 00560a2f  8d4c2404             lea ecx, [esp + 4]
// 00560a33  e868050800           call 0x5e0fa0
// 00560a38  8b760c               mov esi, dword ptr [esi + 0xc]
// 00560a3b  c644243c00           mov byte ptr [esp + 0x3c], 0
// 00560a40  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00560a44  51                   push ecx
// 00560a45  8d8ed4020000         lea ecx, [esi + 0x2d4]
// 00560a4b  e81081ffff           call 0x558b60
// 00560a50  8d4c2404             lea ecx, [esp + 4]
// 00560a54  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 00560a5c  e88f040800           call 0x5e0ef0
// 00560a61  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00560a65  5e                   pop esi
// 00560a66  64890d00000000       mov dword ptr fs:[0], ecx
// 00560a6d  83c430               add esp, 0x30
// 00560a70  c20800               ret 8
// roc-flags: /O2 /GS- /EHsc /MD

struct Item;
template<class T> struct Vec {   // VS2005 vector<T*>: proxy, _Myfirst, _Mylast
    void* proxy; T* first; T* last;
    unsigned size() const { return first == 0 ? 0 : (unsigned)(last - first); }
};
struct Root;
struct Flag { bool b; };
struct Sel2d4 { void set(Flag f); };
struct Root { char pad[0x2d4]; Sel2d4 s; };
struct Op {
    int d[9];   // 0x24 bytes of frame
    Op(void* p, const Vec<Item*>& v, Root* r);
    ~Op();
    void a();
    void b(int x);
    void c();
};
struct FilteredSelection {
    char pad[0xc];
    Root* root;
    void method(int x, const Vec<Item*>& v);
};
void FilteredSelection::method(int x, const Vec<Item*>& v)
{
    if (v.size() != 0) {
        Op op(0, v, root);
        op.a();
        op.b(x);
        op.c();
        Root* r = root;
        Flag f; f.b = false;
        r->s.set(f);
    }
}
