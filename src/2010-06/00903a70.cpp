// from server: 55% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int __stdcall Call(int*, int, int);

int S::f(int)
{
    float value = *(float*)((char*)this + 0x290);
    int object = *(int*)((char*)this + 0x1e4);
    int context = *(int*)((char*)this + 0x294);
    return Call((int*)(object + 0x45a0), context, 1);
}
