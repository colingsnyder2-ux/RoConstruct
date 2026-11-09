// from server: 100% by king_originala
struct Object {
    virtual void slot0();
    virtual int kind();
};

struct Buffer {
    unsigned char* data;
    int size;
    int capacity;

    void resize(int count, unsigned char value);
};

struct Contact {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void reset();

    Object* object;
    unsigned char padding08[0x30];
    int count;
    unsigned char padding3c[4];
    Buffer buffer;
    unsigned char padding4c[8];
    float value;
    unsigned char padding58[4];
    bool flag;
    unsigned char padding5d[7];
    int first;
    int second;

    void prepare();
    void process(int, int, int, int);
    void finish();
    void update();
};

void Contact::update()
{
    if (value <= 0.0f) {
        if (object->kind() == 7) {
            buffer.resize(count, 0);
            for (int i = 0; i < count; ++i)
                buffer.data[i] = 0;

            if (flag)
                prepare();
            else
                process(0, 1, first - 6, second - 6);

            finish();
        }
    } else {
        reset();
        first = -1;
        second = -1;
    }
}
