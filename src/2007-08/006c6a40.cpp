// from server: 100% by colin
struct Inner {
    void method();
};

struct Outer {
    char pad[0xfc];
    Inner* inner;
    void method();
};

void Outer::method()
{
    inner->method();
    (*(void (__thiscall**)(Outer*, int))(*(int*)this + 0x70))(this, 1);
}
