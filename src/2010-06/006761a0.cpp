// from server: 100% by atomic.potato
extern "C" int __cdecl sub_708f20(const char *, int);

char f(int value)
{
    return sub_708f20((const char *)value, 0) != 0;
}
