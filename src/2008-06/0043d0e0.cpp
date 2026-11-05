// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_3d33995c2323af12.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <string>
#pragma pack(push, 4)
#include <boost/bind.hpp>
#pragma pack(pop)

namespace RBX {
struct SoundItem {
    std::string name;
    int value;
};

class Base1 { public: virtual ~Base1(); int x; };
class Base2 { public: virtual ~Base2(); int y; };
class Listener : public Base1, public Base2 {
public:
    void onItem(int& a, int& b, SoundItem item);
};
}

typedef boost::reference_wrapper<int> IntRef;
template boost::_bi::bind_t<void, boost::_mfi::mf3<void, RBX::Listener, int&, int&, RBX::SoundItem>, boost::_bi::list_av_4<RBX::Listener*, IntRef, IntRef, RBX::SoundItem>::type>
boost::bind<void, RBX::Listener, int&, int&, RBX::SoundItem, RBX::Listener*, IntRef, IntRef, RBX::SoundItem>(void (RBX::Listener::*)(int&, int&, RBX::SoundItem), RBX::Listener*, IntRef, IntRef, RBX::SoundItem);
