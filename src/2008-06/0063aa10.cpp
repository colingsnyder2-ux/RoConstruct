// from server: 100% by king_originala
struct Part {
    char data[284];
};

struct Action {
    void invoke(char* result, int value);
};

struct Result {
    char padding[16];
    Action action;
};

struct Lookup {
    Result* find(Part* part);
};

extern Lookup lookup;

struct S {
    char padding[20];
    Part part;
    int value;

    void f(int unused);
};

void S::f(int unused)
{
    char result;
    Part* p = this ? &part : 0;
    int v = value;
    Result* found = lookup.find(p);
    if (found)
        found->action.invoke(&result, v);
}
