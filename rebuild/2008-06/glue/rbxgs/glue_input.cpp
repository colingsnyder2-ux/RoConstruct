// Rebuild glue: keyboard controllers, selection membership, signal lookup and remote-origin tracking,
// which rbxgs declares but never defines (they replace empty stubs in glue_link_stubs.cpp).
// "KeyboardRight" (primary) drives with the arrow keys and "KeyboardLeft" (secondary) with WASD, as the
// 2008 ControllerType names say. Behavioural reconstruction, not byte-verified.
#include <RakPeer.h>  // first, as rbxgs Players.cpp: RakNet needs winsock2 before windows.h
#include "v8datamodel/UserController.h"
#include "v8datamodel/Selection.h"
#include "reflection/signal.h"
#include "Replicator.h"
#include <boost/thread/mutex.hpp>
#include <boost/weak_ptr.hpp>
#include <algorithm>
#include <map>

namespace RBX
{
	namespace
	{
		float axis(const UserInputBase* input, SDLKey plus, SDLKey minus)
		{
			if (!input)
				return 0.0f;
			return (input->keyDown(plus) ? 1.0f : 0.0f) - (input->keyDown(minus) ? 1.0f : 0.0f);
		}

		float driveValue(const UserInputBase* input, Controller::InputType type, SDLKey up, SDLKey down, SDLKey left, SDLKey right)
		{
			float throttle = axis(input, up, down);
			float steer = axis(input, right, left);
			switch (type)
			{
			case Controller::BACK_FORWARD_INPUT: return throttle;
			case Controller::RIGHT_LEFT_INPUT: return steer;
			case Controller::LEFT_TRACK_INPUT: return G3D::clamp(throttle + steer, -1.0f, 1.0f);
			case Controller::RIGHT_TRACK_INPUT: return G3D::clamp(throttle - steer, -1.0f, 1.0f);
			case Controller::CONSTANT_INPUT: return 1.0f;
			default: return 0.0f;
			}
		}
	}

	float KeyboardPrimaryController::getValue(Controller::InputType type) const
	{
		return driveValue(getHardwareDevice(), type, SDLK_UP, SDLK_DOWN, SDLK_LEFT, SDLK_RIGHT);
	}

	float KeyboardSecondaryController::getValue(Controller::InputType type) const
	{
		return driveValue(getHardwareDevice(), type, SDLK_w, SDLK_s, SDLK_a, SDLK_d);
	}

	bool Selection::isSelected(const Instance* instance) const
	{
		boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > items = selection.read();
		if (!items)
			return false;
		for (size_t i = 0; i < items->size(); ++i)
			if ((*items)[i].get() == instance)
				return true;
		return false;
	}

	namespace Reflection
	{
		boost::shared_ptr<SignalInstance> Signal::getSignalInstance() const
		{
			return descriptor->getSignalInstance(*instance);
		}
	}

	namespace Network
	{
		namespace
		{
			boost::mutex& remoteMutex()
			{
				static boost::mutex m;
				return m;
			}

			// instance -> the replicator it arrived through (held weakly; a dead entry means "not remote")
			std::map<const Instance*, std::pair<const Replicator*, boost::weak_ptr<Instance> > >& remoteOrigin()
			{
				static std::map<const Instance*, std::pair<const Replicator*, boost::weak_ptr<Instance> > > m;
				return m;
			}
		}

		bool Replicator::getCameFromRemotePlayer(const Instance* instance) const
		{
			boost::mutex::scoped_lock lock(remoteMutex());
			std::map<const Instance*, std::pair<const Replicator*, boost::weak_ptr<Instance> > >::const_iterator iter = remoteOrigin().find(instance);
			return iter != remoteOrigin().end() && iter->second.first == this && !iter->second.second.expired();
		}

		void Replicator::setCameFromRemotePlayer(Instance* instance)
		{
			boost::mutex::scoped_lock lock(remoteMutex());
			remoteOrigin()[instance] = std::make_pair(static_cast<const Replicator*>(this), boost::weak_ptr<Instance>(shared_from(instance)));
		}
	}
}
