// from server: 93% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS /EHsc /MD
// roc-lib: rbxgs-net roc_espeon_aug2007_network_streaming_native_module_61194d1df130fbee.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8world/Edge.h", "../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp")
#pragma include_alias(<v8world/Edge.h>, <../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp>)
#pragma include_alias("v8world/Contact.h", "../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp")
#pragma include_alias(<v8world/Contact.h>, <../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp>)
#define _MT 1
#define _DLL 1
#pragma include_alias("v8kernel/KernelIndex.h", "../roc_espeon_aug2007_kernelindex_header_d7778b4d74bcf4c0.cpp")
#pragma include_alias("v8kernel/Body.h", "../roc_espeon_aug2007_body_header_b251c002665e01af.cpp")
#pragma include_alias("util/Extents.h", "../roc_espeon_aug2007_extents_inline_58e475d56d206314.cpp")
#pragma include_alias("reflection/object.h", "../roc_espeon_aug2007_describedbase_e64c736f24da029d.cpp")
#pragma include_alias("util/Debug.h", "../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp")
#pragma include_alias(<util/Debug.h>, <../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp>)
#pragma include_alias("util/Events.h", "../roc_espeon_aug2007_datamodel_header_e4d5a36bea2e4f16.cpp")
#pragma include_alias("reflection/reflection.h", "../roc_espeon_aug2007_described_arg_header_14221fd67bb3ca43.cpp")
#pragma include_alias("v8tree/Instance.h", "../roc_espeon_aug2007_instance_header_47f25dc9e4368119.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "../roc_espeon_aug2007_part_flags_header_a6acc69782cd7c29.cpp")
#pragma include_alias("v8world/Primitive.h", "../roc_espeon_aug2007_primitive_trivial_header_ac300ff64c6fc5e6.cpp")
#pragma include_alias("v8datamodel/DataModel.h", "../roc_espeon_aug2007_datamodel_mutex_header_321a3c67de644a82.cpp")
#pragma include_alias("v8tree/Verb.h", "../roc_espeon_aug2007_datamodel_header_c06d28d1a6b724f6.cpp")
#pragma include_alias("util/Evaluator.h", "../roc_espeon_aug2007_datamodel_header_4ba4cf67c400aa66.cpp")
#pragma include_alias(<boost/signals/signal_template.hpp>, <../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp>)
#pragma include_alias("boost/signals/signal_template.hpp", "../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp")
#include "../App/roc_espeon_boost133_header_d432d72f8740aec3.cpp"
#include "../App/roc_espeon_boost133_header_d9eb4711b7fc841c.cpp"
#include "../App/roc_espeon_boost133_signals_header_be197e98651271fa.cpp"

