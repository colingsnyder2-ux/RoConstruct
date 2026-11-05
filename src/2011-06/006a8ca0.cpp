// from server: 67% by atomic.potato
extern "C" int __cdecl sub_5DE520();
extern "C" void* __cdecl sub_80A05E(int);

struct S {
    int* f1;
    void* f2;
    void* f(void*);
};

void* S::f(void* arg) {
    ++*(int*)0xCCA77C;
    int result = sub_5DE520();
    f1 = (int*)result;
    void* ptr = sub_80A05E(8);
    if (ptr) {
        *(int*)ptr = 0xA8EB60;
        *(int*)((char*)ptr + 4) = *(int*)arg;
        f2 = ptr;
        return this;
    }
    f2 = 0;
    return this;
}
