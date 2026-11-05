// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_shadowgeometrybool8be85f1e5c42e020.cpp

// Candidate translation unit (score above; library headers required).
struct Light;
struct VertexArray {
    char data[72];
};

struct RenderDevice {
    void beginIndexedPrimitives();
    void setVertexArray(const VertexArray&);
    void setArray(int, int, int, const void*);
    void prepareIndices();
    void sendIndices(int, int);
    void endIndexedPrimitives();
};

struct RenderItem {
    virtual void slot0();
    virtual void slot1();
    virtual void render(RenderDevice*, const Light&, bool, float);
};

struct S {
    char padding[0x2a4];
    RenderItem** items;
    int itemCount;
    int reserved;
    VertexArray vertices;
    const void* arrayData;
    int arrayCount;

    void render(RenderDevice*, const Light&, bool, float);
};

void S::render(RenderDevice* device, const Light& arg2, bool arg3, float arg4)
{
    device->beginIndexedPrimitives();
    device->setVertexArray(vertices);
    int count = arrayCount;
    device->setArray(2, 4, count, arrayData);
    device->prepareIndices();
    device->sendIndices(2, count);
    device->endIndexedPrimitives();

    for (int i = 0; i < itemCount; ++i)
        items[i]->render(device, arg2, arg3, arg4);
}
