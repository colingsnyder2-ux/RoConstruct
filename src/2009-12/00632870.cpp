// from server: 75% by atomic.potato
extern "C" void __stdcall sub_00537580(void *, void *, void *);

struct StarterGuiService
{
    int f(int, int);
};

int StarterGuiService::f(int a, int b)
{
    sub_00537580((char *)this + 16, (void *)b, (void *)a);
    return b;
}
