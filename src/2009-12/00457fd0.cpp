// from server: 93% by atomic.potato
struct Sub1 {
    char pad[0x80];
    void* field80;
    void method80(void** out);
};

struct Sub2 {
    char pad[0x54];
    void* method54(void** key);
};

struct Obj {
    char pad[0x54];
    Sub2 sub2;
    char pad2[0x80 - 0x54 - 4];
    Sub1 sub1;
    void func(void* a, void* b);
};

extern "C" void* __stdcall getLocalScope();

void Obj::func(void* a, void* b)
{
    if (a != 0) {
        void* tmp;
        sub1.method80(&tmp);
        void* v = *(void**)((char*)a + 4);
        void* key = tmp;
        void** r = (void**)sub2.method54(&key);
        *r = v;
    } else {
        void* g = getLocalScope();
        void* key = b;
        void** r = (void**)sub2.method54(&key);
        *r = g;
    }
}
