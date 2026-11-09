// from server: 70% by atomic.potato
struct HitTestFilter {
    char pad[0x1c];
    void* field_1c;
    void* method(void* a, void* b);
};

extern "C" void __cdecl func_0078c060(void*, void*, void*);

void* HitTestFilter::method(void* a, void* b)
{
    void* p = 0;
    void* q = field_1c;
    if (q != 0)
        q = (char*)q + 0x118;
    else
        q = 0;
    func_0078c060(a, b, q);
    return a;
}
