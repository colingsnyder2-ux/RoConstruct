// from server: 100% by king_originala
namespace RBX {
struct Instance {
    void prepare(void*);
};

struct ServiceProvider {
    void apply(int);
};
}

RBX::ServiceProvider* func_005807b0(RBX::Instance*);

struct Callback {
    virtual void complete(int);
};

struct S {
    char padding[12];
    RBX::Instance* object;
    void execute(Callback*);
};

void S::execute(Callback* callback)
{
    object->prepare(reinterpret_cast<char*>(object) + 0x2d4);
    func_005807b0(object)->apply(11);
    callback->complete(1);
}
