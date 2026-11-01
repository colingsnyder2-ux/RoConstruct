// from server: 100% by king_originala
struct Object {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual Object* parent();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual bool eligible();
};

struct Collection {
    void insert(Object* const& object);
};

struct TreeStage {
    char padding[16];
    void process(Object* object);
};

struct ClumpStage : TreeStage {
    Collection collection;
    void process(Object* object);
};

void ClumpStage::process(Object* object)
{
    if (!object->parent()) {
        Object* entry = object;
        if (object->eligible())
            collection.insert(entry);
    }
    TreeStage::process(object);
}
