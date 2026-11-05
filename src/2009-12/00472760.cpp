// from server: 100% by atomic.potato
struct DxUserInput
{
    void f(int value, unsigned char enabled);
};

void DxUserInput::f(int value, unsigned char enabled)
{
    value = enabled ? value : 0;
    *(int *)((char *)this + 0x170) = value;
}
