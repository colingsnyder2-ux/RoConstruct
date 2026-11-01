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
class SecondBase { public: virtual ~SecondBase(); };
class Instance : public GuidItemBase, public AbstractFactoryProductBase, public Reflection::DescribedBase, public Debugable {
public:
	Instance();
	virtual ~Instance();
	char instPad[0x8c - 0x28];
};
class Controller : public Instance, public SecondBase { public: Controller(); int c[2]; };
class DescribedVehicleController : public Controller { public: DescribedVehicleController(); };
struct SP { void* px; void* pn; SP() : px(0), pn(0) {} ~SP(); };
class VehicleController : public DescribedVehicleController {
	SP a;
public:
	VehicleController();
	virtual ~VehicleController();
};
VehicleController::VehicleController() {}
}
