// from server: 100% by king_originala
struct Table;
struct EventHandler {
    Table* table;
    bool f();
};

struct S {
    char padding[0x158];
    EventHandler handler;
    void setValue(const bool* state);
    void f();
};

void S::f() {
    bool state = handler.f();
    setValue(&state);
}
