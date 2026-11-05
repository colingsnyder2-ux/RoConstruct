// from server: 70% by atomic.potato
extern "C" void sub_9189c0(void*, int);

struct PartInstance
{
    void f(int);
};

void PartInstance::f(int value)
{
    *((unsigned char*)this + 0x228) = 1;
    sub_9189c0((char*)this + 0xb0, value);
}
