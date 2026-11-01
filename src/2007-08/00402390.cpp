// from server: 100% by colin
struct S {
    int a;
    int b;
    int c;
    S* init();
};

S* S::init()
{
    a = 0;
    b = 0;
    c = -1;
    return this;
}
