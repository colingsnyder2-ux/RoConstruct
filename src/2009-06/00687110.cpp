// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <streambuf>
#include <ios>
typedef __int64 stream_offset;
struct Next;
struct Adapter {
    __int64 align_;
    char pad[0x58];
    __declspec(noreturn) std::streampos seek(stream_offset off, std::ios_base::seekdir way, std::ios_base::openmode which, Next* next);
};
__declspec(noreturn) std::streampos seek_filter(Adapter& t, Next& dev, stream_offset off, std::ios_base::seekdir way, std::ios_base::openmode which);
class indirect_streambuf : public std::basic_streambuf<char> {
public:
    Adapter obj_;
    Next* next_;
    std::streampos seek_impl(stream_offset off, std::ios_base::seekdir way, std::ios_base::openmode which);
};
std::streampos indirect_streambuf::seek_impl(stream_offset off, std::ios_base::seekdir way, std::ios_base::openmode which)
{
    if (gptr() != 0 && way == std::ios_base::cur && which == std::ios_base::in &&
        eback() - gptr() <= off && off <= egptr() - gptr())
    {
        gbump(static_cast<int>(off));
        return seek_filter(obj_, *next_, 0, std::ios_base::cur, std::ios_base::in) - static_cast<std::streamoff>(egptr() - gptr());
    }
    if (pptr() != 0)
        this->pubsync();
    if (way == std::ios_base::cur && gptr())
        off -= static_cast<std::streamoff>(egptr() - gptr());
    setg(0, 0, 0);
    setp(0, 0);
    return obj_.seek(off, way, which, next_);
}
