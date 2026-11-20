#include "CRobloxView.h"

void CRobloxWnd::finishAttach() {
    (void)this->dataModel;
    (void)this->dataModelPtr;
    (void)this->adorn;
}

#include "v8datamodel/DataModel.h"
#include "util/Name.h"

namespace RBX {

boost::shared_ptr<boost::recursive_mutex> __cdecl DataModel::getMutex(Instance* context)
{
	if (!context)
		return boost::shared_ptr<boost::recursive_mutex>();

	Instance* root = context;
	if (context->getParent())
		root = context->getRootAncestor();

	DataModel* dataModel = dynamic_cast<DataModel*>(root);
	if (!dataModel)
		return boost::shared_ptr<boost::recursive_mutex>();

	return dataModel->getMutex();
}

}

#include "v8tree/Service.h"

namespace RBX {
	bool ServiceProvider::askAddChild(const Instance* instance) const
	{
		return dynamic_cast<const Service*>(instance) != NULL;
	}
}

#include <limits>
#include <boost/lexical_cast.hpp>
#include "util/Utilities.h"
#include "v8datamodel/BrickColor.h"
#include "G3D/Vector2int16.h"
#include "G3D/Color3.h"
#include "G3D/Vector3.h"
#include <stdlib.h>

namespace RBX
{
	// Numbers: empty text fails, lexical_cast failure (bad_lexical_cast) fails.
	template<>
	bool StringConverter<int>::convertToValue(const std::string& text, int& value)
	{
		unsigned length = text.size();
		if (length)
		{
			try
			{
				value = boost::lexical_cast<int>(text);
				return true;
			}
			catch (...)
			{
			}
		}
		return false;
	}

	// Floating point text also accepts the INF / -INF / NAN spellings.
	template<>
	bool StringConverter<float>::convertToValue(const std::string& text, float& value)
	{
		unsigned length = text.size();
		if (!length)
			return false;
		if (text == "INF")
		{
			value = std::numeric_limits<float>::infinity();
			return true;
		}
		if (text == "-INF")
		{
			value = -std::numeric_limits<float>::infinity();
			return true;
		}
		if (text == "NAN")
		{
			value = std::numeric_limits<float>::quiet_NaN();
			return true;
		}
		try
		{
			value = boost::lexical_cast<float>(text);
			return true;
		}
		catch (...)
		{
			return false;
		}
	}

	template<>
	bool StringConverter<double>::convertToValue(const std::string& text, double& value)
	{
		unsigned length = text.size();
		if (!length)
			return false;
		if (text == "INF")
		{
			value = std::numeric_limits<double>::infinity();
			return true;
		}
		if (text == "-INF")
		{
			value = -std::numeric_limits<double>::infinity();
			return true;
		}
		if (text == "NAN")
		{
			value = std::numeric_limits<double>::quiet_NaN();
			return true;
		}
		try
		{
			value = boost::lexical_cast<double>(text);
			return true;
		}
		catch (...)
		{
			return false;
		}
	}

	template<>
	bool StringConverter<BrickColor>::convertToValue(const std::string& text, BrickColor& value)
	{
		value = BrickColor::parse(text.c_str());
		return true;
	}

	template<>
	bool StringConverter<G3D::Vector2int16>::convertToValue(const std::string& text, G3D::Vector2int16& value)
	{
		int separator = text.find_first_of(",;", 0, 2);
		if (separator < 0)
			return false;
		value.x = atoi(text.substr(0, separator).c_str());
		int next = separator + 1;
		if ((int)text.size() < next)
			return false;
		value.y = atoi(text.substr(next, text.size() - next).c_str());
		return true;
	}

