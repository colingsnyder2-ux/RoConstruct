// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_pickfacenamedray1e4ab579d7dffe1c.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Ray.h>
extern char lookupData[];
struct Result { int consume(const G3D::Ray& value, int* argument); };
struct S {
 G3D::Ray makeTemporary(void* input);
 Result* lookup(void* input, int mode, const char* data);
 int f(void* input, Result** result, int* argument);
};
int S::f(void* input, Result** result, int* argument) {
 *result=lookup(input,0,lookupData);
 if(*result) {
  G3D::Ray ray=makeTemporary(input);
  int value=(*result)->consume(ray,argument);
  if(value) return value;
 }
 return 0;
}
