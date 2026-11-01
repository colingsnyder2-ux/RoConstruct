// from server: 100% by king_originala
struct Renderer {
    virtual void slot0();
    virtual void slot1();
    virtual void render(float x, float y, int value, float scale);
};

struct View {
    unsigned char padding[8];
    Renderer* renderer;
    void render(float x, float y, int value, float scale);
};

void View::render(float x, float y, int value, float scale)
{
    renderer->render(x, y, value, scale);
}
