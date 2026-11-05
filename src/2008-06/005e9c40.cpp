// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_movingprimitivesnativeset1fba8159194f33b8.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include <G3D/Array.h>
#pragma float_control(precise, off)

extern "C" void (__cdecl *invalid_parameter)();
extern float threshold;

struct Primitive;
struct Assembly;

struct Properties {
    char padding[0x28];
    float value;
};

struct Link {
    char padding[0x1c];
    Assembly* assembly;
};

struct __declspec(align(8)) PrimIterator {
    Primitive* current;
    int state;
    void advance();
};

struct Assembly {
    Properties* properties();
};

struct Primitive {
    char padding[0x24];
    Link* link;
    PrimIterator begin();
    PrimIterator end();
    Properties* properties();
};

struct Instance {
 virtual void slot0();virtual int kind();int unused;Instance* parent;
 char padding0[0x114];
 std::set<Primitive*> primitives;
};
typedef G3D::Array<Primitive*> Array;
struct S {
    char padding[0x88];
    Instance* instance;
    void f(Array*);
};

void S::f(Array* output)
{
    Instance* root = instance;
    while (root->kind() != 5)
        root = root->parent;

    for(std::set<Primitive*>::iterator it=root->primitives.begin();it!=root->primitives.end();++it) {
        Primitive* primitive=*it;
        if(primitive->link->assembly->properties()->value < threshold) {
            PrimIterator last=primitive->end();
            PrimIterator current=primitive->begin();
            while(current.current!=last.current) {
                Primitive* value=current.current;
                if(value->properties()->value < threshold) output->append(value);
                current.advance();
            }
        }
    }
}
