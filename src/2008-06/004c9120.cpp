// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lang: cpp
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>
#include <intrin.h>
class XmlNameValuePair;
namespace boost{typedef long long long_long_type;
typedef unsigned long long ulong_long_type;
namespace mpl{struct void_;
template<bool C_>struct bool_;
typedef bool_<true>true_;
typedef bool_<false>false_;
struct integral_c_tag;
template<bool C_>struct bool_{static const bool value=C_;typedef integral_c_tag tag;typedef bool_ type;typedef bool value_type;operator bool()const{return this->value;}};
template<bool C_>bool const bool_<C_>::value;
struct na;
template<typename T>struct is_na:false_{};
template<>struct is_na<na>:true_{};
template<int N>struct int_;
template<int N>struct int_{static const int value=N;typedef int_ type;typedef int value_type;typedef integral_c_tag tag;typedef boost::mpl::int_<static_cast<int>((value+1))>next;typedef boost::mpl::int_<static_cast<int>((value-1))>prior;operator int()const{return static_cast<int>(this->value);}};
template<int N>int const boost::mpl::int_<N>::value;
template<typename T=na,typename Tag=void_>struct lambda;
template<bool C,typename T1,typename T2>struct if_c{typedef T1 type;};
template<typename T1,typename T2>struct if_c<false,T1,T2>{typedef T2 type;};
template<typename T1=na,typename T2=na,typename T3=na>struct if_{private:typedef if_c<static_cast<bool>(T1::value),T2,T3>almost_type_;public:typedef typename almost_type_::type type;};
template<>struct if_<na,na,na>{template<typename T1,typename T2,typename T3,typename T4=na,typename T5=na>struct apply:if_<T1,T2,T3>{};};
template<typename Tag>struct lambda<if_<na,na,na>,Tag>{typedef false_ is_le;typedef if_<na,na,na>result_;typedef if_<na,na,na>type;};
template<typename C=na,typename F1=na,typename F2=na>struct eval_if:if_<C,F1,F2>::type{};
template<bool C,typename F1,typename F2>struct eval_if_c:if_c<C,F1,F2>::type{};
template<>struct eval_if<na,na,na>{template<typename T1,typename T2,typename T3,typename T4=na,typename T5=na>struct apply:eval_if<T1,T2,T3>{};};
template<typename Tag>struct lambda<eval_if<na,na,na>,Tag>{typedef false_ is_le;typedef eval_if<na,na,na>result_;typedef eval_if<na,na,na>type;};
template<typename T,T N>struct integral_c;
template<typename T,T N>struct integral_c{static const T value=N;typedef integral_c type;typedef T value_type;typedef integral_c_tag tag;typedef integral_c<T,static_cast<T>((value+1))>next;typedef integral_c<T,static_cast<T>((value-1))>prior;operator T()const{return static_cast<T>(this->value);}};
template<typename T,T N>T const integral_c<T,N>::value;
template<bool C>struct integral_c<bool,C>{static const bool value=C;typedef integral_c_tag tag;typedef integral_c type;typedef bool value_type;operator bool()const{return this->value;}};
}template<class T,T val>struct integral_constant:public mpl::integral_c<T,val>{typedef integral_constant<T,val>type;};
template<>struct integral_constant<bool,true>:public mpl::true_{typedef integral_constant<bool,true>type;};
template<>struct integral_constant<bool,false>:public mpl::false_{typedef integral_constant<bool,false>type;};
typedef integral_constant<bool,false>false_type;
template<typename T,typename U>struct is_same: ::boost::integral_constant<bool,false>{};
template<typename T>struct is_same<T,T>: ::boost::integral_constant<bool,true>{};
namespace detail{namespace allocator{template<typename Allocator>struct is_partial_std_allocator{static const bool value=false;};
template<typename Allocator,typename Type>struct partial_std_allocator_rebind_to;
template<typename Allocator>struct rebinder{template<typename Type>struct result{typedef typename Allocator::template rebind<Type>::other other;};};
template<typename Allocator,typename Type>struct compliant_allocator_rebind_to{typedef typename rebinder<Allocator>::template result<Type>::other type;};
template<typename Allocator,typename Type>struct rebind_to:mpl::eval_if_c<is_partial_std_allocator<Allocator>::value,partial_std_allocator_rebind_to<Allocator,Type>,compliant_allocator_rebind_to<Allocator,Type> >{};
}}namespace mpl{template<typename Tag>struct at_impl;
template<typename Sequence,typename N>struct at;
template<typename Tag>struct begin_impl;
template<typename Tag>struct end_impl;
template<typename Sequence>struct begin;
template<typename Sequence>struct end;
struct nested_begin_end_tag;
struct non_sequence_tag;
template<typename Sequence>struct sequence_tag;
struct void_;
template<typename T>struct is_void_;
template<>struct is_void_<void_>;
template<typename T>struct is_not_void_;
template<>struct is_not_void_<void_>;
template<>struct is_void_<na>;
template<typename Tag>struct lambda<is_void_<na>,Tag>{typedef false_ is_le;typedef is_void_<na>result_;typedef is_void_<na>type;};
template<>struct is_not_void_<na>;
template<typename Tag>struct lambda<is_not_void_<na>,Tag>{typedef false_ is_le;typedef is_not_void_<na>result_;typedef is_not_void_<na>type;};
namespace aux{template<typename T>struct type_wrapper;
typedef char(&no_tag)[1];
typedef char(&yes_tag)[2];
template<typename T>struct msvc71_sfinae_helper{typedef void type;};
template<typename T,typename U=void>struct has_begin_impl_{static const bool value=false;typedef boost::mpl::bool_<value>type;};
template<typename T>struct has_begin_impl_<T,typename boost::mpl::aux::msvc71_sfinae_helper<typename T::begin>::type>{static const bool value=true;typedef boost::mpl::bool_<value>type;};
template<typename T,typename fallback_=boost::mpl::bool_<true> >struct has_begin:has_begin_impl_<T>{};
template<typename Sequence>struct begin_type{typedef typename Sequence::begin type;};
template<typename Sequence>struct end_type{typedef typename Sequence::end type;};
}template<typename Tag>struct begin_impl{template<typename Sequence>struct apply{typedef typename eval_if<aux::has_begin<Sequence,true_>,aux::begin_type<Sequence>,void_>::type type;};};
template<typename Tag>struct end_impl{template<typename Sequence>struct apply{typedef typename eval_if<aux::has_begin<Sequence,true_>,aux::end_type<Sequence>,void_>::type type;};};
template<>struct begin_impl<nested_begin_end_tag>{template<typename Sequence>struct apply{typedef typename Sequence::begin type;};};
template<>struct end_impl<nested_begin_end_tag>{template<typename Sequence>struct apply{typedef typename Sequence::end type;};};
template<>struct begin_impl<non_sequence_tag>{template<typename Sequence>struct apply{typedef void_ type;};};
template<>struct end_impl<non_sequence_tag>{template<typename Sequence>struct apply{typedef void_ type;};};
template<>struct begin_impl<na>{template<typename Sequence>struct apply{typedef void_ type;};};
template<>struct end_impl<na>{template<typename Sequence>struct apply{typedef void_ type;};};
namespace aux{template<typename T,typename U=void>struct has_tag_impl_{static const bool value=false;typedef boost::mpl::bool_<value>type;};
template<typename T>struct has_tag_impl_<T,typename boost::mpl::aux::msvc71_sfinae_helper<typename T::tag>::type>{static const bool value=true;typedef boost::mpl::bool_<value>type;};
template<typename T,typename fallback_=boost::mpl::bool_<false> >struct has_tag:has_tag_impl_<T>{};
template<bool has_tag_,bool has_begin_>struct sequence_tag_impl{template<typename Sequence>struct result2_;};
template<>struct sequence_tag_impl<true,true>{template<typename Sequence>struct result2_{typedef typename Sequence::tag type;};};
template<>struct sequence_tag_impl<true,false>{template<typename Sequence>struct result2_{typedef typename Sequence::tag type;};};
template<>struct sequence_tag_impl<false,true>{template<typename Sequence>struct result2_{typedef nested_begin_end_tag type;};};
template<>struct sequence_tag_impl<false,false>{template<typename Sequence>struct result2_{typedef non_sequence_tag type;};};
}template<typename Sequence=na>struct sequence_tag:aux::sequence_tag_impl< ::boost::mpl::aux::has_tag<Sequence>::value,::boost::mpl::aux::has_begin<Sequence>::value>::template result2_<Sequence>{};
template<>struct sequence_tag<na>{template<typename T1,typename T2=na,typename T3=na,typename T4=na,typename T5=na>struct apply:sequence_tag<T1>{};};
template<typename Tag>struct lambda<sequence_tag<na>,Tag>{typedef false_ is_le;typedef sequence_tag<na>result_;typedef sequence_tag<na>type;};
template<typename Sequence=na>struct begin{typedef typename sequence_tag<Sequence>::type tag_;typedef typename begin_impl<tag_>::template apply<Sequence>::type type;};
template<typename Sequence=na>struct end{typedef typename sequence_tag<Sequence>::type tag_;typedef typename end_impl<tag_>::template apply<Sequence>::type type;};
template<>struct begin<na>{template<typename T1,typename T2=na,typename T3=na,typename T4=na,typename T5=na>struct apply:begin<T1>{};};
template<typename Tag>struct lambda<begin<na>,Tag>{typedef false_ is_le;typedef begin<na>result_;typedef begin<na>type;};
template<>struct end<na>{template<typename T1,typename T2=na,typename T3=na,typename T4=na,typename T5=na>struct apply:end<T1>{};};
template<typename Tag>struct lambda<end<na>,Tag>{typedef false_ is_le;typedef end<na>result_;typedef end<na>type;};
template<typename Iterator,typename N>struct advance;
template<typename F,typename T1,typename T2>struct apply_wrap2:F::template apply<T1,T2>{};
template<typename F,typename T1,typename T2,typename T3,typename T4,typename T5>struct apply_wrap5:F::template apply<T1,T2,T3,T4,T5>{};
template<typename T,typename Default=void_>struct tag;
namespace aux{template<typename T>struct msvc_eti_base:T{typedef T type;};
template<>struct msvc_eti_base<int>{typedef msvc_eti_base type;typedef msvc_eti_base first;typedef msvc_eti_base second;typedef msvc_eti_base tag;enum{value=0};};
}template<typename N1=na,typename N2=na>struct less;
template<>struct less<na,na>;
template<typename Tag>struct lambda<less<na,na>,Tag>{typedef false_ is_le;typedef less<na,na>result_;typedef less<na,na>type;};
template<typename N=na>struct negate;
template<>struct negate<na>;
template<typename Tag>struct lambda<negate<na>,Tag>{typedef false_ is_le;typedef negate<na>result_;typedef negate<na>type;};
template<long N>struct long_;
template<long N>struct long_{static const long value=N;typedef long_ type;typedef long value_type;typedef integral_c_tag tag;typedef boost::mpl::long_<static_cast<long>((value+1))>next;typedef boost::mpl::long_<static_cast<long>((value-1))>prior;operator long()const{return static_cast<long>(this->value);}};
template<long N>long const boost::mpl::long_<N>::value;
template<typename T=na>struct next{typedef typename T::next type;};
template<typename T=na>struct prior;
template<>struct next<na>{template<typename T1,typename T2=na,typename T3=na,typename T4=na,typename T5=na>struct apply:next<T1>{};};
template<typename Tag>struct lambda<next<na>,Tag>{typedef false_ is_le;typedef next<na>result_;typedef next<na>type;};
template<>struct prior<na>;
template<typename Tag>struct lambda<prior<na>,Tag>{typedef false_ is_le;typedef prior<na>result_;typedef prior<na>type;};
template<typename Iterator=na,typename N=na>struct advance;
template<>struct advance<na,na>;
template<typename Tag>struct lambda<advance<na,na>,Tag>{typedef false_ is_le;typedef advance<na,na>result_;typedef advance<na,na>type;};
template<typename Iterator=na>struct deref{typedef typename Iterator::type type;};
template<>struct deref<na>{template<typename T1,typename T2=na,typename T3=na,typename T4=na,typename T5=na>struct apply:deref<T1>{};};
template<typename Tag>struct lambda<deref<na>,Tag>{typedef false_ is_le;typedef deref<na>result_;typedef deref<na>type;};
template<typename Tag>struct at_impl{template<typename Sequence,typename N>struct apply{typedef typename advance<typename begin<Sequence>::type,N>::type iter_;typedef typename deref<iter_>::type type;};};
template<typename Sequence=na,typename N=na>struct at;
template<typename Sequence,long N>struct at_c:at_impl<typename sequence_tag<Sequence>::type>::template apply<Sequence,mpl::long_<N> >{};
template<>struct at<na,na>;
template<typename Tag>struct lambda<at<na,na>,Tag>{typedef false_ is_le;typedef at<na,na>result_;typedef at<na,na>type;};
template<typename Sequence,typename T>struct contains;
template<typename F,typename T1=na,typename T2=na,typename T3=na,typename T4=na,typename T5=na>struct apply;
template<typename F,typename T1,typename T2>struct apply2;
template<int N>struct arg;
namespace aux{template<long C_>struct not_impl:bool_<!C_>{};
}template<typename T=na>struct not_:aux::not_impl<T::type::value>{};
template<>struct not_<na>{template<typename T1,typename T2=na,typename T3=na,typename T4=na,typename T5=na>struct apply:not_<T1>{};};
template<typename Tag>struct lambda<not_<na>,Tag>{typedef false_ is_le;typedef not_<na>result_;typedef not_<na>type;};
struct failed;
template<bool C>struct assert{typedef void*type;};
template<>struct assert<false>{typedef assert type;};
template<bool C>int assertion_failed(typename assert<C>::type);
bool operator==(failed,failed);
bool operator!=(failed,failed);
bool operator>(failed,failed);
bool operator>=(failed,failed);
bool operator<(failed,failed);
bool operator<=(failed,failed);
template<bool>struct assert_arg_pred_impl{typedef int type;};
template<>struct assert_arg_pred_impl<true>{typedef void*type;};
template<typename P>struct assert_arg_pred{typedef typename P::type p_type;typedef typename assert_arg_pred_impl<p_type::value>::type type;};
template<typename P>struct assert_arg_pred_not;
template<typename Pred>failed************(Pred::************assert_arg(void(*)(Pred),typename assert_arg_pred<Pred>::type));

template<typename Pred>assert<false>assert_arg(void(*)(Pred),typename assert_arg_pred_not<Pred>::type);
template<typename Pred>assert<false>assert_not_arg(void(*)(Pred),typename assert_arg_pred<Pred>::type);
template<>struct arg<-1>;
template<>struct arg<1>{static const int value=1;typedef arg<2>next;template<typename U1=na,typename U2=na,typename U3=na,typename U4=na,typename U5=na>struct apply{typedef U1 type;static const std::size_t mpl_assertion_in_line_45=sizeof(boost::mpl::assertion_failed<false>(boost::mpl::assert_not_arg((void(*)(boost::mpl::is_na<type>))0,1)));};};
template<>struct arg<2>{static const int value=2;typedef arg<3>next;template<typename U1=na,typename U2=na,typename U3=na,typename U4=na,typename U5=na>struct apply{typedef U2 type;static const std::size_t mpl_assertion_in_line_63=sizeof(boost::mpl::assertion_failed<false>(boost::mpl::assert_not_arg((void(*)(boost::mpl::is_na<type>))0,1)));};};
template<>struct arg<3>;
template<>struct arg<4>;
template<>struct arg<5>;
typedef arg<1>_1;
typedef arg<2>_2;
template<typename F,typename T1=na,typename T2=na,typename T3=na,typename T4=na,typename T5=na>struct bind;
template<typename F>struct bind0;
template<typename F,typename T1>struct bind1;
template<typename F,typename T1,typename T2>struct bind2;
template<typename F,typename T1,typename T2,typename T3>struct bind3;
template<typename F,typename T1,typename T2,typename T3,typename T4>struct bind4;
template<typename F,typename T1,typename T2,typename T3,typename T4,typename T5>struct bind5;
template<typename T=na,int not_le_=0>struct protect:T{typedef protect type;};
template<>struct protect<na>{template<typename T1,typename T2=na,typename T3=na,typename T4=na,typename T5=na>struct apply:protect<T1>{};};
namespace aux{template<typename T,typename U1,typename U2,typename U3,typename U4,typename U5>struct resolve_bind_arg{typedef T type;};
template<typename T,typename Arg>struct replace_unnamed_arg{typedef Arg next;typedef T type;};
template<typename Arg>struct replace_unnamed_arg<arg<-1>,Arg>{typedef typename Arg::next next;typedef Arg type;};
template<int N,typename U1,typename U2,typename U3,typename U4,typename U5>struct resolve_bind_arg<arg<N>,U1,U2,U3,U4,U5>{typedef typename apply_wrap5<mpl::arg<N>,U1,U2,U3,U4,U5>::type type;};
template<typename F,typename T1,typename T2,typename T3,typename T4,typename T5,typename U1,typename U2,typename U3,typename U4,typename U5>struct resolve_bind_arg<bind<F,T1,T2,T3,T4,T5>,U1,U2,U3,U4,U5>{typedef bind<F,T1,T2,T3,T4,T5>f_;typedef typename apply_wrap5<f_,U1,U2,U3,U4,U5>::type type;};
}template<typename F>struct bind0;
namespace aux{template<typename F,typename U1,typename U2,typename U3,typename U4,typename U5>struct resolve_bind_arg<bind0<F>,U1,U2,U3,U4,U5>{typedef bind0<F>f_;typedef typename apply_wrap5<f_,U1,U2,U3,U4,U5>::type type;};
}template<typename F>struct bind<F,na,na,na,na,na>:bind0<F>{};
template<typename F,typename T1>struct bind1;
namespace aux{template<typename F,typename T1,typename U1,typename U2,typename U3,typename U4,typename U5>struct resolve_bind_arg<bind1<F,T1>,U1,U2,U3,U4,U5>{typedef bind1<F,T1>f_;typedef typename apply_wrap5<f_,U1,U2,U3,U4,U5>::type type;};
}template<typename F,typename T1>struct bind<F,T1,na,na,na,na>:bind1<F,T1>{};
template<typename F,typename T1,typename T2>struct bind2{template<typename U1=na,typename U2=na,typename U3=na,typename U4=na,typename U5=na>struct apply{private:typedef aux::replace_unnamed_arg<F,mpl::arg<1> >r0;typedef typename r0::type a0;typedef typename r0::next n1;typedef typename aux::resolve_bind_arg<a0,U1,U2,U3,U4,U5>::type f_;typedef aux::replace_unnamed_arg<T1,n1>r1;typedef typename r1::type a1;typedef typename r1::next n2;typedef aux::resolve_bind_arg<a1,U1,U2,U3,U4,U5>t1;typedef aux::replace_unnamed_arg<T2,n2>r2;typedef typename r2::type a2;typedef typename r2::next n3;typedef aux::resolve_bind_arg<a2,U1,U2,U3,U4,U5>t2;public:typedef typename apply_wrap2<f_,typename t1::type,typename t2::type>::type type;};};
namespace aux{template<typename F,typename T1,typename T2,typename U1,typename U2,typename U3,typename U4,typename U5>struct resolve_bind_arg<bind2<F,T1,T2>,U1,U2,U3,U4,U5>{typedef bind2<F,T1,T2>f_;typedef typename apply_wrap5<f_,U1,U2,U3,U4,U5>::type type;};
}template<typename F,typename T1,typename T2>struct bind<F,T1,T2,na,na,na>:bind2<F,T1,T2>{};
template<typename F,typename T1,typename T2,typename T3>struct bind3;
namespace aux{template<typename F,typename T1,typename T2,typename T3,typename U1,typename U2,typename U3,typename U4,typename U5>struct resolve_bind_arg<bind3<F,T1,T2,T3>,U1,U2,U3,U4,U5>{typedef bind3<F,T1,T2,T3>f_;typedef typename apply_wrap5<f_,U1,U2,U3,U4,U5>::type type;};
}template<typename F,typename T1,typename T2,typename T3>struct bind<F,T1,T2,T3,na,na>:bind3<F,T1,T2,T3>{};
template<typename F,typename T1,typename T2,typename T3,typename T4>struct bind4;
namespace aux{template<typename F,typename T1,typename T2,typename T3,typename T4,typename U1,typename U2,typename U3,typename U4,typename U5>struct resolve_bind_arg<bind4<F,T1,T2,T3,T4>,U1,U2,U3,U4,U5>{typedef bind4<F,T1,T2,T3,T4>f_;typedef typename apply_wrap5<f_,U1,U2,U3,U4,U5>::type type;};
}template<typename F,typename T1,typename T2,typename T3,typename T4>struct bind<F,T1,T2,T3,T4,na>:bind4<F,T1,T2,T3,T4>{};
template<typename F,typename T1,typename T2,typename T3,typename T4,typename T5>struct bind5;
namespace aux{template<typename F,typename T1,typename T2,typename T3,typename T4,typename T5,typename U1,typename U2,typename U3,typename U4,typename U5>struct resolve_bind_arg<bind5<F,T1,T2,T3,T4,T5>,U1,U2,U3,U4,U5>{typedef bind5<F,T1,T2,T3,T4,T5>f_;typedef typename apply_wrap5<f_,U1,U2,U3,U4,U5>::type type;};
}template<typename F,typename T1,typename T2,typename T3,typename T4,typename T5>struct bind:bind5<F,T1,T2,T3,T4,T5>{};
template<template<typename T1,typename T2,typename T3>class F,typename Tag>struct quote3;
template<typename T1,typename T2,typename T3>struct if_;
template<typename Tag,typename T1,typename T2,typename T3>struct bind3<quote3<if_,Tag>,T1,T2,T3>;
template<template<typename T1,typename T2,typename T3>class F,typename Tag>struct quote3;
template<typename T1,typename T2,typename T3>struct eval_if;
template<typename Tag,typename T1,typename T2,typename T3>struct bind3<quote3<eval_if,Tag>,T1,T2,T3>;
namespace aux{template<typename T,typename U=void>struct has_type_impl_{static const bool value=false;typedef boost::mpl::bool_<value>type;};
template<typename T>struct has_type_impl_<T,typename boost::mpl::aux::msvc71_sfinae_helper<typename T::type>::type>{static const bool value=true;typedef boost::mpl::bool_<value>type;};
template<typename T,typename fallback_=boost::mpl::bool_<true> >struct has_type:has_type_impl_<T>{};
}template<template<typename P1>class F,typename Tag=void_>struct quote1;
template<template<typename P1,typename P2,typename P3>class F,typename Tag=void_>struct quote3;
namespace aux{template<bool C1=false,bool C2=false,bool C3=false,bool C4=false,bool C5=false>struct lambda_or:true_{};
template<>struct lambda_or<false,false,false,false,false>:false_{};
}template<typename T,typename Tag>struct lambda{typedef false_ is_le;typedef T result_;typedef T type;};
template<typename T>struct is_lambda_expression;
template<int N,typename Tag>struct lambda<arg<N>,Tag>{typedef true_ is_le;typedef mpl::arg<N>result_;typedef mpl::protect<result_>type;};
template<typename F,typename Tag>struct lambda<bind0<F>,Tag>{typedef false_ is_le;typedef bind0<F>result_;typedef result_ type;};
namespace aux{template<typename IsLE,typename Tag,template<typename P1>class F,typename L1>struct le_result1{typedef F<typename L1::type>result_;typedef result_ type;};
template<typename Tag,template<typename P1>class F,typename L1>struct le_result1<true_,Tag,F,L1>{typedef bind1<quote1<F,Tag>,typename L1::result_>result_;typedef mpl::protect<result_>type;};
}template<template<typename P1>class F,typename T1,typename Tag>struct lambda<F<T1>,Tag>{typedef lambda<T1,Tag>l1;typedef typename l1::is_le is_le1;typedef typename aux::lambda_or<is_le1::value>::type is_le;typedef aux::le_result1<is_le,Tag,F,l1>le_result_;typedef typename le_result_::result_ result_;typedef typename le_result_::type type;};
template<typename F,typename T1,typename Tag>struct lambda<bind1<F,T1>,Tag>{typedef false_ is_le;typedef bind1<F,T1>result_;typedef result_ type;};
template<template<typename P1,typename P2>class F,typename T1,typename T2,typename Tag>struct lambda<F<T1,T2>,Tag>;
template<typename F,typename T1,typename T2,typename Tag>struct lambda<bind2<F,T1,T2>,Tag>{typedef false_ is_le;typedef bind2<F,T1,T2>result_;typedef result_ type;};
template<template<typename P1,typename P2,typename P3>class F,typename T1,typename T2,typename T3,typename Tag>struct lambda<F<T1,T2,T3>,Tag>;
template<typename F,typename T1,typename T2,typename T3,typename Tag>struct lambda<bind3<F,T1,T2,T3>,Tag>{typedef false_ is_le;typedef bind3<F,T1,T2,T3>result_;typedef result_ type;};

template<typename F,typename T1,typename T2,typename T3,typename T4,typename Tag>struct lambda<bind4<F,T1,T2,T3,T4>,Tag>{typedef false_ is_le;typedef bind4<F,T1,T2,T3,T4>result_;typedef result_ type;};

template<typename F,typename T1,typename T2,typename T3,typename T4,typename T5,typename Tag>struct lambda<bind5<F,T1,T2,T3,T4,T5>,Tag>{typedef false_ is_le;typedef bind5<F,T1,T2,T3,T4,T5>result_;typedef result_ type;};
template<typename T,typename Tag>struct lambda<mpl::protect<T>,Tag>{typedef false_ is_le;typedef mpl::protect<T>result_;typedef result_ type;};
template<typename F,typename T1,typename T2,typename T3,typename T4,typename T5,typename Tag>struct lambda<bind<F,T1,T2,T3,T4,T5>,Tag>{typedef false_ is_le;typedef bind<F,T1,T2,T3,T4,T5>result_;typedef result_ type;};
template<typename F,typename Tag1,typename Tag2>struct lambda<lambda<F,Tag1>,Tag2>;
template<>struct lambda<na,na>{template<typename T1,typename T2,typename T3=na,typename T4=na,typename T5=na>struct apply:lambda<T1,T2>{};};
template<typename Tag>struct lambda<lambda<na,na>,Tag>{typedef false_ is_le;typedef lambda<na,na>result_;typedef lambda<na,na>type;};
template<typename F>struct apply<F,na,na,na,na,na>;
template<typename F,typename T1>struct apply<F,T1,na,na,na,na>;
template<typename F,typename T1,typename T2>struct apply2:apply_wrap2<typename lambda<F>::type,T1,T2>{};
template<typename F,typename T1,typename T2>struct apply<F,T1,T2,na,na,na>;
template<typename F,typename T1,typename T2,typename T3>struct apply<F,T1,T2,T3,na,na>;
template<typename F,typename T1,typename T2,typename T3,typename T4>struct apply<F,T1,T2,T3,T4,na>;
template<typename F,typename T1,typename T2,typename T3,typename T4,typename T5>struct apply;
namespace aux{template<bool C_,typename T1,typename T2,typename T3,typename T4>struct or_impl:true_{};
template<typename T1,typename T2,typename T3,typename T4>struct or_impl<false,T1,T2,T3,T4>:or_impl<T1::type::value,T2,T3,T4,false_>{};
template<>struct or_impl<false,false_,false_,false_,false_>:false_{};
}template<typename T1=na,typename T2=na,typename T3=false_,typename T4=false_,typename T5=false_>struct or_:aux::or_impl<T1::type::value,T2,T3,T4,T5>{};
template<>struct or_<na,na>{template<typename T1,typename T2,typename T3=na,typename T4=na,typename T5=na>struct apply:or_<T1,T2>{};};
template<typename Tag>struct lambda<or_<na,na>,Tag>{typedef false_ is_le;typedef or_<na,na>result_;typedef or_<na,na>type;};
template<typename T1=na,typename T2=na,typename T3=true_,typename T4=true_,typename T5=true_>struct and_;
template<>struct and_<na,na>;
template<typename Tag>struct lambda<and_<na,na>,Tag>{typedef false_ is_le;typedef and_<na,na>result_;typedef and_<na,na>type;};
template<typename T1=na,typename T2=na>struct pair{typedef pair type;typedef T1 first;typedef T2 second;};
template<typename P=na>struct first{typedef typename P::first type;};
template<typename P=na>struct second;
template<>struct pair<na,na>{template<typename T1,typename T2,typename T3=na,typename T4=na,typename T5=na>struct apply:pair<T1,T2>{};};
template<typename Tag>struct lambda<pair<na,na>,Tag>{typedef false_ is_le;typedef pair<na,na>result_;typedef pair<na,na>type;};
template<>struct first<na>{template<typename T1,typename T2=na,typename T3=na,typename T4=na,typename T5=na>struct apply:first<T1>{};};
template<typename Tag>struct lambda<first<na>,Tag>{typedef false_ is_le;typedef first<na>result_;typedef first<na>type;};
template<>struct second<na>;
template<typename Tag>struct lambda<second<na>,Tag>{typedef false_ is_le;typedef second<na>result_;typedef second<na>type;};
template<typename T=na>struct identity{typedef T type;};
template<typename T=na>struct make_identity;
template<>struct identity<na>{template<typename T1,typename T2=na,typename T3=na,typename T4=na,typename T5=na>struct apply:identity<T1>{};};
template<typename Tag>struct lambda<identity<na>,Tag>{typedef false_ is_le;typedef identity<na>result_;typedef identity<na>type;};
template<>struct make_identity<na>;
template<typename Tag>struct lambda<make_identity<na>,Tag>{typedef false_ is_le;typedef make_identity<na>result_;typedef make_identity<na>type;};
template<typename Sequence=na,typename State=na,typename ForwardOp=na,typename ForwardPredicate=na,typename BackwardOp=na,typename BackwardPredicate=na>struct iter_fold_if;
template<>struct iter_fold_if<na,na,na,na,na,na>;
template<typename Tag>struct lambda<iter_fold_if<na,na,na,na,na,na>,Tag>{typedef false_ is_le;typedef iter_fold_if<na,na,na,na,na,na>result_;typedef iter_fold_if<na,na,na,na,na,na>type;};
template<typename Sequence=na,typename Predicate=na>struct find_if;
template<>struct find_if<na,na>;
template<typename Tag>struct lambda<find_if<na,na>,Tag>{typedef false_ is_le;typedef find_if<na,na>result_;typedef find_if<na,na>type;};
template<typename Sequence=na,typename T=na>struct find;
template<>struct find<na,na>;
template<typename Tag>struct lambda<find<na,na>,Tag>{typedef false_ is_le;typedef find<na,na>result_;typedef find<na,na>type;};
template<typename Sequence=na,typename T=na>struct contains;
template<>struct contains<na,na>;
template<typename Tag>struct lambda<contains<na,na>,Tag>{typedef false_ is_le;typedef contains<na,na>result_;typedef contains<na,na>type;};
template<typename Tag>struct size_impl;
template<typename Sequence>struct size;
template<typename First,typename Last>struct distance;
template<typename Tag>struct O1_size_impl;
template<typename Sequence>struct O1_size;
namespace aux{template<typename T,typename fallback_=boost::mpl::bool_<false> >struct has_size;
template<typename Sequence>struct O1_size_impl;
}template<typename Tag>struct O1_size_impl{template<typename Sequence>struct apply:if_<aux::has_size<Sequence>,aux::O1_size_impl<Sequence>,long_<-1> >::type{};};
template<typename Sequence=na>struct O1_size:O1_size_impl<typename sequence_tag<Sequence>::type>::template apply<Sequence>{};
template<>struct O1_size<na>{template<typename T1,typename T2=na,typename T3=na,typename T4=na,typename T5=na>struct apply:O1_size<T1>{};};
template<typename Tag>struct lambda<O1_size<na>,Tag>{typedef false_ is_le;typedef O1_size<na>result_;typedef O1_size<na>type;};
template<typename Sequence=na,typename State=na,typename ForwardOp=na>struct iter_fold;
template<>struct iter_fold<na,na,na>;
template<typename Tag>struct lambda<iter_fold<na,na,na>,Tag>{typedef false_ is_le;typedef iter_fold<na,na,na>result_;typedef iter_fold<na,na,na>type;};
template<typename First=na,typename Last=na>struct iterator_range;
template<>struct iterator_range<na,na>;
template<typename Tag>struct lambda<iterator_range<na,na>,Tag>{typedef false_ is_le;typedef iterator_range<na,na>result_;typedef iterator_range<na,na>type;};
template<typename First=na,typename Last=na>struct distance;
template<>struct distance<na,na>;
template<typename Tag>struct lambda<distance<na,na>,Tag>{typedef false_ is_le;typedef distance<na,na>result_;typedef distance<na,na>type;};
template<typename Tag>struct size_impl{template<typename Sequence>struct apply:distance<typename begin<Sequence>::type,typename end<Sequence>::type>{};};
template<typename Sequence=na>struct size:aux::msvc_eti_base<typename size_impl<typename sequence_tag<Sequence>::type>::template apply<Sequence>::type>::type{};
template<>struct size<na>{template<typename T1,typename T2=na,typename T3=na,typename T4=na,typename T5=na>struct apply:size<T1>{};};
template<typename Tag>struct lambda<size<na>,Tag>{typedef false_ is_le;typedef size<na>result_;typedef size<na>type;};
}namespace detail{template<typename T>struct cv_traits_imp{};
template<typename T>struct cv_traits_imp<T*>{static const bool is_const=false;static const bool is_volatile=false;typedef T unqualified_type;};
template<typename T>struct cv_traits_imp<const T*>{static const bool is_const=true;static const bool is_volatile=false;typedef T unqualified_type;};
template<typename T>struct cv_traits_imp<volatile T*>{static const bool is_const=false;static const bool is_volatile=true;typedef T unqualified_type;};
template<typename T>struct cv_traits_imp<const volatile T*>{static const bool is_const=true;static const bool is_volatile=true;typedef T unqualified_type;};
}template<typename T>struct is_const: ::boost::integral_constant<bool,::boost::detail::cv_traits_imp<T*>::is_const>{};
template<typename T>struct is_const<T&>: ::boost::integral_constant<bool,false>{};
template<typename T>struct is_volatile;
template<typename T>struct is_volatile<T&>;
template<bool B,class T=void>struct enable_if_c;
template<class T>struct enable_if_c<false,T>;
template<class Cond,class T=void>struct disable_if;
namespace type_traits{typedef char yes_type;
struct no_type{char padding[8];};
}template<typename T>struct is_array: ::boost::integral_constant<bool,false>{};
template<typename T,std::size_t N>struct is_array<T[N]>: ::boost::integral_constant<bool,true>{};
template<typename T,std::size_t N>struct is_array<T const[N]>: ::boost::integral_constant<bool,true>{};
template<typename T,std::size_t N>struct is_array<T volatile[N]>: ::boost::integral_constant<bool,true>{};
template<typename T,std::size_t N>struct is_array<T const volatile[N]>: ::boost::integral_constant<bool,true>{};
template<typename T>struct is_array<T[]>: ::boost::integral_constant<bool,true>{};
template<typename T>struct is_array<T const[]>: ::boost::integral_constant<bool,true>{};
template<typename T>struct is_array<T volatile[]>: ::boost::integral_constant<bool,true>{};
template<typename T>struct is_array<T const volatile[]>: ::boost::integral_constant<bool,true>{};
template<typename T>struct is_reference: ::boost::integral_constant<bool,false>{};
template<typename T>struct is_reference<T&>: ::boost::integral_constant<bool,true>{};
namespace type_traits{template<bool b1,bool b2,bool b3=false,bool b4=false,bool b5=false,bool b6=false,bool b7=false>struct ice_or;
template<bool b1,bool b2,bool b3,bool b4,bool b5,bool b6,bool b7>struct ice_or{static const bool value=true;};
template<>struct ice_or<false,false,false,false,false,false,false>{static const bool value=false;};
template<bool b1,bool b2,bool b3=true,bool b4=true,bool b5=true,bool b6=true,bool b7=true>struct ice_and;
template<bool b1,bool b2,bool b3,bool b4,bool b5,bool b6,bool b7>struct ice_and{static const bool value=false;};
template<>struct ice_and<true,true,true,true,true,true,true>{static const bool value=true;};
template<bool b>struct ice_not{static const bool value=true;};
template<>struct ice_not<true>{static const bool value=false;};
template<int b1,int b2>struct ice_eq{static const bool value=(b1==b2);};
template<int b1,int b2>struct ice_ne{static const bool value=(b1!=b2);};
template<int b1,int b2>bool const ice_eq<b1,b2>::value;
template<int b1,int b2>bool const ice_ne<b1,b2>::value;
}template<typename T>struct is_integral: ::boost::integral_constant<bool,false>{};
template<>struct is_integral<unsigned char>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<unsigned char const>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<unsigned char volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<unsigned char const volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<unsigned short>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<unsigned short const>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<unsigned short volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<unsigned short const volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<unsigned int>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<unsigned int const>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<unsigned int volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<unsigned int const volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<unsigned long>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<unsigned long const>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<unsigned long volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<unsigned long const volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<signed char>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<signed char const>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<signed char volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<signed char const volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<signed short>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<signed short const>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<signed short volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<signed short const volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<signed int>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<signed int const>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<signed int volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<signed int const volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<signed long>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<signed long const>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<signed long volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<signed long const volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<bool>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<bool const>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<bool volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<bool const volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<char>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<char const>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<char volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<char const volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<wchar_t>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<wchar_t const>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<wchar_t volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<wchar_t const volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral< ::boost::ulong_long_type>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral< ::boost::ulong_long_type const>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral< ::boost::ulong_long_type volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral< ::boost::ulong_long_type const volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral< ::boost::long_long_type>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral< ::boost::long_long_type const>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral< ::boost::long_long_type volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral< ::boost::long_long_type const volatile>: ::boost::integral_constant<bool,true>{};
template<typename T>struct is_float: ::boost::integral_constant<bool,false>{};
template<>struct is_float<float>: ::boost::integral_constant<bool,true>{};
template<>struct is_float<float const>: ::boost::integral_constant<bool,true>{};
template<>struct is_float<float volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_float<float const volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_float<double>: ::boost::integral_constant<bool,true>{};
template<>struct is_float<double const>: ::boost::integral_constant<bool,true>{};
template<>struct is_float<double volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_float<double const volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_float<long double>: ::boost::integral_constant<bool,true>{};
template<>struct is_float<long double const>: ::boost::integral_constant<bool,true>{};
template<>struct is_float<long double volatile>: ::boost::integral_constant<bool,true>{};
template<>struct is_float<long double const volatile>: ::boost::integral_constant<bool,true>{};
namespace detail{template<typename T>struct is_arithmetic_impl{static const bool value=(::boost::type_traits::ice_or< ::boost::is_integral<T>::value,::boost::is_float<T>::value>::value);};
}template<typename T>struct is_arithmetic: ::boost::integral_constant<bool,::boost::detail::is_arithmetic_impl<T>::value>{};
template<bool x>struct STATIC_ASSERTION_FAILURE;
template<>struct STATIC_ASSERTION_FAILURE<true>{enum{value=1};};
template<int x>struct static_assert_test;
template<typename T>struct remove_cv{typedef typename boost::detail::cv_traits_imp<T*>::unqualified_type type;};
template<typename T>struct remove_cv<T&>{typedef T&type;};
template<typename T,std::size_t N>struct remove_cv<T const[N]>{typedef T type[N];};
template<typename T,std::size_t N>struct remove_cv<T volatile[N]>{typedef T type[N];};
template<typename T,std::size_t N>struct remove_cv<T const volatile[N]>{typedef T type[N];};
namespace detail{template<typename T>struct is_union_impl{typedef typename remove_cv<T>::type cvt;static const bool value=__is_union(cvt);};
}template<typename T>struct is_union: ::boost::integral_constant<bool,::boost::detail::is_union_impl<T>::value>{};
namespace detail{template<typename T>struct is_class_impl{template<class U>static::boost::type_traits::yes_type is_class_tester(void(U::*)(void));template<class U>static::boost::type_traits::no_type is_class_tester(...);static const bool value=(::boost::type_traits::ice_and<sizeof(is_class_tester<T>(0))==sizeof(::boost::type_traits::yes_type),::boost::type_traits::ice_not< ::boost::is_union<T>::value>::value>::value);};
}template<typename T>struct is_class: ::boost::integral_constant<bool,::boost::detail::is_class_impl<T>::value>{};
template<typename From,typename To>struct is_convertible;
template<class Type>class reference_wrapper;
namespace multi_index{template<class Type>struct identity;
}namespace mpl{namespace aux{struct v_iter_tag;
template<long N>struct vector_tag;
}template<typename Vector,long n_>struct v_at;
template<long n_>struct at_impl<aux::vector_tag<n_> >{template<typename Vector,typename N>struct apply:v_at<Vector,N::value>{};};
template<typename Tag>struct push_front_impl;
template<typename Sequence,typename T>struct push_front;
template<typename Sequence,typename T>struct push_back;
template<typename Sequence>struct back;
template<typename Tag>struct clear_impl;
template<typename Sequence>struct clear;
struct random_access_iterator_tag;
template<typename N1=na,typename N2=na,typename N3=na,typename N4=na,typename N5=na>struct plus;
template<typename N1,typename N2,typename N3,typename N4>struct plus<N1,N2,N3,N4,na>;
template<typename N1,typename N2,typename N3>struct plus<N1,N2,N3,na,na>;
template<typename N1,typename N2>struct plus<N1,N2,na,na,na>;
template<>struct plus<na,na>;
template<typename Tag>struct lambda<plus<na,na>,Tag>{typedef false_ is_le;typedef plus<na,na>result_;typedef plus<na,na>type;};
template<typename N1=na,typename N2=na,typename N3=na,typename N4=na,typename N5=na>struct minus;
template<typename N1,typename N2,typename N3,typename N4>struct minus<N1,N2,N3,N4,na>;
template<typename N1,typename N2,typename N3>struct minus<N1,N2,N3,na,na>;
template<typename N1,typename N2>struct minus<N1,N2,na,na,na>;
template<>struct minus<na,na>;
template<typename Tag>struct lambda<minus<na,na>,Tag>{typedef false_ is_le;typedef minus<na,na>result_;typedef minus<na,na>type;};
template<typename Vector,long n_>struct v_iter{typedef aux::v_iter_tag tag;typedef random_access_iterator_tag category;typedef typename v_at<Vector,n_>::type type;typedef Vector vector_;typedef mpl::long_<n_>pos;};
template<typename Vector,long n_>struct next<v_iter<Vector,n_> >{typedef v_iter<Vector,(n_+1)>type;};
template<typename Vector,long n_>struct prior<v_iter<Vector,n_> >;
template<typename Vector,long n_,typename Distance>struct advance<v_iter<Vector,n_>,Distance>;
template<typename Vector,long n_,long m_>struct distance<v_iter<Vector,n_>,v_iter<Vector,m_> >;
template<typename Dummy=na>struct vector0;
template<>struct vector0<na>{typedef aux::vector_tag<0>tag;typedef vector0 type;typedef void_ item0;typedef v_iter<vector0<>,0>begin;typedef v_iter<vector0<>,0>end;};
template<long N>struct clear_impl<aux::vector_tag<N> >{template<typename Vector>struct apply{typedef vector0<>type;};};
template<long N>struct O1_size_impl<aux::vector_tag<N> >{template<typename Vector>struct apply:mpl::long_<N>{};};
template<long N>struct size_impl<aux::vector_tag<N> >:O1_size_impl<aux::vector_tag<N> >{};
template<typename Tag>struct empty_impl;
template<typename Sequence>struct empty;
template<>struct empty_impl<aux::vector_tag<0> >{template<typename Vector>struct apply:true_{};};
template<long N>struct empty_impl<aux::vector_tag<N> >{template<typename Vector>struct apply:false_{};};
template<typename V>struct v_at<V,0>{typedef typename V::item0 type;};
template<typename T0>struct vector1{typedef aux::vector_tag<1>tag;typedef vector1 type;typedef T0 item0;typedef void_ item1;typedef T0 back;typedef v_iter<type,0>begin;typedef v_iter<type,1>end;};
template<>struct push_front_impl<aux::vector_tag<0> >{template<typename Vector,typename T>struct apply{typedef vector1<T>type;};};
template<typename V>struct v_at<V,1>{typedef typename V::item1 type;};
template<typename T0,typename T1>struct vector2{typedef aux::vector_tag<2>tag;typedef vector2 type;typedef T0 item0;typedef T1 item1;typedef void_ item2;typedef T1 back;typedef v_iter<type,0>begin;typedef v_iter<type,2>end;};
template<>struct push_front_impl<aux::vector_tag<1> >{template<typename Vector,typename T>struct apply{typedef vector2<T,typename Vector::item0>type;};};
template<typename V>struct v_at<V,2>{typedef typename V::item2 type;};
template<typename T0,typename T1,typename T2>struct vector3;
template<>struct push_front_impl<aux::vector_tag<2> >{template<typename Vector,typename T>struct apply{typedef vector3<T,typename Vector::item0,typename Vector::item1>type;};};
template<typename V>struct v_at<V,3>{typedef typename V::item3 type;};
template<typename T0,typename T1,typename T2,typename T3>struct vector4;
template<>struct push_front_impl<aux::vector_tag<3> >{template<typename Vector,typename T>struct apply{typedef vector4<T,typename Vector::item0,typename Vector::item1,typename Vector::item2>type;};};
template<typename V>struct v_at<V,4>{typedef typename V::item4 type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4>struct vector5;
template<>struct push_front_impl<aux::vector_tag<4> >{template<typename Vector,typename T>struct apply{typedef vector5<T,typename Vector::item0,typename Vector::item1,typename Vector::item2,typename Vector::item3>type;};};
template<typename V>struct v_at<V,5>{typedef typename V::item5 type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5>struct vector6;
template<>struct push_front_impl<aux::vector_tag<5> >;
template<typename V>struct v_at<V,6>{typedef typename V::item6 type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6>struct vector7;
template<>struct push_front_impl<aux::vector_tag<6> >;
template<typename V>struct v_at<V,7>{typedef typename V::item7 type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7>struct vector8;
template<>struct push_front_impl<aux::vector_tag<7> >;
template<typename V>struct v_at<V,8>{typedef typename V::item8 type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8>struct vector9;
template<>struct push_front_impl<aux::vector_tag<8> >;
template<typename V>struct v_at<V,9>{typedef typename V::item9 type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9>struct vector10;
template<>struct push_front_impl<aux::vector_tag<9> >;
template<typename V>struct v_at<V,10>{typedef typename V::item10 type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10>struct vector11;
template<>struct push_front_impl<aux::vector_tag<10> >;
template<typename V>struct v_at<V,11>{typedef typename V::item11 type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11>struct vector12;
template<>struct push_front_impl<aux::vector_tag<11> >;
template<typename V>struct v_at<V,12>{typedef typename V::item12 type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12>struct vector13;
template<>struct push_front_impl<aux::vector_tag<12> >;
template<typename V>struct v_at<V,13>{typedef typename V::item13 type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13>struct vector14;
template<>struct push_front_impl<aux::vector_tag<13> >;
template<typename V>struct v_at<V,14>{typedef typename V::item14 type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14>struct vector15;
template<>struct push_front_impl<aux::vector_tag<14> >;
template<typename V>struct v_at<V,15>{typedef typename V::item15 type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15>struct vector16;
template<>struct push_front_impl<aux::vector_tag<15> >;
template<typename V>struct v_at<V,16>{typedef typename V::item16 type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16>struct vector17;
template<>struct push_front_impl<aux::vector_tag<16> >;
template<typename V>struct v_at<V,17>{typedef typename V::item17 type;};
template<>struct push_front_impl<aux::vector_tag<17> >;
template<typename V>struct v_at<V,18>{typedef typename V::item18 type;};
template<>struct push_front_impl<aux::vector_tag<18> >;
template<typename V>struct v_at<V,19>{typedef typename V::item19 type;};
template<>struct push_front_impl<aux::vector_tag<19> >;
template<typename V>struct v_at<V,20>{typedef typename V::item20 type;};
template<typename T0=na,typename T1=na,typename T2=na,typename T3=na,typename T4=na,typename T5=na,typename T6=na,typename T7=na,typename T8=na,typename T9=na,typename T10=na,typename T11=na,typename T12=na,typename T13=na,typename T14=na,typename T15=na,typename T16=na,typename T17=na,typename T18=na,typename T19=na>struct vector;
template<>struct vector<na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na>:vector0<>{typedef vector0<>::type type;};
template<typename T0>struct vector<T0,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na>:vector1<T0>{typedef typename vector1<T0>::type type;};
template<typename T0,typename T1>struct vector<T0,T1,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na>:vector2<T0,T1>{typedef typename vector2<T0,T1>::type type;};
template<typename T0,typename T1,typename T2>struct vector<T0,T1,T2,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na>:vector3<T0,T1,T2>{typedef typename vector3<T0,T1,T2>::type type;};
template<typename T0,typename T1,typename T2,typename T3>struct vector<T0,T1,T2,T3,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na>:vector4<T0,T1,T2,T3>{typedef typename vector4<T0,T1,T2,T3>::type type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4>struct vector<T0,T1,T2,T3,T4,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na>:vector5<T0,T1,T2,T3,T4>{typedef typename vector5<T0,T1,T2,T3,T4>::type type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5>struct vector<T0,T1,T2,T3,T4,T5,na,na,na,na,na,na,na,na,na,na,na,na,na,na>:vector6<T0,T1,T2,T3,T4,T5>{typedef typename vector6<T0,T1,T2,T3,T4,T5>::type type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6>struct vector<T0,T1,T2,T3,T4,T5,T6,na,na,na,na,na,na,na,na,na,na,na,na,na>:vector7<T0,T1,T2,T3,T4,T5,T6>{typedef typename vector7<T0,T1,T2,T3,T4,T5,T6>::type type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7>struct vector<T0,T1,T2,T3,T4,T5,T6,T7,na,na,na,na,na,na,na,na,na,na,na,na>:vector8<T0,T1,T2,T3,T4,T5,T6,T7>{typedef typename vector8<T0,T1,T2,T3,T4,T5,T6,T7>::type type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8>struct vector<T0,T1,T2,T3,T4,T5,T6,T7,T8,na,na,na,na,na,na,na,na,na,na,na>:vector9<T0,T1,T2,T3,T4,T5,T6,T7,T8>{typedef typename vector9<T0,T1,T2,T3,T4,T5,T6,T7,T8>::type type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9>struct vector<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,na,na,na,na,na,na,na,na,na,na>:vector10<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9>{typedef typename vector10<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9>::type type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10>struct vector<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,na,na,na,na,na,na,na,na,na>:vector11<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10>{typedef typename vector11<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10>::type type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11>struct vector<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,na,na,na,na,na,na,na,na>:vector12<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11>{typedef typename vector12<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11>::type type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12>struct vector<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,na,na,na,na,na,na,na>:vector13<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12>{typedef typename vector13<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12>::type type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13>struct vector<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,na,na,na,na,na,na>:vector14<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13>{typedef typename vector14<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13>::type type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14>struct vector<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,na,na,na,na,na>:vector15<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14>{typedef typename vector15<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14>::type type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15>struct vector<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,na,na,na,na>:vector16<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15>{typedef typename vector16<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15>::type type;};
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16>struct vector<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,na,na,na>:vector17<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16>{typedef typename vector17<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16>::type type;};



}namespace multi_index{template<typename T0,typename T1=mpl::na,typename T2=mpl::na,typename T3=mpl::na,typename T4=mpl::na,typename T5=mpl::na,typename T6=mpl::na,typename T7=mpl::na,typename T8=mpl::na,typename T9=mpl::na,typename T10=mpl::na,typename T11=mpl::na,typename T12=mpl::na,typename T13=mpl::na,typename T14=mpl::na,typename T15=mpl::na,typename T16=mpl::na,typename T17=mpl::na,typename T18=mpl::na,typename T19=mpl::na>struct indexed_by:mpl::vector<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19>{};
}namespace mpl{namespace aux{template<int N,typename First,typename Last,typename State,typename ForwardOp>struct fold_impl;
template<typename First,typename Last,typename State,typename ForwardOp>struct fold_impl<0,First,Last,State,ForwardOp>{typedef First iter0;typedef State state0;typedef state0 state;typedef iter0 iterator;};
template<typename First,typename Last,typename State,typename ForwardOp>struct fold_impl<1,First,Last,State,ForwardOp>;
template<typename First,typename Last,typename State,typename ForwardOp>struct fold_impl<2,First,Last,State,ForwardOp>{typedef First iter0;typedef State state0;typedef typename apply2<ForwardOp,state0,typename deref<iter0>::type>::type state1;typedef typename mpl::next<iter0>::type iter1;typedef typename apply2<ForwardOp,state1,typename deref<iter1>::type>::type state2;typedef typename mpl::next<iter1>::type iter2;typedef state2 state;typedef iter2 iterator;};
template<typename First,typename Last,typename State,typename ForwardOp>struct fold_impl<3,First,Last,State,ForwardOp>;
template<typename First,typename Last,typename State,typename ForwardOp>struct fold_impl<4,First,Last,State,ForwardOp>;
template<int N,typename First,typename Last,typename State,typename ForwardOp>struct fold_impl;
template<typename First,typename Last,typename State,typename ForwardOp>struct fold_impl<-1,First,Last,State,ForwardOp>:fold_impl<-1,typename mpl::next<First>::type,Last,typename apply2<ForwardOp,State,typename deref<First>::type>::type,ForwardOp>{};
template<typename Last,typename State,typename ForwardOp>struct fold_impl<-1,Last,Last,State,ForwardOp>{typedef State state;typedef Last iterator;};
}template<typename Sequence=na,typename State=na,typename ForwardOp=na>struct fold{typedef typename aux::fold_impl< ::boost::mpl::O1_size<Sequence>::value,typename begin<Sequence>::type,typename end<Sequence>::type,State,ForwardOp>::state type;};
template<>struct fold<na,na,na>{template<typename T1,typename T2,typename T3,typename T4=na,typename T5=na>struct apply:fold<T1,T2,T3>{};};
template<typename Tag>struct lambda<fold<na,na,na>,Tag>{typedef false_ is_le;typedef fold<na,na,na>result_;typedef fold<na,na,na>type;};
namespace aux{struct set_tag;
}template<typename Tag>struct has_key_impl;
template<typename AssociativeSequence,typename Key>struct has_key;
template<>struct has_key_impl<aux::set_tag>{template<typename Set,typename T>struct apply{static const bool value=(sizeof(Set::is_masked_(*static_cast<Set*>(0),static_cast<aux::type_wrapper<T>*>(0)))==sizeof(aux::no_tag));typedef bool_<value>type;};};
template<>struct at_impl<aux::set_tag>{template<typename Set,typename T>struct apply{typedef typename if_<has_key_impl<aux::set_tag>::apply<Set,T>,T,void_>::type type;};};
template<typename Dummy=na>struct set0{typedef set0<>item_;typedef aux::set_tag tag;typedef void_ last_masked_;typedef void_ item_type_;typedef item_type_ type;typedef long_<0>size;typedef long_<1>order;static aux::no_tag order_by_key_(set0<>const&,void const volatile*);static aux::yes_tag is_masked_(set0<>const&,void const volatile*);};
template<>struct clear_impl<aux::set_tag>{template<typename Set>struct apply{typedef set0<>type;};};
template<>struct size_impl<aux::set_tag>{template<typename Set>struct apply:Set::size{};};
template<>struct empty_impl<aux::set_tag>{template<typename Set>struct apply:not_<typename Set::size>{};};
template<typename T=na>struct base;
template<>struct base<na>;
template<typename Tag>struct lambda<base<na>,Tag>{typedef false_ is_le;typedef base<na>result_;typedef base<na>type;};
template<typename AssociativeSequence,typename T>struct value_type;
template<typename Tag>struct has_key_impl{template<typename AssociativeSequence,typename Key>struct apply;};
template<typename AssociativeSequence=na,typename Key=na>struct has_key:has_key_impl<typename sequence_tag<AssociativeSequence>::type>::template apply<AssociativeSequence,Key>{};
template<>struct has_key<na,na>{template<typename T1,typename T2,typename T3=na,typename T4=na,typename T5=na>struct apply:has_key<T1,T2>{};};
template<typename Tag>struct lambda<has_key<na,na>,Tag>{typedef false_ is_le;typedef has_key<na,na>result_;typedef has_key<na,na>type;};
template<typename Set,typename Tail>struct s_iter;
template<typename Set,typename Tail>struct next<s_iter<Set,Tail> >:eval_if<has_key<Set,typename Tail::next_::type>,identity<s_iter<Set,typename Tail::next_> >,next<s_iter<Set,typename Tail::next_> > >{};
template<typename Set>struct next<s_iter<Set,set0<> > >{typedef s_iter<Set,set0<> >type;};
template<typename Set,typename Tail>struct s_iter;
template<typename Set>struct s_iter<Set,set0<> >;
template<>struct begin_impl<aux::set_tag>{template<typename Set>struct apply{typedef s_iter<Set,Set>type;};};
template<>struct end_impl<aux::set_tag>{template<typename Set>struct apply{typedef s_iter<Set,set0<> >type;};};
}namespace multi_index{namespace detail{struct duplicate_tag_mark;
struct duplicate_tag_marker;
template<typename TagList>struct no_duplicate_tags{typedef typename mpl::fold<TagList,mpl::set0<>,duplicate_tag_marker>::type aux;static const bool value=!(mpl::has_key<aux,duplicate_tag_mark>::value);};
struct duplicate_tag_list_marker{template<typename MplSet,typename Index>struct apply:mpl::fold<typename Index::tag_list,MplSet,duplicate_tag_marker>{};};
template<typename IndexList>struct no_duplicate_tags_in_index_list{typedef typename mpl::fold<IndexList,mpl::set0<>,duplicate_tag_list_marker>::type aux;static const bool value=!(mpl::has_key<aux,duplicate_tag_mark>::value);};
}}namespace mpl{namespace aux{template<long N,typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_fold_impl;
template<typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_fold_impl<0,First,Last,State,BackwardOp,ForwardOp>{typedef First iter0;typedef State fwd_state0;typedef fwd_state0 bkwd_state0;typedef bkwd_state0 state;typedef iter0 iterator;};




template<long N,typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_fold_impl;

template<typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_fold_impl<-1,Last,Last,State,BackwardOp,ForwardOp>{typedef State state;typedef Last iterator;};
}template<typename Sequence=na,typename State=na,typename BackwardOp=na,typename ForwardOp=arg<1> >struct reverse_fold{typedef typename aux::reverse_fold_impl< ::boost::mpl::O1_size<Sequence>::value,typename begin<Sequence>::type,typename end<Sequence>::type,State,BackwardOp,ForwardOp>::state type;};
template<>struct reverse_fold<na,na,na>{template<typename T1,typename T2,typename T3,typename T4=na,typename T5=na>struct apply:reverse_fold<T1,T2,T3>{};};
template<typename Tag>struct lambda<reverse_fold<na,na,na>,Tag>{typedef false_ is_le;typedef reverse_fold<na,na,na>result_;typedef reverse_fold<na,na,na>type;};
template<typename Iterator=na>struct iterator_category;
template<>struct iterator_category<na>;
template<typename Tag>struct lambda<iterator_category<na>,Tag>{typedef false_ is_le;typedef iterator_category<na>result_;typedef iterator_category<na>type;};
template<typename N1=na,typename N2=na>struct min;
template<typename N1=na,typename N2=na>struct max;
template<>struct min<na,na>;
template<typename Tag>struct lambda<min<na,na>,Tag>{typedef false_ is_le;typedef min<na,na>result_;typedef min<na,na>type;};
template<>struct max<na,na>;
template<typename Tag>struct lambda<max<na,na>,Tag>{typedef false_ is_le;typedef max<na,na>result_;typedef max<na,na>type;};
template<typename Iter1,typename Iter2,typename Category>struct pair_iter;
template<typename Iter1,typename Iter2,typename C>struct deref<pair_iter<Iter1,Iter2,C> >{typedef pair<typename deref<Iter1>::type,typename deref<Iter2>::type>type;};
template<typename Iter1,typename Iter2,typename C>struct next<pair_iter<Iter1,Iter2,C> >{typedef typename mpl::next<Iter1>::type i1_;typedef typename mpl::next<Iter2>::type i2_;typedef pair_iter<i1_,i2_,C>type;};
template<typename Iter1,typename Iter2,typename C>struct prior<pair_iter<Iter1,Iter2,C> >;
template<typename Sequence1=na,typename Sequence2=na>struct pair_view;
template<>struct pair_view<na,na>;
template<typename Tag>struct lambda<pair_view<na,na>,Tag>{typedef false_ is_le;typedef pair_view<na,na>result_;typedef pair_view<na,na>type;};
template<typename T=na>struct is_sequence:not_<is_same<typename begin<T>::type,void_> >{};
template<>struct is_sequence<na>{template<typename T1,typename T2=na,typename T3=na,typename T4=na,typename T5=na>struct apply:is_sequence<T1>{};};
template<typename Tag>struct lambda<is_sequence<na>,Tag>{typedef false_ is_le;typedef is_sequence<na>result_;typedef is_sequence<na>type;};
template<typename Tag>struct has_push_back_impl{template<typename Seq>struct apply:aux::has_type<push_back<Seq,int> >{};};
template<typename Sequence=na,typename T=na>struct push_back;
template<typename Sequence=na>struct has_push_back:has_push_back_impl<typename sequence_tag<Sequence>::type>::template apply<Sequence>{};
template<>struct push_back<na,na>;
template<typename Tag>struct lambda<push_back<na,na>,Tag>{typedef false_ is_le;typedef push_back<na,na>result_;typedef push_back<na,na>type;};
template<>struct has_push_back<na>{template<typename T1,typename T2=na,typename T3=na,typename T4=na,typename T5=na>struct apply:has_push_back<T1>{};};
template<typename Tag>struct lambda<has_push_back<na>,Tag>{typedef false_ is_le;typedef has_push_back<na>result_;typedef has_push_back<na>type;};
template<typename Sequence,typename Operation>struct inserter{typedef Sequence state;typedef Operation operation;};
template<typename Sequence>struct back_inserter;
template<typename Tag>struct push_front_impl{template<typename Sequence,typename T>struct apply{};};
template<typename Sequence=na,typename T=na>struct push_front:push_front_impl<typename sequence_tag<Sequence>::type>::template apply<Sequence,T>{};
template<typename Sequence=na>struct has_push_front;
template<>struct push_front<na,na>{template<typename T1,typename T2,typename T3=na,typename T4=na,typename T5=na>struct apply:push_front<T1,T2>{};};
template<typename Tag>struct lambda<push_front<na,na>,Tag>{typedef false_ is_le;typedef push_front<na,na>result_;typedef push_front<na,na>type;};
template<>struct has_push_front<na>;
template<typename Tag>struct lambda<has_push_front<na>,Tag>{typedef false_ is_le;typedef has_push_front<na>result_;typedef has_push_front<na>type;};
template<typename Sequence>struct front_inserter:inserter<Sequence,push_front<> >{};
template<typename Tag>struct clear_impl{template<typename Sequence>struct apply;};
template<typename Sequence=na>struct clear:clear_impl<typename sequence_tag<Sequence>::type>::template apply<Sequence>{};
template<>struct clear<na>{template<typename T1,typename T2=na,typename T3=na,typename T4=na,typename T5=na>struct apply:clear<T1>{};};
template<typename Tag>struct lambda<clear<na>,Tag>{typedef false_ is_le;typedef clear<na>result_;typedef clear<na>type;};
namespace aux{template<typename Seq,typename Op,typename In>struct transform1_impl;
template<typename Seq,typename Op,typename In>struct reverse_transform1_impl:reverse_fold<Seq,typename In::state,bind2<typename lambda<typename In::operation>::type,_1,bind1<typename lambda<Op>::type,_2> > >{};
}template<typename P1=na,typename P2=na,typename P3=na>struct transform1:aux::transform1_impl<P1,P2,P3>{};
template<typename P1,typename P2>struct transform1<P1,P2,na>:if_<has_push_back<P1>,aux::transform1_impl<P1,P2,back_inserter<typename clear<P1>::type> >,aux::reverse_transform1_impl<P1,P2,front_inserter<typename clear<P1>::type> > >::type{};
template<typename P1=na,typename P2=na,typename P3=na>struct reverse_transform1;
template<typename P1,typename P2>struct reverse_transform1<P1,P2,na>;
template<>struct transform1<na,na,na>{template<typename T1,typename T2,typename T3,typename T4=na,typename T5=na>struct apply:transform1<T1,T2,T3>{};};
template<typename Tag>struct lambda<transform1<na,na,na>,Tag>{typedef false_ is_le;typedef transform1<na,na,na>result_;typedef transform1<na,na,na>type;};
template<>struct reverse_transform1<na,na,na>;
template<typename Tag>struct lambda<reverse_transform1<na,na,na>,Tag>{typedef false_ is_le;typedef reverse_transform1<na,na,na>result_;typedef reverse_transform1<na,na,na>type;};
template<typename P1=na,typename P2=na,typename P3=na,typename P4=na>struct transform2;
template<typename P1,typename P2,typename P3>struct transform2<P1,P2,P3,na>;
template<typename P1=na,typename P2=na,typename P3=na,typename P4=na>struct reverse_transform2;
template<typename P1,typename P2,typename P3>struct reverse_transform2<P1,P2,P3,na>;
template<>struct transform2<na,na,na,na>;
template<typename Tag>struct lambda<transform2<na,na,na,na>,Tag>{typedef false_ is_le;typedef transform2<na,na,na,na>result_;typedef transform2<na,na,na,na>type;};
template<>struct reverse_transform2<na,na,na,na>;
template<typename Tag>struct lambda<reverse_transform2<na,na,na,na>,Tag>{typedef false_ is_le;typedef reverse_transform2<na,na,na,na>result_;typedef reverse_transform2<na,na,na,na>type;};
template<typename Seq1=na,typename Seq2OrOperation=na,typename OperationOrInserter=na,typename Inserter=na>struct transform{typedef typename eval_if<or_<is_na<OperationOrInserter>,is_lambda_expression<Seq2OrOperation>,not_<is_sequence<Seq2OrOperation> > >,transform1<Seq1,Seq2OrOperation,OperationOrInserter>,transform2<Seq1,Seq2OrOperation,OperationOrInserter,Inserter> >::type type;};
template<>struct transform<na,na,na,na>{template<typename T1,typename T2,typename T3,typename T4,typename T5=na>struct apply:transform<T1,T2,T3,T4>{};};
template<typename Tag>struct lambda<transform<na,na,na,na>,Tag>{typedef false_ is_le;typedef transform<na,na,na,na>result_;typedef transform<na,na,na,na>type;};
template<typename Seq1=na,typename Seq2OrOperation=na,typename OperationOrInserter=na,typename Inserter=na>struct reverse_transform;
template<>struct reverse_transform<na,na,na,na>;
template<typename Tag>struct lambda<reverse_transform<na,na,na,na>,Tag>{typedef false_ is_le;typedef reverse_transform<na,na,na,na>result_;typedef reverse_transform<na,na,na,na>type;};
}namespace detail{template<typename B,typename D>struct bd_helper{template<typename T>static type_traits::yes_type check_sig(D const volatile*,T);static type_traits::no_type check_sig(B const volatile*,int);};
template<typename B,typename D>struct is_base_and_derived_impl2{struct Host{operator B const volatile*()const;operator D const volatile*();};static const bool value=sizeof(bd_helper<B,D>::check_sig(Host(),0))==sizeof(type_traits::yes_type);};
template<typename B,typename D>struct is_base_and_derived_impl3;
template<bool ic1,bool ic2,bool iss>struct is_base_and_derived_select{template<class T,class U>struct rebind{typedef is_base_and_derived_impl3<T,U>type;};};
template<>struct is_base_and_derived_select<true,true,false>{template<class T,class U>struct rebind{typedef is_base_and_derived_impl2<T,U>type;};};
template<typename B,typename D>struct is_base_and_derived_impl{typedef typename remove_cv<B>::type ncvB;typedef typename remove_cv<D>::type ncvD;typedef is_base_and_derived_select< ::boost::is_class<B>::value,::boost::is_class<D>::value,::boost::is_same<B,D>::value>selector;typedef typename selector::template rebind<ncvB,ncvD>binder;typedef typename binder::type bound_type;static const bool value=bound_type::value;};
}template<typename Base,typename Derived>struct is_base_and_derived: ::boost::integral_constant<bool,(::boost::detail::is_base_and_derived_impl<Base,Derived>::value)>{};
template<typename Base,typename Derived>struct is_base_and_derived<Base&,Derived>: ::boost::integral_constant<bool,false>{};
template<typename Base,typename Derived>struct is_base_and_derived<Base,Derived&>: ::boost::integral_constant<bool,false>{};
template<typename Base,typename Derived>struct is_base_and_derived<Base&,Derived&>: ::boost::integral_constant<bool,false>{};
namespace multi_index{namespace detail{struct tag_marker{};
template<typename T>struct is_tag{static const bool value=(is_base_and_derived<tag_marker,T>::value);};
}template<typename T0=mpl::na,typename T1=mpl::na,typename T2=mpl::na,typename T3=mpl::na,typename T4=mpl::na,typename T5=mpl::na,typename T6=mpl::na,typename T7=mpl::na,typename T8=mpl::na,typename T9=mpl::na,typename T10=mpl::na,typename T11=mpl::na,typename T12=mpl::na,typename T13=mpl::na,typename T14=mpl::na,typename T15=mpl::na,typename T16=mpl::na,typename T17=mpl::na,typename T18=mpl::na,typename T19=mpl::na>struct tag:private detail::tag_marker{typedef typename mpl::transform<mpl::vector<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19>,mpl::identity<mpl::_1> >::type type;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(detail::no_duplicate_tags<type>::value)>)>boost_static_assert_typedef_1;};
namespace detail{template<typename KeyFromValue>struct index_args_default_compare{typedef std::less<typename KeyFromValue::result_type>type;};
template<typename Arg1,typename Arg2,typename Arg3>struct ordered_index_args{typedef is_tag<Arg1>full_form;typedef typename mpl::if_<full_form,Arg1,tag<> >::type tag_list_type;typedef typename mpl::if_<full_form,Arg2,Arg1>::type key_from_value_type;typedef typename mpl::if_<full_form,Arg3,Arg2>::type supplied_compare_type;typedef typename mpl::eval_if<mpl::is_na<supplied_compare_type>,index_args_default_compare<key_from_value_type>,mpl::identity<supplied_compare_type> >::type compare_type;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(is_tag<tag_list_type>::value)>)>boost_static_assert_typedef_2;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(!mpl::is_na<key_from_value_type>::value)>)>boost_static_assert_typedef_3;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(!mpl::is_na<compare_type>::value)>)>boost_static_assert_typedef_4;};
template<typename KeyFromValue,typename Compare,typename SuperMeta,typename TagList,typename Category>class ordered_index;







}template<typename Arg1,typename Arg2=mpl::na,typename Arg3=mpl::na>struct ordered_unique;
template<typename Arg1,typename Arg2=mpl::na,typename Arg3=mpl::na>struct ordered_non_unique;
template<typename Value,typename IndexSpecifierList=indexed_by<ordered_unique<identity<Value> > >,typename Allocator=std::allocator<Value> >class multi_index_container;
template<typename MultiIndexContainer,int N>struct nth_index;
template<typename MultiIndexContainer,typename Tag>struct index;
template<typename MultiIndexContainer,int N>struct nth_index_iterator;
template<typename MultiIndexContainer,int N>struct nth_index_const_iterator;
template<typename MultiIndexContainer,typename Tag>struct index_iterator;
template<typename MultiIndexContainer,typename Tag>struct index_const_iterator;






}using multi_index::multi_index_container;
namespace type_traits{struct false_result{template<typename T>struct result_{static const bool value=false;};};
no_type __cdecl is_mem_fun_pointer_tester(...);
}namespace detail{template<bool>struct is_mem_fun_pointer_select: ::boost::type_traits::false_result{};
template<>struct is_mem_fun_pointer_select<false>{template<typename T>struct result_{static T*make_t;typedef result_<T>self_type;static const bool value=(1==sizeof(::boost::type_traits::is_mem_fun_pointer_tester(self_type::make_t)));};};
template<typename T>struct is_member_function_pointer_impl:is_mem_fun_pointer_select< ::boost::type_traits::ice_or< ::boost::is_reference<T>::value,::boost::is_array<T>::value>::value>::template result_<T>{};
template<typename T>struct is_member_function_pointer_impl<T&>:public false_type{};
template<>struct is_member_function_pointer_impl<void>{static const bool value=(false);};
template<>struct is_member_function_pointer_impl<void const>{static const bool value=(false);};
template<>struct is_member_function_pointer_impl<void volatile>{static const bool value=(false);};
template<>struct is_member_function_pointer_impl<void const volatile>{static const bool value=(false);};
}template<typename T>struct is_member_function_pointer: ::boost::integral_constant<bool,::boost::detail::is_member_function_pointer_impl<T>::value>{};
template<typename T>struct is_member_pointer: ::boost::integral_constant<bool,::boost::is_member_function_pointer<T>::value>{};
template<typename T,typename U>struct is_member_pointer<U T::*>: ::boost::integral_constant<bool,true>{};
namespace detail{template<typename T>struct is_pointer_helper{static const bool value=false;};
template<typename T>struct is_pointer_helper<T*>{static const bool value=true;};
template<typename T>struct is_pointer_helper<T*const>{static const bool value=true;};
template<typename T>struct is_pointer_helper<T*volatile>{static const bool value=true;};
template<typename T>struct is_pointer_helper<T*const volatile>{static const bool value=true;};
template<typename T>struct is_pointer_impl{static const bool value=(::boost::type_traits::ice_and< ::boost::detail::is_pointer_helper<T>::value,::boost::type_traits::ice_not< ::boost::is_member_pointer<T>::value>::value>::value);};
}template<typename T>struct is_pointer: ::boost::integral_constant<bool,::boost::detail::is_pointer_impl<T>::value>{};
namespace detail{template<typename T,bool small_>struct ct_imp2{typedef const T&param_type;};
template<typename T>struct ct_imp2<T,true>{typedef const T param_type;};
template<typename T,bool isp,bool b1>struct ct_imp{typedef const T&param_type;};
template<typename T,bool isp>struct ct_imp<T,isp,true>{typedef typename ct_imp2<T,sizeof(T)<=sizeof(void*)>::param_type param_type;};
template<typename T,bool b1>struct ct_imp<T,true,b1>{typedef const T param_type;};
}template<typename T>struct call_traits{public:typedef T value_type;typedef T&reference;typedef const T&const_reference;typedef typename boost::detail::ct_imp<T,::boost::is_pointer<T>::value,::boost::is_arithmetic<T>::value>::param_type param_type;};
template<typename T>struct call_traits<T&>{typedef T&value_type;typedef T&reference;typedef const T&const_reference;typedef T&param_type;};
template<typename T,std::size_t N>struct call_traits<T[N]>;
template<typename T,std::size_t N>struct call_traits<const T[N]>;
namespace noncopyable_{class noncopyable{protected:noncopyable(){}~noncopyable(){}private:noncopyable(const noncopyable&);const noncopyable&operator=(const noncopyable&);};
}typedef noncopyable_::noncopyable noncopyable;
namespace multi_index{namespace detail{template<typename T,typename Allocator=std::allocator<T> >struct auto_space:private noncopyable{explicit auto_space(const Allocator&al=Allocator(),std::size_t n=1):al_(al),n_(n),data_(n_?al_.allocate(n_):0){}~auto_space(){if(n_)al_.deallocate(data_,n_);}Allocator get_allocator()const{return al_;}T*data()const{return data_;}void swap(auto_space&x){std::swap(n_,x.n_);std::swap(data_,x.data_);}private:typename boost::detail::allocator::rebind_to<Allocator,T>::type al_;std::size_t n_;T*data_;};
template<typename T,typename Allocator>void swap(auto_space<T,Allocator>&x,auto_space<T,Allocator>&y){x.swap(y);}
template<typename Node,typename Allocator>class copy_map;
}}namespace mpl{namespace aux{template<long N,typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_iter_fold_impl;
template<typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_iter_fold_impl<0,First,Last,State,BackwardOp,ForwardOp>{typedef First iter0;typedef State fwd_state0;typedef fwd_state0 bkwd_state0;typedef bkwd_state0 state;typedef iter0 iterator;};

template<typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_iter_fold_impl<2,First,Last,State,BackwardOp,ForwardOp>{typedef First iter0;typedef State fwd_state0;typedef typename apply2<ForwardOp,fwd_state0,iter0>::type fwd_state1;typedef typename mpl::next<iter0>::type iter1;typedef typename apply2<ForwardOp,fwd_state1,iter1>::type fwd_state2;typedef typename mpl::next<iter1>::type iter2;typedef fwd_state2 bkwd_state2;typedef typename apply2<BackwardOp,bkwd_state2,iter1>::type bkwd_state1;typedef typename apply2<BackwardOp,bkwd_state1,iter0>::type bkwd_state0;typedef bkwd_state0 state;typedef iter2 iterator;};


template<long N,typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_iter_fold_impl;

template<typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_iter_fold_impl<-1,Last,Last,State,BackwardOp,ForwardOp>{typedef State state;typedef Last iterator;};
}template<typename Sequence=na,typename State=na,typename BackwardOp=na,typename ForwardOp=arg<1> >struct reverse_iter_fold{typedef typename aux::reverse_iter_fold_impl< ::boost::mpl::O1_size<Sequence>::value,typename begin<Sequence>::type,typename end<Sequence>::type,State,typename lambda<BackwardOp>::type,typename lambda<ForwardOp>::type>::state type;};
template<>struct reverse_iter_fold<na,na,na>{template<typename T1,typename T2,typename T3,typename T4=na,typename T5=na>struct apply:reverse_iter_fold<T1,T2,T3>{};};
template<typename Tag>struct lambda<reverse_iter_fold<na,na,na>,Tag>{typedef false_ is_le;typedef reverse_iter_fold<na,na,na>result_;typedef reverse_iter_fold<na,na,na>type;};
}namespace multi_index{namespace detail{template<typename NodeType,typename Final>struct header_holder:private noncopyable{header_holder():member(final().allocate_node()){}~header_holder(){final().deallocate_node(member);}NodeType*member;private:Final&final(){return*static_cast<Final*>(this);}};
}}namespace mpl{template<std::size_t N>struct size_t;
template<std::size_t N>struct size_t{static const std::size_t value=N;typedef size_t type;typedef std::size_t value_type;typedef integral_c_tag tag;typedef boost::mpl::size_t<static_cast<std::size_t>((value+1))>next;typedef boost::mpl::size_t<static_cast<std::size_t>((value-1))>prior;operator std::size_t()const{return static_cast<std::size_t>(this->value);}};
template<std::size_t N>std::size_t const boost::mpl::size_t<N>::value;
}template<typename T>struct alignment_of;
namespace detail{template<typename T>struct alignment_of_hack{char c;T t;alignment_of_hack();};
template<unsigned A,unsigned S>struct alignment_logic{static const std::size_t value=A<S?A:S;};
template<typename T>struct alignment_of_impl{static const std::size_t value=(::boost::detail::alignment_logic<sizeof(::boost::detail::alignment_of_hack<T>)-sizeof(T),sizeof(T)>::value);};
}template<typename T>struct alignment_of: ::boost::integral_constant<std::size_t,::boost::detail::alignment_of_impl<T>::value>{};
template<typename T>struct alignment_of<T&>:alignment_of<T*>{};
template<>struct alignment_of<void>: ::boost::integral_constant<std::size_t,0>{};
template<>struct alignment_of<void const>: ::boost::integral_constant<std::size_t,0>{};
template<>struct alignment_of<void volatile>: ::boost::integral_constant<std::size_t,0>{};
template<>struct alignment_of<void const volatile>: ::boost::integral_constant<std::size_t,0>{};
namespace detail{class alignment_dummy;
typedef void(*function_ptr)();
typedef int(alignment_dummy::*member_ptr);
typedef int(alignment_dummy::*member_function_ptr)();
template<bool found,std::size_t target,class TestType>struct lower_alignment_helper{typedef char type;enum{value=true};};
template<std::size_t target,class TestType>struct lower_alignment_helper<false,target,TestType>{enum{value=(alignment_of<TestType>::value==target)};typedef typename mpl::if_c<value,TestType,char>::type type;};
template<typename T>struct has_one_T{T data;};
template<std::size_t target>union lower_alignment{enum{found0=false};typename lower_alignment_helper<found0,target,char>::type t0;enum{found1=lower_alignment_helper<found0,target,char>::value};typename lower_alignment_helper<found1,target,short>::type t1;enum{found2=lower_alignment_helper<found1,target,short>::value};typename lower_alignment_helper<found2,target,int>::type t2;enum{found3=lower_alignment_helper<found2,target,int>::value};typename lower_alignment_helper<found3,target,long>::type t3;enum{found4=lower_alignment_helper<found3,target,long>::value};typename lower_alignment_helper<found4,target,::boost::long_long_type>::type t4;enum{found5=lower_alignment_helper<found4,target,::boost::long_long_type>::value};typename lower_alignment_helper<found5,target,float>::type t5;enum{found6=lower_alignment_helper<found5,target,float>::value};typename lower_alignment_helper<found6,target,double>::type t6;enum{found7=lower_alignment_helper<found6,target,double>::value};typename lower_alignment_helper<found7,target,long double>::type t7;enum{found8=lower_alignment_helper<found7,target,long double>::value};typename lower_alignment_helper<found8,target,void*>::type t8;enum{found9=lower_alignment_helper<found8,target,void*>::value};typename lower_alignment_helper<found9,target,function_ptr>::type t9;enum{found10=lower_alignment_helper<found9,target,function_ptr>::value};typename lower_alignment_helper<found10,target,member_ptr>::type t10;enum{found11=lower_alignment_helper<found10,target,member_ptr>::value};typename lower_alignment_helper<found11,target,member_function_ptr>::type t11;enum{found12=lower_alignment_helper<found11,target,member_function_ptr>::value};typename lower_alignment_helper<found12,target,boost::detail::has_one_T<char> >::type t12;enum{found13=lower_alignment_helper<found12,target,boost::detail::has_one_T<char> >::value};typename lower_alignment_helper<found13,target,boost::detail::has_one_T<short> >::type t13;enum{found14=lower_alignment_helper<found13,target,boost::detail::has_one_T<short> >::value};typename lower_alignment_helper<found14,target,boost::detail::has_one_T<int> >::type t14;enum{found15=lower_alignment_helper<found14,target,boost::detail::has_one_T<int> >::value};typename lower_alignment_helper<found15,target,boost::detail::has_one_T<long> >::type t15;enum{found16=lower_alignment_helper<found15,target,boost::detail::has_one_T<long> >::value};typename lower_alignment_helper<found16,target,boost::detail::has_one_T< ::boost::long_long_type> >::type t16;enum{found17=lower_alignment_helper<found16,target,boost::detail::has_one_T< ::boost::long_long_type> >::value};typename lower_alignment_helper<found17,target,boost::detail::has_one_T<float> >::type t17;enum{found18=lower_alignment_helper<found17,target,boost::detail::has_one_T<float> >::value};typename lower_alignment_helper<found18,target,boost::detail::has_one_T<double> >::type t18;enum{found19=lower_alignment_helper<found18,target,boost::detail::has_one_T<double> >::value};typename lower_alignment_helper<found19,target,boost::detail::has_one_T<long double> >::type t19;enum{found20=lower_alignment_helper<found19,target,boost::detail::has_one_T<long double> >::value};typename lower_alignment_helper<found20,target,boost::detail::has_one_T<void*> >::type t20;enum{found21=lower_alignment_helper<found20,target,boost::detail::has_one_T<void*> >::value};typename lower_alignment_helper<found21,target,boost::detail::has_one_T<function_ptr> >::type t21;enum{found22=lower_alignment_helper<found21,target,boost::detail::has_one_T<function_ptr> >::value};typename lower_alignment_helper<found22,target,boost::detail::has_one_T<member_ptr> >::type t22;enum{found23=lower_alignment_helper<found22,target,boost::detail::has_one_T<member_ptr> >::value};typename lower_alignment_helper<found23,target,boost::detail::has_one_T<member_function_ptr> >::type t23;enum{found24=lower_alignment_helper<found23,target,boost::detail::has_one_T<member_function_ptr> >::value};};
union max_align{char t0;short t1;int t2;long t3;::boost::long_long_type t4;float t5;double t6;long double t7;void*t8;function_ptr t9;member_ptr t10;member_function_ptr t11;boost::detail::has_one_T<char>t12;boost::detail::has_one_T<short>t13;boost::detail::has_one_T<int>t14;boost::detail::has_one_T<long>t15;boost::detail::has_one_T< ::boost::long_long_type>t16;boost::detail::has_one_T<float>t17;boost::detail::has_one_T<double>t18;boost::detail::has_one_T<long double>t19;boost::detail::has_one_T<void*>t20;boost::detail::has_one_T<function_ptr>t21;boost::detail::has_one_T<member_ptr>t22;boost::detail::has_one_T<member_function_ptr>t23;};
template<std::size_t TAlign,std::size_t Align>struct is_aligned{static const bool value=(TAlign>=Align)&(TAlign%Align==0);};
}template<std::size_t Align>class type_with_alignment{typedef::boost::detail::lower_alignment<Align>t1;typedef typename mpl::if_c< ::boost::detail::is_aligned< ::boost::alignment_of<t1>::value,Align>::value,t1,::boost::detail::max_align>::type align_t;static const std::size_t found=alignment_of<align_t>::value;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(found>=Align)>)>boost_static_assert_typedef_5;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(found%Align==0)>)>boost_static_assert_typedef_6;public:typedef align_t type;};
namespace detail{namespace aligned_storage{static const std::size_t alignment_of_max_align=::boost::alignment_of<max_align>::value;
template<std::size_t size_,std::size_t alignment_>struct aligned_storage_imp{union data_t{char buf[size_];typename mpl::eval_if_c<alignment_==std::size_t(-1),mpl::identity<detail::max_align>,type_with_alignment<alignment_> >::type align_;}data_;};
}}template<std::size_t size_,std::size_t alignment_=std::size_t(-1)>class aligned_storage{private:detail::aligned_storage::aligned_storage_imp<size_,alignment_>data_;public:typedef detail::aligned_storage::aligned_storage_imp<size_,alignment_>type;static const std::size_t size=size_;static const std::size_t alignment=(alignment_==std::size_t(-1)?::boost::detail::aligned_storage::alignment_of_max_align:alignment_);public:aligned_storage(const aligned_storage&);aligned_storage&operator=(const aligned_storage&);public:aligned_storage(){}~aligned_storage(){}public:void*address(){return this;}const void*address()const{return this;}};
namespace multi_index{namespace detail{template<typename Value>struct pod_value_holder{typename aligned_storage<sizeof(Value),alignment_of<Value>::value>::type space;};
template<typename Value>struct index_node_base:private pod_value_holder<Value>{typedef index_node_base base_type;typedef Value value_type;value_type&value(){return*static_cast<value_type*>(static_cast<void*>(&this->space));}const value_type&value()const{return*static_cast<const value_type*>(static_cast<const void*>(&this->space));}static index_node_base*from_value(const value_type*p){return static_cast<index_node_base*>(reinterpret_cast<pod_value_holder<Value>*>(const_cast<value_type*>(p)));}private:};
}}namespace mpl{template<typename Tag>struct empty_impl{template<typename Sequence>struct apply:is_same<typename begin<Sequence>::type,typename end<Sequence>::type>{};};
template<typename Sequence=na>struct empty:empty_impl<typename sequence_tag<Sequence>::type>::template apply<Sequence>{};
template<>struct empty<na>{template<typename T1,typename T2=na,typename T3=na,typename T4=na,typename T5=na>struct apply:empty<T1>{};};
template<typename Tag>struct lambda<empty<na>,Tag>{typedef false_ is_le;typedef empty<na>result_;typedef empty<na>type;};
}namespace multi_index{namespace detail{template<typename T>struct is_index_list{static const bool mpl_sequence=mpl::is_sequence<T>::value;static const bool non_empty=!mpl::empty<T>::value;static const bool value=mpl_sequence&&non_empty;};
struct index_node_applier{template<typename IndexSpecifierIterator,typename Super>struct apply{typedef typename mpl::deref<IndexSpecifierIterator>::type index_specifier;typedef typename index_specifier::template node_class<Super>::type type;};};
template<typename Value,typename IndexSpecifierList,typename Allocator>struct multi_index_node_type{typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(detail::is_index_list<IndexSpecifierList>::value)>)>boost_static_assert_typedef_7;typedef typename mpl::reverse_iter_fold<IndexSpecifierList,index_node_base<Value>,mpl::bind2<index_node_applier,mpl::_2,mpl::_1> >::type type;};
}}template<typename T>T*addressof(T&v){return reinterpret_cast<T*>(&const_cast<char&>(reinterpret_cast<const volatile char&>(v)));}
template<class T>class reference_wrapper{public:typedef T type;explicit reference_wrapper(T&t):t_(boost::addressof(t)){}operator T&()const{return*t_;}T&get()const{return*t_;}T*get_pointer()const{return t_;}private:T*t_;};
template<class T>inline reference_wrapper<T>const ref(T&t){return reference_wrapper<T>(t);}
namespace tuples{struct null_type;
template<class HT,class TT>struct cons;
template<class T0=null_type,class T1=null_type,class T2=null_type,class T3=null_type,class T4=null_type,class T5=null_type,class T6=null_type,class T7=null_type,class T8=null_type,class T9=null_type>class tuple;
namespace detail{template<int N>struct get_class;
template<>struct get_class<0>;
}template<int N,class T>struct element;
template<class T>struct element<0,T>;
template<int N,class T>struct element<N,const T>;
template<class T>struct element<0,const T>;
template<class T>struct access_traits;
template<class T>struct access_traits<T&>;

template<int N,class HT,class TT>inline typename access_traits<typename element<N,cons<HT,TT> >::type>::const_type get(const cons<HT,TT>&c){return detail::get_class<N>::template get<typename access_traits<typename element<N,cons<HT,TT> >::type>::const_type,HT,TT>(c);}
template<class HT,class TT>struct cons;
template<class HT>struct cons<HT,null_type>;
template<class T0,class T1,class T2,class T3,class T4,class T5,class T6,class T7,class T8,class T9>class tuple;
template<>class tuple<null_type,null_type,null_type,null_type,null_type,null_type,null_type,null_type,null_type,null_type>;
}using tuples::tuple;
using tuples::get;
namespace multi_index{namespace detail{template<typename Value,typename IndexSpecifierList,typename Allocator>class index_base{protected:typedef index_node_base<Value>node_type;typedef typename multi_index_node_type<Value,IndexSpecifierList,Allocator>::type final_node_type;typedef multi_index_container<Value,IndexSpecifierList,Allocator>final_type;typedef tuples::null_type ctor_args_list;typedef typename boost::detail::allocator::rebind_to<Allocator,typename Allocator::value_type>::type final_allocator_type;typedef mpl::vector0<>index_type_list;typedef mpl::vector0<>iterator_type_list;typedef mpl::vector0<>const_iterator_type_list;typedef copy_map<final_node_type,final_allocator_type>copy_map_type;private:typedef typename call_traits<Value>::param_type value_param_type;protected:explicit index_base(const ctor_args_list&,const Allocator&);void copy_(const index_base<Value,IndexSpecifierList,Allocator>&,const copy_map_type&);node_type*insert_(value_param_type v,node_type*x);node_type*insert_(value_param_type v,node_type*,node_type*x);void erase_(node_type*x);void delete_node_(node_type*x);void clear_();void swap_(index_base<Value,IndexSpecifierList,Allocator>&);bool replace_(value_param_type v,node_type*x);bool modify_(node_type*);final_type&final(){return*static_cast<final_type*>(this);}const final_type&final()const{return*static_cast<const final_type*>(this);}final_node_type*final_header()const{return final().header();}bool final_empty_()const;std::size_t final_size_()const;std::size_t final_max_size_()const;std::pair<final_node_type*,bool>final_insert_(value_param_type x){return final().insert_(x);}std::pair<final_node_type*,bool>final_insert_(value_param_type x,final_node_type*position){return final().insert_(x,position);}void final_erase_(final_node_type*x);void final_delete_node_(final_node_type*x);void final_delete_all_nodes_();void final_clear_();void final_swap_(final_type&x);bool final_replace_(value_param_type k,final_node_type*x);template<typename Modifier>bool final_modify_(Modifier mod,final_node_type*x){return final().modify_(mod,x);}};
struct index_applier{template<typename IndexSpecifierMeta,typename SuperMeta>struct apply{typedef typename IndexSpecifierMeta::type index_specifier;typedef typename index_specifier::template index_class<SuperMeta>::type type;};};
template<int N,typename Value,typename IndexSpecifierList,typename Allocator>struct nth_layer{static const int length=mpl::size<IndexSpecifierList>::value;typedef typename mpl::eval_if_c<N==length,mpl::identity<index_base<Value,IndexSpecifierList,Allocator> >,mpl::apply2<index_applier,mpl::at_c<IndexSpecifierList,N>,nth_layer<N+1,Value,IndexSpecifierList,Allocator> > >::type type;};
template<typename Value,typename IndexSpecifierList,typename Allocator>struct multi_index_base_type:nth_layer<0,Value,IndexSpecifierList,Allocator>{typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(detail::is_index_list<IndexSpecifierList>::value)>)>boost_static_assert_typedef_10;};
template<typename MultiIndexContainer,typename Index>struct converter;
template<typename Cons>struct default_constructible_tuple_cons;
template<>struct default_constructible_tuple_cons<tuples::null_type>;
template<typename Tag>struct has_tag;
}}template<typename MemberType,int UniqueID=0>class base_from_member{protected:MemberType member;base_from_member():member(){}template<typename T0>explicit base_from_member(T0 x0):member(x0){}template<typename T0,typename T1>explicit base_from_member(T0 x0,T1 x1):member(x0,x1){}template<typename T0,typename T1,typename T2>explicit base_from_member(T0 x0,T1 x1,T2 x2):member(x0,x1,x2){}template<typename T0,typename T1,typename T2,typename T3>explicit base_from_member(T0 x0,T1 x1,T2 x2,T3 x3):member(x0,x1,x2,x3){}template<typename T0,typename T1,typename T2,typename T3,typename T4>explicit base_from_member(T0 x0,T1 x1,T2 x2,T3 x3,T4 x4):member(x0,x1,x2,x3,x4){}template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5>explicit base_from_member(T0 x0,T1 x1,T2 x2,T3 x3,T4 x4,T5 x5):member(x0,x1,x2,x3,x4,x5){}template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6>explicit base_from_member(T0 x0,T1 x1,T2 x2,T3 x3,T4 x4,T5 x5,T6 x6):member(x0,x1,x2,x3,x4,x5,x6){}template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7>explicit base_from_member(T0 x0,T1 x1,T2 x2,T3 x3,T4 x4,T5 x5,T6 x6,T7 x7):member(x0,x1,x2,x3,x4,x5,x6,x7){}template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8>explicit base_from_member(T0 x0,T1 x1,T2 x2,T3 x3,T4 x4,T5 x5,T6 x6,T7 x7,T8 x8):member(x0,x1,x2,x3,x4,x5,x6,x7,x8){}template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9>explicit base_from_member(T0 x0,T1 x1,T2 x2,T3 x3,T4 x4,T5 x5,T6 x6,T7 x7,T8 x8,T9 x9):member(x0,x1,x2,x3,x4,x5,x6,x7,x8,x9){}};
namespace multi_index{template<typename Value,typename IndexSpecifierList,typename Allocator>class multi_index_container:private::boost::base_from_member<typename boost::detail::allocator::rebind_to<Allocator,typename detail::multi_index_node_type<Value,IndexSpecifierList,Allocator>::type>::type>,private detail::header_holder<typename detail::multi_index_node_type<Value,IndexSpecifierList,Allocator>::type,multi_index_container<Value,IndexSpecifierList,Allocator> >,public detail::multi_index_base_type<Value,IndexSpecifierList,Allocator>::type{private:template<typename,typename,typename>friend class detail::index_base;template<typename,typename>friend class detail::header_holder;template<typename,typename>friend class detail::converter;typedef typename detail::multi_index_base_type<Value,IndexSpecifierList,Allocator>::type super;typedef::boost::base_from_member<typename boost::detail::allocator::rebind_to<Allocator,typename super::node_type>::type>bfm_allocator;typedef detail::header_holder<typename super::node_type,multi_index_container>bfm_header;public:typedef detail::default_constructible_tuple_cons<typename super::ctor_args_list>ctor_args_list;typedef IndexSpecifierList index_specifier_type_list;typedef typename super::index_type_list index_type_list;typedef typename super::iterator_type_list iterator_type_list;typedef typename super::const_iterator_type_list const_iterator_type_list;typedef typename super::value_type value_type;typedef typename super::final_allocator_type allocator_type;typedef typename super::iterator iterator;typedef typename super::const_iterator const_iterator;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(detail::no_duplicate_tags_in_index_list<index_type_list>::value)>)>boost_static_assert_typedef_11;typedef typename super::node_type node_type;explicit multi_index_container(const ctor_args_list&args_list=ctor_args_list(),const allocator_type&al=allocator_type());template<typename InputIterator>multi_index_container(InputIterator first,InputIterator last,const ctor_args_list&args_list=ctor_args_list(),const allocator_type&al=allocator_type());multi_index_container(const multi_index_container<Value,IndexSpecifierList,Allocator>&x);~multi_index_container();multi_index_container<Value,IndexSpecifierList,Allocator>&operator=(const multi_index_container<Value,IndexSpecifierList,Allocator>&x);allocator_type get_allocator()const;template<int N>struct nth_index{typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(N>=0&&N<mpl::size<index_type_list>::type::value)>)>boost_static_assert_typedef_12;typedef typename mpl::at_c<index_type_list,N>::type type;};template<int N>typename nth_index<N>::type&get(){typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(N>=0&&N<mpl::size<index_type_list>::type::value)>)>boost_static_assert_typedef_13;return*this;}template<int N>const typename nth_index<N>::type&get()const{typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(N>=0&&N<mpl::size<index_type_list>::type::value)>)>boost_static_assert_typedef_14;return*this;}template<typename Tag>struct index{typedef typename mpl::find_if<index_type_list,detail::has_tag<Tag> >::type iter;static const bool index_found=!(is_same<iter,typename mpl::end<index_type_list>::type>::value);typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(index_found)>)>boost_static_assert_typedef_15;typedef typename mpl::deref<iter>::type type;};template<typename Tag>typename index<Tag>::type&get(){return*this;}template<typename Tag>const typename index<Tag>::type&get()const{return*this;}template<int N>struct nth_index_iterator{typedef typename nth_index<N>::type::iterator type;};template<int N>struct nth_index_const_iterator{typedef typename nth_index<N>::type::const_iterator type;};template<int N,typename IteratorType>typename nth_index_iterator<N>::type project(IteratorType it);template<int N,typename IteratorType>typename nth_index_const_iterator<N>::type project(IteratorType it)const;template<typename Tag>struct index_iterator{typedef typename index<Tag>::type::iterator type;};template<typename Tag>struct index_const_iterator{typedef typename index<Tag>::type::const_iterator type;};template<typename Tag,typename IteratorType>typename index_iterator<Tag>::type project(IteratorType it);template<typename Tag,typename IteratorType>typename index_const_iterator<Tag>::type project(IteratorType it)const;protected:typedef typename super::copy_map_type copy_map_type;node_type*header()const{return bfm_header::member;}node_type*allocate_node();void deallocate_node(node_type*x);bool empty_()const;std::size_t size_()const;std::size_t max_size_()const;std::pair<node_type*,bool>insert_(const Value&v);std::pair<node_type*,bool>insert_(const Value&v,node_type*position);void erase_(node_type*x);void delete_node_(node_type*x);void delete_all_nodes_();void clear_();void swap_(multi_index_container<Value,IndexSpecifierList,Allocator>&x);bool replace_(const Value&k,node_type*x);template<typename Modifier>bool modify_(Modifier mod,node_type*x);private:std::size_t node_count;};
template<typename MultiIndexContainer,int N>struct nth_index;


template<typename MultiIndexContainer,typename Tag>struct index;
template<typename Tag,typename Value,typename IndexSpecifierList,typename Allocator>typename::boost::multi_index::index<multi_index_container<Value,IndexSpecifierList,Allocator>,Tag>::type&get(multi_index_container<Value,IndexSpecifierList,Allocator>&m){typedef multi_index_container<Value,IndexSpecifierList,Allocator>multi_index_type;typedef typename::boost::multi_index::index<multi_index_container<Value,IndexSpecifierList,Allocator>,Tag>::type index;return detail::converter<multi_index_type,index>::index(m);}

template<typename MultiIndexContainer,int N>struct nth_index_iterator;
template<typename MultiIndexContainer,int N>struct nth_index_const_iterator;


template<typename MultiIndexContainer,typename Tag>struct index_iterator;
template<typename MultiIndexContainer,typename Tag>struct index_const_iterator;








}using multi_index::get;
namespace detail{template<class Category,class T,class Distance,class Pointer,class Reference>struct iterator_base:std::iterator<Category,T,Distance,Pointer,Reference>{};
}template<class Category,class T,class Distance=std::ptrdiff_t,class Pointer=T*,class Reference=T&>struct iterator:boost::detail::iterator_base<Category,T,Distance,Pointer,Reference>{};

template<class T>inline T next(T x){return++x;}
template<class T,class Distance>inline T next(T x,Distance n){std::advance(x,n);return x;}
struct use_default;
namespace detail{
template<class Iterator>typename Iterator::value_type make_operator_brackets_result(Iterator const&iter,mpl::false_){return*iter;}
}









struct use_default;
template<class To>struct is_convertible<use_default,To>;
template<class Iterator>class reverse_iterator;
namespace detail{template<typename T>class empty_base{};
}template<class T,class B=::boost::detail::empty_base<T> >struct equality_comparable1:B{friend bool operator!=(const T&x,const T&y){return!(x==y);}};
template<class T,class B=::boost::detail::empty_base<T> >struct incrementable:B{friend T operator++(T&x,int){incrementable_type nrv(x);++x;return nrv;}private:typedef T incrementable_type;};
template<class T,class P,class B=::boost::detail::empty_base<T> >struct dereferenceable:B{P operator->()const{return&*static_cast<const T&>(*this);}};
template<class T,class P,class B=::boost::detail::empty_base<T> >struct input_iteratable:equality_comparable1<T,incrementable<T,dereferenceable<T,P,B> > >{};
template<class T,class P,class B=::boost::detail::empty_base<T> >struct forward_iteratable:input_iteratable<T,P,B>{};
template<class T,class V,class D=std::ptrdiff_t,class P=V*,class R=V&>struct forward_iterator_helper:forward_iteratable<T,P,boost::iterator<std::forward_iterator_tag,V,D,P,R> >{};
namespace multi_index{namespace detail{template<typename Node,typename Derived=mpl::na>class bidir_node_iterator;
template<int N>struct uintptr_candidates;
template<>struct uintptr_candidates<-1>{typedef unsigned int type;};
template<>struct uintptr_candidates<0>{typedef unsigned int type;};
template<>struct uintptr_candidates<1>{typedef unsigned short type;};
template<>struct uintptr_candidates<2>{typedef unsigned long type;};
template<>struct uintptr_candidates<3>{typedef unsigned long long type;};
struct uintptr_aux{static const int index=sizeof(void*)==sizeof(uintptr_candidates<0>::type)?0:sizeof(void*)==sizeof(uintptr_candidates<1>::type)?1:sizeof(void*)==sizeof(uintptr_candidates<2>::type)?2:sizeof(void*)==sizeof(uintptr_candidates<3>::type)?3:-1;static const bool has_uintptr_type=(index>=0);typedef uintptr_candidates<index>::type type;};
typedef mpl::bool_<uintptr_aux::has_uintptr_type>has_uintptr_type;
typedef uintptr_aux::type uintptr_type;
enum ordered_index_color{red=false,black=true};
enum ordered_index_side{to_left=false,to_right=true};
struct ordered_index_node_impl;
struct ordered_index_node_std_base;
struct ordered_index_node_compressed_base{struct color_ref{color_ref(uintptr_type*r_):r(r_){}operator ordered_index_color()const{return ordered_index_color(*r&uintptr_type(1));}color_ref&operator=(ordered_index_color c){*r&=~uintptr_type(1);*r|=uintptr_type(c);return*this;}color_ref&operator=(const color_ref&x){return operator=(x.operator ordered_index_color());}private:uintptr_type*r;};struct parent_ref{parent_ref(uintptr_type*r_):r(r_){}operator ordered_index_node_impl*()const{return(ordered_index_node_impl*)(void*)(*r&~uintptr_type(1));}parent_ref&operator=(ordered_index_node_impl*p){*r=((uintptr_type)(void*)p)|(*r&uintptr_type(1));return*this;}parent_ref&operator=(const parent_ref&x){return operator=(x.operator ordered_index_node_impl*());}ordered_index_node_impl*operator->()const{return operator ordered_index_node_impl*();}private:uintptr_type*r;};color_ref color(){return color_ref(&parentcolor_);}ordered_index_color color()const{return ordered_index_color(parentcolor_&std::size_t(1ul));}parent_ref parent(){return parent_ref(&parentcolor_);}ordered_index_node_impl*parent()const{return(ordered_index_node_impl*)(void*)(parentcolor_&~uintptr_type(1));}ordered_index_node_impl*&left(){return left_;}ordered_index_node_impl*left()const{return left_;}ordered_index_node_impl*&right(){return right_;}ordered_index_node_impl*right()const{return right_;}private:uintptr_type parentcolor_;ordered_index_node_impl*left_;ordered_index_node_impl*right_;};
struct ordered_index_node_impl:mpl::if_c<!(has_uintptr_type::value)||(alignment_of<ordered_index_node_compressed_base>::value%2),ordered_index_node_std_base,ordered_index_node_compressed_base>::type{static void increment(ordered_index_node_impl*&x){if(x->right()){x=x->right();while(x->left())x=x->left();}else{ordered_index_node_impl*y=x->parent();while(x==y->right()){x=y;y=y->parent();}if(x->right()!=y)x=y;}}static void decrement(ordered_index_node_impl*&x){if(x->color()==red&&x->parent()->parent()==x){x=x->right();}else if(x->left()){ordered_index_node_impl*y=x->left();while(y->right())y=y->right();x=y;}else{ordered_index_node_impl*y=x->parent();while(x==y->left()){x=y;y=y->parent();}x=y;}}static void rotate_left(ordered_index_node_impl*x,parent_ref root){ordered_index_node_impl*y=x->right();x->right()=y->left();if(y->left())y->left()->parent()=x;y->parent()=x->parent();if(x==root)root=y;else if(x==x->parent()->left())x->parent()->left()=y;else x->parent()->right()=y;y->left()=x;x->parent()=y;}static ordered_index_node_impl*minimum(ordered_index_node_impl*x){while(x->left())x=x->left();return x;}static ordered_index_node_impl*maximum(ordered_index_node_impl*x){while(x->right())x=x->right();return x;}static void rotate_right(ordered_index_node_impl*x,parent_ref root){ordered_index_node_impl*y=x->left();x->left()=y->right();if(y->right())y->right()->parent()=x;y->parent()=x->parent();if(x==root)root=y;else if(x==x->parent()->right())x->parent()->right()=y;else x->parent()->left()=y;y->right()=x;x->parent()=y;}static void rebalance(ordered_index_node_impl*x,parent_ref root){x->color()=red;while(x!=root&&x->parent()->color()==red){if(x->parent()==x->parent()->parent()->left()){ordered_index_node_impl*y=x->parent()->parent()->right();if(y&&y->color()==red){x->parent()->color()=black;y->color()=black;x->parent()->parent()->color()=red;x=x->parent()->parent();}else{if(x==x->parent()->right()){x=x->parent();rotate_left(x,root);}x->parent()->color()=black;x->parent()->parent()->color()=red;rotate_right(x->parent()->parent(),root);}}else{ordered_index_node_impl*y=x->parent()->parent()->left();if(y&&y->color()==red){x->parent()->color()=black;y->color()=black;x->parent()->parent()->color()=red;x=x->parent()->parent();}else{if(x==x->parent()->left()){x=x->parent();rotate_right(x,root);}x->parent()->color()=black;x->parent()->parent()->color()=red;rotate_left(x->parent()->parent(),root);}}}root->color()=black;}static void link(ordered_index_node_impl*x,ordered_index_side side,ordered_index_node_impl*position,ordered_index_node_impl*header){if(side==to_left){position->left()=x;if(position==header){header->parent()=x;header->right()=x;}else if(position==header->left()){header->left()=x;}}else{position->right()=x;if(position==header->right()){header->right()=x;}}x->parent()=position;x->left()=0;x->right()=0;ordered_index_node_impl::rebalance(x,header->parent());}static ordered_index_node_impl*rebalance_for_erase(ordered_index_node_impl*z,parent_ref root,ordered_index_node_impl*&leftmost,ordered_index_node_impl*&rightmost){ordered_index_node_impl*y=z;ordered_index_node_impl*x=0;ordered_index_node_impl*x_parent=0;if(y->left()==0){x=y->right();}else{if(y->right()==0){x=y->left();}else{y=y->right();while(y->left())y=y->left();x=y->right();}}if(y!=z){z->left()->parent()=y;y->left()=z->left();if(y!=z->right()){x_parent=y->parent();if(x)x->parent()=y->parent();y->parent()->left()=x;y->right()=z->right();z->right()->parent()=y;}else{x_parent=y;}if(root==z)root=y;else if(z->parent()->left()==z)z->parent()->left()=y;else z->parent()->right()=y;y->parent()=z->parent();ordered_index_color c=y->color();y->color()=z->color();z->color()=c;y=z;}else{x_parent=y->parent();if(x)x->parent()=y->parent();if(root==z){root=x;}else{if(z->parent()->left()==z)z->parent()->left()=x;else z->parent()->right()=x;}if(leftmost==z){if(z->right()==0){leftmost=z->parent();}else{leftmost=minimum(x);}}if(rightmost==z){if(z->left()==0){rightmost=z->parent();}else{rightmost=maximum(x);}}}if(y->color()!=red){while(x!=root&&(x==0||x->color()==black)){if(x==x_parent->left()){ordered_index_node_impl*w=x_parent->right();if(w->color()==red){w->color()=black;x_parent->color()=red;rotate_left(x_parent,root);w=x_parent->right();}if((w->left()==0||w->left()->color()==black)&&(w->right()==0||w->right()->color()==black)){w->color()=red;x=x_parent;x_parent=x_parent->parent();}else{if(w->right()==0||w->right()->color()==black){if(w->left())w->left()->color()=black;w->color()=red;rotate_right(w,root);w=x_parent->right();}w->color()=x_parent->color();x_parent->color()=black;if(w->right())w->right()->color()=black;rotate_left(x_parent,root);break;}}else{ordered_index_node_impl*w=x_parent->left();if(w->color()==red){w->color()=black;x_parent->color()=red;rotate_right(x_parent,root);w=x_parent->left();}if((w->right()==0||w->right()->color()==black)&&(w->left()==0||w->left()->color()==black)){w->color()=red;x=x_parent;x_parent=x_parent->parent();}else{if(w->left()==0||w->left()->color()==black){if(w->right())w->right()->color()=black;w->color()=red;rotate_left(w,root);w=x_parent->left();}w->color()=x_parent->color();x_parent->color()=black;if(w->left())w->left()->color()=black;rotate_right(x_parent,root);break;}}}if(x)x->color()=black;}return y;}static void restore(ordered_index_node_impl*x,ordered_index_node_impl*position,ordered_index_node_impl*header){if(position->left()==0||position->left()==header){link(x,to_left,position,header);}else{decrement(position);link(x,to_right,position,header);}}};
template<typename Super>struct ordered_index_node_trampoline:ordered_index_node_impl{};
template<typename Super>struct ordered_index_node:Super,ordered_index_node_trampoline<Super>{private:typedef ordered_index_node_trampoline<Super>impl_type;typedef typename impl_type::color_ref color_ref;typedef typename impl_type::parent_ref parent_ref;public:color_ref color(){return impl_type::color();}ordered_index_color color()const{return impl_type::color();}parent_ref parent(){return impl_type::parent();}ordered_index_node_impl*parent()const{return impl_type::parent();}ordered_index_node_impl*&left(){return impl_type::left();}ordered_index_node_impl*left()const{return impl_type::left();}ordered_index_node_impl*&right(){return impl_type::right();}ordered_index_node_impl*right()const{return impl_type::right();}ordered_index_node_impl*impl(){return static_cast<impl_type*>(this);}const ordered_index_node_impl*impl()const{return static_cast<const impl_type*>(this);}static ordered_index_node*from_impl(ordered_index_node_impl*x){return static_cast<ordered_index_node*>(static_cast<impl_type*>(x));}static const ordered_index_node*from_impl(const ordered_index_node_impl*x){return static_cast<const ordered_index_node*>(static_cast<const impl_type*>(x));}static void increment(ordered_index_node*&x){ordered_index_node_impl*xi=x->impl();impl_type::increment(xi);x=from_impl(xi);}static void decrement(ordered_index_node*&x){ordered_index_node_impl*xi=x->impl();impl_type::decrement(xi);x=from_impl(xi);}};
struct unbounded_type;
template<typename Value,typename KeyFromValue,typename Compare>struct value_comparison;
struct ordered_unique_tag;
struct ordered_non_unique_tag;
template<typename KeyFromValue,typename Compare,typename SuperMeta,typename TagList,typename Category>class ordered_index:protected SuperMeta::type{typedef typename SuperMeta::type super;protected:typedef ordered_index_node<typename super::node_type>node_type;public:typedef typename KeyFromValue::result_type key_type;typedef typename node_type::value_type value_type;typedef KeyFromValue key_from_value;typedef Compare key_compare;typedef value_comparison<value_type,KeyFromValue,Compare>value_compare;typedef tuple<key_from_value,key_compare>ctor_args;typedef typename super::final_allocator_type allocator_type;typedef typename allocator_type::reference reference;typedef typename allocator_type::const_reference const_reference;typedef bidir_node_iterator<node_type>iterator;typedef iterator const_iterator;typedef std::size_t size_type;typedef std::ptrdiff_t difference_type;typedef typename allocator_type::pointer pointer;typedef typename allocator_type::const_pointer const_pointer;typedef typename boost::reverse_iterator<iterator>reverse_iterator;typedef typename boost::reverse_iterator<const_iterator>const_reverse_iterator;typedef TagList tag_list;protected:typedef typename super::final_node_type final_node_type;typedef tuples::cons<ctor_args,typename super::ctor_args_list>ctor_args_list;typedef typename mpl::push_front<typename super::index_type_list,ordered_index>::type index_type_list;typedef typename mpl::push_front<typename super::iterator_type_list,iterator>::type iterator_type_list;typedef typename mpl::push_front<typename super::const_iterator_type_list,const_iterator>::type const_iterator_type_list;typedef typename super::copy_map_type copy_map_type;private:typedef typename call_traits<value_type>::param_type value_param_type;typedef typename call_traits<key_type>::param_type key_param_type;public:ordered_index<KeyFromValue,Compare,SuperMeta,TagList,Category>&operator=(const ordered_index<KeyFromValue,Compare,SuperMeta,TagList,Category>&x);allocator_type get_allocator()const;iterator begin();const_iterator begin()const;iterator end();const_iterator end()const;reverse_iterator rbegin();const_reverse_iterator rbegin()const;reverse_iterator rend();const_reverse_iterator rend()const;bool empty()const;size_type size()const;size_type max_size()const;std::pair<iterator,bool>insert(value_param_type x);iterator insert(iterator position,value_param_type x);template<typename InputIterator>void insert(InputIterator first,InputIterator last);iterator erase(iterator position);size_type erase(key_param_type x);iterator erase(iterator first,iterator last);bool replace(iterator position,value_param_type x);template<typename Modifier>bool modify(iterator position,Modifier mod);template<typename Modifier>bool modify_key(iterator position,Modifier mod);void swap(ordered_index<KeyFromValue,Compare,SuperMeta,TagList,Category>&x);void clear();key_from_value key_extractor()const;key_compare key_comp()const;value_compare value_comp()const;template<typename CompatibleKey>iterator find(const CompatibleKey&x)const;template<typename CompatibleKey,typename CompatibleCompare>iterator find(const CompatibleKey&x,const CompatibleCompare&comp)const;template<typename CompatibleKey>size_type count(const CompatibleKey&x)const;template<typename CompatibleKey,typename CompatibleCompare>size_type count(const CompatibleKey&x,const CompatibleCompare&comp)const;template<typename CompatibleKey>iterator lower_bound(const CompatibleKey&x)const;template<typename CompatibleKey,typename CompatibleCompare>iterator lower_bound(const CompatibleKey&x,const CompatibleCompare&comp)const;template<typename CompatibleKey>iterator upper_bound(const CompatibleKey&x)const;template<typename CompatibleKey,typename CompatibleCompare>iterator upper_bound(const CompatibleKey&x,const CompatibleCompare&comp)const;template<typename CompatibleKey>std::pair<iterator,iterator>equal_range(const CompatibleKey&x)const;template<typename CompatibleKey,typename CompatibleCompare>std::pair<iterator,iterator>equal_range(const CompatibleKey&x,const CompatibleCompare&comp)const;template<typename LowerBounder,typename UpperBounder>std::pair<iterator,iterator>range(LowerBounder lower,UpperBounder upper)const;protected:ordered_index(const ctor_args_list&args_list,const allocator_type&al);ordered_index(const ordered_index<KeyFromValue,Compare,SuperMeta,TagList,Category>&x);~ordered_index();iterator make_iterator(node_type*node);const_iterator make_iterator(node_type*node)const;void copy_(const ordered_index<KeyFromValue,Compare,SuperMeta,TagList,Category>&x,const copy_map_type&map);node_type*insert_(value_param_type v,node_type*x);node_type*insert_(value_param_type v,node_type*position,node_type*x);void erase_(node_type*x);void delete_all_nodes_();void clear_();void swap_(ordered_index<KeyFromValue,Compare,SuperMeta,TagList,Category>&x);bool replace_(value_param_type v,node_type*x);bool modify_(node_type*x);private:node_type*header()const;node_type*root()const;node_type*leftmost()const;node_type*rightmost()const;void empty_initialize();struct link_info{ordered_index_side side;ordered_index_node_impl*pos;};bool link_point(key_param_type k,link_info&inf,ordered_unique_tag);bool link_point(key_param_type k,link_info&inf,ordered_non_unique_tag);bool hinted_link_point(key_param_type k,node_type*position,link_info&inf,ordered_unique_tag);bool hinted_link_point(key_param_type k,node_type*position,link_info&inf,ordered_non_unique_tag);void delete_all_nodes(node_type*x);bool in_place(value_param_type v,node_type*x,ordered_unique_tag);bool in_place(value_param_type v,node_type*x,ordered_non_unique_tag);template<typename LowerBounder>iterator lower_range(LowerBounder lower)const;iterator lower_range(unbounded_type)const;template<typename UpperBounder>iterator upper_range(UpperBounder upper)const;iterator upper_range(unbounded_type)const;key_from_value key;key_compare comp;};







}template<typename Arg1,typename Arg2,typename Arg3>struct ordered_unique;
template<typename Arg1,typename Arg2,typename Arg3>struct ordered_non_unique{typedef detail::ordered_index_args<Arg1,Arg2,Arg3>index_args;typedef typename index_args::tag_list_type::type tag_list_type;typedef typename index_args::key_from_value_type key_from_value_type;typedef typename index_args::compare_type compare_type;template<typename Super>struct node_class{typedef detail::ordered_index_node<Super>type;};template<typename SuperMeta>struct index_class{typedef detail::ordered_index<key_from_value_type,compare_type,SuperMeta,tag_list_type,detail::ordered_non_unique_tag>type;};};
namespace detail{struct hashed_index_node_impl{hashed_index_node_impl*&next(){return next_;}hashed_index_node_impl*next()const{return next_;}static void increment(hashed_index_node_impl*&x,hashed_index_node_impl*bbegin,hashed_index_node_impl*bbend){std::less_equal<hashed_index_node_impl*>leq;x=x->next();if(leq(bbegin,x)&&leq(x,bbend)){do{++x;}while(x->next()==x);x=x->next();}}static void link(hashed_index_node_impl*x,hashed_index_node_impl*pos){x->next()=pos->next();pos->next()=x;};static void unlink(hashed_index_node_impl*x){hashed_index_node_impl*y=x->next();while(y->next()!=x){y=y->next();}y->next()=x->next();}static hashed_index_node_impl*prev(hashed_index_node_impl*x){hashed_index_node_impl*y=x->next();while(y->next()!=x){y=y->next();}return y;}static void unlink_next(hashed_index_node_impl*x){x->next()=x->next()->next();}private:hashed_index_node_impl*next_;};
template<typename Super>struct hashed_index_node_trampoline:hashed_index_node_impl{};
template<typename Super>struct hashed_index_node:Super,hashed_index_node_trampoline<Super>{hashed_index_node_impl*impl(){return static_cast<impl_type*>(this);}const hashed_index_node_impl*impl()const{return static_cast<const impl_type*>(this);}static hashed_index_node*from_impl(hashed_index_node_impl*x){return static_cast<hashed_index_node*>(static_cast<impl_type*>(x));}static const hashed_index_node*from_impl(const hashed_index_node_impl*x){return static_cast<const hashed_index_node*>(static_cast<const impl_type*>(x));}static void increment(hashed_index_node*&x,hashed_index_node_impl*bbegin,hashed_index_node_impl*bend){hashed_index_node_impl*xi=x->impl();impl_type::increment(xi,bbegin,bend);x=from_impl(xi);}private:typedef hashed_index_node_trampoline<Super>impl_type;};
class bucket_array_base:private noncopyable{protected:inline static std::size_t next_prime(std::size_t n){static const std::size_t prime_list[]={53ul,97ul,193ul,389ul,769ul,1543ul,3079ul,6151ul,12289ul,24593ul,49157ul,98317ul,196613ul,393241ul,786433ul,1572869ul,3145739ul,6291469ul,12582917ul,25165843ul,50331653ul,100663319ul,201326611ul,402653189ul,805306457ul,1610612741ul,3221225473ul,4294967291ul};static const std::size_t prime_list_size=sizeof(prime_list)/sizeof(prime_list[0]);std::size_t const*bound=std::lower_bound(prime_list,prime_list+prime_list_size,n);if(bound==prime_list+prime_list_size)bound--;return*bound;}};
template<typename Allocator>class bucket_array:public bucket_array_base{public:bucket_array(const Allocator&al,hashed_index_node_impl*end_,std::size_t size):size_(bucket_array_base::next_prime(size)),spc(al,size_+1){clear();end()->next()=end_;end_->next()=end();}std::size_t size()const{return size_;}std::size_t position(std::size_t hash)const{return hash%size_;}hashed_index_node_impl*begin()const{return&buckets()[0];}hashed_index_node_impl*end()const{return&buckets()[size_];}hashed_index_node_impl*at(std::size_t n)const{return&buckets()[n];}std::size_t first_nonempty(std::size_t n)const{for(;;++n){hashed_index_node_impl*x=at(n);if(x->next()!=x)return n;}}void clear(){for(hashed_index_node_impl*x=begin(),*y=end();x!=y;++x)x->next()=x;}void swap(bucket_array&x){std::swap(size_,x.size_);spc.swap(x.spc);}private:std::size_t size_;auto_space<hashed_index_node_impl,Allocator>spc;hashed_index_node_impl*buckets()const{return spc.data();}};
template<typename Allocator>void swap(bucket_array<Allocator>&x,bucket_array<Allocator>&y){x.swap(y);}
template<typename Node,typename BucketArray,typename Derived=mpl::na>class hashed_index_iterator:public forward_iterator_helper<hashed_index_iterator<Node,BucketArray,Derived>,typename Node::value_type,std::ptrdiff_t,const typename Node::value_type*,const typename Node::value_type&>{public:hashed_index_iterator(){}hashed_index_iterator(Node*node_,BucketArray*buckets_):node(node_),buckets(buckets_){}const typename Node::value_type&operator*()const{return node->value();}friend bool operator==(const hashed_index_iterator&x,const hashed_index_iterator&y){return x.node==y.node;}hashed_index_iterator&operator++(){Node::increment(node,buckets->begin(),buckets->end());return*this;}typedef Node node_type;Node*get_node()const{return node;}private:Node*node;BucketArray*buckets;};
}}template<class T>struct hash;
template<class T>void hash_combine(std::size_t&seed,T const&v);
template<class It>std::size_t hash_range(It,It);
template<class It>void hash_range(std::size_t&,It,It);
namespace hash_detail{inline float call_ldexp(float v,int exp){using namespace std;return ldexp(v,exp);}
inline double call_ldexp(double v,int exp){using namespace std;return ldexp(v,exp);}
inline long double call_ldexp(long double v,int exp){using namespace std;return ldexp(v,exp);}
inline float call_frexp(float v,int*exp){using namespace std;return frexp(v,exp);}
inline double call_frexp(double v,int*exp){using namespace std;return frexp(v,exp);}
inline long double call_frexp(long double v,int*exp){using namespace std;return frexp(v,exp);}
inline void hash_float_combine(std::size_t&seed,std::size_t value){seed^=value+(seed<<6)+(seed>>2);}
template<class T>inline std::size_t float_hash_impl(T v){int exp=0;(*_errno())=0;v=boost::hash_detail::call_frexp(v,&exp);if((*_errno()))return 0;std::size_t seed=0;std::size_t const length=(std::numeric_limits<T>::digits+std::numeric_limits<int>::digits-1)/std::numeric_limits<int>::digits;for(std::size_t i=0;i<length;++i){v=boost::hash_detail::call_ldexp(v,std::numeric_limits<int>::digits);int const part=static_cast<int>(v);v-=part;hash_float_combine(seed,part);}hash_float_combine(seed,exp);return seed;}
template<class T>inline std::size_t float_hash_value(T v){switch(_fpclass(v)){case 0x0020:case 0x0040:return 0;case 0x0200:return(std::size_t)(-1);case 0x0004:return(std::size_t)(-2);case 0x0001:case 0x0002:return(std::size_t)(-3);case 0x0008:case 0x0010:return float_hash_impl(v);case 0x0080:case 0x0100:return float_hash_impl(v);default:((void)0);return 0;}}
}std::size_t hash_value(int);
std::size_t hash_value(unsigned int);
std::size_t hash_value(long);
std::size_t hash_value(unsigned long);
template<class T>std::size_t hash_value(T*const&);
template<class T,unsigned N>std::size_t hash_value(const T(&array)[N]);
template<class T,unsigned N>std::size_t hash_value(T(&array)[N]);
std::size_t hash_value(float v);
std::size_t hash_value(double v);
std::size_t hash_value(long double v);
template<class Ch,class A>std::size_t hash_value(std::basic_string<Ch,std::char_traits<Ch>,A>const&);
template<class A,class B>std::size_t hash_value(std::pair<A,B>const&);
template<class T,class A>std::size_t hash_value(std::vector<T,A>const&);
template<class T,class A>std::size_t hash_value(std::list<T,A>const&v);
template<class T,class A>std::size_t hash_value(std::deque<T,A>const&v);
template<class K,class C,class A>std::size_t hash_value(std::set<K,C,A>const&v);
template<class K,class C,class A>std::size_t hash_value(std::multiset<K,C,A>const&v);
template<class K,class T,class C,class A>std::size_t hash_value(std::map<K,T,C,A>const&v);
template<class K,class T,class C,class A>std::size_t hash_value(std::multimap<K,T,C,A>const&v);
inline std::size_t hash_value(int v){return static_cast<std::size_t>(v);}
inline std::size_t hash_value(unsigned int v){return static_cast<std::size_t>(v);}
inline std::size_t hash_value(long v){return static_cast<std::size_t>(v);}
inline std::size_t hash_value(unsigned long v){return static_cast<std::size_t>(v);}
template<class T>std::size_t hash_value(T*const&v){std::size_t x=static_cast<std::size_t>(reinterpret_cast<std::ptrdiff_t>(v));return x+(x>>3);}
template<class T>inline void hash_combine(std::size_t&seed,T const&v){boost::hash<T>hasher;seed^=hasher(v)+0x9e3779b9+(seed<<6)+(seed>>2);}

template<class It>inline void hash_range(std::size_t&seed,It first,It last){for(;first!=last;++first){hash_combine(seed,*first);}}
template<class T,unsigned N>inline std::size_t hash_value(const T(&array)[N]){return hash_range(array,array+N);}
template<class T,unsigned N>inline std::size_t hash_value(T(&array)[N]){return hash_range(array,array+N);}

inline std::size_t hash_value(float v){return boost::hash_detail::float_hash_value(v);}
inline std::size_t hash_value(double v){return boost::hash_detail::float_hash_value(v);}
inline std::size_t hash_value(long double v){return boost::hash_detail::float_hash_value(v);}

template<class T,class A>std::size_t hash_value(std::vector<T,A>const&v){return hash_range(v.begin(),v.end());}
template<class T,class A>std::size_t hash_value(std::list<T,A>const&v){return hash_range(v.begin(),v.end());}
template<class T,class A>std::size_t hash_value(std::deque<T,A>const&v){return hash_range(v.begin(),v.end());}
template<class K,class C,class A>std::size_t hash_value(std::set<K,C,A>const&v){return hash_range(v.begin(),v.end());}
template<class K,class C,class A>std::size_t hash_value(std::multiset<K,C,A>const&v){return hash_range(v.begin(),v.end());}
template<class K,class T,class C,class A>std::size_t hash_value(std::map<K,T,C,A>const&v){return hash_range(v.begin(),v.end());}
template<class K,class T,class C,class A>std::size_t hash_value(std::multimap<K,T,C,A>const&v){return hash_range(v.begin(),v.end());}
template<>struct hash<bool>:public std::unary_function<bool,std::size_t>{std::size_t operator()(bool v)const{return boost::hash_value(v);}};
template<>struct hash<char>:public std::unary_function<char,std::size_t>{std::size_t operator()(char v)const{return boost::hash_value(v);}};
template<>struct hash<signed char>:public std::unary_function<signed char,std::size_t>{std::size_t operator()(signed char v)const{return boost::hash_value(v);}};
template<>struct hash<unsigned char>:public std::unary_function<unsigned char,std::size_t>{std::size_t operator()(unsigned char v)const{return boost::hash_value(v);}};
template<>struct hash<wchar_t>:public std::unary_function<wchar_t,std::size_t>{std::size_t operator()(wchar_t v)const{return boost::hash_value(v);}};
template<>struct hash<short>:public std::unary_function<short,std::size_t>{std::size_t operator()(short v)const{return boost::hash_value(v);}};
template<>struct hash<unsigned short>:public std::unary_function<unsigned short,std::size_t>{std::size_t operator()(unsigned short v)const{return boost::hash_value(v);}};
template<>struct hash<int>:public std::unary_function<int,std::size_t>{std::size_t operator()(int v)const{return boost::hash_value(v);}};
template<>struct hash<unsigned int>:public std::unary_function<unsigned int,std::size_t>{std::size_t operator()(unsigned int v)const{return boost::hash_value(v);}};
template<>struct hash<long>:public std::unary_function<long,std::size_t>{std::size_t operator()(long v)const{return boost::hash_value(v);}};
template<>struct hash<unsigned long>:public std::unary_function<unsigned long,std::size_t>{std::size_t operator()(unsigned long v)const{return boost::hash_value(v);}};
template<>struct hash<float>:public std::unary_function<float,std::size_t>{std::size_t operator()(float v)const{return boost::hash_value(v);}};
template<>struct hash<double>:public std::unary_function<double,std::size_t>{std::size_t operator()(double v)const{return boost::hash_value(v);}};
template<>struct hash<long double>:public std::unary_function<long double,std::size_t>{std::size_t operator()(long double v)const{return boost::hash_value(v);}};
template<>struct hash<std::string>:public std::unary_function<std::string,std::size_t>{std::size_t operator()(std::string const&v)const{return boost::hash_value(v);}};
template<>struct hash<std::wstring>:public std::unary_function<std::wstring,std::size_t>{std::size_t operator()(std::wstring const&v)const{return boost::hash_value(v);}};
template<class T>struct hash<T*>:public std::unary_function<T*,std::size_t>{std::size_t operator()(T*v)const{return boost::hash_value(v);}};
template<class T>struct hash:std::unary_function<T,std::size_t>{std::size_t operator()(T const&val)const{return hash_value(val);}};
template<class T>struct hash;
namespace multi_index{namespace detail{template<typename KeyFromValue>struct index_args_default_hash{typedef::boost::hash<typename KeyFromValue::result_type>type;};
template<typename KeyFromValue>struct index_args_default_pred{typedef std::equal_to<typename KeyFromValue::result_type>type;};
template<typename Arg1,typename Arg2,typename Arg3,typename Arg4>struct hashed_index_args{typedef is_tag<Arg1>full_form;typedef typename mpl::if_<full_form,Arg1,tag<> >::type tag_list_type;typedef typename mpl::if_<full_form,Arg2,Arg1>::type key_from_value_type;typedef typename mpl::if_<full_form,Arg3,Arg2>::type supplied_hash_type;typedef typename mpl::eval_if<mpl::is_na<supplied_hash_type>,index_args_default_hash<key_from_value_type>,mpl::identity<supplied_hash_type> >::type hash_type;typedef typename mpl::if_<full_form,Arg4,Arg3>::type supplied_pred_type;typedef typename mpl::eval_if<mpl::is_na<supplied_pred_type>,index_args_default_pred<key_from_value_type>,mpl::identity<supplied_pred_type> >::type pred_type;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(is_tag<tag_list_type>::value)>)>boost_static_assert_typedef_41;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(!mpl::is_na<key_from_value_type>::value)>)>boost_static_assert_typedef_42;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(!mpl::is_na<hash_type>::value)>)>boost_static_assert_typedef_43;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(!mpl::is_na<pred_type>::value)>)>boost_static_assert_typedef_44;};
template<typename KeyFromValue,typename Hash,typename Pred,typename SuperMeta,typename TagList,typename Category>class hashed_index;

}template<typename Arg1,typename Arg2=mpl::na,typename Arg3=mpl::na,typename Arg4=mpl::na>struct hashed_unique;
namespace detail{struct hashed_unique_tag;
struct hashed_non_unique_tag;
template<typename KeyFromValue,typename Hash,typename Pred,typename SuperMeta,typename TagList,typename Category>class hashed_index:protected SuperMeta::type{typedef typename SuperMeta::type super;protected:typedef hashed_index_node<typename super::node_type>node_type;typedef bucket_array<typename super::final_allocator_type>bucket_array_type;public:typedef typename KeyFromValue::result_type key_type;typedef typename node_type::value_type value_type;typedef KeyFromValue key_from_value;typedef Hash hasher;typedef Pred key_equal;typedef tuple<std::size_t,key_from_value,hasher,key_equal>ctor_args;typedef typename super::final_allocator_type allocator_type;typedef typename allocator_type::pointer pointer;typedef typename allocator_type::const_pointer const_pointer;typedef typename allocator_type::reference reference;typedef typename allocator_type::const_reference const_reference;typedef std::size_t size_type;typedef std::ptrdiff_t difference_type;typedef hashed_index_iterator<node_type,bucket_array_type>iterator;typedef iterator const_iterator;typedef iterator local_iterator;typedef const_iterator const_local_iterator;typedef TagList tag_list;protected:typedef typename super::final_node_type final_node_type;typedef tuples::cons<ctor_args,typename super::ctor_args_list>ctor_args_list;typedef typename mpl::push_front<typename super::index_type_list,hashed_index>::type index_type_list;typedef typename mpl::push_front<typename super::iterator_type_list,iterator>::type iterator_type_list;typedef typename mpl::push_front<typename super::const_iterator_type_list,const_iterator>::type const_iterator_type_list;typedef typename super::copy_map_type copy_map_type;private:typedef typename call_traits<value_type>::param_type value_param_type;typedef typename call_traits<key_type>::param_type key_param_type;public:hashed_index<KeyFromValue,Hash,Pred,SuperMeta,TagList,Category>&operator=(const hashed_index<KeyFromValue,Hash,Pred,SuperMeta,TagList,Category>&x);allocator_type get_allocator()const;bool empty()const;size_type size()const;size_type max_size()const;iterator begin();const_iterator begin()const;iterator end(){return make_iterator(header());}const_iterator end()const{return make_iterator(header());}std::pair<iterator,bool>insert(value_param_type x){;std::pair<final_node_type*,bool>p=this->final_insert_(x);return std::pair<iterator,bool>(make_iterator(p.first),p.second);}iterator insert(iterator position,value_param_type x){((void)0);;((void)0);;;std::pair<final_node_type*,bool>p=this->final_insert_(x,static_cast<final_node_type*>(position.get_node()));return make_iterator(p.first);}template<typename InputIterator>void insert(InputIterator first,InputIterator last){;iterator hint=end();for(;first!=last;++first)hint=insert(hint,*first);}iterator erase(iterator position);size_type erase(key_param_type k);iterator erase(iterator first,iterator last);bool replace(iterator position,value_param_type x);template<typename Modifier>bool modify(iterator position,Modifier mod){((void)0);;((void)0);;((void)0);;;return this->final_modify_(mod,static_cast<final_node_type*>(position.get_node()));}template<typename Modifier>bool modify_key(iterator position,Modifier mod);void clear();void swap(hashed_index<KeyFromValue,Hash,Pred,SuperMeta,TagList,Category>&x);key_from_value key_extractor()const;hasher hash_function()const;key_equal key_eq()const;template<typename CompatibleKey>iterator find(const CompatibleKey&k)const{return find(k,hash,eq);}template<typename CompatibleKey,typename CompatibleHash,typename CompatiblePred>iterator find(const CompatibleKey&k,const CompatibleHash&hash,const CompatiblePred&eq)const{std::size_t buc=buckets.position(hash(k));hashed_index_node_impl*x=buckets.at(buc);hashed_index_node_impl*y=x->next();while(y!=x){if(eq(k,key(node_type::from_impl(y)->value()))){return make_iterator(node_type::from_impl(y));}y=y->next();}return end();}template<typename CompatibleKey>size_type count(const CompatibleKey&k)const;template<typename CompatibleKey,typename CompatibleHash,typename CompatiblePred>size_type count(const CompatibleKey&k,const CompatibleHash&hash,const CompatiblePred&eq)const;template<typename CompatibleKey>std::pair<iterator,iterator>equal_range(const CompatibleKey&k)const;template<typename CompatibleKey,typename CompatibleHash,typename CompatiblePred>std::pair<iterator,iterator>equal_range(const CompatibleKey&k,const CompatibleHash&hash,const CompatiblePred&eq)const;size_type bucket_count()const;size_type max_bucket_count()const;size_type bucket_size(size_type n)const;size_type bucket(key_param_type k)const;local_iterator begin(size_type n);const_local_iterator begin(size_type n)const;local_iterator end(size_type n){return const_cast<const hashed_index*>(this)->end(n);}const_local_iterator end(size_type n)const{hashed_index_node_impl*x=buckets.at(n);if(x==x->next())return end();do{++x;}while(x==x->next());return make_iterator(node_type::from_impl(x->next()));}float load_factor()const;float max_load_factor()const;void max_load_factor(float z);void rehash(size_type n);protected:hashed_index(const ctor_args_list&args_list,const allocator_type&al);hashed_index(const hashed_index<KeyFromValue,Hash,Pred,SuperMeta,TagList,Category>&x);~hashed_index();iterator make_iterator(node_type*node){return iterator(node,&buckets);}const_iterator make_iterator(node_type*node)const{return const_iterator(node,&const_cast<bucket_array_type&>(buckets));}void copy_(const hashed_index<KeyFromValue,Hash,Pred,SuperMeta,TagList,Category>&x,const copy_map_type&map);node_type*insert_(value_param_type v,node_type*x);node_type*insert_(value_param_type v,node_type*position,node_type*x);void erase_(node_type*x);void delete_all_nodes_();void clear_();void swap_(hashed_index<KeyFromValue,Hash,Pred,SuperMeta,TagList,Category>&x);bool replace_(value_param_type v,node_type*x);bool modify_(node_type*x);private:node_type*header()const{return this->final_header();}std::size_t find_bucket(value_param_type v)const;bool link_point(value_param_type v,hashed_index_node_impl*&pos,hashed_unique_tag);bool link_point(value_param_type v,hashed_index_node_impl*&pos,hashed_non_unique_tag);void link(node_type*x,hashed_index_node_impl*pos);;void link(hashed_index_node_impl*x,hashed_index_node_impl*pos);;void unlink(node_type*x);;static hashed_index_node_impl*prev(node_type*x);static void unlink_next(hashed_index_node_impl*x);void calculate_max_load();void reserve(size_type n);void unchecked_rehash(size_type n);key_from_value key;hasher hash;key_equal eq;bucket_array_type buckets;float mlf;size_type max_load;std::size_t first_bucket;};

}template<typename Arg1,typename Arg2,typename Arg3,typename Arg4>struct hashed_unique{typedef typename detail::hashed_index_args<Arg1,Arg2,Arg3,Arg4>index_args;typedef typename index_args::tag_list_type::type tag_list_type;typedef typename index_args::key_from_value_type key_from_value_type;typedef typename index_args::hash_type hash_type;typedef typename index_args::pred_type pred_type;template<typename Super>struct node_class{typedef detail::hashed_index_node<Super>type;};template<typename SuperMeta>struct index_class{typedef detail::hashed_index<key_from_value_type,hash_type,pred_type,SuperMeta,tag_list_type,detail::hashed_unique_tag>type;};};
}template<class T>class reference_wrapper;
namespace multi_index{namespace detail{template<class Class,typename Type,Type Class::*PtrToMember>struct const_member_base;
template<class Class,typename Type,Type Class::*PtrToMember>struct non_const_member_base{typedef Type result_type;template<typename ChainedPtr>typename disable_if<is_convertible<const ChainedPtr&,const Class&>,Type&>::type operator()(const ChainedPtr&x)const{return operator()(*x);}const Type&operator()(const Class&x,int=0)const{return x.*PtrToMember;}Type&operator()(Class&x)const{return x.*PtrToMember;}const Type&operator()(const reference_wrapper<const Class>&x,int=0)const{return operator()(x.get());}Type&operator()(const reference_wrapper<Class>&x)const{return operator()(x.get());}};
}template<class Class,typename Type,Type Class::*PtrToMember>struct member:mpl::if_c<is_const<Type>::value,detail::const_member_base<Class,Type,PtrToMember>,detail::non_const_member_base<Class,Type,PtrToMember> >::type{};
}template<class T>T*get_pointer(T*p){return p;}
template<class T>T*get_pointer(std::auto_ptr<T>const&p){return p.get();}
namespace _mfi{template<class R,class T>class mf0;
template<class R,class T>class cmf0;
template<class R,class T,class A1>class mf1;
template<class R,class T,class A1>class cmf1;
template<class R,class T,class A1,class A2>class mf2;
template<class R,class T,class A1,class A2>class cmf2;
template<class R,class T,class A1,class A2,class A3>class mf3{public:typedef R result_type;private:typedef R(T::*F)(A1,A2,A3);F f_;template<class U,class B1,class B2,class B3>R call(U&u,T const*,B1&b1,B2&b2,B3&b3)const{return(u.*f_)(b1,b2,b3);}template<class U,class B1,class B2,class B3>R call(U&u,void const*,B1&b1,B2&b2,B3&b3)const{return(get_pointer(u)->*f_)(b1,b2,b3);}public:explicit mf3(F f):f_(f){}R operator()(T*p,A1 a1,A2 a2,A3 a3)const{return(p->*f_)(a1,a2,a3);}template<class U>R operator()(U&u,A1 a1,A2 a2,A3 a3)const{return call(u,&u,a1,a2,a3);}template<class U>R operator()(U const&u,A1 a1,A2 a2,A3 a3)const{return call(u,&u,a1,a2,a3);}R operator()(T&t,A1 a1,A2 a2,A3 a3)const{return(t.*f_)(a1,a2,a3);}bool operator==(mf3 const&rhs)const{return f_==rhs.f_;}bool operator!=(mf3 const&rhs)const{return f_!=rhs.f_;}};
}template<class R,class T>_mfi::mf0<R,T>mem_fn(R(T::*f)()){return _mfi::mf0<R,T>(f);}
template<class R,class T>_mfi::cmf0<R,T>mem_fn(R(T::*f)()const){return _mfi::cmf0<R,T>(f);}
template<class R,class T,class A1>_mfi::mf1<R,T,A1>mem_fn(R(T::*f)(A1)){return _mfi::mf1<R,T,A1>(f);}
template<class R,class T,class A1>_mfi::cmf1<R,T,A1>mem_fn(R(T::*f)(A1)const){return _mfi::cmf1<R,T,A1>(f);}
template<class R,class T,class A1,class A2>_mfi::mf2<R,T,A1,A2>mem_fn(R(T::*f)(A1,A2)){return _mfi::mf2<R,T,A1,A2>(f);}
template<class R,class T,class A1,class A2>_mfi::cmf2<R,T,A1,A2>mem_fn(R(T::*f)(A1,A2)const){return _mfi::cmf2<R,T,A1,A2>(f);}
template<class R,class T,class A1,class A2,class A3>_mfi::mf3<R,T,A1,A2,A3>mem_fn(R(T::*f)(A1,A2,A3)){return _mfi::mf3<R,T,A1,A2,A3>(f);}











namespace _mfi{template<class R,class T>class dm;
}template<class R,class T>_mfi::dm<R,T>mem_fn(R T::*f){return _mfi::dm<R,T>(f);}
template<class T>struct type{};
template<int I>class arg{};
template<int I>bool operator==(arg<I>const&,arg<I>const&){return true;}
template<typename Visitor,typename T>inline void visit_each(Visitor&visitor,const T&t,long){visitor(t);}
template<typename Visitor,typename T>inline void visit_each(Visitor&visitor,const T&t){visit_each(visitor,t,0);}
namespace _bi{template<class A1>struct storage1{explicit storage1(A1 a1):a1_(a1){}template<class V>void accept(V&v)const{visit_each(v,a1_,0);}A1 a1_;};
template<int I>struct storage1<boost::arg<I> >{explicit storage1(boost::arg<I>){}template<class V>void accept(V&)const{}static boost::arg<I>a1_(){return boost::arg<I>();}};
template<int I>struct storage1<boost::arg<I>(*)()>{explicit storage1(boost::arg<I>(*)()){}template<class V>void accept(V&)const{}static boost::arg<I>a1_(){return boost::arg<I>();}};
template<class A1,class A2>struct storage2:public storage1<A1>{typedef storage1<A1>inherited;storage2(A1 a1,A2 a2):storage1<A1>(a1),a2_(a2){}template<class V>void accept(V&v)const{inherited::accept(v);visit_each(v,a2_,0);}A2 a2_;};
template<class A1,int I>struct storage2<A1,boost::arg<I> >;
template<class A1,int I>struct storage2<A1,boost::arg<I>(*)()>;
template<class A1,class A2,class A3>struct storage3:public storage2<A1,A2>{typedef storage2<A1,A2>inherited;storage3(A1 a1,A2 a2,A3 a3):storage2<A1,A2>(a1,a2),a3_(a3){}template<class V>void accept(V&v)const{inherited::accept(v);visit_each(v,a3_,0);}A3 a3_;};
template<class A1,class A2,int I>struct storage3<A1,A2,boost::arg<I> >;
template<class A1,class A2,int I>struct storage3<A1,A2,boost::arg<I>(*)()>;
template<class A1,class A2,class A3,class A4>struct storage4:public storage3<A1,A2,A3>{typedef storage3<A1,A2,A3>inherited;storage4(A1 a1,A2 a2,A3 a3,A4 a4):storage3<A1,A2,A3>(a1,a2,a3),a4_(a4){}template<class V>void accept(V&v)const{inherited::accept(v);visit_each(v,a4_,0);}A4 a4_;};
template<class A1,class A2,class A3,int I>struct storage4<A1,A2,A3,boost::arg<I> >;
template<class A1,class A2,class A3,int I>struct storage4<A1,A2,A3,boost::arg<I>(*)()>;
template<class R,class F>struct result_traits{typedef R type;};
struct unspecified;
template<class F>struct result_traits<unspecified,F>;
template<class F>struct result_traits<unspecified,reference_wrapper<F> >{typedef typename F::result_type type;};
template<class T>bool ref_compare(T const&a,T const&b,long){return a==b;}
template<int I>bool ref_compare(arg<I>const&,arg<I>const&,int){return true;}
template<int I>bool ref_compare(arg<I>(*)(),arg<I>(*)(),int){return true;}
template<class T>bool ref_compare(reference_wrapper<T>const&a,reference_wrapper<T>const&b,int){return a.get_pointer()==b.get_pointer();}
template<class R,class F,class L>class bind_t;
template<class T>class value{public:value(T const&t):t_(t){}T&get(){return t_;}T const&get()const{return t_;}bool operator==(value const&rhs)const{return t_==rhs.t_;}private:T t_;};
template<class T>class type{};
template<class F>struct unwrapper;
template<class A1,class A2,class A3,class A4>class list4:private storage4<A1,A2,A3,A4>{private:typedef storage4<A1,A2,A3,A4>base_type;public:list4(A1 a1,A2 a2,A3 a3,A4 a4):base_type(a1,a2,a3,a4){}A1 operator[](boost::arg<1>)const{return base_type::a1_;}A2 operator[](boost::arg<2>)const{return base_type::a2_;}A3 operator[](boost::arg<3>)const{return base_type::a3_;}A4 operator[](boost::arg<4>)const{return base_type::a4_;}A1 operator[](boost::arg<1>(*)())const{return base_type::a1_;}A2 operator[](boost::arg<2>(*)())const{return base_type::a2_;}A3 operator[](boost::arg<3>(*)())const{return base_type::a3_;}A4 operator[](boost::arg<4>(*)())const{return base_type::a4_;}template<class T>T&operator[](_bi::value<T>&v)const{return v.get();}template<class T>T const&operator[](_bi::value<T>const&v)const{return v.get();}template<class T>T&operator[](reference_wrapper<T>const&v)const{return v.get();}template<class R,class F,class L>typename result_traits<R,F>::type operator[](bind_t<R,F,L>&b)const{return b.eval(*this);}template<class R,class F,class L>typename result_traits<R,F>::type operator[](bind_t<R,F,L>const&b)const{return b.eval(*this);}template<class R,class F,class A>R operator()(type<R>,F&f,A&a,long){return unwrapper<F>::unwrap(f,0)(a[base_type::a1_],a[base_type::a2_],a[base_type::a3_],a[base_type::a4_]);}template<class R,class F,class A>R operator()(type<R>,F const&f,A&a,long)const{return unwrapper<F const>::unwrap(f,0)(a[base_type::a1_],a[base_type::a2_],a[base_type::a3_],a[base_type::a4_]);}template<class F,class A>void operator()(type<void>,F&f,A&a,int){unwrapper<F>::unwrap(f,0)(a[base_type::a1_],a[base_type::a2_],a[base_type::a3_],a[base_type::a4_]);}template<class F,class A>void operator()(type<void>,F const&f,A&a,int)const{unwrapper<F const>::unwrap(f,0)(a[base_type::a1_],a[base_type::a2_],a[base_type::a3_],a[base_type::a4_]);}template<class V>void accept(V&v)const{base_type::accept(v);}bool operator==(list4 const&rhs)const{return ref_compare(base_type::a1_,rhs.a1_,0)&&ref_compare(base_type::a2_,rhs.a2_,0)&&ref_compare(base_type::a3_,rhs.a3_,0)&&ref_compare(base_type::a4_,rhs.a4_,0);}};
template<class R,class F,class L>class bind_t{public:typedef bind_t this_type;bind_t(F f,L const&l):f_(f),l_(l){}typedef typename result_traits<R,F>::type result_type;result_type operator()();result_type operator()()const;template<class A1>result_type operator()(A1&a1);template<class A1>result_type operator()(A1&a1)const;template<class A1>result_type operator()(A1 const&a1);template<class A1>result_type operator()(A1 const&a1)const;template<class A1,class A2>result_type operator()(A1&a1,A2&a2);template<class A1,class A2>result_type operator()(A1&a1,A2&a2)const;template<class A1,class A2>result_type operator()(A1 const&a1,A2&a2);template<class A1,class A2>result_type operator()(A1 const&a1,A2&a2)const;template<class A1,class A2>result_type operator()(A1&a1,A2 const&a2);template<class A1,class A2>result_type operator()(A1&a1,A2 const&a2)const;template<class A1,class A2>result_type operator()(A1 const&a1,A2 const&a2);template<class A1,class A2>result_type operator()(A1 const&a1,A2 const&a2)const;template<class A1,class A2,class A3>result_type operator()(A1&a1,A2&a2,A3&a3);template<class A1,class A2,class A3>result_type operator()(A1&a1,A2&a2,A3&a3)const;template<class A1,class A2,class A3,class A4>result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4);template<class A1,class A2,class A3,class A4>result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4)const;template<class A1,class A2,class A3,class A4,class A5>result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5);template<class A1,class A2,class A3,class A4,class A5>result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5)const;template<class A1,class A2,class A3,class A4,class A5,class A6>result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6);template<class A1,class A2,class A3,class A4,class A5,class A6>result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6)const;template<class A1,class A2,class A3,class A4,class A5,class A6,class A7>result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7);template<class A1,class A2,class A3,class A4,class A5,class A6,class A7>result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7)const;template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8>result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7,A8&a8);template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8>result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7,A8&a8)const;template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9>result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7,A8&a8,A9&a9);template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9>result_type operator()(A1&a1,A2&a2,A3&a3,A4&a4,A5&a5,A6&a6,A7&a7,A8&a8,A9&a9)const;template<class A>result_type eval(A&a);template<class A>result_type eval(A&a)const;template<class V>void accept(V&v)const;bool compare(this_type const&rhs)const;private:F f_;L l_;};
template<class T>struct add_value{typedef _bi::value<T>type;};
template<class T>struct add_value<value<T> >{typedef _bi::value<T>type;};
template<class T>struct add_value<reference_wrapper<T> >{typedef reference_wrapper<T>type;};
template<int I>struct add_value<arg<I> >{typedef boost::arg<I>type;};
template<int I>struct add_value<arg<I>(*)()>{typedef boost::arg<I>(*type)();};
template<class R,class F,class L>struct add_value<bind_t<R,F,L> >{typedef bind_t<R,F,L>type;};
template<class A1,class A2,class A3,class A4>struct list_av_4{typedef typename add_value<A1>::type B1;typedef typename add_value<A2>::type B2;typedef typename add_value<A3>::type B3;typedef typename add_value<A4>::type B4;typedef list4<B1,B2,B3,B4>type;};







