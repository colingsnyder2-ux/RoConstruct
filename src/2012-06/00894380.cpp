// from server: 65% by atomic.potato
extern "C" void CallObject(void*);

struct BallBlockConnector
{
    void f(float);
};

void __thiscall BallBlockConnector::f(float value)
{
    CallObject(*(void**)((char*)this + 12));
    CallObject(*(void**)((char*)this + 16));
    void** vtable = *(void***)this;
    ((void (__thiscall *)(BallBlockConnector*, float))vtable[8])(this, value);
}
