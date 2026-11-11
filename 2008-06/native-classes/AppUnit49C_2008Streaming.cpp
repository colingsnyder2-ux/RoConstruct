// 2008-06 native RBX::Network streaming rows of the Network/Streaming.cpp unit inside the application range
// 0049c000..004a8000 (inactive). Declarations: native-headers/AppUnit49C_2008/Streaming2008.h. RakNet::BitStream and
// StringCompressor are the RakNet 3.x library headers (tools/rbxgs/Client/Network/raknet30/Source, read-only).
// Bodies are in address order of the original. Verified by tests/record_native_app_unit49c_2008.py.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "AppUnit49C_2008/Streaming2008.h"
#include <BitStream.h>
#include <StringCompressor.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/vectorMath.h>
#include "util/Math.h"
#include "util/Quaternion.h"
#include "v8datamodel/BrickColor.h"
#include "reflection/property.h"
#include <typeinfo>
#include <stdexcept>

namespace RBX
{
	namespace Network
	{
		void serializeEnum(const Reflection::ConstProperty& property, RakNet::BitStream& bitStream) // 004a5a30
		{
			const Reflection::EnumPropertyDescriptor& prop = static_cast<const Reflection::EnumPropertyDescriptor&>(property.getDescriptor());
			int value = prop.getIndexValue(property.getInstance());
			bitStream.WriteBits((unsigned char*)&value, (int)prop.enumDescriptor.getEnumCountMSB() + 1);
		}

		void deserializeEnum(Reflection::Property& property, RakNet::BitStream& bitStream)       // 004a5a70
		{
			const Reflection::EnumPropertyDescriptor& prop = static_cast<const Reflection::EnumPropertyDescriptor&>(property.getDescriptor());
			int value = 0;
			if (!bitStream.ReadBits((unsigned char*)&value, (int)prop.enumDescriptor.getEnumCountMSB() + 1))
				throw std::runtime_error("deserializeEnum failed");
			// 004a5ae8: the setter is skipped for a null instance
			if (property.getInstance())
				prop.setIndexValue(property.getInstance(), value);
		}

		RakNet::BitStream& operator<<(RakNet::BitStream& stream, bool value)                    // 004a5b10
		{
			stream.Write(value);
			return stream;
		}

		RakNet::BitStream& operator>>(RakNet::BitStream& stream, bool& value)                   // 004a5b30
		{
			if (!stream.Read(value))
				throw std::runtime_error("BitStream >> bool failed");
			return stream;
		}

		bool brickEq(float a, float b)                                                          // 004a5bc0
		{
			return a == b || fabs(a - b) <= 0.0005f;
		}

		// Internal linkage: the original passes v in esi (writeBrickVector 004a6700 pushes only x, y, z), the custom
		// convention MSVC gives a static function of the unit.
		static bool isBrickLocation(const G3D::Vector3& v, short& x, unsigned short& y, short& z) // 004a5c00
		{
			if (v.x >= 512.0f)
				return false;

			if (v.x <= -512.0f)
				return false;

			if (v.z >= 512.0f)
				return false;

			if (v.z <= -512.0f)
				return false;

			if (v.y >= 204.8f)
				return false;

			if (v.y < 0.0f)
				return false;

			float dx = v.x * 2.0f;
			x = (short)dx;

			if ((float)x != dx)
				return false;

			float dz = v.z * 2.0f;
			z = (short)dz;

			if ((float)z != dz)
				return false;

			float dy = v.y * 10.0f;
			y = (unsigned short)dy;

			if (!brickEq((float)y, dy))
				return false;

			return true;
		}

		RakNet::BitStream& operator<<(RakNet::BitStream& stream, int value)                     // 004a61a0
		{
			stream.Write(value);
			return stream;
		}

		RakNet::BitStream& operator>>(RakNet::BitStream& stream, long& value)                   // 004a61d0
		{
			if (!stream.Read(value))
				throw std::runtime_error("BitStream >> long failed");
			return stream;
		}

		RakNet::BitStream& operator>>(RakNet::BitStream& stream, int& value)                    // 004a6250
		{
			if (!stream.Read(value))
				throw std::runtime_error("BitStream >> int failed");
			return stream;
		}

		RakNet::BitStream& operator>>(RakNet::BitStream& stream, unsigned int& value)           // 004a62d0
		{
			if (!stream.Read(value))
				throw std::runtime_error("BitStream >> size_t failed");
			return stream;
		}

