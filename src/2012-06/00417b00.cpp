// from server: 69% by atomic.potato
struct S
{
    void* f(void*);
};

extern "C" void* sub_417510(S*, void*);

void* S::f(void* p)
{
    sub_417510(this, p);
    *(void**)((char*)this + 0x20) = (void*)0x00B43C34;
    *(void**)((char*)this + 0x00) = (void*)0x00B46560;
    *(void**)((char*)this + 0x0C) = (void*)0x00B46558;
    *(void**)((char*)this + 0x20) = (void*)0x00B46548;
    return this;
}
