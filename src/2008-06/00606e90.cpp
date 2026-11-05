// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_ballballnativeb8ac485d15b7b187.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off,push)
#include "util/Math.h"
struct Ball {virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual float getRadius()const;};
struct Body {char prefix[0xb8];G3D::Vector3 position;};
struct Primitive {char prefix[0x9c];Ball* ball;Body* body;};
struct Contact {char prefix[0xc];Primitive* a;Primitive* b;bool collide(float);};
bool Contact::collide(float overlap){float r0=a->ball->getRadius();float r1=b->ball->getRadius();G3D::Vector3 delta=b->body->position-a->body->position;float sum=r0+r1;if(sum>RBX::Math::longestVector3Component(delta))return delta.magnitude()<(sum-overlap);else return false;}
