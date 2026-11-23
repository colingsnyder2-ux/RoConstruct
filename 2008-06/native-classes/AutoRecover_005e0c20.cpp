// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <boost/tokenizer.hpp>
#include <boost/cstdint.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/date_time/int_adapter.hpp>

extern "C" int fn_005be120(int a1);
extern "C" int fn_005e01b0(int a1);
extern "C" int fn_005e0020(int a1);

// INFERRED: boost::date_time::parse_delimited_time_duration instantiation for
// posix time_duration; separators "-:,." as in boost. The disassembly reads the
// string pointer and stores the 64-bit tick result through the same slot, so the
// argument is modelled as the string pointer and the result is written over it.
extern "C" boost::int64_t* fn_005e0c20(std::string* in)
{
    typedef boost::posix_time::time_duration::traits_type traits;
    const std::string& s = *in;

    unsigned short hour = 0, min = 0, sec = 0;
    int hourValue = 0;
    boost::int64_t fs = 0;
    int pos = 0;

    bool negative = s.at(0) == '-';
    boost::char_separator<char> sep("-:,.");
    typedef boost::tokenizer<boost::char_separator<char> > tok_t;
    tok_t tok(s, sep);

    for (tok_t::iterator it = tok.begin(); it != tok.end(); ++it) {
        const std::string& tokStr = *it;
        switch (pos) {
        case 0: hourValue = fn_005be120((int)&tokStr); break;
        case 1: min = (unsigned short)fn_005e01b0((int)&tokStr); break;
        case 2: sec = (unsigned short)fn_005e01b0((int)&tokStr); break;
        case 3: {
            int digits = (int)tokStr.length();
            if (digits >= 6) {
                std::string head = tokStr.substr(0, 6);
                fs = *(boost::int64_t*)(size_t)fn_005e0020((int)&head);
            } else {
                fs = *(boost::int64_t*)(size_t)fn_005e0020((int)&tokStr);
                int pad = 6 - digits;
                boost::int64_t mul = 1;
                while (pad-- > 0) mul *= 10;
                fs *= mul;
            }
            break;
        }
        }
        ++pos;
    }

    boost::int64_t ticks = traits::to_tick_count(hourValue, min, sec, fs);
    if (negative) {
        boost::date_time::int_adapter<boost::int64_t> a(ticks);
        ticks = (a * -1).as_number();
    }
    *(boost::int64_t*)in = ticks;
    return (boost::int64_t*)in;
}
