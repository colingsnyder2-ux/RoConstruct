// from server: 51% by atomic.potato
extern "C" void* __cdecl sub_98211a(unsigned int);
extern "C" void __stdcall sub_6cb830(void*, void*);
extern "C" void __stdcall sub_467830(void*, int, void*);

struct Node {
    Node* next;
    Node* prev;
    Node* parent;
    char pad[9];
    unsigned char flag;
};

struct VSpecialShape {
    void* vtable;
    char pad1[0x30];
    Node* head34;
    int count34;
    char pad2[4];
    Node* head40;
    int count40;
    char pad3[0x30];
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    int f74;
    int f78;
    int f7c;
    int f80;
    int f84;
    int f88;
    int f8c;
    int f90;
    int f94;
    int f98;
    int f9c;
    int fa0;
    int fa4;
    int fa8;

    void ctor(void* a, void* b);
};

void VSpecialShape::ctor(void* a, void* b)
{
    sub_6cb830(this, a);
    this->vtable = (void*)0xbaf7c4;

    Node* n = (Node*)sub_98211a(0x18);
    if (n) n->next = 0;
    Node* p = (Node*)((char*)n + 4);
    if (p) { }
    this->head34 = p;
    p->flag = 1;
    p->next = p;
    p->prev = p;
    p->parent = p;
    this->count34 = 0;

    Node* n2 = (Node*)sub_98211a(0x18);
    if (n2) n2->next = 0;
    Node* p2 = (Node*)((char*)n2 + 4);
    if (p2) { }
    this->head40 = p2;
    p2->flag = 1;
    p2->next = p2;
    p2->prev = p2;
    p2->parent = p2;
    this->count40 = 0;

    this->f50 = 0;
    this->f54 = 0;
    this->f58 = 0;
    this->f5c = 0;
    this->f60 = 0;
    this->f64 = 0;
    this->f68 = 0;
    this->f6c = 0;
    this->f70 = 0;
    this->f74 = 0;
    this->f78 = 0;
    this->f7c = 0;
    this->f80 = 0;
    this->f84 = 0;
    this->f88 = 0;
    this->f8c = 0;
    this->f90 = 0;
    this->f94 = 0;
    this->f98 = 0;
    this->f9c = 0;
    this->fa0 = 0;
    this->fa4 = 0;
    this->fa8 = 0;

    sub_467830(this, 0, (void*)0xb70654);
    sub_467830(this, 1, (void*)0xb6b838);
    sub_467830(this, 2, (void*)0xbb25f0);
    sub_467830(this, 7, (void*)0xbb25e8);
    sub_467830(this, 8, (void*)0xbb25e0);
    sub_467830(this, 9, (void*)0xbb25d0);
    sub_467830(this, 0xa, (void*)0xbb25c0);
    sub_467830(this, 0xb, (void*)0xbb25b4);
    sub_467830(this, 6, (void*)0xbad134);
    sub_467830(this, 3, (void*)0xbb25ac);
    sub_467830(this, 4, (void*)0xbb25a0);
    sub_467830(this, 5, (void*)0xbb2324);
}