#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp>)
#pragma include_alias("v8world/IPipelined.h", "../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp")
#pragma include_alias(<v8world/IPipelined.h>, <../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp>)
#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp>)
#pragma include_alias("util/IRenderable.h", "../roc_espeon_aug2007_bucket_header_1deff476fbc5a7ac.cpp")
#pragma include_alias(<util/IRenderable.h>, <../roc_espeon_aug2007_bucket_header_1deff476fbc5a7ac.cpp>)
#pragma include_alias("v8datamodel/JointInstance.h", "../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp")
#pragma include_alias(<v8datamodel/JointInstance.h>, <../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp>)
#pragma include_alias("v8world/IMoving.h", "../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp")
#pragma include_alias(<v8world/IMoving.h>, <../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp>)
#pragma include_alias("v8kernel/IStage.h", "../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp")
#pragma include_alias(<v8kernel/IStage.h>, <../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp>)
#pragma include_alias("reflection/function.h", "../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp")
#pragma include_alias(<reflection/function.h>, <../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp>)
#pragma include_alias("reflection/member.h", "../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp")
#pragma include_alias(<reflection/member.h>, <../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp>)
#pragma include_alias("reflection/property.h", "../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp")
#pragma include_alias(<reflection/property.h>, <../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp>)
#pragma include_alias("reflection/signal.h", "../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp")
#pragma include_alias(<reflection/signal.h>, <../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp>)
#pragma include_alias("script/Script.h", "../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp")
#pragma include_alias(<script/Script.h>, <../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp>)
#pragma include_alias("util/ICameraSubject.h", "../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp")
#pragma include_alias(<util/ICameraSubject.h>, <../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp>)
#pragma include_alias("util/IControllable.h", "../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp")
#pragma include_alias(<util/IControllable.h>, <../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp>)
#pragma include_alias("util/ILocation.h", "../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp")
#pragma include_alias(<util/ILocation.h>, <../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp>)
#pragma include_alias("v8datamodel/ICameraOwner.h", "../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp")
#pragma include_alias(<v8datamodel/ICameraOwner.h>, <../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp>)
#pragma include_alias("v8datamodel/ICharacterSubject.h", "../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp")
#pragma include_alias(<v8datamodel/ICharacterSubject.h>, <../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp>)
#pragma include_alias("v8datamodel/IPrimaryPart.h", "../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp")
#pragma include_alias(<v8datamodel/IPrimaryPart.h>, <../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp>)
#pragma include_alias("v8datamodel/PVInstance.h", "../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp")
#pragma include_alias(<v8datamodel/PVInstance.h>, <../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp>)
#pragma include_alias("v8tree/Service.h", "../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp")
#pragma include_alias(<v8tree/Service.h>, <../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp>)
#pragma include_alias("util/UIEvent.h", "../roc_espeon_aug2007_uievent_viewport_header_04331f71cbc5bc08.cpp")
#pragma include_alias(<util/UIEvent.h>, <../roc_espeon_aug2007_uievent_viewport_header_04331f71cbc5bc08.cpp>)
#pragma include_alias("v8datamodel/Workspace.h", "../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp")
#pragma include_alias(<v8datamodel/Workspace.h>, <../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp>)
#pragma include_alias("v8datamodel/ICharacterSubject.h", "../roc_espeon_aug2007_character_state_f342eee04d017582.cpp")
#pragma include_alias(<v8datamodel/ICharacterSubject.h>, <../roc_espeon_aug2007_character_state_f342eee04d017582.cpp>)
#pragma include_alias("humanoid/Humanoid.h", "../roc_espeon_aug2007_humanoid_state_f78ef0aa0660622a.cpp")
#pragma include_alias(<humanoid/Humanoid.h>, <../roc_espeon_aug2007_humanoid_state_f78ef0aa0660622a.cpp>)
#pragma include_alias("humanoid/Running.h", "../roc_espeon_aug2007_running_balance_hook_875f0bb95aec50f5.cpp")
#pragma include_alias(<humanoid/Running.h>, <../roc_espeon_aug2007_running_balance_hook_875f0bb95aec50f5.cpp>)
#pragma include_alias("humanoid/Balancing.h", "../roc_espeon_aug2007_balancing_balance_hook_37ced1d1de755090.cpp")
#pragma include_alias(<humanoid/Balancing.h>, <../roc_espeon_aug2007_balancing_balance_hook_37ced1d1de755090.cpp>)
#pragma include_alias("humanoid/FallingDown.h", "../roc_espeon_aug2007_fallingdown_state_7499778b68c8dff0.cpp")
#pragma include_alias(<humanoid/FallingDown.h>, <../roc_espeon_aug2007_fallingdown_state_7499778b68c8dff0.cpp>)
#pragma include_alias("humanoid/Flying.h", "../roc_espeon_aug2007_flying_balance_hook_a9eee8e762225c01.cpp")
#pragma include_alias(<humanoid/Flying.h>, <../roc_espeon_aug2007_flying_balance_hook_a9eee8e762225c01.cpp>)
#pragma include_alias("humanoid/Freefall.h", "../roc_espeon_aug2007_freefall_state_671ebe3411c8030d.cpp")
#pragma include_alias(<humanoid/Freefall.h>, <../roc_espeon_aug2007_freefall_state_671ebe3411c8030d.cpp>)
#pragma include_alias("humanoid/GettingUp.h", "../roc_espeon_aug2007_gettingup_balance_hook_972ad7ec2ed27c84.cpp")
#pragma include_alias(<humanoid/GettingUp.h>, <../roc_espeon_aug2007_gettingup_balance_hook_972ad7ec2ed27c84.cpp>)
#pragma include_alias("humanoid/Jumping.h", "../roc_espeon_aug2007_jumping_state_9af9b1e45a772018.cpp")
#pragma include_alias(<humanoid/Jumping.h>, <../roc_espeon_aug2007_jumping_state_9af9b1e45a772018.cpp>)
#pragma include_alias("humanoid/Seated.h", "../roc_espeon_aug2007_seated_state_df5e271a3b8e21cd.cpp")
#pragma include_alias(<humanoid/Seated.h>, <../roc_espeon_aug2007_seated_state_df5e271a3b8e21cd.cpp>)
#pragma include_alias("RbxGraphics/Adorn.h", "../roc_espeon_aug2007_adorn_header_6887d8bb2eb92360.cpp")
#pragma include_alias(<RbxGraphics/Adorn.h>, <../roc_espeon_aug2007_adorn_header_6887d8bb2eb92360.cpp>)
#pragma include_alias("AppDraw/AdornG3D.h", "../roc_espeon_aug2007_adorng3d_header_62d495574bf52995.cpp")
#pragma include_alias(<AppDraw/AdornG3D.h>, <../roc_espeon_aug2007_adorng3d_header_62d495574bf52995.cpp>)
#pragma include_alias("v8kernel/Kernel.h", "../roc_espeon_aug2007_kernel_inline_header_359388a626d15479.cpp")
#pragma include_alias(<v8kernel/Kernel.h>, <../roc_espeon_aug2007_kernel_inline_header_359388a626d15479.cpp>)
#pragma include_alias("v8kernel/Point.h", "../roc_espeon_aug2007_point_inline_header_aac7baa3a10948cb.cpp")
#pragma include_alias(<v8kernel/Point.h>, <../roc_espeon_aug2007_point_inline_header_aac7baa3a10948cb.cpp>)
#pragma include_alias("Streaming.h","roc_espeon_aug2007_idserializer_historical_header_f589f1aef1ff8179.cpp")
#pragma include_alias("Replicator.h","roc_espeon_aug2007_replicator_idserializer_header_723f383f82833206.cpp")
#pragma include_alias("IdManager.h","roc_espeon_aug2007_idmanager_historical_header_bf92b6db84c275bf.cpp")
#include <BitStream.h>
#include <StringCompressor.h>
#include "Streaming.h"
#include "IdManager.h"
#include "v8tree/Service.h"
#include <G3D/vectorMath.h>
#include <algorithm>

