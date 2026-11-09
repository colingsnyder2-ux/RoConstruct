// from server: 45% by atomic.potato
extern "C" void __cdecl sub_516de0(void*);

struct S
{
    void f(int);
};

void S::f(int a)
{
    if (a == 2)
    {
        void** p = (void**)((char*)this + 0x1c4);
        void (**fn)(void*) = (void (**)(void*))p;
        (*fn)(this);
    }
    else if (a == 5)
    {
        sub_516de0(this);
    }
}
