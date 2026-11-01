// from server: 100% by Yeetserama
// roc 2007-08 004364e0  unit: CDeclarationView  size: 222 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004364e0
//
// 004364e0  6aff                 push -1
// 004364e2  6889ff7300           push 0x73ff89
// 004364e7  64a100000000         mov eax, dword ptr fs:[0]
// 004364ed  50                   push eax
// 004364ee  83ec1c               sub esp, 0x1c
// 004364f1  53                   push ebx
// 004364f2  55                   push ebp
// 004364f3  56                   push esi
// 004364f4  57                   push edi
// 004364f5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004364fa  33c4                 xor eax, esp
// 004364fc  50                   push eax
// 004364fd  8d442430             lea eax, [esp + 0x30]
// 00436501  64a300000000         mov dword ptr fs:[0], eax
// 00436507  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 0043650b  837d0000             cmp dword ptr [ebp], 0
// 0043650f  8b742444             mov esi, dword ptr [esp + 0x44]
// 00436513  7e0d                 jle 0x436522
// 00436515  6840cc7800           push 0x78cc40
// 0043651a  8bce                 mov ecx, esi
// 0043651c  ff1560e67700         call dword ptr [0x77e660]
// 00436522  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 00436526  8b4704               mov eax, dword ptr [edi + 4]
// 00436529  8b4004               mov eax, dword ptr [eax + 4]
// 0043652c  8d4804               lea ecx, [eax + 4]
// 0043652f  ff15a8e67700         call dword ptr [0x77e6a8]
// 00436535  50                   push eax
// 00436536  8bce                 mov ecx, esi
// 00436538  ff1560e67700         call dword ptr [0x77e660]
// 0043653e  6834707800           push 0x787034
// 00436543  8bce                 mov ecx, esi
// 00436545  ff1560e67700         call dword ptr [0x77e660]
// 0043654b  8b07                 mov eax, dword ptr [edi]
// 0043654d  8d4804               lea ecx, [eax + 4]
// 00436550  ff15a8e67700         call dword ptr [0x77e6a8]
// 00436556  50                   push eax
// 00436557  8bce                 mov ecx, esi
// 00436559  ff1560e67700         call dword ptr [0x77e660]
// 0043655f  8b4708               mov eax, dword ptr [edi + 8]
// 00436562  3b4704               cmp eax, dword ptr [edi + 4]
// 00436565  8d5f08               lea ebx, [edi + 8]
// 00436568  753c                 jne 0x4365a6
// 0043656a  6844cc7800           push 0x78cc44
// 0043656f  8bce                 mov ecx, esi
// 00436571  ff1560e67700         call dword ptr [0x77e660]
// 00436577  8d4c2414             lea ecx, [esp + 0x14]
// 0043657b  51                   push ecx
// 0043657c  8bcb                 mov ecx, ebx
// 0043657e  e86dfbffff           call 0x4360f0
// 00436583  50                   push eax
// 00436584  8bce                 mov ecx, esi
// 00436586  c744243c00000000     mov dword ptr [esp + 0x3c], 0
// 0043658e  ff1564e67700         call dword ptr [0x77e664]
// 00436594  8d4c2414             lea ecx, [esp + 0x14]
// 00436598  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 004365a0  ff15ace67700         call dword ptr [0x77e6ac]
// 004365a6  83450001             add dword ptr [ebp], 1
// 004365aa  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004365ae  64890d00000000       mov dword ptr fs:[0], ecx
// 004365b5  59                   pop ecx
// 004365b6  5f                   pop edi
// 004365b7  5e                   pop esi
// 004365b8  5d                   pop ebp
// 004365b9  5b                   pop ebx
// 004365ba  83c428               add esp, 0x28
// 004365bd  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000017_00435550@ns_ROCX000017@@YAXPAHPAUString@1@PBUEntry@1@@Z)

namespace ns_ROCX000017 {
// from server: 100% by colin
struct String;

extern String& (__thiscall *append_text)(String*, const char*);
extern String& (__thiscall *append_string)(String*, const String&);
extern const char* (__thiscall *string_data)(const String*);
extern void (__thiscall *destroy_string)(String*);

struct String
{
    unsigned char storage[28];
    ~String();
};

__forceinline String::~String()
{
    destroy_string(this);
}

struct Node
{
    int unused;
    String text;
};

struct Link
{
    int unused;
    Node* node;
};

struct Slot
{
    Link* value;
    String render() const;
};

struct Entry
{
    Node* first;
    Link* second;
    Slot third;
};

extern const char separator[];
extern const char suffix[];
extern const char middle[];

void fn_ROCX000017_00435550(int* count, String* output, const Entry* entry)
{
    if (*count > 0)
        append_text(output, separator);

    {
        const Node* n = entry->second->node;
        append_text(output, string_data(&n->text));
    }
    append_text(output, middle);
    {
        const Node* f = entry->first;
        append_text(output, string_data(&f->text));
    }

    {
        const Link* v = entry->third.value;
        if (v == entry->second)
        {
            append_text(output, suffix);
            append_string(output, entry->third.render());
        }
    }

    ++*count;
}
}