namespace RBX
{
	namespace Network
	{
		RakNet::BitStream& operator<<(RakNet::BitStream& stream, bool value)
		{
			stream.Write(value);
			return stream;
		}

		RakNet::BitStream& operator<<(RakNet::BitStream& stream, int value)
		{
			stream.Write(value);
			return stream;
		}

		RakNet::BitStream& operator<<(RakNet::BitStream& stream, long value)
		{
			stream.Write(value);
			return stream;
		}

		RakNet::BitStream& operator<<(RakNet::BitStream& stream, unsigned int value)
		{
			stream.Write(value);
			return stream;
		}

		RakNet::BitStream& operator<<(RakNet::BitStream& stream, unsigned char value)
		{
			stream.Write(value);
			return stream;
		}

		RakNet::BitStream& operator<<(RakNet::BitStream& stream, float value)
		{
			stream.Write(value);
			return stream;
		}

		RakNet::BitStream& operator<<(RakNet::BitStream& stream, const std::string& value)
		{
			stream.Write((unsigned)value.size());
			stringCompressor->EncodeString(value.c_str(), (int)value.size() + 1, &stream);
			return stream;
		}

		RakNet::BitStream& operator<<(RakNet::BitStream& stream, const G3D::Vector3& value)
		{
			stream << value.x;
			stream << value.y;
			stream << value.z;
			return stream;
		}

