// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8tree/Instance.h"

// INFERRED: The two arguments form a bound callback and its reference argument.
extern "C" void __fastcall fn_005d8540(
    RBX::Instance* self, int unusedEdx,
    void (__cdecl *callback)(boost::shared_ptr<RBX::Instance>, void*),
    void* argument)
{
    if (self->children)
    {
        boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > > c =
            self->children.read();
        std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator end = c->end();
        std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator iter = c->begin();

        for (; iter != end; iter++)
        {
            callback(*iter, argument);
            fn_005d8540(iter->get(), 0, callback, argument);
        }
    }
}
