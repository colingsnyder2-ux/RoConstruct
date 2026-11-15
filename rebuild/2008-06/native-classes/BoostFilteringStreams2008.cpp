// native-flags: /O2 /GS- /EHsc /MD
// Boost 1.34.1 filtering streams; inactive pending source identity and ABI proof.
#include <boost/iostreams/filtering_stream.hpp>
template class boost::iostreams::filtering_stream<boost::iostreams::output>;
template class boost::iostreams::filtering_stream<boost::iostreams::input>;
