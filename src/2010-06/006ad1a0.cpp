// from server: 24% by atomic.potato
struct BoundPropGetSet {
    void* field0;
    void* field4;
    float field8;
    float field12;
    float field16;
    float field20;
    float field24;
    float field28;
    void __cdecl setVtable(void* a, float b, float c, float d, float e, float f, float g);
};

void BoundPropGetSet::setVtable(void* a, float b, float c, float d, float e, float f, float g) {
    BoundPropGetSet* p = (BoundPropGetSet*)a;
    p->field8 = b;
    p->field12 = c;
    p->field16 = d;
    p->field20 = e;
    p->field24 = f;
    p->field0 = 0;
    p->field4 = (void*)0xa1ac90;
    p->field28 = g;
}
