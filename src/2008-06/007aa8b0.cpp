// from server: 100% by user
// from server: 99% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long *);

struct Control
{
    virtual ~Control();
    volatile long references;
    void dispose();
};

template <class T>
struct ReferenceCountedPointer
{
    T *m_pointer;

    ~ReferenceCountedPointer()
    {
        if (m_pointer && InterlockedDecrement(&m_pointer->references) == 0)
        {
            m_pointer->dispose();
            if (m_pointer)
                delete m_pointer;
        }
    }

    void setPointer(T *);

    const ReferenceCountedPointer<T>& operator=(const ReferenceCountedPointer<T>& p)
    {
        setPointer(p.m_pointer);
        return *this;
    }
};

struct EffectSettings
{
    ReferenceCountedPointer<Control> update(float, float, bool, float, void *, void *, void *);
};

struct RenderScene
{
    char padding0[0x24];
    float shadingQuality;
    float meshDetail;
    char padding1[0x2f4 - 0x2c];
    EffectSettings effectSettings;
    char padding2[0x308 - 0x2f5];
    ReferenceCountedPointer<Control> desiredLighting;
    ReferenceCountedPointer<Control> lighting;
    bool shadows;
    char padding3[3];
    float cameraDistance;
    char padding4[0x3a0 - 0x318];
    char desiredSkyParameters[0xf8];
    char skyParameters;

    void setLighting(const ReferenceCountedPointer<Control>&);
};

void RenderScene::setLighting(const ReferenceCountedPointer<Control>& L)
{
    desiredLighting = L;
    lighting = effectSettings.update(shadingQuality, meshDetail, shadows, cameraDistance,
                                     &desiredLighting, desiredSkyParameters, &skyParameters);
}
