// from server: 100% by Espeon
// from server: 86% by king_originala
static const float initialExtent=0.5f;
static const float initialScale=-1.0f;

struct PointerStorage {
    unsigned int unused;
    void *first;
    void *last;
    void *end;

    PointerStorage();
    ~PointerStorage();
};

inline PointerStorage::PointerStorage()
{
    last = 0;
    end = 0;
    first = 0;
}

struct RenderData {
    unsigned char storage[0x160];
    RenderData();
};

struct RenderScene {
    virtual ~RenderScene();

    PointerStorage pointers;
    float extentX;
    float extentY;
    float factorX;
    float factorY;
    float scaleX;
    float scaleY;
    unsigned int unused;
    RenderData data;

    RenderScene();
};

RenderScene::RenderScene()
    : pointers(),
      extentX(initialExtent),
      extentY(extentX),
      factorX(1.0f),
      factorY(1.0f),
      scaleX(initialScale),
      scaleY(scaleX),
      data()
{
}
