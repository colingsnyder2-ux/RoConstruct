// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: boost 1.3x signals source; operator() is the stock header template,
// instantiated as signal1<void,int,last_value<void>,int,less<int>,function<void(int)>>.
#include <boost/signal.hpp>
#include <boost/function.hpp>
#include <functional>

template boost::last_value<void>::unusable
boost::signal1<void, int, boost::last_value<void>, int, std::less<int>,
               boost::function<void(int)> >::operator()(int);
