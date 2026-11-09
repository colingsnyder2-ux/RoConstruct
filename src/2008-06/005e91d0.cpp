// from server: 100% by king_originala
struct Iterator {
    void* primitive;
    int index;
    void advance();
};

struct Assembly {
    Iterator end() const;
    Iterator begin() const;
};

struct Consumer {
    void consume(void* primitive);
};

struct PhysicsService {
    char padding[0x84];
    Consumer* consumer;
    void f(Assembly* assembly);
};

void PhysicsService::f(Assembly* assembly)
{
    Iterator last = assembly->end();
    Iterator current = assembly->begin();

    while (current.primitive != last.primitive) {
        consumer->consume(current.primitive);
        current.advance();
    }
}
