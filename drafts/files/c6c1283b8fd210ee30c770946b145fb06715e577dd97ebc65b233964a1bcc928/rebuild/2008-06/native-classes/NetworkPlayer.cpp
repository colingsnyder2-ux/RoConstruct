// 2008-06 native RBX::Network::Player (inactive); evidence in native-headers/Network/Player.h.
// Verified by tests/record_native_network_player.py. Network/Players.h and v8datamodel/ModelInstance.h
// do not compile against the 2008 const-char-array DescribedCreatable; the recorder supplies
// declaration-only stand-ins (tests/NativeNetworkPlayerPlayers.h, tests/NativeTeamPendingModel.h).
// >>> native-status (generated) -- do not edit >>>
// NetworkPlayer | 2008-06 | 4 byte-exact, inactive (not link-selected)
// 4/12 mapped addresses byte-exact | named 2 | 8 unproved | 4 referenced strings (not rechecked) | by king_originala (+6) (mixed 5)
// <<< native-status | src ee51ac95 | roc native-status --write
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /D_XTP_STATICLINK /D_XTPLIB_NOAUTOLINK /fp:fast
// /fp:fast: doPeriodicIdleCheck 00494650 stores the double idle time straight to the float argument (fld/fstp
// dword [esp] at 004946b0..), without the /fp:precise rounding spill of the explicit float conversion.
#include "Network/Player.h"
#include "Network/Players.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/TimerService.h"
#include "humanoid/Humanoid2008.h"
#include "v8tree/Service.h"
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
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	namespace Reflection
	{
		// Declared (not defined) in reflection/reflection.h; LoadCharacter 004929c0 is its instance.
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

// The 2008 requirePermission calls in this unit (00493da0, 004937c0) push permission 3; the donor
// security/SecurityContext.h enum only has None = 0 and Administrator = 1 (proposal in the recorder).
static const Security::Permissions kAdministrator2008 = static_cast<Security::Permissions>(3);

// Dynamic initializers 007f0f40..007f12f0, in this order.
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

			// 00493da0 converts Vector2::zero() +/- 0.5 to the six DPHYS regions (Vector2int16(const Vector2&)
			// 005122d0, each through its own stack temporary). Open: the x87 order of the four sums differs.
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::Reflection::SignalDescImpl<2,void __cdecl(std::basic_string<char,std::char_traits<char>,std::allocator<char> >,boost::shared_ptr<RBX::Instance>)>;
template class RBX::Reflection::TSignalDesc<void __cdecl(std::basic_string<char,std::char_traits<char>,std::allocator<char> >,boost::shared_ptr<RBX::Instance>)>;
template class RBX::Reflection::TypedPropertyDescriptor<RBX::ModelInstance *>;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::Network::Player,RBX::Network::CharacterAdded> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::Network::Player,RBX::Network::CharacterRemoving> *> >;

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::Network::sPlayer>();
