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

struct too_many_args : public std::exception
{
    too_many_args(const too_many_args &o);
    unsigned int cur_;
    unsigned int expected_;
};

too_many_args::too_many_args(const too_many_args &o)
    : std::exception(o), cur_(o.cur_), expected_(o.expected_)
{
}
