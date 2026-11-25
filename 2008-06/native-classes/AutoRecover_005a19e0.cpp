// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace RBX {
namespace Profiling {
class Profiler;
class CodeProfiler;
}
}

// INFERRED: Bound function and argument occupy offsets 0 and 4.
struct BoundFunction {
    double (__cdecl *function)(const RBX::Profiling::Profiler*);
    RBX::Profiling::CodeProfiler* argument;
};

extern "C" double __cdecl fn_005a19e0(BoundFunction* f)
{
    return f->function(reinterpret_cast<const RBX::Profiling::Profiler*>(f->argument));
}
