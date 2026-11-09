// from server: 100% by king_originala
extern "C" void* __cdecl _RTDynamicCast(void*, long, void*, void*, int);
extern "C" char instance_type;
extern "C" char model_type;

struct Settings {
    unsigned char padding[0x1e4];
    int value;
    void notify(void*);
    void setValue(int);
};

struct Model {
    int hasBodyColors();
    Settings* getHead();
    Settings* getTorso();
    Settings* getLeftArm();
    Settings* getRightArm();
    Settings* getLeftLeg();
    Settings* getRightLeg();
};

struct BodyColors {
    unsigned char padding[0x104];
    void* parent;
    unsigned char padding2[0x2c];
    int headColor;
    int leftLegColor;
    int rightLegColor;
    int torsoColor;
    int leftArmColor;
    int rightArmColor;

    void apply(Model*);
};

void BodyColors::apply(Model* model)
{
    if (parent) {
        Model* owner = static_cast<Model*>(
            _RTDynamicCast(parent, 0, &instance_type, &model_type, 0));
        if (owner && owner->hasBodyColors())
            return;
    }

    Settings* part = model->getHead();
    if (part)
        part->setValue(headColor);

    part = model->getLeftArm();
    if (part)
        part->setValue(leftArmColor);

    part = model->getRightArm();
    if (part)
        part->setValue(rightArmColor);

    part = model->getTorso();
    if (part)
        part->setValue(torsoColor);

    part = model->getLeftLeg();
    if (part)
        part->setValue(leftLegColor);

    part = model->getRightLeg();
    if (part)
        part->setValue(rightLegColor);
}
