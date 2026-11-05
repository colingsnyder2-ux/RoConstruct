// Rebuild glue: small members rbxgs declares but never defines. Behavioural reconstructions, not
// byte-verified; each follows the neighbouring rbxgs code it names.
#include "v8datamodel/Feature.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Team.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Value.h"
#include "v8world/RotateJoint.h"
#include "v8world/World.h"
#include "script/Script.h"
#include "gui/GuiDraw.h"
#include "util/Sound.h"
#include "Streaming.h"
#include "BitStream.h"

namespace RBX
{
	Hole::~Hole() {}
	MotorFeature::~MotorFeature() {}
	LocalScript::~LocalScript() {}
	Team::~Team() {}

	// as the other RotateJoint constructor: a two-breaking multi joint with no connector yet
	RotateJoint::RotateJoint()
		: MultiJoint(2), rotateConnector(NULL)
	{
	}

	// features sit on a part's face
	bool Feature::askSetParent(const Instance* instance) const
	{
		return dynamic_cast<const PartInstance*>(instance) != NULL;
	}

	bool Feature::shouldRender3dAdorn() const
	{
		return true;
	}

	// a feature's frame points out of its face; a hole's points into it
	Feature::InOutZ Feature::getCoordOrientation() const
	{
		return Z_OUT;
	}

	Feature::InOutZ Hole::getCoordOrientation() const
	{
		return Z_IN;
	}

	GuiDrawImage::GuiDrawImage()
		: size(0.0f, 0.0f)
	{
	}

	WorkspaceStatsItem::WorkspaceStatsItem(const Workspace* workspace, const World* world)
	{
		setName("Workspace");
	}

	namespace Network
	{
		// rbxgs Streaming.cpp defines operator<< for long& where the header declares this reader
		RakNet::BitStream& operator>>(RakNet::BitStream& stream, long& value)
		{
			stream.Read(value);
			return stream;
		}
	}

	// declare the reflected classes so the factory can create them by name
	void registerSound()
	{
		Soundscape::SoundChannel::classDescriptor();
		Soundscape::SoundService::classDescriptor();
	}

	void registerValueClasses()
	{
		IntValue::classDescriptor();
		BoolValue::classDescriptor();
		FloatValue::classDescriptor();
		Color3Value::classDescriptor();
		Vector3Value::classDescriptor();
		BrickColorValue::classDescriptor();
		StringValue::classDescriptor();
		CFrameValue::classDescriptor();
		ObjectValue::classDescriptor();
	}
}
