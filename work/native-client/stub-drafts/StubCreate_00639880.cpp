// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 0x00639880 is Creatable<Instance>::create<StringValue>() (ctor 00638490 = Value<std::string,sStringValue>, malloc 0x14c).
// The identity registry names it create<DebrisService> because ICF folded shared_ptr ctors; DebrisService is 0x158
// (create 005c2e10) and its header is correct, so it is NOT edited.
#include "util/Object.h"
#include "v8datamodel/Value.h"
typedef char roc_size_StringValue[sizeof(RBX::StringValue) == 332 ? 1 : -1];   // the original passes malloc(0x14c)
template boost::shared_ptr<RBX::StringValue> RBX::Creatable<RBX::Instance>::create<RBX::StringValue>();
