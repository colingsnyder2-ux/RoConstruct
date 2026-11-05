// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_b9cb221ad6839247.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include "G3D/Vector3.h"
namespace RBX {
class Src { public: G3D::Vector3 get() const; };
class Mover
{
public:
	int a, b;
	Src* src;
	char pad[0x38 - 0xc];
	float speed;
	float lastSpeed;
	G3D::Vector3 getVelocity();
};
G3D::Vector3 Mover::getVelocity()
{
	G3D::Vector3 velocity = src->get() * 16.0f;
	lastSpeed = speed;
	speed = velocity.magnitude();
	return velocity;
}
}
