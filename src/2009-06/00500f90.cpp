// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class String {
public:
    char* p;
    String(const String&);
    ~String();
};
String format(const char* fmt, ...);
class CritSec {
public:
    char cs[0x18];
    bool initialized;
    void lock();
    void unlock();
};
class StringArray {
public:
    String* data; int num; int numAllocated;
    void append(String s);
};
class Log {
public:
    char pad[0xa24];
    CritSec mutex;
    char pad2[0xb84 - 0xa24 - sizeof(CritSec)];
    StringArray lines;
    void write(const char* msg);
};
void Log::write(const char* msg)
{
    mutex.lock();
    lines.append(format(msg));
    mutex.unlock();
}
