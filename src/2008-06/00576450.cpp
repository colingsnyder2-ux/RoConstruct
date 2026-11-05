// from server: 100% by king_originala
#include <string>
#include <exception>
struct StandardOut {
    void print(int, const char *, ...);
};

struct OutHandle {
    StandardOut *pointer;
    void *count;
    ~OutHandle();
    StandardOut *operator->() const { return pointer; }
};

OutHandle __cdecl singleton();


// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Source;
struct Event { void* value; };
struct Listener { virtual void onEvent(const Source*, Event) = 0; };
struct Padding { char bytes[0x344]; };
template <class T, class E> struct Notifier { void raise(E event, Listener* listener) const; int state; };
struct Source : Padding, Notifier<Source, Event> {};
template <class T, class E> void Notifier<T,E>::raise(E event, Listener* listener) const
{
    try {
        listener->onEvent(static_cast<const T*>(this), event);
    }
    catch (std::exception& error) {
        std::string what(error.what());
        singleton()->print(2, "Exception caught in onEvent. %s", what.c_str());
    }
}
template void Notifier<Source,Event>::raise(Event,Listener*) const;
