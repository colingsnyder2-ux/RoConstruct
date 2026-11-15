#include "axis-vector-negation/G3D/Vector3.inl"
template<class T> struct NativeRecoverySink { static T value; };
template<class T> T NativeRecoverySink<T>::value;
template<class T> void nativeRecoveryKeep(T value){NativeRecoverySink<T>::value=value;}
void nativeRecoveryProbe(){nativeRecoveryKeep(&G3D::Vector3::isFinite);}
