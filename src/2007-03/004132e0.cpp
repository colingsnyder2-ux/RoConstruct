// from server: 100% by tester
struct S {
    int f(int* p);
};

int S::f(int* p)
{
    p[2] = p[2] + 1;
    return p[2];
}
