// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: boost::date_time::str_from_delimited_time_duration for posix_time.
// The lexical_cast calls in the vendor source are replaced by the callees seen
// in the target disassembly; the local order/statements are the vendor source.
#include <string>
#include <boost/tokenizer.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/date_time/int_adapter.hpp>

extern "C" int fn_005be120(int a1);
extern "C" int fn_005e01b0(int a1);
extern "C" boost::int64_t fn_005e0020(int a1);

#define ROC_LEX_INT(s)      fn_005be120((int)&(s))
#define ROC_LEX_USHORT(s)   ((unsigned short)fn_005e01b0((int)&(s)))
#define ROC_LEX_I64(s)      fn_005e0020((int)&(s))

extern "C" boost::int64_t* fn_005e0c20(std::string& s)
{
    unsigned short min = 0, sec = 0;
    int hour = 0;
    bool is_neg = (s.at(0) == '-');
    boost::int64_t fs = 0;
    int pos = 0;

    typedef std::basic_string<char>::traits_type traits_type;
    typedef boost::char_separator<char, traits_type> char_separator_type;
    typedef boost::tokenizer<char_separator_type,
                             std::basic_string<char>::const_iterator,
                             std::basic_string<char> > tokenizer;
    typedef tokenizer::iterator tokenizer_iterator;

    char sep_chars[5] = {'-', ':', ',', '.'};
    char_separator_type sep(sep_chars);
    tokenizer tok(s, sep);

    for (tokenizer_iterator beg = tok.begin(); beg != tok.end(); ++beg) {
        switch (pos) {
        case 0: {
            hour = ROC_LEX_INT(*beg);
            break;
        }
        case 1: {
            min = ROC_LEX_USHORT(*beg);
            break;
        }
        case 2: {
            sec = ROC_LEX_USHORT(*beg);
            break;
        }
        case 3: {
            int digits = static_cast<int>(beg->length());
            if (digits >= 6) {
                fs = ROC_LEX_I64(beg->substr(0, 6));
            } else {
                fs = ROC_LEX_I64(*beg);
            }
            if (digits < 6) {
                int pad = 6 - digits;
                boost::int64_t mul = 1;
                while (pad-- > 0) mul *= 10;
                fs *= mul;
            }
            break;
        }
        }
        pos++;
    }

    typedef boost::posix_time::time_duration::traits_type traits;
    boost::int64_t ticks = traits::to_tick_count(hour, min, sec, fs);
    if (is_neg) {
        boost::date_time::int_adapter<boost::int64_t> a(ticks);
        ticks = (a * -1).as_number();
    }
    (*(boost::int64_t*)&s) = ticks;
    return (boost::int64_t*)&s;
}
