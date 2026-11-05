// from server: 100% by colin
struct Node {
    Node* field_0;
    Node* field_4;
    Node* field_8;
    char pad_0xC[0x19];
    char field_25;
};

struct Container {
    char pad_0x0[0x18];
    Node* field_18;
};

struct Target {
    void insert(Node* arg);
};

void Target::insert(Node* arg)
{
    Node* edx = arg;
    Node* eax = edx->field_0;
    Node* esi = eax->field_8;
    edx->field_0 = esi;
    esi = eax->field_8;
    if (esi->field_25 == 0)
        esi->field_4 = edx;
    esi = edx->field_4;
    eax->field_4 = esi;
    Container* ecx = (Container*)this;
    Node* c = ecx->field_18;
    if (edx == c->field_4)
    {
        c->field_4 = eax;
        eax->field_8 = edx;
        edx->field_4 = eax;
        return;
    }
    Node* ecx2 = edx->field_4;
    if (edx == ecx2->field_8)
    {
        ecx2->field_8 = eax;
        eax->field_8 = edx;
        edx->field_4 = eax;
        return;
    }
    ecx2->field_0 = eax;
    eax->field_8 = edx;
    edx->field_4 = eax;
}
