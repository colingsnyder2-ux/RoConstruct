// from server: 100% by EspClaude
// from server: 94% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_4dc607117a83a1d6.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include <boost/shared_ptr.hpp>
namespace RBX {
class Instance;
class PartInstance;
template<typename Class> boost::shared_ptr<Class> shared_from(Class* r);
class Described { public: virtual ~Described(); };
struct SignalDesc { void fire(Described* source, boost::shared_ptr<Instance> arg) const; };
extern SignalDesc event_removed;
class Instance { public: virtual ~Instance(); char pad0[0x10]; Described described; char pad[0x130 - 0x18]; };
class PartInstance : public Instance {};
class PhysicsService : public Instance {
	char pad2[8];
	std::set<PartInstance*> parts;
public:
	void onRemoved(PartInstance* part);
	operator Described*() { return &described; }
};
void PhysicsService::onRemoved(PartInstance* part)
{
	parts.erase(part);
	event_removed.fire(this ? &described : 0, shared_from(part));
}
}
