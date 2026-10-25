// Boost 1.34.1 rebuild test: once, mutex, thread join, signals, regex, filesystem, date_time.
#include <boost/thread/once.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>
#include <boost/signals.hpp>
#include <boost/regex.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <cstdio>

static int onces = 0, counter = 0, fired = 0;
static boost::once_flag flag = BOOST_ONCE_INIT;
static boost::mutex lock;
static void init() { ++onces; }
static void work() { for (int i = 0; i < 1000; ++i) { boost::mutex::scoped_lock l(lock); ++counter; } }
static void slot(int v) { fired += v; }

int main()
{
    int failures = 0;
    boost::call_once(&init, flag); boost::call_once(&init, flag);
    if (onces != 1) { std::printf("once %d\n", onces); ++failures; }
    boost::thread a(&work), b(&work); a.join(); b.join();
    if (counter != 2000) { std::printf("mutex %d\n", counter); ++failures; }
    boost::signal<void (int)> sig; boost::signals::connection c = sig.connect(&slot); sig(3); c.disconnect(); sig(5);
    if (fired != 3) { std::printf("signals %d\n", fired); ++failures; }
    boost::smatch m; std::string s = "rbxasset://textures/sky.png";
    if (!boost::regex_match(s, m, boost::regex("([a-z]+)://(.*)")) || m[1] != "rbxasset") { std::printf("regex\n"); ++failures; }
    if (boost::filesystem::path("a/b/c.txt").leaf() != "c.txt") { std::printf("filesystem\n"); ++failures; }
    if (boost::gregorian::date(2008, 6, 1).day_of_week() != 0) { std::printf("date_time\n"); ++failures; }
    std::printf("failures=%d\n", failures);
    return failures;
}
