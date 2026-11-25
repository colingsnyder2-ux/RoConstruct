// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_resume_a182d654d1ce7cc0.cpp

// Candidate translation unit (score above; library headers required).
#define NDEBUG
#include <string>
#include <boost/signals/detail/signal_base.hpp>
#include <boost/signals/detail/named_slot_map.hpp>
#include <boost/signals/connection.hpp>
#include "libs/signals/src/signal_base.cpp"
#include "libs/signals/src/named_slot_map.cpp"
#include "libs/signals/src/connection.cpp"
#include "libs/signals/src/slot.cpp"
#include "libs/signals/src/trackable.cpp"
