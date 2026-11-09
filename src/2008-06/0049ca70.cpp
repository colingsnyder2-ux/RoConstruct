// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_players_30a8422595c22522.cpp

// Candidate translation unit (score above; library headers required).
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct String;
typedef void (__thiscall *StringCopy)(String*, const String&);
typedef void (__thiscall *StringDestroy)(String*);

extern StringCopy copyString;
extern StringDestroy destroyString;

struct String {
    char storage[28];

    __declspec(dllimport) String(const String&);
    __declspec(dllimport) ~String();
};



#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> Shared;

struct Player;

extern unsigned char instanceType;
extern unsigned char playerType;

void* __cdecl castObject(void*, long, void*, void*, int);

struct S {
    void invoke(Player*, String);
    void f(Shared, String);
};

void S::f(Shared instance, String text)
{
    invoke(static_cast<Player*>(
        castObject(instance.get(), 0, &instanceType, &playerType, 0)),
        text);
}