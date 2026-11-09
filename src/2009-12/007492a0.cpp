// from server: 78% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int __stdcall sub_749020(int, int, int);

int S::f(int value)
{
    return sub_749020(*(int*)((char*)this + 8), *(int*)((char*)this + 12), value);
}
