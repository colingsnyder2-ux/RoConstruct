// from server: 41% by atomic.potato
extern "C" void __cdecl sub_0052f040(void*, void*, int, int);

struct Ray
{
    virtual void* f();
    int field30;
};

void* Ray::f()
{
    void* value = this->f();
    sub_0052f040(this, &value, this->field30 + 1, 1);
    return value;
}