		RakNet::BitStream& operator<<(RakNet::BitStream& stream, unsigned char value)           // 004a6350
		{
			stream.Write(value);
			return stream;
		}

		RakNet::BitStream& operator>>(RakNet::BitStream& stream, unsigned char& value)          // 004a6380
		{
			if (!stream.Read(value))
				throw std::runtime_error("BitStream >> unsigned char failed");
			return stream;
		}

		RakNet::BitStream& operator<<(RakNet::BitStream& stream, float value)                   // 004a6400
		{
			stream.Write(value);
			return stream;
		}

		RakNet::BitStream& operator>>(RakNet::BitStream& stream, float& value)                  // 004a6430
		{
			if (!stream.Read(value))
				throw std::runtime_error("BitStream >> float failed");
			return stream;
		}

		RakNet::BitStream& operator<<(RakNet::BitStream& stream, double value)                  // 004a64b0
		{
			stream.Write(value);
			return stream;
		}

		RakNet::BitStream& operator>>(RakNet::BitStream& stream, double& value)                 // 004a64e0
		{
			if (!stream.Read(value))
				throw std::runtime_error("BitStream >> double failed");
			return stream;
		}

		RakNet::BitStream& operator<<(RakNet::BitStream& stream, const std::string& value)      // 004a6560
		{
			if (value.size() > 200000)
				throw std::runtime_error("BitStream string write: String too long");
			stream.Write((unsigned)value.size());
			stringCompressor->EncodeString(value.c_str(), (int)value.size() + 1, &stream);
			return stream;
		}

		RakNet::BitStream& operator>>(RakNet::BitStream& stream, std::string& value)            // 004a6610
		{
			unsigned int strSize;
			if (!stream.Read(strSize))
				throw std::runtime_error("BitStream >> std::string: failed to read length");
			if (strSize > 200000)
				throw std::runtime_error("BitStream >> std::string: Bad string length");

			char* strBuf = (char*)_alloca(strSize + 1);
			stringCompressor->DecodeString(strBuf, strSize + 1, &stream);
			value = strBuf;
			return stream;
		}

		void writeBrickVector(RakNet::BitStream& stream, const G3D::Vector3& value)             // 004a6700
		{
			short x;
			unsigned short y;
			short z;

			if (isBrickLocation(value, x, y, z))
			{
				stream.Write(true);
				stream.WriteBits((unsigned char*)&x, 11);
				stream.WriteBits((unsigned char*)&y, 11);
				stream.WriteBits((unsigned char*)&z, 11);
			}
			else
			{
				stream.Write(false);
				stream.Write(value.x);
				stream.Write(value.y);
				stream.Write(value.z);
			}
		}

		void readBrickVector(RakNet::BitStream& stream, G3D::Vector3& value)                    // 004a67c0
		{
			bool compressed;
			stream >> compressed;
			if (compressed)
			{
				unsigned int x = 0, y = 0, z = 0;
				if (!stream.ReadBits((unsigned char*)&x, 11))
					throw std::runtime_error("readBrickVector x failed");
				if (!stream.ReadBits((unsigned char*)&y, 11))
					throw std::runtime_error("readBrickVector y failed");
				if (!stream.ReadBits((unsigned char*)&z, 11))
					throw std::runtime_error("readBrickVector z failed");
				if (x & 0x400)
					x |= 0xfffffc00;
				if (z & 0x400)
					z |= 0xfffffc00;
				value.x = (short)x * 0.5f;
				value.y = (unsigned short)y * 0.1f;
				value.z = (short)z * 0.5f;
			}
			else
			{
				stream >> value.x;
				stream >> value.y;
				stream >> value.z;
			}
		}

		RakNet::BitStream& operator<<(RakNet::BitStream& stream, const G3D::Vector3& value)     // 004a69a0
		{
			stream.Write(value.x);
			stream.Write(value.y);
			stream.Write(value.z);
			return stream;
		}

		void rationalize(G3D::CoordinateFrame& value)                                           // 004a6a00
		{
			if (!value.translation.isFinite())
			{
				value.translation = G3D::Vector3(0.0f, -1e+6f, 0.0f);
			}
			else
			{
				// G3D::clamp(v, low, high) is v.clamp(low, high): the first argument is the vector clamped (004a6a92 calls
				// Vector3::clamp 004a6100 on the (-1e6) temporary).
				value.translation = G3D::clamp(G3D::Vector3(-1e+6f, -1e+6f, -1e+6f), value.translation, G3D::Vector3(1e+6f, 1e+6f, 1e+6f));
			}
		}

