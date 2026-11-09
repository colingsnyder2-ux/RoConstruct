// from server: 29% by atomic.potato
struct Slot {
    void* vtable;
    Slot* next;
    int a;
    int b;
    int c;
    int d;
};

struct Signal {
    char pad[0x1c];
    Slot* slot;
    void connect(int a, int b, int c, int d, int e);
};

extern "C" void* __stdcall sub_6518A0(int, int);
extern "C" void __cdecl sub_7F385A(void*);
extern "C" void* __cdecl sub_7F3860(unsigned int);

void Signal::connect(int a, int b, int c, int d, int e)
{
    void* p = sub_6518A0(a, b);
    ((void (__thiscall*)(Signal*, void*))0x442310)(this, p);
    sub_7F385A(0);
    this->slot = (Slot*)0x9a9f54;
    Slot* s = (Slot*)sub_7F3860(0x18);
    if (s) {
        s->a = c;
        s->vtable = (void*)0x9e81f4;
        s->next = (Slot*)this;
        s->c = 0;
        s->d = 0;
    } else {
        s = 0;
    }
    if (s != this->slot) {
        sub_7F385A(this->slot);
    }
    this->slot = s;
}
