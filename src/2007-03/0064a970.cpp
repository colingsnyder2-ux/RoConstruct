// from server: 100% by tester
struct S;

struct Inner {
    char pad[0x40];
    S* owner;
};

struct S {
    char pad[0x54];
    Inner* field;
    int m();
};

int S::m()
{
    return field->owner == this;
}