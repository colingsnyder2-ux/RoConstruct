// from server: 44% by atomic.potato
struct Node {
    Node* next;
    Node* prev;
    Node* parent;
    char pad[9];
    char color;
};

struct C {
    void* vtable;
    char pad0[0x30];
    Node* head1;
    Node* head2;
    char pad1[0x0c];
    int f50;
    int f54;
    int f58;
    char pad2[4];
    int f60;
    int f64;
    int f68;
    char pad3[4];
    int f70;
    int f74;
    int f78;
    char pad4[4];
    int f80;
    int f84;
    int f88;
    char pad5[4];
    int f90;
    int f94;
    int f98;
    char pad6[4];
    int fa0;
    int fa4;
    int fa8;
};

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __stdcall sub_6cb830(void*, void*);
extern "C" Node* __stdcall sub_7cd1f0(Node*);
extern "C" void __stdcall sub_467830(C*, int, const char*);
extern "C" void __stdcall sub_467790(C*, int, const char*, int);

void __cdecl sub_467c90(C* self)
{
    sub_6cb830(self, (void*)0xd6b9e0);
    self->vtable = (void*)0xb580f8;

    Node* n1 = (Node*)operator_new(0x18);
    if (n1) n1->next = 0;
    Node* r1 = sub_7cd1f0(n1);
    self->head1 = r1;
    r1->color = 1;
    r1->next = r1;
    r1->prev = r1;
    r1->parent = r1;

    Node* n2 = (Node*)operator_new(0x18);
    if (n2) n2->next = 0;
    Node* r2 = sub_7cd1f0(n2);
    self->head2 = r2;
    r2->color = 1;
    r2->next = r2;
    r2->prev = r2;
    r2->parent = r2;

    self->f50 = 0;
    self->f54 = 0;
    self->f58 = 0;
    self->f60 = 0;
    self->f64 = 0;
    self->f68 = 0;
    self->f70 = 0;
    self->f74 = 0;
    self->f78 = 0;
    self->f80 = 0;
    self->f84 = 0;
    self->f88 = 0;
    self->f90 = 0;
    self->f94 = 0;
    self->f98 = 0;
    self->fa0 = 0;
    self->fa4 = 0;
    self->fa8 = 0;

    sub_467830(self, 1, (const char*)0xb58318);
    sub_467830(self, 3, (const char*)0xb5830c);
    sub_467830(self, 4, (const char*)0xb58304);
    sub_467830(self, 5, (const char*)0xb582f8);
    sub_467790(self, 2, (const char*)0xb582e8, 1);
}
