// from server: 100% by tester
struct S {
    unsigned int f();
};

#pragma optimize("", off)
unsigned int S::f()
{
    unsigned int count = 0x3fffffff;
    return count > 0 ? count : 1;
}
#pragma optimize("", on)
