// from server: 100% by EspClaude
// roc 2009-06 006796a0  unit: RBX::Lighting::getTimeStr
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace boost { namespace posix_time {
class time_duration {
public:
    int lo, hi;
    time_duration(const time_duration& o) : lo(o.lo), hi(o.hi) {}
};
std::string to_simple_string(time_duration td);
} }
namespace RBX {
class Lighting {
public:
    char pad[0x1c8];
    boost::posix_time::time_duration timeOfDay;
    std::string getTimeStr() const;
};
std::string Lighting::getTimeStr() const
{
    return boost::posix_time::to_simple_string(timeOfDay);
}
}
