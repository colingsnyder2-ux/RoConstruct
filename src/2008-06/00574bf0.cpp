// from server: 100% by king_originala
struct Result {
    int first;
    int second;
    Result(int a, int b) : first(a), second(b) {}
};

struct Event {
    int kind;
    int unused;
    int value;
};

struct Rectangle {
    int data[4];
    bool contains();
};

struct Base;

struct VTable {
    char padding[84];
    bool (__thiscall *enabled)(Base *);
};

struct Base {
    VTable *vtable;
    Rectangle rectangle(int);
};

struct S {
    char padding[32];
    float amount;

    Result query(Event *);
    Result f(Event *);
};

Result S::f(Event *event)
{
    Base *base = reinterpret_cast<Base *>(
        reinterpret_cast<char *>(this) - 304);

    if (base->vtable->enabled(base)) {
        {
            Result result = query(event);
            if (result.first)
                return result;
        }

        if (amount > 0.0f &&
            event->kind >= 1 &&
            event->kind <= 7) {
            if (base->rectangle(event->value).contains())
                return Result(1, 0);
        }
    }

    return Result(0, 0);
}
