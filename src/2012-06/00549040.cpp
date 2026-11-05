// from server: 64% by atomic.potato
struct Inner {
    void* pad0;
    void* pad4;
    void* pad8;
};

struct Outer {
    char pad0[4];
    Inner* field4;
    Inner* field8;
    void clear();
};

extern "C" void __stdcall sub_5467D0(void*, void*, void*);
extern "C" void __stdcall sub_982114(void*);

void Outer::clear()
{
    Inner* p = field8;
    void* a = *(void**)p;
    void* b = p;
    void* tmp;
    sub_5467D0(field4, a, &tmp);
    sub_982114(field4->pad4);
    field4->pad4 = 0;
    field4->pad8 = 0;
}
