// from server: 100% by EspClaude
// from server: 86% by EspClaude
// from server: 100% by EspClaude
// from server: 99% by EspClaude
// from server: 89% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_5a179fbe55128dae.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <stddef.h>
#include <algorithm>
#include <boost/noncopyable.hpp>
#include <windows.h>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
namespace RBX {
class Instance {
public:
	virtual ~Instance();
	char exePad[0x88];
};
template<class Class>
boost::shared_ptr<Class> shared_from(Class* r);
template<typename T>
class CopyOnWrite : public boost::noncopyable
{
private:
	boost::shared_ptr<T> object;
public:
	boost::shared_ptr<T>& write();
};
class ServiceProvider : public Instance {
public:
	static const ServiceProvider* findServiceProvider(const Instance* context);
};
template<class Signature> class ExeSignal {
public:
	void operator()(boost::shared_ptr<Instance> arg1);
};
namespace Network {
class Player : public Instance {
public:
	virtual ~Player();
};
class Client {
public:
	static bool clientIsPresent(const Instance* context, bool testInDatamodel);
};
class Players : public Instance
{
	char pad8c[0xd4 - 0x8c];
	CopyOnWrite<std::vector<boost::shared_ptr<Instance> > > players;
	char padDC[0xf0 - 0xdc];
	ExeSignal<void(boost::shared_ptr<Instance>)> playerRemovingSignal;
public:
	static bool backendProcessing(const Instance* context, bool testInDatamodel);
protected:
	virtual void onChildRemoving(Instance* child);
};
inline bool Players::backendProcessing(const Instance* context, bool testInDatamodel)
{
	const ServiceProvider* sp = ServiceProvider::findServiceProvider(context);
	return sp && !Client::clientIsPresent(context, testInDatamodel);
}
void Players::onChildRemoving(Instance* child)
{
	Player* player = dynamic_cast<Player*>(child);
	if (!player)
		return;

	boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > >& myPlayers = players.write();
	myPlayers->erase(std::find(myPlayers->begin(), myPlayers->end(), shared_from(child)));

	if (backendProcessing(this, false))
		playerRemovingSignal(shared_from(player));
}
}
}
