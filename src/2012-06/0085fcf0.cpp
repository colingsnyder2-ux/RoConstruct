// from server: 84% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <streambuf>
#include <ios>
#include <memory>
namespace boost { namespace iostreams {
struct output {};
template <class Alloc> class basic_gzip_compressor;
namespace detail {
template <class T>
struct member_close_operation {
    member_close_operation(T& t, std::ios_base::openmode which) : t_(t), which_(which) {}
    T& t_;
    std::ios_base::openmode which_;
};
template <class T>
member_close_operation<T> call_member_close(T& t, std::ios_base::openmode which) { return member_close_operation<T>(t, which); }
template <class T>
struct reset_operation {
    reset_operation(T& t) : t_(t) {}
    T& t_;
};
template <class T>
reset_operation<T> call_reset(T& t) { return reset_operation<T>(t); }
template <class T>
struct clear_flags_operation {
    clear_flags_operation(T& t) : t_(t) {}
    T& t_;
};
template <class T>
clear_flags_operation<T> clear_flags(T& t) { return clear_flags_operation<T>(t); }
template <class Op, class C0, class C1, class C2>
void execute_all(Op op, C0 c0, C1 c1, C2 c2);

template <class Ch, class Tr>
class linked_streambuf : public std::basic_streambuf<Ch, Tr> {
protected:
    linked_streambuf() : flags_(0) {}
public:
    virtual void set_next(linked_streambuf<Ch, Tr>*) {}
    virtual void close_impl(std::ios_base::openmode) = 0;
    virtual bool auto_close() const = 0;
    virtual void set_auto_close(bool) = 0;
    virtual bool strict_sync() = 0;
    virtual const std::type_info& component_type() const = 0;
    virtual void* component_impl() = 0;
private:
    int flags_;
};
template <class T>
struct optional_storage {
    char data[0x9c - 0x40 - 0x10];
};
template <class T, class Tr, class Alloc, class Mode>
class indirect_streambuf : public linked_streambuf<char, Tr> {
public:
    typedef linked_streambuf<char, Tr> base_type;
    indirect_streambuf();
    ~indirect_streambuf();
    bool is_open() const { return (flags_ & f_open) != 0; }
    void close()
    {
        using namespace std;
        base_type* self = this;
        detail::execute_all(
            detail::call_member_close(*self, std::ios_base::in),
            detail::call_member_close(*self, std::ios_base::out),
            detail::call_reset(storage_),
            detail::clear_flags(flags_));
    }
    bool auto_close() const { return (flags_ & f_auto_close) != 0; }
    void set_auto_close(bool close);
    bool strict_sync();
    void close_impl(std::ios_base::openmode);
    const std::type_info& component_type() const;
    void* component_impl();
private:
    enum flag_type {
        f_open = 1,
        f_output_buffered = f_open << 1,
        f_auto_close = f_output_buffered << 1
    };
    optional_storage<T> storage_;
    base_type* next_;
    char* buffer_[2];
    std::streamsize pback_size_;
    int flags_;
};
}
template <class T, class Tr = std::char_traits<char>, class Alloc = std::allocator<char>, class Mode = output>
class stream_buffer : public detail::indirect_streambuf<T, Tr, Alloc, Mode> {
public:
    stream_buffer();
    ~stream_buffer()
    {
        try {
            if (this->is_open() && this->auto_close())
                this->close();
        } catch (...) { }
    }
};
template class stream_buffer<basic_gzip_compressor<std::allocator<char> >, std::char_traits<char>, std::allocator<char>, output>;
}}