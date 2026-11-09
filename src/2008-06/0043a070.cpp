// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_editorvectors_383e9bc19ccb3ee1.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <boost/shared_ptr.hpp>
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

typedef std::vector<boost::shared_ptr<void> > Storage;

struct Argument
{
    unsigned int reserved[3];
    int value;
};

struct CSelectionPropGrid
{
    virtual ~CSelectionPropGrid();

    Storage storage;
    unsigned int context;

    CSelectionPropGrid(Argument*, unsigned int);
    void initialize(int);
};

CSelectionPropGrid::CSelectionPropGrid(Argument* argument, unsigned int value)
    : storage(), context(value)
{
    initialize(argument->value);
}