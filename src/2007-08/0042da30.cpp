// from server: 76% by EspClaude
// from server: 60% by Intel
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: boost-1.34.1 roc_claude_3a5e154fb27be6f5.cpp

// Candidate translation unit (score above; library headers required).
// Element type proven by 0x42d700 (_Construct<RBX::Reflection::Value>) and 0x42d970
// (allocator<Value>::destroy): {const Type* _type; boost::any value;}, 8 bytes.
// Layout copied from rbxgs include/reflection/type.h.
#include <boost/any.hpp>
#include <vector>

namespace RBX
{
	namespace Reflection
	{
		class Type;

		class Value
		{
		private:
			const Type* _type;
			boost::any value;

		public:
			Value();
		};
	}
}

template class std::vector<RBX::Reflection::Value>;
