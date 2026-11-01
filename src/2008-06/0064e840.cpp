// from server: 100% by king_originala
struct Color {
    float r, g, b, a;
    Color();
};

struct Image {
    void draw(void* context, bool enabled, const Color& color);
};

struct Widget {
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
    virtual void slot10();
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
    virtual bool visible();

    char padding[0x140];
    int state;
    Image image;

    Color getColor(int mode);
    void draw(void* context);
};

void Widget::draw(void* context)
{
    if (visible()) {
        int mode;
        switch (state) {
        case 1:
            mode = 1;
            break;
        case 2:
        case 3:
            mode = 2;
            break;
        default:
            mode = 0;
            break;
        }
        image.draw((&context)[1], true, getColor(mode));
    }
}
