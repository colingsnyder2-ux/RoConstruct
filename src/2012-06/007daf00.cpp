// from server: 62% by atomic.potato
struct S
{
    int f(void* p);
    int g(void* p);
};

extern "C" int target(char*);

int S::f(void* p)
{
    char* q = (char*)p;
    if (q)
        q -= 0x1c;
    return target(*(char**)((char*)this + 0x2c) + (int)q);
}

int S::g(void* p)
{
    return target(*(char**)((char*)this + 0x2c));
}
