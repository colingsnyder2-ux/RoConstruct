// from server: 100% by atomic.potato
struct S
{
    int AddRef(int* p);
};

int S::AddRef(int* p)
{
    ++p[6];
    return p[6];
}
