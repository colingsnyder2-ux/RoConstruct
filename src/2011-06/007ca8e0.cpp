// from server: 24% by atomic.potato
struct Inner {
    char pad[8];
    void f(int, char*, char**);
};

struct Outer {
    Inner* p;
    void __cdecl g(int, char*);
};

void Outer::g(int a, char* b) {
    Inner* q = p;
    char* tmp;
    q->f(a, b, &tmp);
}
