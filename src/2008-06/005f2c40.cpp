// from server: 100% by colin
typedef unsigned long DWORD;

extern "C" {
    extern int (__stdcall *WinHttpQueryDataAvailable)(void *, DWORD *);
    extern int (__stdcall *WinHttpReadData)(void *, void *, DWORD, DWORD *);
}

extern void (__thiscall *string_construct)(void *, const char *);

namespace std {
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class T, class Traits, class Alloc>
    class basic_string {
        unsigned char storage[28];
    public:
        basic_string(const T *);
        basic_string(const basic_string &);
        ~basic_string();
    };

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::basic_string(const T *text)
    {
        string_construct(this, text);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    class exception {
        void *vtable;
        const char *message;
    public:
        exception(const exception &);
        virtual ~exception();
        virtual const char *what() const;
    };

    class runtime_error : public exception {
        string message;
    public:
        runtime_error(const string &);
        runtime_error(const runtime_error &);
        virtual ~runtime_error();
        virtual const char *what() const;
    };
}

struct StreamBuffer {
    void *handle;
    int read(void *buffer, DWORD length);
};

int StreamBuffer::read(void *buffer, DWORD length)
{
    DWORD available;
    DWORD received;

    if (!WinHttpQueryDataAvailable(handle, &available))
        goto fail;
    if (available == 0)
        goto fail;

    if (!WinHttpReadData(handle, buffer, length, &received)) {
        std::string message("InternetReadFile failed");
        throw std::runtime_error(message);
    }
    return received;

fail:
    return -1;
}
