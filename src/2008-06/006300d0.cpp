// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_gyro_ff3362a6f64c40ec.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct Object { char padding[0x2c8]; void* value; };
struct VControllerService { boost::shared_ptr<Object> getSomething(); };
struct BodyGyro {
 char padding[0x10]; VControllerService svc;
 void call1(void*); void call2(void*);
 void method(int, int);
};
void BodyGyro::method(int, int) {
 void* value = svc.getSomething()->value;
 BodyGyro* self = reinterpret_cast<BodyGyro*>(reinterpret_cast<char*>(this) - 0x130);
 self->call1(value);
 self->call2(value);
}
