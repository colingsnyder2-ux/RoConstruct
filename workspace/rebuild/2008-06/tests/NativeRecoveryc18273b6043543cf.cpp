#include "v8datamodel/ModelInstance.h"
template<class T> struct NativeRecoverySink { static T value; };
template<class T> T NativeRecoverySink<T>::value;
template<class T> void nativeRecoveryKeep(T value){NativeRecoverySink<T>::value=value;}
void nativeRecoveryProbe(){nativeRecoveryKeep(&RBX::ModelInstance::setModelInPrimary);}
