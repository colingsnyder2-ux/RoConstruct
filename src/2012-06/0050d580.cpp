// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
// boost::pool<>::purge_memory()
typedef unsigned int size_type;
void user_free(char*);
struct PODptr {
    char* ptr; size_type sz;
    PODptr(char* p, size_type s) : ptr(p), sz(s) {}
    PODptr() : ptr(0), sz(0) {}
    PODptr& operator=(const PODptr& o) { ptr = o.ptr; sz = o.sz; return *this; }
    bool valid() const { return ptr != 0; }
    void invalidate() { ptr = 0; }
    char*& begin() { return ptr; }
    char* ptr_next_size() const { return ptr + sz - sizeof(size_type); }
    char* ptr_next_ptr() const { return ptr_next_size() - sizeof(void*); }
    size_type& next_size() const { return *((size_type*)ptr_next_size()); }
    char*& next_ptr() const { return *((char**)ptr_next_ptr()); }
    PODptr next() const { return PODptr(next_ptr(), next_size()); }
};
struct pool {
    void* first;
    PODptr list;
    size_type requested_size;
    size_type next_size;
    size_type start_size;
    bool purge_memory();
};
bool pool::purge_memory()
{
    PODptr iter = list;
    if (!iter.valid())
        return false;
    do {
        const PODptr next = iter.next();
        user_free(iter.begin());
        iter = next;
    } while (iter.valid());
    list.invalidate();
    this->first = 0;
    next_size = start_size;
    return true;
}