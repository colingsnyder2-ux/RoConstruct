// from server: 100% by king_originala
struct S {
    unsigned int f();
};

#pragma optimize("", off)
unsigned int S::f()
{
    unsigned int count = 0x06666666;
    return count > 0 ? count : 1;
}
#pragma optimize("", on)
