// from server: 65% by atomic.potato
extern "C" void * std_string_ctor(const char *, const char *);
extern "C" void call_67aaa0(void *, void *);

struct DeleteSelectionVerb
{
    DeleteSelectionVerb *f(const char *);
};

DeleteSelectionVerb *DeleteSelectionVerb::f(const char *p)
{
    char local[28];
    std_string_ctor(local, "SelectionTilt");
    call_67aaa0(this, local);
    *(void **)this = (void *)0x9cfec8;
    return this;
}
