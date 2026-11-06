// from server: 100% by tajop
struct ymd_type {
    unsigned short year;
    unsigned short month;
    unsigned short day;
    ymd_type(unsigned short y, unsigned short m, unsigned short d) : year(y), month(m), day(d) {}
};

ymd_type from_day_number(unsigned int dn);
unsigned short day_of_week_calc(const ymd_type& ymd);
__declspec(noreturn) void on_error(int cur, unsigned short val, int violation);

struct greg_weekday {
    unsigned short value_;
    greg_weekday(unsigned short v) : value_(0)
    {
        if (v + 1 < 0 + 1)
            on_error(0, v, 0);
        if (v > 6)
            on_error(0, v, 1);
        value_ = v;
    }
};

struct date_t {
    unsigned int days_;
    greg_weekday day_of_week() const;
};

greg_weekday date_t::day_of_week() const
{
    const ymd_type& ymd = from_day_number(days_);
    return greg_weekday(day_of_week_calc(ymd));
}
