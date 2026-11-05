// from server: 96% by atomic.potato
extern "C" int __cdecl sub_540150(char *, const char *);
extern "C" int __cdecl sub_5338f0(int, int);

int sub_5409a0(const char *value)
{
    char buffer[0x30];
    int result = sub_540150(buffer, value);
    return sub_5338f0(*(int *)((char *)&value + 0x3c), result);
}
