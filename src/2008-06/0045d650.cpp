// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>

struct Rect2D {
    float x0, y0, x1, y1;
    static Rect2D xywh(float x, float y, float w, float h);
};

struct RenderDevice {
    void push2D(unsigned int a, unsigned int b);
    int width();
    int height();
    void setViewport(const Rect2D& v);
};

struct Texture {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37(); virtual void bind();
};

template<class T> struct Ref { T* p; T* operator->() const { return p; } bool isNull() const { return p == 0; } };

namespace GLCaps { const std::string& renderer(); }
bool beginsWith(const std::string& test, const std::string& pattern);

extern Texture* currentTexture;

struct Table {
    unsigned char padding0[0x8b];
    bool applied;
    unsigned char padding1[0xa4 - 0x8c];
    Texture* texture;
    unsigned char gap[4];
    Ref<RenderDevice> renderDevice;

    void prepare();
    void configure(unsigned int, unsigned int);
    void apply(unsigned int mode, unsigned int a, unsigned int b);
};

void Table::apply(unsigned int mode, unsigned int a, unsigned int b)
{
    if (!texture || renderDevice.isNull())
        return;

    std::string r = GLCaps::renderer();
    if (beginsWith(r, "MOBILITY RADEON 7500")) {
        prepare();
        try {
            configure(a, b);
            Texture* t = texture;
            if (currentTexture != t) {
                t->bind();
                currentTexture = t;
            }
        } catch (...) {
        }
    } else {
        renderDevice->push2D(a, b);
        RenderDevice* rd = renderDevice.p;
        Rect2D view = Rect2D::xywh(0, 0, (float)rd->width(), (float)rd->height());
        renderDevice->setViewport(view);
    }
    applied = true;
}
