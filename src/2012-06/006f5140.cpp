// from server: 79% by tajop
struct FilteredSelection
{
    char data[0xa0];
    FilteredSelection();
};

struct Deleter
{
};

struct SharedPtr
{
    FilteredSelection* px;
    void* pn;
    SharedPtr(FilteredSelection* p, Deleter d);
};

SharedPtr createFilteredSelection()
{
    return SharedPtr(new FilteredSelection(), Deleter());
}
