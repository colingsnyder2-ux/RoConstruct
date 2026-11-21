// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00464d70 ?execute@EventData@?$MarshaledListener@VRunService@RBX@@W4RunState@2@V12@W432@@RBX@@UAEXXZ: no body here.
// The explicit instantiation `template class RBX::MarshaledListener<RBX::RunService, RBX::RunState>::EventData;`
// that stood here repeated the one in AppUnit460_2008MarshaledEventData.cpp (the CScriptEditor range unit that owns
// 00464b60 / 00464ce0 / 00464d70 / 00464e00), so it was retired in batch 32 to keep one copy. Both units are blocked
// by the stray '}' in core util/MarshaledListener.h; with that fix (scratch build) 00464d70 is IDENTICAL there.
