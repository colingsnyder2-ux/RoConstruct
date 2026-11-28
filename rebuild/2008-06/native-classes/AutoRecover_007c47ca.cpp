// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: This is an exception-unwind funclet that accesses its parent's EBP frame.
// The supplied analog is empty, so the parent function and destructor are unknown.
// A standalone C++ definition cannot reproduce this funclet from the supplied evidence.
