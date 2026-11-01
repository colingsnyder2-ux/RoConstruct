// from server: 100% by Espeon
// from server: 99% by colin
// roc 2008-06 006712e0  unit: RBX::AdornRbxGfx  size: 195 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006712e0
//
// 006712e0  6aff                 push -1
// 006712e2  68e3c87d00           push 0x7dc8e3
// 006712e7  64a100000000         mov eax, dword ptr fs:[0]
// 006712ed  50                   push eax
// 006712ee  64892500000000       mov dword ptr fs:[0], esp
// 006712f5  83ec0c               sub esp, 0xc
// 006712f8  53                   push ebx
// 006712f9  55                   push ebp
// 006712fa  56                   push esi
// 006712fb  57                   push edi
// 006712fc  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00671304  8d7178               lea esi, [ecx + 0x78]
// 00671307  8d442430             lea eax, [esp + 0x30]
// 0067130b  50                   push eax
// 0067130c  8d4c2418             lea ecx, [esp + 0x18]
// 00671310  51                   push ecx
// 00671311  8bce                 mov ecx, esi
// 00671313  c744242c01000000     mov dword ptr [esp + 0x2c], 1
// 0067131b  e8c0fdffff           call 0x6710e0
// 00671320  8b38                 mov edi, dword ptr [eax]
// 00671322  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00671325  8b6804               mov ebp, dword ptr [eax + 4]
// 00671328  8b36                 mov esi, dword ptr [esi]
// 0067132a  85ff                 test edi, edi
// 0067132c  7404                 je 0x671332
// 0067132e  3bfe                 cmp edi, esi
// 00671330  740a                 je 0x67133c
// 00671332  8b3590288000         mov esi, dword ptr [0x802890]
// 00671338  ffd6                 call esi
// 0067133a  eb06                 jmp 0x671342
// 0067133c  8b3590288000         mov esi, dword ptr [0x802890]
// 00671342  3beb                 cmp ebp, ebx
// 00671344  7423                 je 0x671369
// 00671346  85ff                 test edi, edi
// 00671348  751b                 jne 0x671365
// 0067134a  ffd6                 call esi
// 0067134c  3b6f18               cmp ebp, dword ptr [edi + 0x18]
// 0067134f  7502                 jne 0x671353
// 00671351  ffd6                 call esi
// 00671353  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00671357  83c528               add ebp, 0x28
// 0067135a  55                   push ebp
// 0067135b  8bce                 mov ecx, esi
// 0067135d  ff15684c8000         call dword ptr [0x804c68]
// 00671363  eb10                 jmp 0x671375
// 00671365  8b3f                 mov edi, dword ptr [edi]
// 00671367  ebe3                 jmp 0x67134c
// 00671369  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0067136d  8bce                 mov ecx, esi
// 0067136f  ff15904c8000         call dword ptr [0x804c90]
// 00671375  8d4c2430             lea ecx, [esp + 0x30]
// 00671379  c744241001000000     mov dword ptr [esp + 0x10], 1
// 00671381  c644242400           mov byte ptr [esp + 0x24], 0
// 00671386  ff1568248000         call dword ptr [0x802468]
// 0067138c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00671390  5f                   pop edi
// 00671391  8bc6                 mov eax, esi
// 00671393  5e                   pop esi
// 00671394  5d                   pop ebp
// 00671395  5b                   pop ebx
// 00671396  64890d00000000       mov dword ptr fs:[0], ecx
// 0067139d  83c418               add esp, 0x18
// 006713a0  c22000               ret 0x20

extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();

struct String;
struct MeshPtr;

extern void (__thiscall *string_destroy)(String*);
extern void (__thiscall *mesh_copy)(MeshPtr*, const MeshPtr&);
extern void (__thiscall *mesh_default)(MeshPtr*);

struct String {
    char storage[28];
    ~String();
};

struct MeshPtr {
    void* object;
    void* count;

    MeshPtr();
    MeshPtr(const MeshPtr&);
    ~MeshPtr();
};

__forceinline String::~String()
{
    string_destroy(this);
}

__forceinline MeshPtr::MeshPtr()
{
    mesh_default(this);
}

__forceinline MeshPtr::MeshPtr(const MeshPtr& other)
{
    mesh_copy(this, other);
}

struct Node {
    char padding[40];
    MeshPtr value;
};

struct Map;

struct Iterator {
    Map** owner;
    Node* node;
};

struct Map {
    Map** owner;
    char padding[20];
    Node* end;

    Iterator* find(Iterator* result, const String* key);
};

struct S {
    char padding[120];
    Map meshes;

    MeshPtr f(String key);
};

MeshPtr S::f(String key)
{
    Map& map = meshes;
    Iterator position;
    Iterator* found = map.find(&position, &key);
    Map** owner = found->owner;
    Node* finish = map.end;
    Node* node = found->node;
    Map** expected = map.owner;
    void (__cdecl *invalid)();

    if (!owner || owner != expected) {
        invalid = _invalid_parameter_noinfo;
        invalid();
    } else {
        invalid = _invalid_parameter_noinfo;
    }

    if (node != finish) {
        if (!owner)
            invalid();

        Map* container = owner ? *owner : 0;
        if (node == container->end)
            invalid();

        return MeshPtr(node->value);
    }

    return MeshPtr();
}
