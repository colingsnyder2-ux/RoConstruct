// from server: 55% by atomic.potato
struct ContentProviderJob
{
    void *get();
};

void *ContentProviderJob::get()
{
    ContentProviderJob *p = this;
    void *result = *(void **)((char *)p + 0x1c);
    if (result)
        return result;

    p = *(ContentProviderJob **)((char *)p + 4);
    if (!p)
        return 0;

    return p->get();
}
