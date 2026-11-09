// from server: 36% by atomic.potato
struct CRobloxControlMaterialSelector
{
    int Select(int, int);
    int material;
    void Update(int);
};

int CRobloxControlMaterialSelector::Select(int a, int b)
{
    return 0;
}

void CRobloxControlMaterialSelector::Update(int value)
{
    if (value != -1)
    {
        material = value;
        Update(1);
    }
}
