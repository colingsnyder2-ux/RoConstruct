#include <boost/thread/once.hpp>
#include "v8tree/Service.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/SpawnerService.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/TimerService.h"
#include "v8datamodel/Backpack.h"
#include "util/RunStateOwner.h"
#include "Network/Player.h"
#include "Network/Players.h"

namespace RBX
{
	template<class Class, class Derived, const char* Name>
	const RBX::Name& FactoryProduct<Class, Derived, Name>::className() { return RBX::Name::declare<Name>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class Class> size_t ServiceProvider::doGetClassIndex() { static size_t index = newIndex(); return index; }
	template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }
	template<class Class> size_t ServiceProvider::getClassIndex()
	{
		static boost::once_flag flag = BOOST_ONCE_INIT;
		boost::call_once(&callDoGetClassIndex<Class>, flag);
		return doGetClassIndex<Class>();
	}

	template<class Class> Class* ServiceProvider::find() const
	{
		size_t index = getClassIndex<Class>();
		Class* service;
		if (index + 1 > serviceArray.size())
		{
			serviceArray.resize(index + 1, boost::shared_ptr<Instance>());
			service = NULL;
		}
		else
		{
			service = static_cast<Class*>(serviceArray[index].get());
			if (service != NULL)
				return service;
		}
		boost::shared_ptr<Instance> item = findServiceByClassName(Class::className());
		if (!item)
			return NULL;
		service = static_cast<Class*>(item.get());
		serviceArray[index] = item;
		return service;
	}

	template<class Class> Class* ServiceProvider::create() const
	{
		Class* service = find<Class>();
		if (service == NULL)
		{
			boost::shared_ptr<Class> value = Creatable<Instance>::create<Class>();
			service = value.get();
			size_t index = getClassIndex<Class>();
			serviceArray[index] = value;
			service->setParent(const_cast<ServiceProvider*>(this));
		}
		return service;
	}

	template<class Class> Class* ServiceProvider::find(const Instance* context)
	{
		for (const Instance* instance = context; instance; instance = instance->getParent())
		{
			if (const ServiceProvider* provider = dynamic_cast<const ServiceProvider*>(instance))
				return provider->find<Class>();
		}
		return NULL;
	}

	template<class Class> Class* ServiceProvider::create(const Instance* context)
	{
		for (const Instance* instance = context; instance; instance = instance->getParent())
		{
			if (const ServiceProvider* provider = dynamic_cast<const ServiceProvider*>(instance))
				return provider->create<Class>();
		}
		return NULL;
	}

	template Workspace* ServiceProvider::find<Workspace>() const;
	template SpawnerService* ServiceProvider::find<SpawnerService>() const;
	template StarterPackService* ServiceProvider::find<StarterPackService>() const;
	template TimerService* ServiceProvider::find<TimerService>() const;
	template TimerService* ServiceProvider::create<TimerService>() const;
	template Workspace* ServiceProvider::find<Workspace>(const Instance* context);
	template SpawnerService* ServiceProvider::find<SpawnerService>(const Instance* context);
	template StarterPackService* ServiceProvider::find<StarterPackService>(const Instance* context);
	template TimerService* ServiceProvider::create<TimerService>(const Instance* context);
	template Network::Players* ServiceProvider::find<Network::Players>(const Instance* context);
	template RunService* ServiceProvider::create<RunService>(const Instance* context);

	template const Name& FactoryProduct<Network::Player, Instance, Network::sPlayer>::getClassName() const;

	namespace Network
	{
		Backpack* Player::getPlayerBackpack() const
		{
			return findFirstChildOfType<Backpack>();
		}
	}
}

template class boost::shared_ptr<RBX::RunService>;
template class std::_Vector_iterator<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > >;
template class std::deque<RBX::Network::AbuseReport,std::allocator<RBX::Network::AbuseReport> >;

#include <stdexcept>

