// from server: 76% by atomic.potato
struct Inner {
    int method(int);
};

struct Target {
    char pad[0x144];
    int get(int);
};

extern "C" int __stdcall sub_6e32e0(Inner*);
extern "C" void __stdcall sub_47e7b0(int);
extern "C" void __stdcall sub_6cd670(Inner*, int);

int Target::get(int a) {
    Inner* p = (Inner*)((char*)this - 0x144);
    int r = p->method(a);
    if (r) {
        sub_6cd670((Inner*)r, a);
    } else {
        sub_47e7b0(a);
    }
    return a;
}
