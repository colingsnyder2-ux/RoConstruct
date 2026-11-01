// from server: 100% by king_originala
extern "C" long (__stdcall *InterlockedDecrement)(volatile long*);

struct Image {
    virtual void destroy(int);
    volatile long references;
    char padding[0x5C];
    int width;
    int height;

    void release();
};

struct ImagePtr {
    Image* value;
    ~ImagePtr();
};

inline ImagePtr::~ImagePtr() {
    if (value && InterlockedDecrement(&value->references) == 0) {
        value->release();
        if (value)
            value->destroy(1);
    }
}

struct Vector2 {
    float x;
    float y;

    Vector2(float a, float b);
};

inline Vector2::Vector2(float a, float b) : x(a), y(b) {}

struct TextureProxy {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual ImagePtr getImage();

    Vector2 dimensions();
};

Vector2 TextureProxy::dimensions() {
    ImagePtr image = getImage();
    Vector2 result(0.0f, 0.0f);
    if (image.value) {
        result.x = static_cast<float>(image.value->width);
        result.y = static_cast<float>(image.value->height);
    } else {
        result.y = 0.0f;
        result.x = 0.0f;
    }
    return result;
}
