// from server: 97% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00574bf0  unit: RBX::TopMenuBar  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00574bf0
//
// 00574bf0  83ec10               sub esp, 0x10
// 00574bf3  53                   push ebx
// 00574bf4  56                   push esi
// 00574bf5  8bf1                 mov esi, ecx
// 00574bf7  8b86d0feffff         mov eax, dword ptr [esi - 0x130]
// 00574bfd  8b5054               mov edx, dword ptr [eax + 0x54]
// 00574c00  8d9ed0feffff         lea ebx, [esi - 0x130]
// 00574c06  57                   push edi
// 00574c07  8bcb                 mov ecx, ebx
// 00574c09  ffd2                 call edx
// 00574c0b  84c0                 test al, al
// 00574c0d  747c                 je 0x574c8b
// 00574c0f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00574c13  57                   push edi
// 00574c14  8d442410             lea eax, [esp + 0x10]
// 00574c18  50                   push eax
// 00574c19  8bce                 mov ecx, esi
// 00574c1b  e8f0feffff           call 0x574b10
// 00574c20  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00574c24  85c9                 test ecx, ecx
// 00574c26  7416                 je 0x574c3e
// 00574c28  8b442420             mov eax, dword ptr [esp + 0x20]
// 00574c2c  5f                   pop edi
// 00574c2d  8908                 mov dword ptr [eax], ecx
// 00574c2f  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00574c33  5e                   pop esi
// 00574c34  894804               mov dword ptr [eax + 4], ecx
// 00574c37  5b                   pop ebx
// 00574c38  83c410               add esp, 0x10
// 00574c3b  c20800               ret 8
// 00574c3e  d9ee                 fldz 
// 00574c40  d85e20               fcomp dword ptr [esi + 0x20]
// 00574c43  dfe0                 fnstsw ax
// 00574c45  f6c405               test ah, 5
// 00574c48  7a41                 jp 0x574c8b
// 00574c4a  8b07                 mov eax, dword ptr [edi]
// 00574c4c  83f801               cmp eax, 1
// 00574c4f  7c3a                 jl 0x574c8b
// 00574c51  83f807               cmp eax, 7
// 00574c54  7f35                 jg 0x574c8b
// 00574c56  8b5708               mov edx, dword ptr [edi + 8]
// 00574c59  52                   push edx
// 00574c5a  8d442410             lea eax, [esp + 0x10]
// 00574c5e  50                   push eax
// 00574c5f  8bcb                 mov ecx, ebx
// 00574c61  e8aae6ffff           call 0x573310
// 00574c66  8bc8                 mov ecx, eax
// 00574c68  e8c3e4ffff           call 0x573130
// 00574c6d  84c0                 test al, al
// 00574c6f  741a                 je 0x574c8b
// 00574c71  8b442420             mov eax, dword ptr [esp + 0x20]
// 00574c75  5f                   pop edi
// 00574c76  5e                   pop esi
// 00574c77  c70001000000         mov dword ptr [eax], 1
// 00574c7d  c7400400000000       mov dword ptr [eax + 4], 0
// 00574c84  5b                   pop ebx
// 00574c85  83c410               add esp, 0x10
// 00574c88  c20800               ret 8
// 00574c8b  8b442420             mov eax, dword ptr [esp + 0x20]
// 00574c8f  5f                   pop edi
// 00574c90  5e                   pop esi
// 00574c91  c70000000000         mov dword ptr [eax], 0
// 00574c97  c7400400000000       mov dword ptr [eax + 4], 0
// 00574c9e  5b                   pop ebx
// 00574c9f  83c410               add esp, 0x10
// 00574ca2  c20800               ret 8

struct Result {
    int first;
    int second;
    Result(int a, int b) : first(a), second(b) {}
};

struct Event {
    int kind;
    int unused;
    int value;
};

struct Rectangle {
    int data[4];
    bool contains();
};

struct Base;

struct VTable {
    char padding[84];
    bool (__thiscall *enabled)(Base *);
};

struct Base {
    VTable *vtable;
    Rectangle rectangle(int);
};

struct S {
    char padding[32];
    float amount;

    Result query(Event *);
    Result f(Event *);
};

Result S::f(Event *event)
{
    Base *base = reinterpret_cast<Base *>(
        reinterpret_cast<char *>(this) - 304);

    if (base->vtable->enabled(base)) {
        {
            Result result = query(event);
            if (result.first)
                return result;
        }

        if (amount > 0.0f &&
            event->kind >= 1 &&
            event->kind <= 7) {
            if (base->rectangle(event->value).contains())
                return Result(1, 0);
        }
    }

    return Result(0, 0);
}