namespace RBX
{
	namespace Network
	{
		void Player::rebuildBackpack()
		{
			if (!Players::backendProcessing(this, true))
				throw std::runtime_error("rebuildBackpack can only be called by the backend server");

			while (Backpack* r = findFirstChildOfType<Backpack>())
			{
				r->setParent(NULL);
			}

			boost::shared_ptr<Instance> backpack = Creatable<Instance>::create<Backpack>();
			backpack->setParent(this);

			if (StarterPackService* starterPack = ServiceProvider::find<StarterPackService>(this))
			{
				for (size_t i = 0; i < starterPack->numChildren(); i++)
				{
					boost::shared_ptr<Instance> copy = starterPack->getChild(i)->clone();
					copy->setParent(backpack.get());
				}
			}
		}

#if 0
		void Player::loadCharacter(bool inGame)
		{
			Workspace* workspace = ServiceProvider::find<Workspace>(this);
			if (!workspace)
				throw std::runtime_error("LoadCharacter can only be called when Player is in the world");

			if (!Players::backendProcessing(this, true))
				throw std::runtime_error("LoadCharacter can only be called by the backend server");

			std::vector<boost::shared_ptr<Instance> > instances;
			ServiceProvider::create<ContentProvider>(this)->load(ContentId::fromAssets("fonts\\character.rbxm"), instances);

			if (instances.size() != 1)
				throw std::runtime_error("character.rbxm should contain a Character model");

			boost::shared_ptr<ModelInstance> model = boost::shared_dynamic_cast<ModelInstance>(instances.front());
			if (!model)
				throw std::runtime_error("character.rbxm should contain a Character model");

			Humanoid* humanoid = Humanoid::modelIsCharacter(model.get());
			if (!humanoid)
				throw std::runtime_error("character.rbxm should contain a humanoid");

			{
				std::vector<boost::shared_ptr<Instance> > extraSound;
				ServiceProvider::create<ContentProvider>(this)->load(ContentId::fromAssets("fonts\\humanoidSound.rbxm"), extraSound);
				std::for_each(extraSound.begin(), extraSound.end(), boost::bind(&addChild, model, _1));
			}
			{
				std::vector<boost::shared_ptr<Instance> > extraHealth;
				ServiceProvider::create<ContentProvider>(this)->load(ContentId::fromAssets("fonts\\humanoidHealth.rbxm"), extraHealth);
				std::for_each(extraHealth.begin(), extraHealth.end(), boost::bind(&addChild, model, _1));
			}
			{
				std::vector<boost::shared_ptr<Instance> > extraAnimate;
				ServiceProvider::create<ContentProvider>(this)->load(ContentId::fromAssets("fonts\\humanoidAnimate.rbxm"), extraAnimate);
				std::for_each(extraAnimate.begin(), extraAnimate.end(), boost::bind(&addChild, model, _1));
			}

			model->setName(getName());
			if (inGame)
				humanoid->buildJoints();
			Instance::propArchivable.setValue(model.get(), false);
			setCharacter(model.get());
			model->setParent(workspace);
			loadCharacterAppearance(!inGame);

			if (SpawnerService* spawnerService = ServiceProvider::find<SpawnerService>(this))
				spawnerService->SpawnPlayer(model, this);   // 005d2b80 (declared in v8datamodel/SpawnerService.h)
			else
				workspace->moveToPoint(model.get(), G3D::Vector3(0.0f, 20.0f, 25.0f));
		}
#endif

	}
}

#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Camera.h"
#include "humanoid/Humanoid2008.h"
#include "security/SecurityContext.h"
#include "reflection/signal.h"
#include <G3D/System.h>
#include <G3D/Vector2.h>

namespace RBX
{
	namespace Network
	{
		char sPlayer[] = "Player"; // 00934d38 (.data; setName in the constructor 00493da0)
	}

	// Template members the shared headers only declare (same definitions as Team.cpp / DecalBases.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	namespace Reflection
	{
		template<typename Class, typename Function>
		BoundFuncDesc<Class, Function, 1>::BoundFuncDesc(
			typename BoundFuncDesc<Class, Function, 1>::FunctionSig function,
			const char* name,
			const char* arg1Name,
			typename BoundFuncDesc<Class, Function, 1>::Arg1 default1,
			Security security)
			: FuncDesc<Class>(name, security),
			  function(function),
			  default1(default1)
		{
			declareSignature(arg1Name);
		}
	}
}

using namespace RBX;
using namespace RBX::Network;

static const Security::Permissions kAdministrator2008 = static_cast<Security::Permissions>(3);

