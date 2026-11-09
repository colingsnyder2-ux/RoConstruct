// from server: 100% by colin
struct Func_6a79e0_result
{
    char pad[0x648];
    int field;
};

extern Func_6a79e0_result* func_6a79e0();

int func_6a7d70()
{
    return func_6a79e0()->field;
}
