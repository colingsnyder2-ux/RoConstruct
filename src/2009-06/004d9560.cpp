// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class GuidItemBase { public: virtual void g0(); char pad[0x10]; };
class Object { public: virtual void o0(); };
class DescribedBase { public: virtual void d0(); const void* descriptor; };
class Debugable { public: virtual void b0(); char pad[8]; };
class Instance : public GuidItemBase, public Object, public DescribedBase, public Debugable {
public:
	Instance();
	virtual ~Instance();
	char instancePad[0x8c - 0x2c];
};
class Service {};
template<class P> class Ptr { P* px; void* pn; public: ~Ptr(); };
namespace Network {
class Registry;
class FactoryProductGRS : public Instance {
public:
	FactoryProductGRS();
	virtual ~FactoryProductGRS();
};
class GuidRegistryService : public FactoryProductGRS, public Service {
	Ptr<Registry> registry;
	static Ptr<Registry> createRegistry();
public:
	GuidRegistryService();
	virtual ~GuidRegistryService();
};
GuidRegistryService::GuidRegistryService() : registry(createRegistry()) {}
}
}
