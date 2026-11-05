// from server: 100% by king_originala
struct S;

struct Model {
    void notify();
};

Model* __cdecl func_005d7670(S* object);

struct Primary {
    virtual ~Primary();
};

struct Secondary {
    virtual ~Secondary();
};

struct Base : Primary, Secondary {
    Base(S* object);
    virtual ~Base();
};

struct Dead : Base {
    Dead(S* object);
    virtual ~Dead();
};

Dead::Dead(S* object) : Base(object)
{
    Model* model = func_005d7670(object);
    if (model)
        model->notify();
}
