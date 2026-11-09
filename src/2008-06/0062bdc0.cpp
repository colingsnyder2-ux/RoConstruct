// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_flagstandvirtualbe7b24435e7fb07c.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/CoordinateFrame.h>
#pragma float_control(precise,off)
#include <G3D/Vector3.h>

typedef G3D::Vector3 Vector3;

typedef G3D::CoordinateFrame Frame;

struct Object
{
    void setFrame(const Frame& value);
    void setPosition(Vector3 value);
    void activate();
};

struct Argument
{
    void assign(unsigned int value);
    Object* getObject();
};

struct Interface { virtual Frame getFrame()=0; };

extern float positionOffset;

struct S
{
    char padding0[0x104];
    unsigned int value;
    char padding1[0x2c];
    int* baseOffsets;

    int check();
    void update(Argument* argument);
};

void S::update(Argument* argument)
{
    if (check())
        return;

    argument->assign(value);
    Object* object = argument->getObject();
    if (!object)
        return;

    object->setFrame(Frame());

    Interface* interfaceObject = reinterpret_cast<Interface*>(
        reinterpret_cast<char*>(&baseOffsets) + baseOffsets[2]);

    Vector3 position=interfaceObject->getFrame().translation;
    position.y+=0.5f;
    object->setPosition(position);
    object->activate();
}