template<class V,class T>void visit_each(V&v,value<T>const&t,int){using boost::visit_each;visit_each(v,t.get(),0);}
template<class V,class R,class F,class L>void visit_each(V&v,bind_t<R,F,L>const&t,int){t.accept(v);}
}













































template<class R,class T,class B1,class B2,class B3,class A1,class A2,class A3,class A4>_bi::bind_t<R,_mfi::mf3<R,T,B1,B2,B3>,typename _bi::list_av_4<A1,A2,A3,A4>::type>bind(R(T::*f)(B1,B2,B3),A1 a1,A2 a2,A3 a3,A4 a4){typedef _mfi::mf3<R,T,B1,B2,B3>F;typedef typename _bi::list_av_4<A1,A2,A3,A4>::type list_type;return _bi::bind_t<R,F,list_type>(F(f),list_type(a1,a2,a3,a4));}












}namespace {static boost::arg<1>_1;
}namespace G3D{class Vector2;
class Vector3;
class Vector2;



























class Vector2;
class Vector3;
class Vector3{private:public:Vector3();Vector3(class BinaryInput&b);Vector3(const class Vector2&v,float _z);Vector3(const Vector3&rkVector);Vector3(const class Vector3int16&v);Vector3(class TextInput&t);void serialize(class BinaryOutput&b)const;void deserialize(class BinaryInput&b);void serialize(class TextOutput&t)const;void deserialize(class TextInput&t);float x,y,z;enum Axis{X_AXIS=0,Y_AXIS=1,Z_AXIS=2,DETECT_AXIS=-1};Vector3&operator=(const Vector3&rkVector);class Matrix3 cross()const;static const Vector3 ZERO;static const Vector3 ZERO3;static const Vector3 UNIT_X;static const Vector3 UNIT_Y;static const Vector3 UNIT_Z;static const Vector3 INF3;static const Vector3 NAN3;static Vector3 dummy;};



std::ostream&operator<<(std::ostream&os,const Vector3&);
void serialize(const Vector3::Axis&a,class BinaryOutput&bo);
void deserialize(Vector3::Axis&a,class BinaryInput&bo);







inline Vector3&Vector3::operator=(const Vector3&rkVector){x=rkVector.x;y=rkVector.y;z=rkVector.z;return*this;}














class Vector2;
class Vector3;














class Matrix3{private:float elt[3][3];public:inline Matrix3();Matrix3(class BinaryInput&b);Matrix3(const Matrix3&rkMatrix);Matrix3(const class Quat&q);void serialize(class BinaryOutput&b)const;void deserialize(class BinaryInput&b);inline Matrix3&operator=(const Matrix3&rkMatrix){memcpy(elt,rkMatrix.elt,9*sizeof(float));return*this;}private:public:private:public:static const float EPSILON;static const Matrix3 ZERO;static const Matrix3 IDENTITY;protected:static const float ms_fSvdEpsilon;static const int ms_iSvdMaxIterations;};

class Vector2;
class Vector3;
class Vector3int16;
class CoordinateFrame{public:Matrix3 rotation;Vector3 translation;static const float zLookDirection;inline CoordinateFrame();CoordinateFrame(class BinaryInput&b);void deserialize(class BinaryInput&b);void serialize(class BinaryOutput&b)const;CoordinateFrame(const CoordinateFrame&other);inline~CoordinateFrame(){}class Matrix4 toMatrix4()const;class Ray toObjectSpace(const Ray&r)const;class Box toWorldSpace(const class AABox&b)const;class Box toWorldSpace(const class Box&b)const;class Cylinder toWorldSpace(const class Cylinder&b)const;class Capsule toWorldSpace(const class Capsule&b)const;class Plane toWorldSpace(const class Plane&p)const;class Sphere toWorldSpace(const class Sphere&b)const;class Triangle toWorldSpace(const class Triangle&t)const;class Box toObjectSpace(const AABox&b)const;class Box toObjectSpace(const Box&b)const;class Plane toObjectSpace(const Plane&p)const;class Sphere toObjectSpace(const Sphere&b)const;class Ray lookRay()const;};
class Plane;
}namespace RBX{class PartInstance;
}namespace boost{typedef long once_flag;
void call_once(void(*func)(),once_flag&flag);
}namespace RBX{class Name;
}namespace boost{namespace detail{namespace thread{template<typename Mutex>class lock_ops;
template<typename Mutex>class scoped_lock;
}}template<class E>inline void throw_exception(E const&e){throw e;}
}namespace RBX{namespace Reflection{class ClassDescriptor;
class DescribedBase;
}}class XmlElement;
namespace RBX{class IReferenceBinder;
namespace Reflection{class DescribedBase;
class __declspec(novtable)PropertyDescriptor;
class DescribedBase;
}class StandardOut;
template<class Source,class Event>class Notifier;
struct RaiseRange;
template<class Source,class Event>class __declspec(novtable)Listener;
template<class Source,class Event>class __declspec(novtable)Notifier{public:void addListener(Listener<Source,Event>*listener)const;void removeListener(Listener<Source,Event>*listener)const;protected:Notifier();virtual~Notifier();virtual void onAddListener(Listener<Source,Event>*listener)const;virtual void onRemoveListener(Listener<Source,Event>*listener)const;bool hasListeners()const;void raise(Event event,Listener<Source,Event>*listener)const;void raise(Event event)const throw();private:mutable std::vector<Listener<Source,Event>*>listeners;mutable RaiseRange*raiseRange;};
template<class Source,class Event>void Notifier<Source,Event>::addListener(Listener<Source,Event>*listener)const;
template<class Source,class Event>void Notifier<Source,Event>::removeListener(Listener<Source,Event>*listener)const;
template<class Source,class Event>void Notifier<Source,Event>::raise(Event event,Listener<Source,Event>*listener)const;
template<class Source,class Event>void Notifier<Source,Event>::raise(Event event)const throw();
}namespace boost{class bad_weak_ptr:public std::exception{public:virtual char const*what()const throw(){return"tr1::bad_weak_ptr";}};
namespace detail{class sp_counted_base{private:sp_counted_base(sp_counted_base const&);sp_counted_base&operator=(sp_counted_base const&);long use_count_;long weak_count_;public:sp_counted_base():use_count_(1),weak_count_(1){}virtual~sp_counted_base(){}virtual void dispose()=0;virtual void destroy(){delete this;}virtual void*get_deleter(std::type_info const&ti)=0;void add_ref_copy(){_InterlockedIncrement(&use_count_);}bool add_ref_lock(){for(;;){long tmp=static_cast<long const volatile&>(use_count_);if(tmp==0)return false;if(_InterlockedCompareExchange(&use_count_,tmp+1,tmp)==tmp)return true;}}void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}void weak_add_ref(){_InterlockedIncrement(&weak_count_);}void weak_release(){if(_InterlockedDecrement(&weak_count_)==0){destroy();}}long use_count()const{return static_cast<long const volatile&>(use_count_);}};
template<class X>class sp_counted_impl_p;
template<class P,class D>class sp_counted_impl_pd;
template<class P,class D,class A>class sp_counted_impl_pda;
class weak_count;
class shared_count{private:sp_counted_base*pi_;friend class weak_count;public:shared_count():pi_(0){}template<class Y>explicit shared_count(Y*p):pi_(0){try{pi_=new sp_counted_impl_p<Y>(p);}catch(...){boost::checked_delete(p);throw;}}template<class P,class D>shared_count(P p,D d):pi_(0){try{pi_=new sp_counted_impl_pd<P,D>(p,d);}catch(...){d(p);throw;}}template<class P,class D,class A>shared_count(P p,D d,A a):pi_(0){typedef sp_counted_impl_pda<P,D,A>impl_type;typedef typename A::template rebind<impl_type>::other A2;A2 a2(a);try{pi_=a2.allocate(1,static_cast<impl_type*>(0));new(static_cast<void*>(pi_))impl_type(p,d,a);}catch(...){d(p);if(pi_!=0){a2.deallocate(static_cast<impl_type*>(pi_),1);}throw;}}template<class Y>explicit shared_count(std::auto_ptr<Y>&r):pi_(new sp_counted_impl_p<Y>(r.get())){r.release();}~shared_count(){if(pi_!=0)pi_->release();}shared_count(shared_count const&r):pi_(r.pi_){if(pi_!=0)pi_->add_ref_copy();}explicit shared_count(weak_count const&r);shared_count&operator=(shared_count const&r){sp_counted_base*tmp=r.pi_;if(tmp!=pi_){if(tmp!=0)tmp->add_ref_copy();if(pi_!=0)pi_->release();pi_=tmp;}return*this;}void swap(shared_count&r){sp_counted_base*tmp=r.pi_;r.pi_=pi_;pi_=tmp;}long use_count()const{return pi_!=0?pi_->use_count():0;}bool unique()const{return use_count()==1;}friend inline bool operator==(shared_count const&a,shared_count const&b){return a.pi_==b.pi_;}friend inline bool operator<(shared_count const&a,shared_count const&b){return std::less<sp_counted_base*>()(a.pi_,b.pi_);}void*get_deleter(std::type_info const&ti)const{return pi_?pi_->get_deleter(ti):0;}};
class weak_count{private:sp_counted_base*pi_;friend class shared_count;public:weak_count():pi_(0){}weak_count(shared_count const&r):pi_(r.pi_){if(pi_!=0)pi_->weak_add_ref();}weak_count(weak_count const&r):pi_(r.pi_){if(pi_!=0)pi_->weak_add_ref();}~weak_count(){if(pi_!=0)pi_->weak_release();}weak_count&operator=(shared_count const&r){sp_counted_base*tmp=r.pi_;if(tmp!=0)tmp->weak_add_ref();if(pi_!=0)pi_->weak_release();pi_=tmp;return*this;}weak_count&operator=(weak_count const&r){sp_counted_base*tmp=r.pi_;if(tmp!=0)tmp->weak_add_ref();if(pi_!=0)pi_->weak_release();pi_=tmp;return*this;}void swap(weak_count&r){sp_counted_base*tmp=r.pi_;r.pi_=pi_;pi_=tmp;}long use_count()const{return pi_!=0?pi_->use_count():0;}friend inline bool operator==(weak_count const&a,weak_count const&b){return a.pi_==b.pi_;}friend inline bool operator<(weak_count const&a,weak_count const&b){return std::less<sp_counted_base*>()(a.pi_,b.pi_);}};

}template<class T>class weak_ptr;
template<class T>class enable_shared_from_this;
namespace detail{struct static_cast_tag;
struct const_cast_tag;
struct dynamic_cast_tag;
struct polymorphic_cast_tag;
template<class T>struct shared_ptr_traits{typedef T&reference;};
template<>struct shared_ptr_traits<void>{typedef void reference;};
template<>struct shared_ptr_traits<void const>{typedef void reference;};
template<>struct shared_ptr_traits<void volatile>{typedef void reference;};
template<>struct shared_ptr_traits<void const volatile>{typedef void reference;};

inline void sp_enable_shared_from_this(shared_count const&,...){}
template<class T,class R>struct sp_enable_if_auto_ptr;
template<class T,class R>struct sp_enable_if_auto_ptr<std::auto_ptr<T>,R>{typedef R type;};
}template<class T>class shared_ptr{private:typedef shared_ptr<T>this_type;public:typedef T element_type;typedef T value_type;typedef T*pointer;typedef typename boost::detail::shared_ptr_traits<T>::reference reference;shared_ptr():px(0),pn(){}template<class Y>explicit shared_ptr(Y*p):px(p),pn(p){boost::detail::sp_enable_shared_from_this(pn,p,p);}template<class Y,class D>shared_ptr(Y*p,D d):px(p),pn(p,d){boost::detail::sp_enable_shared_from_this(pn,p,p);}template<class Y,class D,class A>shared_ptr(Y*p,D d,A a):px(p),pn(p,d,a){boost::detail::sp_enable_shared_from_this(pn,p,p);}template<class Y>explicit shared_ptr(weak_ptr<Y>const&r):pn(r.pn){px=r.px;}template<class Y>shared_ptr(shared_ptr<Y>const&r):px(r.px),pn(r.pn){}template<class Y>shared_ptr(shared_ptr<Y>const&r,boost::detail::static_cast_tag):px(static_cast<element_type*>(r.px)),pn(r.pn){}template<class Y>shared_ptr(shared_ptr<Y>const&r,boost::detail::const_cast_tag):px(const_cast<element_type*>(r.px)),pn(r.pn){}template<class Y>shared_ptr(shared_ptr<Y>const&r,boost::detail::dynamic_cast_tag):px(dynamic_cast<element_type*>(r.px)),pn(r.pn){if(px==0){pn=boost::detail::shared_count();}}template<class Y>shared_ptr(shared_ptr<Y>const&r,boost::detail::polymorphic_cast_tag):px(dynamic_cast<element_type*>(r.px)),pn(r.pn){if(px==0){boost::throw_exception(std::bad_cast());}}template<class Y>explicit shared_ptr(std::auto_ptr<Y>&r):px(r.get()),pn(){Y*tmp=r.get();pn=boost::detail::shared_count(r);boost::detail::sp_enable_shared_from_this(pn,tmp,tmp);}template<class Ap>explicit shared_ptr(Ap r,typename boost::detail::sp_enable_if_auto_ptr<Ap,int>::type=0):px(r.get()),pn(){typename Ap::element_type*tmp=r.get();pn=boost::detail::shared_count(r);boost::detail::sp_enable_shared_from_this(pn,tmp,tmp);}template<class Y>shared_ptr&operator=(shared_ptr<Y>const&r){px=r.px;pn=r.pn;return*this;}template<class Y>shared_ptr&operator=(std::auto_ptr<Y>&r){this_type(r).swap(*this);return*this;}template<class Ap>typename boost::detail::sp_enable_if_auto_ptr<Ap,shared_ptr&>::type operator=(Ap r){this_type(r).swap(*this);return*this;}void reset(){this_type().swap(*this);}template<class Y>void reset(Y*p){((void)0);this_type(p).swap(*this);}template<class Y,class D>void reset(Y*p,D d){this_type(p,d).swap(*this);}template<class Y,class D,class A>void reset(Y*p,D d,A a){this_type(p,d,a).swap(*this);}reference operator*()const{((void)0);return*px;}T*operator->()const{((void)0);return px;}T*get()const{return px;}typedef T*this_type::*unspecified_bool_type;operator unspecified_bool_type()const{return px==0?0:&this_type::px;}bool operator!()const{return px==0;}bool unique()const{return pn.unique();}long use_count()const{return pn.use_count();}void swap(shared_ptr<T>&other){std::swap(px,other.px);pn.swap(other.pn);}template<class Y>bool _internal_less(shared_ptr<Y>const&rhs)const{return pn<rhs.pn;}void*_internal_get_deleter(std::type_info const&ti)const{return pn.get_deleter(ti);}private:template<class Y>friend class shared_ptr;template<class Y>friend class weak_ptr;T*px;boost::detail::shared_count pn;};
template<class T,class U>inline bool operator==(shared_ptr<T>const&a,shared_ptr<U>const&b){return a.get()==b.get();}
template<class T,class U>inline bool operator!=(shared_ptr<T>const&a,shared_ptr<U>const&b){return a.get()!=b.get();}
template<class T,class U>inline bool operator<(shared_ptr<T>const&a,shared_ptr<U>const&b){return a._internal_less(b);}
template<class T>inline void swap(shared_ptr<T>&a,shared_ptr<T>&b){a.swap(b);}
template<class T>inline T*get_pointer(shared_ptr<T>const&p){return p.get();}
template<class E,class T,class Y>std::basic_ostream<E,T>&operator<<(std::basic_ostream<E,T>&os,shared_ptr<Y>const&p){os<<p.get();return os;}
template<class D,class T>D*get_deleter(shared_ptr<T>const&p){return static_cast<D*>(p._internal_get_deleter(typeid(D)));}
template<class T>class weak_ptr{private:typedef weak_ptr<T>this_type;public:typedef T element_type;weak_ptr():px(0),pn(){}template<class Y>weak_ptr(weak_ptr<Y>const&r):pn(r.pn){px=r.lock().get();}template<class Y>weak_ptr(shared_ptr<Y>const&r):px(r.px),pn(r.pn){}template<class Y>weak_ptr&operator=(weak_ptr<Y>const&r){px=r.lock().get();pn=r.pn;return*this;}template<class Y>weak_ptr&operator=(shared_ptr<Y>const&r){px=r.px;pn=r.pn;return*this;}shared_ptr<T>lock()const{if(expired()){return shared_ptr<element_type>();}try{return shared_ptr<element_type>(*this);}catch(bad_weak_ptr const&){return shared_ptr<element_type>();}}long use_count()const{return pn.use_count();}bool expired()const{return pn.use_count()==0;}void reset(){this_type().swap(*this);}void swap(this_type&other){std::swap(px,other.px);pn.swap(other.pn);}void _internal_assign(T*px2,boost::detail::shared_count const&pn2){px=px2;pn=pn2;}template<class Y>bool _internal_less(weak_ptr<Y>const&rhs)const{return pn<rhs.pn;}private:template<class Y>friend class weak_ptr;template<class Y>friend class shared_ptr;T*px;boost::detail::weak_count pn;};
template<class T,class U>inline bool operator<(weak_ptr<T>const&a,weak_ptr<U>const&b){return a._internal_less(b);}
template<class T>void swap(weak_ptr<T>&a,weak_ptr<T>&b){a.swap(b);}
template<class T>class enable_shared_from_this{protected:enable_shared_from_this(){}enable_shared_from_this(enable_shared_from_this const&){}enable_shared_from_this&operator=(enable_shared_from_this const&){return*this;}~enable_shared_from_this(){}public:shared_ptr<T>shared_from_this(){shared_ptr<T>p(_internal_weak_this);((void)0);return p;}shared_ptr<T const>shared_from_this()const{shared_ptr<T const>p(_internal_weak_this);((void)0);return p;}typedef T _internal_element_type;mutable weak_ptr<_internal_element_type>_internal_weak_this;};
template<typename F,typename G>bool function_equal_impl(const F&f,const G&g,long){return f==g;}
template<typename F,typename G>bool function_equal(const F&f,const G&g){return function_equal_impl(f,g,0);}

