// from server: 32% by colin
struct EventDesc {
    void construct(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m);
};

extern "C" void __stdcall sub_795DA0(void* dst, void* src);
extern "C" void __stdcall sub_795FA0(void* p);
extern "C" void __stdcall sub_687880(void* p);

void EventDesc::construct(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m)
{
    int local[12];
    local[0] = a;
    sub_795DA0(&local[2], &local[0]);
    sub_687880(this);
    sub_795FA0(&local[8]);
}
