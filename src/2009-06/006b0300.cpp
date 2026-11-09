// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 00607ea0  unit: RBX::BlockBlockContact  size: 238 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00607ea0
//
// 00607ea0  53                   push ebx
// 00607ea1  55                   push ebp
// 00607ea2  56                   push esi
// 00607ea3  57                   push edi
// 00607ea4  8bf9                 mov edi, ecx
// 00607ea6  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00607eaa  8bd9                 mov ebx, ecx
// 00607eac  81e301000080         and ebx, 0x80000001
// 00607eb2  7905                 jns 0x607eb9
// 00607eb4  4b                   dec ebx
// 00607eb5  83cbfe               or ebx, 0xfffffffe
// 00607eb8  43                   inc ebx
// 00607eb9  8bc1                 mov eax, ecx
// 00607ebb  99                   cdq 
// 00607ebc  83e203               and edx, 3
// 00607ebf  03c2                 add eax, edx
// 00607ec1  c1f802               sar eax, 2
// 00607ec4  8d1c5b               lea ebx, [ebx + ebx*2]
// 00607ec7  03d8                 add ebx, eax
// 00607ec9  83f90c               cmp ecx, 0xc
// 00607ecc  7e0d                 jle 0x607edb
// 00607ece  8d4303               lea eax, [ebx + 3]
// 00607ed1  99                   cdq 
// 00607ed2  b906000000           mov ecx, 6
// 00607ed7  f7f9                 idiv ecx
// 00607ed9  8bda                 mov ebx, edx
// 00607edb  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00607edf  8be9                 mov ebp, ecx
// 00607ee1  81e501000080         and ebp, 0x80000001
// 00607ee7  7905                 jns 0x607eee
// 00607ee9  4d                   dec ebp
// 00607eea  83cdfe               or ebp, 0xfffffffe
// 00607eed  45                   inc ebp
// 00607eee  8bc1                 mov eax, ecx
// 00607ef0  99                   cdq 
// 00607ef1  83e203               and edx, 3
// 00607ef4  03c2                 add eax, edx
// 00607ef6  c1f802               sar eax, 2
// 00607ef9  8d6c6d00             lea ebp, [ebp + ebp*2]
// 00607efd  03e8                 add ebp, eax
// 00607eff  83f90c               cmp ecx, 0xc
// 00607f02  7e0d                 jle 0x607f11
// 00607f04  8d4503               lea eax, [ebp + 3]
// 00607f07  99                   cdq 
// 00607f08  b906000000           mov ecx, 6
// 00607f0d  f7f9                 idiv ecx
// 00607f0f  8bea                 mov ebp, edx
// 00607f11  8b542418             mov edx, dword ptr [esp + 0x18]
// 00607f15  8b44970c             mov eax, dword ptr [edi + edx*4 + 0xc]
// 00607f19  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00607f1d  8b548f0c             mov edx, dword ptr [edi + ecx*4 + 0xc]
// 00607f21  8b80a0000000         mov eax, dword ptr [eax + 0xa0]
// 00607f27  8b8aa0000000         mov ecx, dword ptr [edx + 0xa0]
// 00607f2d  55                   push ebp
// 00607f2e  53                   push ebx
// 00607f2f  6a06                 push 6
// 00607f31  50                   push eax
// 00607f32  51                   push ecx
// 00607f33  8bcf                 mov ecx, edi
// 00607f35  e886fdffff           call 0x607cc0
// 00607f3a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00607f3e  8b548f0c             mov edx, dword ptr [edi + ecx*4 + 0xc]
// 00607f42  8b8a9c000000         mov ecx, dword ptr [edx + 0x9c]
// 00607f48  8bf0                 mov esi, eax
// 00607f4a  8b442420             mov eax, dword ptr [esp + 0x20]
// 00607f4e  50                   push eax
// 00607f4f  e8acebffff           call 0x606b00
// 00607f54  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00607f58  8b548f0c             mov edx, dword ptr [edi + ecx*4 + 0xc]
// 00607f5c  8b8a9c000000         mov ecx, dword ptr [edx + 0x9c]
// 00607f62  89442420             mov dword ptr [esp + 0x20], eax
// 00607f66  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00607f6a  50                   push eax
// 00607f6b  e890ebffff           call 0x606b00
// 00607f70  89460c               mov dword ptr [esi + 0xc], eax
// 00607f73  8b442420             mov eax, dword ptr [esp + 0x20]
// 00607f77  5f                   pop edi
// 00607f78  895e20               mov dword ptr [esi + 0x20], ebx
// 00607f7b  896e24               mov dword ptr [esi + 0x24], ebp
// 00607f7e  894610               mov dword ptr [esi + 0x10], eax
// 00607f81  c7460806000000       mov dword ptr [esi + 8], 6
// 00607f88  5e                   pop esi
// 00607f89  5d                   pop ebp
// 00607f8a  5b                   pop ebx
// 00607f8b  c21000               ret 0x10

struct FaceMap {
    int lookup(int face);
};

struct Body {
    char reserved[0xe0];
    FaceMap* faces;
    int geometry;
};

struct Contact {
    int reserved0[2];
    int kind;
    int firstFace;
    int secondFace;
    int reserved1[3];
    int firstIndex;
    int secondIndex;
};

struct S {
    int reserved[4];
    Body* bodies[2];

    Contact* create(int first, int second, int kind, int firstIndex, int secondIndex);
    void f(int firstBody, int secondBody, int firstFace, int secondFace);
};

void S::f(int firstBody, int secondBody, int firstFace, int secondFace)
{
    int firstIndex = (firstFace % 2) * 3 + firstFace / 4;
    if (firstFace > 12)
        firstIndex = (firstIndex + 3) % 6;

    int secondIndex = (secondFace % 2) * 3 + secondFace / 4;
    if (secondFace > 12)
        secondIndex = (secondIndex + 3) % 6;

    Body* second = bodies[secondBody];
    Body* first = bodies[firstBody];
    int secondGeometry = second->geometry;
    int firstGeometry = first->geometry;

    Contact* contact = create(
        firstGeometry, secondGeometry, 6, firstIndex, secondIndex);

    int mappedSecond = bodies[secondBody]->faces->lookup(secondFace);
    int mappedFirst = bodies[firstBody]->faces->lookup(firstFace);

    contact->firstFace = mappedFirst;
    contact->firstIndex = firstIndex;
    contact->secondIndex = secondIndex;
    contact->secondFace = mappedSecond;
    contact->kind = 6;
}
