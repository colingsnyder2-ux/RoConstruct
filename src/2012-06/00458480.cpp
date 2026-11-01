// from server: 100% by tester
struct S {
    bool f(const char* a, const char* b);
};

bool S::f(const char* a, const char* b)
{
    return *a == *b;
}
