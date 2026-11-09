// from server: 100% by atomic.potato
struct S_func_0092f680
{
    void* vftable;
    int field_04;
    int field_08;
    int field_0c;
    int field_10;
    int field_14;
    char field_18;
    int field_1c;

    S_func_0092f680* construct(const S_func_0092f680* other);
};

S_func_0092f680* S_func_0092f680::construct(const S_func_0092f680* other)
{
    vftable = (void*)0xbfec24;
    field_04 = other->field_04;
    field_08 = other->field_08;
    field_0c = other->field_0c;
    field_10 = other->field_10;
    field_14 = other->field_14;
    field_18 = other->field_18;
    field_1c = other->field_1c;
    return this;
}
