#include "v8datamodel/Lighting2008.h"
#include <boost/date_time/posix_time/time_formatters.hpp>
namespace RBX {
std::string Lighting::getTimeStr() const
	{
		return boost::posix_time::to_simple_string(timeOfDay);
	}
}
