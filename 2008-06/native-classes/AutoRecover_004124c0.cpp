// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <vector>
#include <boost/shared_ptr.hpp>

namespace RBX { class Instance; }

// INFERRED: the target is the stock VC9 std::vector::resize(size_type, _Ty) instantiation.
// The by-value shared_ptr parameter and the _invalid_parameter_noinfo calls (checked iterators)
// come from the STL header, so an explicit instantiation reproduces it.
template void std::vector<boost::shared_ptr<RBX::Instance>, std::allocator<boost::shared_ptr<RBX::Instance> > >::resize(size_t, boost::shared_ptr<RBX::Instance>);
