// from server: 100% by auto
// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_a491fb17a36c2cb7.cpp

// Candidate translation unit (score above; library headers required).
#include <exception>
#define BOOST_NO_EXCEPTIONS
namespace boost { __declspec(noreturn) void throw_exception(std::exception const &); }
#include <deque>
#include <boost/function.hpp>
#include <boost/thread/mutex.hpp>
#include "util/standardout.h"

namespace RBX {
class Worker {
public:
    char pad[0x2ac];
    boost::mutex mutex;
    std::deque<boost::function0<void> > queue;
    void run();
};

void Worker::run()
{
    while (true) {
        boost::function0<void> item;
        {
            boost::mutex::scoped_lock lock(mutex);
            if (queue.empty())
                return;
            item = queue.front();
            queue.pop_front();
        }
        try {
            item();
        } catch (std::exception& e) {
            StandardOut::singleton()->print(MESSAGE_ERROR, "%s", e.what());
        }
    }
}
}
