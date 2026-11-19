// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native Reflection::BoundFuncDesc<Class, Function, N> explicit instances (inactive): execute() and the
// private call<ReturnType>() members of the descriptors whose original bodies sit in the owner units
// (Server 004a49a0, Instance 0055a300, Lighting 005e15d0/005e1700, PartInstance 0059d050, ScriptContext 005ada90,
// ones of the native reflection/reflection.h (0..2 arguments); explicit class instantiation emits execute + call.
#include "Network/Server2008.h"
#include "v8datamodel/Lighting2008.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/BodyMovers.h"
#include "v8datamodel/DataModel.h"
#include "script/ScriptContext.h"

using namespace RBX;
using namespace RBX::Reflection;

template class BoundFuncDesc<Network::Server, int(void), 0>;
template class BoundFuncDesc<Instance, bool(boost::shared_ptr<Instance>), 1>;
template class BoundFuncDesc<Lighting, float(void), 0>;
template class BoundFuncDesc<Lighting, G3D::Vector3(void), 0>;
template class BoundFuncDesc<PartInstance, float(void), 0>;
template class BoundFuncDesc<ScriptContext, void(double), 1>;
template class BoundFuncDesc<Workspace, void(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >), 1>;
template class BoundFuncDesc<BodyPosition, G3D::Vector3(void), 0>;
template class BoundFuncDesc<BodyVelocity, G3D::Vector3(void), 0>;
