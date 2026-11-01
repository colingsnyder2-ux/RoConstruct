// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
namespace Reflection { class DescribedBase { public: virtual ~DescribedBase(); protected: const void* descriptor; }; }
class GuidItemBase { public: virtual ~GuidItemBase(); int g[4]; };
class AbstractFactoryProductBase { public: virtual ~AbstractFactoryProductBase(); };
class Debugable { public: virtual ~Debugable(); int d; };
class Instance : public GuidItemBase, public AbstractFactoryProductBase, public Reflection::DescribedBase, public Debugable {
public:
	Instance();
	virtual ~Instance();
	char instPad[0x8c - 0x28];
};
class IRenderable { public: virtual ~IRenderable(); };
class FaceInstance : public Instance, public IRenderable {
public:
	FaceInstance();
	virtual ~FaceInstance();
	char facePad[0xa0 - 0x90];
};
extern char sDecal[];
template<class Class, class Base, char* name>
class FactoryProduct : public Base {
public:
	FactoryProduct();
	virtual ~FactoryProduct() {}
};
class Decal : public FactoryProduct<Decal, FaceInstance, sDecal> {
	std::string texture;
public:
	Decal();

};
Decal::Decal() {}
}
