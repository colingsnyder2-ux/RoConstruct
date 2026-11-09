// from server: 100% by atomic.potato
struct S {
    int *f(int);
};

int *S::f(int index)
{
    return reinterpret_cast<int **>(*reinterpret_cast<int **>(
        reinterpret_cast<char *>(this) + 0x98))[index];
}
