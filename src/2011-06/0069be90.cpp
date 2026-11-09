// from server: 73% by atomic.potato
struct S
{
    int Get();
};

extern "C" int __stdcall Helper(int, int);

int S::Get()
{
    return Helper((int)((char*)this + 0x94), *((int*)((char*)this + 0x90)));
}
