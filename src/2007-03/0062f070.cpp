// from server: 100% by tester
struct CXTPCommandBarsOptions
{
    void Add(int);
    void AddRange(int* items, int count);
};

void CXTPCommandBarsOptions::AddRange(int* items, int count)
{
    int i = 0;
    if (count > 0)
    {
        do
        {
            Add(items[i]);
            ++i;
        } while (i < count);
    }
}
