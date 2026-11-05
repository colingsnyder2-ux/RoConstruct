// from server: 62% by atomic.potato
struct Inner {
    char pad0[4];
    int field4;
};

struct Arg {
    int a;
    int b;
};

struct Obj {
    char pad0[4];
    int field4;
    char pad8[8];
    Inner* field10;
    char pad14[4];
    Inner* field18;
    int method(Arg* arg, Arg* out);
};

struct Vtbl {
    void* slot0;
    void* slot4;
    void* slot8;
    void* slotC;
    void* slot10;
    void* slot14;
    void* slot18;
    void* slot1C;
    void* slot20;
    void* slot24;
};

extern "C" void __stdcall sub_984920(void* out, int val);

int Obj::method(Arg* arg, Arg* out)
{
    int local;
    sub_984920(&local, this->field4);
    Vtbl* vt = *(Vtbl**)arg;
    int r1 = ((int (__thiscall*)(void*))vt->slot24)(arg);
    Inner* inner = this->field18;
    int flags = inner->field4 & 0xf00;
    if (flags == 0x200 || flags == 0x100) {
        Vtbl* vt2 = *(Vtbl**)this->field10;
        ((void (__thiscall*)(void*, int, int*))vt2->slot4)(this->field10, 1, &local);
    } else if (flags == 0) {
        Vtbl* vt3 = *(Vtbl**)this->field10;
        ((void (__thiscall*)(void*, int, int*))vt3->slot0)(this->field10, 0, &local);
    } else if (flags == 0x300) {
        Vtbl* vt4 = *(Vtbl**)this->field10;
        ((void (__thiscall*)(void*, int, int*))vt4->slot4)(this->field10, 1, &local);
    }
    Vtbl* vt5 = *(Vtbl**)arg;
    int r2 = ((int (__thiscall*)(void*))vt5->slot24)(arg);
    out->a = r1;
    out->b = r2;
    return 0;
}
