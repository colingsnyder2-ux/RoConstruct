// from server: 79% by atomic.potato
extern "C" void sub_009c01a0(void*);

struct PyramidBuilder
{
    PyramidBuilder* f(void*);
};

PyramidBuilder* PyramidBuilder::f(void* arg)
{
    sub_009c01a0(arg);
    *(int*)((char*)this + 0x28) = 0xC2;
    *(volatile float*)((char*)this + 0x2C) = 0.0f;
    return this;
}
