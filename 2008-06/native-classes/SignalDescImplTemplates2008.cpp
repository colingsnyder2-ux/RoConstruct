// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/signal-any-direct
// 2008-06 native SignalDescImpl<N, S>::GenericSlotAdapter::operator() and ::fire instances (inactive) of the owner
// units listed per row below. The 1-argument operator() body is the inline one of the native reflection/signal.h; the
// 2-argument one is declared only, so it is defined here exactly like AppUnit554RunServiceTemplates.cpp /
// AppUnit628Explosion.cpp (vector<any>(2), args[0] = a, args[1] = b, wrapper->execute).
#include "reflection/signal.h"
#include "v8datamodel/BrickColor.h"
#include "v8tree/Instance.h"
#include <G3D/CoordinateFrame.h>
#include <G3D/Color3.h>
#include <string>
#include <vector>

namespace RBX
{
	namespace Reflection
	{
		template<class S>
		void SignalDescImpl<2, S>::GenericSlotAdapter::operator()(
			typename boost::function_traits<S>::arg1_type a, typename boost::function_traits<S>::arg2_type b)
		{
			std::vector<boost::any> args(2);
			args[0] = a;
			args[1] = b;
			wrapper->execute(args);
		}
	}
}

using namespace RBX;
using namespace RBX::Reflection;
typedef boost::shared_ptr<Instance> InstancePtr;

#define ADAPTER1(T) template void SignalDescImpl<1, void(T)>::GenericSlotAdapter::operator()(T);
ADAPTER1(std::string)               // 0041b5a0
ADAPTER1(InstancePtr)               // 0049a770
ADAPTER1(double)                    // 00636430
ADAPTER1(G3D::Vector3)              // 006364f0
ADAPTER1(G3D::CoordinateFrame)      // 006365c0
ADAPTER1(G3D::Color3)               // 00636670
ADAPTER1(BrickColor)                // 00636740
template void SignalDescImpl<2, void(std::string, InstancePtr)>::GenericSlotAdapter::operator()(std::string, InstancePtr); // 00491090
template void SignalDescImpl<2, void(std::string, bool)>::GenericSlotAdapter::operator()(std::string, bool);               // 004b35e0
template void SignalDescImpl<2, void(std::string, int)>::fire(SignalSource*, std::string, int);                            // 004a0f00
