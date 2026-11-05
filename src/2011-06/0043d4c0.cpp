// from server: 28% by atomic.potato
struct CBrowserFrameWnd
{
    void* vfptr;
    char pad[0xe4];
    void* field_e8;
    void destroy();
    void base_destroy();
};

void CBrowserFrameWnd::destroy()
{
    vfptr = (void*)0xa6790c;
    if (field_e8)
        ((CBrowserFrameWnd*)field_e8)->destroy();
    base_destroy();
}
