// from server: 100% by Yeetserama
// hypothesis: 0054dc70 is boost::iostreams::detail::indirect_streambuf
// init_put_area for a stream buffer whose cached buffer begins at 0x50 and whose
// flags live at 0x5c. boost::iostreams::detail::buffer stores a begin pointer
// and a size, so end() is begin + size; that arithmetic reproduces the target's
// add/sub sequence inside std::streambuf::setp.
#include <streambuf>
#include <cstddef>

struct S_func_0054dc70 : std::streambuf
{
    char pad_to_50[0x50 - sizeof(std::streambuf)];
    char* buf_;
    int size_;
    char pad58[4];
    int flags_;

    bool output_buffered() const { return (flags_ & 8) != 0; }
    void f();
};

void S_func_0054dc70::f()
{
    if (output_buffered())
        setp(buf_, buf_ + size_);
    else
        setp(0, 0);
}
