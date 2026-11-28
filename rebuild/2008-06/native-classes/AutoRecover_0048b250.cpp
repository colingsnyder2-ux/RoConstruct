// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: placeholder has a virtual destructor and no fields accessed here.
namespace boost {
class any {
public:
    class placeholder {
    public:
        virtual ~placeholder() {}
    };
};
}

// INFERRED: The compiler-generated deleting destructor cannot be named directly.
extern "C" void* __fastcall fn_0048b250(boost::any::placeholder* self, int unusedEdx, unsigned int flags)
{
    self->boost::any::placeholder::~placeholder();
    if (flags & 1)
        ::operator delete((void*)self);
    return self;
}
