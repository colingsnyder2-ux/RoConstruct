// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

namespace std {
struct _Iterator_base_aux {
    bool _Same_container(const _Iterator_base_aux&) const;
};
}

// INFERRED: callee takes no stack args (none pushed); returns bool in al (iterator has-container check)
extern "C" char __fastcall fn_00402410(void* self, int unusedEdx);

// INFERRED: checked vector iterator operator-: layout { proxy, ptr }
struct VecIter {
    int proxy;
    int* ptr;
};

extern "C" int __fastcall fn_00544500(VecIter* self, int unusedEdx, VecIter* other)
{
    if (!fn_00402410(self, 0) ||
        !reinterpret_cast<std::_Iterator_base_aux*>(self)->_Same_container(
            *reinterpret_cast<std::_Iterator_base_aux*>(other))) {
        _invalid_parameter_noinfo();
    }
    do {
    } while (0);
    return (int)(self->ptr - other->ptr);
}
