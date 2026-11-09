// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection { class PropertyDescriptor { public: virtual ~PropertyDescriptor(); }; }
extern Reflection::PropertyDescriptor desc_Steer;
class Instance { public: void raisePropertyChanged(const Reflection::PropertyDescriptor&); };
class Controller { public: virtual void a(); virtual void b(); virtual void c(); virtual void set(int a, void* p); };
class VehicleSeat : public Instance {
	char pad0[0x118];
	void* occupant;
	char pad11c[0x248 - 0x11c];
	Controller controller;
	char pad24c[0x2fc - 0x24c];
	int steer;
public:
	void setState(int state);
};
void VehicleSeat::setState(int state)
{
	if (steer != state) {
		steer = state <= -1 ? -1 : (state >= 1 ? 1 : state);
		raisePropertyChanged(desc_Steer);
		if (steer == 0)
			controller.set(0, 0);
		else
			controller.set(0, occupant);
	}
}
}
