// from server: 100% by EspClaude
// from server: 62% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-view roc_espclaude_5ad92cb9b0b5593a.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <G3D/Color3.h>
#include <G3D/Color4.h>
#include <G3D/ReferenceCount.h>
namespace G3D {
class Sky : public ReferenceCountedObject { };
class LightingParameters {
public:
	LightingParameters(const LightingParameters&);
	~LightingParameters();
	char data[0xf8];
};
}
namespace RBX {
namespace RenderBase {
class RenderSceneBase {
public:
	virtual ~RenderSceneBase();
	virtual void presetLighting(G3D::ReferenceCountedPointer<G3D::Sky> sky, G3D::LightingParameters skyParameters, G3D::Color3 ambientTop, G3D::Color3 ambientBottom) = 0;
	char pad[0x10];
	G3D::Color4 colorClearValue;
	void setClearColor(G3D::Color4 c) { colorClearValue = c; }
};
}
namespace RenderNew {
class RenderScene : public RenderBase::RenderSceneBase {
public:
	char pad2[0x328 - 0x24];
	G3D::Color4 clearColor2;
};
}
class Lighting {
public:
	char pad[0x130];
	G3D::LightingParameters skyParameters;
	G3D::Color3 ambientTop;
	G3D::Color3 ambientBottom;
	bool hasSky;
	G3D::Color4 clearColor;
	G3D::Color4 clearColor2;
	const G3D::LightingParameters& getSkyParameters() const { return skyParameters; }
	G3D::Color4 getClearColor() const { return clearColor; }
	G3D::Color4 getClearColor2() const { return clearColor2; }
	G3D::Color3 getAmbientTop() const { return ambientTop; }
	G3D::Color3 getAmbientBottom() const { return ambientBottom; }
};
class DataModel {
public:
	Lighting* createLighting();
};
namespace ServiceProvider {
template<class Class> inline Class* create(DataModel* context)
{
	return context ? context->createLighting() : NULL;
}
}
namespace View {
class View {
public:
	virtual void suppressSkybox();
	int unk4;
	boost::shared_ptr<RenderBase::RenderSceneBase> renderLibScene;
	int unk10;
	boost::shared_ptr<DataModel> dataModel;
};
void View::suppressSkybox()
{
	Lighting* lighting = ServiceProvider::create<Lighting>(dataModel.get());

	renderLibScene->presetLighting(NULL, lighting->getSkyParameters(), lighting->getAmbientTop(), lighting->getAmbientBottom());
	renderLibScene->colorClearValue = lighting->getClearColor();
	dynamic_cast<RenderNew::RenderScene*>(renderLibScene.get())->clearColor2 = lighting->getClearColor2();
}
}
}
