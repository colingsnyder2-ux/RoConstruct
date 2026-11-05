// from server: 94% by atomic.potato
extern "C" void G1_func_00411f60(const void *);

struct Scale9Frame
{
    void update(void *);
};

void Scale9Frame::update(void *value)
{
    if (*(void **)((char *)this + 0x200) != value)
    {
        *(void **)((char *)this + 0x200) = value;
        G1_func_00411f60((const void *)0x00cd4cc8);
        void **vtable = *(void ***)this;
        ((void (__thiscall *)(void *))vtable[31])(this);
    }
}
