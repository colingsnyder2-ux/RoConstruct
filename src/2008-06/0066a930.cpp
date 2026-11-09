// from server: 100% by king_originala
namespace RBX {
    void handle(int a, int b);
}

struct Context {
    void reset();
};

struct Text {
    int reserved;
    union {
        char local[16];
        char* heap;
    } storage;
    unsigned length;
    unsigned capacity;
};

struct Name {
    int reserved;
    Text text;
};

struct S {
    virtual Name* getName();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void finish();

    char padding0[20];
    int target;
    Context* context;
    char padding1[8];
    bool active;

    int run(int);
};

int S::run(int)
{
    if (active) {
        context->reset();
        active = false;
        Text* text = &getName()->text;
        char* value = text->capacity >= 16
            ? text->storage.heap
            : text->storage.local;
        RBX::handle(reinterpret_cast<int>(value), target);
    }
    finish();
    return 0;
}
