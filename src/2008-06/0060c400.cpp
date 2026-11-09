// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_settingsbind_b92bb5731c0ba930.cpp

// Candidate translation unit (score above; library headers required).


#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#pragma pointers_to_members(full_generality, multiple_inheritance)

struct Object
{
    char prefix[20];
};

typedef boost::shared_ptr<Object> Shared;

struct Settings;

struct Function
{
    char storage[40];
    template<class F> Function(const F&);
    ~Function();
};

struct Connection
{
    char storage[16];
    ~Connection();
};

struct ConnectionHandle
{
    char storage[16];
    ConnectionHandle& operator=(const Connection&);
    void clear();
};

struct Dispatcher
{
    Connection connect(void*, const Function&, int);
};

extern Dispatcher dispatcher;
extern char propertyDescriptor;
extern Shared __cdecl acquire(Object*);

struct Settings
{
    char prefix[0x154];
    Shared shared;
    ConnectionHandle connection;

    void callback();
    void notify(const void*);
    void update(int, Object*);
    void set(Object*);
};

void Settings::set(Object* value)
{
    if (value == shared.get())
        return;

    shared = acquire(value);

    notify(&propertyDescriptor);
    update(1, shared.get());

    if (shared.get())
    {
        Function function(boost::bind(&Settings::callback, this));
        connection = dispatcher.connect(
            shared.get() ? reinterpret_cast<char*>(shared.get()) + 20 : 0,
            function, 10);
    }
    else
    {
        connection.clear();
    }
}