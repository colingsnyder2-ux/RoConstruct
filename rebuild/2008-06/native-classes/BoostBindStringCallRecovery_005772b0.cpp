// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /I{headers}/../../../tools/rbxgs/Client/boost_1_34_1/src
// 005772b0 / 005772e0: boost::bind nullary call operators instantiated by DataModel.cpp
// (bound std::string(*)(std::string) and std::string(*)(std::string, std::string)).
#include <string>
#include <boost/bind.hpp>

template std::string boost::_bi::bind_t<
    std::string,
    std::string (__cdecl*)(std::string),
    boost::_bi::list1<boost::_bi::value<std::string> > >::operator()();

// INFERRED: 005772e0 calls list2<value<string>,value<string>>::operator() at 00576e50 (registry decorated name)
template std::string boost::_bi::bind_t<
    std::string,
    std::string (__cdecl*)(std::string, std::string),
    boost::_bi::list2<boost::_bi::value<std::string>, boost::_bi::value<std::string> > >::operator()();
