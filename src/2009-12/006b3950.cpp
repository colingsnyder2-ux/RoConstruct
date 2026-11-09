// from server: 71% by atomic.potato
extern "C" int __cdecl sub_7F37AC(int value, unsigned char* result);

struct S {
    unsigned char f(int);
    int member_9C;
};

unsigned char S::f(int)
{
    if (member_9C == 0)
        return 1;

    unsigned char result;
    if (sub_7F37AC(member_9C, &result) == 0x24)
        return 1;

    return result;
}