	// Color3: "#rrggbb", "0xrrggbb" (hex bytes scaled by 1/255), or "r,g,b" / "r;g;b" floats.
	template<>
	bool StringConverter<G3D::Color3>::convertToValue(const std::string& text, G3D::Color3& value)
	{
		const float scale = 1.0f / 255.0f;
		if (text.c_str()[0] == '#')
		{
			if (text.size() != 7)
				return false;
			value.r = strtol(text.substr(1, 2).c_str(), 0, 16) * scale;
			value.g = strtol(text.substr(3, 2).c_str(), 0, 16) * scale;
			value.b = strtol(text.substr(5, 2).c_str(), 0, 16) * scale;
		}
		else if (text.substr(0, 2) == "0x")
		{
			if (text.size() != 8)
				return false;
			value.r = strtol(text.substr(2, 2).c_str(), 0, 16) * scale;
			value.g = strtol(text.substr(4, 2).c_str(), 0, 16) * scale;
			value.b = strtol(text.substr(6, 2).c_str(), 0, 16) * scale;
		}
		else
		{
			int first = text.find_first_of(",;", 0, 2);
			if (first < 0)
				return false;
			value.r = (float)atof(text.substr(0, first).c_str());
			int start = first + 1;
			int second = text.find_first_of(",;", start, 2);
			if (second < start)
				return false;
			value.g = (float)atof(text.substr(start, second - start).c_str());
			int next = second + 1;
			if ((int)text.size() < next)
				return false;
			value.b = (float)atof(text.substr(next, text.size() - next).c_str());
		}
		return true;
	}
	template<>
	std::string StringConverter<G3D::Vector3>::convertToString(const G3D::Vector3& value)
	{
		std::string result = StringConverter<float>::convertToString(value.x);
		result += ", ";
		result += StringConverter<float>::convertToString(value.y);
		result += ", ";
		result += StringConverter<float>::convertToString(value.z);
		return result;
	}

	template<>
	bool StringConverter<G3D::Vector3>::convertToValue(const std::string& text, G3D::Vector3& value)
	{
		int first = text.find_first_of(",;", 0, 2);
		if (first < 0)
			return false;
		value.x = (float)atof(text.substr(0, first).c_str());
		int start = first + 1;
		int second = text.find_first_of(",;", start, 2);
		if (second < start)
			return false;
		value.y = (float)atof(text.substr(start, second - start).c_str());
		int next = second + 1;
		if ((int)text.size() < next)
			return false;
		value.z = (float)atof(text.substr(next, text.size() - next).c_str());
		return true;
	}
}

namespace RBX {
extern template boost::shared_ptr<DataModel> Creatable<Instance>::create<DataModel>();

boost::shared_ptr<DataModel> DataModel::createDataModel(bool start) {
    boost::shared_ptr<DataModel> result = Creatable<Instance>::create<DataModel>();
    Lock lock(result);
    result->initializeContents(start);
    result->renderEnabled = true;
    return result;
}
}

#include "util/RunStateOwner.h"

double RBX::DataModel::getDutyCycle() const { return runService->dutyCycle(); }

#include "v8datamodel/Workspace.h"

namespace RBX { typedef DescendantAdded DescendentAdded; typedef DescendantRemoving DescendentRemoving; }
#include "v8datamodel/LocalBackpack.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/JointsService.h"
#include "gui/Gui.h"
#include "util/Sound.h"

namespace RBX {
class PhysicsService;
template<> PhysicsService* ServiceProvider::create<PhysicsService>() const;

void DataModel::initializeContents(bool start) {
    workspace->setParent(this);
    guiRoot->setParent(this);
    guiHooks->setParent(this);
    localBackpack = shared_from(ServiceProvider::create<LocalBackpack>());
    starterPackService = shared_from(ServiceProvider::create<StarterPackService>());
    runService = shared_from(ServiceProvider::create<RunService>());
    ServiceProvider::create<Soundscape::SoundService>();
    workspace->setNullMouseCommand();
    workspace->setVerbParent(this);
    if (start) runService->start();
    Notifier<RunService, RunTransition>::connect(runService, this);
    ServiceProvider::create<JointsService>();
    ServiceProvider::create<PhysicsService>();
}
}

template class boost::shared_ptr<RBX::LocalBackpack>;
template class std::_Vector_const_iterator<RBX::Listener<RBX::RunService,RBX::RunTransition> *,std::allocator<RBX::Listener<RBX::RunService,RBX::RunTransition> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::RunService,RBX::RunTransition> *,std::allocator<RBX::Listener<RBX::RunService,RBX::RunTransition> *> >;

double RBX::DataModel::getGameTime() const { return runService->gameTime(); }
double RBX::DataModel::getFrameRate() const { return runService->frameRate(); }
