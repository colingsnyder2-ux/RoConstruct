// from server: 100% by Xemicl
﻿#include <exception>
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Stream;
extern int (__thiscall *pubsync)(Stream*);

struct S {
    char pad0[0x14];
    char** first;
    char pad1[0x0c];
    char** current;
    char pad2[0x0c];
    int* available;
    char pad3[0x0c];
    Stream* stream;
    char* buffer;
    int length;

    char* pbase() const { return *first; }
    char* pptr() const { return *current; }
    void setp(char* b, char* e) { *first = b; *current = b; *available = e - b; }
    int write(const char*, int n) { return n; }
    void sync_impl()
    {
        int avail, amt;
        if ((avail = static_cast<int>(pptr() - pbase())) > 0) {
            if ((amt = write(pbase(), avail)) == avail)
                setp(buffer, buffer + length);
            else
                setp(buffer + amt, buffer + length);
        }
    }
    bool flush(Stream* sb)
    {
        bool result = true;
        if (sb && pubsync(sb) == -1)
            result = false;
        return result;
    }
    int sync();
};

int S::sync()
{
    try {
        sync_impl();
        flush(stream);
        return 0;
    } catch (std::exception&) {
        return -1;
    }
}