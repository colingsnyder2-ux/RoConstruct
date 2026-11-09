// from server: 56% by atomic.potato
extern "C" void construct_string(void*, const char*);
extern "C" void call_005e37c0(void*);

struct FilteredSelection
{
    void* vftable;
    FilteredSelection(void*);
};

FilteredSelection::FilteredSelection(void* value)
{
    char buffer[28];
    construct_string(buffer, "SelectionTilt");
    call_005e37c0(this);
    vftable = (void*)0xa2e578;
}
