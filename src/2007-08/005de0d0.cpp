// from server: 100% by atomic.potato
struct S {
    bool f(int* a, int* b);
};

bool S::f(int* a, int* b)
{
    int i = 0;
    while (i < 3) {
        if (a[i] < b[i])
            return true;
        if (a[i] > b[i])
            return false;
        ++i;
    }
    return false;
}
