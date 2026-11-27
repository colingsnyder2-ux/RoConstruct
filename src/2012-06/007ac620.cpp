// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
typedef __int64 int64_t;
typedef int int32_t;
namespace date_time {
template<typename int_type_>
class int_adapter {
public:
  typedef int_type_ int_type;
  int_adapter(int_type v) : value_(v) {}
  int_type as_number() const { return value_; }
private:
  int_type value_;
};
template <typename T> inline T absolute_value(T x) { return x < 0 ? -x : x; }
struct time_resolution_traits_adapted64_impl {
  typedef boost::int64_t int_type;
  typedef boost::date_time::int_adapter<boost::int64_t> impl_type;
  static int_type as_number(impl_type i){ return i.as_number();}
};
template<typename frac_sec_type, typename frac_sec_type::int_type resolution_adjust, unsigned short frac_digits, typename v_type = boost::int32_t >
class time_resolution_traits {
public:
  typedef typename frac_sec_type::int_type fractional_seconds_type;
  typedef typename frac_sec_type::int_type tick_type;
  typedef typename frac_sec_type::impl_type impl_type;
  typedef v_type day_type; typedef v_type hour_type; typedef v_type min_type; typedef v_type sec_type;
  static typename frac_sec_type::int_type as_number(typename frac_sec_type::impl_type i) { return frac_sec_type::as_number(i); }
  static fractional_seconds_type res_adjust() { return resolution_adjust; }
  static tick_type to_tick_count(hour_type hours, min_type minutes, sec_type seconds, fractional_seconds_type fs)
  {
    if(hours < 0 || minutes < 0 || seconds < 0 || fs < 0)
    {
      hours = absolute_value(hours);
      minutes = absolute_value(minutes);
      seconds = absolute_value(seconds);
      fs = absolute_value(fs);
      return (((((fractional_seconds_type(hours)*3600) + (fractional_seconds_type(minutes)*60) + seconds)*res_adjust()) + fs) * -1);
    }
    return (((fractional_seconds_type(hours)*3600) + (fractional_seconds_type(minutes)*60) + seconds)*res_adjust()) + fs;
  }
};
template<class T, typename rep_type>
class time_duration {
public:
  typedef typename rep_type::hour_type hour_type;
  typedef typename rep_type::min_type min_type;
  typedef typename rep_type::sec_type sec_type;
  typedef typename rep_type::fractional_seconds_type fractional_seconds_type;
  typedef typename rep_type::tick_type tick_type;
  typedef typename rep_type::impl_type impl_type;
  time_duration() : ticks_(0) {}
  time_duration(hour_type hours_in, min_type minutes_in, sec_type seconds_in=0, fractional_seconds_type frac_sec_in = 0) :
    ticks_(rep_type::to_tick_count(hours_in,minutes_in,seconds_in,frac_sec_in)) {}
  time_duration(const time_duration<T, rep_type>& other) : ticks_(other.ticks_) {}
  static tick_type ticks_per_second() { return rep_type::res_adjust(); }
  sec_type total_seconds() const { return static_cast<sec_type>(ticks() / ticks_per_second()); }
  tick_type total_milliseconds() const
  {
    if (ticks_per_second() < 1000) { return ticks() * (static_cast<tick_type>(1000) / ticks_per_second()); }
    return ticks() / (ticks_per_second() / static_cast<tick_type>(1000)) ;
  }
  tick_type ticks() const { return traits_type_as_number(); }
protected:
  tick_type traits_type_as_number() const { return rep_type::as_number(ticks_); }
  impl_type ticks_;
};
}
namespace posix_time {
typedef date_time::time_resolution_traits<boost::date_time::time_resolution_traits_adapted64_impl, 1000000, 6 > time_res_traits;
class time_duration : public date_time::time_duration<time_duration, time_res_traits>
{
public:
  time_duration(hour_type hour, min_type min, sec_type sec, fractional_seconds_type fs=0) :
    date_time::time_duration<time_duration, time_res_traits>(hour,min,sec,fs) {}
  time_duration() : date_time::time_duration<time_duration, time_res_traits>(0,0,0) {}
};
class seconds : public time_duration
{
public:
  explicit seconds(long s) : time_duration(0,0,s) {}
};
}
}struct PropDesc { int dummy; };
extern PropDesc prop_Time;
struct LightingParameters { void setTime(double t); };
struct LightingSignal { void operator()(bool skyboxChanged); };
struct Lighting {
    char pad0[0x88];
    LightingParameters skyParameters;
    char pad1[0x1c0 - 0x89];
    boost::posix_time::time_duration timeOfDay;
    char pad2[0x1f0 - 0x1c8];
    LightingSignal lightingChangedSignal;
    void raisePropertyChanged(const PropDesc& desc);
    void fireLightingChanged(bool b) { lightingChangedSignal(b); }
    void setTime(const boost::posix_time::time_duration& value);
};
void Lighting::setTime(const boost::posix_time::time_duration& value)
{
    int totalSeconds = value.total_seconds();
    totalSeconds -= (totalSeconds / 86400) * 86400;
    if (timeOfDay.total_seconds() != totalSeconds)
    {
        timeOfDay = boost::posix_time::seconds(totalSeconds);
        skyParameters.setTime(timeOfDay.total_seconds());
        raisePropertyChanged(prop_Time);
        fireLightingChanged(false);
    }
}
