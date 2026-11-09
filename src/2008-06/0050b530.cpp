// from server: 100% by king_originala
namespace std {
template<class T> class allocator {};
template<class T> struct char_traits {};

template<class T, class Traits = char_traits<T>, class Alloc = allocator<T> >
class basic_string {
    char storage[28];
public:
    basic_string(const T*);
    basic_string(const basic_string&);
    ~basic_string();
};

typedef basic_string<char> string;

class exception {
protected:
    void* table;
    char* message;
    bool owned;
public:
    exception();
    exception(const exception&);
    ~exception();
    const char* what() const;
};

class runtime_error : public exception {
    string message;
public:
    runtime_error(const string&);
    runtime_error(const runtime_error&);
    ~runtime_error();
    const char* what() const;
};
}

extern void (__thiscall *stringFromText)(std::string*, const char*);
extern void (__thiscall *stringFromString)(std::string*, const std::string&);
extern void (__thiscall *exceptionConstruct)(std::exception*);
extern void* runtimeErrorTable[];

template<>
__forceinline std::basic_string<char>::basic_string(const char* text)
{
    stringFromText(this, text);
}

template<>
__forceinline std::basic_string<char>::basic_string(const std::basic_string<char>& text)
{
    stringFromString(this, text);
}

__forceinline std::exception::exception()
{
    exceptionConstruct(this);
}

__forceinline std::runtime_error::runtime_error(const std::string& text)
    : exception(), message((table = runtimeErrorTable, text)) {}

struct Dialog;

struct DialogFunctions {
    void (__cdecl *slot0)();
    void (__cdecl *slot1)();
    void (__cdecl *prepare)(Dialog*);
    void (__cdecl *getMessage)(Dialog*, char*);
};

struct Dialog {
    DialogFunctions* functions;
};

extern void __cdecl releaseDialog(Dialog*);

void __cdecl reportDialogError(Dialog* dialog)
{
    char buffer[200];
    dialog->functions->prepare(dialog);
    releaseDialog(dialog);
    dialog->functions->getMessage(dialog, buffer);
    std::string message(buffer);
    throw std::runtime_error(message);
}
