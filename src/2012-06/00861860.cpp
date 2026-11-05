// from server: 100% by Intel
struct S {
    void f();
};

void S::f()
{
    if (*(unsigned char*)((char*)this + 8))
        *(unsigned char*)((char*)this + 8) = 0;
}
