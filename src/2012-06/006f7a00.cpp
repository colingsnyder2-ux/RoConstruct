// from server: 65% by atomic.potato
extern "C" void *construct_string(void *, const char *);
extern "C" void function_006f7810(void *, void *);

struct ClearStarterpack
{
    void *clear(void *);
};

void *ClearStarterpack::clear(void *arg)
{
    char string_object[28];
    construct_string(string_object, "SnapSelection");
    function_006f7810(this, string_object);
    *(void **)this = (void *)0x00b9c6c0;
    return this;
}
