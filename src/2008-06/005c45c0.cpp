// from server: 100% by Xemicl
﻿// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>

namespace boost {
    struct xtime {
        __int64 sec;
        int nsec;
    };
    int __cdecl xtime_get(xtime* xtp, int clock_type);
    struct thread {
        static void __cdecl sleep(const xtime& xt);
    };
}

struct Report {
    std::string first;
    std::string second;
    Report(const std::string& text) : first(text) {}
    void send(const std::string& message);
};

int __cdecl wait_and_report(std::string text, int seconds)
{
    try {
        std::string message;
        Report report(text);
        report.send(message);
    } catch (...) {
    }
    boost::xtime xt;
    boost::xtime_get(&xt, 1);
    xt.sec += seconds;
    boost::thread::sleep(xt);
    return 1;
}
