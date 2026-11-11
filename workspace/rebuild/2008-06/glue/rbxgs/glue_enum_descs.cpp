// Rebuild glue: reflection enum descriptors rbxgs uses but never defines, in the style of rbxgs
// v8datamodel/Camera.cpp. Names are the 2008-06 Roblox.exe strings next to each enum's type name
// (e.g. "...|Laser|Rocket|Slingshot|Hammer|Grab|GameTool|BinType"); names /GF pooled elsewhere
// ("Script", "Clone", "None", "Torso", "Brick", "Top", "Left", "Ball", "Block", "Cylinder") are the
// remaining members. Behavioural reconstruction, not byte-verified.
#include "reflection/enumconverter.h"
#include "util/NormalId.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/custommesh.h"
#include "v8world/Controller.h"
#include "AppDraw/Part.h"

namespace RBX
{
}
