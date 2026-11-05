// from server: 45% by tester
struct ContentProviderJob
{
    char pad[0x258];
    bool flag;
    char pad2[3];
    char field25c[4];

    int f(void* arg);
};

extern "C" void __stdcall G1_func_00b22654(void*);
extern "C" void __stdcall G1_func_00706540(void*);

struct Helper1
{
    bool f(void*);
};

struct Helper2
{
    int f(void*, void*);
};

int ContentProviderJob::f(void* arg)
{
    char local[0x24];
    G1_func_00b22654(local);
    *(int*)(local + 0x1c) = 0;
    *(int*)(local + 0x20) = 0;
    *(int*)(local + 0x2c) = 0;
    if (!this->flag)
    {
        Helper1* p = (Helper1*)((char*)this + 0x25c);
        while (p->f(local))
        {
            if (((Helper2*)this)->f(local, 0) != 0)
            {
                *(int*)(local + 0x2c) = -1;
                G1_func_00706540(local);
                return 0;
            }
            if (this->flag)
                break;
        }
    }
    *(int*)(local + 0x2c) = -1;
    G1_func_00706540(local);
    return 1;
}
