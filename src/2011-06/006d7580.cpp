// from server: 100% by atomic.potato
typedef int BOOL;

struct Instance;

extern "C" BOOL sub_0080B2EA(Instance*, int, const void*, const void*, int);

struct JointsService
{
    BOOL f(Instance*);
};

BOOL JointsService::f(Instance* a)
{
    return sub_0080B2EA(a, 0, (const void*)0xC071F8, (const void*)0xC70290, 0) != 0;
}