		RakNet::BitStream& operator<<(RakNet::BitStream& stream, const G3D::CoordinateFrame& value) // 004a6ab0
		{
			G3D::CoordinateFrame cf = value;
			rationalize(cf);
			writeBrickVector(stream, cf.translation);
			if (Math::isAxisAligned(cf.rotation))
			{
				stream.Write(true);
				int orientId = Math::getOrientId(cf.rotation);
				stream.WriteBits((unsigned char*)&orientId, 6);
			}
			else
			{
				stream.Write(false);
				Quaternion q(cf.rotation);
				stream.WriteNormQuat(q.w, q.x, q.y, q.z);
			}
			return stream;
		}

		RakNet::BitStream& operator>>(RakNet::BitStream& stream, G3D::CoordinateFrame& value)   // 004a6b80
		{
			readBrickVector(stream, value.translation);
			bool axisAligned;
			stream >> axisAligned;
			if (axisAligned)
			{
				int orientId = 0;
				if (!stream.ReadBits((unsigned char*)&orientId, 6))
					throw std::runtime_error("BitStream >> CoordinateFrame orientId failed");
				Math::idToMatrix3(orientId, value.rotation);
			}
			else
			{
				Quaternion q(0.0f, 0.0f, 0.0f, 1.0f);
				if (!stream.ReadNormQuat(q.w, q.x, q.y, q.z))
					throw std::runtime_error("BitStream >> CoordinateFrame ReadNormQuat failed");
				q.toRotationMatrix(value.rotation);
				Math::orthonormalizeIfNecessary(value.rotation);
			}
			return stream;
		}

		RakNet::BitStream& operator>>(RakNet::BitStream& stream, G3D::Vector3& value)           // 004a6cd0
		{
			stream >> value.x;
			stream >> value.y;
			stream >> value.z;
			return stream;
		}

		template<>
		void serialize<std::string>(const Reflection::ConstProperty& property, RakNet::BitStream& bitStream) // 004a6d00
		{
			bitStream << property.getStringValue();
		}

		template<>
		void deserialize<std::string>(Reflection::Property& property, RakNet::BitStream& bitStream) // 004a6d60
		{
			std::string value;
			bitStream >> value;
			if (property.getInstance())
				property.getDescriptor().setStringValue(property.getInstance(), value);
		}

		RakNet::BitStream& operator>>(RakNet::BitStream& stream, BrickColor& value)             // 004a7000
		{
			int index = 0;
			if (!stream.ReadBits((unsigned char*)&index, 5))
				throw std::runtime_error("BitStream >> BrickColor failed");
			value = BrickColor::colorPalette()[index];
			return stream;
		}
	}

	namespace Reflection
	{
		// Declared in the read-only native reflection/property.h and defined in no native header (same definition as
		// native-classes/LuaBridge2008Instance.cpp): checked dynamic_cast of the descriptor to TypedPropertyDescriptor<T>
		// (type descriptor 0092ff20 in both bodies), std::bad_cast on failure, then the getset slot.
		template<typename T>
		T ConstProperty::getValue() const                                                       // 004a7460
		{
			const TypedPropertyDescriptor<T>* typed = dynamic_cast<const TypedPropertyDescriptor<T>*>(&getDescriptor());
			if (typed == NULL)
				throw std::bad_cast();
			return typed->getValue(getInstance());
		}

		template<typename T>
		void Property::setValue(const T& value)                                                 // 004a74c0
		{
			const TypedPropertyDescriptor<T>* typed = dynamic_cast<const TypedPropertyDescriptor<T>*>(&getDescriptor());
			if (typed == NULL)
				throw std::bad_cast();
			typed->setValue(getInstance(), value);
		}
	}

	namespace Network
	{
		template<>
		void serialize<BrickColor>(const Reflection::ConstProperty& property, RakNet::BitStream& bitStream) // 004a7570
		{
			BrickColor value = property.getValue<BrickColor>();
			int index = value.getClosestPaletteIndex();
			bitStream.WriteBits((unsigned char*)&index, 5);
		}

		template<>
		void deserialize<BrickColor>(Reflection::Property& property, RakNet::BitStream& bitStream) // 004a75b0
		{
			BrickColor value;
			bitStream >> value;
			if (property.getInstance())
				property.setValue(value);
		}
	}
}
