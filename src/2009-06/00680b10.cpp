// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection {
class ClassDescriptor;
class DescribedBase { public: virtual ~DescribedBase(); protected: const ClassDescriptor* descriptor; };
}
class GuidItemBase { public: virtual ~GuidItemBase(); int g[4]; };
class AbstractFactoryProductBase { public: virtual ~AbstractFactoryProductBase(); };
class Debugable { public: virtual ~Debugable(); int d; };
class Instance : public GuidItemBase, public AbstractFactoryProductBase, public Reflection::DescribedBase, public Debugable {
public:
	Instance();
	virtual ~Instance();
	char ipad[0x8c - 0x28];
};
class DataModelMesh : public Instance { public: DataModelMesh(); char mpad[0xb8 - 0x8c]; };
template<class Base, char** ClassName> class NonFactoryProduct : public Base { protected: NonFactoryProduct() {} virtual ~NonFactoryProduct() {} };
namespace Reflection {
template<class Class, char** sClassName, class BaseClass>
class __declspec(novtable) Described : public BaseClass {
public:
	Described();
};
}
extern char* sBevelMesh;
class BevelMesh : public Reflection::Described<BevelMesh, &sBevelMesh, NonFactoryProduct<DataModelMesh, &sBevelMesh> > {
public:
	BevelMesh();
	~BevelMesh();
	float bevel;
	float bevelRoundness;
	float bulge;
};
BevelMesh::BevelMesh()
	: bevel(0), bevelRoundness(0), bulge(0)
{
}
}
