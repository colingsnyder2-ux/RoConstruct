// from server: 100% by EspClaude
// from server: 97% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_d698c7ebbe6fca8a.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <boost/bind.hpp>
#include <G3D/Array.h>
#include <G3D/Vector4.h>
namespace RBX {
struct Settings {
	G3D::Array<G3D::Vector4> values;
	bool first;
	bool second;
};
class TargetBase0 { public: virtual ~TargetBase0(); };
class TargetBase1 { public: virtual ~TargetBase1(); };
class Target : public TargetBase0, public TargetBase1 {
public:
	void method(float elapsed, Settings settings);
};
}
template boost::_bi::bind_t<void, boost::_mfi::mf2<void, RBX::Target, float, RBX::Settings>,
	boost::_bi::list_av_3<RBX::Target*, boost::arg<1>, RBX::Settings>::type>
	boost::bind<void, RBX::Target, float, RBX::Settings, RBX::Target*, boost::arg<1>, RBX::Settings>(
		void (RBX::Target::*)(float, RBX::Settings), RBX::Target*, boost::arg<1>, RBX::Settings);
