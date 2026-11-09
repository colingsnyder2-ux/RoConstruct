// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_docauthoringempty_2d969e909e300645.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <string>
struct Model; struct Context;
typedef boost::shared_ptr<Model> Shared;
struct Returned : Shared {};
struct String { char storage[28]; __declspec(dllimport) ~String(); __declspec(dllimport) const char* c_str() const; };
struct Source
{
    Returned getModel();
};

struct Lock
{
    char storage[12];
    Lock(Shared model);
    ~Lock();
};

struct Model
{
    Context* getContext();
};

struct Authoring
{
    void getValues(int* first, int* second);
};

struct Context
{
    char padding[0x1f0];
    Authoring* authoring;
};

String __cdecl formatValue(int value);

struct Result
{
    virtual void setSuccess(int success) = 0;
    virtual void reserved1() = 0;
    virtual void reserved2() = 0;
    virtual void setText(const char* text) = 0;
};

struct CRobloxDoc
{
    char padding[0x94];
    Source* source;

    Returned getModel();
    void authoring(Result* result);
};

__forceinline Context* resolve(const Shared& p) { return p ? p->getContext() : 0; }

void CRobloxDoc::authoring(Result* result)
{
    Lock lock(source->getModel());

    Context* context = resolve(getModel());

    if (context && context->authoring)
    {
        int first;
        int second;
        context->authoring->getValues(&first, &second);
        String text = formatValue(first);
        result->setText(text.c_str());
        result->setSuccess(1);
    }
    else
    {
        result->setText("");
        result->setSuccess(0);
    }
}