static Reflection::BoundFuncDesc<Player, void(bool), 1> loadCharacterFunction(&Player::loadCharacter, "LoadCharacter", "inGame", true, Reflection::FunctionDescriptor::AnyCaller); // 0096fe28
static Reflection::BoundFuncDesc<Player, void(void), 0> removeCharacterFunction(&Player::removeCharacter, "RemoveCharacter", Reflection::FunctionDescriptor::AnyCaller); // 0096fd28
static Reflection::BoundFuncDesc<Player, void(bool), 1> func_SetUnder13(&Player::setUnder13, "SetUnder13", "value", Reflection::FunctionDescriptor::AnyCaller); // 0096fd88
static Reflection::BoundFuncDesc<Player, void(bool), 1> func_SetSuperSafeChat(&Player::setSuperSafeChat, "SetSuperSafeChat", "value", Reflection::FunctionDescriptor::AnyCaller); // 0096fc08
static Reflection::RefPropDescriptor<Player, ModelInstance> prop_Character("Character", "Data", &Player::getCharacter, &Player::setCharacter, Reflection::PropertyDescriptor::STANDARD); // 0096fe70
static Reflection::PropDescriptor<Player, std::string> prop_characterAppearance("CharacterAppearance", "Data", &Player::getCharacterAppearance, &Player::setCharacterAppearance, Reflection::PropertyDescriptor::STANDARD); // 0096fe90
static Reflection::PropDescriptor<Player, int> prop_userId("userId", "Data", &Player::getUserID, &Player::setUserID, Reflection::PropertyDescriptor::STANDARD); // 0096fc84
Reflection::BoundProp<bool, 1> Player::prop_Under13("Under13", "Data", &Player::under13, Reflection::PropertyDescriptor::STREAMING); // 0096fee4
Reflection::BoundProp<bool, 1> Player::prop_SuperSafeChat("SuperSafeChat", "Data", &Player::superSafeChat, Reflection::PropertyDescriptor::STREAMING); // 0096fcd4
Reflection::BoundProp<G3D::Vector2int16, 1> Player::prop_ServerRequestLow("ServerRequestLow", "DPHYS", &Player::serverRequestLow, Reflection::PropertyDescriptor::STREAMING); // 0096fe08
Reflection::BoundProp<G3D::Vector2int16, 1> Player::prop_ServerRequestHigh("ServerRequestHigh", "DPHYS", &Player::serverRequestHigh, Reflection::PropertyDescriptor::STREAMING); // 0096fdec
Reflection::BoundProp<G3D::Vector2int16, 1> Player::prop_ServerDemandLow("ServerDemandLow", "DPHYS", &Player::serverDemandLow, Reflection::PropertyDescriptor::STREAMING); // 0096fd0c
Reflection::BoundProp<G3D::Vector2int16, 1> Player::prop_ServerDemandHigh("ServerDemandHigh", "DPHYS", &Player::serverDemandHigh, Reflection::PropertyDescriptor::STREAMING); // 0096feac
Reflection::BoundProp<G3D::Vector2int16, 1> Player::prop_ClientSimulateLow("ClientSimulateLow", "DPHYS", &Player::clientSimulateLow, Reflection::PropertyDescriptor::STREAMING); // 0096fdd0
Reflection::BoundProp<G3D::Vector2int16, 1> Player::prop_ClientSimulateHigh("ClientSimulateHigh", "DPHYS", &Player::clientSimulateHigh, Reflection::PropertyDescriptor::STREAMING); // 0096fcf0
static Reflection::PropDescriptor<Player, BrickColor> prop_teamColor("TeamColor", "Team", &Player::getTeamColor, &Player::setTeamColor, Reflection::PropertyDescriptor::STANDARD); // 0096fd68
static Reflection::PropDescriptor<Player, bool> prop_neutral("Neutral", "Team", &Player::getNeutral, &Player::setNeutral, Reflection::PropertyDescriptor::STANDARD); // 0096fec8
static Reflection::SignalDesc<Player, void(std::string, boost::shared_ptr<Instance>)> event_Chatted("Chatted", "message", "recipient"); // 0096fca0
static Reflection::SignalDesc<Player, void(float)> event_Idled("Idled", "time"); // 0096fc50

namespace RBX
{
	namespace Network
	{
		Player::Player()
			: teamColor(BrickColor::lego_1),
			  neutral(true),
			  under13(false),
			  superSafeChat(false),
			  userId(0),
			  lastActivityTime(0.0)
		{
			Security::Context::current().requirePermission(kAdministrator2008, "create a Player");
			setName(sPlayer);

			const G3D::Vector2& center = G3D::Vector2::zero();
			float x1 = center.x + 0.5f;
			float y1 = center.y + 0.5f;
			float x0 = center.x - 0.5f;
			float y0 = center.y - 0.5f;
			G3D::Vector2 low(x0, y0);
			G3D::Vector2 high(x1, y1);
			{ G3D::Vector2int16 region(low); serverRequestLow = region; }
			{ G3D::Vector2int16 region(high); serverRequestHigh = region; }
			{ G3D::Vector2int16 region(low); serverDemandLow = region; }
			{ G3D::Vector2int16 region(high); serverDemandHigh = region; }
			{ G3D::Vector2int16 region(low); clientSimulateLow = region; }
			{ G3D::Vector2int16 region(high); clientSimulateHigh = region; }
		}

