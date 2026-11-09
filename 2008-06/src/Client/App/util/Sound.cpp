#include "util/Sound.h"
#include "util/Utilities.h"

namespace RBX
{
	template<>
	class StringConverter<Soundscape::SoundId>
	{
	public:
		static std::string convertToString(const Soundscape::SoundId& value)
		{
			return value.toString();
		}

		// TODO: does not match
		static bool convertToValue(const std::string& text, Soundscape::SoundId& value)
		{
			value = Soundscape::SoundId(text);
			return true;
		}
	};
}
