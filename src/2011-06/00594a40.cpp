// from server: 47% by atomic.potato
extern "C" int __stdcall sub_40E040();
extern "C" int __stdcall sub_40E0A0();

struct VPlayers_RefPropDescriptor {
    int f();
};

int VPlayers_RefPropDescriptor::f() {
    int a = sub_40E040();
    *(int*)((char*)this + 4) = a;
    int b = sub_40E0A0();
    *(int*)((char*)this + 4) = b;
    *(int*)0x00CCA65C = *(int*)0x00CCA65C + 1;
    return (int)this;
}
