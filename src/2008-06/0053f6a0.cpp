// from server: 100% by king_originala
#pragma optimize("", off)

struct Queue {
    void process(int, int);
};

struct Scene {
    char pad[8];
    Queue queue;
};

struct SimpleSceneManager {
    void* vtbl;
    Scene* scene;
    void process();
};

struct B {
    void f();
};

struct Item {
    char pad[12];
    B b;
    void g();
};

struct Handle {
    Item* get();
};

struct Node {
    char pad[12];
    Handle handle;
};

struct Iterator {
    unsigned int value;
    void* owner;
    bool different(Iterator*);
    Node* dereference();
    void advance();
};

struct Container {
    char pad[24];
    unsigned int value;
    unsigned int reserved;
    Iterator* begin(Iterator*);
    Iterator* end(Iterator*);
};

struct VChunk {
    char pad[8];
};

struct Slots {
    char pad[24];
    VChunk* chunk;
    int count;
    VChunk** slot();
};

struct Manager : SimpleSceneManager {
    Container container;
    Slots first;
    Slots second;
    void process();
};

void Manager::process()
{
    first.slot();
    second.slot();

    Iterator current;
    Iterator finish;
    container.begin(&current);
    container.end(&finish);

    while (current.different(&finish)) {
        current.dereference()->handle.get()->g();
        current.advance();
    }

    SimpleSceneManager::process();
}
