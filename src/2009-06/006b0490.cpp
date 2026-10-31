// from server: 97% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00608030  unit: RBX::BlockBlockContact  size: 296 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00608030
//
// 00608030  83ec08               sub esp, 8
// 00608033  53                   push ebx
// 00608034  55                   push ebp
// 00608035  56                   push esi
// 00608036  57                   push edi
// 00608037  8bf9                 mov edi, ecx
// 00608039  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0060803d  8bd9                 mov ebx, ecx
// 0060803f  81e301000080         and ebx, 0x80000001
// 00608045  7905                 jns 0x60804c
// 00608047  4b                   dec ebx
// 00608048  83cbfe               or ebx, 0xfffffffe
// 0060804b  43                   inc ebx
// 0060804c  8bc1                 mov eax, ecx
// 0060804e  99                   cdq 
// 0060804f  83e203               and edx, 3
// 00608052  03c2                 add eax, edx
// 00608054  c1f802               sar eax, 2
// 00608057  8d1c5b               lea ebx, [ebx + ebx*2]
// 0060805a  03d8                 add ebx, eax
// 0060805c  83f90c               cmp ecx, 0xc
// 0060805f  7e0d                 jle 0x60806e
// 00608061  8d4303               lea eax, [ebx + 3]
// 00608064  99                   cdq 
// 00608065  b906000000           mov ecx, 6
// 0060806a  f7f9                 idiv ecx
// 0060806c  8bda                 mov ebx, edx
// 0060806e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00608072  8be9                 mov ebp, ecx
// 00608074  81e501000080         and ebp, 0x80000001
// 0060807a  7905                 jns 0x608081
// 0060807c  4d                   dec ebp
// 0060807d  83cdfe               or ebp, 0xfffffffe
// 00608080  45                   inc ebp
// 00608081  8bc1                 mov eax, ecx
// 00608083  99                   cdq 
// 00608084  83e203               and edx, 3
// 00608087  03c2                 add eax, edx
// 00608089  c1f802               sar eax, 2
// 0060808c  8d6c6d00             lea ebp, [ebp + ebp*2]
// 00608090  03e8                 add ebp, eax
// 00608092  83f90c               cmp ecx, 0xc
// 00608095  7e0d                 jle 0x6080a4
// 00608097  8d4503               lea eax, [ebp + 3]
// 0060809a  99                   cdq 
// 0060809b  b906000000           mov ecx, 6
// 006080a0  f7f9                 idiv ecx
// 006080a2  8bea                 mov ebp, edx
// 006080a4  8b542420             mov edx, dword ptr [esp + 0x20]
// 006080a8  8b44970c             mov eax, dword ptr [edi + edx*4 + 0xc]
// 006080ac  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006080b0  8b548f0c             mov edx, dword ptr [edi + ecx*4 + 0xc]
// 006080b4  8b80a0000000         mov eax, dword ptr [eax + 0xa0]
// 006080ba  8b8aa0000000         mov ecx, dword ptr [edx + 0xa0]
// 006080c0  55                   push ebp
// 006080c1  53                   push ebx
// 006080c2  6a05                 push 5
// 006080c4  50                   push eax
// 006080c5  51                   push ecx
// 006080c6  8bcf                 mov ecx, edi
// 006080c8  e8f3fbffff           call 0x607cc0
// 006080cd  8bf0                 mov esi, eax
// 006080cf  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006080d3  8b4c870c             mov ecx, dword ptr [edi + eax*4 + 0xc]
// 006080d7  8b899c000000         mov ecx, dword ptr [ecx + 0x9c]
// 006080dd  b856555555           mov eax, 0x55555556
// 006080e2  f7eb                 imul ebx
// 006080e4  8bc2                 mov eax, edx
// 006080e6  c1e81f               shr eax, 0x1f
// 006080e9  03c2                 add eax, edx
// 006080eb  8d1440               lea edx, [eax + eax*2]
// 006080ee  8bc3                 mov eax, ebx
// 006080f0  2bc2                 sub eax, edx
// 006080f2  8b542428             mov edx, dword ptr [esp + 0x28]
// 006080f6  894c241c             mov dword ptr [esp + 0x1c], ecx
// 006080fa  d9448104             fld dword ptr [ecx + eax*4 + 4]
// 006080fe  8b4f74               mov ecx, dword ptr [edi + 0x74]
// 00608101  8b442420             mov eax, dword ptr [esp + 0x20]
// 00608105  d95c2414             fstp dword ptr [esp + 0x14]
// 00608109  894c2410             mov dword ptr [esp + 0x10], ecx
// 0060810d  8b4c870c             mov ecx, dword ptr [edi + eax*4 + 0xc]
// 00608111  8b899c000000         mov ecx, dword ptr [ecx + 0x9c]
// 00608117  52                   push edx
// 00608118  e8e3e9ffff           call 0x606b00
// 0060811d  8b542424             mov edx, dword ptr [esp + 0x24]
// 00608121  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00608125  52                   push edx
// 00608126  8bf8                 mov edi, eax
// 00608128  e8d3e9ffff           call 0x606b00
// 0060812d  d9442414             fld dword ptr [esp + 0x14]
// 00608131  89460c               mov dword ptr [esi + 0xc], eax
// 00608134  8b442410             mov eax, dword ptr [esp + 0x10]
// 00608138  d95e1c               fstp dword ptr [esi + 0x1c]
// 0060813b  897e10               mov dword ptr [esi + 0x10], edi
// 0060813e  5f                   pop edi
// 0060813f  895e20               mov dword ptr [esi + 0x20], ebx
// 00608142  896e24               mov dword ptr [esi + 0x24], ebp
// 00608145  894628               mov dword ptr [esi + 0x28], eax
// 00608148  c7460805000000       mov dword ptr [esi + 8], 5
// 0060814f  5e                   pop esi
// 00608150  5d                   pop ebp
// 00608151  5b                   pop ebx
// 00608152  83c408               add esp, 8
// 00608155  c21000               ret 0x10

