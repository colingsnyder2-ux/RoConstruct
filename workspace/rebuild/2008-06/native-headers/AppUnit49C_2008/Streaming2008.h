#pragma once
// >>> native-status (generated) -- do not edit >>>
// Streaming2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 6c361d1c | roc native-status --write
// 2008-06 native RBX::Network BitStream streaming free functions (Network/Streaming.cpp unit 004a5a30..004a7fff of
// the application range 0049c000..004a8000; inactive). Shape after the donor tools/rbxgs/Client/Network/Streaming.h
// (read-only, not on the native include path); every signature below is read from the 2008-06 binary (evidence
// names and the argument/return shapes of the bodies cited per declaration). No layout: these are free functions on
// RakNet::BitStream (RakNet 3.x BitStream.h: numberOfBitsUsed +0x0, readOffset +0x8, data +0xc, as read by the
// inline Read<bool> 004a5050).
//   2008 differs from the donor: every operator>> checks the read and throws std::runtime_error
//   ("BitStream >> int failed" etc., 004a5b30..004a64e0); operator<<(const std::string&) rejects strings longer
//   than 200000 (0x30d40, "BitStream string write: String too long", 004a6560) and operator>>(std::string&)
//   checks the decoded length the same way (004a6610).
#include <string>

namespace RakNet
{
	class BitStream;
}

namespace G3D
{
	class Vector3;
	class CoordinateFrame;
}

namespace RBX
{
	class BrickColor;

	namespace Reflection
	{
		class ConstProperty;
		class Property;
	}

	namespace Network
	{
		// Property streaming (callers: the Replicator property serialisation 004b6890 / 004b6ab0).
		template<typename T>
		void serialize(const Reflection::ConstProperty& property, RakNet::BitStream& bitStream);   // <std::string> 004a6d00, <BrickColor> 004a7570
		template<typename T>
		void deserialize(Reflection::Property& property, RakNet::BitStream& bitStream);           // <std::string> 004a6d60, <BrickColor> 004a75b0
		void serializeEnum(const Reflection::ConstProperty& property, RakNet::BitStream& bitStream); // 004a5a30
		void deserializeEnum(Reflection::Property& property, RakNet::BitStream& bitStream);       // 004a5a70

		RakNet::BitStream& operator<<(RakNet::BitStream& stream, bool value);                    // 004a5b10
		RakNet::BitStream& operator<<(RakNet::BitStream& stream, int value);                     // 004a61a0
		RakNet::BitStream& operator<<(RakNet::BitStream& stream, unsigned char value);           // 004a6350
		RakNet::BitStream& operator<<(RakNet::BitStream& stream, float value);                   // 004a6400
		RakNet::BitStream& operator<<(RakNet::BitStream& stream, double value);                  // 004a64b0
		RakNet::BitStream& operator<<(RakNet::BitStream& stream, const std::string& value);      // 004a6560
		RakNet::BitStream& operator<<(RakNet::BitStream& stream, const G3D::Vector3& value);     // 004a69a0

		RakNet::BitStream& operator>>(RakNet::BitStream& stream, bool& value);                   // 004a5b30
		RakNet::BitStream& operator>>(RakNet::BitStream& stream, long& value);                   // 004a61d0
		RakNet::BitStream& operator>>(RakNet::BitStream& stream, int& value);                    // 004a6250
		RakNet::BitStream& operator>>(RakNet::BitStream& stream, unsigned int& value);           // 004a62d0
		RakNet::BitStream& operator>>(RakNet::BitStream& stream, unsigned char& value);          // 004a6380
		RakNet::BitStream& operator>>(RakNet::BitStream& stream, float& value);                  // 004a6430
		RakNet::BitStream& operator>>(RakNet::BitStream& stream, double& value);                 // 004a64e0
		RakNet::BitStream& operator>>(RakNet::BitStream& stream, std::string& value);            // 004a6610
		RakNet::BitStream& operator>>(RakNet::BitStream& stream, G3D::Vector3& value);           // 004a6cd0
		RakNet::BitStream& operator>>(RakNet::BitStream& stream, BrickColor& value);             // 004a7000

		bool brickEq(float a, float b);                                                          // 004a5bc0
		// isBrickLocation 004a5c00 is static in the unit (v is passed in esi): not declared here.
		void writeBrickVector(RakNet::BitStream& stream, const G3D::Vector3& value);             // 004a6700
		void readBrickVector(RakNet::BitStream& stream, G3D::Vector3& value);                    // 004a67c0
		void rationalize(G3D::CoordinateFrame& value);                                           // 004a6a00
		RakNet::BitStream& operator<<(RakNet::BitStream& stream, const G3D::CoordinateFrame& value); // 004a6ab0
		RakNet::BitStream& operator>>(RakNet::BitStream& stream, G3D::CoordinateFrame& value);   // 004a6b80
	}
}
