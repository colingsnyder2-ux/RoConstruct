// from server: 100% by tester
struct S {
    void f();
};

void S::f()
{
    if (*(unsigned char*)((char*)this + 8))
        *(unsigned char*)((char*)this + 8) = 0;
}
