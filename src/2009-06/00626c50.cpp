// from server: 76% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005fd3e0  unit: RBX::Tool  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005fd3e0
//
// 005fd3e0  51                   push ecx
// 005fd3e1  a138539700           mov eax, dword ptr [0x975338]
// 005fd3e6  53                   push ebx
// 005fd3e7  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 005fd3eb  56                   push esi
// 005fd3ec  57                   push edi
// 005fd3ed  8bf9                 mov edi, ecx
// 005fd3ef  50                   push eax
// 005fd3f0  8bcb                 mov ecx, ebx
// 005fd3f2  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005fd3fa  e8b1eef7ff           call 0x57c2b0
// 005fd3ff  85c0                 test eax, eax
// 005fd401  7443                 je 0x5fd446
// 005fd403  8d4c240c             lea ecx, [esp + 0xc]
// 005fd407  51                   push ecx
// 005fd408  8d4808               lea ecx, [eax + 8]
// 005fd40b  e850eff7ff           call 0x57c360
// 005fd410  84c0                 test al, al
// 005fd412  7432                 je 0x5fd446
// 005fd414  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005fd418  8b356c238000         mov esi, dword ptr [0x80236c]
// 005fd41e  83c204               add edx, 4
// 005fd421  68e8168400           push 0x8416e8
// 005fd426  52                   push edx
// 005fd427  ffd6                 call esi
// 005fd429  83c408               add esp, 8
// 005fd42c  84c0                 test al, al
// 005fd42e  7523                 jne 0x5fd453
// 005fd430  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005fd434  83c004               add eax, 4
// 005fd437  68d8168400           push 0x8416d8
// 005fd43c  50                   push eax
// 005fd43d  ffd6                 call esi
// 005fd43f  83c408               add esp, 8
// 005fd442  84c0                 test al, al
// 005fd444  750d                 jne 0x5fd453
// 005fd446  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005fd44a  51                   push ecx
// 005fd44b  53                   push ebx
// 005fd44c  8bcf                 mov ecx, edi
// 005fd44e  e81dbdf5ff           call 0x559170
// 005fd453  5f                   pop edi
// 005fd454  5e                   pop esi
// 005fd455  5b                   pop ebx
// 005fd456  59                   pop ecx
// 005fd457  c20800               ret 8

struct String;
struct Property;

struct Value {
    bool get(Property** result);
};

struct Node {
    char padding[8];
    Value value;
};

struct Descriptor {
    Node* find(const void* key);
};

extern const void* propertyKey;
extern "C" bool (__cdecl *stringEquals)(const String&, const char*);

struct Base {
    void changed(Descriptor* descriptor, int argument);
};

struct Tool : Base {
    void changed(Descriptor* descriptor, int argument);
};

void Tool::changed(Descriptor* descriptor, int argument)
{
    Property* property = 0;
    Node* node = descriptor->find(propertyKey);
    if (node && node->value.get(&property)) {
        bool (__cdecl *equals)(const String&, const char*) = stringEquals;
        if (equals(
                *reinterpret_cast<const String*>(
                    reinterpret_cast<const char*>(property) + 4),
                "BackendToolState"))
            return;
        if (equals(
                *reinterpret_cast<const String*>(
                    reinterpret_cast<const char*>(property) + 4),
                "ActivationState"))
            return;
    }
    Base::changed(descriptor, argument);
}
