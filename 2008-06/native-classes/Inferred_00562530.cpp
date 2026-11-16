// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: RBX::ContentProvider::sub_00562530 (placeholder name for 00562530 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/NativeContentProvider.h"

void RBX::ContentProvider::sub_00562530(const ContentId& id, boost::function<void(RequestResult, std::istream&)> callback)
{
	CachedContent* content = loadContent(id, 1, &callback);
	if (content)
	{
		if (content->data)
		{
			callback((RequestResult)1, static_cast<std::istream&>(std::istringstream(*content->data, std::ios_base::in)));
		}
		else
		{
			callback((RequestResult)1, static_cast<std::istream&>(std::ifstream(content->filename->c_str(), std::ios_base::in | std::ios_base::binary, _SH_DENYNO)));
		}
	}
}
