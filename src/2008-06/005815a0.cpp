// from server: 100% by colin
//

//

struct Subject;

struct Intermediate {
    Subject* resolve();
};

struct Source {
    Intermediate* get();
};

struct Camera {
    void setType(int);
    void setSubject(Subject*);
};

struct CameraProvider {
    virtual void unused();
    virtual Camera* getCamera();
};

struct Model {
    char padding[0x288];
    CameraProvider cameras;
};

struct String {
    unsigned int unused;
    union {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int size;
    unsigned int capacity;
};

struct Descriptor {
    unsigned int unused;
    String name;
};

struct Disposable {
    virtual void release(int);
};

extern "C" void __cdecl notify(const char*, Model*);

struct Command {
    unsigned int unused0;
    Descriptor* descriptor;
    unsigned int unused8;
    Model* model;
    char padding[16];
    Source* source;

    void execute(Disposable*);
};

void Command::execute(Disposable* disposable)
{
    Subject* subject = (source ? source->get() : 0)->resolve();

    model->cameras.getCamera()->setType(2);
    model->cameras.getCamera()->setSubject(subject);

    Model* target = model;
    String* name = &descriptor->name;
    const char* text = name->capacity >= 16
        ? name->storage.pointer
        : name->storage.buffer;

    notify(text, target);
    disposable->release(1);
}
