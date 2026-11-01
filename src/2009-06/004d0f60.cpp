// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>

namespace RBX {
class Mutex;

class ScopedLock
{
public:
    explicit ScopedLock(Mutex& m);
    ~ScopedLock();
private:
    Mutex* m;
    bool locked;
};

class Log
{
public:
    void write(std::string message);
};

struct Logger
{
    char pad0[5];
    volatile bool enabled;
    char pad6[2];
    char mutexStorage[0x10];
    Log log;

    Mutex& mutex() { return *reinterpret_cast<Mutex*>(mutexStorage); }
};

void writeLog(Logger* logger, std::string message)
{
    ScopedLock lock(logger->mutex());
    if (logger->enabled)
        logger->log.write(message);
}
}
