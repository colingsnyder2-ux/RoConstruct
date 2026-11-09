// from server: 62% by atomic.potato
struct DxUserInput
{
    void f();
};

void DxUserInput::f()
{
    *(unsigned short *)((char *)this + 0) = 0;
    *(unsigned int *)((char *)this + 4) = 0;
    *(unsigned int *)((char *)this + 0x10) = 0;
    *(unsigned short *)((char *)this + 2) = 0x4e4;
    *(unsigned int *)((char *)this + 8) = 0;
    *(unsigned int *)((char *)this + 0xc) = 0;
}
