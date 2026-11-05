// from server: 53% by atomic.potato
struct CPropGrid_UpdateItemsJob {
    char pad[12];
    void* first;
    void* last;
    void* end;

    void __cdecl UpdateItemsJob(void* a, void* b, void* c, void* d);
};

void __stdcall helper(void*, void*);

void CPropGrid_UpdateItemsJob::UpdateItemsJob(void* a, void* b, void* c, void* d)
{
    void** p = (void**)this->first;
    void** q = (void**)this->last;
    while (p != q) {
        helper(d, *p);
        ++p;
    }
    this->first = a;
    this->last = b;
    this->end = c;
}
