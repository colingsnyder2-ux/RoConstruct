// from server: 26% by atomic.potato
struct CRobloxControlColorSelector
{
    int Select(int, int);
    void Update(int);
    void Update(int, int);
    int value;
};

int CRobloxControlColorSelector::Select(int a, int b)
{
    return 0;
}

void CRobloxControlColorSelector::Update(int v)
{
}

void CRobloxControlColorSelector::Update(int a, int b)
{
    int result = Select(a, b);
    if (result != -1)
    {
        value = result;
        Update(1);
    }
}
