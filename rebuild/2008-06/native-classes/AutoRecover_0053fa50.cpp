// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: The supplied symbols for 0x00541030, 0x0071f210,
// 0x004e6c00, and 0x00502a70 appear to be folded functions.
// Their displayed signatures do not establish the actual object types
// and ABIs used here. A linkable, byte-exact definition is unresolved.
//
// Observed control flow:
// enabled: erase from self+0x48; if erased, insert into self+0x28;
//          call fn_0053f340(self, node).
// disabled: erase from self+0x28; if erased, insert into self+0x48;
//           obtain a handle from node; if valid, call fn_005400f0;
//           call fn_0053f470(self, node); release the handle.
