// from server: 48% by atomic.potato
extern "C" void* __cdecl sub_7f3860(unsigned int);

struct RbxPartBinding {
    void* field0;
    void* field4;
    void* field8;
    char pad[0x50];
    unsigned char field5c;
    unsigned char field5d;
};

RbxPartBinding* __cdecl create_RbxPartBinding();

RbxPartBinding* __cdecl create_RbxPartBinding()
{
    RbxPartBinding* p = (RbxPartBinding*)sub_7f3860(0x60);
    if (p)
    {
        p->field0 = 0;
    }
    if (p)
    {
        p->field4 = 0;
    }
    if (p)
    {
        p->field8 = 0;
    }
    p->field5c = 1;
    p->field5d = 0;
    return p;
}
