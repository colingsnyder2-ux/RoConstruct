// from server: 94% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00607f90  unit: RBX::BlockBlockContact  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00607f90
//
// 00607f90  53                   push ebx
// 00607f91  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00607f95  55                   push ebp
// 00607f96  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00607f9a  56                   push esi
// 00607f9b  57                   push edi
// 00607f9c  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00607fa0  8bf1                 mov esi, ecx
// 00607fa2  8b44ae0c             mov eax, dword ptr [esi + ebp*4 + 0xc]
// 00607fa6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00607faa  8b548e0c             mov edx, dword ptr [esi + ecx*4 + 0xc]
// 00607fae  8b80a0000000         mov eax, dword ptr [eax + 0xa0]
// 00607fb4  8b8aa0000000         mov ecx, dword ptr [edx + 0xa0]
// 00607fba  57                   push edi
// 00607fbb  53                   push ebx
// 00607fbc  6a04                 push 4
// 00607fbe  50                   push eax
// 00607fbf  51                   push ecx
// 00607fc0  8bce                 mov ecx, esi
// 00607fc2  e8f9fcffff           call 0x607cc0
// 00607fc7  8bcf                 mov ecx, edi
// 00607fc9  c1e104               shl ecx, 4
// 00607fcc  8b89c8ae8400         mov ecx, dword ptr [ecx + 0x84aec8]
// 00607fd2  8d1449               lea edx, [ecx + ecx*2]
// 00607fd5  8b4cae0c             mov ecx, dword ptr [esi + ebp*4 + 0xc]
// 00607fd9  8b899c000000         mov ecx, dword ptr [ecx + 0x9c]
// 00607fdf  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 00607fe2  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00607fe6  8b74ae0c             mov esi, dword ptr [esi + ebp*4 + 0xc]
// 00607fea  8bb69c000000         mov esi, dword ptr [esi + 0x9c]
// 00607ff0  8b7610               mov esi, dword ptr [esi + 0x10]
// 00607ff3  8d1491               lea edx, [ecx + edx*4]
// 00607ff6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00607ffa  8d0c8b               lea ecx, [ebx + ecx*4]
// 00607ffd  8b0c8dc8ae8400       mov ecx, dword ptr [ecx*4 + 0x84aec8]
// 00608004  8d0c49               lea ecx, [ecx + ecx*2]
// 00608007  897824               mov dword ptr [eax + 0x24], edi
// 0060800a  5f                   pop edi
// 0060800b  8d0c8e               lea ecx, [esi + ecx*4]
// 0060800e  5e                   pop esi
// 0060800f  5d                   pop ebp
// 00608010  895828               mov dword ptr [eax + 0x28], ebx
// 00608013  89480c               mov dword ptr [eax + 0xc], ecx
// 00608016  895010               mov dword ptr [eax + 0x10], edx
// 00608019  c7400804000000       mov dword ptr [eax + 8], 4
// 00608020  5b                   pop ebx
// 00608021  c21400               ret 0x14

struct Vector3 {
    float x, y, z;
};

struct Geometry {
    char pad[0x10];
    Vector3* vertices;
};

struct Object {
    char pad[0x9c];
    Geometry* geometry;
    void* data;
};

struct Contact {
    char pad0[8];
    int type;
    Vector3* first;
    Vector3* second;
    char pad1[0x10];
    int secondIndex;
    int firstIndex;
};

struct S {
    char pad[0x0c];
    Object* objects[2];

    Contact* create(void*, void*, int, int, int);
    Contact* f(int, int, int, int, int);
};

Contact* S::f(int firstObject, int secondObject, int firstIndex,
              int faceIndex, int secondIndex)
{
    Object* secondObjectPtr = objects[secondObject];
    Object* firstObjectPtr = objects[firstObject];
    void* secondData = secondObjectPtr->data;
    void* firstData = firstObjectPtr->data;
    Contact* result = create(firstData, secondData, 4, firstIndex, secondIndex);

    int (*vertexIndices)[4] = reinterpret_cast<int (*)[4]>(0x84aec8);
    int offset = vertexIndices[secondIndex][0] * 3;
    Vector3* second = reinterpret_cast<Vector3*>(
        reinterpret_cast<float*>(objects[secondObject]->geometry->vertices)
        + offset);
    Vector3* first = objects[firstObject]->geometry->vertices
                   + vertexIndices[faceIndex][firstIndex];

    result->secondIndex = secondIndex;
    result->firstIndex = firstIndex;
    result->first = first;
    result->second = second;
    result->type = 4;
    return result;
}
