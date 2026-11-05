// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_specdatastringreturns7002de86d90e7d94.cpp

// Candidate translation unit (score above; library headers required).
// from server: 98% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>

extern bool enabled;
extern const char emptyText[];

extern double __cdecl queryFloat();
extern unsigned __int64 __cdecl queryCounter();
extern unsigned __cdecl queryFirst();
extern unsigned __cdecl querySecond();
extern const std::string &__cdecl queryFirstString();
extern const std::string &__cdecl querySecondString();

struct MemoryStatus {
    unsigned length;
    unsigned load;
    int totalPhysical;
    unsigned availablePhysical;
    unsigned totalPageFile;
    unsigned availablePageFile;
    unsigned totalVirtual;
    unsigned availableVirtual;
};

extern "C" __declspec(dllimport) void __stdcall GlobalMemoryStatus(MemoryStatus *);

inline int queryPhysicalMegabytes()
{
    MemoryStatus status;
    GlobalMemoryStatus(&status);
    return status.totalPhysical / 1048576;
}

extern std::string __cdecl queryBlock();
extern std::string __cdecl queryTail();

struct S {
    float value;
    unsigned counter;
    unsigned first;
    unsigned second;
    std::string firstString;
    std::string secondString;
    std::string block;
    int physicalMegabytes;
    std::string tail;

    S();
};

S::S()
    : value(enabled ? queryFloat() : 0.0),
      counter(static_cast<unsigned>(queryCounter() >> 20)),
      first(queryFirst()),
      second(querySecond()),
      firstString(enabled ? queryFirstString() : std::string(emptyText)),
      secondString(enabled ? querySecondString() : std::string(emptyText)),
      block(queryBlock()),
      physicalMegabytes(queryPhysicalMegabytes()),
      tail(queryTail())
{
}
