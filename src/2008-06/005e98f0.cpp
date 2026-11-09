// from server: 100% by colin
// from server: 92% by king_originala
// roc 2008-06 005e98f0  unit: RBX::PhysicsService  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e98f0
//
// 005e98f0  56                   push esi
// 005e98f1  8bf1                 mov esi, ecx
// 005e98f3  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 005e98f9  57                   push edi
// 005e98fa  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005e98fe  8d8eac000000         lea ecx, [esi + 0xac]
// 005e9904  8d54240c             lea edx, [esp + 0xc]
// 005e9908  52                   push edx
// 005e9909  897c2410             mov dword ptr [esp + 0x10], edi
// 005e990d  894750               mov dword ptr [edi + 0x50], eax
// 005e9910  e87b08fbff           call 0x59a190
// 005e9915  897758               mov dword ptr [edi + 0x58], esi
// 005e9918  8b8e88000000         mov ecx, dword ptr [esi + 0x88]
// 005e991e  57                   push edi
// 005e991f  e8bc0a0600           call 0x64a3e0
// 005e9924  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 005e992a  57                   push edi
// 005e992b  e800330200           call 0x60cc30
// 005e9930  5f                   pop edi
// 005e9931  5e                   pop esi
// 005e9932  c20400               ret 4

struct PhysicsService;

struct Part {
    char padding0[0x50];
    int index;
    char padding1[4];
    PhysicsService* service;
};

struct PartList {
    Part** data;
    int size;
    int capacity;
    void append(Part* const* part);
};

struct CleanStage {
    void f(Part* part);
};

struct FinalStage {
    void f(Part* part);
};

struct PhysicsService {
    char padding0[0x84];
    FinalStage* finalStage;
    CleanStage* cleanStage;
    char padding1[0x20];
    PartList parts;

    void f(Part* part);
};

void PhysicsService::f(Part* part)
{
    PartList* list = &parts;
    Part* entry = part;
    part->index = list->size;
    list->append(&entry);
    part->service = this;
    cleanStage->f(part);
    finalStage->f(part);
}
