// from server: 100% by colin
// from server: 97% by king_originala
// roc 2008-06 00562670  unit: std::D::DU?$char_traits::?$basic_ifstream  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00562670
//
// 00562670  51                   push ecx
// 00562671  53                   push ebx
// 00562672  56                   push esi
// 00562673  57                   push edi
// 00562674  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00562678  6a00                 push 0
// 0056267a  6a01                 push 1
// 0056267c  83ec20               sub esp, 0x20
// 0056267f  8bf4                 mov esi, esp
// 00562681  8bd9                 mov ebx, ecx
// 00562683  89642434             mov dword ptr [esp + 0x34], esp
// 00562687  57                   push edi
// 00562688  8bce                 mov ecx, esi
// 0056268a  ff155c248000         call dword ptr [0x80245c]
// 00562690  8b471c               mov eax, dword ptr [edi + 0x1c]
// 00562693  8bcb                 mov ecx, ebx
// 00562695  89461c               mov dword ptr [esi + 0x1c], eax
// 00562698  e8e3f2ffff           call 0x561980
// 0056269d  8bf0                 mov esi, eax
// 0056269f  85f6                 test esi, esi
// 005626a1  7547                 jne 0x5626ea
// 005626a3  8bcf                 mov ecx, edi
// 005626a5  e8a694ffff           call 0x55bb50
// 005626aa  84c0                 test al, al
// 005626ac  742b                 je 0x5626d9
// 005626ae  837f1810             cmp dword ptr [edi + 0x18], 0x10
// 005626b2  7205                 jb 0x5626b9
// 005626b4  8b7f04               mov edi, dword ptr [edi + 4]
// 005626b7  eb03                 jmp 0x5626bc
// 005626b9  83c704               add edi, 4
// 005626bc  57                   push edi
// 005626bd  8bcb                 mov ecx, ebx
// 005626bf  e8ecd0ffff           call 0x55f7b0
// 005626c4  84c0                 test al, al
// 005626c6  7511                 jne 0x5626d9
// 005626c8  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005626cc  c70100000000         mov dword ptr [ecx], 0
// 005626d2  5f                   pop edi
// 005626d3  5e                   pop esi
// 005626d4  5b                   pop ebx
// 005626d5  59                   pop ecx
// 005626d6  c20c00               ret 0xc
// 005626d9  8b542418             mov edx, dword ptr [esp + 0x18]
// 005626dd  c70202000000         mov dword ptr [edx], 2
// 005626e3  5f                   pop edi
// 005626e4  5e                   pop esi
// 005626e5  5b                   pop ebx
// 005626e6  59                   pop ecx
// 005626e7  c20c00               ret 0xc
// 005626ea  56                   push esi
// 005626eb  8bcb                 mov ecx, ebx
// 005626ed  e80edbffff           call 0x560200
// 005626f2  84c0                 test al, al
// 005626f4  7511                 jne 0x562707
// 005626f6  8b442418             mov eax, dword ptr [esp + 0x18]
// 005626fa  c70002000000         mov dword ptr [eax], 2
// 00562700  5f                   pop edi
// 00562701  5e                   pop esi
// 00562702  5b                   pop ebx
// 00562703  59                   pop ecx
// 00562704  c20c00               ret 0xc
// 00562707  8b4e08               mov ecx, dword ptr [esi + 8]
// 0056270a  51                   push ecx
// 0056270b  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0056270f  ff150c248000         call dword ptr [0x80240c]
// 00562715  8b542418             mov edx, dword ptr [esp + 0x18]
// 00562719  5f                   pop edi
// 0056271a  5e                   pop esi
// 0056271b  c70201000000         mov dword ptr [edx], 1
// 00562721  5b                   pop ebx
// 00562722  59                   pop ecx
// 00562723  c20c00               ret 0xc

struct String {
    unsigned int reserved;
    union {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;
    __declspec(dllimport) String(const String&);
    __declspec(dllimport) ~String();
};

extern String* (__thiscall *copyString)(String*, const String&);
extern String* (__thiscall *assignString)(String*, const String&);

struct Value {
    String text;
    unsigned int tag;

    Value(const Value& other);
    bool valid() const;
};

inline Value::Value(const Value& other) : text(other.text)
{
    tag = other.tag;
}

struct Node {
    unsigned int reserved[2];
    String* text;
};

struct S {
    Node* find(Value value, int mode, int flags);
    bool fallback(const char* text);
    bool accept(Node* node);
    void f(const Value& value, int* result, String& output);
};

void S::f(const Value& value, int* result, String& output)
{
    Node* node = find(value, 1, 0);
    if (!node) {
        if (value.valid()) {
            const char* text;
            if (value.text.capacity >= 16)
                text = value.text.storage.pointer;
            else
                text = value.text.storage.buffer;
            if (!fallback(text)) {
                *result = 0;
                return;
            }
        }
        *result = 2;
        return;
    }

    if (!accept(node)) {
        *result = 2;
        return;
    }

    assignString(&output, *node->text);
    *result = 1;
}
