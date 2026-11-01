// from server: 100% by king_originala
struct Value
{
    void set(bool enabled);
};

struct Owner
{
    void* first();
    int second();
};

struct S
{
    unsigned char padding[8];
    Owner* owner;

    void f(bool enabled);
};

void S::f(bool enabled)
{
    if (owner->first())
    {
        Owner* p = owner;
        bool disabled = !enabled;
        static_cast<Value*>(p->first())->set(disabled);
    }

    if (owner->second())
    {
        Owner* p = owner;
        bool disabled = !enabled;
        reinterpret_cast<Value*>(p->second())->set(disabled);
    }
}
