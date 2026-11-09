// from server: 45% by colin
struct FilteredSelection {
    void assign(void* first, void* last);
};

extern "C" void __stdcall sub_4078A0(void*);
extern "C" void __stdcall sub_541630(void*, void*);
extern "C" void __stdcall sub_77E6D8();

void FilteredSelection::assign(void* first, void* last)
{
    void* localFirst = 0;
    void* localLast = 0;
    void* srcFirst = first;
    void* srcLast = last;

    sub_4078A0(srcFirst);

    void* dstFirst = *(void**)srcFirst;
    sub_541630(dstFirst, this);

    void* p = srcFirst;
    void* q = srcLast;

    while (p != q) {
        if (p == 0 || p == q) {
            sub_77E6D8();
        }
        if (q != srcLast) {
            if (p == 0) {
                sub_77E6D8();
            }
            if (q >= *(void**)((char*)p + 8)) {
                sub_77E6D8();
            }
            void* v = *(void**)q;
            sub_541630(v, this);
            if (q >= *(void**)((char*)p + 8)) {
                sub_77E6D8();
            }
            q = (char*)q + 8;
        }
        p = (char*)p + 8;
    }
}
