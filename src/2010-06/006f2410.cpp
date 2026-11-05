// from server: 88% by atomic.potato
struct BoundFuncDesc {
    void f(int);
};

extern "C" void G1_func_00664330(void*, int);

void BoundFuncDesc::f(int value)
{
    if (*(int*)((char*)this + 0x9c) != 0)
        G1_func_00664330(*(void**)((char*)this + 0x94), value);
}
