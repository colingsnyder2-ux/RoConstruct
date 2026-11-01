// from server: 100% by king_originala
namespace RBX {
    void handle(int a, int b);
}

struct String {
    int proxy;
    union {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;
};

struct Label {
    int prefix;
    String text;
};

struct State {
    int reserved;
    int active;
};

struct Service {
    virtual void setEnabled(int enabled);
};

struct Context {
    char reserved[0x3A8];
    Service* service;
};

struct ResizeTool {
    virtual Label* getLabel();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void update();

    char reserved0[0x10];
    bool enabled;
    char reserved1[3];
    Context* context;
    char reserved2[8];
    State* state;

    int execute(int argument);
};

int ResizeTool::execute(int argument)
{
    if (enabled) {
        update();
        if (state && state->active) {
            String* text = &getLabel()->text;
            char* data;
            if (text->capacity >= 16)
                data = text->storage.pointer;
            else
                data = text->storage.buffer;
            RBX::handle(reinterpret_cast<int>(data),
                        reinterpret_cast<int>(context));
            context->service->setEnabled(1);
        }
    }
    return 0;
}
