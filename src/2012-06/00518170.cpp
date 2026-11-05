// from server: 48% by atomic.potato
extern "C" void* __cdecl sub_98211A(unsigned int size);

struct RbxPartBinding {
    void* field0;
    void* field4;
    void* field8;
    char pad[0x50];
    unsigned char field5C;
    unsigned char field5D;
};

RbxPartBinding* __cdecl create_RbxPartBinding()
{
    RbxPartBinding* p = (RbxPartBinding*)sub_98211A(0x60);
    if (p)
        p->field0 = 0;
    if (p)
        p->field4 = 0;
    if (p)
        p->field8 = 0;
    p->field5C = 1;
    p->field5D = 0;
    return p;
}