namespace detail{namespace function{class X;
union function_buffer{void*obj_ptr;const void*const_obj_ptr;mutable void(*func_ptr)();struct bound_memfunc_ptr_t{void(X::*memfunc_ptr)(int);void*obj_ptr;}bound_memfunc_ptr;mutable char data;};
enum functor_manager_operation_type{clone_functor_tag,destroy_functor_tag,check_functor_type_tag,get_functor_type_tag};
struct useless_clear_type;
struct vtable_base{vtable_base():manager(0){}void(*manager)(const function_buffer&in_buffer,function_buffer&out_buffer,functor_manager_operation_type op);};
}}class function_base{public:function_base():vtable(0){}bool empty()const{return!vtable;}const std::type_info&target_type()const{if(!vtable)return typeid(void);detail::function::function_buffer type;vtable->manager(functor,type,detail::function::get_functor_type_tag);return*static_cast<const std::type_info*>(type.const_obj_ptr);}template<typename Functor>Functor*target(){if(!vtable)return 0;detail::function::function_buffer type_result;type_result.const_obj_ptr=&typeid(Functor);vtable->manager(functor,type_result,detail::function::check_functor_type_tag);return static_cast<Functor*>(type_result.obj_ptr);}template<typename Functor>const Functor*target()const{if(!vtable)return 0;detail::function::function_buffer type_result;type_result.const_obj_ptr=&typeid(Functor);vtable->manager(functor,type_result,detail::function::check_functor_type_tag);return(const Functor*)(type_result.obj_ptr);}template<typename F>bool contains(const F&f)const{if(const F*fp=this->template target<F>()){return function_equal(*fp,f);}else{return false;}}public:detail::function::vtable_base*vtable;mutable detail::function::function_buffer functor;};
inline bool operator==(const function_base&f,detail::function::useless_clear_type*){return f.empty();}
inline bool operator!=(const function_base&f,detail::function::useless_clear_type*){return!f.empty();}
inline bool operator==(detail::function::useless_clear_type*,const function_base&f){return f.empty();}
inline bool operator!=(detail::function::useless_clear_type*,const function_base&f){return!f.empty();}








