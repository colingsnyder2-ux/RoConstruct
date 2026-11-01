// from server: 100% by colin
// from server: 98% by colin
// roc 2008-06 0062d310  unit: RBX::VForceField::?$FactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0062d310
//
// 0062d310  53                   push ebx
// 0062d311  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0062d315  55                   push ebp
// 0062d316  56                   push esi
// 0062d317  57                   push edi
// 0062d318  8bcb                 mov ecx, ebx
// 0062d31a  33f6                 xor esi, esi
// 0062d31c  e8ffdae5ff           call 0x48ae20
// 0062d321  85c0                 test eax, eax
// 0062d323  764d                 jbe 0x62d372
// 0062d325  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0062d32b  eb03                 jmp 0x62d330
// 0062d32d  8d4900               lea ecx, [ecx]
// 0062d330  8bbb08010000         mov edi, dword ptr [ebx + 0x108]
// 0062d336  8b4710               mov eax, dword ptr [edi + 0x10]
// 0062d339  2b470c               sub eax, dword ptr [edi + 0xc]
// 0062d33c  c1f803               sar eax, 3
// 0062d33f  3bf0                 cmp esi, eax
// 0062d341  7202                 jb 0x62d345
// 0062d343  ffd5                 call ebp
// 0062d345  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 0062d348  8b04f1               mov eax, dword ptr [ecx + esi*8]
// 0062d34b  6a00                 push 0
// 0062d34d  6810c49500           push 0x95c410
// 0062d352  687c909200           push 0x92907c
// 0062d357  6a00                 push 0
// 0062d359  50                   push eax
// 0062d35a  e867440700           call 0x6a17c6
// 0062d35f  83c414               add esp, 0x14
// 0062d362  85c0                 test eax, eax
// 0062d364  7513                 jne 0x62d379
// 0062d366  8bcb                 mov ecx, ebx
// 0062d368  46                   inc esi
// 0062d369  e8b2dae5ff           call 0x48ae20
// 0062d36e  3bf0                 cmp esi, eax
// 0062d370  72be                 jb 0x62d330
// 0062d372  5f                   pop edi
// 0062d373  5e                   pop esi
// 0062d374  5d                   pop ebp
// 0062d375  32c0                 xor al, al
// 0062d377  5b                   pop ebx
// 0062d378  c3                   ret 
// 0062d379  5f                   pop edi
// 0062d37a  5e                   pop esi
// 0062d37b  5d                   pop ebp
// 0062d37c  b001                 mov al, 1
// 0062d37e  5b                   pop ebx
// 0062d37f  c3                   ret 

// from server: 73% by king_originala
struct Instance;

struct Entry {
    Instance *object;
    void *control;
};

struct Children {
    unsigned char padding[12];
    Entry *first;
    Entry *last;
};

struct Instance {
    virtual ~Instance();
    unsigned char padding[0x100];
    Instance *parent;
    Children *children;

    unsigned int childCount();
};

struct ForceField : Instance {};
struct Workspace : Instance {};

extern void (__cdecl *invalidParameter)();
extern char instanceType;
extern char forceFieldType;
extern "C" void *__cdecl __RTDynamicCast(void *, long, void *, void *, int);

__declspec(noinline) bool __cdecl hasForceField(Instance *object)
{
    unsigned int i = 0;
    if (object->childCount() > 0) {
        void (__cdecl *handler)() = invalidParameter;
        do {
            Children *children = object->children;
            if (i >= static_cast<unsigned int>(children->last - children->first))
                handler();

            Instance* candidate = children->first[i].object;
            if (__RTDynamicCast(candidate, 0, &instanceType, &forceFieldType, 0))
                return true;

            ++i;
        } while (i < object->childCount());
    }
    return false;
}

