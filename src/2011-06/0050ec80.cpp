// from server: 85% by atomic.potato
extern "C" int __stdcall setsockopt(int, int, int, const char*, int);

struct EventDesc
{
    int f(int);
};

int EventDesc::f(int a)
{
    char v;
    return setsockopt(a, 0, 14, &v, 4);
}