template<typename R,typename Allocator=std::allocator<function_base> >class function0;
template<typename R,typename Allocator>inline void swap(function0<R,Allocator>&f1,function0<R,Allocator>&f2){f1.swap(f2);}

template<typename R,typename Allocator>void operator==(const function0<R,Allocator>&,const function0<R,Allocator>&);
template<typename R,typename Allocator>void operator!=(const function0<R,Allocator>&,const function0<R,Allocator>&);
namespace detail{namespace function{template<typename R,typename T0,typename Allocator>struct basic_vtable1;
}}template<typename R,typename T0,typename Allocator=std::allocator<function_base> >class function1:public function_base{public:typedef R result_type;private:typedef boost::detail::function::basic_vtable1<R,T0,Allocator>vtable_type;struct clear_type{};public:static const int args=1;template<typename Args>struct sig{typedef result_type type;};typedef T0 argument_type;static const int arity=1;typedef T0 arg1_type;typedef Allocator allocator_type;typedef function1 self_type;function1():function_base(){}template<typename Functor>function1(Functor f,typename enable_if_c<(boost::type_traits::ice_not<(is_integral<Functor>::value)>::value),int>::type=0):function_base(){this->assign_to(f);}function1(clear_type*):function_base(){}function1(const function1&f):function_base(){this->assign_to_own(f);}~function1(){clear();}result_type operator()(T0 a0)const;template<typename Functor>typename enable_if_c<(boost::type_traits::ice_not<(is_integral<Functor>::value)>::value),function1&>::type operator=(Functor f){this->clear();try{this->assign_to(f);}catch(...){vtable=0;throw;}return*this;}function1&operator=(clear_type*){this->clear();return*this;}function1&operator=(const function1&f){if(&f==this)return*this;this->clear();try{this->assign_to_own(f);}catch(...){vtable=0;throw;}return*this;}void swap(function1&other){if(&other==this)return;function1 tmp=*this;*this=other;other=tmp;}void clear(){if(vtable){static_cast<vtable_type*>(vtable)->clear(this->functor);vtable=0;}}private:struct dummy{void nonnull(){};};typedef void(dummy::*safe_bool)();public:operator safe_bool()const{return(this->empty())?0:&dummy::nonnull;}bool operator!()const{return this->empty();}private:void assign_to_own(const function1&f){if(!f.empty()){this->vtable=f.vtable;f.vtable->manager(f.functor,this->functor,boost::detail::function::clone_functor_tag);}}template<typename Functor>void assign_to(Functor f){static vtable_type stored_vtable(f);if(stored_vtable.assign_to(f,functor))vtable=&stored_vtable;else vtable=0;}};
template<typename R,typename T0,typename Allocator>inline void swap(function1<R,T0,Allocator>&f1,function1<R,T0,Allocator>&f2){f1.swap(f2);}