		RakNet::BitStream& operator<<(RakNet::BitStream& stream, const G3D::Color3& value)
		{
			stream << value.r;
			stream << value.g;
			stream << value.b;
			return stream;
		}

		RakNet::BitStream& operator>>(RakNet::BitStream& stream, bool& value)
		{
			stream.Read(value);
			return stream;
		}

		RakNet::BitStream& operator>>(RakNet::BitStream& stream, int& value)
		{
			stream.Read(value);
			return stream;
		}

		RakNet::BitStream& operator<<(RakNet::BitStream& stream, long& value)
		{
			stream.Write(value);
			return stream;
		}

		RakNet::BitStream& operator>>(RakNet::BitStream& stream, unsigned int& value)
		{
			stream.Read(value);
			return stream;
		}


		RakNet::BitStream& operator>>(RakNet::BitStream& stream, unsigned char& value)
		{
			stream.Read(value);
			return stream;
		}

		RakNet::BitStream& operator>>(RakNet::BitStream& stream, float& value)
		{
			stream.Read(value);
			return stream;
		}

		RakNet::BitStream& operator>>(RakNet::BitStream& stream, std::string& value)
		{
			unsigned int strSize;
			stream >> strSize;

			char* strBuf = new char[strSize + 1];
			stringCompressor->DecodeString(strBuf, strSize + 1, &stream);
			value = strBuf;

			delete[] strBuf;
			return stream;
		}

		RakNet::BitStream& operator>>(RakNet::BitStream& stream, G3D::Vector3& value)
		{
			stream >> value.x;
			stream >> value.y;
			stream >> value.z;
			return stream;
		}

		RakNet::BitStream& operator>>(RakNet::BitStream& stream, G3D::Color3& value)
		{
			stream >> value.r;
			stream >> value.g;
			stream >> value.b;
			return stream;
		}

		template<typename T>
		RakNet::BitStream& operator>>(RakNet::BitStream& stream, T& value) // TODO: check match
		{
			return operator>>(stream, value);
		}

		bool brickEq(float a, float b)
		{
			return a == b || fabs(a - b) <= 0.0005f;
		}

