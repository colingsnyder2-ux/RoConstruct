// from server: 100% by king_originala
struct Vector2
{
    float x;
    float y;
};

struct Texture
{
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
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual unsigned int height();
    virtual unsigned int width();
};

struct TextureProxy
{
    unsigned char padding[0x58];
    Texture* texture;

    Vector2 getSize();
};

Vector2 TextureProxy::getSize()
{
    Vector2 result = { 0.0f, 0.0f };
    Texture* current = texture;

    if (current)
    {
        result.x = (float)current->width();
        result.y = (float)texture->height();
    }
    else
    {
        result.y = 0.0f;
        result.x = 0.0f;
    }

    return result;
}