template<typename R,typename T0,typename Allocator>void operator==(const function1<R,T0,Allocator>&,const function1<R,T0,Allocator>&);
template<typename R,typename T0,typename Allocator>void operator!=(const function1<R,T0,Allocator>&,const function1<R,T0,Allocator>&);




































class mutex:private noncopyable{public:friend class detail::thread::lock_ops<mutex>;typedef detail::thread::scoped_lock<mutex>scoped_lock;mutex();~mutex();private:typedef void*cv_state;void do_lock();void do_unlock();void do_lock(cv_state&state);void do_unlock(cv_state&state);void*m_mutex;bool m_critical_section;};
}namespace RBX{enum MessageType{MESSAGE_OUTPUT=0,MESSAGE_INFO=1,MESSAGE_WARNING=2,MESSAGE_ERROR=3};
struct StandardOutMessage;
class StandardOut:public boost::enable_shared_from_this<StandardOut>,public Notifier<StandardOut,StandardOutMessage>{public:static boost::shared_ptr<StandardOut>singleton();static void print_exception(const boost::function0<void>&job,MessageType type,bool rethrow);void print(MessageType type,const std::exception&error);void print(MessageType type,const char*format,...);boost::mutex sync;};
}namespace boost{template<class T>class scoped_ptr{private:T*ptr;scoped_ptr(scoped_ptr const&);scoped_ptr&operator=(scoped_ptr const&);typedef scoped_ptr<T>this_type;public:typedef T element_type;explicit scoped_ptr(T*p=0):ptr(p){}explicit scoped_ptr(std::auto_ptr<T>p):ptr(p.release()){}~scoped_ptr(){boost::checked_delete(ptr);}void reset(T*p=0){((void)0);this_type(p).swap(*this);}T&operator*()const{((void)0);return*ptr;}T*operator->()const{((void)0);return ptr;}T*get()const{return ptr;}typedef T*this_type::*unspecified_bool_type;operator unspecified_bool_type()const{return ptr==0?0:&this_type::ptr;}bool operator!()const{return ptr==0;}void swap(scoped_ptr&b){T*tmp=b.ptr;b.ptr=ptr;ptr=tmp;}};
template<class T>inline void swap(scoped_ptr<T>&a,scoped_ptr<T>&b){a.swap(b);}
template<class T>inline T*get_pointer(scoped_ptr<T>const&p){return p.get();}
template<class T>class scoped_array;
template<class T>inline void swap(scoped_array<T>&a,scoped_array<T>&b){a.swap(b);}
template<class T>class shared_array;
template<class T>inline bool operator==(shared_array<T>const&a,shared_array<T>const&b){return a.get()==b.get();}
template<class T>inline bool operator!=(shared_array<T>const&a,shared_array<T>const&b){return a.get()!=b.get();}
template<class T>inline bool operator<(shared_array<T>const&a,shared_array<T>const&b){return std::less<T*>()(a.get(),b.get());}
template<class T>void swap(shared_array<T>&a,shared_array<T>&b){a.swap(b);}
template<class T>class intrusive_ptr;
template<class T,class U>inline bool operator==(intrusive_ptr<T>const&a,intrusive_ptr<U>const&b){return a.get()==b.get();}
template<class T,class U>inline bool operator!=(intrusive_ptr<T>const&a,intrusive_ptr<U>const&b){return a.get()!=b.get();}
template<class T,class U>inline bool operator==(intrusive_ptr<T>const&a,U*b){return a.get()==b;}
template<class T,class U>inline bool operator!=(intrusive_ptr<T>const&a,U*b){return a.get()!=b;}
template<class T,class U>inline bool operator==(T*a,intrusive_ptr<U>const&b){return a==b.get();}
template<class T,class U>inline bool operator!=(T*a,intrusive_ptr<U>const&b){return a!=b.get();}
template<class T>inline bool operator<(intrusive_ptr<T>const&a,intrusive_ptr<T>const&b){return std::less<T*>()(a.get(),b.get());}
template<class T>void swap(intrusive_ptr<T>&lhs,intrusive_ptr<T>&rhs){lhs.swap(rhs);}
template<class T>T*get_pointer(intrusive_ptr<T>const&p){return p.get();}

namespace detail{class none_helper;
class none_helper;
}typedef void(*none_t)(detail::none_helper);

template<class OptionalPointee>inline bool less_pointees(OptionalPointee const&x,OptionalPointee const&y){return!y?false:(!x?true:(*x)<(*y));}
template<class T>class optional;
template<class T>class optional;
template<class T>inline typename optional<T>::reference_const_type get(optional<T>const&opt){return opt.get();}
template<class T>inline typename optional<T>::reference_type get(optional<T>&opt){return opt.get();}
template<class T>inline typename optional<T>::pointer_const_type get(optional<T>const*opt){return opt->get_ptr();}
template<class T>inline typename optional<T>::pointer_type get(optional<T>*opt){return opt->get_ptr();}
template<class T>inline typename optional<T>::pointer_const_type get_pointer(optional<T>const&opt){return opt.get_ptr();}
template<class T>inline typename optional<T>::pointer_type get_pointer(optional<T>&opt){return opt.get_ptr();}
template<class T>inline bool operator==(optional<T>const&x,optional<T>const&y){return equal_pointees(x,y);}
template<class T>inline bool operator<(optional<T>const&x,optional<T>const&y){return less_pointees(x,y);}
template<class T>inline bool operator!=(optional<T>const&x,optional<T>const&y){return!(x==y);}
template<class T>inline bool operator>(optional<T>const&x,optional<T>const&y){return y<x;}
template<class T>inline bool operator<=(optional<T>const&x,optional<T>const&y){return!(y<x);}
template<class T>inline bool operator>=(optional<T>const&x,optional<T>const&y){return!(x<y);}
template<class T>inline bool operator==(optional<T>const&x,T const&y){return equal_pointees(x,optional<T>(y));}
template<class T>inline bool operator<(optional<T>const&x,T const&y){return less_pointees(x,optional<T>(y));}
template<class T>inline bool operator!=(optional<T>const&x,T const&y){return!(x==y);}
template<class T>inline bool operator>(optional<T>const&x,T const&y){return y<x;}
template<class T>inline bool operator<=(optional<T>const&x,T const&y){return!(y<x);}
template<class T>inline bool operator>=(optional<T>const&x,T const&y){return!(x<y);}
template<class T>inline bool operator==(T const&x,optional<T>const&y){return equal_pointees(optional<T>(x),y);}
template<class T>inline bool operator<(T const&x,optional<T>const&y){return less_pointees(optional<T>(x),y);}
template<class T>inline bool operator!=(T const&x,optional<T>const&y){return!(x==y);}
template<class T>inline bool operator>(T const&x,optional<T>const&y){return y<x;}
template<class T>inline bool operator<=(T const&x,optional<T>const&y){return!(y<x);}
template<class T>inline bool operator>=(T const&x,optional<T>const&y){return!(x<y);}
template<class T>inline bool operator==(optional<T>const&x,none_t){return equal_pointees(x,optional<T>());}
template<class T>inline bool operator<(optional<T>const&x,none_t){return less_pointees(x,optional<T>());}
template<class T>inline bool operator!=(optional<T>const&x,none_t y){return!(x==y);}
template<class T>inline bool operator>(optional<T>const&x,none_t y){return y<x;}
template<class T>inline bool operator<=(optional<T>const&x,none_t y){return!(y<x);}
template<class T>inline bool operator>=(optional<T>const&x,none_t y){return!(x<y);}
template<class T>inline bool operator==(none_t x,optional<T>const&y){return equal_pointees(optional<T>(),y);}
template<class T>inline bool operator<(none_t x,optional<T>const&y){return less_pointees(optional<T>(),y);}
template<class T>inline bool operator!=(none_t x,optional<T>const&y){return!(x==y);}
template<class T>inline bool operator>(none_t x,optional<T>const&y){return y<x;}
template<class T>inline bool operator<=(none_t x,optional<T>const&y){return!(y<x);}
template<class T>inline bool operator>=(none_t x,optional<T>const&y){return!(x<y);}
namespace optional_detail{
}template<class T>inline void swap(optional<T>&x,optional<T>&y){optional_detail::optional_swap(x,y);}






















}namespace RBX{namespace Reflection{class SignalDescriptor;
class SignalSource;
class SignalInstance;
class __declspec(novtable)SignalSource{public:typedef std::map<const SignalDescriptor*,boost::shared_ptr<SignalInstance> >SignalMap;virtual~SignalSource();void disconnect_all_slots();private:friend class SignalDescriptor;boost::scoped_ptr<SignalMap>signals;};
class __declspec(novtable)SignalDescriptor;
template<class Class,class Signature>class SignalDesc;
class ClassDescriptor;
}class Instance;
class Instance;
namespace Reflection{class DescribedBase;
}class __declspec(novtable)IReferenceBinder;
class Instance;
class Name;
}class XmlElement;
namespace boost{namespace mpl{template<typename N1=na,typename N2=na>struct equal_to;
template<>struct equal_to<na,na>;
template<typename Tag>struct lambda<equal_to<na,na>,Tag>{typedef false_ is_le;typedef equal_to<na,na>result_;typedef equal_to<na,na>type;};
template<typename N1=na,typename N2=na,typename N3=na,typename N4=na,typename N5=na>struct times;
template<typename N1,typename N2,typename N3,typename N4>struct times<N1,N2,N3,N4,na>;
template<typename N1,typename N2,typename N3>struct times<N1,N2,N3,na,na>;
template<typename N1,typename N2>struct times<N1,N2,na,na,na>;
template<>struct times<na,na>;
template<typename Tag>struct lambda<times<na,na>,Tag>;
template<typename N1=na,typename N2=na,typename N3=na,typename N4=na,typename N5=na>struct multiplies;
template<>struct multiplies<na,na,na,na,na>;
template<typename Tag>struct lambda<multiplies<na,na,na,na,na>,Tag>;
}}namespace RBX{namespace Reflection{class DescribedBase:public SignalSource{public:static ClassDescriptor&classDescriptor();virtual~DescribedBase();const ClassDescriptor&getDescriptor()const;protected:const ClassDescriptor*descriptor;};
template<class T,const char*sName,class Base>class __declspec(novtable)Described:public Base{public:Described();template<class U>Described(U*joint);static ClassDescriptor&classDescriptor();};
template<class Class,class T>class RefPropDescriptor;
}template<class T>class Association{public:class Item;private:std::vector<Item*>items;};
class Name;
class Guid:private boost::noncopyable{public:struct Data{bool operator<(const Data&other)const;std::string readableString(int scopeLength)const;const Name*scope;int index;};Guid();void assign(Data data);static int compare(const Guid*a,const Guid*b);static int compare(const Guid*a0,const Guid*a1,const Guid*b0,const Guid*b1);static const Name&getLocalScope();static void generateGUID(std::string&result);Data data;};
template<class T>class GuidItem{public:virtual~GuidItem();private:bool registeredGuid;Guid guid;};
class Debugable{public:enum AssertAction{CrashOnAssert=0,IgnoreAssert=1};static AssertAction assertAction;static bool validatingDebug;static void forceBadTypeId();static void doCrash();static void dump(void*object,std::ostream&stream);virtual void dump(std::ostream&stream);};
template<class T>class CopyOnWrite:public boost::noncopyable{public:operator typename boost::shared_ptr<T>::unspecified_bool_type()const;const T&operator*()const;const T*operator->()const;boost::shared_ptr<const T>read()const;boost::shared_ptr<T>&write();void reset();private:boost::shared_ptr<T>object;};
class Instance;
class Object{public:virtual~Object();};
template<class T,class Base>boost::shared_ptr<T>shared_from_dynamic_cast(boost::enable_shared_from_this<Base>*r);
template<class T>class Creatable:public Object{public:class Deleter{public:void operator()(T*instance);};template<class U>static boost::shared_ptr<U>create();template<class U,class A>static boost::shared_ptr<U>create(A argument);protected:Creatable();virtual~Creatable();static void*operator new(size_t size);static void operator delete(void*p);};
using boost::shared_ptr;
class IReferenceBinder;
class Instance;
class Name;
class ServiceProvider;
struct ChildAdded{const boost::shared_ptr<Instance>child;ChildAdded(Instance*child);private:ChildAdded&operator=(const ChildAdded&other);};
struct ChildRemoved;
struct DescendentAdded;
struct DescendentRemoving{const boost::shared_ptr<Instance>instance;const boost::shared_ptr<Instance>parent;};
struct AncestorChanged;
class PropertyChanged;
template<class T>class AbstractFactoryProduct:public Creatable<T>{public:virtual~AbstractFactoryProduct();virtual const Name&getClassName()const=0;};
extern const char sInstance[];
class Instance:public GuidItem<Instance>,public AbstractFactoryProduct<Instance>,public Reflection::Described<Instance,sInstance,Reflection::DescribedBase>,public Debugable,public Notifier<Instance,ChildAdded>,public Notifier<Instance,ChildRemoved>,public Notifier<Instance,DescendentAdded>,public Notifier<Instance,DescendentRemoving>,public Notifier<Instance,AncestorChanged>,public Notifier<Instance,PropertyChanged>,public boost::enable_shared_from_this<Instance>,public boost::noncopyable{public:Instance();protected:Instance(const char*name);virtual~Instance();public:virtual void setName(const std::string&value);protected:virtual bool askAddChild(const Instance*instance)const;virtual bool askSetParent(const Instance*instance)const;virtual void onAncestorChanged(const AncestorChanged&event);virtual void onDescendentAdded(Instance*instance);virtual void onDescendentRemoving(const shared_ptr<Instance>&instance);virtual void onChildAdded(Instance*child);virtual void onChildRemoving(Instance*child);virtual void onChildRemoved(Instance*child);private:virtual void onLastChildRemoved();protected:virtual void readProperty(const XmlElement*element,IReferenceBinder&binder);public:virtual void onServiceProvider(const ServiceProvider*oldProvider,const ServiceProvider*newProvider);virtual shared_ptr<Instance>createChild(const Name&className);virtual XmlElement*write();protected:virtual void onChildChanged(Instance*child,const PropertyChanged&event);public:static Reflection::SignalDesc<Instance,void(shared_ptr<Instance>)>event_childAdded;static Reflection::SignalDesc<Instance,void(shared_ptr<Instance>)>event_childRemoved;static Reflection::SignalDesc<Instance,void(shared_ptr<Instance>)>event_ancestryChanged;static Reflection::SignalDesc<Instance,void(const Reflection::PropertyDescriptor*)>event_propertyChanged;static const Reflection::RefPropDescriptor<Instance,Instance>propParent;Instance*getParent()const;void setParent(Instance*newParent);Instance*getRootAncestor();Instance*findFirstChildByName(const std::string&findName)const;template<class T>T*findFirstChildOfType()const;const std::string&getName()const;const CopyOnWrite<std::vector<shared_ptr<Instance> > >&getChildren()const;unsigned int numChildren()const;const Instance*getChild(unsigned int index)const;Instance*getChild(unsigned int index);void raisePropertyChanged(const Reflection::PropertyDescriptor&descriptor);void readProperties(const XmlElement*element,IReferenceBinder&binder);void readChild(const XmlElement*childElement,IReferenceBinder&binder);void readChildren(const XmlElement*element,IReferenceBinder&binder);void writeChildren(XmlElement*element);bool contains(const Instance*instance)const;bool canAddChild(const Instance*child)const;bool canSetParent(const Instance*parent)const;template<class T>const T*getTypedRoot()const;bool isAncestorOf(const Instance*descendent)const;bool isDescendentOf(const Instance*ancestor)const;private:friend class Creatable<Instance>::Deleter;void predelete();static void predelete(Instance*instance);static void signalDescendentAdded(Instance*instance,Instance*beginParent,Instance*oldParent);static void signalDescendentRemoving(const shared_ptr<Instance>&instance,Instance*beginParent,Instance*newParent);Association<Instance>assoc;Instance*parent;CopyOnWrite<std::vector<boost::shared_ptr<Instance> > >children;std::string name;bool archivable;};

}namespace G3D{















class Triangle;
class Ray;
}namespace RBX{class PartInstance;
class ModelInstance;
}
namespace RakNet {class BitStream;}
template<class T>inline T&receiverField(void*p,unsigned o){return *reinterpret_cast<T*>(static_cast<char*>(p)+o);}
namespace RBX {
class NativeReceiverAssembly {public:bool getAnchored()const;};
class NativeReceiverPrimitive {public:NativeReceiverAssembly*getAssembly()const;};
class PartInstance {public:static bool nonNullInWorkspace(boost::shared_ptr<PartInstance>);NativeReceiverPrimitive&primitive(){return receiverField<NativeReceiverPrimitive>(this,0x228);}};
template<> boost::shared_ptr<PartInstance> shared_from_dynamic_cast<PartInstance,Instance>(boost::enable_shared_from_this<Instance>*);
namespace Network {
class Player;
class IdSerializer:public Instance {};
class PluginInterface {public:virtual~PluginInterface();};
class Replicator:public IdSerializer,public PluginInterface {public:virtual bool wantReplicate(const Instance*)const;virtual Player*findTargetPlayer();bool deserializeInstanceRef(RakNet::BitStream&,Instance*&,Guid::Data&);};
class Settings {public:static Settings&singleton();};
class IPhysicsReceiver:private boost::noncopyable {public:virtual~IPhysicsReceiver();virtual void step(unsigned)=0;virtual void receivePacket(RakNet::BitStream&,unsigned)=0;Replicator*replicator;};
}}
struct ReceiverNativeHistory {
 unsigned timestamp;
 G3D::CoordinateFrame frame;
 std::vector<float>motors;
};
struct ReceiverNativeNugget {
 boost::shared_ptr<RBX::PartInstance>part;
 unsigned key8;
 double interval;
 int last;
 int count;
 ReceiverNativeHistory history[8];
 ReceiverNativeNugget(const boost::shared_ptr<RBX::PartInstance>&);
 ~ReceiverNativeNugget();
 void receive(RakNet::BitStream&,unsigned,RBX::ModelInstance*);
};
struct ReceiverPartHash {size_t operator()(const boost::shared_ptr<RBX::PartInstance>&p)const{return boost::hash<RBX::PartInstance*>()(p.get());}};
namespace bmi=boost::multi_index;
typedef boost::multi_index_container<ReceiverNativeNugget,bmi::indexed_by<
 bmi::hashed_unique<bmi::member<ReceiverNativeNugget,boost::shared_ptr<RBX::PartInstance>,&ReceiverNativeNugget::part>,ReceiverPartHash >,
 bmi::ordered_non_unique<bmi::member<ReceiverNativeNugget,unsigned,&ReceiverNativeNugget::key8> >
