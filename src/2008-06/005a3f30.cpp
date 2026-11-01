// from server: 100% by king_originala
struct Buffer {
    unsigned char bytes[24];
};

struct Manager {
    void (__cdecl *manage)(Buffer*, Buffer*, int);
};

struct Function {
    Manager* manager;
    unsigned padding;
    Buffer buffer;

    Function(const Function&);
    ~Function();
};

inline Function::Function(const Function& source) : manager(0)
{
    if (source.manager) {
        manager = source.manager;
        manager->manage(const_cast<Buffer*>(&source.buffer), &buffer, 0);
    }
}

inline Function::~Function()
{
    if (manager) {
        void (__cdecl *manage)(Buffer*, Buffer*, int) = manager->manage;
        if (manage)
            manage(&buffer, &buffer, 1);
    }
}

struct B0 {
    virtual ~B0();
    unsigned char padding[12];
};

struct B1 {
    virtual ~B1();
};

struct B2 {
    virtual ~B2();
    unsigned char padding[8];
};

struct B3 {
    virtual ~B3();
};

struct B4 {
    virtual ~B4();
    unsigned char padding[28];
};

struct B5 {
    virtual ~B5();
    unsigned char padding[28];
};

struct B6 {
    virtual ~B6();
    unsigned char padding[28];
};

struct B7 {
    virtual ~B7();
    unsigned char padding[28];
};

struct B8 {
    virtual ~B8();
    unsigned char padding[28];
};

struct B9 {
    virtual ~B9();
    unsigned char padding[144];
};

struct Base : B0, B1, B2, B3, B4, B5, B6, B7, B8, B9 {
    Base();
    virtual ~Base();
};

struct Descriptor : Base {
    Function callback;

    Descriptor(Function);
    virtual ~Descriptor();
};

Descriptor::Descriptor(Function source) : callback(source)
{
}
