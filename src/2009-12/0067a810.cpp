// from server: 65% by atomic.potato
extern "C" void ConstructString(void *, const char *);
extern "C" void InitializeFilteredSelection(void *, void *);

struct FilteredSelection
{
    FilteredSelection(const char *);
};

FilteredSelection::FilteredSelection(const char *value)
{
    char buffer[28];
    ConstructString(buffer, "WatchCamera");
    InitializeFilteredSelection(this, buffer);
    *(void **)this = (void *)0x9cfe48;
}