struct Geometry {
    int reserved;
    float extent[3];
    int feature(int);
};

struct Primitive {
    char reserved[0x9c];
    Geometry* geometry;
    void* data;
};

struct Contact {
    char reserved0[8];
    int type;
    int feature0;
    int feature1;
    char reserved1[8];
    float extent;
    int face0;
    int face1;
    int value;
};

struct BlockBlockContact {
    char reserved0[12];
    Primitive* primitive[2];
    char reserved1[0x60];
    int value;

    Contact* create(void*, void*, int, int, int);
    void build(int, int, int, int);
};

void BlockBlockContact::build(int first, int second, int feature0, int feature1)
{
    int face0 = (feature0 % 2) * 3 + feature0 / 4;
    if (feature0 > 12)
        face0 = (face0 + 3) % 6;

    int face1 = (feature1 % 2) * 3 + feature1 / 4;
    if (feature1 > 12)
        face1 = (face1 + 3) % 6;

    Primitive* primitive1 = primitive[second];
    Primitive* primitive0 = primitive[first];
    void* data1 = primitive1->data;
    void* data0 = primitive0->data;
    Contact* contact = create(data0, data1, 5, face0, face1);

    struct Saved {
        int value;
        float extent;
    } saved;

    Geometry* geometry0 = primitive[first]->geometry;
    saved.extent = geometry0->extent[face0 % 3];
    saved.value = value;
    int id1 = primitive[second]->geometry->feature(feature1);
    int id0 = geometry0->feature(feature0);

    contact->feature0 = id0;
    contact->extent = saved.extent;
    contact->feature1 = id1;
    contact->face0 = face0;
    contact->face1 = face1;
    contact->value = saved.value;
    contact->type = 5;
}
