// from server: 100% by king_originala
namespace RBX {
    void handle(int a, int b);
}

struct Text {
    int reserved;
    union {
        char buffer[16];
        char* pointer;
    };
    unsigned size;
    unsigned capacity;
};

struct Result {
    int reserved;
    Text text;
};

struct DecalTool {
    virtual Result* v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void cancel();

    char padding[20];
    int context;

    int execute(int argument);
};

int DecalTool::execute(int argument)
{
    cancel();
    Text* text = &v0()->text;
    RBX::handle((int)(text->capacity >= 16
                         ? text->pointer
                         : text->buffer),
                context);
    return 0;
}
