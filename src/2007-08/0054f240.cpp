// from server: 100% by EspClaude
// from server: 53% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.34.1 roc_claude_7f6fe6cdcd0d2747.cpp

// Candidate translation unit (score above; library headers required).
// Authentic Boost.Iostreams 1.34.1 template: stream_buffer<T>::open_impl(const T&, int, int)
// (ret 0xc, is_open flag test, the library's non-throwing BOOST_IOSTREAMS_FAILURE("already open")
// temporary). The target's base open (0054df10) copies T as one boost::shared_ptr (addref of
// [t+4]) and keeps flags_ at +0x5c, so T is an 8-byte shared_ptr-holding device; the library's
// basic_file_sink<char> (basic_file: shared_ptr<impl> pimpl_) is used as the codegen analog.
// The recipe preprocesses without /MD; the target calls MSVCP80/MSVCR80 through the IAT.
#ifndef _DLL
#define _DLL
#endif
#include <boost/iostreams/stream_buffer.hpp>
#include <boost/iostreams/device/file.hpp>

template class boost::iostreams::stream_buffer< boost::iostreams::basic_file_sink<char> >;
