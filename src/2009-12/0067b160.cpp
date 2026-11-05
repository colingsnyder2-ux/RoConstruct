// from server: 21% by atomic.potato
extern "C" void sub_677E50(void *);
extern "C" void *sub_503120(void *);
extern "C" void sub_637180(void *);

struct ClearStarterpack
{
    void Clear();
    void *value;
};

void ClearStarterpack::Clear()
{
    void *p = value;
    sub_677E50(this);
    p = value;
    if (p)
    {
        void *q = sub_503120(p);
        if (q)
            sub_637180(q);
    }
}
