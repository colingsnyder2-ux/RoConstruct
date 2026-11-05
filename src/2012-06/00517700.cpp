// from server: 72% by atomic.potato
struct S
{
    S* f(S*);
};

S* S::f(S* p)
{
    ((void (__thiscall *)(void*, const void*))0x62c250)(this, p);
    *(long*)((char*)this + 0x24) = *(long*)((char*)p + 0x24);
    *(long*)((char*)this + 0x28) = *(long*)((char*)p + 0x28);
    *(long*)((char*)this + 0x2c) = *(long*)((char*)p + 0x2c);
    return this;
}
