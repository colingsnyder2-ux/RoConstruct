// from server: 90% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(int*)this = 0xB8DFBC;
    *((int*)this + 1) = 0xB8DFB4;
    *((int*)this + 6) = 0xB8DFA8;
    *((int*)this + 7) = 0xB8DF9C;
}
