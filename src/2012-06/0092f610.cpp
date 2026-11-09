// from server: 100% by atomic.potato
struct S_func_0092f610 {
    void* vtable;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    int field_14;
    char field_18;
    int field_1c;
    S_func_0092f610* construct(int a, int b, int* c, int d, char e);
};

S_func_0092f610* S_func_0092f610::construct(int a, int b, int* c, int d, char e)
{
    vtable = (void*)0xbfec24;
    field_c = c[0];
    field_10 = c[1];
    field_14 = c[2];
    field_4 = a;
    field_8 = b;
    field_1c = d;
    field_18 = e;
    return this;
}
