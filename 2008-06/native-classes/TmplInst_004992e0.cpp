// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 004992e0 ??$for_each@V?$_Iterator@$00@?$list@UMessage@AbuseReport@Network@RBX@@V?$allocator@UMessage@AbuseReport@Networ: explicit template instantiation (generic_templates.py, function form, byte-proved standalone)
#include <map>
#include <set>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <memory>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/any.hpp>
#include "Network/Players.h"
#include "v8xml/XmlElement.h"
#include "util/Object.h"

template boost::_bi::bind_t<void,void (__cdecl*)(RBX::Network::AbuseReport::Message const &,XmlElement *),boost::_bi::list2<boost::arg<1>,boost::_bi::value<XmlElement *> > > std::for_each<std::list<RBX::Network::AbuseReport::Message,std::allocator<RBX::Network::AbuseReport::Message> >::_Iterator<1>,boost::_bi::bind_t<void,void (__cdecl*)(RBX::Network::AbuseReport::Message const &,XmlElement *),boost::_bi::list2<boost::arg<1>,boost::_bi::value<XmlElement *> > > >(std::list<RBX::Network::AbuseReport::Message,std::allocator<RBX::Network::AbuseReport::Message> >::_Iterator<1>,std::list<RBX::Network::AbuseReport::Message,std::allocator<RBX::Network::AbuseReport::Message> >::_Iterator<1>,boost::_bi::bind_t<void,void (__cdecl*)(RBX::Network::AbuseReport::Message const &,XmlElement *),boost::_bi::list2<boost::arg<1>,boost::_bi::value<XmlElement *> > >);
