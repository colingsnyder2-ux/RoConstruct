// from server: 84% by EspClaude
// from server: 73% by colin
// roc 2007-08 005b5170  unit: RBX::Primitive  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005b5170
//
// 005b5170  56                   push esi
// 005b5171  8bf1                 mov esi, ecx
// 005b5173  57                   push edi
// 005b5174  8b7e64               mov edi, dword ptr [esi + 0x64]
// 005b5177  8bcf                 mov ecx, edi
// 005b5179  e882aff7ff           call 0x530100
// 005b517e  81c784000000         add edi, 0x84
// 005b5184  57                   push edi
// 005b5185  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005b5189  8bcf                 mov ecx, edi
// 005b518b  e850dfebff           call 0x4730e0
// 005b5190  84c0                 test al, al
// 005b5192  7468                 je 0x5b51fc
// 005b5194  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 005b5197  85c9                 test ecx, ecx
// 005b5199  7523                 jne 0x5b51be
// 005b519b  8b4e64               mov ecx, dword ptr [esi + 0x64]
// 005b519e  57                   push edi
// 005b519f  e86cce0200           call 0x5e2010
// 005b51a4  8b4e68               mov ecx, dword ptr [esi + 0x68]
// 005b51a7  e884da0200           call 0x5e2c30
// 005b51ac  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 005b51af  85c9                 test ecx, ecx
// 005b51b1  7449                 je 0x5b51fc
// 005b51b3  56                   push esi
// 005b51b4  e8c73effff           call 0x5a9080
// 005b51b9  5f                   pop edi
// 005b51ba  5e                   pop esi
// 005b51bb  c20400               ret 4
// 005b51be  8b4120               mov eax, dword ptr [ecx + 0x20]
// 005b51c1  85c0                 test eax, eax
// 005b51c3  7408                 je 0x5b51cd
// 005b51c5  8b4008               mov eax, dword ptr [eax + 8]
// 005b51c8  397024               cmp dword ptr [eax + 0x24], esi
// 005b51cb  eb03                 jmp 0x5b51d0
// 005b51cd  397124               cmp dword ptr [ecx + 0x24], esi
// 005b51d0  0f94c0               sete al
// 005b51d3  84c0                 test al, al
// 005b51d5  7425                 je 0x5b51fc
// 005b51d7  57                   push edi
// 005b51d8  56                   push esi
// 005b51d9  e8a2680500           call 0x60ba80
// 005b51de  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 005b51e1  51                   push ecx
// 005b51e2  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 005b51e5  e88643ffff           call 0x5a9570
// 005b51ea  8b5620               mov edx, dword ptr [esi + 0x20]
// 005b51ed  837a2800             cmp dword ptr [edx + 0x28], 0
// 005b51f1  7509                 jne 0x5b51fc
// 005b51f3  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 005b51f6  56                   push esi
// 005b51f7  e8c43fffff           call 0x5a91c0

struct Primitive;
struct Node24 { char pad[0x24]; Primitive* owner; };
struct Link8 { char pad[8]; Node24* node; };
struct Joint20 {
    char pad[0x20];
    Link8* link;
    Primitive* owner;
    int count;
    bool isOwner(const Primitive* p) const {
        return (link ? link->node->owner == p : owner == p);
    }
};
void __stdcall func_60ba80(Primitive* p, void* arg);

struct Primitive {
    char pad0[0x1c];
    void* field1c;
    void* field20;
    char pad24[0x40];
    void* field64;
    void* field68;

    void method_530100();
    bool method_4730e0(void* arg);
    void method_5e2010(void* arg);
    void method_5e2c30();
    void method_5a9080(void* arg);
    void method_5a9570(void* arg);
    void method_5a91c0(void* arg);

    void func(void* arg);
};

void Primitive::func(void* arg) {
    Primitive* p = (Primitive*)field64;
    p->method_530100();
    void* p84 = (char*)p + 0x84;
    if (((Primitive*)arg)->method_4730e0(p84)) {
        Joint20* f20 = (Joint20*)field20;
        if (f20 == 0) {
            ((Primitive*)field64)->method_5e2010(arg);
            ((Primitive*)field68)->method_5e2c30();
            if (field1c != 0)
                ((Primitive*)field1c)->method_5a9080(this);
        } else {
            if (f20->isOwner(this)) {
                func_60ba80(this, arg);
                ((Primitive*)field1c)->method_5a9570(field20);
                if (((Joint20*)field20)->count == 0)
                    ((Primitive*)field1c)->method_5a91c0(this);
            }
        }
    }
}
