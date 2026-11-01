// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0059a040  unit: RBX::PartInstance  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0059a040
//
// 0059a040  53                   push ebx
// 0059a041  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0059a045  6a00                 push 0
// 0059a047  6850dd9200           push 0x9df950
// 0059a04c  687c909200           push 0x9dbe40
// 0059a051  6a00                 push 0
// 0059a053  53                   push ebx
// 0059a054  e86d771000           call 0x6a17c6
// 0059a059  83c414               add esp, 0x14
// 0059a05c  85c0                 test eax, eax
// 0059a05e  7408                 je 0x59a068
// 0059a060  8a80f0010000         mov al, byte ptr [eax + 0x1f0]
// 0059a066  5b                   pop ebx
// 0059a067  c3                   ret 
// 0059a068  55                   push ebp
// 0059a069  56                   push esi
// 0059a06a  57                   push edi
// 0059a06b  8bcb                 mov ecx, ebx
// 0059a06d  33f6                 xor esi, esi
// 0059a06f  e8ac0defff           call 0x48ae20
// 0059a074  85c0                 test eax, eax
// 0059a076  763c                 jbe 0x59a0b4
// 0059a078  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0059a07e  8bff                 mov edi, edi
// 0059a080  8bbb08010000         mov edi, dword ptr [ebx + 0x108]
// 0059a086  8b4710               mov eax, dword ptr [edi + 0x10]
// 0059a089  2b470c               sub eax, dword ptr [edi + 0xc]
// 0059a08c  c1f803               sar eax, 3
// 0059a08f  3bf0                 cmp esi, eax
// 0059a091  7202                 jb 0x59a095
// 0059a093  ffd5                 call ebp
// 0059a095  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 0059a098  8b04f1               mov eax, dword ptr [ecx + esi*8]
// 0059a09b  50                   push eax
// 0059a09c  e89fffffff           call 0x59a040
// 0059a0a1  83c404               add esp, 4
// 0059a0a4  84c0                 test al, al
// 0059a0a6  7513                 jne 0x59a0bb
// 0059a0a8  8bcb                 mov ecx, ebx
// 0059a0aa  46                   inc esi
// 0059a0ab  e8700defff           call 0x48ae20
// 0059a0b0  3bf0                 cmp esi, eax
// 0059a0b2  72cc                 jb 0x59a080
// 0059a0b4  5f                   pop edi
// 0059a0b5  5e                   pop esi
// 0059a0b6  5d                   pop ebp
// 0059a0b7  32c0                 xor al, al
// 0059a0b9  5b                   pop ebx
// 0059a0ba  c3                   ret 
// 0059a0bb  5f                   pop edi
// 0059a0bc  5e                   pop esi
// 0059a0bd  5d                   pop ebp
// 0059a0be  b001                 mov al, 1
// 0059a0c0  5b                   pop ebx
// 0059a0c1  c3                   ret 

struct Instance;

struct Entry {
    Instance* object;
    void* control;
};

struct Children {
    char padding[12];
    Entry* first;
    Entry* last;
};

struct Instance {
    char padding[0x4c];
    Children* children;
    unsigned int childCount();
};

struct Part {
    char padding[0x130];
    bool value;
};

extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern "C" void (__cdecl* _invalid_parameter_noinfo)();

bool __cdecl check(Instance* object)
{
    Part* part = static_cast<Part*>(
        __RTDynamicCast(object, 0,
                       reinterpret_cast<void*>(0x9dbe40),
                       reinterpret_cast<void*>(0x9df950), 0));
    if (part)
        return part->value;

    unsigned int i = 0;
    if (object->childCount() > 0) {
        void (__cdecl* invalid)() = _invalid_parameter_noinfo;
        do {
            Children* children = object->children;
            if (i >= static_cast<unsigned int>(children->last - children->first))
                invalid();

            Instance* child = children->first[i].object;
            if (check(child))
                return true;
            ++i;
        } while (i < object->childCount());
    }
    return false;
}
