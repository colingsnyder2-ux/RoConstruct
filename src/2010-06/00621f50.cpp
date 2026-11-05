// from server: 66% by atomic.potato
struct S {
    void f();
};

extern "C" void __stdcall sub_599c50();

void S::f() {
    *(int*)((char*)this + 0) = 0xa3463c;
    *(int*)((char*)this + 4) = 0xa34630;
    *(int*)((char*)this + 0x18) = 0xa34624;
    *(int*)((char*)this + 0x1c) = 0xa34618;
    sub_599c50();
}