		Player::~Player()
		{
			setCharacter(NULL);
		}

		void Player::setName(const std::string& value)
		{
			Security::Context::current().requirePermission(kAdministrator2008, "set a Player's name");
			Instance::setName(value);
		}

		void Player::setTeamColor(BrickColor value)
		{
			if (value != teamColor)
			{
				teamColor = value;
				raisePropertyChanged(prop_teamColor);
			}
		}

		void Player::setNeutral(bool value)
		{
			if (value != neutral)
			{
				neutral = value;
				raisePropertyChanged(prop_neutral);
			}
		}

		void Player::setUserID(int value)
		{
			if (value != userId)
			{
				userId = value;
				raisePropertyChanged(prop_userId);
			}
		}

		void Player::removeCharacter()
		{
			if (!Players::backendProcessing(this, true))
				throw std::runtime_error("RemoveCharacter can only be called by the backend server");

			setCharacter(NULL);
		}

		void Player::setCharacterAppearance(const std::string& value)
		{
			if (value != characterAppearance)
			{
				characterAppearance = value;
				if (Players::backendProcessing(this, false))
					loadCharacterAppearance(false);

				raisePropertyChanged(prop_characterAppearance);
			}
		}

		void Player::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
		{
			if (oldProvider && Players::backendProcessing(oldProvider, true))
				setCharacter(NULL);

			if (newProvider && Players::frontendProcessing(newProvider, true))
				onCharacterChangedFrontend();

			if (!oldProvider && Players::frontendProcessing(newProvider, true))
			{
				lastActivityTime = G3D::System::getLocalTime();
				doPeriodicIdleCheck();
			}
		}

		void Player::onCharacterChangedFrontend()
		{
			if (this == Players::findLocalPlayer(this))
			{
				Workspace* workspace = ServiceProvider::find<Workspace>(this);
				if (character.get() == NULL)
				{
					workspace->getCamera()->setCameraType(Camera::FIXED_CAMERA);
					workspace->getCamera()->setDistanceFromTarget(0.0f);
					workspace->getCamera()->zoom(-1.0f);
				}
				else
				{
					workspace->getCamera()->setCameraSubject(Humanoid::modelIsCharacter(character.get()));
					workspace->getCamera()->setCameraType(Camera::CUSTOM_CAMERA);
					workspace->getCamera()->setDistanceFromTarget(13.0f);
					workspace->getCamera()->zoom(-1.0f);
					workspace->setDefaultMouseCommand();
				}
			}
		}

		void Player::doPeriodicIdleCheck()
		{
			if (ServiceProvider::findServiceProvider(this))
			{
				if (lastActivityTime != 0.0)
				{
					G3D::RealTime idleTime = G3D::System::getLocalTime() - lastActivityTime;
					if (idleTime > 120.0)
					{
						Players* players = ServiceProvider::find<Players>(this);
						if (players && players->getLocalPlayer() && Players::clientIsPresent(this, true))
							event_Idled.fire(this, static_cast<float>(idleTime));
					}
				}

				TimerService* timerService = ServiceProvider::create<TimerService>(this);
				if (timerService)
					timerService->delay(boost::bind(&Player::doPeriodicIdleCheck, shared_from(this)), 30.0);
			}
		}

		void Player::setCharacter(ModelInstance* value)
		{
			if (value != character.get())
			{
				if (character.get())
				{
					characterDiedConnection.disconnect();

					Notifier<Player, CharacterRemoving>::raise(character.get());

					if (Players::backendProcessing(this, false))
						character->setParent(NULL);

					character.reset();
				}

				if (value)
				{
					character = shared_from(value);

					Notifier<Player, CharacterAdded>::raise(character.get());

					if (Players::frontendProcessing(this, false))
						onCharacterChangedFrontend();
				}

				raisePropertyChanged(prop_Character);
			}
		}
	}
}

template class RBX::Reflection::SignalDescImpl<2,void __cdecl(std::basic_string<char,std::char_traits<char>,std::allocator<char> >,boost::shared_ptr<RBX::Instance>)>;
template class RBX::Reflection::TSignalDesc<void __cdecl(std::basic_string<char,std::char_traits<char>,std::allocator<char> >,boost::shared_ptr<RBX::Instance>)>;
template class RBX::Reflection::TypedPropertyDescriptor<RBX::ModelInstance *>;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::Network::Player,RBX::Network::CharacterAdded> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::Network::Player,RBX::Network::CharacterRemoving> *> >;

template void RBX::Name::callDoDeclare<RBX::Network::sPlayer>();
