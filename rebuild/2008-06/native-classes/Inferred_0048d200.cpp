// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 0048d200: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "util/RunStateOwner.h"
#include "v8datamodel/DataModel.h"

typedef boost::shared_ptr<RBX::RunService> SA;
typedef boost::shared_ptr<RBX::DataModel> SB;
typedef void (*Fn)(SA, SB, int, int);

template boost::_bi::bind_t<void, Fn, boost::_bi::list_av_4<SA, SB, boost::arg<1>, boost::arg<2> >::type>
boost::bind<void, SA, SB, int, int, SA, SB, boost::arg<1>, boost::arg<2> >(Fn, SA, SB, boost::arg<1>, boost::arg<2>);
