// from server: 78% by atomic.potato
extern "C" int __cdecl function_00981ffa(int, int);

struct S
{
    int f();
    int padding_88[34];
    int member_88;
    int padding_bc[12];
    int member_bc;
};

int S::f()
{
    if (member_88 == 0)
    {
        return member_bc > member_88;
    }

    unsigned char value = 3;
    function_00981ffa(member_88, (int)&value);
    return value;
}
