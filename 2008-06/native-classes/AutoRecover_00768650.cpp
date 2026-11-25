// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was provided, so the classes are declared locally.
// The target is the compiler-generated scalar deleting destructor of a class
// derived from CXTPDockingPanePaintManager. It calls the base destructor
// (0x762d60), then the global operator delete when the low flag bit is set.
// INFERRED: the derived class name and its empty destructor are guesses.

class CXTPDockingPanePaintManager
{
public:
    CXTPDockingPanePaintManager();
protected:
    virtual ~CXTPDockingPanePaintManager();
};

class Local_00768650 : public CXTPDockingPanePaintManager
{
public:
    Local_00768650();
    virtual ~Local_00768650() {}
};

// INFERRED: defining the constructor out of line makes this translation unit
// emit the vtable, and with it the deleting destructor (the target).
Local_00768650::Local_00768650()
{
}
