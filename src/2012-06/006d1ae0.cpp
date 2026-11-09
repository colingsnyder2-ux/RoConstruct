// from server: 100% by tajop
namespace std
{
class exception
{
public:
    __declspec(dllimport) exception(const exception &);
    __declspec(dllimport) virtual ~exception();
private:
    const char *_m_what;
    int _m_doFree;
};
}

struct bad_format_string : public std::exception
{
    bad_format_string(const bad_format_string &o);
    unsigned int pos_;
    unsigned int next_;
};

bad_format_string::bad_format_string(const bad_format_string &o)
    : std::exception(o), pos_(o.pos_), next_(o.next_)
{
}
