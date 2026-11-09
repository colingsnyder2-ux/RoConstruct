// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_0273d3be2b1c5160.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include "G3D/Color3.h"
#include "G3D/Color4.h"
namespace RBX {
class Adorn;
class Primitive;
enum SelectState { SELECT_NORMAL };
enum NormalId { NORM_X };
class Instance
{
public:
	virtual ~Instance();
	char pad[0x100];
	Instance* parent;
	char pad2[0x28];
	Instance* getParent() const { return parent; }
};
class IRenderable
{
public:
	int index2d, index3d;
	void* bucket;
	virtual void render3dSelect(Adorn* adorn, SelectState selectState);
};
class PartInstance : public Instance { public: Primitive* getPrimitive() const; };
class Draw { public: static const G3D::Color3& selectColor(); };
class DrawAdorn { public: static void surfaceBorder(Primitive* prim, NormalId face, Adorn* adorn, const G3D::Color4& color); };
class FaceInstance : public Instance, public IRenderable
{
public:
	NormalId face;
	virtual void render3dSelect(Adorn* adorn, SelectState selectState);
};
void FaceInstance::render3dSelect(Adorn* adorn, SelectState selectState)
{
	if (PartInstance* part = dynamic_cast<PartInstance*>(getParent()))
		DrawAdorn::surfaceBorder(part->getPrimitive(), face, adorn, G3D::Color4(Draw::selectColor(), 1.0f));
}
}
