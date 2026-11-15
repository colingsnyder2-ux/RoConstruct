// native-flags: /O2 /GS- /EHsc /MD
// Authentic Boost 1.34.1 stream buffers used by the native HTTP transport.
// Original destructor ranges: 005f73e0 (compressor), 005f75b0 (decompressor).
// Source identity remains subject to original RTTI/reference verification.
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/stream_buffer.hpp>

template class boost::iostreams::stream_buffer<boost::iostreams::basic_gzip_compressor<std::allocator<char> >, std::char_traits<char>, std::allocator<char>, boost::iostreams::output>;
template class boost::iostreams::stream_buffer<boost::iostreams::basic_gzip_decompressor<std::allocator<char> >, std::char_traits<char>, std::allocator<char>, boost::iostreams::input>;
