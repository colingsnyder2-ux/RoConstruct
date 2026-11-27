// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <exception>
namespace FLog {
typedef unsigned char Channel;
void FastLog(Channel channel, const char* message, const void* arg);
extern Channel Signals;
}
#define FASTLOG(group, message) do { if (group) FLog::FastLog(group, message, 0); } while (0)
namespace rbx { namespace signals {
struct slot_base;
struct slot_ptr
{
    slot_base* p;
    slot_ptr() : p(0) {}
    ~slot_ptr();
    slot_base* get() const { return p; }
};
template <class A1, class A2>
struct slot2
{
    static void call(slot_base* s, A1 a1, A2 a2);
};
class signal2
{
public:
    bool next(slot_ptr& p);
    void onException(const std::exception& e);
    void operator()(int a1, int a2);
};void signal2::operator()(int a1, int a2)
{
    FASTLOG(FLog::Signals, "Signal with 2 args executed");
    slot_ptr p;
    for (;;)
    {
        try
        {
            while (next(p))
                slot2<int, int>::call(p.get(), a1, a2);
            break;
        }
        catch (std::exception& e)
        {
            onException(e);
        }
    }
}
}}
