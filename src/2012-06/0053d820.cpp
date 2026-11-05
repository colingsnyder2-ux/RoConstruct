// from server: 92% by atomic.potato
struct RBX_StringValue {
    char pad[0x94];
    unsigned int field_94;
    int getValue();
};

extern "C" int __cdecl sub_680CA0();

int RBX_StringValue::getValue()
{
    unsigned int a = field_94 / 100;
    int b = 1;
    unsigned int *p;
    if (a > 1)
        p = &a;
    else
        p = (unsigned int *)&b;
    return sub_680CA0() + *p;
}
