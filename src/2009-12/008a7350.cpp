// from server: 42% by atomic.potato
extern "C" int __stdcall UpdateWindow(void*);

struct Sub {
    char pad0[0x74];
    int (__stdcall *fn)(void*, void*, void*);
};

struct Inner {
    char pad0[0x54];
    Sub* sub;
};

struct S {
    char pad0[0x20];
    void* hwnd;
    int f(int, int, int, int);
};

int S::f(int a, int b, int c, int d)
{
    UpdateWindow(hwnd);
    Inner* inner = (Inner*)c;
    Sub* sub = inner->sub;
    return sub->fn(sub, (void*)b, (void*)d);
}