		static bool isBrickLocation(const G3D::Vector3& v, short& x, unsigned short& y, short& z)
		{
			if (v.x >= 512.0f)
				return false;

			if (v.x <= -512.0f)
				return false;

			if (v.z >= 512.0f)
				return false;

			if (v.z <= -512.0f)
				return false;
			
			if (v.y >= 204.8)
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

		void writeBrickVector(RakNet::BitStream& stream, const G3D::Vector3& value)
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

		void readBrickVector(RakNet::BitStream& stream, G3D::Vector3& value)
		{
			bool isBrickLocation;
			stream.Read(isBrickLocation);

			if (isBrickLocation)
			{
				short x = 0;
				unsigned short y = 0;
				short z = 0;

				stream.ReadBits((unsigned char*)&x, 11);
				stream.ReadBits((unsigned char*)&y, 11);
				stream.ReadBits((unsigned char*)&z, 11);

				if (x & 0x400) // sign extend x and z
					x |= 0xfc00;

				if (z & 0x400)
					z |= 0xfc00;

				value.x = (float)(x * 0.5);
				value.y = (float)(y / 10.0);
				value.z = (float)(z * 0.5);
			}
			else
			{
				stream.Read(value.x);
				stream.Read(value.y);
				stream.Read(value.z);
			}
		}

		void rationalize(G3D::CoordinateFrame& value)
		{
			if (!value.translation.isFinite())
			{
				value.translation = G3D::Vector3(0.0f, -1e+6f, 0.0f);
			}
			else
			{
				value.translation = G3D::clamp(G3D::Vector3(-1e+6f, -1e+6f, -1e+6f), value.translation, G3D::Vector3(1e+6f, 1e+6f, 1e+6f));
			}
		}

		void deserializeEnum(Reflection::Property& property, RakNet::BitStream& bitStream)
		{
			const Reflection::EnumPropertyDescriptor& prop = static_cast<const Reflection::EnumPropertyDescriptor&>(property.getDescriptor());

			int value = 0;
			bitStream.ReadBits((unsigned char*)&value, (int)prop.enumDescriptor.getEnumCountMSB() + 1);

			RBXASSERT(value >= 0);
			RBXASSERT(value < (int)prop.enumDescriptor.getEnumCount());

			prop.setIndexValue(property.getInstance(), value);
		}

		void serializeEnum(const Reflection::ConstProperty& property, RakNet::BitStream& bitStream)
		{
			const Reflection::EnumPropertyDescriptor& prop = static_cast<const Reflection::EnumPropertyDescriptor&>(property.getDescriptor());

			int value = prop.getIndexValue(property.getInstance());

			RBXASSERT(value >= 0);
			RBXASSERT(value < (int)prop.enumDescriptor.getEnumCount());

			bitStream.WriteBits((unsigned char*)&value, (int)prop.enumDescriptor.getEnumCountMSB() + 1);
		}

		void StringReceiver::receive(RakNet::BitStream& stream, std::string& value)
		{
			unsigned char id;
			stream >> id;

			if (id == 0)
			{
				value.clear();
			}
			else if (id >> 7)
			{
				stream >> value;
				dictionary[id & 127] = value;
			}
			else
			{
				value = dictionary[id];
			}
		}

		void StringReceiver::receive(RakNet::BitStream& stream, const Name*& value)
		{
			std::string s;
			receive(stream, s);

			value = &Name::declare(s.c_str(), -1);
		}

		void StringReceiver::deserializeString(Reflection::Property& property, RakNet::BitStream& bitStream)
		{
			std::string value;
			receive(bitStream, value);
			
			Instance* instance = static_cast<Instance*>(property.getInstance());
			const Reflection::PropertyDescriptor& desc = property.getDescriptor();

			desc.setStringValue(instance, value);
		}

		void StringSender::serializeString(const Reflection::ConstProperty& property, RakNet::BitStream& bitStream)
		{
			const Instance* instance = static_cast<const Instance*>(property.getInstance());
			const Reflection::PropertyDescriptor& desc = property.getDescriptor();

			std::string value = desc.getStringValue(instance);
			send(bitStream, value);
		}

		void StringSender::send(RakNet::BitStream& stream, const std::string& value)
		{
			if (value == "")
			{
				stream << (unsigned char)0;
			}
			else
			{
				std::pair<std::map<std::string, unsigned char>::iterator, bool> pair = dictionary.insert(std::pair<const std::string, unsigned char>(value, 0));

				if (!pair.second)
				{
					stream << pair.first->second;
				}
				else
				{
					lastIndex = lastIndex % 127 + 1;
					dictionary.erase(strings[lastIndex]);
					pair.first->second = lastIndex;
					strings[lastIndex] = value;

					stream << (unsigned char)(lastIndex | 0x80);
					stream << value;
				}
			}
		}

		bool StringSender::trySend(RakNet::BitStream& stream, const std::string& value)
		{
			if (value == "")
			{
				stream << (unsigned char)0;
				return true;
			}

			std::map<std::string, unsigned char>::const_iterator iter = dictionary.find(value);

			if (iter == dictionary.end())
			{
				return false;
			}
			else
			{
				stream << iter->second;
				return true;
			}
		}

		
}}
