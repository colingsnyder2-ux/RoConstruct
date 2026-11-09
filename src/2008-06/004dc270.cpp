// from server: 100% by king_originala
extern "C" long (__stdcall *InterlockedDecrement)(volatile long *);

struct Interface {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void close();
};

struct Auxiliary {
    void destroy();
};

struct Image {
    virtual ~Image();
    volatile long references;
    void releaseResources();
};

struct ImageReference {
    Image *pointer;
    ~ImageReference();
};

inline ImageReference::~ImageReference() {
    if (pointer) {
        if (InterlockedDecrement(&pointer->references) == 0) {
            pointer->releaseResources();
            if (pointer)
                delete pointer;
        }
        pointer = 0;
    }
}

struct Resource {
    ~Resource();
};

struct Base {
    virtual ~Base();
};

void shutdown1();
void shutdown2();
void shutdown3();
void shutdown4();
void shutdown5();
void shutdown6();
void shutdown7();

struct S : Base {
    Interface *interfacePointer;
    unsigned char padding08[12];
    Auxiliary *auxiliary;
    unsigned char padding18[48];
    ImageReference image;
    Resource resource;

    virtual ~S();
};

S::~S() {
    interfacePointer->close();
    if (auxiliary)
        auxiliary->destroy();
    shutdown1();
    shutdown2();
    shutdown3();
    shutdown4();
    shutdown5();
    shutdown6();
    shutdown7();
}
