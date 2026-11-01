// from server: 100% by atomic.potato
extern "C" int __cdecl sub_006A17C6(void*, void*, void*, void*, void*);

struct Team
{
    int f(void*);
};

int Team::f(void* value)
{
    return sub_006A17C6(value, 0, (void*)0x92907C, (void*)0x9455E0, 0) != 0;
}
