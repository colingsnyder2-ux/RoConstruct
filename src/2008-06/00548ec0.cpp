// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Analog for 00548ec0: after the shared initializer (00548cb0) and unless
// disabled (flag 009738a1), binds each available global program/state to the
// device: valid() is 004892d0, binders 00479820/00479840/00479860.
class Resource {
public:
    bool notNull() const;
    void* pointer;
};

class Device {
public:
    void reset();
    void bindVertex(const Resource& r);
    void bindPixel(const Resource& r);
    void bindStage(int stage, const Resource& r);
};

void initializeShared();
extern bool sharedDisabled;
extern Resource vertexProgram;
extern Resource pixelProgram;
extern Resource stageZero;
extern Resource stageTwo;

void bindShared(Device* device, bool useStageZero, bool useStageTwo)
{
    initializeShared();
    if (sharedDisabled)
        return;
    do {} while (0);
    device->reset();
    if (vertexProgram.notNull())
        device->bindVertex(vertexProgram);
    if (pixelProgram.notNull())
        device->bindPixel(pixelProgram);
    if (useStageZero && stageZero.notNull())
        device->bindStage(0, stageZero);
    if (useStageTwo && stageTwo.notNull())
        device->bindStage(2, stageTwo);
}
