// from server: 87% by atomic.potato
struct CXTPFormulaMulDivC
{
    int GetValue(int value);
};

int CXTPFormulaMulDivC::GetValue(int value)
{
    int divisor = *(int *)((char *)this + 0x24);
    if (divisor == 0)
        divisor = 1;
    return (*(int *)((char *)this + 0x20) * value) / divisor
        + *(int *)((char *)this + 0x28);
}
