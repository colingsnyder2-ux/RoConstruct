// from server: 50% by atomic.potato
struct S
{
    virtual void f(void*);
};

void S::f(void* value)
{
    ((void (**)(void*, void*))(*(void***)this))[3](this, value);
}
