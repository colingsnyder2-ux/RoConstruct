// from server: 100% by Xemicl
﻿#include <exception>
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef void* (__thiscall *AppendFunction)(void*, const char*, unsigned int);
typedef int (__thiscall *SyncFunction)(void*);

extern AppendFunction basic_string_append;
extern SyncFunction basic_streambuf_pubsync;

struct S {
    char reserved0[0x14];
    char** first;
    char reserved1[0x0C];
    char** next;
    char reserved2[0x0C];
    int* remaining;
    char reserved3[0x08];
    void* string;
    char reserved4[0x04];
    void* streambuf;
    char* buffer;
    int capacity;

    char* pbase() const { return *first; }
    char* pptr() const { return *next; }
    void setp(char* b, char* e) { *first = b; *next = b; *remaining = e - b; }
    int write(const char* s, int n) { basic_string_append(string, s, n); return n; }
    void sync_impl()
    {
        int avail, amt;
        if ((avail = static_cast<int>(pptr() - pbase())) > 0) {
            if ((amt = write(pbase(), avail)) == avail)
                setp(buffer, buffer + capacity);
            else {
                const char* ptr = pptr();
                setp(buffer + amt, buffer + capacity);
            }
        }
    }
    bool flush(void* sb)
    {
        bool result = true;
        if (sb && basic_streambuf_pubsync(sb) == -1)
            result = false;
        return result;
    }
    int sync();
};

int S::sync()
{
    try {
        sync_impl();
        flush(streambuf);
        return 0;
    } catch (std::exception&) {
        return -1;
    }
}
