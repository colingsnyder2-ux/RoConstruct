// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was provided, so the classes are declared locally.
// The target is the compiler-generated vector deleting destructor of a class derived
// from CXTPNotifySinkImpl<CXTPCalendarControl, CXTPCalendarControl::C_m_Sink_DP_Informator>.
// The previous draft compiled the constructor instead of this function, so the deleting
// destructor is written out directly here: a non-virtual call to the base destructor
// (0x6bdce0), then the global operator delete when bit 0 of the flags argument is set.

class CXTPCalendarControl
{
public:
    class C_m_Sink_DP_Informator;
};

template <class T, class S>
class CXTPNotifySinkImpl
{
public:
    CXTPNotifySinkImpl();
    virtual ~CXTPNotifySinkImpl();
};

typedef CXTPNotifySinkImpl<CXTPCalendarControl, CXTPCalendarControl::C_m_Sink_DP_Informator> Local_006bdec0;

extern "C" Local_006bdec0* __fastcall fn_006bdec0(Local_006bdec0* self, int unusedEdx, unsigned int flags)
{
    self->Local_006bdec0::~Local_006bdec0();
    if (flags & 1)
        ::operator delete(self);
    return self;
}
