// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// 00657c60: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "boost/algorithm/string/detail/classification.hpp"
#include "util/Name.h"

namespace boost {
namespace algorithm {
namespace detail {

template<typename ForwardIteratorT, typename PredicateT>
ForwardIteratorT trim_begin(ForwardIteratorT InBegin, ForwardIteratorT InEnd, PredicateT IsSpace)
{
	ForwardIteratorT It = InBegin;
	for (; It != InEnd; ++It)
	{
		if (!IsSpace(*It))
			return It;
	}
	return It;
}

template std::string::iterator trim_begin<std::string::iterator, is_classifiedF>(std::string::iterator, std::string::iterator, is_classifiedF);

}
}
}
