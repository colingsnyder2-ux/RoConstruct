// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00671f00  unit: RBX::AdornRbxGfx  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00671f00
//
// 00671f00  51                   push ecx
// 00671f01  8b442408             mov eax, dword ptr [esp + 8]
// 00671f05  890c24               mov dword ptr [esp], ecx
// 00671f08  8b4804               mov ecx, dword ptr [eax + 4]
// 00671f0b  55                   push ebp
// 00671f0c  33ed                 xor ebp, ebp
// 00671f0e  ff15b84c8000         call dword ptr [0x804cb8]
// 00671f14  33c9                 xor ecx, ecx
// 00671f16  663bc8               cmp cx, ax
// 00671f19  736b                 jae 0x671f86
// 00671f1b  53                   push ebx
// 00671f1c  56                   push esi
// 00671f1d  57                   push edi
// 00671f1e  8bff                 mov edi, edi
// 00671f20  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00671f24  e837feffff           call 0x671d60
// 00671f29  8b542418             mov edx, dword ptr [esp + 0x18]
// 00671f2d  8b4a04               mov ecx, dword ptr [edx + 4]
// 00671f30  55                   push ebp
// 00671f31  8bd8                 mov ebx, eax
// 00671f33  ff15bc4c8000         call dword ptr [0x804cbc]
// 00671f39  50                   push eax
// 00671f3a  8bcb                 mov ecx, ebx
// 00671f3c  e8afe9daff           call 0x4208f0
// 00671f41  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00671f45  8b442420             mov eax, dword ptr [esp + 0x20]
// 00671f49  8dbbf0000000         lea edi, [ebx + 0xf0]
// 00671f4f  b910000000           mov ecx, 0x10
// 00671f54  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00671f56  50                   push eax
// 00671f57  8bcb                 mov ecx, ebx
// 00671f59  e842310100           call 0x6850a0
// 00671f5e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00671f62  8b8998000000         mov ecx, dword ptr [ecx + 0x98]
// 00671f68  53                   push ebx
// 00671f69  e8e2ba0000           call 0x67da50
// 00671f6e  8b542418             mov edx, dword ptr [esp + 0x18]
// 00671f72  8b4a04               mov ecx, dword ptr [edx + 4]
// 00671f75  45                   inc ebp
// 00671f76  ff15b84c8000         call dword ptr [0x804cb8]
// 00671f7c  0fb7c0               movzx eax, ax
// 00671f7f  3be8                 cmp ebp, eax
// 00671f81  7c9d                 jl 0x671f20
// 00671f83  5f                   pop edi
// 00671f84  5e                   pop esi
// 00671f85  5b                   pop ebx
// 00671f86  5d                   pop ebp
// 00671f87  59                   pop ecx
// 00671f88  c20c00               ret 0xc

struct Mesh;

extern unsigned short (__thiscall *getNumSubMeshes)(const Mesh*);
extern void* (__thiscall *getSubMesh)(const Mesh*, unsigned short);

struct MeshRef {
    void* control;
    Mesh* mesh;
};

struct Matrix {
    float elements[16];
};

struct RenderObject {
    char padding0[84];
    int m_x;
    char padding1[152];
    Matrix matrix;

    void f(int value);
    void setState(void* value);
};

struct Sink {
    void f(void* value);
};

struct S {
    char padding[0x98];
    Sink* sink;

    RenderObject* create();
    void f(const MeshRef& mesh, const Matrix& matrix, void* state);
};

void S::f(const MeshRef& mesh, const Matrix& matrix, void* state)
{
    for (int i = 0; i < getNumSubMeshes(mesh.mesh); ++i) {
        RenderObject* object = create();
        object->f((int)getSubMesh(mesh.mesh, (unsigned short)i));
        object->matrix = matrix;
        object->setState(state);
        sink->f(object);
    }
}
