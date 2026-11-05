// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <stdexcept>
namespace boost {
template<class E> __declspec(noreturn) void throw_exception(E const& e);
namespace gregorian {
class greg_year { public: unsigned short value_; operator unsigned short() const { return value_; } };
class greg_month { public: unsigned short value_; operator unsigned short() const { return value_; } };
class greg_day { public: unsigned short value_; operator unsigned short() const { return value_; } };
struct ymd_type {
	ymd_type(unsigned short y, unsigned short m, unsigned short d) : year(y), month(m), day(d) {}
	unsigned short year, month, day;
};
struct gregorian_calendar {
	static unsigned long day_number(const ymd_type& ymd);
	static unsigned short end_of_month_day(greg_year y, greg_month m);
};
struct bad_day_of_month : public std::out_of_range {
	bad_day_of_month(const std::string& s) : std::out_of_range(s) {}
};
class date_base {
public:
	date_base(greg_year y, greg_month m, greg_day d)
		: days_(gregorian_calendar::day_number(ymd_type(y, m, d))) {}
	unsigned long days_;
};
class date : public date_base {
public:
	date(greg_year y, greg_month m, greg_day d);
};
date::date(greg_year y, greg_month m, greg_day d) : date_base(y, m, d)
{
	if (gregorian_calendar::end_of_month_day(y, m) < d) {
		boost::throw_exception(bad_day_of_month(std::string("Day of month is not valid for year")));
	}
}
}
}
