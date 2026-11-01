// from server: 100% by king_originala
struct TreeStage;

struct Object {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int state();
    virtual void slot4();
    virtual int level();

    void setStage(int stage);
};

extern "C" void __cdecl prepare(Object* object);

struct TreeStage {
    void process(Object* object);
    void promote(Object* object);
    void insert(Object* object);
};

void TreeStage::process(Object* object)
{
    if (!object->state())
        object->level();

    prepare(object);
    object->setStage((int)this);

    if (!object->state() && object->level() >= 5)
        promote(object);
    else
        insert(object);
}
