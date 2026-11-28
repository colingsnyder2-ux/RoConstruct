// native-flags: /O2 /GS- /MD /DNDEBUG /fp:fast
// Compiler float-constant COMDATs our link only had as zero stubs (gemini dossier section 22: __real@41d00000 = 26.0f).
// Using the literal from memory makes the compiler emit the __real@<bits> COMDAT with the right value.
float roc_real_41d00000(float x) { return x * 26.0f; }
