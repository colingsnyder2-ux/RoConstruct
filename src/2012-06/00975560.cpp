// from server: 100% by Xemicl
// roc 2012-06 00975560  unit: RBX::worker_thread::Udata::?$sp_counted_impl_p  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00975560
//
// 00975560  8b442408             mov eax, dword ptr [esp + 8]
// 00975564  dd00                 fld qword ptr [eax]
// 00975566  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0097556a  dc21                 fsub qword ptr [ecx]
// 0097556c  8b442404             mov eax, dword ptr [esp + 4]
// 00975570  dd18                 fstp qword ptr [eax]
// 00975572  c3                   ret 
// copied from an identical function in another client (function ?subtract@@YA?AUDur@@ABU1@0@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

struct Dur {
    double v;
    Dur() {}
};

Dur subtract(const Dur& a, const Dur& b)
{
    Dur r;
    r.v = a.v - b.v;
    return r;
}