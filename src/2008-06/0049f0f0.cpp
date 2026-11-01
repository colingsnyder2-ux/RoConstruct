// from server: 100% by king_originala
struct Interface {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void finish(int, int);
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void configure(int, int, int, int);
};

struct S {
    char padding[0x140];
    Interface* object;
    char padding144[4];
    int first;
    int second;

    void prepare();
    void f(int value);
};

void S::f(int value)
{
    prepare();
    object->configure(first, second, 1, 0);
    object->finish(value, 0);
}
