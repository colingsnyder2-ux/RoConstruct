// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005b0840  unit: RBX::Accoutrement  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b0840
//
// 005b0840  51                   push ecx
// 005b0841  a138539700           mov eax, dword ptr [0x975338]
// 005b0846  56                   push esi
// 005b0847  57                   push edi
// 005b0848  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005b084c  8bf1                 mov esi, ecx
// 005b084e  50                   push eax
// 005b084f  8bcf                 mov ecx, edi
// 005b0851  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 005b0859  e852bafcff           call 0x57c2b0
// 005b085e  85c0                 test eax, eax
// 005b0860  742b                 je 0x5b088d
// 005b0862  8d4c2408             lea ecx, [esp + 8]
// 005b0866  51                   push ecx
// 005b0867  8d4808               lea ecx, [eax + 8]
// 005b086a  e8f1bafcff           call 0x57c360
// 005b086f  84c0                 test al, al
// 005b0871  741a                 je 0x5b088d
// 005b0873  8b542408             mov edx, dword ptr [esp + 8]
// 005b0877  83c204               add edx, 4
// 005b087a  680c4a8300           push 0x834a0c
// 005b087f  52                   push edx
// 005b0880  ff156c238000         call dword ptr [0x80236c]
// 005b0886  83c408               add esp, 8
// 005b0889  84c0                 test al, al
// 005b088b  750d                 jne 0x5b089a
// 005b088d  8b442414             mov eax, dword ptr [esp + 0x14]
// 005b0891  50                   push eax
// 005b0892  57                   push edi
// 005b0893  8bce                 mov ecx, esi
// 005b0895  e8d688faff           call 0x559170
// 005b089a  5f                   pop edi
// 005b089b  5e                   pop esi
// 005b089c  59                   pop ecx
// 005b089d  c20800               ret 8

struct String {};

struct Object {
    String text;
};

struct Value {
    bool extract(Object** result);
};

struct Node {
    unsigned char prefix[8];
    Value value;
};

struct Descriptor {
    Node* lookup(void* key);
};

struct Accoutrement {
    void fallback(Descriptor* descriptor, void* argument);
    void update(Descriptor* descriptor, void* argument);
};

typedef bool (__cdecl *StringEqual)(const String&, const char*);

extern void* lookupKey;
extern StringEqual stringEqual;
extern const char backendState[];

void Accoutrement::update(Descriptor* descriptor, void* argument)
{
    Object* object = 0;
    Node* node = descriptor->lookup(lookupKey);

    if (node && node->value.extract(&object)) {
        if (stringEqual(object->text, backendState))
            return;
    }

    fallback(descriptor, argument);
}