> >ReceiverNativeRecords;
namespace RBX {namespace Network {
class InterpolatingPhysicsReceiver:public IPhysicsReceiver {public:ReceiverNativeRecords records;virtual void receivePacket(RakNet::BitStream&,unsigned);};
}}
void RBX::Network::InterpolatingPhysicsReceiver::receivePacket(RakNet::BitStream&stream,unsigned timestamp){
 ReceiverNativeRecords::nth_index<0>::type&index=records.get<0>();
 ModelInstance*character;
 Player*player=replicator->findTargetPlayer();
 if(player)character=receiverField<ModelInstance*>(player,0x170);else character=0;
 for(;;){
  boost::shared_ptr<PartInstance>part;
  Instance*instance;
  Guid::Data id;
  if(replicator->deserializeInstanceRef(stream,instance,id)){
   if(!instance)return;
   part=shared_from_dynamic_cast<PartInstance>(instance);
  }else if(receiverField<bool>(&Settings::singleton(),0x130))
   StandardOut::singleton()->print(MESSAGE_WARNING,"Physics-in of unidentified %s",id.readableString(4).c_str());
  if(part){
   if(!PartInstance::nonNullInWorkspace(part)){
    if(receiverField<bool>(&Settings::singleton(),0x130))StandardOut::singleton()->print(MESSAGE_INFO,"Physics-in of part not in workspace %s",id.readableString(4).c_str());
    part.reset();
   }else if(!part->primitive().getAssembly()){
    if(receiverField<bool>(&Settings::singleton(),0x130))StandardOut::singleton()->print(MESSAGE_INFO,"Physics-in of primitive with no assembly %s",id.readableString(4).c_str());
    part.reset();
   }else if(part->primitive().getAssembly()->getAnchored()){
    if(receiverField<bool>(&Settings::singleton(),0x130))StandardOut::singleton()->print(MESSAGE_INFO,"Physics-in of anchored assembly %s",id.readableString(4).c_str());
    part.reset();
   }
  }
  ReceiverNativeRecords::iterator found=index.find(part);
  if(found!=index.end())index.modify(found,boost::bind(&ReceiverNativeNugget::receive,_1,boost::ref(stream),timestamp,character));
  else{
   ReceiverNativeNugget nugget(part);
   nugget.receive(stream,timestamp,character);
   if(part)index.insert(nugget);
  }
 }
}
typedef char ReceiverHistorySize[sizeof(ReceiverNativeHistory)==76?1:-1];
typedef char ReceiverNuggetSize[sizeof(ReceiverNativeNugget)==640?1:-1];
typedef char ReceiverNuggetHistory[(size_t)&reinterpret_cast<const volatile char&>((((ReceiverNativeNugget *)0)->history))==32?1:-1];
typedef char ReceiverNuggetInterval[(size_t)&reinterpret_cast<const volatile char&>((((ReceiverNativeNugget *)0)->interval))==16?1:-1];
typedef char ReceiverContainerSize[sizeof(ReceiverNativeRecords)==52?1:-1];
typedef char ReceiverOwnerSize[sizeof(RBX::Network::InterpolatingPhysicsReceiver)==60?1:-1];