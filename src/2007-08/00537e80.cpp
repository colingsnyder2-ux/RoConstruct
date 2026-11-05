// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-net roc_espeon_aug2007_bind133_compact_bd624eaf73501af4.cpp

// Candidate translation unit (score above; library headers required).
/* Authentic Boost1.33.1 bind/function sources. Comments/whitespace compacted for the verifier400000-character unit limit.
Copyright (c) 2001 David Abrahams
Copyright (c) 2001 Peter Dimov and Multi Media Ltd.
Copyright (c) 2001, 2002 Peter Dimov and Multi Media Ltd.
Copyright (c) 2001-2004 Peter Dimov and Multi Media Ltd.
Copyright (c) 2002 Peter Dimov and Multi Media Ltd.
Copyright (c) 2002, 2003 Peter Dimov and Multi Media Ltd.
Copyright (c) 2003-2005 Peter Dimov
Copyright (c) 2005 Peter Dimov
Copyright Douglas Gregor 2001-2004.
Use, modification and distribution are subject to the Boost Software License, Version1.0. https://www.boost.org/LICENSE_1_0.txt
*/
#define _MT 1
#ifndef _DLL
#define _DLL
#endif
#ifndef BOOST_BIND_HPP_INCLUDED
#define BOOST_BIND_HPP_INCLUDED
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif
#include <boost/config.hpp>
#include <boost/ref.hpp>
#ifndef BOOST_MEM_FN_HPP_INCLUDED
#define BOOST_MEM_FN_HPP_INCLUDED
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif
#include <boost/config.hpp>
#include <boost/get_pointer.hpp>
#include <boost/detail/workaround.hpp>
namespace boost
{
#if defined(BOOST_NO_VOID_RETURNS)
#define BOOST_MEM_FN_CLASS_F , class F
#define BOOST_MEM_FN_TYPEDEF(X)
namespace _mfi
{
template<class V> struct mf
{
#define BOOST_MEM_FN_RETURN return
#define BOOST_MEM_FN_NAME(X) inner_##X
#define BOOST_MEM_FN_CC
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf0)
{
public:
typedef R result_type;
typedef T*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)())
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(mf0)(F f):f_(f){}
R operator()(T*p) const
{
BOOST_MEM_FN_RETURN(p->*f_)();
}
template<class U> R operator()(U&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf0)
{
public:
typedef R result_type;
typedef T const*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)() const)
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(cmf0)(F f):f_(f){}
template<class U> R operator()(U const&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T const&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf1)
{
public:
typedef R result_type;
typedef T*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1))
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(mf1)(F f):f_(f){}
R operator()(T*p,A1 a1) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1);
}
template<class U> R operator()(U&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf1)
{
public:
typedef R result_type;
typedef T const*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1) const)
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(cmf1)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T const&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2))
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(mf2)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2);
}
template<class U> R operator()(U&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2) const)
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(cmf2)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T const&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3))
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(mf3)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3) const)
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(cmf3)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4))
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(mf4)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4) const)
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(cmf4)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(mf5)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(cmf5)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(mf6)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(cmf6)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(mf7)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(cmf7)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(mf8)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(cmf8)(F f):f_(f){}
R operator()(T const*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
#undef BOOST_MEM_FN_CC
#undef BOOST_MEM_FN_NAME
#ifdef BOOST_MEM_FN_ENABLE_CDECL
#define BOOST_MEM_FN_NAME(X) inner_##X##_cdecl
#define BOOST_MEM_FN_CC __cdecl
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf0)
{
public:
typedef R result_type;
typedef T*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)())
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(mf0)(F f):f_(f){}
R operator()(T*p) const
{
BOOST_MEM_FN_RETURN(p->*f_)();
}
template<class U> R operator()(U&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf0)
{
public:
typedef R result_type;
typedef T const*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)() const)
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(cmf0)(F f):f_(f){}
template<class U> R operator()(U const&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T const&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf1)
{
public:
typedef R result_type;
typedef T*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1))
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(mf1)(F f):f_(f){}
R operator()(T*p,A1 a1) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1);
}
template<class U> R operator()(U&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf1)
{
public:
typedef R result_type;
typedef T const*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1) const)
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(cmf1)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T const&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2))
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(mf2)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2);
}
template<class U> R operator()(U&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2) const)
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(cmf2)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T const&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3))
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(mf3)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3) const)
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(cmf3)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4))
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(mf4)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4) const)
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(cmf4)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(mf5)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(cmf5)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(mf6)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(cmf6)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(mf7)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(cmf7)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(mf8)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(cmf8)(F f):f_(f){}
R operator()(T const*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
#undef BOOST_MEM_FN_CC
#undef BOOST_MEM_FN_NAME
#endif
#ifdef BOOST_MEM_FN_ENABLE_STDCALL
#define BOOST_MEM_FN_NAME(X) inner_##X##_stdcall
#define BOOST_MEM_FN_CC __stdcall
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf0)
{
public:
typedef R result_type;
typedef T*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)())
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(mf0)(F f):f_(f){}
R operator()(T*p) const
{
BOOST_MEM_FN_RETURN(p->*f_)();
}
template<class U> R operator()(U&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf0)
{
public:
typedef R result_type;
typedef T const*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)() const)
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(cmf0)(F f):f_(f){}
template<class U> R operator()(U const&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T const&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf1)
{
public:
typedef R result_type;
typedef T*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1))
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(mf1)(F f):f_(f){}
R operator()(T*p,A1 a1) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1);
}
template<class U> R operator()(U&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf1)
{
public:
typedef R result_type;
typedef T const*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1) const)
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(cmf1)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T const&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2))
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(mf2)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2);
}
template<class U> R operator()(U&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2) const)
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(cmf2)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T const&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3))
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(mf3)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3) const)
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(cmf3)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4))
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(mf4)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4) const)
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(cmf4)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(mf5)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(cmf5)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(mf6)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(cmf6)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(mf7)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(cmf7)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(mf8)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(cmf8)(F f):f_(f){}
R operator()(T const*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
#undef BOOST_MEM_FN_CC
#undef BOOST_MEM_FN_NAME
#endif
#ifdef BOOST_MEM_FN_ENABLE_FASTCALL
#define BOOST_MEM_FN_NAME(X) inner_##X##_fastcall
#define BOOST_MEM_FN_CC __fastcall
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf0)
{
public:
typedef R result_type;
typedef T*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)())
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(mf0)(F f):f_(f){}
R operator()(T*p) const
{
BOOST_MEM_FN_RETURN(p->*f_)();
}
template<class U> R operator()(U&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf0)
{
public:
typedef R result_type;
typedef T const*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)() const)
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(cmf0)(F f):f_(f){}
template<class U> R operator()(U const&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T const&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf1)
{
public:
typedef R result_type;
typedef T*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1))
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(mf1)(F f):f_(f){}
R operator()(T*p,A1 a1) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1);
}
template<class U> R operator()(U&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf1)
{
public:
typedef R result_type;
typedef T const*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1) const)
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(cmf1)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T const&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2))
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(mf2)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2);
}
template<class U> R operator()(U&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2) const)
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(cmf2)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T const&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3))
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(mf3)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3) const)
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(cmf3)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4))
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(mf4)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4) const)
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(cmf4)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(mf5)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(cmf5)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(mf6)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(cmf6)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(mf7)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(cmf7)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(mf8)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(cmf8)(F f):f_(f){}
R operator()(T const*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
#undef BOOST_MEM_FN_CC
#undef BOOST_MEM_FN_NAME
#endif
#undef BOOST_MEM_FN_RETURN
};
template<> struct mf<void>
{
#define BOOST_MEM_FN_RETURN
#define BOOST_MEM_FN_NAME(X) inner_##X
#define BOOST_MEM_FN_CC
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf0)
{
public:
typedef R result_type;
typedef T*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)())
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(mf0)(F f):f_(f){}
R operator()(T*p) const
{
BOOST_MEM_FN_RETURN(p->*f_)();
}
template<class U> R operator()(U&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf0)
{
public:
typedef R result_type;
typedef T const*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)() const)
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(cmf0)(F f):f_(f){}
template<class U> R operator()(U const&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T const&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf1)
{
public:
typedef R result_type;
typedef T*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1))
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(mf1)(F f):f_(f){}
R operator()(T*p,A1 a1) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1);
}
template<class U> R operator()(U&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf1)
{
public:
typedef R result_type;
typedef T const*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1) const)
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(cmf1)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T const&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2))
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(mf2)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2);
}
template<class U> R operator()(U&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2) const)
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(cmf2)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T const&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3))
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(mf3)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3) const)
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(cmf3)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4))
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(mf4)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4) const)
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(cmf4)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(mf5)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(cmf5)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(mf6)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(cmf6)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(mf7)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(cmf7)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(mf8)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(cmf8)(F f):f_(f){}
R operator()(T const*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
#undef BOOST_MEM_FN_CC
#undef BOOST_MEM_FN_NAME
#ifdef BOOST_MEM_FN_ENABLE_CDECL
#define BOOST_MEM_FN_NAME(X) inner_##X##_cdecl
#define BOOST_MEM_FN_CC __cdecl
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf0)
{
public:
typedef R result_type;
typedef T*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)())
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(mf0)(F f):f_(f){}
R operator()(T*p) const
{
BOOST_MEM_FN_RETURN(p->*f_)();
}
template<class U> R operator()(U&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf0)
{
public:
typedef R result_type;
typedef T const*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)() const)
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(cmf0)(F f):f_(f){}
template<class U> R operator()(U const&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T const&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf1)
{
public:
typedef R result_type;
typedef T*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1))
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(mf1)(F f):f_(f){}
R operator()(T*p,A1 a1) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1);
}
template<class U> R operator()(U&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf1)
{
public:
typedef R result_type;
typedef T const*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1) const)
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(cmf1)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T const&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2))
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(mf2)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2);
}
template<class U> R operator()(U&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2) const)
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(cmf2)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T const&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3))
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(mf3)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3) const)
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(cmf3)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4))
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(mf4)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4) const)
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(cmf4)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(mf5)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(cmf5)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(mf6)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(cmf6)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(mf7)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(cmf7)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(mf8)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(cmf8)(F f):f_(f){}
R operator()(T const*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
#undef BOOST_MEM_FN_CC
#undef BOOST_MEM_FN_NAME
#endif
#ifdef BOOST_MEM_FN_ENABLE_STDCALL
#define BOOST_MEM_FN_NAME(X) inner_##X##_stdcall
#define BOOST_MEM_FN_CC __stdcall
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf0)
{
public:
typedef R result_type;
typedef T*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)())
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(mf0)(F f):f_(f){}
R operator()(T*p) const
{
BOOST_MEM_FN_RETURN(p->*f_)();
}
template<class U> R operator()(U&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf0)
{
public:
typedef R result_type;
typedef T const*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)() const)
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(cmf0)(F f):f_(f){}
template<class U> R operator()(U const&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T const&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf1)
{
public:
typedef R result_type;
typedef T*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1))
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(mf1)(F f):f_(f){}
R operator()(T*p,A1 a1) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1);
}
template<class U> R operator()(U&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf1)
{
public:
typedef R result_type;
typedef T const*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1) const)
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(cmf1)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T const&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2))
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(mf2)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2);
}
template<class U> R operator()(U&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2) const)
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(cmf2)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T const&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3))
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(mf3)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3) const)
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(cmf3)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4))
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(mf4)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4) const)
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(cmf4)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(mf5)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(cmf5)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(mf6)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(cmf6)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(mf7)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(cmf7)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(mf8)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(cmf8)(F f):f_(f){}
R operator()(T const*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
#undef BOOST_MEM_FN_CC
#undef BOOST_MEM_FN_NAME
#endif
#ifdef BOOST_MEM_FN_ENABLE_FASTCALL
#define BOOST_MEM_FN_NAME(X) inner_##X##_fastcall
#define BOOST_MEM_FN_CC __fastcall
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf0)
{
public:
typedef R result_type;
typedef T*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)())
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(mf0)(F f):f_(f){}
R operator()(T*p) const
{
BOOST_MEM_FN_RETURN(p->*f_)();
}
template<class U> R operator()(U&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf0)
{
public:
typedef R result_type;
typedef T const*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)() const)
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(cmf0)(F f):f_(f){}
template<class U> R operator()(U const&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T const&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf1)
{
public:
typedef R result_type;
typedef T*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1))
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(mf1)(F f):f_(f){}
R operator()(T*p,A1 a1) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1);
}
template<class U> R operator()(U&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf1)
{
public:
typedef R result_type;
typedef T const*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1) const)
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(cmf1)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T const&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2))
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(mf2)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2);
}
template<class U> R operator()(U&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2) const)
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(cmf2)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T const&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3))
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(mf3)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3) const)
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(cmf3)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4))
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(mf4)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4) const)
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(cmf4)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(mf5)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(cmf5)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(mf6)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(cmf6)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(mf7)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(cmf7)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(mf8)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(cmf8)(F f):f_(f){}
R operator()(T const*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
#undef BOOST_MEM_FN_CC
#undef BOOST_MEM_FN_NAME
#endif
#undef BOOST_MEM_FN_RETURN
};
#undef BOOST_MEM_FN_CLASS_F
#undef BOOST_MEM_FN_TYPEDEF_F
#define BOOST_MEM_FN_NAME(X) X
#define BOOST_MEM_FN_NAME2(X) inner_##X
#define BOOST_MEM_FN_CC
template<class R,class T> struct BOOST_MEM_FN_NAME(mf0):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf0)<R,T,R(BOOST_MEM_FN_CC T::*)()>
{
typedef R(BOOST_MEM_FN_CC T::*F)();
explicit BOOST_MEM_FN_NAME(mf0)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf0)<R,T,F>(f){}
};
template<class R,class T> struct BOOST_MEM_FN_NAME(cmf0):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf0)<R,T,R(BOOST_MEM_FN_CC T::*)() const>
{
typedef R(BOOST_MEM_FN_CC T::*F)() const;
explicit BOOST_MEM_FN_NAME(cmf0)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf0)<R,T,F>(f){}
};
template<class R,class T,class A1> struct BOOST_MEM_FN_NAME(mf1):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf1)<R,T,A1,R(BOOST_MEM_FN_CC T::*)(A1)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1);
explicit BOOST_MEM_FN_NAME(mf1)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf1)<R,T,A1,F>(f){}
};
template<class R,class T,class A1> struct BOOST_MEM_FN_NAME(cmf1):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf1)<R,T,A1,R(BOOST_MEM_FN_CC T::*)(A1) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1) const;
explicit BOOST_MEM_FN_NAME(cmf1)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf1)<R,T,A1,F>(f){}
};
template<class R,class T,class A1,class A2> struct BOOST_MEM_FN_NAME(mf2):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf2)<R,T,A1,A2,R(BOOST_MEM_FN_CC T::*)(A1,A2)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2);
explicit BOOST_MEM_FN_NAME(mf2)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf2)<R,T,A1,A2,F>(f){}
};
template<class R,class T,class A1,class A2> struct BOOST_MEM_FN_NAME(cmf2):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf2)<R,T,A1,A2,R(BOOST_MEM_FN_CC T::*)(A1,A2) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2) const;
explicit BOOST_MEM_FN_NAME(cmf2)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf2)<R,T,A1,A2,F>(f){}
};
template<class R,class T,class A1,class A2,class A3> struct BOOST_MEM_FN_NAME(mf3):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf3)<R,T,A1,A2,A3,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3);
explicit BOOST_MEM_FN_NAME(mf3)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf3)<R,T,A1,A2,A3,F>(f){}
};
template<class R,class T,class A1,class A2,class A3> struct BOOST_MEM_FN_NAME(cmf3):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf3)<R,T,A1,A2,A3,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3) const;
explicit BOOST_MEM_FN_NAME(cmf3)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf3)<R,T,A1,A2,A3,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4> struct BOOST_MEM_FN_NAME(mf4):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf4)<R,T,A1,A2,A3,A4,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4);
explicit BOOST_MEM_FN_NAME(mf4)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf4)<R,T,A1,A2,A3,A4,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4> struct BOOST_MEM_FN_NAME(cmf4):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf4)<R,T,A1,A2,A3,A4,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4) const;
explicit BOOST_MEM_FN_NAME(cmf4)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf4)<R,T,A1,A2,A3,A4,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5> struct BOOST_MEM_FN_NAME(mf5):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf5)<R,T,A1,A2,A3,A4,A5,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5);
explicit BOOST_MEM_FN_NAME(mf5)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf5)<R,T,A1,A2,A3,A4,A5,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5> struct BOOST_MEM_FN_NAME(cmf5):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf5)<R,T,A1,A2,A3,A4,A5,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5) const;
explicit BOOST_MEM_FN_NAME(cmf5)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf5)<R,T,A1,A2,A3,A4,A5,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6> struct BOOST_MEM_FN_NAME(mf6):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf6)<R,T,A1,A2,A3,A4,A5,A6,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6);
explicit BOOST_MEM_FN_NAME(mf6)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf6)<R,T,A1,A2,A3,A4,A5,A6,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6> struct BOOST_MEM_FN_NAME(cmf6):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf6)<R,T,A1,A2,A3,A4,A5,A6,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6) const;
explicit BOOST_MEM_FN_NAME(cmf6)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf6)<R,T,A1,A2,A3,A4,A5,A6,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7> struct BOOST_MEM_FN_NAME(mf7):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf7)<R,T,A1,A2,A3,A4,A5,A6,A7,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6,A7)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7);
explicit BOOST_MEM_FN_NAME(mf7)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf7)<R,T,A1,A2,A3,A4,A5,A6,A7,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7> struct BOOST_MEM_FN_NAME(cmf7):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf7)<R,T,A1,A2,A3,A4,A5,A6,A7,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6,A7) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7) const;
explicit BOOST_MEM_FN_NAME(cmf7)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf7)<R,T,A1,A2,A3,A4,A5,A6,A7,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> struct BOOST_MEM_FN_NAME(mf8):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6,A7,A8)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8);
explicit BOOST_MEM_FN_NAME(mf8)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> struct BOOST_MEM_FN_NAME(cmf8):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6,A7,A8) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8) const;
explicit BOOST_MEM_FN_NAME(cmf8)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8,F>(f){}
};
#undef BOOST_MEM_FN_NAME
#undef BOOST_MEM_FN_NAME2
#undef BOOST_MEM_FN_CC
#ifdef BOOST_MEM_FN_ENABLE_CDECL
#define BOOST_MEM_FN_NAME(X) X##_cdecl
#define BOOST_MEM_FN_NAME2(X) inner_##X##_cdecl
#define BOOST_MEM_FN_CC __cdecl
template<class R,class T> struct BOOST_MEM_FN_NAME(mf0):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf0)<R,T,R(BOOST_MEM_FN_CC T::*)()>
{
typedef R(BOOST_MEM_FN_CC T::*F)();
explicit BOOST_MEM_FN_NAME(mf0)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf0)<R,T,F>(f){}
};
template<class R,class T> struct BOOST_MEM_FN_NAME(cmf0):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf0)<R,T,R(BOOST_MEM_FN_CC T::*)() const>
{
typedef R(BOOST_MEM_FN_CC T::*F)() const;
explicit BOOST_MEM_FN_NAME(cmf0)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf0)<R,T,F>(f){}
};
template<class R,class T,class A1> struct BOOST_MEM_FN_NAME(mf1):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf1)<R,T,A1,R(BOOST_MEM_FN_CC T::*)(A1)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1);
explicit BOOST_MEM_FN_NAME(mf1)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf1)<R,T,A1,F>(f){}
};
template<class R,class T,class A1> struct BOOST_MEM_FN_NAME(cmf1):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf1)<R,T,A1,R(BOOST_MEM_FN_CC T::*)(A1) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1) const;
explicit BOOST_MEM_FN_NAME(cmf1)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf1)<R,T,A1,F>(f){}
};
template<class R,class T,class A1,class A2> struct BOOST_MEM_FN_NAME(mf2):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf2)<R,T,A1,A2,R(BOOST_MEM_FN_CC T::*)(A1,A2)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2);
explicit BOOST_MEM_FN_NAME(mf2)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf2)<R,T,A1,A2,F>(f){}
};
template<class R,class T,class A1,class A2> struct BOOST_MEM_FN_NAME(cmf2):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf2)<R,T,A1,A2,R(BOOST_MEM_FN_CC T::*)(A1,A2) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2) const;
explicit BOOST_MEM_FN_NAME(cmf2)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf2)<R,T,A1,A2,F>(f){}
};
template<class R,class T,class A1,class A2,class A3> struct BOOST_MEM_FN_NAME(mf3):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf3)<R,T,A1,A2,A3,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3);
explicit BOOST_MEM_FN_NAME(mf3)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf3)<R,T,A1,A2,A3,F>(f){}
};
template<class R,class T,class A1,class A2,class A3> struct BOOST_MEM_FN_NAME(cmf3):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf3)<R,T,A1,A2,A3,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3) const;
explicit BOOST_MEM_FN_NAME(cmf3)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf3)<R,T,A1,A2,A3,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4> struct BOOST_MEM_FN_NAME(mf4):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf4)<R,T,A1,A2,A3,A4,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4);
explicit BOOST_MEM_FN_NAME(mf4)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf4)<R,T,A1,A2,A3,A4,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4> struct BOOST_MEM_FN_NAME(cmf4):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf4)<R,T,A1,A2,A3,A4,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4) const;
explicit BOOST_MEM_FN_NAME(cmf4)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf4)<R,T,A1,A2,A3,A4,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5> struct BOOST_MEM_FN_NAME(mf5):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf5)<R,T,A1,A2,A3,A4,A5,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5);
explicit BOOST_MEM_FN_NAME(mf5)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf5)<R,T,A1,A2,A3,A4,A5,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5> struct BOOST_MEM_FN_NAME(cmf5):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf5)<R,T,A1,A2,A3,A4,A5,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5) const;
explicit BOOST_MEM_FN_NAME(cmf5)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf5)<R,T,A1,A2,A3,A4,A5,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6> struct BOOST_MEM_FN_NAME(mf6):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf6)<R,T,A1,A2,A3,A4,A5,A6,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6);
explicit BOOST_MEM_FN_NAME(mf6)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf6)<R,T,A1,A2,A3,A4,A5,A6,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6> struct BOOST_MEM_FN_NAME(cmf6):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf6)<R,T,A1,A2,A3,A4,A5,A6,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6) const;
explicit BOOST_MEM_FN_NAME(cmf6)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf6)<R,T,A1,A2,A3,A4,A5,A6,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7> struct BOOST_MEM_FN_NAME(mf7):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf7)<R,T,A1,A2,A3,A4,A5,A6,A7,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6,A7)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7);
explicit BOOST_MEM_FN_NAME(mf7)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf7)<R,T,A1,A2,A3,A4,A5,A6,A7,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7> struct BOOST_MEM_FN_NAME(cmf7):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf7)<R,T,A1,A2,A3,A4,A5,A6,A7,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6,A7) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7) const;
explicit BOOST_MEM_FN_NAME(cmf7)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf7)<R,T,A1,A2,A3,A4,A5,A6,A7,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> struct BOOST_MEM_FN_NAME(mf8):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6,A7,A8)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8);
explicit BOOST_MEM_FN_NAME(mf8)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> struct BOOST_MEM_FN_NAME(cmf8):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6,A7,A8) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8) const;
explicit BOOST_MEM_FN_NAME(cmf8)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8,F>(f){}
};
#undef BOOST_MEM_FN_NAME
#undef BOOST_MEM_FN_NAME2
#undef BOOST_MEM_FN_CC
#endif
#ifdef BOOST_MEM_FN_ENABLE_STDCALL
#define BOOST_MEM_FN_NAME(X) X##_stdcall
#define BOOST_MEM_FN_NAME2(X) inner_##X##_stdcall
#define BOOST_MEM_FN_CC __stdcall
template<class R,class T> struct BOOST_MEM_FN_NAME(mf0):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf0)<R,T,R(BOOST_MEM_FN_CC T::*)()>
{
typedef R(BOOST_MEM_FN_CC T::*F)();
explicit BOOST_MEM_FN_NAME(mf0)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf0)<R,T,F>(f){}
};
template<class R,class T> struct BOOST_MEM_FN_NAME(cmf0):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf0)<R,T,R(BOOST_MEM_FN_CC T::*)() const>
{
typedef R(BOOST_MEM_FN_CC T::*F)() const;
explicit BOOST_MEM_FN_NAME(cmf0)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf0)<R,T,F>(f){}
};
template<class R,class T,class A1> struct BOOST_MEM_FN_NAME(mf1):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf1)<R,T,A1,R(BOOST_MEM_FN_CC T::*)(A1)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1);
explicit BOOST_MEM_FN_NAME(mf1)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf1)<R,T,A1,F>(f){}
};
template<class R,class T,class A1> struct BOOST_MEM_FN_NAME(cmf1):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf1)<R,T,A1,R(BOOST_MEM_FN_CC T::*)(A1) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1) const;
explicit BOOST_MEM_FN_NAME(cmf1)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf1)<R,T,A1,F>(f){}
};
template<class R,class T,class A1,class A2> struct BOOST_MEM_FN_NAME(mf2):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf2)<R,T,A1,A2,R(BOOST_MEM_FN_CC T::*)(A1,A2)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2);
explicit BOOST_MEM_FN_NAME(mf2)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf2)<R,T,A1,A2,F>(f){}
};
template<class R,class T,class A1,class A2> struct BOOST_MEM_FN_NAME(cmf2):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf2)<R,T,A1,A2,R(BOOST_MEM_FN_CC T::*)(A1,A2) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2) const;
explicit BOOST_MEM_FN_NAME(cmf2)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf2)<R,T,A1,A2,F>(f){}
};
template<class R,class T,class A1,class A2,class A3> struct BOOST_MEM_FN_NAME(mf3):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf3)<R,T,A1,A2,A3,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3);
explicit BOOST_MEM_FN_NAME(mf3)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf3)<R,T,A1,A2,A3,F>(f){}
};
template<class R,class T,class A1,class A2,class A3> struct BOOST_MEM_FN_NAME(cmf3):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf3)<R,T,A1,A2,A3,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3) const;
explicit BOOST_MEM_FN_NAME(cmf3)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf3)<R,T,A1,A2,A3,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4> struct BOOST_MEM_FN_NAME(mf4):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf4)<R,T,A1,A2,A3,A4,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4);
explicit BOOST_MEM_FN_NAME(mf4)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf4)<R,T,A1,A2,A3,A4,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4> struct BOOST_MEM_FN_NAME(cmf4):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf4)<R,T,A1,A2,A3,A4,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4) const;
explicit BOOST_MEM_FN_NAME(cmf4)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf4)<R,T,A1,A2,A3,A4,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5> struct BOOST_MEM_FN_NAME(mf5):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf5)<R,T,A1,A2,A3,A4,A5,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5);
explicit BOOST_MEM_FN_NAME(mf5)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf5)<R,T,A1,A2,A3,A4,A5,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5> struct BOOST_MEM_FN_NAME(cmf5):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf5)<R,T,A1,A2,A3,A4,A5,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5) const;
explicit BOOST_MEM_FN_NAME(cmf5)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf5)<R,T,A1,A2,A3,A4,A5,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6> struct BOOST_MEM_FN_NAME(mf6):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf6)<R,T,A1,A2,A3,A4,A5,A6,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6);
explicit BOOST_MEM_FN_NAME(mf6)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf6)<R,T,A1,A2,A3,A4,A5,A6,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6> struct BOOST_MEM_FN_NAME(cmf6):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf6)<R,T,A1,A2,A3,A4,A5,A6,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6) const;
explicit BOOST_MEM_FN_NAME(cmf6)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf6)<R,T,A1,A2,A3,A4,A5,A6,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7> struct BOOST_MEM_FN_NAME(mf7):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf7)<R,T,A1,A2,A3,A4,A5,A6,A7,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6,A7)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7);
explicit BOOST_MEM_FN_NAME(mf7)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf7)<R,T,A1,A2,A3,A4,A5,A6,A7,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7> struct BOOST_MEM_FN_NAME(cmf7):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf7)<R,T,A1,A2,A3,A4,A5,A6,A7,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6,A7) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7) const;
explicit BOOST_MEM_FN_NAME(cmf7)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf7)<R,T,A1,A2,A3,A4,A5,A6,A7,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> struct BOOST_MEM_FN_NAME(mf8):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6,A7,A8)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8);
explicit BOOST_MEM_FN_NAME(mf8)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> struct BOOST_MEM_FN_NAME(cmf8):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6,A7,A8) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8) const;
explicit BOOST_MEM_FN_NAME(cmf8)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8,F>(f){}
};
#undef BOOST_MEM_FN_NAME
#undef BOOST_MEM_FN_NAME2
#undef BOOST_MEM_FN_CC
#endif
#ifdef BOOST_MEM_FN_ENABLE_FASTCALL
#define BOOST_MEM_FN_NAME(X) X##_fastcall
#define BOOST_MEM_FN_NAME2(X) inner_##X##_fastcall
#define BOOST_MEM_FN_CC __fastcall
template<class R,class T> struct BOOST_MEM_FN_NAME(mf0):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf0)<R,T,R(BOOST_MEM_FN_CC T::*)()>
{
typedef R(BOOST_MEM_FN_CC T::*F)();
explicit BOOST_MEM_FN_NAME(mf0)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf0)<R,T,F>(f){}
};
template<class R,class T> struct BOOST_MEM_FN_NAME(cmf0):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf0)<R,T,R(BOOST_MEM_FN_CC T::*)() const>
{
typedef R(BOOST_MEM_FN_CC T::*F)() const;
explicit BOOST_MEM_FN_NAME(cmf0)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf0)<R,T,F>(f){}
};
template<class R,class T,class A1> struct BOOST_MEM_FN_NAME(mf1):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf1)<R,T,A1,R(BOOST_MEM_FN_CC T::*)(A1)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1);
explicit BOOST_MEM_FN_NAME(mf1)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf1)<R,T,A1,F>(f){}
};
template<class R,class T,class A1> struct BOOST_MEM_FN_NAME(cmf1):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf1)<R,T,A1,R(BOOST_MEM_FN_CC T::*)(A1) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1) const;
explicit BOOST_MEM_FN_NAME(cmf1)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf1)<R,T,A1,F>(f){}
};
template<class R,class T,class A1,class A2> struct BOOST_MEM_FN_NAME(mf2):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf2)<R,T,A1,A2,R(BOOST_MEM_FN_CC T::*)(A1,A2)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2);
explicit BOOST_MEM_FN_NAME(mf2)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf2)<R,T,A1,A2,F>(f){}
};
template<class R,class T,class A1,class A2> struct BOOST_MEM_FN_NAME(cmf2):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf2)<R,T,A1,A2,R(BOOST_MEM_FN_CC T::*)(A1,A2) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2) const;
explicit BOOST_MEM_FN_NAME(cmf2)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf2)<R,T,A1,A2,F>(f){}
};
template<class R,class T,class A1,class A2,class A3> struct BOOST_MEM_FN_NAME(mf3):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf3)<R,T,A1,A2,A3,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3);
explicit BOOST_MEM_FN_NAME(mf3)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf3)<R,T,A1,A2,A3,F>(f){}
};
template<class R,class T,class A1,class A2,class A3> struct BOOST_MEM_FN_NAME(cmf3):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf3)<R,T,A1,A2,A3,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3) const;
explicit BOOST_MEM_FN_NAME(cmf3)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf3)<R,T,A1,A2,A3,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4> struct BOOST_MEM_FN_NAME(mf4):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf4)<R,T,A1,A2,A3,A4,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4);
explicit BOOST_MEM_FN_NAME(mf4)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf4)<R,T,A1,A2,A3,A4,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4> struct BOOST_MEM_FN_NAME(cmf4):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf4)<R,T,A1,A2,A3,A4,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4) const;
explicit BOOST_MEM_FN_NAME(cmf4)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf4)<R,T,A1,A2,A3,A4,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5> struct BOOST_MEM_FN_NAME(mf5):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf5)<R,T,A1,A2,A3,A4,A5,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5);
explicit BOOST_MEM_FN_NAME(mf5)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf5)<R,T,A1,A2,A3,A4,A5,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5> struct BOOST_MEM_FN_NAME(cmf5):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf5)<R,T,A1,A2,A3,A4,A5,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5) const;
explicit BOOST_MEM_FN_NAME(cmf5)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf5)<R,T,A1,A2,A3,A4,A5,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6> struct BOOST_MEM_FN_NAME(mf6):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf6)<R,T,A1,A2,A3,A4,A5,A6,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6);
explicit BOOST_MEM_FN_NAME(mf6)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf6)<R,T,A1,A2,A3,A4,A5,A6,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6> struct BOOST_MEM_FN_NAME(cmf6):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf6)<R,T,A1,A2,A3,A4,A5,A6,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6) const;
explicit BOOST_MEM_FN_NAME(cmf6)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf6)<R,T,A1,A2,A3,A4,A5,A6,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7> struct BOOST_MEM_FN_NAME(mf7):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf7)<R,T,A1,A2,A3,A4,A5,A6,A7,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6,A7)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7);
explicit BOOST_MEM_FN_NAME(mf7)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf7)<R,T,A1,A2,A3,A4,A5,A6,A7,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7> struct BOOST_MEM_FN_NAME(cmf7):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf7)<R,T,A1,A2,A3,A4,A5,A6,A7,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6,A7) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7) const;
explicit BOOST_MEM_FN_NAME(cmf7)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf7)<R,T,A1,A2,A3,A4,A5,A6,A7,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> struct BOOST_MEM_FN_NAME(mf8):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6,A7,A8)>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8);
explicit BOOST_MEM_FN_NAME(mf8)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(mf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8,F>(f){}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> struct BOOST_MEM_FN_NAME(cmf8):public mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8,R(BOOST_MEM_FN_CC T::*)(A1,A2,A3,A4,A5,A6,A7,A8) const>
{
typedef R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8) const;
explicit BOOST_MEM_FN_NAME(cmf8)(F f):mf<R>::BOOST_NESTED_TEMPLATE BOOST_MEM_FN_NAME2(cmf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8,F>(f){}
};
#undef BOOST_MEM_FN_NAME
#undef BOOST_MEM_FN_NAME2
#undef BOOST_MEM_FN_CC
#endif
}
#else
#define BOOST_MEM_FN_CLASS_F
#define BOOST_MEM_FN_TYPEDEF(X) typedef X;
namespace _mfi
{
#define BOOST_MEM_FN_RETURN return
#define BOOST_MEM_FN_NAME(X) X
#define BOOST_MEM_FN_CC
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf0)
{
public:
typedef R result_type;
typedef T*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)())
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(mf0)(F f):f_(f){}
R operator()(T*p) const
{
BOOST_MEM_FN_RETURN(p->*f_)();
}
template<class U> R operator()(U&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf0)
{
public:
typedef R result_type;
typedef T const*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)() const)
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(cmf0)(F f):f_(f){}
template<class U> R operator()(U const&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T const&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf1)
{
public:
typedef R result_type;
typedef T*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1))
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(mf1)(F f):f_(f){}
R operator()(T*p,A1 a1) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1);
}
template<class U> R operator()(U&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf1)
{
public:
typedef R result_type;
typedef T const*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1) const)
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(cmf1)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T const&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2))
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(mf2)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2);
}
template<class U> R operator()(U&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2) const)
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(cmf2)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T const&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3))
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(mf3)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3) const)
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(cmf3)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4))
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(mf4)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4) const)
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(cmf4)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(mf5)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(cmf5)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(mf6)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(cmf6)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(mf7)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(cmf7)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(mf8)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(cmf8)(F f):f_(f){}
R operator()(T const*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
#undef BOOST_MEM_FN_CC
#undef BOOST_MEM_FN_NAME
#ifdef BOOST_MEM_FN_ENABLE_CDECL
#define BOOST_MEM_FN_NAME(X) X##_cdecl
#define BOOST_MEM_FN_CC __cdecl
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf0)
{
public:
typedef R result_type;
typedef T*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)())
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(mf0)(F f):f_(f){}
R operator()(T*p) const
{
BOOST_MEM_FN_RETURN(p->*f_)();
}
template<class U> R operator()(U&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf0)
{
public:
typedef R result_type;
typedef T const*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)() const)
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(cmf0)(F f):f_(f){}
template<class U> R operator()(U const&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T const&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf1)
{
public:
typedef R result_type;
typedef T*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1))
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(mf1)(F f):f_(f){}
R operator()(T*p,A1 a1) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1);
}
template<class U> R operator()(U&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf1)
{
public:
typedef R result_type;
typedef T const*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1) const)
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(cmf1)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T const&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2))
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(mf2)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2);
}
template<class U> R operator()(U&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2) const)
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(cmf2)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T const&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3))
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(mf3)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3) const)
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(cmf3)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4))
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(mf4)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4) const)
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(cmf4)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(mf5)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(cmf5)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(mf6)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(cmf6)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(mf7)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(cmf7)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(mf8)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(cmf8)(F f):f_(f){}
R operator()(T const*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
#undef BOOST_MEM_FN_CC
#undef BOOST_MEM_FN_NAME
#endif
#ifdef BOOST_MEM_FN_ENABLE_STDCALL
#define BOOST_MEM_FN_NAME(X) X##_stdcall
#define BOOST_MEM_FN_CC __stdcall
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf0)
{
public:
typedef R result_type;
typedef T*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)())
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(mf0)(F f):f_(f){}
R operator()(T*p) const
{
BOOST_MEM_FN_RETURN(p->*f_)();
}
template<class U> R operator()(U&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf0)
{
public:
typedef R result_type;
typedef T const*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)() const)
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(cmf0)(F f):f_(f){}
template<class U> R operator()(U const&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T const&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf1)
{
public:
typedef R result_type;
typedef T*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1))
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(mf1)(F f):f_(f){}
R operator()(T*p,A1 a1) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1);
}
template<class U> R operator()(U&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf1)
{
public:
typedef R result_type;
typedef T const*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1) const)
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(cmf1)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T const&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2))
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(mf2)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2);
}
template<class U> R operator()(U&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2) const)
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(cmf2)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T const&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3))
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(mf3)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3) const)
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(cmf3)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4))
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(mf4)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4) const)
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(cmf4)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(mf5)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(cmf5)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(mf6)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(cmf6)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(mf7)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(cmf7)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(mf8)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(cmf8)(F f):f_(f){}
R operator()(T const*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
#undef BOOST_MEM_FN_CC
#undef BOOST_MEM_FN_NAME
#endif
#ifdef BOOST_MEM_FN_ENABLE_FASTCALL
#define BOOST_MEM_FN_NAME(X) X##_fastcall
#define BOOST_MEM_FN_CC __fastcall
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf0)
{
public:
typedef R result_type;
typedef T*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)())
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(mf0)(F f):f_(f){}
R operator()(T*p) const
{
BOOST_MEM_FN_RETURN(p->*f_)();
}
template<class U> R operator()(U&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf0)
{
public:
typedef R result_type;
typedef T const*argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)() const)
F f_;
template<class U> R call(U&u,T const*) const
{
BOOST_MEM_FN_RETURN(u.*f_)();
}
template<class U> R call(U&u,void const*) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)();
}
public:
explicit BOOST_MEM_FN_NAME(cmf0)(F f):f_(f){}
template<class U> R operator()(U const&u) const
{
BOOST_MEM_FN_RETURN call(u,&u);
}
R operator()(T const&t) const
{
BOOST_MEM_FN_RETURN(t.*f_)();
}
bool operator==(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf0) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf1)
{
public:
typedef R result_type;
typedef T*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1))
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(mf1)(F f):f_(f){}
R operator()(T*p,A1 a1) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1);
}
template<class U> R operator()(U&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf1)
{
public:
typedef R result_type;
typedef T const*first_argument_type;
typedef A1 second_argument_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1) const)
F f_;
template<class U,class B1> R call(U&u,T const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1);
}
template<class U,class B1> R call(U&u,void const*,B1&b1) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1);
}
public:
explicit BOOST_MEM_FN_NAME(cmf1)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1);
}
R operator()(T const&t,A1 a1) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1);
}
bool operator==(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf1) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2))
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(mf2)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2);
}
template<class U> R operator()(U&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf2)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2) const)
F f_;
template<class U,class B1,class B2> R call(U&u,T const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2);
}
template<class U,class B1,class B2> R call(U&u,void const*,B1&b1,B2&b2) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2);
}
public:
explicit BOOST_MEM_FN_NAME(cmf2)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2);
}
R operator()(T const&t,A1 a1,A2 a2) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2);
}
bool operator==(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf2) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3))
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(mf3)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf3)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3) const)
F f_;
template<class U,class B1,class B2,class B3> R call(U&u,T const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3);
}
template<class U,class B1,class B2,class B3> R call(U&u,void const*,B1&b1,B2&b2,B3&b3) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3);
}
public:
explicit BOOST_MEM_FN_NAME(cmf3)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3);
}
bool operator==(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf3) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4))
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(mf4)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf4)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4) const)
F f_;
template<class U,class B1,class B2,class B3,class B4> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4);
}
template<class U,class B1,class B2,class B3,class B4> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4);
}
public:
explicit BOOST_MEM_FN_NAME(cmf4)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4);
}
bool operator==(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf4) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(mf5)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf5)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5);
}
template<class U,class B1,class B2,class B3,class B4,class B5> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5);
}
public:
explicit BOOST_MEM_FN_NAME(cmf5)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5);
}
bool operator==(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf5) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(mf6)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf6)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6);
}
public:
explicit BOOST_MEM_FN_NAME(cmf6)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6);
}
bool operator==(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf6) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(mf7)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf7)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7);
}
public:
explicit BOOST_MEM_FN_NAME(cmf7)(F f):f_(f){}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7);
}
bool operator==(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf7) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(mf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8))
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(mf8)(F f):f_(f){}
R operator()(T*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(mf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8 BOOST_MEM_FN_CLASS_F> class BOOST_MEM_FN_NAME(cmf8)
{
public:
typedef R result_type;
private:
BOOST_MEM_FN_TYPEDEF(R(BOOST_MEM_FN_CC T::*F)(A1,A2,A3,A4,A5,A6,A7,A8) const)
F f_;
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,T const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(u.*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
template<class U,class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8> R call(U&u,void const*,B1&b1,B2&b2,B3&b3,B4&b4,B5&b5,B6&b6,B7&b7,B8&b8) const
{
BOOST_MEM_FN_RETURN(get_pointer(u)->*f_)(b1,b2,b3,b4,b5,b6,b7,b8);
}
public:
explicit BOOST_MEM_FN_NAME(cmf8)(F f):f_(f){}
R operator()(T const*p,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(p->*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
template<class U> R operator()(U const&u,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN call(u,&u,a1,a2,a3,a4,a5,a6,a7,a8);
}
R operator()(T const&t,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8) const
{
BOOST_MEM_FN_RETURN(t.*f_)(a1,a2,a3,a4,a5,a6,a7,a8);
}
bool operator==(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(BOOST_MEM_FN_NAME(cmf8) const&rhs) const
{
return f_ !=rhs.f_;
}
};
#undef BOOST_MEM_FN_CC
#undef BOOST_MEM_FN_NAME
#endif
#undef BOOST_MEM_FN_RETURN
}
#undef BOOST_MEM_FN_CLASS_F
#undef BOOST_MEM_FN_TYPEDEF
#endif
#define BOOST_MEM_FN_NAME(X) X
#define BOOST_MEM_FN_CC
template<class R,class T> _mfi::BOOST_MEM_FN_NAME(mf0)<R,T> mem_fn(R(BOOST_MEM_FN_CC T::*f)())
{
return _mfi::BOOST_MEM_FN_NAME(mf0)<R,T>(f);
}
template<class R,class T> _mfi::BOOST_MEM_FN_NAME(cmf0)<R,T> mem_fn(R(BOOST_MEM_FN_CC T::*f)() const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf0)<R,T>(f);
}
template<class R,class T,class A1> _mfi::BOOST_MEM_FN_NAME(mf1)<R,T,A1> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1))
{
return _mfi::BOOST_MEM_FN_NAME(mf1)<R,T,A1>(f);
}
template<class R,class T,class A1> _mfi::BOOST_MEM_FN_NAME(cmf1)<R,T,A1> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf1)<R,T,A1>(f);
}
template<class R,class T,class A1,class A2> _mfi::BOOST_MEM_FN_NAME(mf2)<R,T,A1,A2> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2))
{
return _mfi::BOOST_MEM_FN_NAME(mf2)<R,T,A1,A2>(f);
}
template<class R,class T,class A1,class A2> _mfi::BOOST_MEM_FN_NAME(cmf2)<R,T,A1,A2> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf2)<R,T,A1,A2>(f);
}
template<class R,class T,class A1,class A2,class A3> _mfi::BOOST_MEM_FN_NAME(mf3)<R,T,A1,A2,A3> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3))
{
return _mfi::BOOST_MEM_FN_NAME(mf3)<R,T,A1,A2,A3>(f);
}
template<class R,class T,class A1,class A2,class A3> _mfi::BOOST_MEM_FN_NAME(cmf3)<R,T,A1,A2,A3> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf3)<R,T,A1,A2,A3>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4> _mfi::BOOST_MEM_FN_NAME(mf4)<R,T,A1,A2,A3,A4> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4))
{
return _mfi::BOOST_MEM_FN_NAME(mf4)<R,T,A1,A2,A3,A4>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4> _mfi::BOOST_MEM_FN_NAME(cmf4)<R,T,A1,A2,A3,A4> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf4)<R,T,A1,A2,A3,A4>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5> _mfi::BOOST_MEM_FN_NAME(mf5)<R,T,A1,A2,A3,A4,A5> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5))
{
return _mfi::BOOST_MEM_FN_NAME(mf5)<R,T,A1,A2,A3,A4,A5>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5> _mfi::BOOST_MEM_FN_NAME(cmf5)<R,T,A1,A2,A3,A4,A5> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf5)<R,T,A1,A2,A3,A4,A5>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6> _mfi::BOOST_MEM_FN_NAME(mf6)<R,T,A1,A2,A3,A4,A5,A6> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6))
{
return _mfi::BOOST_MEM_FN_NAME(mf6)<R,T,A1,A2,A3,A4,A5,A6>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6> _mfi::BOOST_MEM_FN_NAME(cmf6)<R,T,A1,A2,A3,A4,A5,A6> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf6)<R,T,A1,A2,A3,A4,A5,A6>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7> _mfi::BOOST_MEM_FN_NAME(mf7)<R,T,A1,A2,A3,A4,A5,A6,A7> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6,A7))
{
return _mfi::BOOST_MEM_FN_NAME(mf7)<R,T,A1,A2,A3,A4,A5,A6,A7>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7> _mfi::BOOST_MEM_FN_NAME(cmf7)<R,T,A1,A2,A3,A4,A5,A6,A7> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6,A7) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf7)<R,T,A1,A2,A3,A4,A5,A6,A7>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> _mfi::BOOST_MEM_FN_NAME(mf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6,A7,A8))
{
return _mfi::BOOST_MEM_FN_NAME(mf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> _mfi::BOOST_MEM_FN_NAME(cmf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6,A7,A8) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8>(f);
}
#undef BOOST_MEM_FN_NAME
#undef BOOST_MEM_FN_CC
#ifdef BOOST_MEM_FN_ENABLE_CDECL
#define BOOST_MEM_FN_NAME(X) X##_cdecl
#define BOOST_MEM_FN_CC __cdecl
template<class R,class T> _mfi::BOOST_MEM_FN_NAME(mf0)<R,T> mem_fn(R(BOOST_MEM_FN_CC T::*f)())
{
return _mfi::BOOST_MEM_FN_NAME(mf0)<R,T>(f);
}
template<class R,class T> _mfi::BOOST_MEM_FN_NAME(cmf0)<R,T> mem_fn(R(BOOST_MEM_FN_CC T::*f)() const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf0)<R,T>(f);
}
template<class R,class T,class A1> _mfi::BOOST_MEM_FN_NAME(mf1)<R,T,A1> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1))
{
return _mfi::BOOST_MEM_FN_NAME(mf1)<R,T,A1>(f);
}
template<class R,class T,class A1> _mfi::BOOST_MEM_FN_NAME(cmf1)<R,T,A1> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf1)<R,T,A1>(f);
}
template<class R,class T,class A1,class A2> _mfi::BOOST_MEM_FN_NAME(mf2)<R,T,A1,A2> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2))
{
return _mfi::BOOST_MEM_FN_NAME(mf2)<R,T,A1,A2>(f);
}
template<class R,class T,class A1,class A2> _mfi::BOOST_MEM_FN_NAME(cmf2)<R,T,A1,A2> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf2)<R,T,A1,A2>(f);
}
template<class R,class T,class A1,class A2,class A3> _mfi::BOOST_MEM_FN_NAME(mf3)<R,T,A1,A2,A3> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3))
{
return _mfi::BOOST_MEM_FN_NAME(mf3)<R,T,A1,A2,A3>(f);
}
template<class R,class T,class A1,class A2,class A3> _mfi::BOOST_MEM_FN_NAME(cmf3)<R,T,A1,A2,A3> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf3)<R,T,A1,A2,A3>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4> _mfi::BOOST_MEM_FN_NAME(mf4)<R,T,A1,A2,A3,A4> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4))
{
return _mfi::BOOST_MEM_FN_NAME(mf4)<R,T,A1,A2,A3,A4>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4> _mfi::BOOST_MEM_FN_NAME(cmf4)<R,T,A1,A2,A3,A4> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf4)<R,T,A1,A2,A3,A4>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5> _mfi::BOOST_MEM_FN_NAME(mf5)<R,T,A1,A2,A3,A4,A5> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5))
{
return _mfi::BOOST_MEM_FN_NAME(mf5)<R,T,A1,A2,A3,A4,A5>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5> _mfi::BOOST_MEM_FN_NAME(cmf5)<R,T,A1,A2,A3,A4,A5> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf5)<R,T,A1,A2,A3,A4,A5>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6> _mfi::BOOST_MEM_FN_NAME(mf6)<R,T,A1,A2,A3,A4,A5,A6> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6))
{
return _mfi::BOOST_MEM_FN_NAME(mf6)<R,T,A1,A2,A3,A4,A5,A6>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6> _mfi::BOOST_MEM_FN_NAME(cmf6)<R,T,A1,A2,A3,A4,A5,A6> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf6)<R,T,A1,A2,A3,A4,A5,A6>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7> _mfi::BOOST_MEM_FN_NAME(mf7)<R,T,A1,A2,A3,A4,A5,A6,A7> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6,A7))
{
return _mfi::BOOST_MEM_FN_NAME(mf7)<R,T,A1,A2,A3,A4,A5,A6,A7>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7> _mfi::BOOST_MEM_FN_NAME(cmf7)<R,T,A1,A2,A3,A4,A5,A6,A7> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6,A7) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf7)<R,T,A1,A2,A3,A4,A5,A6,A7>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> _mfi::BOOST_MEM_FN_NAME(mf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6,A7,A8))
{
return _mfi::BOOST_MEM_FN_NAME(mf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> _mfi::BOOST_MEM_FN_NAME(cmf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6,A7,A8) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8>(f);
}
#undef BOOST_MEM_FN_NAME
#undef BOOST_MEM_FN_CC
#endif
#ifdef BOOST_MEM_FN_ENABLE_STDCALL
#define BOOST_MEM_FN_NAME(X) X##_stdcall
#define BOOST_MEM_FN_CC __stdcall
template<class R,class T> _mfi::BOOST_MEM_FN_NAME(mf0)<R,T> mem_fn(R(BOOST_MEM_FN_CC T::*f)())
{
return _mfi::BOOST_MEM_FN_NAME(mf0)<R,T>(f);
}
template<class R,class T> _mfi::BOOST_MEM_FN_NAME(cmf0)<R,T> mem_fn(R(BOOST_MEM_FN_CC T::*f)() const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf0)<R,T>(f);
}
template<class R,class T,class A1> _mfi::BOOST_MEM_FN_NAME(mf1)<R,T,A1> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1))
{
return _mfi::BOOST_MEM_FN_NAME(mf1)<R,T,A1>(f);
}
template<class R,class T,class A1> _mfi::BOOST_MEM_FN_NAME(cmf1)<R,T,A1> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf1)<R,T,A1>(f);
}
template<class R,class T,class A1,class A2> _mfi::BOOST_MEM_FN_NAME(mf2)<R,T,A1,A2> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2))
{
return _mfi::BOOST_MEM_FN_NAME(mf2)<R,T,A1,A2>(f);
}
template<class R,class T,class A1,class A2> _mfi::BOOST_MEM_FN_NAME(cmf2)<R,T,A1,A2> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf2)<R,T,A1,A2>(f);
}
template<class R,class T,class A1,class A2,class A3> _mfi::BOOST_MEM_FN_NAME(mf3)<R,T,A1,A2,A3> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3))
{
return _mfi::BOOST_MEM_FN_NAME(mf3)<R,T,A1,A2,A3>(f);
}
template<class R,class T,class A1,class A2,class A3> _mfi::BOOST_MEM_FN_NAME(cmf3)<R,T,A1,A2,A3> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf3)<R,T,A1,A2,A3>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4> _mfi::BOOST_MEM_FN_NAME(mf4)<R,T,A1,A2,A3,A4> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4))
{
return _mfi::BOOST_MEM_FN_NAME(mf4)<R,T,A1,A2,A3,A4>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4> _mfi::BOOST_MEM_FN_NAME(cmf4)<R,T,A1,A2,A3,A4> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf4)<R,T,A1,A2,A3,A4>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5> _mfi::BOOST_MEM_FN_NAME(mf5)<R,T,A1,A2,A3,A4,A5> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5))
{
return _mfi::BOOST_MEM_FN_NAME(mf5)<R,T,A1,A2,A3,A4,A5>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5> _mfi::BOOST_MEM_FN_NAME(cmf5)<R,T,A1,A2,A3,A4,A5> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf5)<R,T,A1,A2,A3,A4,A5>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6> _mfi::BOOST_MEM_FN_NAME(mf6)<R,T,A1,A2,A3,A4,A5,A6> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6))
{
return _mfi::BOOST_MEM_FN_NAME(mf6)<R,T,A1,A2,A3,A4,A5,A6>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6> _mfi::BOOST_MEM_FN_NAME(cmf6)<R,T,A1,A2,A3,A4,A5,A6> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf6)<R,T,A1,A2,A3,A4,A5,A6>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7> _mfi::BOOST_MEM_FN_NAME(mf7)<R,T,A1,A2,A3,A4,A5,A6,A7> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6,A7))
{
return _mfi::BOOST_MEM_FN_NAME(mf7)<R,T,A1,A2,A3,A4,A5,A6,A7>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7> _mfi::BOOST_MEM_FN_NAME(cmf7)<R,T,A1,A2,A3,A4,A5,A6,A7> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6,A7) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf7)<R,T,A1,A2,A3,A4,A5,A6,A7>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> _mfi::BOOST_MEM_FN_NAME(mf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6,A7,A8))
{
return _mfi::BOOST_MEM_FN_NAME(mf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> _mfi::BOOST_MEM_FN_NAME(cmf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6,A7,A8) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8>(f);
}
#undef BOOST_MEM_FN_NAME
#undef BOOST_MEM_FN_CC
#endif
#ifdef BOOST_MEM_FN_ENABLE_FASTCALL
#define BOOST_MEM_FN_NAME(X) X##_fastcall
#define BOOST_MEM_FN_CC __fastcall
template<class R,class T> _mfi::BOOST_MEM_FN_NAME(mf0)<R,T> mem_fn(R(BOOST_MEM_FN_CC T::*f)())
{
return _mfi::BOOST_MEM_FN_NAME(mf0)<R,T>(f);
}
template<class R,class T> _mfi::BOOST_MEM_FN_NAME(cmf0)<R,T> mem_fn(R(BOOST_MEM_FN_CC T::*f)() const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf0)<R,T>(f);
}
template<class R,class T,class A1> _mfi::BOOST_MEM_FN_NAME(mf1)<R,T,A1> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1))
{
return _mfi::BOOST_MEM_FN_NAME(mf1)<R,T,A1>(f);
}
template<class R,class T,class A1> _mfi::BOOST_MEM_FN_NAME(cmf1)<R,T,A1> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf1)<R,T,A1>(f);
}
template<class R,class T,class A1,class A2> _mfi::BOOST_MEM_FN_NAME(mf2)<R,T,A1,A2> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2))
{
return _mfi::BOOST_MEM_FN_NAME(mf2)<R,T,A1,A2>(f);
}
template<class R,class T,class A1,class A2> _mfi::BOOST_MEM_FN_NAME(cmf2)<R,T,A1,A2> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf2)<R,T,A1,A2>(f);
}
template<class R,class T,class A1,class A2,class A3> _mfi::BOOST_MEM_FN_NAME(mf3)<R,T,A1,A2,A3> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3))
{
return _mfi::BOOST_MEM_FN_NAME(mf3)<R,T,A1,A2,A3>(f);
}
template<class R,class T,class A1,class A2,class A3> _mfi::BOOST_MEM_FN_NAME(cmf3)<R,T,A1,A2,A3> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf3)<R,T,A1,A2,A3>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4> _mfi::BOOST_MEM_FN_NAME(mf4)<R,T,A1,A2,A3,A4> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4))
{
return _mfi::BOOST_MEM_FN_NAME(mf4)<R,T,A1,A2,A3,A4>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4> _mfi::BOOST_MEM_FN_NAME(cmf4)<R,T,A1,A2,A3,A4> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf4)<R,T,A1,A2,A3,A4>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5> _mfi::BOOST_MEM_FN_NAME(mf5)<R,T,A1,A2,A3,A4,A5> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5))
{
return _mfi::BOOST_MEM_FN_NAME(mf5)<R,T,A1,A2,A3,A4,A5>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5> _mfi::BOOST_MEM_FN_NAME(cmf5)<R,T,A1,A2,A3,A4,A5> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf5)<R,T,A1,A2,A3,A4,A5>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6> _mfi::BOOST_MEM_FN_NAME(mf6)<R,T,A1,A2,A3,A4,A5,A6> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6))
{
return _mfi::BOOST_MEM_FN_NAME(mf6)<R,T,A1,A2,A3,A4,A5,A6>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6> _mfi::BOOST_MEM_FN_NAME(cmf6)<R,T,A1,A2,A3,A4,A5,A6> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf6)<R,T,A1,A2,A3,A4,A5,A6>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7> _mfi::BOOST_MEM_FN_NAME(mf7)<R,T,A1,A2,A3,A4,A5,A6,A7> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6,A7))
{
return _mfi::BOOST_MEM_FN_NAME(mf7)<R,T,A1,A2,A3,A4,A5,A6,A7>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7> _mfi::BOOST_MEM_FN_NAME(cmf7)<R,T,A1,A2,A3,A4,A5,A6,A7> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6,A7) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf7)<R,T,A1,A2,A3,A4,A5,A6,A7>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> _mfi::BOOST_MEM_FN_NAME(mf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6,A7,A8))
{
return _mfi::BOOST_MEM_FN_NAME(mf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8>(f);
}
template<class R,class T,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> _mfi::BOOST_MEM_FN_NAME(cmf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8> mem_fn(R(BOOST_MEM_FN_CC T::*f)(A1,A2,A3,A4,A5,A6,A7,A8) const)
{
return _mfi::BOOST_MEM_FN_NAME(cmf8)<R,T,A1,A2,A3,A4,A5,A6,A7,A8>(f);
}
#undef BOOST_MEM_FN_NAME
#undef BOOST_MEM_FN_CC
#endif
namespace _mfi
{
template<class R,class T> class dm
{
public:
typedef R const&result_type;
typedef T const*argument_type;
private:
typedef R(T::*F);
F f_;
template<class U> R const&call(U&u,T const*) const
{
return(u.*f_);
}
template<class U> R&call(U&u,T*) const
{
return(u.*f_);
}
template<class U> R const&call(U&u,void const*) const
{
return(get_pointer(u)->*f_);
}
public:
explicit dm(F f):f_(f){}
R&operator()(T*p) const
{
return(p->*f_);
}
R const&operator()(T const*p) const
{
return(p->*f_);
}
template<class U> R const&operator()(U&u) const
{
return call(u,&u);
}
#if !BOOST_WORKAROUND(BOOST_MSVC, <= 1300) && !BOOST_WORKAROUND(__MWERKS__, < 0x3200)
R&operator()(T&t) const
{
return(t.*f_);
}
#endif
R const&operator()(T const&t) const
{
return(t.*f_);
}
bool operator==(dm const&rhs) const
{
return f_==rhs.f_;
}
bool operator!=(dm const&rhs) const
{
return f_ !=rhs.f_;
}
};
}
template<class R,class T> _mfi::dm<R,T> mem_fn(R T::*f)
{
return _mfi::dm<R,T>(f);
}
}
#endif
#include <boost/type.hpp>
#ifndef BOOST_BIND_ARG_HPP_INCLUDED
#define BOOST_BIND_ARG_HPP_INCLUDED
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif
namespace boost
{
template<int I> class arg
{
};
template<int I> bool operator==(arg<I> const&,arg<I> const&)
{
return true;
}
}
#endif
#include <boost/detail/workaround.hpp>
#if defined(__BORLANDC__)
#  define BOOST_BIND_VISIT_EACH boost::visit_each
#else
#  define BOOST_BIND_VISIT_EACH visit_each
#endif
#ifdef BOOST_MSVC
# pragma warning(push)
# pragma warning(disable: 4512)
#endif
namespace boost
{
namespace _bi
{
template<class R,class F> struct result_traits
{
typedef R type;
};
#if !defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) && !defined(BOOST_NO_FUNCTION_TEMPLATE_ORDERING)
struct unspecified{};
template<class F> struct result_traits<unspecified,F>
{
typedef typename F::result_type type;
};
template<class F> struct result_traits< unspecified,reference_wrapper<F> >
{
typedef typename F::result_type type;
};
#endif
template<class T> bool ref_compare(T const&a,T const&b,long)
{
return a==b;
}
template<class T> bool ref_compare(reference_wrapper<T> const&a,reference_wrapper<T> const&b,int)
{
return a.get_pointer()==b.get_pointer();
}
template<class R,class F,class L> class bind_t;
template<class T> class value
{
public:
value(T const&t):t_(t){}
T&get(){return t_;}
T const&get() const{return t_;}
bool operator==(value const&rhs) const
{
return t_==rhs.t_;
}
private:
T t_;
};
template<class T> class type{};
template<class F> inline F&unwrap(F*f,long)
{
return*f;
}
template<class F> inline F&unwrap(reference_wrapper<F>*f,int)
{
return f->get();
}
template<class F> inline F&unwrap(reference_wrapper<F> const*f,int)
{
return f->get();
}
#if !( defined(__MWERKS__) && BOOST_WORKAROUND(__MWERKS__, <= 0x3004) )
template<class R,class T> inline _mfi::dm<R,T> unwrap(R T::**pm,int)
{
return _mfi::dm<R,T>(*pm);
}
#if !BOOST_WORKAROUND(__IBMCPP__, BOOST_TESTED_AT(600))
template<class R,class T> inline _mfi::dm<R,T> unwrap(R T::*const*pm,int)
{
return _mfi::dm<R,T>(*pm);
}
#endif
#endif
class list0
{
public:
list0(){}
template<class T> T&operator[](_bi::value<T>&v) const{return v.get();}
template<class T> T const&operator[](_bi::value<T> const&v) const{return v.get();}
template<class T> T&operator[](reference_wrapper<T> const&v) const{return v.get();}
template<class R,class F,class L> typename result_traits<R,F>::type operator[](bind_t<R,F,L>&b) const{return b.eval(*this);}
template<class R,class F,class L> typename result_traits<R,F>::type operator[](bind_t<R,F,L> const&b) const{return b.eval(*this);}
template<class R,class F,class A> R operator()(type<R>,F&f,A&,long)
{
return unwrap(&f,0)();
}
template<class R,class F,class A> R operator()(type<R>,F const&f,A&,long) const
{
return unwrap(&f,0)();
}
template<class F,class A> void operator()(type<void>,F&f,A&,int)
{
unwrap(&f,0)();
}
template<class F,class A> void operator()(type<void>,F const&f,A&,int) const
{
unwrap(&f,0)();
}
template<class V> void accept(V&) const
{
}
bool operator==(list0 const&) const
{
return true;
}
};
template<class A1> class list1
{
public:
explicit list1(A1 a1):a1_(a1){}
A1 operator[](boost::arg<1>) const{return a1_;}
A1 operator[](boost::arg<1>(*)()) const{return a1_;}
template<class T> T&operator[](_bi::value<T>&v) const{return v.get();}
template<class T> T const&operator[](_bi::value<T> const&v) const{return v.get();}
template<class T> T&operator[](reference_wrapper<T> const&v) const{return v.get();}
template<class R,class F,class L> typename result_traits<R,F>::type operator[](bind_t<R,F,L>&b) const{return b.eval(*this);}
template<class R,class F,class L> typename result_traits<R,F>::type operator[](bind_t<R,F,L> const&b) const{return b.eval(*this);}
template<class R,class F,class A> R operator()(type<R>,F&f,A&a,long)
{
return unwrap(&f,0)(a[a1_]);
}
template<class R,class F,class A> R operator()(type<R>,F const&f,A&a,long) const
{
return unwrap(&f,0)(a[a1_]);
}
template<class F,class A> void operator()(type<void>,F&f,A&a,int)
{
unwrap(&f,0)(a[a1_]);
}
template<class F,class A> void operator()(type<void>,F const&f,A&a,int) const
{
unwrap(&f,0)(a[a1_]);
}
template<class V> void accept(V&v) const
{
BOOST_BIND_VISIT_EACH(v,a1_,0);
}
bool operator==(list1 const&rhs) const
{
return ref_compare(a1_,rhs.a1_,0);
}
private:
A1 a1_;
};
template<class A1,class A2> class list2
{
public:
list2(A1 a1,A2 a2):a1_(a1),a2_(a2){}
A1 operator[](boost::arg<1>) const{return a1_;}
A2 operator[](boost::arg<2>) const{return a2_;}
A1 operator[](boost::arg<1>(*)()) const{return a1_;}
A2 operator[](boost::arg<2>(*)()) const{return a2_;}
template<class T> T&operator[](_bi::value<T>&v) const{return v.get();}
template<class T> T const&operator[](_bi::value<T> const&v) const{return v.get();}
template<class T> T&operator[](reference_wrapper<T> const&v) const{return v.get();}
template<class R,class F,class L> typename result_traits<R,F>::type operator[](bind_t<R,F,L>&b) const{return b.eval(*this);}
template<class R,class F,class L> typename result_traits<R,F>::type operator[](bind_t<R,F,L> const&b) const{return b.eval(*this);}
template<class R,class F,class A> R operator()(type<R>,F&f,A&a,long)
{
return unwrap(&f,0)(a[a1_],a[a2_]);
}
template<class R,class F,class A> R operator()(type<R>,F const&f,A&a,long) const
{
return unwrap(&f,0)(a[a1_],a[a2_]);
}
template<class F,class A> void operator()(type<void>,F&f,A&a,int)
{
unwrap(&f,0)(a[a1_],a[a2_]);
}
template<class F,class A> void operator()(type<void>,F const&f,A&a,int) const
{
unwrap(&f,0)(a[a1_],a[a2_]);
}
template<class V> void accept(V&v) const
{
BOOST_BIND_VISIT_EACH(v,a1_,0);
BOOST_BIND_VISIT_EACH(v,a2_,0);
}
bool operator==(list2 const&rhs) const
{
return ref_compare(a1_,rhs.a1_,0)&&ref_compare(a2_,rhs.a2_,0);
}
private:
A1 a1_;
A2 a2_;
};
template<class A1,class A2,class A3> class list3
{
public:
list3(A1 a1,A2 a2,A3 a3):a1_(a1),a2_(a2),a3_(a3){}
A1 operator[](boost::arg<1>) const{return a1_;}
A2 operator[](boost::arg<2>) const{return a2_;}
A3 operator[](boost::arg<3>) const{return a3_;}
A1 operator[](boost::arg<1>(*)()) const{return a1_;}
A2 operator[](boost::arg<2>(*)()) const{return a2_;}
A3 operator[](boost::arg<3>(*)()) const{return a3_;}
template<class T> T&operator[](_bi::value<T>&v) const{return v.get();}
template<class T> T const&operator[](_bi::value<T> const&v) const{return v.get();}
template<class T> T&operator[](reference_wrapper<T> const&v) const{return v.get();}
template<class R,class F,class L> typename result_traits<R,F>::type operator[](bind_t<R,F,L>&b) const{return b.eval(*this);}
template<class R,class F,class L> typename result_traits<R,F>::type operator[](bind_t<R,F,L> const&b) const{return b.eval(*this);}
template<class R,class F,class A> R operator()(type<R>,F&f,A&a,long)
{
return unwrap(&f,0)(a[a1_],a[a2_],a[a3_]);
}
template<class R,class F,class A> R operator()(type<R>,F const&f,A&a,long) const
{
return unwrap(&f,0)(a[a1_],a[a2_],a[a3_]);
}
template<class F,class A> void operator()(type<void>,F&f,A&a,int)
{
unwrap(&f,0)(a[a1_],a[a2_],a[a3_]);
}
template<class F,class A> void operator()(type<void>,F const&f,A&a,int) const
{
unwrap(&f,0)(a[a1_],a[a2_],a[a3_]);
}
template<class V> void accept(V&v) const
{
BOOST_BIND_VISIT_EACH(v,a1_,0);
BOOST_BIND_VISIT_EACH(v,a2_,0);
BOOST_BIND_VISIT_EACH(v,a3_,0);
}
bool operator==(list3 const&rhs) const
{
return ref_compare(a1_,rhs.a1_,0)&&ref_compare(a2_,rhs.a2_,0)&&ref_compare(a3_,rhs.a3_,0);
}
private:
A1 a1_;
A2 a2_;
A3 a3_;
};
template<class A1,class A2,class A3,class A4> class list4
{
public:
list4(A1 a1,A2 a2,A3 a3,A4 a4):a1_(a1),a2_(a2),a3_(a3),a4_(a4){}
A1 operator[](boost::arg<1>) const{return a1_;}
A2 operator[](boost::arg<2>) const{return a2_;}
A3 operator[](boost::arg<3>) const{return a3_;}
A4 operator[](boost::arg<4>) const{return a4_;}
A1 operator[](boost::arg<1>(*)()) const{return a1_;}
A2 operator[](boost::arg<2>(*)()) const{return a2_;}
A3 operator[](boost::arg<3>(*)()) const{return a3_;}
A4 operator[](boost::arg<4>(*)()) const{return a4_;}
template<class T> T&operator[](_bi::value<T>&v) const{return v.get();}
template<class T> T const&operator[](_bi::value<T> const&v) const{return v.get();}
template<class T> T&operator[](reference_wrapper<T> const&v) const{return v.get();}
template<class R,class F,class L> typename result_traits<R,F>::type operator[](bind_t<R,F,L>&b) const{return b.eval(*this);}
template<class R,class F,class L> typename result_traits<R,F>::type operator[](bind_t<R,F,L> const&b) const{return b.eval(*this);}
template<class R,class F,class A> R operator()(type<R>,F&f,A&a,long)
{
return unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_]);
}
template<class R,class F,class A> R operator()(type<R>,F const&f,A&a,long) const
{
return unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_]);
}
template<class F,class A> void operator()(type<void>,F&f,A&a,int)
{
unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_]);
}
template<class F,class A> void operator()(type<void>,F const&f,A&a,int) const
{
unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_]);
}
template<class V> void accept(V&v) const
{
BOOST_BIND_VISIT_EACH(v,a1_,0);
BOOST_BIND_VISIT_EACH(v,a2_,0);
BOOST_BIND_VISIT_EACH(v,a3_,0);
BOOST_BIND_VISIT_EACH(v,a4_,0);
}
bool operator==(list4 const&rhs) const
{
return
ref_compare(a1_,rhs.a1_,0)&&ref_compare(a2_,rhs.a2_,0)&&ref_compare(a3_,rhs.a3_,0)&&
ref_compare(a4_,rhs.a4_,0);
}
private:
A1 a1_;
A2 a2_;
A3 a3_;
A4 a4_;
};
template<class A1,class A2,class A3,class A4,class A5> class list5
{
public:
list5(A1 a1,A2 a2,A3 a3,A4 a4,A5 a5):a1_(a1),a2_(a2),a3_(a3),a4_(a4),a5_(a5){}
A1 operator[](boost::arg<1>) const{return a1_;}
A2 operator[](boost::arg<2>) const{return a2_;}
A3 operator[](boost::arg<3>) const{return a3_;}
A4 operator[](boost::arg<4>) const{return a4_;}
A5 operator[](boost::arg<5>) const{return a5_;}
A1 operator[](boost::arg<1>(*)()) const{return a1_;}
A2 operator[](boost::arg<2>(*)()) const{return a2_;}
A3 operator[](boost::arg<3>(*)()) const{return a3_;}
A4 operator[](boost::arg<4>(*)()) const{return a4_;}
A5 operator[](boost::arg<5>(*)()) const{return a5_;}
template<class T> T&operator[](_bi::value<T>&v) const{return v.get();}
template<class T> T const&operator[](_bi::value<T> const&v) const{return v.get();}
template<class T> T&operator[](reference_wrapper<T> const&v) const{return v.get();}
template<class R,class F,class L> typename result_traits<R,F>::type operator[](bind_t<R,F,L>&b) const{return b.eval(*this);}
template<class R,class F,class L> typename result_traits<R,F>::type operator[](bind_t<R,F,L> const&b) const{return b.eval(*this);}
template<class R,class F,class A> R operator()(type<R>,F&f,A&a,long)
{
return unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_],a[a5_]);
}
template<class R,class F,class A> R operator()(type<R>,F const&f,A&a,long) const
{
return unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_],a[a5_]);
}
template<class F,class A> void operator()(type<void>,F&f,A&a,int)
{
unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_],a[a5_]);
}
template<class F,class A> void operator()(type<void>,F const&f,A&a,int) const
{
unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_],a[a5_]);
}
template<class V> void accept(V&v) const
{
BOOST_BIND_VISIT_EACH(v,a1_,0);
BOOST_BIND_VISIT_EACH(v,a2_,0);
BOOST_BIND_VISIT_EACH(v,a3_,0);
BOOST_BIND_VISIT_EACH(v,a4_,0);
BOOST_BIND_VISIT_EACH(v,a5_,0);
}
bool operator==(list5 const&rhs) const
{
return
ref_compare(a1_,rhs.a1_,0)&&ref_compare(a2_,rhs.a2_,0)&&ref_compare(a3_,rhs.a3_,0)&&
ref_compare(a4_,rhs.a4_,0)&&ref_compare(a5_,rhs.a5_,0);
}
private:
A1 a1_;
A2 a2_;
A3 a3_;
A4 a4_;
A5 a5_;
};
template<class A1,class A2,class A3,class A4,class A5,class A6> class list6
{
public:
list6(A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6):a1_(a1),a2_(a2),a3_(a3),a4_(a4),a5_(a5),a6_(a6){}
A1 operator[](boost::arg<1>) const{return a1_;}
A2 operator[](boost::arg<2>) const{return a2_;}
A3 operator[](boost::arg<3>) const{return a3_;}
A4 operator[](boost::arg<4>) const{return a4_;}
A5 operator[](boost::arg<5>) const{return a5_;}
A6 operator[](boost::arg<6>) const{return a6_;}
A1 operator[](boost::arg<1>(*)()) const{return a1_;}
A2 operator[](boost::arg<2>(*)()) const{return a2_;}
A3 operator[](boost::arg<3>(*)()) const{return a3_;}
A4 operator[](boost::arg<4>(*)()) const{return a4_;}
A5 operator[](boost::arg<5>(*)()) const{return a5_;}
A6 operator[](boost::arg<6>(*)()) const{return a6_;}
template<class T> T&operator[](_bi::value<T>&v) const{return v.get();}
template<class T> T const&operator[](_bi::value<T> const&v) const{return v.get();}
template<class T> T&operator[](reference_wrapper<T> const&v) const{return v.get();}
template<class R,class F,class L> typename result_traits<R,F>::type operator[](bind_t<R,F,L>&b) const{return b.eval(*this);}
template<class R,class F,class L> typename result_traits<R,F>::type operator[](bind_t<R,F,L> const&b) const{return b.eval(*this);}
template<class R,class F,class A> R operator()(type<R>,F&f,A&a,long)
{
return unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_],a[a5_],a[a6_]);
}
template<class R,class F,class A> R operator()(type<R>,F const&f,A&a,long) const
{
return unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_],a[a5_],a[a6_]);
}
template<class F,class A> void operator()(type<void>,F&f,A&a,int)
{
unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_],a[a5_],a[a6_]);
}
template<class F,class A> void operator()(type<void>,F const&f,A&a,int) const
{
unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_],a[a5_],a[a6_]);
}
template<class V> void accept(V&v) const
{
BOOST_BIND_VISIT_EACH(v,a1_,0);
BOOST_BIND_VISIT_EACH(v,a2_,0);
BOOST_BIND_VISIT_EACH(v,a3_,0);
BOOST_BIND_VISIT_EACH(v,a4_,0);
BOOST_BIND_VISIT_EACH(v,a5_,0);
BOOST_BIND_VISIT_EACH(v,a6_,0);
}
bool operator==(list6 const&rhs) const
{
return
ref_compare(a1_,rhs.a1_,0)&&ref_compare(a2_,rhs.a2_,0)&&ref_compare(a3_,rhs.a3_,0)&&
ref_compare(a4_,rhs.a4_,0)&&ref_compare(a5_,rhs.a5_,0)&&ref_compare(a6_,rhs.a6_,0);
}
private:
A1 a1_;
A2 a2_;
A3 a3_;
A4 a4_;
A5 a5_;
A6 a6_;
};
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7> class list7
{
public:
list7(A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7):a1_(a1),a2_(a2),a3_(a3),a4_(a4),a5_(a5),a6_(a6),a7_(a7){}
A1 operator[](boost::arg<1>) const{return a1_;}
A2 operator[](boost::arg<2>) const{return a2_;}
A3 operator[](boost::arg<3>) const{return a3_;}
A4 operator[](boost::arg<4>) const{return a4_;}
A5 operator[](boost::arg<5>) const{return a5_;}
A6 operator[](boost::arg<6>) const{return a6_;}
A7 operator[](boost::arg<7>) const{return a7_;}
A1 operator[](boost::arg<1>(*)()) const{return a1_;}
A2 operator[](boost::arg<2>(*)()) const{return a2_;}
A3 operator[](boost::arg<3>(*)()) const{return a3_;}
A4 operator[](boost::arg<4>(*)()) const{return a4_;}
A5 operator[](boost::arg<5>(*)()) const{return a5_;}
A6 operator[](boost::arg<6>(*)()) const{return a6_;}
A7 operator[](boost::arg<7>(*)()) const{return a7_;}
template<class T> T&operator[](_bi::value<T>&v) const{return v.get();}
template<class T> T const&operator[](_bi::value<T> const&v) const{return v.get();}
template<class T> T&operator[](reference_wrapper<T> const&v) const{return v.get();}
template<class R,class F,class L> typename result_traits<R,F>::type operator[](bind_t<R,F,L>&b) const{return b.eval(*this);}
template<class R,class F,class L> typename result_traits<R,F>::type operator[](bind_t<R,F,L> const&b) const{return b.eval(*this);}
template<class R,class F,class A> R operator()(type<R>,F&f,A&a,long)
{
return unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_],a[a5_],a[a6_],a[a7_]);
}
template<class R,class F,class A> R operator()(type<R>,F const&f,A&a,long) const
{
return unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_],a[a5_],a[a6_],a[a7_]);
}
template<class F,class A> void operator()(type<void>,F&f,A&a,int)
{
unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_],a[a5_],a[a6_],a[a7_]);
}
template<class F,class A> void operator()(type<void>,F const&f,A&a,int) const
{
unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_],a[a5_],a[a6_],a[a7_]);
}
template<class V> void accept(V&v) const
{
BOOST_BIND_VISIT_EACH(v,a1_,0);
BOOST_BIND_VISIT_EACH(v,a2_,0);
BOOST_BIND_VISIT_EACH(v,a3_,0);
BOOST_BIND_VISIT_EACH(v,a4_,0);
BOOST_BIND_VISIT_EACH(v,a5_,0);
BOOST_BIND_VISIT_EACH(v,a6_,0);
BOOST_BIND_VISIT_EACH(v,a7_,0);
}
bool operator==(list7 const&rhs) const
{
return
ref_compare(a1_,rhs.a1_,0)&&ref_compare(a2_,rhs.a2_,0)&&ref_compare(a3_,rhs.a3_,0)&&
ref_compare(a4_,rhs.a4_,0)&&ref_compare(a5_,rhs.a5_,0)&&ref_compare(a6_,rhs.a6_,0)&&
ref_compare(a7_,rhs.a7_,0);
}
private:
A1 a1_;
A2 a2_;
A3 a3_;
A4 a4_;
A5 a5_;
A6 a6_;
A7 a7_;
};
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> class list8
{
public:
list8(A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8):a1_(a1),a2_(a2),a3_(a3),a4_(a4),a5_(a5),a6_(a6),a7_(a7),a8_(a8){}
A1 operator[](boost::arg<1>) const{return a1_;}
A2 operator[](boost::arg<2>) const{return a2_;}
A3 operator[](boost::arg<3>) const{return a3_;}
A4 operator[](boost::arg<4>) const{return a4_;}
A5 operator[](boost::arg<5>) const{return a5_;}
A6 operator[](boost::arg<6>) const{return a6_;}
A7 operator[](boost::arg<7>) const{return a7_;}
A8 operator[](boost::arg<8>) const{return a8_;}
A1 operator[](boost::arg<1>(*)()) const{return a1_;}
A2 operator[](boost::arg<2>(*)()) const{return a2_;}
A3 operator[](boost::arg<3>(*)()) const{return a3_;}
A4 operator[](boost::arg<4>(*)()) const{return a4_;}
A5 operator[](boost::arg<5>(*)()) const{return a5_;}
A6 operator[](boost::arg<6>(*)()) const{return a6_;}
A7 operator[](boost::arg<7>(*)()) const{return a7_;}
A8 operator[](boost::arg<8>(*)()) const{return a8_;}
template<class T> T&operator[](_bi::value<T>&v) const{return v.get();}
template<class T> T const&operator[](_bi::value<T> const&v) const{return v.get();}
template<class T> T&operator[](reference_wrapper<T> const&v) const{return v.get();}
template<class R,class F,class L> typename result_traits<R,F>::type operator[](bind_t<R,F,L>&b) const{return b.eval(*this);}
template<class R,class F,class L> typename result_traits<R,F>::type operator[](bind_t<R,F,L> const&b) const{return b.eval(*this);}
template<class R,class F,class A> R operator()(type<R>,F&f,A&a,long)
{
return unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_],a[a5_],a[a6_],a[a7_],a[a8_]);
}
template<class R,class F,class A> R operator()(type<R>,F const&f,A&a,long) const
{
return unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_],a[a5_],a[a6_],a[a7_],a[a8_]);
}
template<class F,class A> void operator()(type<void>,F&f,A&a,int)
{
unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_],a[a5_],a[a6_],a[a7_],a[a8_]);
}
template<class F,class A> void operator()(type<void>,F const&f,A&a,int) const
{
unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_],a[a5_],a[a6_],a[a7_],a[a8_]);
}
template<class V> void accept(V&v) const
{
BOOST_BIND_VISIT_EACH(v,a1_,0);
BOOST_BIND_VISIT_EACH(v,a2_,0);
BOOST_BIND_VISIT_EACH(v,a3_,0);
BOOST_BIND_VISIT_EACH(v,a4_,0);
BOOST_BIND_VISIT_EACH(v,a5_,0);
BOOST_BIND_VISIT_EACH(v,a6_,0);
BOOST_BIND_VISIT_EACH(v,a7_,0);
BOOST_BIND_VISIT_EACH(v,a8_,0);
}
bool operator==(list8 const&rhs) const
{
return
ref_compare(a1_,rhs.a1_,0)&&ref_compare(a2_,rhs.a2_,0)&&ref_compare(a3_,rhs.a3_,0)&&
ref_compare(a4_,rhs.a4_,0)&&ref_compare(a5_,rhs.a5_,0)&&ref_compare(a6_,rhs.a6_,0)&&
ref_compare(a7_,rhs.a7_,0)&&ref_compare(a8_,rhs.a8_,0);
}
private:
A1 a1_;
A2 a2_;
A3 a3_;
A4 a4_;
A5 a5_;
A6 a6_;
A7 a7_;
A8 a8_;
};
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9> class list9
{
public:
list9(A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8,A9 a9):a1_(a1),a2_(a2),a3_(a3),a4_(a4),a5_(a5),a6_(a6),a7_(a7),a8_(a8),a9_(a9){}
A1 operator[](boost::arg<1>) const{return a1_;}
A2 operator[](boost::arg<2>) const{return a2_;}
A3 operator[](boost::arg<3>) const{return a3_;}
A4 operator[](boost::arg<4>) const{return a4_;}
A5 operator[](boost::arg<5>) const{return a5_;}
A6 operator[](boost::arg<6>) const{return a6_;}
A7 operator[](boost::arg<7>) const{return a7_;}
A8 operator[](boost::arg<8>) const{return a8_;}
A9 operator[](boost::arg<9>) const{return a9_;}
A1 operator[](boost::arg<1>(*)()) const{return a1_;}
A2 operator[](boost::arg<2>(*)()) const{return a2_;}
A3 operator[](boost::arg<3>(*)()) const{return a3_;}
A4 operator[](boost::arg<4>(*)()) const{return a4_;}
A5 operator[](boost::arg<5>(*)()) const{return a5_;}
A6 operator[](boost::arg<6>(*)()) const{return a6_;}
A7 operator[](boost::arg<7>(*)()) const{return a7_;}
A8 operator[](boost::arg<8>(*)()) const{return a8_;}
A9 operator[](boost::arg<9>(*)()) const{return a9_;}
template<class T> T&operator[](_bi::value<T>&v) const{return v.get();}
template<class T> T const&operator[](_bi::value<T> const&v) const{return v.get();}
template<class T> T&operator[](reference_wrapper<T> const&v) const{return v.get();}
template<class R,class F,class L> typename result_traits<R,F>::type operator[](bind_t<R,F,L>&b) const{return b.eval(*this);}
template<class R,class F,class L> typename result_traits<R,F>::type operator[](bind_t<R,F,L> const&b) const{return b.eval(*this);}
template<class R,class F,class A> R operator()(type<R>,F&f,A&a,long)
{
return unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_],a[a5_],a[a6_],a[a7_],a[a8_],a[a9_]);
}
template<class R,class F,class A> R operator()(type<R>,F const&f,A&a,long) const
{
return unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_],a[a5_],a[a6_],a[a7_],a[a8_],a[a9_]);
}
template<class F,class A> void operator()(type<void>,F&f,A&a,int)
{
unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_],a[a5_],a[a6_],a[a7_],a[a8_],a[a9_]);
}
template<class F,class A> void operator()(type<void>,F const&f,A&a,int) const
{
unwrap(&f,0)(a[a1_],a[a2_],a[a3_],a[a4_],a[a5_],a[a6_],a[a7_],a[a8_],a[a9_]);
}
template<class V> void accept(V&v) const
{
BOOST_BIND_VISIT_EACH(v,a1_,0);
BOOST_BIND_VISIT_EACH(v,a2_,0);
BOOST_BIND_VISIT_EACH(v,a3_,0);
BOOST_BIND_VISIT_EACH(v,a4_,0);
BOOST_BIND_VISIT_EACH(v,a5_,0);
BOOST_BIND_VISIT_EACH(v,a6_,0);
BOOST_BIND_VISIT_EACH(v,a7_,0);
BOOST_BIND_VISIT_EACH(v,a8_,0);
BOOST_BIND_VISIT_EACH(v,a9_,0);
}
bool operator==(list9 const&rhs) const
{
return
ref_compare(a1_,rhs.a1_,0)&&ref_compare(a2_,rhs.a2_,0)&&ref_compare(a3_,rhs.a3_,0)&&
ref_compare(a4_,rhs.a4_,0)&&ref_compare(a5_,rhs.a5_,0)&&ref_compare(a6_,rhs.a6_,0)&&
ref_compare(a7_,rhs.a7_,0)&&ref_compare(a8_,rhs.a8_,0)&&ref_compare(a9_,rhs.a9_,0);
}
private:
A1 a1_;
A2 a2_;
A3 a3_;
A4 a4_;
A5 a5_;
A6 a6_;
A7 a7_;
A8 a8_;
A9 a9_;
};
#ifndef BOOST_NO_VOID_RETURNS
template<class R,class F,class L> class bind_t
{
public:
typedef bind_t this_type;
bind_t(F f,L const&l):f_(f),l_(l){}
#define BOOST_BIND_RETURN return
typedef typename result_traits<R,F>::type result_type;
result_type operator()()
{
list0 a;
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
result_type operator()() const
{
list0 a;
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1> result_type operator()(A1&a1)
{
list1<A1&> a(a1);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1> result_type operator()(A1&a1) const
{
list1<A1&> a(a1);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2> result_type operator()(A1&a1,A2&a2)
{
list2<A1&,A2&> a(a1,a2);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2> result_type operator()(A1&a1,A2&a2) const
{
list2<A1&,A2&> a(a1,a2);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3> result_type operator()(A1&a1,A2&a2,A3&a3)
{
list3<A1&,A2&,A3&> a(a1,a2,a3);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3> result_type operator()(A1&a1,A2&a2,A3&a3) const
{
list3<A1&,A2&,A3&> a(a1,a2,a3);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4)
{
list4<A1&,A2&,A3&,A4&> a(a1,a2,a3,a4);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4) const
{
list4<A1&,A2&,A3&,A4&> a(a1,a2,a3,a4);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5)
{
list5<A1&,A2&,A3&,A4&,A5&> a(a1,a2,a3,a4,a5);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5) const
{
list5<A1&,A2&,A3&,A4&,A5&> a(a1,a2,a3,a4,a5);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6)
{
list6<A1&,A2&,A3&,A4&,A5&,A6&> a(a1,a2,a3,a4,a5,a6);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6) const
{
list6<A1&,A2&,A3&,A4&,A5&,A6&> a(a1,a2,a3,a4,a5,a6);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7)
{
list7<A1&,A2&,A3&,A4&,A5&,A6&,A7&> a(a1,a2,a3,a4,a5,a6,a7);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7) const
{
list7<A1&,A2&,A3&,A4&,A5&,A6&,A7&> a(a1,a2,a3,a4,a5,a6,a7);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7,A8&a8)
{
list8<A1&,A2&,A3&,A4&,A5&,A6&,A7&,A8&> a(a1,a2,a3,a4,a5,a6,a7,a8);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7,A8&a8) const
{
list8<A1&,A2&,A3&,A4&,A5&,A6&,A7&,A8&> a(a1,a2,a3,a4,a5,a6,a7,a8);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7,A8&a8,A9&a9)
{
list9<A1&,A2&,A3&,A4&,A5&,A6&,A7&,A8&,A9&> a(a1,a2,a3,a4,a5,a6,a7,a8,a9);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7,A8&a8,A9&a9) const
{
list9<A1&,A2&,A3&,A4&,A5&,A6&,A7&,A8&,A9&> a(a1,a2,a3,a4,a5,a6,a7,a8,a9);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A> result_type eval(A&a)
{
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A> result_type eval(A&a) const
{
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class V> void accept(V&v) const
{
BOOST_BIND_VISIT_EACH(v,f_,0);
l_.accept(v);
}
bool compare(this_type const&rhs) const
{
return ref_compare(f_,rhs.f_,0)&&l_==rhs.l_;
}
private:
F f_;
L l_;
#undef BOOST_BIND_RETURN
};
#else
template<class R> struct bind_t_generator
{
template<class F,class L> class implementation
{
public:
typedef implementation this_type;
implementation(F f,L const&l):f_(f),l_(l){}
#define BOOST_BIND_RETURN return
typedef typename result_traits<R,F>::type result_type;
result_type operator()()
{
list0 a;
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
result_type operator()() const
{
list0 a;
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1> result_type operator()(A1&a1)
{
list1<A1&> a(a1);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1> result_type operator()(A1&a1) const
{
list1<A1&> a(a1);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2> result_type operator()(A1&a1,A2&a2)
{
list2<A1&,A2&> a(a1,a2);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2> result_type operator()(A1&a1,A2&a2) const
{
list2<A1&,A2&> a(a1,a2);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3> result_type operator()(A1&a1,A2&a2,A3&a3)
{
list3<A1&,A2&,A3&> a(a1,a2,a3);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3> result_type operator()(A1&a1,A2&a2,A3&a3) const
{
list3<A1&,A2&,A3&> a(a1,a2,a3);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4)
{
list4<A1&,A2&,A3&,A4&> a(a1,a2,a3,a4);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4) const
{
list4<A1&,A2&,A3&,A4&> a(a1,a2,a3,a4);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5)
{
list5<A1&,A2&,A3&,A4&,A5&> a(a1,a2,a3,a4,a5);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5) const
{
list5<A1&,A2&,A3&,A4&,A5&> a(a1,a2,a3,a4,a5);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6)
{
list6<A1&,A2&,A3&,A4&,A5&,A6&> a(a1,a2,a3,a4,a5,a6);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6) const
{
list6<A1&,A2&,A3&,A4&,A5&,A6&> a(a1,a2,a3,a4,a5,a6);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7)
{
list7<A1&,A2&,A3&,A4&,A5&,A6&,A7&> a(a1,a2,a3,a4,a5,a6,a7);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7) const
{
list7<A1&,A2&,A3&,A4&,A5&,A6&,A7&> a(a1,a2,a3,a4,a5,a6,a7);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7,A8&a8)
{
list8<A1&,A2&,A3&,A4&,A5&,A6&,A7&,A8&> a(a1,a2,a3,a4,a5,a6,a7,a8);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7,A8&a8) const
{
list8<A1&,A2&,A3&,A4&,A5&,A6&,A7&,A8&> a(a1,a2,a3,a4,a5,a6,a7,a8);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7,A8&a8,A9&a9)
{
list9<A1&,A2&,A3&,A4&,A5&,A6&,A7&,A8&,A9&> a(a1,a2,a3,a4,a5,a6,a7,a8,a9);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7,A8&a8,A9&a9) const
{
list9<A1&,A2&,A3&,A4&,A5&,A6&,A7&,A8&,A9&> a(a1,a2,a3,a4,a5,a6,a7,a8,a9);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A> result_type eval(A&a)
{
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A> result_type eval(A&a) const
{
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class V> void accept(V&v) const
{
BOOST_BIND_VISIT_EACH(v,f_,0);
l_.accept(v);
}
bool compare(this_type const&rhs) const
{
return ref_compare(f_,rhs.f_,0)&&l_==rhs.l_;
}
private:
F f_;
L l_;
#undef BOOST_BIND_RETURN
};
};
template<> struct bind_t_generator<void>
{
template<class F,class L> class implementation
{
private:
typedef void R;
public:
typedef implementation this_type;
implementation(F f,L const&l):f_(f),l_(l){}
#define BOOST_BIND_RETURN
typedef typename result_traits<R,F>::type result_type;
result_type operator()()
{
list0 a;
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
result_type operator()() const
{
list0 a;
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1> result_type operator()(A1&a1)
{
list1<A1&> a(a1);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1> result_type operator()(A1&a1) const
{
list1<A1&> a(a1);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2> result_type operator()(A1&a1,A2&a2)
{
list2<A1&,A2&> a(a1,a2);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2> result_type operator()(A1&a1,A2&a2) const
{
list2<A1&,A2&> a(a1,a2);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3> result_type operator()(A1&a1,A2&a2,A3&a3)
{
list3<A1&,A2&,A3&> a(a1,a2,a3);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3> result_type operator()(A1&a1,A2&a2,A3&a3) const
{
list3<A1&,A2&,A3&> a(a1,a2,a3);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4)
{
list4<A1&,A2&,A3&,A4&> a(a1,a2,a3,a4);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4) const
{
list4<A1&,A2&,A3&,A4&> a(a1,a2,a3,a4);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5)
{
list5<A1&,A2&,A3&,A4&,A5&> a(a1,a2,a3,a4,a5);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5) const
{
list5<A1&,A2&,A3&,A4&,A5&> a(a1,a2,a3,a4,a5);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6)
{
list6<A1&,A2&,A3&,A4&,A5&,A6&> a(a1,a2,a3,a4,a5,a6);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6) const
{
list6<A1&,A2&,A3&,A4&,A5&,A6&> a(a1,a2,a3,a4,a5,a6);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7)
{
list7<A1&,A2&,A3&,A4&,A5&,A6&,A7&> a(a1,a2,a3,a4,a5,a6,a7);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7) const
{
list7<A1&,A2&,A3&,A4&,A5&,A6&,A7&> a(a1,a2,a3,a4,a5,a6,a7);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7,A8&a8)
{
list8<A1&,A2&,A3&,A4&,A5&,A6&,A7&,A8&> a(a1,a2,a3,a4,a5,a6,a7,a8);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7,A8&a8) const
{
list8<A1&,A2&,A3&,A4&,A5&,A6&,A7&,A8&> a(a1,a2,a3,a4,a5,a6,a7,a8);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7,A8&a8,A9&a9)
{
list9<A1&,A2&,A3&,A4&,A5&,A6&,A7&,A8&,A9&> a(a1,a2,a3,a4,a5,a6,a7,a8,a9);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9> result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7,A8&a8,A9&a9) const
{
list9<A1&,A2&,A3&,A4&,A5&,A6&,A7&,A8&,A9&> a(a1,a2,a3,a4,a5,a6,a7,a8,a9);
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A> result_type eval(A&a)
{
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class A> result_type eval(A&a) const
{
BOOST_BIND_RETURN l_(type<result_type>(),f_,a,0);
}
template<class V> void accept(V&v) const
{
BOOST_BIND_VISIT_EACH(v,f_,0);
l_.accept(v);
}
bool compare(this_type const&rhs) const
{
return ref_compare(f_,rhs.f_,0)&&l_==rhs.l_;
}
private:
F f_;
L l_;
#undef BOOST_BIND_RETURN
};
};
template<class R2,class F,class L> class bind_t:public bind_t_generator<R2>::BOOST_NESTED_TEMPLATE implementation<F,L>
{
public:
bind_t(F f,L const&l):bind_t_generator<R2>::BOOST_NESTED_TEMPLATE implementation<F,L>(f,l){}
};
#endif
#ifndef BOOST_NO_ARGUMENT_DEPENDENT_LOOKUP
# ifndef BOOST_NO_FUNCTION_TEMPLATE_ORDERING
template<class R,class F,class L> bool function_equal(bind_t<R,F,L> const&a,bind_t<R,F,L> const&b)
{
return a.compare(b);
}
# else
template<class R,class F,class L> bool function_equal_impl(bind_t<R,F,L> const&a,bind_t<R,F,L> const&b,int)
{
return a.compare(b);
}
# endif
#else
}
# ifndef BOOST_NO_FUNCTION_TEMPLATE_ORDERING
template<class R,class F,class L> bool function_equal(_bi::bind_t<R,F,L> const&a,_bi::bind_t<R,F,L> const&b)
{
return a.compare(b);
}
# else
template<class R,class F,class L> bool function_equal_impl(_bi::bind_t<R,F,L> const&a,_bi::bind_t<R,F,L> const&b,int)
{
return a.compare(b);
}
# endif
namespace _bi
{
#endif
#if !defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) || (__SUNPRO_CC >= 0x530)
template<class T> struct add_value
{
typedef _bi::value<T> type;
};
template<class T> struct add_value< value<T> >
{
typedef _bi::value<T> type;
};
template<class T> struct add_value< reference_wrapper<T> >
{
typedef reference_wrapper<T> type;
};
template<int I> struct add_value< arg<I> >
{
typedef boost::arg<I> type;
};
template<int I> struct add_value< arg<I>(*)()>
{
typedef boost::arg<I>(*type)();
};
template<class R,class F,class L> struct add_value< bind_t<R,F,L> >
{
typedef bind_t<R,F,L> type;
};
#else
template<int I> struct _avt_0;
template<> struct _avt_0<1>
{
template<class T> struct inner
{
typedef T type;
};
};
template<> struct _avt_0<2>
{
template<class T> struct inner
{
typedef value<T> type;
};
};
typedef char(&_avt_r1)[1];
typedef char(&_avt_r2)[2];
template<class T> _avt_r1 _avt_f(value<T>);
template<class T> _avt_r1 _avt_f(reference_wrapper<T>);
template<int I> _avt_r1 _avt_f(arg<I>);
template<int I> _avt_r1 _avt_f(arg<I>(*)());
template<class R,class F,class L> _avt_r1 _avt_f(bind_t<R,F,L>);
_avt_r2 _avt_f(...);
template<class T> struct add_value
{
static T t();
typedef typename _avt_0<sizeof(_avt_f(t()))>::template inner<T>::type type;
};
#endif
template<class A1> struct list_av_1
{
typedef typename add_value<A1>::type B1;
typedef list1<B1> type;
};
template<class A1,class A2> struct list_av_2
{
typedef typename add_value<A1>::type B1;
typedef typename add_value<A2>::type B2;
typedef list2<B1,B2> type;
};
template<class A1,class A2,class A3> struct list_av_3
{
typedef typename add_value<A1>::type B1;
typedef typename add_value<A2>::type B2;
typedef typename add_value<A3>::type B3;
typedef list3<B1,B2,B3> type;
};
template<class A1,class A2,class A3,class A4> struct list_av_4
{
typedef typename add_value<A1>::type B1;
typedef typename add_value<A2>::type B2;
typedef typename add_value<A3>::type B3;
typedef typename add_value<A4>::type B4;
typedef list4<B1,B2,B3,B4> type;
};
template<class A1,class A2,class A3,class A4,class A5> struct list_av_5
{
typedef typename add_value<A1>::type B1;
typedef typename add_value<A2>::type B2;
typedef typename add_value<A3>::type B3;
typedef typename add_value<A4>::type B4;
typedef typename add_value<A5>::type B5;
typedef list5<B1,B2,B3,B4,B5> type;
};
template<class A1,class A2,class A3,class A4,class A5,class A6> struct list_av_6
{
typedef typename add_value<A1>::type B1;
typedef typename add_value<A2>::type B2;
typedef typename add_value<A3>::type B3;
typedef typename add_value<A4>::type B4;
typedef typename add_value<A5>::type B5;
typedef typename add_value<A6>::type B6;
typedef list6<B1,B2,B3,B4,B5,B6> type;
};
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7> struct list_av_7
{
typedef typename add_value<A1>::type B1;
typedef typename add_value<A2>::type B2;
typedef typename add_value<A3>::type B3;
typedef typename add_value<A4>::type B4;
typedef typename add_value<A5>::type B5;
typedef typename add_value<A6>::type B6;
typedef typename add_value<A7>::type B7;
typedef list7<B1,B2,B3,B4,B5,B6,B7> type;
};
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8> struct list_av_8
{
typedef typename add_value<A1>::type B1;
typedef typename add_value<A2>::type B2;
typedef typename add_value<A3>::type B3;
typedef typename add_value<A4>::type B4;
typedef typename add_value<A5>::type B5;
typedef typename add_value<A6>::type B6;
typedef typename add_value<A7>::type B7;
typedef typename add_value<A8>::type B8;
typedef list8<B1,B2,B3,B4,B5,B6,B7,B8> type;
};
template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9> struct list_av_9
{
typedef typename add_value<A1>::type B1;
typedef typename add_value<A2>::type B2;
typedef typename add_value<A3>::type B3;
typedef typename add_value<A4>::type B4;
typedef typename add_value<A5>::type B5;
typedef typename add_value<A6>::type B6;
typedef typename add_value<A7>::type B7;
typedef typename add_value<A8>::type B8;
typedef typename add_value<A9>::type B9;
typedef list9<B1,B2,B3,B4,B5,B6,B7,B8,B9> type;
};
struct logical_not
{
template<class V> bool operator()(V const&v) const{return !v;}
};
template<class R,class F,class L>
bind_t< bool,logical_not,list1< bind_t<R,F,L> > >
operator!(bind_t<R,F,L> const&f)
{
typedef list1< bind_t<R,F,L> > list_type;
return bind_t<bool,logical_not,list_type>(logical_not(),list_type(f));
}
#define BOOST_BIND_OPERATOR( op, name ) \
\
struct name \
{ \
template<class V, class W> bool operator()(V const & v, W const & w) const { return v op w; } \
}; \
\
template<class R, class F, class L, class A2> \
bind_t< bool, name, list2< bind_t<R, F, L>, typename add_value<A2>::type > > \
operator op (bind_t<R, F, L> const & f, A2 a2) \
{ \
typedef typename add_value<A2>::type B2; \
typedef list2< bind_t<R, F, L>, B2> list_type; \
return bind_t<bool, name, list_type> ( name(), list_type(f, a2) ); \
}
BOOST_BIND_OPERATOR(==,equal)
BOOST_BIND_OPERATOR(!=,not_equal)
BOOST_BIND_OPERATOR(<,less)
BOOST_BIND_OPERATOR(<=,less_equal)
BOOST_BIND_OPERATOR(>,greater)
BOOST_BIND_OPERATOR(>=,greater_equal)
#undef BOOST_BIND_OPERATOR
#if defined(__GNUC__) && BOOST_WORKAROUND(__GNUC__, < 3)
#define BOOST_BIND_OPERATOR( op, name ) \
\
template<class R, class F, class L> \
bind_t< bool, name, list2< bind_t<R, F, L>, bind_t<R, F, L> > > \
operator op (bind_t<R, F, L> const & f, bind_t<R, F, L> const & g) \
{ \
typedef list2< bind_t<R, F, L>, bind_t<R, F, L> > list_type; \
return bind_t<bool, name, list_type> ( name(), list_type(f, g) ); \
}
BOOST_BIND_OPERATOR(!=,not_equal)
BOOST_BIND_OPERATOR(<=,less_equal)
BOOST_BIND_OPERATOR(>,greater)
BOOST_BIND_OPERATOR(>=,greater_equal)
#endif
}
template<class V,class T> void visit_each(V&v,_bi::value<T> const&t,int)
{
BOOST_BIND_VISIT_EACH(v,t.get(),0);
}
template<class V,class R,class F,class L> void visit_each(V&v,_bi::bind_t<R,F,L> const&t,int)
{
t.accept(v);
}
#ifndef BOOST_BIND
#define BOOST_BIND bind
#endif
template<class R,class F>
_bi::bind_t<R,F,_bi::list0>
BOOST_BIND(F f)
{
typedef _bi::list0 list_type;
return _bi::bind_t<R,F,list_type>(f,list_type());
}
template<class R,class F,class A1>
_bi::bind_t<R,F,typename _bi::list_av_1<A1>::type>
BOOST_BIND(F f,A1 a1)
{
typedef typename _bi::list_av_1<A1>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1));
}
template<class R,class F,class A1,class A2>
_bi::bind_t<R,F,typename _bi::list_av_2<A1,A2>::type>
BOOST_BIND(F f,A1 a1,A2 a2)
{
typedef typename _bi::list_av_2<A1,A2>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2));
}
template<class R,class F,class A1,class A2,class A3>
_bi::bind_t<R,F,typename _bi::list_av_3<A1,A2,A3>::type>
BOOST_BIND(F f,A1 a1,A2 a2,A3 a3)
{
typedef typename _bi::list_av_3<A1,A2,A3>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3));
}
template<class R,class F,class A1,class A2,class A3,class A4>
_bi::bind_t<R,F,typename _bi::list_av_4<A1,A2,A3,A4>::type>
BOOST_BIND(F f,A1 a1,A2 a2,A3 a3,A4 a4)
{
typedef typename _bi::list_av_4<A1,A2,A3,A4>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4));
}
template<class R,class F,class A1,class A2,class A3,class A4,class A5>
_bi::bind_t<R,F,typename _bi::list_av_5<A1,A2,A3,A4,A5>::type>
BOOST_BIND(F f,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5)
{
typedef typename _bi::list_av_5<A1,A2,A3,A4,A5>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5));
}
template<class R,class F,class A1,class A2,class A3,class A4,class A5,class A6>
_bi::bind_t<R,F,typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type>
BOOST_BIND(F f,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6)
{
typedef typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6));
}
template<class R,class F,class A1,class A2,class A3,class A4,class A5,class A6,class A7>
_bi::bind_t<R,F,typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type>
BOOST_BIND(F f,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7)
{
typedef typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6,a7));
}
template<class R,class F,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8>
_bi::bind_t<R,F,typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type>
BOOST_BIND(F f,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8)
{
typedef typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6,a7,a8));
}
template<class R,class F,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9>
_bi::bind_t<R,F,typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type>
BOOST_BIND(F f,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8,A9 a9)
{
typedef typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6,a7,a8,a9));
}
template<class R,class F>
_bi::bind_t<R,F,_bi::list0>
BOOST_BIND(boost::type<R>,F f)
{
typedef _bi::list0 list_type;
return _bi::bind_t<R,F,list_type>(f,list_type());
}
template<class R,class F,class A1>
_bi::bind_t<R,F,typename _bi::list_av_1<A1>::type>
BOOST_BIND(boost::type<R>,F f,A1 a1)
{
typedef typename _bi::list_av_1<A1>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1));
}
template<class R,class F,class A1,class A2>
_bi::bind_t<R,F,typename _bi::list_av_2<A1,A2>::type>
BOOST_BIND(boost::type<R>,F f,A1 a1,A2 a2)
{
typedef typename _bi::list_av_2<A1,A2>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2));
}
template<class R,class F,class A1,class A2,class A3>
_bi::bind_t<R,F,typename _bi::list_av_3<A1,A2,A3>::type>
BOOST_BIND(boost::type<R>,F f,A1 a1,A2 a2,A3 a3)
{
typedef typename _bi::list_av_3<A1,A2,A3>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3));
}
template<class R,class F,class A1,class A2,class A3,class A4>
_bi::bind_t<R,F,typename _bi::list_av_4<A1,A2,A3,A4>::type>
BOOST_BIND(boost::type<R>,F f,A1 a1,A2 a2,A3 a3,A4 a4)
{
typedef typename _bi::list_av_4<A1,A2,A3,A4>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4));
}
template<class R,class F,class A1,class A2,class A3,class A4,class A5>
_bi::bind_t<R,F,typename _bi::list_av_5<A1,A2,A3,A4,A5>::type>
BOOST_BIND(boost::type<R>,F f,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5)
{
typedef typename _bi::list_av_5<A1,A2,A3,A4,A5>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5));
}
template<class R,class F,class A1,class A2,class A3,class A4,class A5,class A6>
_bi::bind_t<R,F,typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type>
BOOST_BIND(boost::type<R>,F f,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6)
{
typedef typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6));
}
template<class R,class F,class A1,class A2,class A3,class A4,class A5,class A6,class A7>
_bi::bind_t<R,F,typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type>
BOOST_BIND(boost::type<R>,F f,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7)
{
typedef typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6,a7));
}
template<class R,class F,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8>
_bi::bind_t<R,F,typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type>
BOOST_BIND(boost::type<R>,F f,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8)
{
typedef typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6,a7,a8));
}
template<class R,class F,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9>
_bi::bind_t<R,F,typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type>
BOOST_BIND(boost::type<R>,F f,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8,A9 a9)
{
typedef typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6,a7,a8,a9));
}
#if !defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) && !defined(BOOST_NO_FUNCTION_TEMPLATE_ORDERING)
template<class F>
_bi::bind_t<_bi::unspecified,F,_bi::list0>
BOOST_BIND(F f)
{
typedef _bi::list0 list_type;
return _bi::bind_t<_bi::unspecified,F,list_type>(f,list_type());
}
template<class F,class A1>
_bi::bind_t<_bi::unspecified,F,typename _bi::list_av_1<A1>::type>
BOOST_BIND(F f,A1 a1)
{
typedef typename _bi::list_av_1<A1>::type list_type;
return _bi::bind_t<_bi::unspecified,F,list_type>(f,list_type(a1));
}
template<class F,class A1,class A2>
_bi::bind_t<_bi::unspecified,F,typename _bi::list_av_2<A1,A2>::type>
BOOST_BIND(F f,A1 a1,A2 a2)
{
typedef typename _bi::list_av_2<A1,A2>::type list_type;
return _bi::bind_t<_bi::unspecified,F,list_type>(f,list_type(a1,a2));
}
template<class F,class A1,class A2,class A3>
_bi::bind_t<_bi::unspecified,F,typename _bi::list_av_3<A1,A2,A3>::type>
BOOST_BIND(F f,A1 a1,A2 a2,A3 a3)
{
typedef typename _bi::list_av_3<A1,A2,A3>::type list_type;
return _bi::bind_t<_bi::unspecified,F,list_type>(f,list_type(a1,a2,a3));
}
template<class F,class A1,class A2,class A3,class A4>
_bi::bind_t<_bi::unspecified,F,typename _bi::list_av_4<A1,A2,A3,A4>::type>
BOOST_BIND(F f,A1 a1,A2 a2,A3 a3,A4 a4)
{
typedef typename _bi::list_av_4<A1,A2,A3,A4>::type list_type;
return _bi::bind_t<_bi::unspecified,F,list_type>(f,list_type(a1,a2,a3,a4));
}
template<class F,class A1,class A2,class A3,class A4,class A5>
_bi::bind_t<_bi::unspecified,F,typename _bi::list_av_5<A1,A2,A3,A4,A5>::type>
BOOST_BIND(F f,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5)
{
typedef typename _bi::list_av_5<A1,A2,A3,A4,A5>::type list_type;
return _bi::bind_t<_bi::unspecified,F,list_type>(f,list_type(a1,a2,a3,a4,a5));
}
template<class F,class A1,class A2,class A3,class A4,class A5,class A6>
_bi::bind_t<_bi::unspecified,F,typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type>
BOOST_BIND(F f,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6)
{
typedef typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type list_type;
return _bi::bind_t<_bi::unspecified,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6));
}
template<class F,class A1,class A2,class A3,class A4,class A5,class A6,class A7>
_bi::bind_t<_bi::unspecified,F,typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type>
BOOST_BIND(F f,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7)
{
typedef typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type list_type;
return _bi::bind_t<_bi::unspecified,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6,a7));
}
template<class F,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8>
_bi::bind_t<_bi::unspecified,F,typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type>
BOOST_BIND(F f,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8)
{
typedef typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type list_type;
return _bi::bind_t<_bi::unspecified,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6,a7,a8));
}
template<class F,class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9>
_bi::bind_t<_bi::unspecified,F,typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type>
BOOST_BIND(F f,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8,A9 a9)
{
typedef typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type list_type;
return _bi::bind_t<_bi::unspecified,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6,a7,a8,a9));
}
#endif
#define BOOST_BIND_CC
#define BOOST_BIND_ST
template<class R>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(),_bi::list0>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)())
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)();
typedef _bi::list0 list_type;
return _bi::bind_t<R,F,list_type>(f,list_type());
}
template<class R,class B1,class A1>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1),typename _bi::list_av_1<A1>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1),A1 a1)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1);
typedef typename _bi::list_av_1<A1>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1));
}
template<class R,class B1,class B2,class A1,class A2>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2),typename _bi::list_av_2<A1,A2>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2),A1 a1,A2 a2)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2);
typedef typename _bi::list_av_2<A1,A2>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2));
}
template<class R,
class B1,class B2,class B3,
class A1,class A2,class A3>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3),typename _bi::list_av_3<A1,A2,A3>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3),A1 a1,A2 a2,A3 a3)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3);
typedef typename _bi::list_av_3<A1,A2,A3>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3));
}
template<class R,
class B1,class B2,class B3,class B4,
class A1,class A2,class A3,class A4>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4),typename _bi::list_av_4<A1,A2,A3,A4>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4),A1 a1,A2 a2,A3 a3,A4 a4)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4);
typedef typename _bi::list_av_4<A1,A2,A3,A4>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4));
}
template<class R,
class B1,class B2,class B3,class B4,class B5,
class A1,class A2,class A3,class A4,class A5>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4,B5),typename _bi::list_av_5<A1,A2,A3,A4,A5>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4,B5),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4,B5);
typedef typename _bi::list_av_5<A1,A2,A3,A4,A5>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5));
}
template<class R,
class B1,class B2,class B3,class B4,class B5,class B6,
class A1,class A2,class A3,class A4,class A5,class A6>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4,B5,B6),typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4,B5,B6),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4,B5,B6);
typedef typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6));
}
template<class R,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,
class A1,class A2,class A3,class A4,class A5,class A6,class A7>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4,B5,B6,B7),typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4,B5,B6,B7),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4,B5,B6,B7);
typedef typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6,a7));
}
template<class R,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4,B5,B6,B7,B8),typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4,B5,B6,B7,B8),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4,B5,B6,B7,B8);
typedef typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6,a7,a8));
}
template<class R,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8,class B9,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4,B5,B6,B7,B8,B9),typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4,B5,B6,B7,B8,B9),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8,A9 a9)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4,B5,B6,B7,B8,B9);
typedef typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6,a7,a8,a9));
}
#undef BOOST_BIND_CC
#undef BOOST_BIND_ST
#ifdef BOOST_BIND_ENABLE_STDCALL
#define BOOST_BIND_CC __stdcall
#define BOOST_BIND_ST
template<class R>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(),_bi::list0>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)())
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)();
typedef _bi::list0 list_type;
return _bi::bind_t<R,F,list_type>(f,list_type());
}
template<class R,class B1,class A1>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1),typename _bi::list_av_1<A1>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1),A1 a1)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1);
typedef typename _bi::list_av_1<A1>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1));
}
template<class R,class B1,class B2,class A1,class A2>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2),typename _bi::list_av_2<A1,A2>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2),A1 a1,A2 a2)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2);
typedef typename _bi::list_av_2<A1,A2>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2));
}
template<class R,
class B1,class B2,class B3,
class A1,class A2,class A3>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3),typename _bi::list_av_3<A1,A2,A3>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3),A1 a1,A2 a2,A3 a3)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3);
typedef typename _bi::list_av_3<A1,A2,A3>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3));
}
template<class R,
class B1,class B2,class B3,class B4,
class A1,class A2,class A3,class A4>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4),typename _bi::list_av_4<A1,A2,A3,A4>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4),A1 a1,A2 a2,A3 a3,A4 a4)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4);
typedef typename _bi::list_av_4<A1,A2,A3,A4>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4));
}
template<class R,
class B1,class B2,class B3,class B4,class B5,
class A1,class A2,class A3,class A4,class A5>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4,B5),typename _bi::list_av_5<A1,A2,A3,A4,A5>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4,B5),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4,B5);
typedef typename _bi::list_av_5<A1,A2,A3,A4,A5>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5));
}
template<class R,
class B1,class B2,class B3,class B4,class B5,class B6,
class A1,class A2,class A3,class A4,class A5,class A6>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4,B5,B6),typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4,B5,B6),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4,B5,B6);
typedef typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6));
}
template<class R,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,
class A1,class A2,class A3,class A4,class A5,class A6,class A7>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4,B5,B6,B7),typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4,B5,B6,B7),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4,B5,B6,B7);
typedef typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6,a7));
}
template<class R,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4,B5,B6,B7,B8),typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4,B5,B6,B7,B8),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4,B5,B6,B7,B8);
typedef typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6,a7,a8));
}
template<class R,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8,class B9,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4,B5,B6,B7,B8,B9),typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4,B5,B6,B7,B8,B9),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8,A9 a9)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4,B5,B6,B7,B8,B9);
typedef typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6,a7,a8,a9));
}
#undef BOOST_BIND_CC
#undef BOOST_BIND_ST
#endif
#ifdef BOOST_BIND_ENABLE_FASTCALL
#define BOOST_BIND_CC __fastcall
#define BOOST_BIND_ST
template<class R>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(),_bi::list0>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)())
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)();
typedef _bi::list0 list_type;
return _bi::bind_t<R,F,list_type>(f,list_type());
}
template<class R,class B1,class A1>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1),typename _bi::list_av_1<A1>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1),A1 a1)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1);
typedef typename _bi::list_av_1<A1>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1));
}
template<class R,class B1,class B2,class A1,class A2>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2),typename _bi::list_av_2<A1,A2>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2),A1 a1,A2 a2)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2);
typedef typename _bi::list_av_2<A1,A2>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2));
}
template<class R,
class B1,class B2,class B3,
class A1,class A2,class A3>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3),typename _bi::list_av_3<A1,A2,A3>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3),A1 a1,A2 a2,A3 a3)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3);
typedef typename _bi::list_av_3<A1,A2,A3>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3));
}
template<class R,
class B1,class B2,class B3,class B4,
class A1,class A2,class A3,class A4>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4),typename _bi::list_av_4<A1,A2,A3,A4>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4),A1 a1,A2 a2,A3 a3,A4 a4)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4);
typedef typename _bi::list_av_4<A1,A2,A3,A4>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4));
}
template<class R,
class B1,class B2,class B3,class B4,class B5,
class A1,class A2,class A3,class A4,class A5>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4,B5),typename _bi::list_av_5<A1,A2,A3,A4,A5>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4,B5),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4,B5);
typedef typename _bi::list_av_5<A1,A2,A3,A4,A5>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5));
}
template<class R,
class B1,class B2,class B3,class B4,class B5,class B6,
class A1,class A2,class A3,class A4,class A5,class A6>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4,B5,B6),typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4,B5,B6),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4,B5,B6);
typedef typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6));
}
template<class R,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,
class A1,class A2,class A3,class A4,class A5,class A6,class A7>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4,B5,B6,B7),typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4,B5,B6,B7),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4,B5,B6,B7);
typedef typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6,a7));
}
template<class R,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4,B5,B6,B7,B8),typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4,B5,B6,B7,B8),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4,B5,B6,B7,B8);
typedef typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6,a7,a8));
}
template<class R,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8,class B9,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4,B5,B6,B7,B8,B9),typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4,B5,B6,B7,B8,B9),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8,A9 a9)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4,B5,B6,B7,B8,B9);
typedef typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6,a7,a8,a9));
}
#undef BOOST_BIND_CC
#undef BOOST_BIND_ST
#endif
#ifdef BOOST_BIND_ENABLE_PASCAL
#define BOOST_BIND_ST pascal
#define BOOST_BIND_CC
template<class R>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(),_bi::list0>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)())
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)();
typedef _bi::list0 list_type;
return _bi::bind_t<R,F,list_type>(f,list_type());
}
template<class R,class B1,class A1>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1),typename _bi::list_av_1<A1>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1),A1 a1)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1);
typedef typename _bi::list_av_1<A1>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1));
}
template<class R,class B1,class B2,class A1,class A2>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2),typename _bi::list_av_2<A1,A2>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2),A1 a1,A2 a2)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2);
typedef typename _bi::list_av_2<A1,A2>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2));
}
template<class R,
class B1,class B2,class B3,
class A1,class A2,class A3>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3),typename _bi::list_av_3<A1,A2,A3>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3),A1 a1,A2 a2,A3 a3)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3);
typedef typename _bi::list_av_3<A1,A2,A3>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3));
}
template<class R,
class B1,class B2,class B3,class B4,
class A1,class A2,class A3,class A4>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4),typename _bi::list_av_4<A1,A2,A3,A4>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4),A1 a1,A2 a2,A3 a3,A4 a4)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4);
typedef typename _bi::list_av_4<A1,A2,A3,A4>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4));
}
template<class R,
class B1,class B2,class B3,class B4,class B5,
class A1,class A2,class A3,class A4,class A5>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4,B5),typename _bi::list_av_5<A1,A2,A3,A4,A5>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4,B5),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4,B5);
typedef typename _bi::list_av_5<A1,A2,A3,A4,A5>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5));
}
template<class R,
class B1,class B2,class B3,class B4,class B5,class B6,
class A1,class A2,class A3,class A4,class A5,class A6>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4,B5,B6),typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4,B5,B6),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4,B5,B6);
typedef typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6));
}
template<class R,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,
class A1,class A2,class A3,class A4,class A5,class A6,class A7>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4,B5,B6,B7),typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4,B5,B6,B7),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4,B5,B6,B7);
typedef typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6,a7));
}
template<class R,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4,B5,B6,B7,B8),typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4,B5,B6,B7,B8),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4,B5,B6,B7,B8);
typedef typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6,a7,a8));
}
template<class R,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8,class B9,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9>
_bi::bind_t<R,BOOST_BIND_ST R(BOOST_BIND_CC*)(B1,B2,B3,B4,B5,B6,B7,B8,B9),typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type>
BOOST_BIND(BOOST_BIND_ST R(BOOST_BIND_CC*f)(B1,B2,B3,B4,B5,B6,B7,B8,B9),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8,A9 a9)
{
typedef BOOST_BIND_ST R(BOOST_BIND_CC*F)(B1,B2,B3,B4,B5,B6,B7,B8,B9);
typedef typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type list_type;
return _bi::bind_t<R,F,list_type>(f,list_type(a1,a2,a3,a4,a5,a6,a7,a8,a9));
}
#undef BOOST_BIND_ST
#undef BOOST_BIND_CC
#endif
#define BOOST_BIND_MF_NAME(X) X
#define BOOST_BIND_MF_CC
template<class R,class T,
class A1>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf0)<R,T>,typename _bi::list_av_1<A1>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(),A1 a1)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf0)<R,T> F;
typedef typename _bi::list_av_1<A1>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1));
}
template<class R,class T,
class A1>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf0)<R,T>,typename _bi::list_av_1<A1>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)() const,A1 a1)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf0)<R,T> F;
typedef typename _bi::list_av_1<A1>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1));
}
template<class R,class T,
class B1,
class A1,class A2>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf1)<R,T,B1>,typename _bi::list_av_2<A1,A2>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1),A1 a1,A2 a2)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf1)<R,T,B1> F;
typedef typename _bi::list_av_2<A1,A2>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2));
}
template<class R,class T,
class B1,
class A1,class A2>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf1)<R,T,B1>,typename _bi::list_av_2<A1,A2>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1) const,A1 a1,A2 a2)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf1)<R,T,B1> F;
typedef typename _bi::list_av_2<A1,A2>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2));
}
template<class R,class T,
class B1,class B2,
class A1,class A2,class A3>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf2)<R,T,B1,B2>,typename _bi::list_av_3<A1,A2,A3>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2),A1 a1,A2 a2,A3 a3)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf2)<R,T,B1,B2> F;
typedef typename _bi::list_av_3<A1,A2,A3>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3));
}
template<class R,class T,
class B1,class B2,
class A1,class A2,class A3>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf2)<R,T,B1,B2>,typename _bi::list_av_3<A1,A2,A3>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2) const,A1 a1,A2 a2,A3 a3)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf2)<R,T,B1,B2> F;
typedef typename _bi::list_av_3<A1,A2,A3>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3));
}
template<class R,class T,
class B1,class B2,class B3,
class A1,class A2,class A3,class A4>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf3)<R,T,B1,B2,B3>,typename _bi::list_av_4<A1,A2,A3,A4>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3),A1 a1,A2 a2,A3 a3,A4 a4)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf3)<R,T,B1,B2,B3> F;
typedef typename _bi::list_av_4<A1,A2,A3,A4>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4));
}
template<class R,class T,
class B1,class B2,class B3,
class A1,class A2,class A3,class A4>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf3)<R,T,B1,B2,B3>,typename _bi::list_av_4<A1,A2,A3,A4>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3) const,A1 a1,A2 a2,A3 a3,A4 a4)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf3)<R,T,B1,B2,B3> F;
typedef typename _bi::list_av_4<A1,A2,A3,A4>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4));
}
template<class R,class T,
class B1,class B2,class B3,class B4,
class A1,class A2,class A3,class A4,class A5>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf4)<R,T,B1,B2,B3,B4>,typename _bi::list_av_5<A1,A2,A3,A4,A5>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf4)<R,T,B1,B2,B3,B4> F;
typedef typename _bi::list_av_5<A1,A2,A3,A4,A5>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5));
}
template<class R,class T,
class B1,class B2,class B3,class B4,
class A1,class A2,class A3,class A4,class A5>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf4)<R,T,B1,B2,B3,B4>,typename _bi::list_av_5<A1,A2,A3,A4,A5>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4) const,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf4)<R,T,B1,B2,B3,B4> F;
typedef typename _bi::list_av_5<A1,A2,A3,A4,A5>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,
class A1,class A2,class A3,class A4,class A5,class A6>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf5)<R,T,B1,B2,B3,B4,B5>,typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf5)<R,T,B1,B2,B3,B4,B5> F;
typedef typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,
class A1,class A2,class A3,class A4,class A5,class A6>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf5)<R,T,B1,B2,B3,B4,B5>,typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5) const,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf5)<R,T,B1,B2,B3,B4,B5> F;
typedef typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,
class A1,class A2,class A3,class A4,class A5,class A6,class A7>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf6)<R,T,B1,B2,B3,B4,B5,B6>,typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf6)<R,T,B1,B2,B3,B4,B5,B6> F;
typedef typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,
class A1,class A2,class A3,class A4,class A5,class A6,class A7>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf6)<R,T,B1,B2,B3,B4,B5,B6>,typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6) const,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf6)<R,T,B1,B2,B3,B4,B5,B6> F;
typedef typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf7)<R,T,B1,B2,B3,B4,B5,B6,B7>,typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6,B7),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf7)<R,T,B1,B2,B3,B4,B5,B6,B7> F;
typedef typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7,a8));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf7)<R,T,B1,B2,B3,B4,B5,B6,B7>,typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6,B7) const,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf7)<R,T,B1,B2,B3,B4,B5,B6,B7> F;
typedef typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7,a8));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf8)<R,T,B1,B2,B3,B4,B5,B6,B7,B8>,typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6,B7,B8),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8,A9 a9)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf8)<R,T,B1,B2,B3,B4,B5,B6,B7,B8> F;
typedef typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7,a8,a9));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf8)<R,T,B1,B2,B3,B4,B5,B6,B7,B8>,typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6,B7,B8) const,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8,A9 a9)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf8)<R,T,B1,B2,B3,B4,B5,B6,B7,B8> F;
typedef typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7,a8,a9));
}
#undef BOOST_BIND_MF_NAME
#undef BOOST_BIND_MF_CC
#ifdef BOOST_MEM_FN_ENABLE_CDECL
#define BOOST_BIND_MF_NAME(X) X##_cdecl
#define BOOST_BIND_MF_CC __cdecl
template<class R,class T,
class A1>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf0)<R,T>,typename _bi::list_av_1<A1>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(),A1 a1)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf0)<R,T> F;
typedef typename _bi::list_av_1<A1>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1));
}
template<class R,class T,
class A1>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf0)<R,T>,typename _bi::list_av_1<A1>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)() const,A1 a1)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf0)<R,T> F;
typedef typename _bi::list_av_1<A1>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1));
}
template<class R,class T,
class B1,
class A1,class A2>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf1)<R,T,B1>,typename _bi::list_av_2<A1,A2>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1),A1 a1,A2 a2)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf1)<R,T,B1> F;
typedef typename _bi::list_av_2<A1,A2>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2));
}
template<class R,class T,
class B1,
class A1,class A2>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf1)<R,T,B1>,typename _bi::list_av_2<A1,A2>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1) const,A1 a1,A2 a2)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf1)<R,T,B1> F;
typedef typename _bi::list_av_2<A1,A2>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2));
}
template<class R,class T,
class B1,class B2,
class A1,class A2,class A3>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf2)<R,T,B1,B2>,typename _bi::list_av_3<A1,A2,A3>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2),A1 a1,A2 a2,A3 a3)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf2)<R,T,B1,B2> F;
typedef typename _bi::list_av_3<A1,A2,A3>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3));
}
template<class R,class T,
class B1,class B2,
class A1,class A2,class A3>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf2)<R,T,B1,B2>,typename _bi::list_av_3<A1,A2,A3>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2) const,A1 a1,A2 a2,A3 a3)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf2)<R,T,B1,B2> F;
typedef typename _bi::list_av_3<A1,A2,A3>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3));
}
template<class R,class T,
class B1,class B2,class B3,
class A1,class A2,class A3,class A4>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf3)<R,T,B1,B2,B3>,typename _bi::list_av_4<A1,A2,A3,A4>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3),A1 a1,A2 a2,A3 a3,A4 a4)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf3)<R,T,B1,B2,B3> F;
typedef typename _bi::list_av_4<A1,A2,A3,A4>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4));
}
template<class R,class T,
class B1,class B2,class B3,
class A1,class A2,class A3,class A4>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf3)<R,T,B1,B2,B3>,typename _bi::list_av_4<A1,A2,A3,A4>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3) const,A1 a1,A2 a2,A3 a3,A4 a4)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf3)<R,T,B1,B2,B3> F;
typedef typename _bi::list_av_4<A1,A2,A3,A4>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4));
}
template<class R,class T,
class B1,class B2,class B3,class B4,
class A1,class A2,class A3,class A4,class A5>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf4)<R,T,B1,B2,B3,B4>,typename _bi::list_av_5<A1,A2,A3,A4,A5>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf4)<R,T,B1,B2,B3,B4> F;
typedef typename _bi::list_av_5<A1,A2,A3,A4,A5>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5));
}
template<class R,class T,
class B1,class B2,class B3,class B4,
class A1,class A2,class A3,class A4,class A5>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf4)<R,T,B1,B2,B3,B4>,typename _bi::list_av_5<A1,A2,A3,A4,A5>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4) const,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf4)<R,T,B1,B2,B3,B4> F;
typedef typename _bi::list_av_5<A1,A2,A3,A4,A5>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,
class A1,class A2,class A3,class A4,class A5,class A6>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf5)<R,T,B1,B2,B3,B4,B5>,typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf5)<R,T,B1,B2,B3,B4,B5> F;
typedef typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,
class A1,class A2,class A3,class A4,class A5,class A6>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf5)<R,T,B1,B2,B3,B4,B5>,typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5) const,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf5)<R,T,B1,B2,B3,B4,B5> F;
typedef typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,
class A1,class A2,class A3,class A4,class A5,class A6,class A7>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf6)<R,T,B1,B2,B3,B4,B5,B6>,typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf6)<R,T,B1,B2,B3,B4,B5,B6> F;
typedef typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,
class A1,class A2,class A3,class A4,class A5,class A6,class A7>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf6)<R,T,B1,B2,B3,B4,B5,B6>,typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6) const,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf6)<R,T,B1,B2,B3,B4,B5,B6> F;
typedef typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf7)<R,T,B1,B2,B3,B4,B5,B6,B7>,typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6,B7),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf7)<R,T,B1,B2,B3,B4,B5,B6,B7> F;
typedef typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7,a8));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf7)<R,T,B1,B2,B3,B4,B5,B6,B7>,typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6,B7) const,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf7)<R,T,B1,B2,B3,B4,B5,B6,B7> F;
typedef typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7,a8));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf8)<R,T,B1,B2,B3,B4,B5,B6,B7,B8>,typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6,B7,B8),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8,A9 a9)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf8)<R,T,B1,B2,B3,B4,B5,B6,B7,B8> F;
typedef typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7,a8,a9));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf8)<R,T,B1,B2,B3,B4,B5,B6,B7,B8>,typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6,B7,B8) const,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8,A9 a9)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf8)<R,T,B1,B2,B3,B4,B5,B6,B7,B8> F;
typedef typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7,a8,a9));
}
#undef BOOST_BIND_MF_NAME
#undef BOOST_BIND_MF_CC
#endif
#ifdef BOOST_MEM_FN_ENABLE_STDCALL
#define BOOST_BIND_MF_NAME(X) X##_stdcall
#define BOOST_BIND_MF_CC __stdcall
template<class R,class T,
class A1>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf0)<R,T>,typename _bi::list_av_1<A1>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(),A1 a1)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf0)<R,T> F;
typedef typename _bi::list_av_1<A1>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1));
}
template<class R,class T,
class A1>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf0)<R,T>,typename _bi::list_av_1<A1>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)() const,A1 a1)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf0)<R,T> F;
typedef typename _bi::list_av_1<A1>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1));
}
template<class R,class T,
class B1,
class A1,class A2>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf1)<R,T,B1>,typename _bi::list_av_2<A1,A2>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1),A1 a1,A2 a2)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf1)<R,T,B1> F;
typedef typename _bi::list_av_2<A1,A2>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2));
}
template<class R,class T,
class B1,
class A1,class A2>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf1)<R,T,B1>,typename _bi::list_av_2<A1,A2>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1) const,A1 a1,A2 a2)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf1)<R,T,B1> F;
typedef typename _bi::list_av_2<A1,A2>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2));
}
template<class R,class T,
class B1,class B2,
class A1,class A2,class A3>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf2)<R,T,B1,B2>,typename _bi::list_av_3<A1,A2,A3>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2),A1 a1,A2 a2,A3 a3)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf2)<R,T,B1,B2> F;
typedef typename _bi::list_av_3<A1,A2,A3>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3));
}
template<class R,class T,
class B1,class B2,
class A1,class A2,class A3>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf2)<R,T,B1,B2>,typename _bi::list_av_3<A1,A2,A3>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2) const,A1 a1,A2 a2,A3 a3)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf2)<R,T,B1,B2> F;
typedef typename _bi::list_av_3<A1,A2,A3>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3));
}
template<class R,class T,
class B1,class B2,class B3,
class A1,class A2,class A3,class A4>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf3)<R,T,B1,B2,B3>,typename _bi::list_av_4<A1,A2,A3,A4>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3),A1 a1,A2 a2,A3 a3,A4 a4)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf3)<R,T,B1,B2,B3> F;
typedef typename _bi::list_av_4<A1,A2,A3,A4>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4));
}
template<class R,class T,
class B1,class B2,class B3,
class A1,class A2,class A3,class A4>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf3)<R,T,B1,B2,B3>,typename _bi::list_av_4<A1,A2,A3,A4>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3) const,A1 a1,A2 a2,A3 a3,A4 a4)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf3)<R,T,B1,B2,B3> F;
typedef typename _bi::list_av_4<A1,A2,A3,A4>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4));
}
template<class R,class T,
class B1,class B2,class B3,class B4,
class A1,class A2,class A3,class A4,class A5>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf4)<R,T,B1,B2,B3,B4>,typename _bi::list_av_5<A1,A2,A3,A4,A5>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf4)<R,T,B1,B2,B3,B4> F;
typedef typename _bi::list_av_5<A1,A2,A3,A4,A5>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5));
}
template<class R,class T,
class B1,class B2,class B3,class B4,
class A1,class A2,class A3,class A4,class A5>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf4)<R,T,B1,B2,B3,B4>,typename _bi::list_av_5<A1,A2,A3,A4,A5>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4) const,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf4)<R,T,B1,B2,B3,B4> F;
typedef typename _bi::list_av_5<A1,A2,A3,A4,A5>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,
class A1,class A2,class A3,class A4,class A5,class A6>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf5)<R,T,B1,B2,B3,B4,B5>,typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf5)<R,T,B1,B2,B3,B4,B5> F;
typedef typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,
class A1,class A2,class A3,class A4,class A5,class A6>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf5)<R,T,B1,B2,B3,B4,B5>,typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5) const,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf5)<R,T,B1,B2,B3,B4,B5> F;
typedef typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,
class A1,class A2,class A3,class A4,class A5,class A6,class A7>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf6)<R,T,B1,B2,B3,B4,B5,B6>,typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf6)<R,T,B1,B2,B3,B4,B5,B6> F;
typedef typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,
class A1,class A2,class A3,class A4,class A5,class A6,class A7>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf6)<R,T,B1,B2,B3,B4,B5,B6>,typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6) const,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf6)<R,T,B1,B2,B3,B4,B5,B6> F;
typedef typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf7)<R,T,B1,B2,B3,B4,B5,B6,B7>,typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6,B7),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf7)<R,T,B1,B2,B3,B4,B5,B6,B7> F;
typedef typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7,a8));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf7)<R,T,B1,B2,B3,B4,B5,B6,B7>,typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6,B7) const,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf7)<R,T,B1,B2,B3,B4,B5,B6,B7> F;
typedef typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7,a8));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf8)<R,T,B1,B2,B3,B4,B5,B6,B7,B8>,typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6,B7,B8),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8,A9 a9)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf8)<R,T,B1,B2,B3,B4,B5,B6,B7,B8> F;
typedef typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7,a8,a9));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf8)<R,T,B1,B2,B3,B4,B5,B6,B7,B8>,typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6,B7,B8) const,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8,A9 a9)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf8)<R,T,B1,B2,B3,B4,B5,B6,B7,B8> F;
typedef typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7,a8,a9));
}
#undef BOOST_BIND_MF_NAME
#undef BOOST_BIND_MF_CC
#endif
#ifdef BOOST_MEM_FN_ENABLE_FASTCALL
#define BOOST_BIND_MF_NAME(X) X##_fastcall
#define BOOST_BIND_MF_CC __fastcall
template<class R,class T,
class A1>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf0)<R,T>,typename _bi::list_av_1<A1>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(),A1 a1)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf0)<R,T> F;
typedef typename _bi::list_av_1<A1>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1));
}
template<class R,class T,
class A1>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf0)<R,T>,typename _bi::list_av_1<A1>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)() const,A1 a1)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf0)<R,T> F;
typedef typename _bi::list_av_1<A1>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1));
}
template<class R,class T,
class B1,
class A1,class A2>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf1)<R,T,B1>,typename _bi::list_av_2<A1,A2>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1),A1 a1,A2 a2)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf1)<R,T,B1> F;
typedef typename _bi::list_av_2<A1,A2>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2));
}
template<class R,class T,
class B1,
class A1,class A2>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf1)<R,T,B1>,typename _bi::list_av_2<A1,A2>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1) const,A1 a1,A2 a2)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf1)<R,T,B1> F;
typedef typename _bi::list_av_2<A1,A2>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2));
}
template<class R,class T,
class B1,class B2,
class A1,class A2,class A3>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf2)<R,T,B1,B2>,typename _bi::list_av_3<A1,A2,A3>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2),A1 a1,A2 a2,A3 a3)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf2)<R,T,B1,B2> F;
typedef typename _bi::list_av_3<A1,A2,A3>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3));
}
template<class R,class T,
class B1,class B2,
class A1,class A2,class A3>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf2)<R,T,B1,B2>,typename _bi::list_av_3<A1,A2,A3>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2) const,A1 a1,A2 a2,A3 a3)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf2)<R,T,B1,B2> F;
typedef typename _bi::list_av_3<A1,A2,A3>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3));
}
template<class R,class T,
class B1,class B2,class B3,
class A1,class A2,class A3,class A4>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf3)<R,T,B1,B2,B3>,typename _bi::list_av_4<A1,A2,A3,A4>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3),A1 a1,A2 a2,A3 a3,A4 a4)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf3)<R,T,B1,B2,B3> F;
typedef typename _bi::list_av_4<A1,A2,A3,A4>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4));
}
template<class R,class T,
class B1,class B2,class B3,
class A1,class A2,class A3,class A4>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf3)<R,T,B1,B2,B3>,typename _bi::list_av_4<A1,A2,A3,A4>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3) const,A1 a1,A2 a2,A3 a3,A4 a4)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf3)<R,T,B1,B2,B3> F;
typedef typename _bi::list_av_4<A1,A2,A3,A4>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4));
}
template<class R,class T,
class B1,class B2,class B3,class B4,
class A1,class A2,class A3,class A4,class A5>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf4)<R,T,B1,B2,B3,B4>,typename _bi::list_av_5<A1,A2,A3,A4,A5>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf4)<R,T,B1,B2,B3,B4> F;
typedef typename _bi::list_av_5<A1,A2,A3,A4,A5>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5));
}
template<class R,class T,
class B1,class B2,class B3,class B4,
class A1,class A2,class A3,class A4,class A5>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf4)<R,T,B1,B2,B3,B4>,typename _bi::list_av_5<A1,A2,A3,A4,A5>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4) const,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf4)<R,T,B1,B2,B3,B4> F;
typedef typename _bi::list_av_5<A1,A2,A3,A4,A5>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,
class A1,class A2,class A3,class A4,class A5,class A6>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf5)<R,T,B1,B2,B3,B4,B5>,typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf5)<R,T,B1,B2,B3,B4,B5> F;
typedef typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,
class A1,class A2,class A3,class A4,class A5,class A6>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf5)<R,T,B1,B2,B3,B4,B5>,typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5) const,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf5)<R,T,B1,B2,B3,B4,B5> F;
typedef typename _bi::list_av_6<A1,A2,A3,A4,A5,A6>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,
class A1,class A2,class A3,class A4,class A5,class A6,class A7>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf6)<R,T,B1,B2,B3,B4,B5,B6>,typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf6)<R,T,B1,B2,B3,B4,B5,B6> F;
typedef typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,
class A1,class A2,class A3,class A4,class A5,class A6,class A7>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf6)<R,T,B1,B2,B3,B4,B5,B6>,typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6) const,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf6)<R,T,B1,B2,B3,B4,B5,B6> F;
typedef typename _bi::list_av_7<A1,A2,A3,A4,A5,A6,A7>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf7)<R,T,B1,B2,B3,B4,B5,B6,B7>,typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6,B7),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf7)<R,T,B1,B2,B3,B4,B5,B6,B7> F;
typedef typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7,a8));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf7)<R,T,B1,B2,B3,B4,B5,B6,B7>,typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6,B7) const,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf7)<R,T,B1,B2,B3,B4,B5,B6,B7> F;
typedef typename _bi::list_av_8<A1,A2,A3,A4,A5,A6,A7,A8>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7,a8));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(mf8)<R,T,B1,B2,B3,B4,B5,B6,B7,B8>,typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6,B7,B8),A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8,A9 a9)
{
typedef _mfi::BOOST_BIND_MF_NAME(mf8)<R,T,B1,B2,B3,B4,B5,B6,B7,B8> F;
typedef typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7,a8,a9));
}
template<class R,class T,
class B1,class B2,class B3,class B4,class B5,class B6,class B7,class B8,
class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9>
_bi::bind_t<R,_mfi::BOOST_BIND_MF_NAME(cmf8)<R,T,B1,B2,B3,B4,B5,B6,B7,B8>,typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type>
BOOST_BIND(R(BOOST_BIND_MF_CC T::*f)(B1,B2,B3,B4,B5,B6,B7,B8) const,A1 a1,A2 a2,A3 a3,A4 a4,A5 a5,A6 a6,A7 a7,A8 a8,A9 a9)
{
typedef _mfi::BOOST_BIND_MF_NAME(cmf8)<R,T,B1,B2,B3,B4,B5,B6,B7,B8> F;
typedef typename _bi::list_av_9<A1,A2,A3,A4,A5,A6,A7,A8,A9>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4,a5,a6,a7,a8,a9));
}
#undef BOOST_BIND_MF_NAME
#undef BOOST_BIND_MF_CC
#endif
template<class R,class T,class A1>
_bi::bind_t< R,_mfi::dm<R,T>,typename _bi::list_av_1<A1>::type >
BOOST_BIND(R T::*f,A1 a1)
{
typedef _mfi::dm<R,T> F;
typedef typename _bi::list_av_1<A1>::type list_type;
return _bi::bind_t<R,F,list_type>(F(f),list_type(a1));
}
}
#ifndef BOOST_BIND_NO_PLACEHOLDERS
#ifndef BOOST_BIND_PLACEHOLDERS_HPP_INCLUDED
#define BOOST_BIND_PLACEHOLDERS_HPP_INCLUDED
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif
#ifndef BOOST_BIND_ARG_HPP_INCLUDED
#define BOOST_BIND_ARG_HPP_INCLUDED
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif
namespace boost
{
template<int I> class arg
{
};
template<int I> bool operator==(arg<I> const&,arg<I> const&)
{
return true;
}
}
#endif
#include <boost/config.hpp>
namespace
{
#if defined(__BORLANDC__)
static inline boost::arg<1> _1(){return boost::arg<1>();}
static inline boost::arg<2> _2(){return boost::arg<2>();}
static inline boost::arg<3> _3(){return boost::arg<3>();}
static inline boost::arg<4> _4(){return boost::arg<4>();}
static inline boost::arg<5> _5(){return boost::arg<5>();}
static inline boost::arg<6> _6(){return boost::arg<6>();}
static inline boost::arg<7> _7(){return boost::arg<7>();}
static inline boost::arg<8> _8(){return boost::arg<8>();}
static inline boost::arg<9> _9(){return boost::arg<9>();}
#elif defined(BOOST_MSVC) || (defined(__DECCXX_VER) && __DECCXX_VER <= 60590031) || defined(__MWERKS__)
static boost::arg<1> _1;
static boost::arg<2> _2;
static boost::arg<3> _3;
static boost::arg<4> _4;
static boost::arg<5> _5;
static boost::arg<6> _6;
static boost::arg<7> _7;
static boost::arg<8> _8;
static boost::arg<9> _9;
#else
boost::arg<1> _1;
boost::arg<2> _2;
boost::arg<3> _3;
boost::arg<4> _4;
boost::arg<5> _5;
boost::arg<6> _6;
boost::arg<7> _7;
boost::arg<8> _8;
boost::arg<9> _9;
#endif
}
#endif
#endif
#ifdef BOOST_MSVC
# pragma warning(default: 4512)
# pragma warning(pop)
#endif
#endif
#include "script/ScriptContext.h"
#include "util/RunStateOwner.h"
#include "util/ContentProvider.h"
#include "v8datamodel/Feature.h"
#include "v8world/World.h"
#include "Replicator.h"
#include "util/boost.hpp"
class ThreadLogManager;
class DHTMLWindow;
class __single_inheritance CLuaHtmlView{public:class Binder;};
namespace G3D{class Stopwatch;}
namespace RBX{namespace View{class View;class PartChunk;class Decal;class Texture;}
namespace Network{class Server;}}
#include "reflection/signal.h"
#define BOOST_FUNCTION_COMPARE_TYPE_ID(X,Y) ((X)==(Y))
namespace recovered_boost133{
using namespace boost::detail::function;
union any_pointer
{
void*obj_ptr;
const void*const_obj_ptr;
void(*func_ptr)();
char data[1];
};
inline any_pointer make_any_pointer(void*o)
{
any_pointer p;
p.obj_ptr=o;
return p;
}
inline any_pointer make_any_pointer(const void*o)
{
any_pointer p;
p.const_obj_ptr=o;
return p;
}
inline any_pointer make_any_pointer(void(*f)())
{
any_pointer p;
p.func_ptr=f;
return p;
}
template<typename Functor,typename Allocator>
struct functor_manager
{
private:
typedef Functor functor_type;
static inline any_pointer
manager(any_pointer function_ptr,
functor_manager_operation_type op,
function_ptr_tag)
{
if(op==clone_functor_tag)
return function_ptr;
else
return make_any_pointer(static_cast<void(*)()>(0));
}
static inline any_pointer
manager(any_pointer function_obj_ptr,
functor_manager_operation_type op,
function_obj_tag)
{
#ifndef BOOST_NO_STD_ALLOCATOR
typedef typename Allocator::template rebind<functor_type>::other
allocator_type;
typedef typename allocator_type::pointer pointer_type;
#else
typedef functor_type*pointer_type;
#endif
#  ifndef BOOST_NO_STD_ALLOCATOR
allocator_type allocator;
#  endif
if(op==clone_functor_tag){
functor_type*f=
static_cast<functor_type*>(function_obj_ptr.obj_ptr);
#  ifndef BOOST_NO_STD_ALLOCATOR
pointer_type copy=allocator.allocate(1);
allocator.construct(copy,*f);
functor_type*new_f=static_cast<functor_type*>(copy);
#  else
functor_type*new_f=new functor_type(*f);
#  endif
return make_any_pointer(static_cast<void*>(new_f));
}
else{
functor_type*f=
reinterpret_cast<functor_type*>(function_obj_ptr.obj_ptr);
#  ifndef BOOST_NO_STD_ALLOCATOR
pointer_type victim=static_cast<pointer_type>(f);
allocator.destroy(victim);
allocator.deallocate(victim,1);
#  else
delete f;
#  endif
return make_any_pointer(static_cast<void*>(0));
}
}
public:
static any_pointer
manage(any_pointer functor_ptr,functor_manager_operation_type op)
{
if(op==check_functor_type_tag){
std::type_info*type=
static_cast<std::type_info*>(functor_ptr.obj_ptr);
return(BOOST_FUNCTION_COMPARE_TYPE_ID(typeid(Functor),*type)?
functor_ptr
:make_any_pointer(reinterpret_cast<void*>(0)));
}
else{
typedef typename get_function_tag<functor_type>::type tag_type;
return manager(functor_ptr,op,tag_type());
}
}
};
}
template struct recovered_boost133::functor_manager< boost::_mfi::mf0<void,CLuaHtmlView>,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,DHTMLWindow,RBX::Lua::FunctionRef>,boost::_bi::list2<boost::_bi::value<boost::shared_ptr<DHTMLWindow> >,boost::_bi::value<RBX::Lua::FunctionRef> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,DHTMLWindow,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,boost::_bi::list2<boost::_bi::value<boost::shared_ptr<DHTMLWindow> >,boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf3<void,DHTMLWindow,boost::shared_ptr<RBX::Instance>,RBX::Reflection::PropertyDescriptor const&,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,boost::_bi::list4<boost::_bi::value<boost::shared_ptr<DHTMLWindow> >,boost::_bi::value<boost::shared_ptr<RBX::Instance> >,boost::reference_wrapper<RBX::Reflection::PropertyDescriptor const >,boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< void(__cdecl*)(ThreadLogManager*),std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<bool,boost::_mfi::mf0<bool,CLuaHtmlView::Binder>,boost::_bi::list1<boost::_bi::value<CLuaHtmlView::Binder*> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,void(__cdecl*)(RBX::Reflection::PropertyDescriptor const*,RBX::Reflection::PropertyDescriptor const&,CLuaHtmlView::Binder*),boost::_bi::list3<boost::arg<1>,boost::reference_wrapper<RBX::Reflection::PropertyDescriptor const >,boost::_bi::value<CLuaHtmlView::Binder*> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< bool(__cdecl*)(void),std::allocator<void> >;
template struct recovered_boost133::functor_manager< void(__cdecl*)(RBX::Security::Context*),std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<G3D::Stopwatch const&,G3D::Stopwatch const&(__cdecl*)(G3D::Stopwatch const*),boost::_bi::list1<boost::_bi::value<G3D::Stopwatch const*> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<int const&,int const&(__cdecl*)(int const*),boost::_bi::list1<boost::_bi::value<int const*> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<RBX::worker_thread::work_result,RBX::worker_thread::work_result(__cdecl*)(boost::shared_ptr<RBX::Network::AbuseReporter::data>,std::basic_string<char,std::char_traits<char>,std::allocator<char> >),boost::_bi::list2<boost::_bi::value<boost::shared_ptr<RBX::Network::AbuseReporter::data> >,boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<RBX::worker_thread::work_result,RBX::worker_thread::work_result(__cdecl*)(boost::weak_ptr<RBX::Network::Server>,std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::basic_string<char,std::char_traits<char>,std::allocator<char> >),boost::_bi::list4<boost::_bi::value<boost::weak_ptr<RBX::Network::Server> >,boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,boost::_bi::value<int>,boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::Network::Replicator,boost::shared_ptr<RBX::Instance> >,boost::_bi::list2<boost::_bi::value<RBX::Network::Replicator*>,boost::arg<1> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<bool const&,bool const&(__cdecl*)(bool const*),boost::_bi::list1<boost::_bi::value<bool const*> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::View::View,bool>,boost::_bi::list2<boost::_bi::value<RBX::View::View*>,boost::arg<1> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::View::View,boost::shared_ptr<RBX::Instance> >,boost::_bi::list2<boost::_bi::value<RBX::View::View*>,boost::arg<1> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::View::PartChunk,boost::shared_ptr<RBX::Instance> >,boost::_bi::list2<boost::_bi::value<RBX::View::PartChunk*>,boost::arg<1> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::View::PartChunk,RBX::Reflection::PropertyDescriptor const*>,boost::_bi::list2<boost::_bi::value<RBX::View::PartChunk*>,boost::arg<1> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf0<void,RBX::View::PartChunk>,boost::_bi::list1<boost::_bi::value<RBX::View::PartChunk*> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::View::Decal,boost::shared_ptr<RBX::Instance> >,boost::_bi::list2<boost::_bi::value<RBX::View::Decal*>,boost::arg<1> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::View::Decal,RBX::Reflection::PropertyDescriptor const*>,boost::_bi::list2<boost::_bi::value<RBX::View::Decal*>,boost::arg<1> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::View::Texture,boost::shared_ptr<RBX::Instance> >,boost::_bi::list2<boost::_bi::value<RBX::View::Texture*>,boost::arg<1> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::View::Texture,RBX::Reflection::PropertyDescriptor const*>,boost::_bi::list2<boost::_bi::value<RBX::View::Texture*>,boost::arg<1> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::RunService,boost::shared_ptr<RBX::DataModel> >,boost::_bi::list2<boost::_bi::value<boost::shared_ptr<RBX::RunService> >,boost::_bi::value<boost::shared_ptr<RBX::DataModel> > > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<unsigned int,boost::_mfi::cmf0<unsigned int,RBX::ScriptContext>,boost::_bi::list1<boost::_bi::value<RBX::ScriptContext*> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<unsigned int,unsigned int(__cdecl*)(lua_State*),boost::_bi::list1<boost::arg<1> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,void(__cdecl*)(lua_State*,unsigned int),boost::_bi::list2<boost::arg<1>,boost::arg<2> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<unsigned int,unsigned int(__cdecl*)(std::vector<RBX::Reflection::Value,std::allocator<RBX::Reflection::Value> > const&,lua_State*),boost::_bi::list2<boost::reference_wrapper<std::vector<RBX::Reflection::Value,std::allocator<RBX::Reflection::Value> > const >,boost::arg<1> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,void(__cdecl*)(std::auto_ptr<std::vector<RBX::Reflection::Value,std::allocator<RBX::Reflection::Value> > >&,lua_State*,unsigned int),boost::_bi::list3<boost::reference_wrapper<std::auto_ptr<std::vector<RBX::Reflection::Value,std::allocator<RBX::Reflection::Value> > > >,boost::arg<1>,boost::arg<2> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<RBX::worker_thread::work_result,boost::_mfi::mf0<RBX::worker_thread::work_result,RBX::ContentProvider>,boost::_bi::list1<boost::_bi::value<RBX::ContentProvider*> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::basic_string<char,std::char_traits<char>,std::allocator<char> >(__cdecl*)(std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::basic_string<char,std::char_traits<char>,std::allocator<char> >),boost::_bi::list2<boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::basic_string<char,std::char_traits<char>,std::allocator<char> >(__cdecl*)(std::basic_string<char,std::char_traits<char>,std::allocator<char> >),boost::_bi::list1<boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< void(__cdecl*)(std::basic_string<char,std::char_traits<char>,std::allocator<char> >*),std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,void(__cdecl*)(boost::function0<void,std::allocator<boost::function_base> > const&,std::basic_string<char,std::char_traits<char>,std::allocator<char> >),boost::_bi::list2<boost::_bi::value<boost::function0<void,std::allocator<boost::function_base> > >,boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<double,double(__cdecl*)(RBX::Profiling::CodeProfiler*),boost::_bi::list1<boost::_bi::value<RBX::Profiling::CodeProfiler*> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<int,boost::_mfi::cmf0<int,RBX::World>,boost::_bi::list1<boost::_bi::value<RBX::World const*> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<unsigned int const&,unsigned int const&(__cdecl*)(unsigned int const*),boost::_bi::list1<boost::_bi::value<unsigned int const*> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<RBX::worker_thread::work_result,RBX::worker_thread::work_result(__cdecl*)(std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int),boost::_bi::list2<boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,boost::_bi::value<int> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf0<void,RBX::VelocityMotor>,boost::_bi::list1<boost::_bi::value<RBX::VelocityMotor*> > >,std::allocator<void> >;
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,void(__cdecl*)(boost::shared_ptr<RBX::worker_thread::data>,boost::function0<RBX::worker_thread::work_result,std::allocator<boost::function_base> > const&),boost::_bi::list2<boost::_bi::value<boost::shared_ptr<RBX::worker_thread::data> >,boost::_bi::value<boost::function0<RBX::worker_thread::work_result,std::allocator<boost::function_base> > > > >,std::allocator<void> >;
