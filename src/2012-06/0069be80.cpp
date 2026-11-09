// from server: 52% by atomic.potato
struct Inner {
    void* p0;
    void* p4;
};

struct Outer {
    char pad0[4];
    Inner inner;
    void* p8;
    void clear();
};

extern "C" void __stdcall sub_425320(void*, void*, void*);
extern "C" void __stdcall sub_982114(void*);

void Outer::clear()
{
    void* a = this->p8;
    void* b = *(void**)a;
    void* tmp;
    sub_425320(&tmp, b, a);
    sub_982114(this->inner.p4);
    this->inner.p4 = 0;
    this->p8 = 0;
}
