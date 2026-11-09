// from server: 61% by atomic.potato
extern "C" int sub_00743400(void*);

struct S
{
    int f(void*);
};

int S::f(void* value)
{
    char* base = *(char**)((char*)this + 0x2c);
    if (value)
        return sub_00743400(base + ((char*)value - (char*)0x1c));
    return sub_00743400(base);
}
