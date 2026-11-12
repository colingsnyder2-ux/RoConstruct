// from server: 100% by EspClaude
// from server: 57% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS /EHsc /MD
// roc-lib: openrbx-client roc_claude_a06d177dd027e2de.cpp

// Candidate translation unit (score above; library headers required).
// Codegen analog for 2007-08 00495780 (cdecl, no return value):
//   arg1 [esp+4] = object pointer, args 2-3 = a boost::shared_ptr passed by value;
//   copies the shared_ptr and calls thiscall 00494c40 on arg1 with it, then the
//   by-value parameter is released (sp_counted_base dispose slot +4, destroy +8).
#include <boost/shared_ptr.hpp>

class RocPayload;
class RocTarget
{
public:
	void receive(boost::shared_ptr<RocPayload> item);	// 00494c40
};

void rocForward(RocTarget *target, boost::shared_ptr<RocPayload> item)
{
	target->receive(item);
}
