// from server: 87% by atomic.potato
struct ConstraintSurfacePair {
    char padding[0x19];
    unsigned char field19;
    char padding2[2];
    int field1C;
    void Update(void* value);
};

extern "C" void CallTarget(void*);

void ConstraintSurfacePair::Update(void* value)
{
    if (field1C == 0) {
        field1C = (int)value;
        if (field19 == 0) {
            CallTarget(*(void**)((char*)value + 0x1a8));
            field19 = 1;
        }
    }
}
