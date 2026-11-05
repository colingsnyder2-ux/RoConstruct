// from server: 100% by king_originala
struct Base {
    char data;
};

struct Token {};

struct Action {
    void invoke(Token*, int);
};

struct Result {
    char padding[16];
    Action action;
};

struct Lookup {
    Result* find(Base*);
};

extern Lookup lookup;

struct S {
    char padding0[20];
    Base base;
    char padding1[283];
    int value;

    void f(void*);
};

void S::f(void*)
{
    Base* key = this ? &base : 0;
    int saved = value;
    Result* result = lookup.find(key);
    if (result) {
        Token token;
        result->action.invoke(&token, saved);
    }
}
