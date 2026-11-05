// from server: 82% by atomic.potato
struct Inner {
    char pad[4];
    void* field4;
};

struct Outer {
    char pad[0x24];
    Inner* field24;
    void method(void* a, void* b);
};

struct Target {
    void method(void* p);
};

extern "C" void* __stdcall sub_5c5430(void* p);

void Outer::method(void* a, void* b) {
    Inner* p = (Inner*)a;
    if (p != 0) {
        p = (Inner*)((char*)p - 0x1c);
    } else {
        p = 0;
    }
    Target* q = (Target*)((char*)field24 + (int)p);
    void* r = sub_5c5430(*(void**)((char*)b + 4));
    q->method(*(void**)r);
}
