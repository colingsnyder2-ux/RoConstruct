// from server: 100% by tester
struct Inner {
    void method();
};

struct Outer {
    char pad[0x100];
    Inner* inner;
    void method();
};

void Outer::method()
{
    inner->method();
    (*(void (__thiscall**)(Outer*, int))(*(int*)this + 0x70))(this, 1);
}
