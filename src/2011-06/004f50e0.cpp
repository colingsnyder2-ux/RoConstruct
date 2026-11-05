// from server: 71% by atomic.potato
struct S
{
    int f();

    char pad[0x1cf0];
    int member_1cf0;
    char pad2[4];
    int member_1cf8;
    int member_1cfc;
};

extern "C" int __stdcall func_004efaf0(int, int);

int S::f()
{
    if (member_1cf0)
        return func_004efaf0(member_1cf8, member_1cfc);
    return 0;
}
