// from server: 50% by atomic.potato
extern "C" int __cdecl sub_809f4a(int, int);

struct S
{
    int padding[0x26];
    int value;
    int f();
};

int S::f()
{
    unsigned char result;
    if (value == 0)
        return 0;

    unsigned char input = 0;
    sub_809f4a(value, (int)&input);
    result = (unsigned char)(-(value - 0x24) >= 0);
    return result & input;
}
