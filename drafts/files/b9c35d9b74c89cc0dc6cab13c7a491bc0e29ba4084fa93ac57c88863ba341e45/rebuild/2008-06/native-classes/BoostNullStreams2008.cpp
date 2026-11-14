// native-flags: /O2 /GS- /EHsc /MD
// Boost 1.34.1 null-stream implementations; inactive pending identity and runtime proof.
#include <boost/iostreams/device/null.hpp>
#include <boost/iostreams/stream_buffer.hpp>
template class boost::iostreams::stream_buffer<boost::iostreams::basic_null_device<char, boost::iostreams::output>, std::char_traits<char>, std::allocator<char>, boost::iostreams::output>;
template class boost::iostreams::stream_buffer<boost::iostreams::basic_null_device<char, boost::iostreams::input>, std::char_traits<char>, std::allocator<char>, boost::iostreams::input>;
