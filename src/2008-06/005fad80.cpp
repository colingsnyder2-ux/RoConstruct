// from server: 100% by king_originala
struct Item {
    char pad[4];
    int index;
    int* f();
};

struct Buffer {
    Item** data;
    int count;
    void resize(int, int);
};

struct Storage {
    char pad[48];
    Buffer buffer;
};

struct Sink {
    char pad[16];
    Storage* storage;
    void f(Item*);
};

void Sink::f(Item* item)
{
    Buffer* buffer = &storage->buffer;
    int index = *item->f();
    Item* last = buffer->data[buffer->count - 1];
    buffer->data[index] = last;
    *last->f() = index;
    buffer->resize(buffer->count - 1, 0);
    *item->f() = -1;
}
