// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_scriptjobnativeclockheadersb670c080334b6e81.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/date_time/posix_time/posix_time.hpp>
typedef __int64 TimeValue;
extern "C" {
    __declspec(dllimport) long __stdcall InterlockedExchange(volatile long *, long);
    __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long *);
}

extern volatile long sharedCounter;
extern double __cdecl currentTime();


extern void __cdecl updateState(void *, int, int);

struct Owner {
    void refresh();
};

struct Callback {
    void invoke(int, int);
};

#pragma pack(push, 4)
struct S {
    unsigned char padding0[4];
    void *state;
    unsigned char padding1[0x44];
    boost::posix_time::ptime nextUpdate;
    unsigned char padding2[0x20];
    Callback *callback;
    unsigned char padding3[0x0c];
    double interval;
    double deadline;
    volatile long counter;

    void run(int, int, int);
};
#pragma pack(pop)

void S::run(int unused, int first, int second)
{
    if (interval > 0.0)
        deadline = currentTime() + interval;

    if (InterlockedExchange(&counter, 0) == 1)
        InterlockedDecrement(&sharedCounter);

    boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();
    if (now >= nextUpdate) {
        reinterpret_cast<Owner *>(reinterpret_cast<char *>(this) - 0x134)->refresh();
        nextUpdate = boost::posix_time::second_clock::local_time() + boost::posix_time::seconds(1);
    }

    if (callback)
        callback->invoke(first, second);

    if (state)
        updateState(state, 5, 1);
}