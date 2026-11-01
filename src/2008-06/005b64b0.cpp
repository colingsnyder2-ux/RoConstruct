// from server: 100% by king_originala
struct Settings {
    void notify(void*);
};

struct Event {
    virtual void setEnabled(int);
};

namespace RBX {
    struct Instance {
        unsigned char padding[0x3a8];
        Event* event;
    };

    struct ServiceProvider {
        void apply(int);
    };

    void handle(int, int);
}

extern RBX::ServiceProvider* func_005807b0(RBX::Instance*);
extern "C" Settings* __stdcall lookup(void*, int, const void*);
extern unsigned char descriptor;
extern void* property;

struct String {
    unsigned char allocator[4];
    union {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;
};

struct Result {
    unsigned char padding[4];
    String text;
};

struct FillTool {
    virtual Result* getResult();
    unsigned char padding[0x14];
    RBX::Instance* instance;
    int execute(void*);
};

int FillTool::execute(void* argument)
{
    Settings* settings = lookup(argument, 0, &descriptor);
    if (settings) {
        settings->notify(property);
        func_005807b0(instance)->apply(10);

        String* text = &getResult()->text;
        const char* value;
        if (text->capacity >= 16)
            value = text->storage.pointer;
        else
            value = text->storage.buffer;

        RBX::handle(reinterpret_cast<int>(value),
                    reinterpret_cast<int>(instance));
        instance->event->setEnabled(1);
    }
    return 0;
}
