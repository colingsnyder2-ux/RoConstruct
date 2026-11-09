// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.40.0 roc_espclaude_ae4d8787be273a7e.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
namespace RBX { class Instance; class Player; }
struct Pair2 {
    boost::weak_ptr<RBX::Instance> a;
    boost::shared_ptr<RBX::Player> b;
    ~Pair2();
};
Pair2::~Pair2() {}
