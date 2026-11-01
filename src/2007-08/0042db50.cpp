// from server: 100% by colin
struct Holder {
    virtual void destroy(char);
};

struct Entry {
    int pad;
    Holder* h;
};

void __stdcall func(Entry* first, Entry* last)
{
    while (first != last) {
        Holder* h = first->h;
        if (h) {
            h->destroy(1);
        }
        ++first;
    }
}
