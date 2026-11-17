// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 004992e0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "Network/Players.h"

class XmlElement;

typedef boost::_bi::bind_t<void, void (__cdecl*)(const RBX::Network::AbuseReport::Message&, XmlElement*),
	boost::_bi::list2<boost::arg<1>, boost::_bi::value<XmlElement*> > > AbuseVisitFn;

typedef std::list<RBX::Network::AbuseReport::Message, std::allocator<RBX::Network::AbuseReport::Message> > AbuseMsgList;

template AbuseVisitFn std::for_each<AbuseMsgList::_Iterator<1>, AbuseVisitFn>(
	AbuseMsgList::_Iterator<1> first,
	AbuseMsgList::_Iterator<1> last,
	AbuseVisitFn f);
