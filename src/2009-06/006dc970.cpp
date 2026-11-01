// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0065a870  unit: RBX::BallBallContact  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065a870
//
// 0065a870  51                   push ecx
// 0065a871  53                   push ebx
// 0065a872  55                   push ebp
// 0065a873  56                   push esi
// 0065a874  57                   push edi
// 0065a875  8be9                 mov ebp, ecx
// 0065a877  6a01                 push 1
// 0065a879  8db580000000         lea esi, [ebp + 0x80]
// 0065a87f  6a00                 push 0
// 0065a881  8bce                 mov ecx, esi
// 0065a883  e8e8f1f3ff           call 0x599a70
// 0065a888  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0065a88c  e83fd3f8ff           call 0x5e7bd0
// 0065a891  8bd8                 mov ebx, eax
// 0065a893  85db                 test ebx, ebx
// 0065a895  7478                 je 0x65a90f
// 0065a897  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 0065a89a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0065a89e  3bcf                 cmp ecx, edi
// 0065a8a0  7503                 jne 0x65a8a5
// 0065a8a2  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 0065a8a5  53                   push ebx
// 0065a8a6  e835d3f8ff           call 0x5e7be0
// 0065a8ab  8bd8                 mov ebx, eax
// 0065a8ad  8b442418             mov eax, dword ptr [esp + 0x18]
// 0065a8b1  57                   push edi
// 0065a8b2  50                   push eax
// 0065a8b3  8bcd                 mov ecx, ebp
// 0065a8b5  e816ebffff           call 0x6593d0
// 0065a8ba  84c0                 test al, al
// 0065a8bc  754d                 jne 0x65a90b
// 0065a8be  8b4604               mov eax, dword ptr [esi + 4]
// 0065a8c1  3b4608               cmp eax, dword ptr [esi + 8]
// 0065a8c4  8b0e                 mov ecx, dword ptr [esi]
// 0065a8c6  7d0e                 jge 0x65a8d6
// 0065a8c8  8d0481               lea eax, [ecx + eax*4]
// 0065a8cb  85c0                 test eax, eax
// 0065a8cd  7402                 je 0x65a8d1
// 0065a8cf  8938                 mov dword ptr [eax], edi
// 0065a8d1  ff4604               inc dword ptr [esi + 4]
// 0065a8d4  eb35                 jmp 0x65a90b
// 0065a8d6  8d542410             lea edx, [esp + 0x10]
// 0065a8da  3bd1                 cmp edx, ecx
// 0065a8dc  7219                 jb 0x65a8f7
// 0065a8de  8d0c81               lea ecx, [ecx + eax*4]
// 0065a8e1  3bd1                 cmp edx, ecx
// 0065a8e3  7312                 jae 0x65a8f7
// 0065a8e5  8d442410             lea eax, [esp + 0x10]
// 0065a8e9  50                   push eax
// 0065a8ea  8bce                 mov ecx, esi
// 0065a8ec  897c2414             mov dword ptr [esp + 0x14], edi
// 0065a8f0  e89bf8f3ff           call 0x59a190
// 0065a8f5  eb14                 jmp 0x65a90b
// 0065a8f7  6a00                 push 0
// 0065a8f9  40                   inc eax
// 0065a8fa  50                   push eax
// 0065a8fb  8bce                 mov ecx, esi
// 0065a8fd  e86ef1f3ff           call 0x599a70
// 0065a902  8b4e04               mov ecx, dword ptr [esi + 4]
// 0065a905  8b16                 mov edx, dword ptr [esi]
// 0065a907  897c8afc             mov dword ptr [edx + ecx*4 - 4], edi
// 0065a90b  85db                 test ebx, ebx
// 0065a90d  7588                 jne 0x65a897
// 0065a90f  33ff                 xor edi, edi
// 0065a911  39bd84000000         cmp dword ptr [ebp + 0x84], edi
// 0065a917  7e23                 jle 0x65a93c
// 0065a919  8da42400000000       lea esp, [esp]
// 0065a920  8b06                 mov eax, dword ptr [esi]
// 0065a922  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 0065a925  8b542418             mov edx, dword ptr [esp + 0x18]
// 0065a929  51                   push ecx
// 0065a92a  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0065a92d  52                   push edx
// 0065a92e  e8cd22fbff           call 0x60cc00
// 0065a933  47                   inc edi
// 0065a934  3bbd84000000         cmp edi, dword ptr [ebp + 0x84]
// 0065a93a  7ce4                 jl 0x65a920
// 0065a93c  5f                   pop edi
// 0065a93d  5e                   pop esi
// 0065a93e  5d                   pop ebp
// 0065a93f  5b                   pop ebx
// 0065a940  59                   pop ecx
// 0065a941  c20400               ret 4

struct Geometry;
struct Edge;

struct Geometry {
    Edge* getFirstB();
    Edge* getNextB(Edge* edge);
};

struct Edge {
    char pad[12];
    Geometry* g0;
    Geometry* g1;
};

struct GeometryArray {
    Geometry** data;
    int count;
    int capacity;

    void resize(int size, bool preserve);
    void appendSlow(Geometry* const& value);
};

struct Controller {
    void apply(Geometry* first, Geometry* second);
};

struct Contact {
    char pad0[8];
    Controller* controller;
    char pad1[0x80 - 12];
    GeometryArray pending;

    bool intersects(Geometry* first, Geometry* second);
    void process(Geometry* geometry);
};

void Contact::process(Geometry* geometry)
{
    GeometryArray& list = pending;
    list.resize(0, true);

    Edge* edge = geometry->getFirstB();
    while (edge) {
        Geometry* other = edge->g0;
        if (geometry == other)
            other = edge->g1;

        edge = geometry->getNextB(edge);

        if (!intersects(geometry, other)) {
            Geometry* value;
            if (list.count < list.capacity) {
                Geometry** slot = list.data + list.count;
                if (slot)
                    *slot = other;
                ++list.count;
            } else if (
                reinterpret_cast<unsigned int>(&value) >=
                    reinterpret_cast<unsigned int>(list.data) &&
                reinterpret_cast<unsigned int>(&value) <
                    reinterpret_cast<unsigned int>(list.data + list.count)) {
                Geometry* copy = other;
                list.appendSlow(copy);
            } else {
                list.resize(list.count + 1, false);
                list.data[list.count - 1] = other;
            }
        }
    }

    for (int i = 0; i < pending.count; ++i)
        controller->apply(geometry, list.data[i]);
}
