// from server: 27% by atomic.potato
struct Player {
    void f();
};

extern "C" void __stdcall sub_5064C0(void*, int);
extern "C" void __stdcall sub_50E590(void*, void*, void*);

void Player::f()
{
    char pad[0x28];
    void* p = *(void**)((char*)this + 4);
    if (p) {
        sub_5064C0(p, 1);
    }
    void* a = 0;
    void* b = 0;
    void* c = 0;
    sub_50E590(this, &a, &b);
    if (c) {
        void* d = *(void**)c;
        if (d) {
            ((void (__stdcall*)(void*, int))d)(&c, 2);
        }
    }
}
