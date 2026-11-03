// from server: 100% by EspClaude
// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-lib: rbxgs-dll roc_dynamic_6bac3cea7322b2a0.cpp

// Candidate translation unit (score above; library headers required).
#define private public
#include "Network/Player.h"
#undef private
boost::shared_ptr<RBX::Network::Player> cast_player(boost::shared_ptr<RBX::Instance> const& p) { return boost::dynamic_pointer_cast<RBX::Network::Player>(p); }
