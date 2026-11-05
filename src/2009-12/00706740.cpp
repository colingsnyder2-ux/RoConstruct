// from server: 43% by atomic.potato
struct Inner {
    char pad[8];
    void method(int, void*, void*);
};

struct Outer {
    Inner* p;

    void __cdecl method(int a, void* b, void* c);
};

extern "C" void __stdcall helper(Outer* self, int a, void* b, void* c);

void Outer::method(int a, void* b, void* c)
{
    Inner* q = p;
    void* local;
    char flag = 0;
    helper(this, a, &local, &flag);
    q->method(a, &local, &flag);
}
