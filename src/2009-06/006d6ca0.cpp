// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <stddef.h>
namespace RBX {
template<class T> class Allocator {
public:
	static void* operator new(size_t size);
	static void operator delete(void* p);
};
class Link {
public:
	Link();
	virtual ~Link();
	char pad[0xc8];
};
class RevoluteLink : public Link, public Allocator<RevoluteLink> {
public:
	float angle;
	RevoluteLink() : angle(0.0f) {}
};
class Edge { public: virtual ~Edge(); char pad[0x1c]; };
class SpanningEdge { public: virtual ~SpanningEdge(); char pad[0x74]; };
class Joint : public Edge, public SpanningEdge {
public:
	Joint();
	virtual ~Joint();
};
class MotorJoint : public Joint {
public:
	RevoluteLink* link;
	float currentAngle;
	float maxVelocity;
	float desiredAngle;
	MotorJoint();
	virtual ~MotorJoint();
};
MotorJoint::MotorJoint()
	: currentAngle(0.0f),
	  link(new RevoluteLink()),
	  maxVelocity(0.0f),
	  desiredAngle(0.0f)
{
}
}
