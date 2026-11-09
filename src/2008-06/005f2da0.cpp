// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_ustring_sink_owner_68c46decc463f1da.cpp

// Candidate translation unit (score above; library headers required).
#include <ostream>
#include <boost/iostreams/categories.hpp>

struct UString_output
{
    void* field0;
    void* field4;
    std::ostream stream;
};

struct UString_sink
{
    typedef char char_type;
    typedef boost::iostreams::sink_tag category;

    UString_output** output;

    std::streamsize write(const char* source, std::streamsize count);
};

std::streamsize UString_sink::write(const char* source, std::streamsize count)
{
    std::streamsize written = 0;
    while (written < count)
        written += (*output)->stream.rdbuf()->sputn(source + written, count - written);
    return written;
}
