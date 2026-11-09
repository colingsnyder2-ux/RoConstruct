// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_65cb7ef5d764b5af.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise, off)
#include "G3D/Vector3.h"
#include "G3D/Matrix3.h"
static inline G3D::Vector3 getColumn(const G3D::Matrix3& m, int c) { return G3D::Vector3(m[0][c], m[1][c], m[2][c]); }
static inline G3D::Vector3 getWorldNormal(int id, const G3D::Matrix3& mat) { return (1 - (id / 3) * 2) * getColumn(mat, id % 3); }
typedef G3D::Vector3 Vector3;
struct Instance {
    void* getCastObject();
    const G3D::Matrix3& getMatrix();
};

struct Model {
    void setDirection(const Vector3&);
};

struct Argument {
    Instance* instance;
    int face;
};

extern unsigned char sourceType;
extern unsigned char destinationType;

extern "C" void* __cdecl runtimeCast(
    void*, long, void*, void*, int);

void __stdcall setFront(Argument* argument)
{
    Instance* instance = argument->instance;
    Model* model = static_cast<Model*>(runtimeCast(
        instance->getCastObject(), 0,
        &sourceType, &destinationType, 0));

    if (model) {
        int face = argument->face;
        model->setDirection(getWorldNormal(face, instance->getMatrix()));
    }
}
