// from server: 65% by atomic.potato
extern "C" void std_string_ctor(void*, const char*);
extern "C" void func_005e3300(void*);
extern const char* const g_00a0dd44;
extern int g_00a2e510;

struct FilteredSelection {
    int vtable;
    FilteredSelection(const char*);
};

FilteredSelection::FilteredSelection(const char* value)
{
    char buffer[28];
    std_string_ctor(buffer, value);
    func_005e3300(this);
    vtable = g_00a2e510;
}
