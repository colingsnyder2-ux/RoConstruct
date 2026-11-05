#define _CRT_SECURE_NO_DEPRECATE
#include "util/Utilities.h"
#include "util/ContentProvider.h"
#include "util/MeshId.h"
#include "util/TextureId.h"
#include <stdio.h>
#include <boost/lexical_cast.hpp>

namespace RBX
{
	template<>
	class StringConverter<bool>
	{
	public:
		static std::string convertToString(const bool& value)
		{
			return value ? "true" : "false";
		}

		static bool convertToValue(const std::string& text, bool& value)
		{
			if (text == "true" || text == "True" || text == "TRUE")
			{
				value = true;
				return true;
			}
			else if (text == "false" || text == "False" || text == "FALSE")
			{
				value = false;
				return true;
			}

			return false;
		}
	};

	template<>
	class StringConverter<int>
	{
	public:
		static std::string convertToString(const int& value)
		{
			char buffer[16];
			_snprintf(buffer, sizeof(buffer), "%d", value);
			return buffer;
		}

		static bool convertToValue(const std::string& text, int& value)
		{
			if (text.size() == 0)
				return false;

			try
			{
				value = boost::lexical_cast<int>(text);
				return true;
			}
			catch (boost::bad_lexical_cast&)
			{
				return false;
			}
		}
	};

	template<>
	class StringConverter<unsigned>
	{
	public:
		static std::string convertToString(const unsigned& value)
		{
			char buffer[16];
			_snprintf(buffer, sizeof(buffer), "%u", value);
			return buffer;
		}

		static bool convertToValue(const std::string& text, unsigned& value)
		{
			if (text.size() == 0)
				return false;

			try
			{
				value = boost::lexical_cast<unsigned>(text);
				return true;
			}
			catch (boost::bad_lexical_cast&)
			{
				return false;
			}
		}
	};

	template<>
	class StringConverter<double>
	{
	public:
		static std::string convertToString(const double& value)
		{
			if (value == std::numeric_limits<double>::infinity())
			{
				return "INF";
			}
			else if (value == -std::numeric_limits<double>::infinity())
			{
				return "-INF";
			}
			else if (!(value < 0.0 || value >= 0.0))
			{
				return "NAN";
			}
			else
			{
				char buffer[32];
				_snprintf(buffer, 32, "%.9g", value);
				return buffer;
			}
		}

		static bool convertToValue(const std::string& text, double& value)
		{
			if (text.size() == 0)
				return false;

			if (text == "INF")
			{
				value = std::numeric_limits<double>::infinity();
				return true;
			}
			else if (text == "-INF")
			{
				value = -std::numeric_limits<double>::infinity();
				return true;
			}
			else if (text == "NAN")
			{
				value = std::numeric_limits<double>::quiet_NaN();
				return true;
			}
			else
			{
				try
				{
					value = boost::lexical_cast<double>(text);
					return true;
				}
				catch (boost::bad_lexical_cast&)
				{
					return false;
				}
			}
		}
	};

	template<>
	class StringConverter<float>
	{
	public:
		static std::string convertToString(const float& value)
		{
			if (value == std::numeric_limits<float>::infinity())
			{
				return "INF";
			}
			else if (value == -std::numeric_limits<float>::infinity())
			{
				return "-INF";
			}
			else if (!(value < 0.0f || value >= 0.0f))
			{
				return "NAN";
			}
			else
			{
				char buffer[32];
				_snprintf(buffer, 32, "%.9g", value);
				return buffer;
			}
		}

		static bool convertToValue(const std::string& text, float& value)
		{
			if (text.size() == 0)
				return false;

			if (text == "INF")
			{
				value = std::numeric_limits<float>::infinity();
				return true;
			}
			else if (text == "-INF")
			{
				value = -std::numeric_limits<float>::infinity();
				return true;
			}
			else if (text == "NAN")
			{
				value = std::numeric_limits<float>::quiet_NaN();
				return true;
			}
			else
			{
				try
				{
					value = boost::lexical_cast<float>(text);
					return true;
				}
				catch (boost::bad_lexical_cast&)
				{
					return false;
				}
			}
		}
	};

	template<>
	class StringConverter<ContentId>
	{
	public:
		static std::string convertToString(const ContentId& value)
		{
			return value.toString();
		}

		// TODO: does not match
		static bool convertToValue(const std::string& text, ContentId& value)
		{
			value = ContentId(text);
			return true;
		}
	};

	template<>
	class StringConverter<MeshId>
	{
	public:
		static std::string convertToString(const MeshId& value)
		{
			return value.toString();
		}

		// TODO: does not match
		static bool convertToValue(const std::string& text, MeshId& value)
		{
			value = MeshId(text);
			return true;
		}
	};

	template<>
	class StringConverter<TextureId>
	{
	public:
		static std::string convertToString(const TextureId& value)
		{
			return value.toString();
		}

		// TODO: does not match
		static bool convertToValue(const std::string& text, TextureId& value)
		{
			value = TextureId(text);
			return true;
		}
	};
}
