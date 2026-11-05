// from server: 53% by atomic.potato
extern "C" void __stdcall sub_004c8700(void*);
extern "C" void __stdcall sub_0053a820(void*, int, int);

struct VPlayerEventDesc
{
    char pad0[4];
    char field4[4];
    int init(int a, int b);
};

int VPlayerEventDesc::init(int a, int b)
{
    sub_004c8700(field4);
    sub_0053a820(this, a, b);
    return a;
}
