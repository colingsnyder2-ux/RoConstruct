// from server: 100% by king_originala
struct S {
    unsigned int reserved;
    unsigned int value;
    void f();
};

#pragma optimize("", off)
void S::f()
{
    do {
    } while (0);
    value = 0;
}
#pragma optimize("", on)
