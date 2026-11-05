// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct V {
    unsigned int size() const;
    double& operator()(unsigned int i);
};
template<class T1, class T2> struct scalar_multiplies_assign {
    static void apply(T1 t1, const T2& t2);
};
template<template <class T1, class T2> class F, class VV, class T>
void indexing_vector_assign_scalar(VV& v, const T& t)
{
    typedef F<double&, T> functor_type;
    unsigned int size(v.size());
    for (unsigned int i = 0; i < size; ++i)
        functor_type::apply(v(i), t);
}
template void indexing_vector_assign_scalar<scalar_multiplies_assign, V, double>(V&, const double&);
