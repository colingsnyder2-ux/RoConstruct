// from server: 100% by Xemicl
// roc 2012-06 009735f0  unit: std::D::DU?$char_traits::V?$basic_string::?$thread_specific_ptr::delete_data  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009735f0
//
// 009735f0  6aff                 push -1
// 009735f2  6878aead00           push 0xadae78
// 009735f7  64a100000000         mov eax, dword ptr fs:[0]
// 009735fd  50                   push eax
// 009735fe  64892500000000       mov dword ptr fs:[0], esp
// 00973605  83ec08               sub esp, 8
// 00973608  56                   push esi
// 00973609  8bf1                 mov esi, ecx
// 0097360b  89742404             mov dword ptr [esp + 4], esi
// 0097360f  83ec20               sub esp, 0x20
// 00973612  8bc4                 mov eax, esp
// 00973614  c70000000000         mov dword ptr [eax], 0
// 0097361a  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0097361e  c744243401000000     mov dword ptr [esp + 0x34], 1
// 00973626  89642428             mov dword ptr [esp + 0x28], esp
// 0097362a  85c9                 test ecx, ecx
// 0097362c  7418                 je 0x973646
// 0097362e  8908                 mov dword ptr [eax], ecx
// 00973630  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00973634  8b11                 mov edx, dword ptr [ecx]
// 00973636  83c008               add eax, 8
// 00973639  6a00                 push 0
// 0097363b  50                   push eax
// 0097363c  8d44244c             lea eax, [esp + 0x4c]
// 00973640  50                   push eax
// 00973641  ffd2                 call edx
// 00973643  83c40c               add esp, 0xc
// 00973646  8bce                 mov ecx, esi
// 00973648  e8636cddff           call 0x74a2b0
// 0097364d  8d44243c             lea eax, [esp + 0x3c]
// 00973651  8d4e20               lea ecx, [esi + 0x20]
// 00973654  50                   push eax
// 00973655  c644241802           mov byte ptr [esp + 0x18], 2
// 0097365a  ff154426b200         call dword ptr [0xb22644]
// 00973660  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00973664  c644241400           mov byte ptr [esp + 0x14], 0
// 00973669  85c0                 test eax, eax
// 0097366b  741d                 je 0x97368a
// 0097366d  8b00                 mov eax, dword ptr [eax]
// 0097366f  85c0                 test eax, eax
// 00973671  740f                 je 0x973682
// 00973673  8d4c2424             lea ecx, [esp + 0x24]
// 00973677  6a02                 push 2
// 00973679  51                   push ecx
// 0097367a  8bd1                 mov edx, ecx
// 0097367c  52                   push edx
// 0097367d  ffd0                 call eax
// 0097367f  83c40c               add esp, 0xc
// 00973682  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0097368a  8d4c243c             lea ecx, [esp + 0x3c]
// 0097368e  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00973696  ff153c26b200         call dword ptr [0xb2263c]
// 0097369c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009736a0  8bc6                 mov eax, esi
// 009736a2  64890d00000000       mov dword ptr fs:[0], ecx
// 009736a9  5e                   pop esi
// 009736aa  83c414               add esp, 0x14
// 009736ad  c23c00               ret 0x3c
// copied from an identical function in another client (function ??0S@@QAE@UFunction@@UString@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct String {
    unsigned char data[28];
    __declspec(dllimport) String(const String& other);
    __declspec(dllimport) ~String();
};
struct Function {
    typedef void (__cdecl *Manager)(const void*, void*, int);
    struct Table {
        Manager invoke;
    };
    Table* manager;
    unsigned int reserved;
    unsigned char storage[24];
    Function(const Function& other);
    ~Function();
};
inline Function::Function(const Function& other) : manager(0) {
    if (other.manager) {
        manager = other.manager;
        other.manager->invoke(other.storage, storage, 0);
    }
}
inline Function::~Function() {
    if (manager) {
        Manager invoke = manager->invoke;
        if (invoke)
            invoke(storage, storage, 2);
        manager = 0;
    }
}
struct Base {
    unsigned char data[32];
    Base(Function function);
    ~Base();
};
struct Value {
    String t_;
    Value(const String& t) : t_(t) {}
};
struct S : Base {
    Value name;
    S(Function function, String text);
};
S::S(Function function, String text) : Base(function), name(text) {
}