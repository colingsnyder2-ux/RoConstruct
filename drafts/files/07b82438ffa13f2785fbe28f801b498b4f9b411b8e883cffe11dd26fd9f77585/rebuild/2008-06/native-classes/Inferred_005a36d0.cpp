// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 005a36d0 RBX::append (v8datamodel/Workspace.cpp helper): registry decorated name
// ?append@RBX@@YAXABV?$shared_ptr@VInstance@RBX@@@boost@@PAV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@Z;
// donor Workspace.cpp (rbxgs line 434 / openrbx line 639) declares it 'static void append(item, values)'. Linkage is
// left external here because this unit has no caller to keep a static body alive; the target is a 15-byte
// forwarder to vector::push_back 00420110. Formerly the placeholder sub_005a36d0.
#include "util/Name.h"
#include "v8datamodel/Workspace.h"

namespace RBX {

// 005a36d0
void append(const boost::shared_ptr<Instance>& item, std::vector<boost::shared_ptr<Instance> >* values)
{
	values->push_back(item);
}

}
