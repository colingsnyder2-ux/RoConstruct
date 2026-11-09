// from server: 43% by atomic.potato
struct Base
{
    void f(int);
};

struct EventDesc
{
    void f(int);
};

void EventDesc::f(int value)
{
    ((Base*)((char*)this + 0x24))->f(value);
}
