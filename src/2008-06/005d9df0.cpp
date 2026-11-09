// from server: 100% by EspClaude
// from server: 94% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_5558dffc755c69a4.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise, off)
#include <vector>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
namespace RBX {
class Primitive;
class Instance {
public:
	virtual ~Instance();
	char pad[0x100];
	Instance* parent;
	Instance* getParent() const { return parent; }
};
class ModelInstance : public Instance {
public:
	template<class F> void visitDescendents(F f);
};
class Tool : public Instance {};
class PartInstance : public Instance {
public:
	static PartInstance* fromPrimitive(Primitive*);
	void setAlphaModifier(float);
};
void collectAllDescendantCharacterPrims(boost::shared_ptr<Instance> descendant, std::vector<Primitive*>& primitives);
class HBase : public Instance { char hpad[0x14c - 0x108]; };
class IControllable { public: virtual void tellCameraNear(float distance) = 0; };
class Humanoid : public HBase, public IControllable {
public:
	static ModelInstance* getCharacterFromHumanoid(Humanoid* humanoid)
	{
		if (humanoid)
		{
			if (ModelInstance* character = dynamic_cast<ModelInstance*>(humanoid->getParent()))
				return character;
		}
		return NULL;
	}
	virtual void tellCameraNear(float distance);
};
void Humanoid::tellCameraNear(float distance)
{
	std::vector<Primitive*> primitives;
	if (ModelInstance* character = getCharacterFromHumanoid(this))
		character->visitDescendents(boost::bind(&collectAllDescendantCharacterPrims, _1, boost::ref(primitives)));

	float alphaModifier = 1.0f;
	if (distance < 3.0f)
	{
		alphaModifier = 0.0f;
	}
	else if (distance < 6.0f)
	{
		alphaModifier = 0.5f;
	}

	for (size_t i = 0; i < primitives.size(); i++)
	{
		PartInstance* part = PartInstance::fromPrimitive(primitives[i]);
		if (!dynamic_cast<Tool*>(part->getParent()))
		{
			part->setAlphaModifier(alphaModifier);
		}
	}
}
}
