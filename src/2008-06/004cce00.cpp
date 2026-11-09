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
namespace boost{typedef long long long_long_type;
typedef unsigned long long ulong_long_type;
namespace mpl{struct void_;
template<bool C_>struct bool_;
typedef bool_<true>true_;
typedef bool_<false>false_;
struct integral_c_tag{static const int value=0;};
template<bool C_>struct bool_{static const bool value=C_;typedef integral_c_tag tag;typedef bool_ type;typedef bool value_type;operator bool()const{return this->value;}};
template<bool C_>bool const bool_<C_>::value;
struct na{typedef na type;enum{value=0};};
template<typename T>struct is_na:false_{};
template<>struct is_na<na>:true_{};
template<int N>struct int_;
template<int N>struct int_{static const int value=N;typedef int_ type;typedef int value_type;typedef integral_c_tag tag;typedef boost::mpl::int_<static_cast<int>((value+1))>next;typedef boost::mpl::int_<static_cast<int>((value-1))>prior;operator int()const{return static_cast<int>(this->value);}};
template<int N>int const boost::mpl::int_<N>::value;
template<typename T=na,typename Tag=void_>struct lambda;
template<bool C,typename T1,typename T2>struct if_c{typedef T1 type;};
template<typename T1,typename T2>struct if_c<false,T1,T2>{typedef T2 type;};
template<typename T1=na,typename T2=na,typename T3=na>struct if_{private:typedef if_c<static_cast<bool>(T1::value),T2,T3>almost_type_;public:typedef typename almost_type_::type type;};
template<>struct if_<na,na,na>;
template<typename Tag>struct lambda<if_<na,na,na>,Tag>;
template<typename C=na,typename F1=na,typename F2=na>struct eval_if:if_<C,F1,F2>::type{};
template<bool C,typename F1,typename F2>struct eval_if_c:if_c<C,F1,F2>::type{};
template<>struct eval_if<na,na,na>;
template<typename Tag>struct lambda<eval_if<na,na,na>,Tag>;
template<typename T,T N>struct integral_c;
template<typename T,T N>struct integral_c{static const T value=N;typedef integral_c type;typedef T value_type;typedef integral_c_tag tag;typedef integral_c<T,static_cast<T>((value+1))>next;typedef integral_c<T,static_cast<T>((value-1))>prior;operator T()const{return static_cast<T>(this->value);}};
template<typename T,T N>T const integral_c<T,N>::value;
template<bool C>struct integral_c<bool,C>;
}template<class T,T val>struct integral_constant:public mpl::integral_c<T,val>{typedef integral_constant<T,val>type;};
template<>struct integral_constant<bool,true>:public mpl::true_{typedef integral_constant<bool,true>type;};
template<>struct integral_constant<bool,false>:public mpl::false_{typedef integral_constant<bool,false>type;};
template<typename T,typename U>struct is_same: ::boost::integral_constant<bool,false>{};
template<typename T>struct is_same<T,T>;
namespace detail{namespace allocator{template<typename Allocator>struct is_partial_std_allocator{static const bool value=false;};
template<typename Allocator,typename Type>struct partial_std_allocator_rebind_to;
template<typename Allocator>struct rebinder{template<typename Type>struct result{typedef typename Allocator::template rebind<Type>::other other;};};
template<typename Allocator,typename Type>struct compliant_allocator_rebind_to{typedef typename rebinder<Allocator>::template result<Type>::other type;};
template<typename Allocator,typename Type>struct rebind_to:mpl::eval_if_c<is_partial_std_allocator<Allocator>::value,partial_std_allocator_rebind_to<Allocator,Type>,compliant_allocator_rebind_to<Allocator,Type> >{};
template<typename Type>void construct(void*p,const Type&t){new(p)Type(t);}
template<typename Type>void destroy(const Type*p){p->~Type();}
}}namespace mpl{template<typename Tag>struct at_impl;
template<typename Sequence,typename N>struct at;
template<typename Tag>struct begin_impl;
template<typename Tag>struct end_impl;
template<typename Sequence>struct begin;
template<typename Sequence>struct end;
struct nested_begin_end_tag;
struct non_sequence_tag;
template<typename Sequence>struct sequence_tag;
struct void_{typedef void_ type;};
template<typename T>struct is_void_;
template<>struct is_void_<void_>;
template<typename T>struct is_not_void_;
template<>struct is_not_void_<void_>;
template<>struct is_void_<na>;
template<typename Tag>struct lambda<is_void_<na>,Tag>;
template<>struct is_not_void_<na>;
template<typename Tag>struct lambda<is_not_void_<na>,Tag>;
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
template<>struct begin_impl<nested_begin_end_tag>;
template<>struct end_impl<nested_begin_end_tag>;
template<>struct begin_impl<non_sequence_tag>;
template<>struct end_impl<non_sequence_tag>;
template<>struct begin_impl<na>;
template<>struct end_impl<na>;
namespace aux{template<typename T,typename U=void>struct has_tag_impl_;
template<typename T>struct has_tag_impl_<T,typename boost::mpl::aux::msvc71_sfinae_helper<typename T::tag>::type>{static const bool value=true;typedef boost::mpl::bool_<value>type;};
template<typename T,typename fallback_=boost::mpl::bool_<false> >struct has_tag:has_tag_impl_<T>{};
template<bool has_tag_,bool has_begin_>struct sequence_tag_impl;
template<>struct sequence_tag_impl<true,true>{template<typename Sequence>struct result2_{typedef typename Sequence::tag type;};};
template<>struct sequence_tag_impl<true,false>{template<typename Sequence>struct result2_{typedef typename Sequence::tag type;};};
template<>struct sequence_tag_impl<false,true>;
template<>struct sequence_tag_impl<false,false>;
}template<typename Sequence=na>struct sequence_tag:aux::sequence_tag_impl< ::boost::mpl::aux::has_tag<Sequence>::value,::boost::mpl::aux::has_begin<Sequence>::value>::template result2_<Sequence>{};
template<>struct sequence_tag<na>;
template<typename Tag>struct lambda<sequence_tag<na>,Tag>;
template<typename Sequence=na>struct begin{typedef typename sequence_tag<Sequence>::type tag_;typedef typename begin_impl<tag_>::template apply<Sequence>::type type;};
template<typename Sequence=na>struct end{typedef typename sequence_tag<Sequence>::type tag_;typedef typename end_impl<tag_>::template apply<Sequence>::type type;};
template<>struct begin<na>;
template<typename Tag>struct lambda<begin<na>,Tag>;
template<>struct end<na>;
template<typename Tag>struct lambda<end<na>,Tag>;
template<typename Iterator,typename N>struct advance;
template<typename F,typename T1,typename T2>struct apply_wrap2:F::template apply<T1,T2>{};
template<typename F,typename T1,typename T2,typename T3,typename T4,typename T5>struct apply_wrap5:F::template apply<T1,T2,T3,T4,T5>{};
template<typename T,typename Default=void_>struct tag;
namespace aux{template<typename T>struct msvc_eti_base:T{typedef T type;};
template<>struct msvc_eti_base<int>;
}template<typename N1=na,typename N2=na>struct less;
template<>struct less<na,na>;
template<typename Tag>struct lambda<less<na,na>,Tag>;
template<typename N=na>struct negate;
template<>struct negate<na>;
template<typename Tag>struct lambda<negate<na>,Tag>;
template<long N>struct long_;
template<long N>struct long_{static const long value=N;typedef long_ type;typedef long value_type;typedef integral_c_tag tag;typedef boost::mpl::long_<static_cast<long>((value+1))>next;typedef boost::mpl::long_<static_cast<long>((value-1))>prior;operator long()const{return static_cast<long>(this->value);}};
template<long N>long const boost::mpl::long_<N>::value;
template<typename T=na>struct next;
template<typename T=na>struct prior;
template<>struct next<na>;
template<typename Tag>struct lambda<next<na>,Tag>;
template<>struct prior<na>;
template<typename Tag>struct lambda<prior<na>,Tag>;
template<typename Iterator=na,typename N=na>struct advance;
template<>struct advance<na,na>;
template<typename Tag>struct lambda<advance<na,na>,Tag>;
template<typename Iterator=na>struct deref{typedef typename Iterator::type type;};
template<>struct deref<na>;
template<typename Tag>struct lambda<deref<na>,Tag>;
template<typename Tag>struct at_impl;
template<typename Sequence=na,typename N=na>struct at;
template<typename Sequence,long N>struct at_c:at_impl<typename sequence_tag<Sequence>::type>::template apply<Sequence,mpl::long_<N> >{};
template<>struct at<na,na>;
template<typename Tag>struct lambda<at<na,na>,Tag>;
template<typename Sequence,typename T>struct contains;
template<typename F,typename T1=na,typename T2=na,typename T3=na,typename T4=na,typename T5=na>struct apply;
template<typename F,typename T1,typename T2>struct apply2;
template<int N>struct arg;
namespace aux{template<long C_>struct not_impl:bool_<!C_>{};
}template<typename T=na>struct not_:aux::not_impl<T::type::value>{};
template<>struct not_<na>;
template<typename Tag>struct lambda<not_<na>,Tag>;
struct failed{};
template<bool C>struct assert;
template<>struct assert<false>{typedef assert type;};
template<bool C>int assertion_failed(typename assert<C>::type);
bool operator==(failed,failed);
bool operator!=(failed,failed);
bool operator>(failed,failed);
bool operator>=(failed,failed);
bool operator<(failed,failed);
bool operator<=(failed,failed);
template<bool>struct assert_arg_pred_impl{typedef int type;};
template<>struct assert_arg_pred_impl<true>;
template<typename P>struct assert_arg_pred{typedef typename P::type p_type;typedef typename assert_arg_pred_impl<p_type::value>::type type;};
template<typename P>struct assert_arg_pred_not;
template<typename Pred>failed************(Pred::************assert_arg(void(*)(Pred),typename assert_arg_pred<Pred>::type));
template<typename Pred>failed************(boost::mpl::not_<Pred>::************assert_not_arg(void(*)(Pred),typename assert_arg_pred_not<Pred>::type));
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
template<>struct protect<na>;
namespace aux{template<typename T,typename U1,typename U2,typename U3,typename U4,typename U5>struct resolve_bind_arg{typedef T type;};
template<typename T,typename Arg>struct replace_unnamed_arg{typedef Arg next;typedef T type;};
template<typename Arg>struct replace_unnamed_arg<arg<-1>,Arg>;
template<int N,typename U1,typename U2,typename U3,typename U4,typename U5>struct resolve_bind_arg<arg<N>,U1,U2,U3,U4,U5>{typedef typename apply_wrap5<mpl::arg<N>,U1,U2,U3,U4,U5>::type type;};
template<typename F,typename T1,typename T2,typename T3,typename T4,typename T5,typename U1,typename U2,typename U3,typename U4,typename U5>struct resolve_bind_arg<bind<F,T1,T2,T3,T4,T5>,U1,U2,U3,U4,U5>;
}template<typename F>struct bind0;
namespace aux{template<typename F,typename U1,typename U2,typename U3,typename U4,typename U5>struct resolve_bind_arg<bind0<F>,U1,U2,U3,U4,U5>;
}template<typename F>struct bind<F,na,na,na,na,na>;
template<typename F,typename T1>struct bind1;
namespace aux{template<typename F,typename T1,typename U1,typename U2,typename U3,typename U4,typename U5>struct resolve_bind_arg<bind1<F,T1>,U1,U2,U3,U4,U5>;
}template<typename F,typename T1>struct bind<F,T1,na,na,na,na>;
template<typename F,typename T1,typename T2>struct bind2{template<typename U1=na,typename U2=na,typename U3=na,typename U4=na,typename U5=na>struct apply{private:typedef aux::replace_unnamed_arg<F,mpl::arg<1> >r0;typedef typename r0::type a0;typedef typename r0::next n1;typedef typename aux::resolve_bind_arg<a0,U1,U2,U3,U4,U5>::type f_;typedef aux::replace_unnamed_arg<T1,n1>r1;typedef typename r1::type a1;typedef typename r1::next n2;typedef aux::resolve_bind_arg<a1,U1,U2,U3,U4,U5>t1;typedef aux::replace_unnamed_arg<T2,n2>r2;typedef typename r2::type a2;typedef typename r2::next n3;typedef aux::resolve_bind_arg<a2,U1,U2,U3,U4,U5>t2;public:typedef typename apply_wrap2<f_,typename t1::type,typename t2::type>::type type;};};
namespace aux{template<typename F,typename T1,typename T2,typename U1,typename U2,typename U3,typename U4,typename U5>struct resolve_bind_arg<bind2<F,T1,T2>,U1,U2,U3,U4,U5>;
}template<typename F,typename T1,typename T2>struct bind<F,T1,T2,na,na,na>;
template<typename F,typename T1,typename T2,typename T3>struct bind3;
namespace aux{template<typename F,typename T1,typename T2,typename T3,typename U1,typename U2,typename U3,typename U4,typename U5>struct resolve_bind_arg<bind3<F,T1,T2,T3>,U1,U2,U3,U4,U5>;
}template<typename F,typename T1,typename T2,typename T3>struct bind<F,T1,T2,T3,na,na>;
template<typename F,typename T1,typename T2,typename T3,typename T4>struct bind4;
namespace aux{template<typename F,typename T1,typename T2,typename T3,typename T4,typename U1,typename U2,typename U3,typename U4,typename U5>struct resolve_bind_arg<bind4<F,T1,T2,T3,T4>,U1,U2,U3,U4,U5>;
}template<typename F,typename T1,typename T2,typename T3,typename T4>struct bind<F,T1,T2,T3,T4,na>;
template<typename F,typename T1,typename T2,typename T3,typename T4,typename T5>struct bind5;
namespace aux{template<typename F,typename T1,typename T2,typename T3,typename T4,typename T5,typename U1,typename U2,typename U3,typename U4,typename U5>struct resolve_bind_arg<bind5<F,T1,T2,T3,T4,T5>,U1,U2,U3,U4,U5>;
}template<typename F,typename T1,typename T2,typename T3,typename T4,typename T5>struct bind;
template<template<typename T1,typename T2,typename T3>class F,typename Tag>struct quote3;
template<typename T1,typename T2,typename T3>struct if_;
template<typename Tag,typename T1,typename T2,typename T3>struct bind3<quote3<if_,Tag>,T1,T2,T3>;
template<template<typename T1,typename T2,typename T3>class F,typename Tag>struct quote3;
template<typename T1,typename T2,typename T3>struct eval_if;
template<typename Tag,typename T1,typename T2,typename T3>struct bind3<quote3<eval_if,Tag>,T1,T2,T3>;
namespace aux{template<typename T,typename U=void>struct has_type_impl_{static const bool value=false;typedef boost::mpl::bool_<value>type;};
template<typename T>struct has_type_impl_<T,typename boost::mpl::aux::msvc71_sfinae_helper<typename T::type>::type>;
template<typename T,typename fallback_=boost::mpl::bool_<true> >struct has_type:has_type_impl_<T>{};
}template<template<typename P1>class F,typename Tag=void_>struct quote1;
template<template<typename P1,typename P2,typename P3>class F,typename Tag=void_>struct quote3;
namespace aux{template<bool C1=false,bool C2=false,bool C3=false,bool C4=false,bool C5=false>struct lambda_or:true_{};
template<>struct lambda_or<false,false,false,false,false>;
}template<typename T,typename Tag>struct lambda{typedef false_ is_le;typedef T result_;typedef T type;};
template<typename T>struct is_lambda_expression;
template<int N,typename Tag>struct lambda<arg<N>,Tag>{typedef true_ is_le;typedef mpl::arg<N>result_;typedef mpl::protect<result_>type;};
template<typename F,typename Tag>struct lambda<bind0<F>,Tag>;
namespace aux{template<typename IsLE,typename Tag,template<typename P1>class F,typename L1>struct le_result1;
template<typename Tag,template<typename P1>class F,typename L1>struct le_result1<true_,Tag,F,L1>{typedef bind1<quote1<F,Tag>,typename L1::result_>result_;typedef mpl::protect<result_>type;};
}template<template<typename P1>class F,typename T1,typename Tag>struct lambda<F<T1>,Tag>{typedef lambda<T1,Tag>l1;typedef typename l1::is_le is_le1;typedef typename aux::lambda_or<is_le1::value>::type is_le;typedef aux::le_result1<is_le,Tag,F,l1>le_result_;typedef typename le_result_::result_ result_;typedef typename le_result_::type type;};
template<typename F,typename T1,typename Tag>struct lambda<bind1<F,T1>,Tag>;
template<template<typename P1,typename P2>class F,typename T1,typename T2,typename Tag>struct lambda<F<T1,T2>,Tag>;
template<typename F,typename T1,typename T2,typename Tag>struct lambda<bind2<F,T1,T2>,Tag>{typedef false_ is_le;typedef bind2<F,T1,T2>result_;typedef result_ type;};
template<template<typename P1,typename P2,typename P3>class F,typename T1,typename T2,typename T3,typename Tag>struct lambda<F<T1,T2,T3>,Tag>;
template<typename F,typename T1,typename T2,typename T3,typename Tag>struct lambda<bind3<F,T1,T2,T3>,Tag>;
template<template<typename P1,typename P2,typename P3,typename P4>class F,typename T1,typename T2,typename T3,typename T4,typename Tag>struct lambda<F<T1,T2,T3,T4>,Tag>;
template<typename F,typename T1,typename T2,typename T3,typename T4,typename Tag>struct lambda<bind4<F,T1,T2,T3,T4>,Tag>;
template<template<typename P1,typename P2,typename P3,typename P4,typename P5>class F,typename T1,typename T2,typename T3,typename T4,typename T5,typename Tag>struct lambda<F<T1,T2,T3,T4,T5>,Tag>;
template<typename F,typename T1,typename T2,typename T3,typename T4,typename T5,typename Tag>struct lambda<bind5<F,T1,T2,T3,T4,T5>,Tag>;
template<typename T,typename Tag>struct lambda<mpl::protect<T>,Tag>{typedef false_ is_le;typedef mpl::protect<T>result_;typedef result_ type;};
template<typename F,typename T1,typename T2,typename T3,typename T4,typename T5,typename Tag>struct lambda<bind<F,T1,T2,T3,T4,T5>,Tag>;
template<typename F,typename Tag1,typename Tag2>struct lambda<lambda<F,Tag1>,Tag2>;
template<>struct lambda<na,na>;
template<typename Tag>struct lambda<lambda<na,na>,Tag>;
template<typename F>struct apply<F,na,na,na,na,na>;
template<typename F,typename T1>struct apply<F,T1,na,na,na,na>;
template<typename F,typename T1,typename T2>struct apply2:apply_wrap2<typename lambda<F>::type,T1,T2>{};
template<typename F,typename T1,typename T2>struct apply<F,T1,T2,na,na,na>;
template<typename F,typename T1,typename T2,typename T3>struct apply<F,T1,T2,T3,na,na>;
template<typename F,typename T1,typename T2,typename T3,typename T4>struct apply<F,T1,T2,T3,T4,na>;
template<typename F,typename T1,typename T2,typename T3,typename T4,typename T5>struct apply;
namespace aux{template<bool C_,typename T1,typename T2,typename T3,typename T4>struct or_impl:true_{};
template<typename T1,typename T2,typename T3,typename T4>struct or_impl<false,T1,T2,T3,T4>;
template<>struct or_impl<false,false_,false_,false_,false_>;
}template<typename T1=na,typename T2=na,typename T3=false_,typename T4=false_,typename T5=false_>struct or_:aux::or_impl<T1::type::value,T2,T3,T4,T5>{};
template<>struct or_<na,na>;
template<typename Tag>struct lambda<or_<na,na>,Tag>;
template<typename T1=na,typename T2=na,typename T3=true_,typename T4=true_,typename T5=true_>struct and_;
template<>struct and_<na,na>;
template<typename Tag>struct lambda<and_<na,na>,Tag>;
template<typename T1=na,typename T2=na>struct pair;
template<typename P=na>struct first;
template<typename P=na>struct second;
template<>struct pair<na,na>;
template<typename Tag>struct lambda<pair<na,na>,Tag>;
template<>struct first<na>;
template<typename Tag>struct lambda<first<na>,Tag>;
template<>struct second<na>;
template<typename Tag>struct lambda<second<na>,Tag>;
template<typename T=na>struct identity{typedef T type;};
template<typename T=na>struct make_identity;
template<>struct identity<na>;
template<typename Tag>struct lambda<identity<na>,Tag>;
template<>struct make_identity<na>;
template<typename Tag>struct lambda<make_identity<na>,Tag>;
template<typename Sequence=na,typename State=na,typename ForwardOp=na,typename ForwardPredicate=na,typename BackwardOp=na,typename BackwardPredicate=na>struct iter_fold_if;
template<>struct iter_fold_if<na,na,na,na,na,na>;
template<typename Tag>struct lambda<iter_fold_if<na,na,na,na,na,na>,Tag>;
template<typename Sequence=na,typename Predicate=na>struct find_if;
template<>struct find_if<na,na>;
template<typename Tag>struct lambda<find_if<na,na>,Tag>;
template<typename Sequence=na,typename T=na>struct find;
template<>struct find<na,na>;
template<typename Tag>struct lambda<find<na,na>,Tag>;
template<typename Sequence=na,typename T=na>struct contains;
template<>struct contains<na,na>;
template<typename Tag>struct lambda<contains<na,na>,Tag>;
template<typename Tag>struct size_impl;
template<typename Sequence>struct size;
template<typename First,typename Last>struct distance;
template<typename Tag>struct O1_size_impl;
template<typename Sequence>struct O1_size;
template<typename Tag>struct O1_size_impl;
template<typename Sequence=na>struct O1_size:O1_size_impl<typename sequence_tag<Sequence>::type>::template apply<Sequence>{};
template<>struct O1_size<na>;
template<typename Tag>struct lambda<O1_size<na>,Tag>;
template<typename Sequence=na,typename State=na,typename ForwardOp=na>struct iter_fold;
template<>struct iter_fold<na,na,na>;
template<typename Tag>struct lambda<iter_fold<na,na,na>,Tag>;
template<typename First=na,typename Last=na>struct iterator_range;
template<>struct iterator_range<na,na>;
template<typename Tag>struct lambda<iterator_range<na,na>,Tag>;
template<typename First=na,typename Last=na>struct distance;
template<>struct distance<na,na>;
template<typename Tag>struct lambda<distance<na,na>,Tag>;
template<typename Tag>struct size_impl;
template<typename Sequence=na>struct size:aux::msvc_eti_base<typename size_impl<typename sequence_tag<Sequence>::type>::template apply<Sequence>::type>::type{};
template<>struct size<na>;
template<typename Tag>struct lambda<size<na>,Tag>;
}namespace detail{template<typename T>struct cv_traits_imp;
template<typename T>struct cv_traits_imp<T*>{static const bool is_const=false;static const bool is_volatile=false;typedef T unqualified_type;};
template<typename T>struct cv_traits_imp<const T*>;
template<typename T>struct cv_traits_imp<volatile T*>;
template<typename T>struct cv_traits_imp<const volatile T*>;
}template<typename T>struct is_const: ::boost::integral_constant<bool,::boost::detail::cv_traits_imp<T*>::is_const>{};
template<typename T>struct is_const<T&>;
template<typename T>struct is_volatile;
template<typename T>struct is_volatile<T&>;
template<class Cond,class T=void>struct disable_if;
namespace type_traits{typedef char yes_type;
struct no_type{char padding[8];};
}template<typename T>struct is_array: ::boost::integral_constant<bool,false>{};
template<typename T,std::size_t N>struct is_array<T[N]>;
template<typename T,std::size_t N>struct is_array<T const[N]>;
template<typename T,std::size_t N>struct is_array<T volatile[N]>;
template<typename T,std::size_t N>struct is_array<T const volatile[N]>;
template<typename T>struct is_array<T[]>;
template<typename T>struct is_array<T const[]>;
template<typename T>struct is_array<T volatile[]>;
template<typename T>struct is_array<T const volatile[]>;
template<typename T>struct is_reference: ::boost::integral_constant<bool,false>{};
template<typename T>struct is_reference<T&>;
namespace type_traits{template<bool b1,bool b2,bool b3=false,bool b4=false,bool b5=false,bool b6=false,bool b7=false>struct ice_or;
template<bool b1,bool b2,bool b3,bool b4,bool b5,bool b6,bool b7>struct ice_or{static const bool value=true;};
template<>struct ice_or<false,false,false,false,false,false,false>{static const bool value=false;};
template<bool b1,bool b2,bool b3=true,bool b4=true,bool b5=true,bool b6=true,bool b7=true>struct ice_and;
template<bool b1,bool b2,bool b3,bool b4,bool b5,bool b6,bool b7>struct ice_and{static const bool value=false;};
template<>struct ice_and<true,true,true,true,true,true,true>{static const bool value=true;};
template<bool b>struct ice_not{static const bool value=true;};
template<>struct ice_not<true>;
template<int b1,int b2>struct ice_eq{static const bool value=(b1==b2);};
template<int b1,int b2>struct ice_ne{static const bool value=(b1!=b2);};
template<int b1,int b2>bool const ice_eq<b1,b2>::value;
template<int b1,int b2>bool const ice_ne<b1,b2>::value;
}template<typename T>struct is_integral: ::boost::integral_constant<bool,false>{};
template<>struct is_integral<unsigned char>;
template<>struct is_integral<unsigned char const>;
template<>struct is_integral<unsigned char volatile>;
template<>struct is_integral<unsigned char const volatile>;
template<>struct is_integral<unsigned short>;
template<>struct is_integral<unsigned short const>;
template<>struct is_integral<unsigned short volatile>;
template<>struct is_integral<unsigned short const volatile>;
template<>struct is_integral<unsigned int>;
template<>struct is_integral<unsigned int const>;
template<>struct is_integral<unsigned int volatile>;
template<>struct is_integral<unsigned int const volatile>;
template<>struct is_integral<unsigned long>;
template<>struct is_integral<unsigned long const>;
template<>struct is_integral<unsigned long volatile>;
template<>struct is_integral<unsigned long const volatile>;
template<>struct is_integral<signed char>;
template<>struct is_integral<signed char const>;
template<>struct is_integral<signed char volatile>;
template<>struct is_integral<signed char const volatile>;
template<>struct is_integral<signed short>;
template<>struct is_integral<signed short const>;
template<>struct is_integral<signed short volatile>;
template<>struct is_integral<signed short const volatile>;
template<>struct is_integral<signed int>: ::boost::integral_constant<bool,true>{};
template<>struct is_integral<signed int const>;
template<>struct is_integral<signed int volatile>;
template<>struct is_integral<signed int const volatile>;
template<>struct is_integral<signed long>;
template<>struct is_integral<signed long const>;
template<>struct is_integral<signed long volatile>;
template<>struct is_integral<signed long const volatile>;
template<>struct is_integral<bool>;
template<>struct is_integral<bool const>;
template<>struct is_integral<bool volatile>;
template<>struct is_integral<bool const volatile>;
template<>struct is_integral<char>;
template<>struct is_integral<char const>;
template<>struct is_integral<char volatile>;
template<>struct is_integral<char const volatile>;
template<>struct is_integral<wchar_t>;
template<>struct is_integral<wchar_t const>;
template<>struct is_integral<wchar_t volatile>;
template<>struct is_integral<wchar_t const volatile>;
template<>struct is_integral< ::boost::ulong_long_type>;
template<>struct is_integral< ::boost::ulong_long_type const>;
template<>struct is_integral< ::boost::ulong_long_type volatile>;
template<>struct is_integral< ::boost::ulong_long_type const volatile>;
template<>struct is_integral< ::boost::long_long_type>;
template<>struct is_integral< ::boost::long_long_type const>;
template<>struct is_integral< ::boost::long_long_type volatile>;
template<>struct is_integral< ::boost::long_long_type const volatile>;
template<typename T>struct is_float: ::boost::integral_constant<bool,false>{};
template<>struct is_float<float>;
template<>struct is_float<float const>;
template<>struct is_float<float volatile>;
template<>struct is_float<float const volatile>;
template<>struct is_float<double>: ::boost::integral_constant<bool,true>{};
template<>struct is_float<double const>;
template<>struct is_float<double volatile>;
template<>struct is_float<double const volatile>;
template<>struct is_float<long double>;
template<>struct is_float<long double const>;
template<>struct is_float<long double volatile>;
template<>struct is_float<long double const volatile>;
namespace detail{template<typename T>struct is_arithmetic_impl{static const bool value=(::boost::type_traits::ice_or< ::boost::is_integral<T>::value,::boost::is_float<T>::value>::value);};
}template<typename T>struct is_arithmetic: ::boost::integral_constant<bool,::boost::detail::is_arithmetic_impl<T>::value>{};
template<bool x>struct STATIC_ASSERTION_FAILURE;
template<>struct STATIC_ASSERTION_FAILURE<true>{enum{value=1};};
template<int x>struct static_assert_test;
template<typename T>struct remove_cv{typedef typename boost::detail::cv_traits_imp<T*>::unqualified_type type;};
template<typename T>struct remove_cv<T&>;
template<typename T,std::size_t N>struct remove_cv<T const[N]>;
template<typename T,std::size_t N>struct remove_cv<T volatile[N]>;
template<typename T,std::size_t N>struct remove_cv<T const volatile[N]>;
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
struct random_access_iterator_tag:int_<2>{typedef random_access_iterator_tag type;};
template<typename N1=na,typename N2=na,typename N3=na,typename N4=na,typename N5=na>struct plus;
template<typename N1,typename N2,typename N3,typename N4>struct plus<N1,N2,N3,N4,na>;
template<typename N1,typename N2,typename N3>struct plus<N1,N2,N3,na,na>;
template<typename N1,typename N2>struct plus<N1,N2,na,na,na>;
template<>struct plus<na,na>;
template<typename Tag>struct lambda<plus<na,na>,Tag>;
template<typename N1=na,typename N2=na,typename N3=na,typename N4=na,typename N5=na>struct minus;
template<typename N1,typename N2,typename N3,typename N4>struct minus<N1,N2,N3,N4,na>;
template<typename N1,typename N2,typename N3>struct minus<N1,N2,N3,na,na>;
template<typename N1,typename N2>struct minus<N1,N2,na,na,na>;
template<>struct minus<na,na>;
template<typename Tag>struct lambda<minus<na,na>,Tag>;
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
template<>struct empty_impl<aux::vector_tag<0> >;
template<long N>struct empty_impl<aux::vector_tag<N> >{template<typename Vector>struct apply:false_{};};
template<typename V>struct v_at<V,0>{typedef typename V::item0 type;};
template<typename T0>struct vector1{typedef aux::vector_tag<1>tag;typedef vector1 type;typedef T0 item0;typedef void_ item1;typedef T0 back;typedef v_iter<type,0>begin;typedef v_iter<type,1>end;};
template<>struct push_front_impl<aux::vector_tag<0> >{template<typename Vector,typename T>struct apply{typedef vector1<T>type;};};
template<typename V>struct v_at<V,1>{typedef typename V::item1 type;};
template<typename T0,typename T1>struct vector2{typedef aux::vector_tag<2>tag;typedef vector2 type;typedef T0 item0;typedef T1 item1;typedef void_ item2;typedef T1 back;typedef v_iter<type,0>begin;typedef v_iter<type,2>end;};
template<>struct push_front_impl<aux::vector_tag<1> >{template<typename Vector,typename T>struct apply{typedef vector2<T,typename Vector::item0>type;};};
template<typename V>struct v_at<V,2>{typedef typename V::item2 type;};
template<typename T0,typename T1,typename T2>struct vector3{typedef aux::vector_tag<3>tag;typedef vector3 type;typedef T0 item0;typedef T1 item1;typedef T2 item2;typedef void_ item3;typedef T2 back;typedef v_iter<type,0>begin;typedef v_iter<type,3>end;};
template<>struct push_front_impl<aux::vector_tag<2> >{template<typename Vector,typename T>struct apply{typedef vector3<T,typename Vector::item0,typename Vector::item1>type;};};
template<typename V>struct v_at<V,3>;
template<>struct push_front_impl<aux::vector_tag<3> >;
template<typename V>struct v_at<V,4>;
template<>struct push_front_impl<aux::vector_tag<4> >;
template<typename V>struct v_at<V,5>;
template<>struct push_front_impl<aux::vector_tag<5> >;
template<typename V>struct v_at<V,6>;
template<>struct push_front_impl<aux::vector_tag<6> >;
template<typename V>struct v_at<V,7>;
template<>struct push_front_impl<aux::vector_tag<7> >;
template<typename V>struct v_at<V,8>;
template<>struct push_front_impl<aux::vector_tag<8> >;
template<typename V>struct v_at<V,9>;
template<>struct push_front_impl<aux::vector_tag<9> >;
template<typename V>struct v_at<V,10>;
template<>struct push_front_impl<aux::vector_tag<10> >;
template<typename V>struct v_at<V,11>;
template<>struct push_front_impl<aux::vector_tag<11> >;
template<typename V>struct v_at<V,12>;
template<>struct push_front_impl<aux::vector_tag<12> >;
template<typename V>struct v_at<V,13>;
template<>struct push_front_impl<aux::vector_tag<13> >;
template<typename V>struct v_at<V,14>;
template<>struct push_front_impl<aux::vector_tag<14> >;
template<typename V>struct v_at<V,15>;
template<>struct push_front_impl<aux::vector_tag<15> >;
template<typename V>struct v_at<V,16>;
template<>struct push_front_impl<aux::vector_tag<16> >;
template<typename V>struct v_at<V,17>;
template<>struct push_front_impl<aux::vector_tag<17> >;
template<typename V>struct v_at<V,18>;
template<>struct push_front_impl<aux::vector_tag<18> >;
template<typename V>struct v_at<V,19>;
template<>struct push_front_impl<aux::vector_tag<19> >;
template<typename V>struct v_at<V,20>;
template<typename T0=na,typename T1=na,typename T2=na,typename T3=na,typename T4=na,typename T5=na,typename T6=na,typename T7=na,typename T8=na,typename T9=na,typename T10=na,typename T11=na,typename T12=na,typename T13=na,typename T14=na,typename T15=na,typename T16=na,typename T17=na,typename T18=na,typename T19=na>struct vector;
template<>struct vector<na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na>:vector0<>{typedef vector0<>::type type;};
template<typename T0>struct vector<T0,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na>;
template<typename T0,typename T1>struct vector<T0,T1,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na>;
template<typename T0,typename T1,typename T2>struct vector<T0,T1,T2,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na>:vector3<T0,T1,T2>{typedef typename vector3<T0,T1,T2>::type type;};
template<typename T0,typename T1,typename T2,typename T3>struct vector<T0,T1,T2,T3,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na>;
template<typename T0,typename T1,typename T2,typename T3,typename T4>struct vector<T0,T1,T2,T3,T4,na,na,na,na,na,na,na,na,na,na,na,na,na,na,na>;
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5>struct vector<T0,T1,T2,T3,T4,T5,na,na,na,na,na,na,na,na,na,na,na,na,na,na>;
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6>struct vector<T0,T1,T2,T3,T4,T5,T6,na,na,na,na,na,na,na,na,na,na,na,na,na>;
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7>struct vector<T0,T1,T2,T3,T4,T5,T6,T7,na,na,na,na,na,na,na,na,na,na,na,na>;
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8>struct vector<T0,T1,T2,T3,T4,T5,T6,T7,T8,na,na,na,na,na,na,na,na,na,na,na>;
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9>struct vector<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,na,na,na,na,na,na,na,na,na,na>;
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10>struct vector<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,na,na,na,na,na,na,na,na,na>;
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11>struct vector<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,na,na,na,na,na,na,na,na>;
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12>struct vector<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,na,na,na,na,na,na,na>;
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13>struct vector<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,na,na,na,na,na,na>;
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14>struct vector<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,na,na,na,na,na>;
template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15>struct vector<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,na,na,na,na>;



template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9,typename T10,typename T11,typename T12,typename T13,typename T14,typename T15,typename T16,typename T17,typename T18,typename T19>struct vector;
}namespace multi_index{template<typename T0,typename T1=mpl::na,typename T2=mpl::na,typename T3=mpl::na,typename T4=mpl::na,typename T5=mpl::na,typename T6=mpl::na,typename T7=mpl::na,typename T8=mpl::na,typename T9=mpl::na,typename T10=mpl::na,typename T11=mpl::na,typename T12=mpl::na,typename T13=mpl::na,typename T14=mpl::na,typename T15=mpl::na,typename T16=mpl::na,typename T17=mpl::na,typename T18=mpl::na,typename T19=mpl::na>struct indexed_by:mpl::vector<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19>{};
}namespace mpl{namespace aux{template<int N,typename First,typename Last,typename State,typename ForwardOp>struct fold_impl;
template<typename First,typename Last,typename State,typename ForwardOp>struct fold_impl<0,First,Last,State,ForwardOp>{typedef First iter0;typedef State state0;typedef state0 state;typedef iter0 iterator;};
template<typename First,typename Last,typename State,typename ForwardOp>struct fold_impl<1,First,Last,State,ForwardOp>;
template<typename First,typename Last,typename State,typename ForwardOp>struct fold_impl<2,First,Last,State,ForwardOp>;
template<typename First,typename Last,typename State,typename ForwardOp>struct fold_impl<3,First,Last,State,ForwardOp>{typedef First iter0;typedef State state0;typedef typename apply2<ForwardOp,state0,typename deref<iter0>::type>::type state1;typedef typename mpl::next<iter0>::type iter1;typedef typename apply2<ForwardOp,state1,typename deref<iter1>::type>::type state2;typedef typename mpl::next<iter1>::type iter2;typedef typename apply2<ForwardOp,state2,typename deref<iter2>::type>::type state3;typedef typename mpl::next<iter2>::type iter3;typedef state3 state;typedef iter3 iterator;};
template<typename First,typename Last,typename State,typename ForwardOp>struct fold_impl<4,First,Last,State,ForwardOp>;
template<int N,typename First,typename Last,typename State,typename ForwardOp>struct fold_impl;
template<typename First,typename Last,typename State,typename ForwardOp>struct fold_impl<-1,First,Last,State,ForwardOp>;
template<typename Last,typename State,typename ForwardOp>struct fold_impl<-1,Last,Last,State,ForwardOp>;
}template<typename Sequence=na,typename State=na,typename ForwardOp=na>struct fold{typedef typename aux::fold_impl< ::boost::mpl::O1_size<Sequence>::value,typename begin<Sequence>::type,typename end<Sequence>::type,State,ForwardOp>::state type;};
template<>struct fold<na,na,na>;
template<typename Tag>struct lambda<fold<na,na,na>,Tag>;
namespace aux{struct set_tag;
}template<typename Tag>struct has_key_impl;
template<typename AssociativeSequence,typename Key>struct has_key;
template<>struct has_key_impl<aux::set_tag>{template<typename Set,typename T>struct apply{static const bool value=(sizeof(Set::is_masked_(*static_cast<Set*>(0),static_cast<aux::type_wrapper<T>*>(0)))==sizeof(aux::no_tag));typedef bool_<value>type;};};
template<>struct at_impl<aux::set_tag>;
template<typename Dummy=na>struct set0{typedef set0<>item_;typedef aux::set_tag tag;typedef void_ last_masked_;typedef void_ item_type_;typedef item_type_ type;typedef long_<0>size;typedef long_<1>order;static aux::no_tag order_by_key_(set0<>const&,void const volatile*);static aux::yes_tag is_masked_(set0<>const&,void const volatile*);};
template<>struct clear_impl<aux::set_tag>;
template<>struct size_impl<aux::set_tag>;
template<>struct empty_impl<aux::set_tag>;
template<typename T,typename Base>struct s_item;
template<typename T=na>struct base;
template<>struct base<na>;
template<typename Tag>struct lambda<base<na>,Tag>;
template<typename AssociativeSequence,typename T>struct value_type;
template<typename Tag>struct has_key_impl;
template<typename AssociativeSequence=na,typename Key=na>struct has_key:has_key_impl<typename sequence_tag<AssociativeSequence>::type>::template apply<AssociativeSequence,Key>{};
template<>struct has_key<na,na>;
template<typename Tag>struct lambda<has_key<na,na>,Tag>;
template<typename Set,typename Tail>struct s_iter;
template<typename Set,typename Tail>struct next<s_iter<Set,Tail> >;
template<typename Set>struct next<s_iter<Set,set0<> > >;
template<typename Set,typename Tail>struct s_iter;
template<typename Set>struct s_iter<Set,set0<> >;
template<>struct begin_impl<aux::set_tag>;
template<>struct end_impl<aux::set_tag>;
}namespace multi_index{namespace detail{struct duplicate_tag_mark{};
struct duplicate_tag_marker{template<typename MplSet,typename Tag>struct apply{typedef mpl::s_item<typename mpl::if_<mpl::has_key<MplSet,Tag>,duplicate_tag_mark,Tag>::type,MplSet>type;};};
template<typename TagList>struct no_duplicate_tags{typedef typename mpl::fold<TagList,mpl::set0<>,duplicate_tag_marker>::type aux;static const bool value=!(mpl::has_key<aux,duplicate_tag_mark>::value);};
struct duplicate_tag_list_marker{template<typename MplSet,typename Index>struct apply:mpl::fold<typename Index::tag_list,MplSet,duplicate_tag_marker>{};};
template<typename IndexList>struct no_duplicate_tags_in_index_list{typedef typename mpl::fold<IndexList,mpl::set0<>,duplicate_tag_list_marker>::type aux;static const bool value=!(mpl::has_key<aux,duplicate_tag_mark>::value);};
}}namespace mpl{namespace aux{template<long N,typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_fold_impl;
template<typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_fold_impl<0,First,Last,State,BackwardOp,ForwardOp>{typedef First iter0;typedef State fwd_state0;typedef fwd_state0 bkwd_state0;typedef bkwd_state0 state;typedef iter0 iterator;};
template<typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_fold_impl<1,First,Last,State,BackwardOp,ForwardOp>;
template<typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_fold_impl<2,First,Last,State,BackwardOp,ForwardOp>;
template<typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_fold_impl<3,First,Last,State,BackwardOp,ForwardOp>;
template<typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_fold_impl<4,First,Last,State,BackwardOp,ForwardOp>;
template<long N,typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_fold_impl;
template<typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_fold_impl<-1,First,Last,State,BackwardOp,ForwardOp>;
template<typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_fold_impl<-1,Last,Last,State,BackwardOp,ForwardOp>;
}template<typename Sequence=na,typename State=na,typename BackwardOp=na,typename ForwardOp=arg<1> >struct reverse_fold{typedef typename aux::reverse_fold_impl< ::boost::mpl::O1_size<Sequence>::value,typename begin<Sequence>::type,typename end<Sequence>::type,State,BackwardOp,ForwardOp>::state type;};
template<>struct reverse_fold<na,na,na>;
template<typename Tag>struct lambda<reverse_fold<na,na,na>,Tag>;
template<typename Iterator=na>struct iterator_category;
template<>struct iterator_category<na>;
template<typename Tag>struct lambda<iterator_category<na>,Tag>;
template<typename N1=na,typename N2=na>struct min;
template<typename N1=na,typename N2=na>struct max;
template<>struct min<na,na>;
template<typename Tag>struct lambda<min<na,na>,Tag>;
template<>struct max<na,na>;
template<typename Tag>struct lambda<max<na,na>,Tag>;
template<typename Iter1,typename Iter2,typename Category>struct pair_iter;
template<typename Iter1,typename Iter2,typename C>struct deref<pair_iter<Iter1,Iter2,C> >;
template<typename Iter1,typename Iter2,typename C>struct next<pair_iter<Iter1,Iter2,C> >;
template<typename Iter1,typename Iter2,typename C>struct prior<pair_iter<Iter1,Iter2,C> >;
template<typename Sequence1=na,typename Sequence2=na>struct pair_view;
template<>struct pair_view<na,na>;
template<typename Tag>struct lambda<pair_view<na,na>,Tag>;
template<typename T=na>struct is_sequence:not_<is_same<typename begin<T>::type,void_> >{};
template<>struct is_sequence<na>;
template<typename Tag>struct lambda<is_sequence<na>,Tag>;
template<typename Tag>struct has_push_back_impl{template<typename Seq>struct apply:aux::has_type<push_back<Seq,int> >{};};
template<typename Sequence=na,typename T=na>struct push_back;
template<typename Sequence=na>struct has_push_back:has_push_back_impl<typename sequence_tag<Sequence>::type>::template apply<Sequence>{};
template<>struct push_back<na,na>;
template<typename Tag>struct lambda<push_back<na,na>,Tag>;
template<>struct has_push_back<na>;
template<typename Tag>struct lambda<has_push_back<na>,Tag>;
template<typename Sequence,typename Operation>struct inserter{typedef Sequence state;typedef Operation operation;};
template<typename Sequence>struct back_inserter;
template<typename Tag>struct push_front_impl;
template<typename Sequence=na,typename T=na>struct push_front:push_front_impl<typename sequence_tag<Sequence>::type>::template apply<Sequence,T>{};
template<typename Sequence=na>struct has_push_front;
template<>struct push_front<na,na>;
template<typename Tag>struct lambda<push_front<na,na>,Tag>{typedef false_ is_le;typedef push_front<na,na>result_;typedef push_front<na,na>type;};
template<>struct has_push_front<na>;
template<typename Tag>struct lambda<has_push_front<na>,Tag>;
template<typename Sequence>struct front_inserter:inserter<Sequence,push_front<> >{};
template<typename Tag>struct clear_impl;
template<typename Sequence=na>struct clear:clear_impl<typename sequence_tag<Sequence>::type>::template apply<Sequence>{};
template<>struct clear<na>;
template<typename Tag>struct lambda<clear<na>,Tag>;
namespace aux{template<typename Seq,typename Op,typename In>struct transform1_impl;
template<typename Seq,typename Op,typename In>struct reverse_transform1_impl:reverse_fold<Seq,typename In::state,bind2<typename lambda<typename In::operation>::type,_1,bind1<typename lambda<Op>::type,_2> > >{};
}template<typename P1=na,typename P2=na,typename P3=na>struct transform1;
template<typename P1,typename P2>struct transform1<P1,P2,na>:if_<has_push_back<P1>,aux::transform1_impl<P1,P2,back_inserter<typename clear<P1>::type> >,aux::reverse_transform1_impl<P1,P2,front_inserter<typename clear<P1>::type> > >::type{};
template<typename P1=na,typename P2=na,typename P3=na>struct reverse_transform1;
template<typename P1,typename P2>struct reverse_transform1<P1,P2,na>;
template<>struct transform1<na,na,na>;
template<typename Tag>struct lambda<transform1<na,na,na>,Tag>;
template<>struct reverse_transform1<na,na,na>;
template<typename Tag>struct lambda<reverse_transform1<na,na,na>,Tag>;
template<typename P1=na,typename P2=na,typename P3=na,typename P4=na>struct transform2;
template<typename P1,typename P2,typename P3>struct transform2<P1,P2,P3,na>;
template<typename P1=na,typename P2=na,typename P3=na,typename P4=na>struct reverse_transform2;
template<typename P1,typename P2,typename P3>struct reverse_transform2<P1,P2,P3,na>;
template<>struct transform2<na,na,na,na>;
template<typename Tag>struct lambda<transform2<na,na,na,na>,Tag>;
template<>struct reverse_transform2<na,na,na,na>;
template<typename Tag>struct lambda<reverse_transform2<na,na,na,na>,Tag>;
template<typename Seq1=na,typename Seq2OrOperation=na,typename OperationOrInserter=na,typename Inserter=na>struct transform{typedef typename eval_if<or_<is_na<OperationOrInserter>,is_lambda_expression<Seq2OrOperation>,not_<is_sequence<Seq2OrOperation> > >,transform1<Seq1,Seq2OrOperation,OperationOrInserter>,transform2<Seq1,Seq2OrOperation,OperationOrInserter,Inserter> >::type type;};
template<>struct transform<na,na,na,na>;
template<typename Tag>struct lambda<transform<na,na,na,na>,Tag>;
template<typename Seq1=na,typename Seq2OrOperation=na,typename OperationOrInserter=na,typename Inserter=na>struct reverse_transform;
template<>struct reverse_transform<na,na,na,na>;
template<typename Tag>struct lambda<reverse_transform<na,na,na,na>,Tag>;
}namespace detail{template<typename B,typename D>struct bd_helper{template<typename T>static type_traits::yes_type check_sig(D const volatile*,T);static type_traits::no_type check_sig(B const volatile*,int);};
template<typename B,typename D>struct is_base_and_derived_impl2{struct Host{operator B const volatile*()const;operator D const volatile*();};static const bool value=sizeof(bd_helper<B,D>::check_sig(Host(),0))==sizeof(type_traits::yes_type);};
template<bool ic1,bool ic2,bool iss>struct is_base_and_derived_select;
template<>struct is_base_and_derived_select<true,true,false>{template<class T,class U>struct rebind{typedef is_base_and_derived_impl2<T,U>type;};};
template<typename B,typename D>struct is_base_and_derived_impl{typedef typename remove_cv<B>::type ncvB;typedef typename remove_cv<D>::type ncvD;typedef is_base_and_derived_select< ::boost::is_class<B>::value,::boost::is_class<D>::value,::boost::is_same<B,D>::value>selector;typedef typename selector::template rebind<ncvB,ncvD>binder;typedef typename binder::type bound_type;static const bool value=bound_type::value;};
}template<typename Base,typename Derived>struct is_base_and_derived: ::boost::integral_constant<bool,(::boost::detail::is_base_and_derived_impl<Base,Derived>::value)>{};
template<typename Base,typename Derived>struct is_base_and_derived<Base&,Derived>;
template<typename Base,typename Derived>struct is_base_and_derived<Base,Derived&>;
template<typename Base,typename Derived>struct is_base_and_derived<Base&,Derived&>;
namespace multi_index{namespace detail{struct tag_marker{};
template<typename T>struct is_tag{static const bool value=(is_base_and_derived<tag_marker,T>::value);};
}template<typename T0=mpl::na,typename T1=mpl::na,typename T2=mpl::na,typename T3=mpl::na,typename T4=mpl::na,typename T5=mpl::na,typename T6=mpl::na,typename T7=mpl::na,typename T8=mpl::na,typename T9=mpl::na,typename T10=mpl::na,typename T11=mpl::na,typename T12=mpl::na,typename T13=mpl::na,typename T14=mpl::na,typename T15=mpl::na,typename T16=mpl::na,typename T17=mpl::na,typename T18=mpl::na,typename T19=mpl::na>struct tag:private detail::tag_marker{typedef typename mpl::transform<mpl::vector<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19>,mpl::identity<mpl::_1> >::type type;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(detail::no_duplicate_tags<type>::value)>)>boost_static_assert_typedef_1;};
namespace detail{template<typename KeyFromValue>struct index_args_default_compare{typedef std::less<typename KeyFromValue::result_type>type;};
template<typename Arg1,typename Arg2,typename Arg3>struct ordered_index_args{typedef is_tag<Arg1>full_form;typedef typename mpl::if_<full_form,Arg1,tag<> >::type tag_list_type;typedef typename mpl::if_<full_form,Arg2,Arg1>::type key_from_value_type;typedef typename mpl::if_<full_form,Arg3,Arg2>::type supplied_compare_type;typedef typename mpl::eval_if<mpl::is_na<supplied_compare_type>,index_args_default_compare<key_from_value_type>,mpl::identity<supplied_compare_type> >::type compare_type;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(is_tag<tag_list_type>::value)>)>boost_static_assert_typedef_2;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(!mpl::is_na<key_from_value_type>::value)>)>boost_static_assert_typedef_3;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(!mpl::is_na<compare_type>::value)>)>boost_static_assert_typedef_4;};
template<typename KeyFromValue,typename Compare,typename SuperMeta,typename TagList,typename Category>class ordered_index;






template<typename KeyFromValue,typename Compare,typename SuperMeta,typename TagList,typename Category>void swap(ordered_index<KeyFromValue,Compare,SuperMeta,TagList,Category>&x,ordered_index<KeyFromValue,Compare,SuperMeta,TagList,Category>&y);
}template<typename Arg1,typename Arg2=mpl::na,typename Arg3=mpl::na>struct ordered_unique;
template<typename Arg1,typename Arg2=mpl::na,typename Arg3=mpl::na>struct ordered_non_unique;
template<typename Value,typename IndexSpecifierList=indexed_by<ordered_unique<identity<Value> > >,typename Allocator=std::allocator<Value> >class multi_index_container;
template<typename MultiIndexContainer,int N>struct nth_index;
template<typename MultiIndexContainer,typename Tag>struct index;
template<typename MultiIndexContainer,int N>struct nth_index_iterator;
template<typename MultiIndexContainer,int N>struct nth_index_const_iterator;
template<typename MultiIndexContainer,typename Tag>struct index_iterator;
template<typename MultiIndexContainer,typename Tag>struct index_const_iterator;

template<typename Value1,typename IndexSpecifierList1,typename Allocator1,typename Value2,typename IndexSpecifierList2,typename Allocator2>bool operator<(const multi_index_container<Value1,IndexSpecifierList1,Allocator1>&x,const multi_index_container<Value2,IndexSpecifierList2,Allocator2>&y);

template<typename Value1,typename IndexSpecifierList1,typename Allocator1,typename Value2,typename IndexSpecifierList2,typename Allocator2>bool operator>(const multi_index_container<Value1,IndexSpecifierList1,Allocator1>&x,const multi_index_container<Value2,IndexSpecifierList2,Allocator2>&y);


}using multi_index::multi_index_container;
namespace type_traits{no_type __cdecl is_mem_fun_pointer_tester(...);
}namespace detail{template<bool>struct is_mem_fun_pointer_select;
template<>struct is_mem_fun_pointer_select<false>{template<typename T>struct result_{static T*make_t;typedef result_<T>self_type;static const bool value=(1==sizeof(::boost::type_traits::is_mem_fun_pointer_tester(self_type::make_t)));};};
template<typename T>struct is_member_function_pointer_impl:is_mem_fun_pointer_select< ::boost::type_traits::ice_or< ::boost::is_reference<T>::value,::boost::is_array<T>::value>::value>::template result_<T>{};
template<typename T>struct is_member_function_pointer_impl<T&>;
template<>struct is_member_function_pointer_impl<void>;
template<>struct is_member_function_pointer_impl<void const>;
template<>struct is_member_function_pointer_impl<void volatile>;
template<>struct is_member_function_pointer_impl<void const volatile>;
}template<typename T>struct is_member_function_pointer: ::boost::integral_constant<bool,::boost::detail::is_member_function_pointer_impl<T>::value>{};
template<typename T>struct is_member_pointer: ::boost::integral_constant<bool,::boost::is_member_function_pointer<T>::value>{};
template<typename T,typename U>struct is_member_pointer<U T::*>;
namespace detail{template<typename T>struct is_pointer_helper{static const bool value=false;};
template<typename T>struct is_pointer_helper<T*>{static const bool value=true;};
template<typename T>struct is_pointer_helper<T*const>;
template<typename T>struct is_pointer_helper<T*volatile>;
template<typename T>struct is_pointer_helper<T*const volatile>;
template<typename T>struct is_pointer_impl{static const bool value=(::boost::type_traits::ice_and< ::boost::detail::is_pointer_helper<T>::value,::boost::type_traits::ice_not< ::boost::is_member_pointer<T>::value>::value>::value);};
}template<typename T>struct is_pointer: ::boost::integral_constant<bool,::boost::detail::is_pointer_impl<T>::value>{};
namespace detail{template<typename T,bool small_>struct ct_imp2{typedef const T&param_type;};
template<typename T>struct ct_imp2<T,true>{typedef const T param_type;};
template<typename T,bool isp,bool b1>struct ct_imp{typedef const T&param_type;};
template<typename T,bool isp>struct ct_imp<T,isp,true>{typedef typename ct_imp2<T,sizeof(T)<=sizeof(void*)>::param_type param_type;};
template<typename T,bool b1>struct ct_imp<T,true,b1>{typedef const T param_type;};
}template<typename T>struct call_traits{public:typedef T value_type;typedef T&reference;typedef const T&const_reference;typedef typename boost::detail::ct_imp<T,::boost::is_pointer<T>::value,::boost::is_arithmetic<T>::value>::param_type param_type;};
template<typename T>struct call_traits<T&>;
template<typename T,std::size_t N>struct call_traits<T[N]>;
template<typename T,std::size_t N>struct call_traits<const T[N]>;
namespace noncopyable_{class noncopyable{protected:noncopyable(){}~noncopyable(){}private:noncopyable(const noncopyable&);const noncopyable&operator=(const noncopyable&);};
}typedef noncopyable_::noncopyable noncopyable;
namespace multi_index{namespace detail{template<typename T,typename Allocator=std::allocator<T> >struct auto_space:private noncopyable{explicit auto_space(const Allocator&al=Allocator(),std::size_t n=1):al_(al),n_(n),data_(n_?al_.allocate(n_):0){}~auto_space(){if(n_)al_.deallocate(data_,n_);}Allocator get_allocator()const{return al_;}T*data()const{return data_;}void swap(auto_space&x){std::swap(n_,x.n_);std::swap(data_,x.data_);}private:typename boost::detail::allocator::rebind_to<Allocator,T>::type al_;std::size_t n_;T*data_;};
template<typename T,typename Allocator>void swap(auto_space<T,Allocator>&x,auto_space<T,Allocator>&y){x.swap(y);}
template<typename Node,typename Allocator>class copy_map;
}}namespace mpl{namespace aux{template<long N,typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_iter_fold_impl;
template<typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_iter_fold_impl<0,First,Last,State,BackwardOp,ForwardOp>;
template<typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_iter_fold_impl<1,First,Last,State,BackwardOp,ForwardOp>;
template<typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_iter_fold_impl<2,First,Last,State,BackwardOp,ForwardOp>;
template<typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_iter_fold_impl<3,First,Last,State,BackwardOp,ForwardOp>{typedef First iter0;typedef State fwd_state0;typedef typename apply2<ForwardOp,fwd_state0,iter0>::type fwd_state1;typedef typename mpl::next<iter0>::type iter1;typedef typename apply2<ForwardOp,fwd_state1,iter1>::type fwd_state2;typedef typename mpl::next<iter1>::type iter2;typedef typename apply2<ForwardOp,fwd_state2,iter2>::type fwd_state3;typedef typename mpl::next<iter2>::type iter3;typedef fwd_state3 bkwd_state3;typedef typename apply2<BackwardOp,bkwd_state3,iter2>::type bkwd_state2;typedef typename apply2<BackwardOp,bkwd_state2,iter1>::type bkwd_state1;typedef typename apply2<BackwardOp,bkwd_state1,iter0>::type bkwd_state0;typedef bkwd_state0 state;typedef iter3 iterator;};
template<typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_iter_fold_impl<4,First,Last,State,BackwardOp,ForwardOp>;
template<long N,typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_iter_fold_impl;
template<typename First,typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_iter_fold_impl<-1,First,Last,State,BackwardOp,ForwardOp>;
template<typename Last,typename State,typename BackwardOp,typename ForwardOp>struct reverse_iter_fold_impl<-1,Last,Last,State,BackwardOp,ForwardOp>;
}template<typename Sequence=na,typename State=na,typename BackwardOp=na,typename ForwardOp=arg<1> >struct reverse_iter_fold{typedef typename aux::reverse_iter_fold_impl< ::boost::mpl::O1_size<Sequence>::value,typename begin<Sequence>::type,typename end<Sequence>::type,State,typename lambda<BackwardOp>::type,typename lambda<ForwardOp>::type>::state type;};
template<>struct reverse_iter_fold<na,na,na>;
template<typename Tag>struct lambda<reverse_iter_fold<na,na,na>,Tag>;
}namespace multi_index{namespace detail{template<typename NodeType,typename Final>struct header_holder:private noncopyable{header_holder():member(final().allocate_node()){}~header_holder(){final().deallocate_node(member);}NodeType*member;private:Final&final(){return*static_cast<Final*>(this);}};
}}namespace mpl{template<std::size_t N>struct size_t;
template<std::size_t N>struct size_t{static const std::size_t value=N;typedef size_t type;typedef std::size_t value_type;typedef integral_c_tag tag;typedef boost::mpl::size_t<static_cast<std::size_t>((value+1))>next;typedef boost::mpl::size_t<static_cast<std::size_t>((value-1))>prior;operator std::size_t()const{return static_cast<std::size_t>(this->value);}};
template<std::size_t N>std::size_t const boost::mpl::size_t<N>::value;
}template<typename T>struct alignment_of;
namespace detail{template<typename T>struct alignment_of_hack{char c;T t;alignment_of_hack();};
template<unsigned A,unsigned S>struct alignment_logic{static const std::size_t value=A<S?A:S;};
template<typename T>struct alignment_of_impl{static const std::size_t value=(::boost::detail::alignment_logic<sizeof(::boost::detail::alignment_of_hack<T>)-sizeof(T),sizeof(T)>::value);};
}template<typename T>struct alignment_of: ::boost::integral_constant<std::size_t,::boost::detail::alignment_of_impl<T>::value>{};
template<typename T>struct alignment_of<T&>;
template<>struct alignment_of<void>;
template<>struct alignment_of<void const>;
template<>struct alignment_of<void volatile>;
template<>struct alignment_of<void const volatile>;
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
}}namespace mpl{template<typename Tag>struct empty_impl;
template<typename Sequence=na>struct empty:empty_impl<typename sequence_tag<Sequence>::type>::template apply<Sequence>{};
template<>struct empty<na>;
template<typename Tag>struct lambda<empty<na>,Tag>;
}namespace multi_index{namespace detail{template<typename T>struct is_index_list{static const bool mpl_sequence=mpl::is_sequence<T>::value;static const bool non_empty=!mpl::empty<T>::value;static const bool value=mpl_sequence&&non_empty;};
struct index_node_applier{template<typename IndexSpecifierIterator,typename Super>struct apply{typedef typename mpl::deref<IndexSpecifierIterator>::type index_specifier;typedef typename index_specifier::template node_class<Super>::type type;};};
template<typename Value,typename IndexSpecifierList,typename Allocator>struct multi_index_node_type{typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(detail::is_index_list<IndexSpecifierList>::value)>)>boost_static_assert_typedef_7;typedef typename mpl::reverse_iter_fold<IndexSpecifierList,index_node_base<Value>,mpl::bind2<index_node_applier,mpl::_2,mpl::_1> >::type type;};
}}template<class T>class reference_wrapper;
namespace tuples{struct null_type{};
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
template<int N,class HT,class TT>inline typename access_traits<typename element<N,cons<HT,TT> >::type>::non_const_type get(cons<HT,TT>&c){return detail::get_class<N>::template get<typename access_traits<typename element<N,cons<HT,TT> >::type>::non_const_type,HT,TT>(c);}
template<int N,class HT,class TT>inline typename access_traits<typename element<N,cons<HT,TT> >::type>::const_type get(const cons<HT,TT>&c){return detail::get_class<N>::template get<typename access_traits<typename element<N,cons<HT,TT> >::type>::const_type,HT,TT>(c);}
template<class HT,class TT>struct cons;
template<class HT>struct cons<HT,null_type>;
template<class T0,class T1,class T2,class T3,class T4,class T5,class T6,class T7,class T8,class T9>class tuple;
template<>class tuple<null_type,null_type,null_type,null_type,null_type,null_type,null_type,null_type,null_type,null_type>;
}using tuples::tuple;
using tuples::get;
namespace multi_index{namespace detail{template<typename Value,typename IndexSpecifierList,typename Allocator>class index_base{protected:typedef index_node_base<Value>node_type;typedef typename multi_index_node_type<Value,IndexSpecifierList,Allocator>::type final_node_type;typedef multi_index_container<Value,IndexSpecifierList,Allocator>final_type;typedef tuples::null_type ctor_args_list;typedef typename boost::detail::allocator::rebind_to<Allocator,typename Allocator::value_type>::type final_allocator_type;typedef mpl::vector0<>index_type_list;typedef mpl::vector0<>iterator_type_list;typedef mpl::vector0<>const_iterator_type_list;typedef copy_map<final_node_type,final_allocator_type>copy_map_type;private:typedef typename call_traits<Value>::param_type value_param_type;protected:explicit index_base(const ctor_args_list&,const Allocator&){}void copy_(const index_base<Value,IndexSpecifierList,Allocator>&,const copy_map_type&){}node_type*insert_(value_param_type v,node_type*x){boost::detail::allocator::construct(&x->value(),v);return x;}node_type*insert_(value_param_type v,node_type*,node_type*x){boost::detail::allocator::construct(&x->value(),v);return x;}void erase_(node_type*x){boost::detail::allocator::destroy(&x->value());}void delete_node_(node_type*x){boost::detail::allocator::destroy(&x->value());}void clear_(){}void swap_(index_base<Value,IndexSpecifierList,Allocator>&){}bool replace_(value_param_type v,node_type*x){x->value()=v;return true;}bool modify_(node_type*){return true;}final_type&final(){return*static_cast<final_type*>(this);}const final_type&final()const{return*static_cast<const final_type*>(this);}final_node_type*final_header()const{return final().header();}bool final_empty_()const{return final().empty_();}std::size_t final_size_()const{return final().size_();}std::size_t final_max_size_()const{return final().max_size_();}std::pair<final_node_type*,bool>final_insert_(value_param_type x){return final().insert_(x);}std::pair<final_node_type*,bool>final_insert_(value_param_type x,final_node_type*position){return final().insert_(x,position);}void final_erase_(final_node_type*x){final().erase_(x);}void final_delete_node_(final_node_type*x){final().delete_node_(x);}void final_delete_all_nodes_(){final().delete_all_nodes_();}void final_clear_(){final().clear_();}void final_swap_(final_type&x){final().swap_(x);}bool final_replace_(value_param_type k,final_node_type*x){return final().replace_(k,x);}template<typename Modifier>bool final_modify_(Modifier mod,final_node_type*x){return final().modify_(mod,x);}};
struct index_applier{template<typename IndexSpecifierMeta,typename SuperMeta>struct apply{typedef typename IndexSpecifierMeta::type index_specifier;typedef typename index_specifier::template index_class<SuperMeta>::type type;};};
template<int N,typename Value,typename IndexSpecifierList,typename Allocator>struct nth_layer{static const int length=mpl::size<IndexSpecifierList>::value;typedef typename mpl::eval_if_c<N==length,mpl::identity<index_base<Value,IndexSpecifierList,Allocator> >,mpl::apply2<index_applier,mpl::at_c<IndexSpecifierList,N>,nth_layer<N+1,Value,IndexSpecifierList,Allocator> > >::type type;};
template<typename Value,typename IndexSpecifierList,typename Allocator>struct multi_index_base_type:nth_layer<0,Value,IndexSpecifierList,Allocator>{typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(detail::is_index_list<IndexSpecifierList>::value)>)>boost_static_assert_typedef_10;};
template<typename MultiIndexContainer,typename Index>struct converter;
template<typename Cons>struct default_constructible_tuple_cons;
template<>struct default_constructible_tuple_cons<tuples::null_type>;
template<typename Tag>struct has_tag;
}}template<typename MemberType,int UniqueID=0>class base_from_member{protected:MemberType member;base_from_member():member(){}template<typename T0>explicit base_from_member(T0 x0):member(x0){}template<typename T0,typename T1>explicit base_from_member(T0 x0,T1 x1):member(x0,x1){}template<typename T0,typename T1,typename T2>explicit base_from_member(T0 x0,T1 x1,T2 x2):member(x0,x1,x2){}template<typename T0,typename T1,typename T2,typename T3>explicit base_from_member(T0 x0,T1 x1,T2 x2,T3 x3):member(x0,x1,x2,x3){}template<typename T0,typename T1,typename T2,typename T3,typename T4>explicit base_from_member(T0 x0,T1 x1,T2 x2,T3 x3,T4 x4):member(x0,x1,x2,x3,x4){}template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5>explicit base_from_member(T0 x0,T1 x1,T2 x2,T3 x3,T4 x4,T5 x5):member(x0,x1,x2,x3,x4,x5){}template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6>explicit base_from_member(T0 x0,T1 x1,T2 x2,T3 x3,T4 x4,T5 x5,T6 x6):member(x0,x1,x2,x3,x4,x5,x6){}template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7>explicit base_from_member(T0 x0,T1 x1,T2 x2,T3 x3,T4 x4,T5 x5,T6 x6,T7 x7):member(x0,x1,x2,x3,x4,x5,x6,x7){}template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8>explicit base_from_member(T0 x0,T1 x1,T2 x2,T3 x3,T4 x4,T5 x5,T6 x6,T7 x7,T8 x8):member(x0,x1,x2,x3,x4,x5,x6,x7,x8){}template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9>explicit base_from_member(T0 x0,T1 x1,T2 x2,T3 x3,T4 x4,T5 x5,T6 x6,T7 x7,T8 x8,T9 x9):member(x0,x1,x2,x3,x4,x5,x6,x7,x8,x9){}};
namespace multi_index{template<typename Value,typename IndexSpecifierList,typename Allocator>class multi_index_container:private::boost::base_from_member<typename boost::detail::allocator::rebind_to<Allocator,typename detail::multi_index_node_type<Value,IndexSpecifierList,Allocator>::type>::type>,private detail::header_holder<typename detail::multi_index_node_type<Value,IndexSpecifierList,Allocator>::type,multi_index_container<Value,IndexSpecifierList,Allocator> >,public detail::multi_index_base_type<Value,IndexSpecifierList,Allocator>::type{private:template<typename,typename,typename>friend class detail::index_base;template<typename,typename>friend class detail::header_holder;template<typename,typename>friend class detail::converter;typedef typename detail::multi_index_base_type<Value,IndexSpecifierList,Allocator>::type super;typedef::boost::base_from_member<typename boost::detail::allocator::rebind_to<Allocator,typename super::node_type>::type>bfm_allocator;typedef detail::header_holder<typename super::node_type,multi_index_container>bfm_header;public:typedef detail::default_constructible_tuple_cons<typename super::ctor_args_list>ctor_args_list;typedef IndexSpecifierList index_specifier_type_list;typedef typename super::index_type_list index_type_list;typedef typename super::iterator_type_list iterator_type_list;typedef typename super::const_iterator_type_list const_iterator_type_list;typedef typename super::value_type value_type;typedef typename super::final_allocator_type allocator_type;typedef typename super::iterator iterator;typedef typename super::const_iterator const_iterator;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(detail::no_duplicate_tags_in_index_list<index_type_list>::value)>)>boost_static_assert_typedef_11;typedef typename super::node_type node_type;explicit multi_index_container(const ctor_args_list&args_list=ctor_args_list(),const allocator_type&al=allocator_type()):bfm_allocator(al),super(args_list,bfm_allocator::member),node_count(0){;}template<typename InputIterator>multi_index_container(InputIterator first,InputIterator last,const ctor_args_list&args_list=ctor_args_list(),const allocator_type&al=allocator_type()):bfm_allocator(al),super(args_list,bfm_allocator::member),node_count(0){;{try{iterator hint=super::end();for(;first!=last;++first){hint=super::make_iterator(insert_(*first,hint.get_node()).first);}}catch(...){clear_();throw;;}}}multi_index_container(const multi_index_container<Value,IndexSpecifierList,Allocator>&x):bfm_allocator(x.bfm_allocator::member),bfm_header(),super(x),node_count(0){copy_map_type map(bfm_allocator::member,x.size(),x.header(),header());for(const_iterator it=x.begin(),it_end=x.end();it!=it_end;++it){map.clone(it.get_node());}super::copy_(x,map);map.release();node_count=x.size();;}~multi_index_container(){delete_all_nodes_();}multi_index_container<Value,IndexSpecifierList,Allocator>&operator=(const multi_index_container<Value,IndexSpecifierList,Allocator>&x){;multi_index_container<Value,IndexSpecifierList,Allocator>tmp(x);this->swap(tmp);return*this;}allocator_type get_allocator()const{return allocator_type(bfm_allocator::member);}template<int N>struct nth_index{typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(N>=0&&N<mpl::size<index_type_list>::type::value)>)>boost_static_assert_typedef_12;typedef typename mpl::at_c<index_type_list,N>::type type;};template<int N>typename nth_index<N>::type&get(){typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(N>=0&&N<mpl::size<index_type_list>::type::value)>)>boost_static_assert_typedef_13;return*this;}template<int N>const typename nth_index<N>::type&get()const{typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(N>=0&&N<mpl::size<index_type_list>::type::value)>)>boost_static_assert_typedef_14;return*this;}template<typename Tag>struct index{typedef typename mpl::find_if<index_type_list,detail::has_tag<Tag> >::type iter;static const bool index_found=!(is_same<iter,typename mpl::end<index_type_list>::type>::value);typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(index_found)>)>boost_static_assert_typedef_15;typedef typename mpl::deref<iter>::type type;};template<typename Tag>typename index<Tag>::type&get(){return*this;}template<typename Tag>const typename index<Tag>::type&get()const{return*this;}template<int N>struct nth_index_iterator{typedef typename nth_index<N>::type::iterator type;};template<int N>struct nth_index_const_iterator{typedef typename nth_index<N>::type::const_iterator type;};template<int N,typename IteratorType>typename nth_index_iterator<N>::type project(IteratorType it){typedef typename nth_index<N>::type index;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)((mpl::contains<iterator_type_list,IteratorType>::value))>)>boost_static_assert_typedef_16;((void)0);;((void)0);;return index::make_iterator(static_cast<node_type*>(it.get_node()));}template<int N,typename IteratorType>typename nth_index_const_iterator<N>::type project(IteratorType it)const{typedef typename nth_index<N>::type index;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)((mpl::contains<iterator_type_list,IteratorType>::value||mpl::contains<const_iterator_type_list,IteratorType>::value))>)>boost_static_assert_typedef_17;((void)0);;((void)0);;return index::make_iterator(static_cast<node_type*>(it.get_node()));}template<typename Tag>struct index_iterator{typedef typename index<Tag>::type::iterator type;};template<typename Tag>struct index_const_iterator{typedef typename index<Tag>::type::const_iterator type;};template<typename Tag,typename IteratorType>typename index_iterator<Tag>::type project(IteratorType it){typedef typename index<Tag>::type index;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)((mpl::contains<iterator_type_list,IteratorType>::value))>)>boost_static_assert_typedef_18;((void)0);;((void)0);;return index::make_iterator(static_cast<node_type*>(it.get_node()));}template<typename Tag,typename IteratorType>typename index_const_iterator<Tag>::type project(IteratorType it)const{typedef typename index<Tag>::type index;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)((mpl::contains<iterator_type_list,IteratorType>::value||mpl::contains<const_iterator_type_list,IteratorType>::value))>)>boost_static_assert_typedef_19;((void)0);;((void)0);;return index::make_iterator(static_cast<node_type*>(it.get_node()));}protected:typedef typename super::copy_map_type copy_map_type;node_type*header()const{return bfm_header::member;}node_type*allocate_node(){return bfm_allocator::member.allocate(1);}void deallocate_node(node_type*x){bfm_allocator::member.deallocate(x,1);}bool empty_()const{return node_count==0;}std::size_t size_()const{return node_count;}std::size_t max_size_()const{return static_cast<std::size_t>(-1);}std::pair<node_type*,bool>insert_(const Value&v){node_type*x=allocate_node();{try{node_type*res=super::insert_(v,x);if(res==x){++node_count;return std::pair<node_type*,bool>(res,true);}else{deallocate_node(x);return std::pair<node_type*,bool>(res,false);}}catch(...){deallocate_node(x);throw;;}}}std::pair<node_type*,bool>insert_(const Value&v,node_type*position){node_type*x=allocate_node();{try{node_type*res=super::insert_(v,position,x);if(res==x){++node_count;return std::pair<node_type*,bool>(res,true);}else{deallocate_node(x);return std::pair<node_type*,bool>(res,false);}}catch(...){deallocate_node(x);throw;;}}}void erase_(node_type*x){super::erase_(x);deallocate_node(x);--node_count;}void delete_node_(node_type*x){super::delete_node_(x);deallocate_node(x);}void delete_all_nodes_(){super::delete_all_nodes_();}void clear_(){delete_all_nodes_();super::clear_();node_count=0;}void swap_(multi_index_container<Value,IndexSpecifierList,Allocator>&x){std::swap(bfm_header::member,x.bfm_header::member);super::swap_(x);std::swap(node_count,x.node_count);}bool replace_(const Value&k,node_type*x){return super::replace_(k,x);}template<typename Modifier>bool modify_(Modifier mod,node_type*x){mod(const_cast<value_type&>(x->value()));{try{if(!super::modify_(x)){deallocate_node(x);--node_count;return false;}else return true;}catch(...){deallocate_node(x);--node_count;throw;;}}}private:std::size_t node_count;};
template<typename MultiIndexContainer,int N>struct nth_index;
template<int N,typename Value,typename IndexSpecifierList,typename Allocator>typename nth_index<multi_index_container<Value,IndexSpecifierList,Allocator>,N>::type&get(multi_index_container<Value,IndexSpecifierList,Allocator>&m){typedef multi_index_container<Value,IndexSpecifierList,Allocator>multi_index_type;typedef typename nth_index<multi_index_container<Value,IndexSpecifierList,Allocator>,N>::type index;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(N>=0&&N<mpl::size<typename multi_index_type::index_type_list>::type::value)>)>boost_static_assert_typedef_21;return detail::converter<multi_index_type,index>::index(m);}
template<int N,typename Value,typename IndexSpecifierList,typename Allocator>const typename nth_index<multi_index_container<Value,IndexSpecifierList,Allocator>,N>::type&get(const multi_index_container<Value,IndexSpecifierList,Allocator>&m){typedef multi_index_container<Value,IndexSpecifierList,Allocator>multi_index_type;typedef typename nth_index<multi_index_container<Value,IndexSpecifierList,Allocator>,N>::type index;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(N>=0&&N<mpl::size<typename multi_index_type::index_type_list>::type::value)>)>boost_static_assert_typedef_22;return detail::converter<multi_index_type,index>::index(m);}
template<typename MultiIndexContainer,typename Tag>struct index;
template<typename Tag,typename Value,typename IndexSpecifierList,typename Allocator>typename::boost::multi_index::index<multi_index_container<Value,IndexSpecifierList,Allocator>,Tag>::type&get(multi_index_container<Value,IndexSpecifierList,Allocator>&m){typedef multi_index_container<Value,IndexSpecifierList,Allocator>multi_index_type;typedef typename::boost::multi_index::index<multi_index_container<Value,IndexSpecifierList,Allocator>,Tag>::type index;return detail::converter<multi_index_type,index>::index(m);}
template<typename Tag,typename Value,typename IndexSpecifierList,typename Allocator>const typename::boost::multi_index::index<multi_index_container<Value,IndexSpecifierList,Allocator>,Tag>::type&get(const multi_index_container<Value,IndexSpecifierList,Allocator>&m){typedef multi_index_container<Value,IndexSpecifierList,Allocator>multi_index_type;typedef typename::boost::multi_index::index<multi_index_container<Value,IndexSpecifierList,Allocator>,Tag>::type index;return detail::converter<multi_index_type,index>::index(m);}
template<typename MultiIndexContainer,int N>struct nth_index_iterator;
template<typename MultiIndexContainer,int N>struct nth_index_const_iterator;
template<int N,typename IteratorType,typename Value,typename IndexSpecifierList,typename Allocator>typename nth_index_iterator<multi_index_container<Value,IndexSpecifierList,Allocator>,N>::type project(multi_index_container<Value,IndexSpecifierList,Allocator>&m,IteratorType it){typedef multi_index_container<Value,IndexSpecifierList,Allocator>multi_index_type;typedef typename nth_index<multi_index_type,N>::type index;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)((mpl::contains<typename multi_index_type::iterator_type_list,IteratorType>::value))>)>boost_static_assert_typedef_24;((void)0);;return detail::converter<multi_index_type,index>::iterator(m,static_cast<typename multi_index_type::node_type*>(it.get_node()));}
template<int N,typename IteratorType,typename Value,typename IndexSpecifierList,typename Allocator>typename nth_index_const_iterator<multi_index_container<Value,IndexSpecifierList,Allocator>,N>::type project(const multi_index_container<Value,IndexSpecifierList,Allocator>&m,IteratorType it){typedef multi_index_container<Value,IndexSpecifierList,Allocator>multi_index_type;typedef typename nth_index<multi_index_type,N>::type index;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)((mpl::contains<typename multi_index_type::iterator_type_list,IteratorType>::value||mpl::contains<typename multi_index_type::const_iterator_type_list,IteratorType>::value))>)>boost_static_assert_typedef_25;((void)0);;return detail::converter<multi_index_type,index>::const_iterator(m,static_cast<typename multi_index_type::node_type*>(it.get_node()));}
template<typename MultiIndexContainer,typename Tag>struct index_iterator;
template<typename MultiIndexContainer,typename Tag>struct index_const_iterator;
template<typename Tag,typename IteratorType,typename Value,typename IndexSpecifierList,typename Allocator>typename index_iterator<multi_index_container<Value,IndexSpecifierList,Allocator>,Tag>::type project(multi_index_container<Value,IndexSpecifierList,Allocator>&m,IteratorType it){typedef multi_index_container<Value,IndexSpecifierList,Allocator>multi_index_type;typedef typename::boost::multi_index::index<multi_index_type,Tag>::type index;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)((mpl::contains<typename multi_index_type::iterator_type_list,IteratorType>::value))>)>boost_static_assert_typedef_26;((void)0);;return detail::converter<multi_index_type,index>::iterator(m,static_cast<typename multi_index_type::node_type*>(it.get_node()));}
template<typename Tag,typename IteratorType,typename Value,typename IndexSpecifierList,typename Allocator>typename index_const_iterator<multi_index_container<Value,IndexSpecifierList,Allocator>,Tag>::type project(const multi_index_container<Value,IndexSpecifierList,Allocator>&m,IteratorType it){typedef multi_index_container<Value,IndexSpecifierList,Allocator>multi_index_type;typedef typename::boost::multi_index::index<multi_index_type,Tag>::type index;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)((mpl::contains<typename multi_index_type::iterator_type_list,IteratorType>::value||mpl::contains<typename multi_index_type::const_iterator_type_list,IteratorType>::value))>)>boost_static_assert_typedef_27;((void)0);;return detail::converter<multi_index_type,index>::const_iterator(m,static_cast<typename multi_index_type::node_type*>(it.get_node()));}
template<typename Value1,typename IndexSpecifierList1,typename Allocator1,typename Value2,typename IndexSpecifierList2,typename Allocator2>bool operator==(const multi_index_container<Value1,IndexSpecifierList1,Allocator1>&x,const multi_index_container<Value2,IndexSpecifierList2,Allocator2>&y){return get<0>(x)==get<0>(y);}
template<typename Value1,typename IndexSpecifierList1,typename Allocator1,typename Value2,typename IndexSpecifierList2,typename Allocator2>bool operator<(const multi_index_container<Value1,IndexSpecifierList1,Allocator1>&x,const multi_index_container<Value2,IndexSpecifierList2,Allocator2>&y){return get<0>(x)<get<0>(y);}
template<typename Value1,typename IndexSpecifierList1,typename Allocator1,typename Value2,typename IndexSpecifierList2,typename Allocator2>bool operator!=(const multi_index_container<Value1,IndexSpecifierList1,Allocator1>&x,const multi_index_container<Value2,IndexSpecifierList2,Allocator2>&y){return get<0>(x)!=get<0>(y);}
template<typename Value1,typename IndexSpecifierList1,typename Allocator1,typename Value2,typename IndexSpecifierList2,typename Allocator2>bool operator>(const multi_index_container<Value1,IndexSpecifierList1,Allocator1>&x,const multi_index_container<Value2,IndexSpecifierList2,Allocator2>&y){return get<0>(x)>get<0>(y);}
template<typename Value1,typename IndexSpecifierList1,typename Allocator1,typename Value2,typename IndexSpecifierList2,typename Allocator2>bool operator>=(const multi_index_container<Value1,IndexSpecifierList1,Allocator1>&x,const multi_index_container<Value2,IndexSpecifierList2,Allocator2>&y){return get<0>(x)>=get<0>(y);}
template<typename Value1,typename IndexSpecifierList1,typename Allocator1,typename Value2,typename IndexSpecifierList2,typename Allocator2>bool operator<=(const multi_index_container<Value1,IndexSpecifierList1,Allocator1>&x,const multi_index_container<Value2,IndexSpecifierList2,Allocator2>&y){return get<0>(x)<=get<0>(y);}
}using multi_index::get;
namespace detail{template<class Category,class T,class Distance,class Pointer,class Reference>struct iterator_base:std::iterator<Category,T,Distance,Pointer,Reference>{};
}template<class Category,class T,class Distance=std::ptrdiff_t,class Pointer=T*,class Reference=T&>struct iterator:boost::detail::iterator_base<Category,T,Distance,Pointer,Reference>{};
template<class T>inline void checked_delete(T*x){typedef char type_must_be_complete[sizeof(T)?1:-1];(void)sizeof(type_must_be_complete);delete x;}
template<class T>inline T next(T x){return++x;}
template<class T,class Distance>inline T next(T x,Distance n){std::advance(x,n);return x;}
template<typename A,typename B>struct is_interoperable;
template<class Iterator>struct iterator_difference;
struct use_default;
template<class I,class V,class TC,class R,class D>class iterator_facade;
namespace detail{struct always_bool2{template<class T,class U>struct apply{typedef bool type;};};
template<class Facade1,class Facade2,class Return>struct enable_if_interoperable;
template<class Iterator,class Value,class Reference,class CategoryOrTraversal>struct postfix_increment_result;
template<class Iterator>class operator_brackets_proxy;
template<class Iterator>operator_brackets_proxy<Iterator>make_operator_brackets_result(Iterator const&iter,mpl::true_){return operator_brackets_proxy<Iterator>(iter);}
template<class Iterator>typename Iterator::value_type make_operator_brackets_result(Iterator const&iter,mpl::false_){return*iter;}
struct choose_difference_type{template<class I1,class I2>struct apply:mpl::eval_if<is_convertible<I2,I1>,iterator_difference<I1>,iterator_difference<I2> >{};};
}class iterator_core_access{template<class I,class V,class TC,class R,class D>friend class iterator_facade;template<class Derived1,class V1,class TC1,class R1,class D1,class Derived2,class V2,class TC2,class R2,class D2>friend typename detail::enable_if_interoperable<Derived1,Derived2,typename mpl::apply2<detail::always_bool2,Derived1,Derived2>::type>::type operator==(iterator_facade<Derived1,V1,TC1,R1,D1>const&lhs,iterator_facade<Derived2,V2,TC2,R2,D2>const&rhs);template<class Derived1,class V1,class TC1,class R1,class D1,class Derived2,class V2,class TC2,class R2,class D2>friend typename detail::enable_if_interoperable<Derived1,Derived2,typename mpl::apply2<detail::always_bool2,Derived1,Derived2>::type>::type operator!=(iterator_facade<Derived1,V1,TC1,R1,D1>const&lhs,iterator_facade<Derived2,V2,TC2,R2,D2>const&rhs);template<class Derived1,class V1,class TC1,class R1,class D1,class Derived2,class V2,class TC2,class R2,class D2>friend typename detail::enable_if_interoperable<Derived1,Derived2,typename mpl::apply2<detail::always_bool2,Derived1,Derived2>::type>::type operator<(iterator_facade<Derived1,V1,TC1,R1,D1>const&lhs,iterator_facade<Derived2,V2,TC2,R2,D2>const&rhs);template<class Derived1,class V1,class TC1,class R1,class D1,class Derived2,class V2,class TC2,class R2,class D2>friend typename detail::enable_if_interoperable<Derived1,Derived2,typename mpl::apply2<detail::always_bool2,Derived1,Derived2>::type>::type operator>(iterator_facade<Derived1,V1,TC1,R1,D1>const&lhs,iterator_facade<Derived2,V2,TC2,R2,D2>const&rhs);template<class Derived1,class V1,class TC1,class R1,class D1,class Derived2,class V2,class TC2,class R2,class D2>friend typename detail::enable_if_interoperable<Derived1,Derived2,typename mpl::apply2<detail::always_bool2,Derived1,Derived2>::type>::type operator<=(iterator_facade<Derived1,V1,TC1,R1,D1>const&lhs,iterator_facade<Derived2,V2,TC2,R2,D2>const&rhs);template<class Derived1,class V1,class TC1,class R1,class D1,class Derived2,class V2,class TC2,class R2,class D2>friend typename detail::enable_if_interoperable<Derived1,Derived2,typename mpl::apply2<detail::always_bool2,Derived1,Derived2>::type>::type operator>=(iterator_facade<Derived1,V1,TC1,R1,D1>const&lhs,iterator_facade<Derived2,V2,TC2,R2,D2>const&rhs);template<class Derived1,class V1,class TC1,class R1,class D1,class Derived2,class V2,class TC2,class R2,class D2>friend typename detail::enable_if_interoperable<Derived1,Derived2,typename mpl::apply2<detail::choose_difference_type,Derived1,Derived2>::type>::type operator-(iterator_facade<Derived1,V1,TC1,R1,D1>const&lhs,iterator_facade<Derived2,V2,TC2,R2,D2>const&rhs);template<class Derived,class V,class TC,class R,class D>friend inline Derived operator+(iterator_facade<Derived,V,TC,R,D>const&,typename Derived::difference_type);template<class Derived,class V,class TC,class R,class D>friend inline Derived operator+(typename Derived::difference_type,iterator_facade<Derived,V,TC,R,D>const&);template<class Facade>static typename Facade::reference dereference(Facade const&f){return f.dereference();}template<class Facade>static void increment(Facade&f){f.increment();}template<class Facade>static void decrement(Facade&f){f.decrement();}template<class Facade1,class Facade2>static bool equal(Facade1 const&f1,Facade2 const&f2,mpl::true_){return f1.equal(f2);}template<class Facade1,class Facade2>static bool equal(Facade1 const&f1,Facade2 const&f2,mpl::false_){return f2.equal(f1);}template<class Facade>static void advance(Facade&f,typename Facade::difference_type n){f.advance(n);}template<class Facade1,class Facade2>static typename Facade1::difference_type distance_from(Facade1 const&f1,Facade2 const&f2,mpl::true_){return-f1.distance_to(f2);}template<class Facade1,class Facade2>static typename Facade2::difference_type distance_from(Facade1 const&f1,Facade2 const&f2,mpl::false_){return f2.distance_to(f1);}template<class I,class V,class TC,class R,class D>static I&derived(iterator_facade<I,V,TC,R,D>&facade){return*static_cast<I*>(&facade);}template<class I,class V,class TC,class R,class D>static I const&derived(iterator_facade<I,V,TC,R,D>const&facade){return*static_cast<I const*>(&facade);}private:iterator_core_access();};
template<class Derived,class Value,class CategoryOrTraversal,class Reference=Value&,class Difference=std::ptrdiff_t>class iterator_facade;
template<class I,class V,class TC,class R,class D>inline typename detail::postfix_increment_result<I,V,R,TC>::type operator++(iterator_facade<I,V,TC,R,D>&i,int){typename detail::postfix_increment_result<I,V,R,TC>::type tmp(*static_cast<I*>(&i));++i;return tmp;}
template<class Derived1,class V1,class TC1,class R1,class D1,class Derived2,class V2,class TC2,class R2,class D2>inline typename detail::enable_if_interoperable<Derived1,Derived2,typename mpl::apply2<detail::always_bool2,Derived1,Derived2>::type>::type operator==(iterator_facade<Derived1,V1,TC1,R1,D1>const&lhs,iterator_facade<Derived2,V2,TC2,R2,D2>const&rhs){typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)((is_interoperable<Derived1,Derived2>::value))>)>boost_static_assert_typedef_33;return iterator_core_access::equal(*static_cast<Derived1 const*>(&lhs),*static_cast<Derived2 const*>(&rhs),is_convertible<Derived2,Derived1>());}
template<class Derived1,class V1,class TC1,class R1,class D1,class Derived2,class V2,class TC2,class R2,class D2>inline typename detail::enable_if_interoperable<Derived1,Derived2,typename mpl::apply2<detail::always_bool2,Derived1,Derived2>::type>::type operator!=(iterator_facade<Derived1,V1,TC1,R1,D1>const&lhs,iterator_facade<Derived2,V2,TC2,R2,D2>const&rhs){typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)((is_interoperable<Derived1,Derived2>::value))>)>boost_static_assert_typedef_34;return!iterator_core_access::equal(*static_cast<Derived1 const*>(&lhs),*static_cast<Derived2 const*>(&rhs),is_convertible<Derived2,Derived1>());}
template<class Derived1,class V1,class TC1,class R1,class D1,class Derived2,class V2,class TC2,class R2,class D2>inline typename detail::enable_if_interoperable<Derived1,Derived2,typename mpl::apply2<detail::always_bool2,Derived1,Derived2>::type>::type operator<(iterator_facade<Derived1,V1,TC1,R1,D1>const&lhs,iterator_facade<Derived2,V2,TC2,R2,D2>const&rhs){typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)((is_interoperable<Derived1,Derived2>::value))>)>boost_static_assert_typedef_35;return 0>iterator_core_access::distance_from(*static_cast<Derived1 const*>(&lhs),*static_cast<Derived2 const*>(&rhs),is_convertible<Derived2,Derived1>());}
template<class Derived1,class V1,class TC1,class R1,class D1,class Derived2,class V2,class TC2,class R2,class D2>inline typename detail::enable_if_interoperable<Derived1,Derived2,typename mpl::apply2<detail::always_bool2,Derived1,Derived2>::type>::type operator>(iterator_facade<Derived1,V1,TC1,R1,D1>const&lhs,iterator_facade<Derived2,V2,TC2,R2,D2>const&rhs){typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)((is_interoperable<Derived1,Derived2>::value))>)>boost_static_assert_typedef_36;return 0<iterator_core_access::distance_from(*static_cast<Derived1 const*>(&lhs),*static_cast<Derived2 const*>(&rhs),is_convertible<Derived2,Derived1>());}
template<class Derived1,class V1,class TC1,class R1,class D1,class Derived2,class V2,class TC2,class R2,class D2>inline typename detail::enable_if_interoperable<Derived1,Derived2,typename mpl::apply2<detail::always_bool2,Derived1,Derived2>::type>::type operator<=(iterator_facade<Derived1,V1,TC1,R1,D1>const&lhs,iterator_facade<Derived2,V2,TC2,R2,D2>const&rhs){typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)((is_interoperable<Derived1,Derived2>::value))>)>boost_static_assert_typedef_37;return 0>=iterator_core_access::distance_from(*static_cast<Derived1 const*>(&lhs),*static_cast<Derived2 const*>(&rhs),is_convertible<Derived2,Derived1>());}
template<class Derived1,class V1,class TC1,class R1,class D1,class Derived2,class V2,class TC2,class R2,class D2>inline typename detail::enable_if_interoperable<Derived1,Derived2,typename mpl::apply2<detail::always_bool2,Derived1,Derived2>::type>::type operator>=(iterator_facade<Derived1,V1,TC1,R1,D1>const&lhs,iterator_facade<Derived2,V2,TC2,R2,D2>const&rhs){typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)((is_interoperable<Derived1,Derived2>::value))>)>boost_static_assert_typedef_38;return 0<=iterator_core_access::distance_from(*static_cast<Derived1 const*>(&lhs),*static_cast<Derived2 const*>(&rhs),is_convertible<Derived2,Derived1>());}
template<class Derived1,class V1,class TC1,class R1,class D1,class Derived2,class V2,class TC2,class R2,class D2>inline typename detail::enable_if_interoperable<Derived1,Derived2,typename mpl::apply2<detail::choose_difference_type,Derived1,Derived2>::type>::type operator-(iterator_facade<Derived1,V1,TC1,R1,D1>const&lhs,iterator_facade<Derived2,V2,TC2,R2,D2>const&rhs){typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)((is_interoperable<Derived1,Derived2>::value))>)>boost_static_assert_typedef_39;return iterator_core_access::distance_from(*static_cast<Derived1 const*>(&lhs),*static_cast<Derived2 const*>(&rhs),is_convertible<Derived2,Derived1>());}
template<class Derived,class V,class TC,class R,class D>inline Derived operator+(iterator_facade<Derived,V,TC,R,D>const&i,typename Derived::difference_type n){Derived tmp(static_cast<Derived const&>(i));return tmp+=n;}
template<class Derived,class V,class TC,class R,class D>inline Derived operator+(typename Derived::difference_type n,iterator_facade<Derived,V,TC,R,D>const&i){Derived tmp(static_cast<Derived const&>(i));return tmp+=n;}
struct use_default;
template<class To>struct is_convertible<use_default,To>;
template<class Iterator>class reverse_iterator;
template<class BidirectionalIterator>reverse_iterator<BidirectionalIterator>make_reverse_iterator(BidirectionalIterator x){return reverse_iterator<BidirectionalIterator>(x);}
namespace detail{template<typename T>class empty_base;
}template<class T,class B=::boost::detail::empty_base<T> >struct equality_comparable1:B{friend bool operator!=(const T&x,const T&y){return!(x==y);}};
template<class T,class B=::boost::detail::empty_base<T> >struct incrementable:B{friend T operator++(T&x,int){incrementable_type nrv(x);++x;return nrv;}private:typedef T incrementable_type;};
template<class T,class B=::boost::detail::empty_base<T> >struct decrementable:B{friend T operator--(T&x,int){decrementable_type nrv(x);--x;return nrv;}private:typedef T decrementable_type;};
template<class T,class P,class B=::boost::detail::empty_base<T> >struct dereferenceable:B{P operator->()const{return&*static_cast<const T&>(*this);}};
template<class T,class P,class B=::boost::detail::empty_base<T> >struct input_iteratable:equality_comparable1<T,incrementable<T,dereferenceable<T,P,B> > >{};
template<class T,class P,class B=::boost::detail::empty_base<T> >struct forward_iteratable:input_iteratable<T,P,B>{};
template<class T,class P,class B=::boost::detail::empty_base<T> >struct bidirectional_iteratable:forward_iteratable<T,P,decrementable<T,B> >{};
template<class T,class V,class D=std::ptrdiff_t,class P=V*,class R=V&>struct bidirectional_iterator_helper:bidirectional_iteratable<T,P,boost::iterator<std::bidirectional_iterator_tag,V,D,P,R> >{};
namespace multi_index{namespace detail{template<typename Node,typename Derived=mpl::na>class bidir_node_iterator:public bidirectional_iterator_helper<bidir_node_iterator<Node,Derived>,typename Node::value_type,std::ptrdiff_t,const typename Node::value_type*,const typename Node::value_type&>{public:bidir_node_iterator(){}explicit bidir_node_iterator(Node*node_):node(node_){}const typename Node::value_type&operator*()const{return node->value();}friend bool operator==(const bidir_node_iterator&x,const bidir_node_iterator&y){return x.node==y.node;}bidir_node_iterator&operator++(){Node::increment(node);return*this;}bidir_node_iterator&operator--(){Node::decrement(node);return*this;}typedef Node node_type;Node*get_node()const{return node;}private:Node*node;};
template<typename Modifier,typename Value,typename KeyFromValue>struct modify_key_adaptor;
template<int N>struct uintptr_candidates;
template<>struct uintptr_candidates<-1>;
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
struct ordered_index_node_std_base{typedef ordered_index_color&color_ref;typedef ordered_index_node_impl*&parent_ref;ordered_index_color&color(){return color_;}ordered_index_color color()const{return color_;}ordered_index_node_impl*&parent(){return parent_;}ordered_index_node_impl*parent()const{return parent_;}ordered_index_node_impl*&left(){return left_;}ordered_index_node_impl*left()const{return left_;}ordered_index_node_impl*&right(){return right_;}ordered_index_node_impl*right()const{return right_;}private:ordered_index_color color_;ordered_index_node_impl*parent_;ordered_index_node_impl*left_;ordered_index_node_impl*right_;};
struct ordered_index_node_compressed_base{struct color_ref{color_ref(uintptr_type*r_):r(r_){}operator ordered_index_color()const{return ordered_index_color(*r&uintptr_type(1));}color_ref&operator=(ordered_index_color c){*r&=~uintptr_type(1);*r|=uintptr_type(c);return*this;}color_ref&operator=(const color_ref&x){return operator=(x.operator ordered_index_color());}private:uintptr_type*r;};struct parent_ref{parent_ref(uintptr_type*r_):r(r_){}operator ordered_index_node_impl*()const{return(ordered_index_node_impl*)(void*)(*r&~uintptr_type(1));}parent_ref&operator=(ordered_index_node_impl*p){*r=((uintptr_type)(void*)p)|(*r&uintptr_type(1));return*this;}parent_ref&operator=(const parent_ref&x){return operator=(x.operator ordered_index_node_impl*());}ordered_index_node_impl*operator->()const{return operator ordered_index_node_impl*();}private:uintptr_type*r;};color_ref color(){return color_ref(&parentcolor_);}ordered_index_color color()const{return ordered_index_color(parentcolor_&std::size_t(1ul));}parent_ref parent(){return parent_ref(&parentcolor_);}ordered_index_node_impl*parent()const{return(ordered_index_node_impl*)(void*)(parentcolor_&~uintptr_type(1));}ordered_index_node_impl*&left(){return left_;}ordered_index_node_impl*left()const{return left_;}ordered_index_node_impl*&right(){return right_;}ordered_index_node_impl*right()const{return right_;}private:uintptr_type parentcolor_;ordered_index_node_impl*left_;ordered_index_node_impl*right_;};
struct ordered_index_node_impl:mpl::if_c<!(has_uintptr_type::value)||(alignment_of<ordered_index_node_compressed_base>::value%2),ordered_index_node_std_base,ordered_index_node_compressed_base>::type{static void increment(ordered_index_node_impl*&x){if(x->right()){x=x->right();while(x->left())x=x->left();}else{ordered_index_node_impl*y=x->parent();while(x==y->right()){x=y;y=y->parent();}if(x->right()!=y)x=y;}}static void decrement(ordered_index_node_impl*&x){if(x->color()==red&&x->parent()->parent()==x){x=x->right();}else if(x->left()){ordered_index_node_impl*y=x->left();while(y->right())y=y->right();x=y;}else{ordered_index_node_impl*y=x->parent();while(x==y->left()){x=y;y=y->parent();}x=y;}}static void rotate_left(ordered_index_node_impl*x,parent_ref root){ordered_index_node_impl*y=x->right();x->right()=y->left();if(y->left())y->left()->parent()=x;y->parent()=x->parent();if(x==root)root=y;else if(x==x->parent()->left())x->parent()->left()=y;else x->parent()->right()=y;y->left()=x;x->parent()=y;}static ordered_index_node_impl*minimum(ordered_index_node_impl*x){while(x->left())x=x->left();return x;}static ordered_index_node_impl*maximum(ordered_index_node_impl*x){while(x->right())x=x->right();return x;}static void rotate_right(ordered_index_node_impl*x,parent_ref root){ordered_index_node_impl*y=x->left();x->left()=y->right();if(y->right())y->right()->parent()=x;y->parent()=x->parent();if(x==root)root=y;else if(x==x->parent()->right())x->parent()->right()=y;else x->parent()->left()=y;y->right()=x;x->parent()=y;}static void rebalance(ordered_index_node_impl*x,parent_ref root){x->color()=red;while(x!=root&&x->parent()->color()==red){if(x->parent()==x->parent()->parent()->left()){ordered_index_node_impl*y=x->parent()->parent()->right();if(y&&y->color()==red){x->parent()->color()=black;y->color()=black;x->parent()->parent()->color()=red;x=x->parent()->parent();}else{if(x==x->parent()->right()){x=x->parent();rotate_left(x,root);}x->parent()->color()=black;x->parent()->parent()->color()=red;rotate_right(x->parent()->parent(),root);}}else{ordered_index_node_impl*y=x->parent()->parent()->left();if(y&&y->color()==red){x->parent()->color()=black;y->color()=black;x->parent()->parent()->color()=red;x=x->parent()->parent();}else{if(x==x->parent()->left()){x=x->parent();rotate_right(x,root);}x->parent()->color()=black;x->parent()->parent()->color()=red;rotate_left(x->parent()->parent(),root);}}}root->color()=black;}static void link(ordered_index_node_impl*x,ordered_index_side side,ordered_index_node_impl*position,ordered_index_node_impl*header){if(side==to_left){position->left()=x;if(position==header){header->parent()=x;header->right()=x;}else if(position==header->left()){header->left()=x;}}else{position->right()=x;if(position==header->right()){header->right()=x;}}x->parent()=position;x->left()=0;x->right()=0;ordered_index_node_impl::rebalance(x,header->parent());}static ordered_index_node_impl*rebalance_for_erase(ordered_index_node_impl*z,parent_ref root,ordered_index_node_impl*&leftmost,ordered_index_node_impl*&rightmost){ordered_index_node_impl*y=z;ordered_index_node_impl*x=0;ordered_index_node_impl*x_parent=0;if(y->left()==0){x=y->right();}else{if(y->right()==0){x=y->left();}else{y=y->right();while(y->left())y=y->left();x=y->right();}}if(y!=z){z->left()->parent()=y;y->left()=z->left();if(y!=z->right()){x_parent=y->parent();if(x)x->parent()=y->parent();y->parent()->left()=x;y->right()=z->right();z->right()->parent()=y;}else{x_parent=y;}if(root==z)root=y;else if(z->parent()->left()==z)z->parent()->left()=y;else z->parent()->right()=y;y->parent()=z->parent();ordered_index_color c=y->color();y->color()=z->color();z->color()=c;y=z;}else{x_parent=y->parent();if(x)x->parent()=y->parent();if(root==z){root=x;}else{if(z->parent()->left()==z)z->parent()->left()=x;else z->parent()->right()=x;}if(leftmost==z){if(z->right()==0){leftmost=z->parent();}else{leftmost=minimum(x);}}if(rightmost==z){if(z->left()==0){rightmost=z->parent();}else{rightmost=maximum(x);}}}if(y->color()!=red){while(x!=root&&(x==0||x->color()==black)){if(x==x_parent->left()){ordered_index_node_impl*w=x_parent->right();if(w->color()==red){w->color()=black;x_parent->color()=red;rotate_left(x_parent,root);w=x_parent->right();}if((w->left()==0||w->left()->color()==black)&&(w->right()==0||w->right()->color()==black)){w->color()=red;x=x_parent;x_parent=x_parent->parent();}else{if(w->right()==0||w->right()->color()==black){if(w->left())w->left()->color()=black;w->color()=red;rotate_right(w,root);w=x_parent->right();}w->color()=x_parent->color();x_parent->color()=black;if(w->right())w->right()->color()=black;rotate_left(x_parent,root);break;}}else{ordered_index_node_impl*w=x_parent->left();if(w->color()==red){w->color()=black;x_parent->color()=red;rotate_right(x_parent,root);w=x_parent->left();}if((w->right()==0||w->right()->color()==black)&&(w->left()==0||w->left()->color()==black)){w->color()=red;x=x_parent;x_parent=x_parent->parent();}else{if(w->left()==0||w->left()->color()==black){if(w->right())w->right()->color()=black;w->color()=red;rotate_left(w,root);w=x_parent->left();}w->color()=x_parent->color();x_parent->color()=black;if(w->left())w->left()->color()=black;rotate_right(x_parent,root);break;}}}if(x)x->color()=black;}return y;}static void restore(ordered_index_node_impl*x,ordered_index_node_impl*position,ordered_index_node_impl*header){if(position->left()==0||position->left()==header){link(x,to_left,position,header);}else{decrement(position);link(x,to_right,position,header);}}};
template<typename Super>struct ordered_index_node_trampoline:ordered_index_node_impl{};
template<typename Super>struct ordered_index_node:Super,ordered_index_node_trampoline<Super>{private:typedef ordered_index_node_trampoline<Super>impl_type;typedef typename impl_type::color_ref color_ref;typedef typename impl_type::parent_ref parent_ref;public:color_ref color(){return impl_type::color();}ordered_index_color color()const{return impl_type::color();}parent_ref parent(){return impl_type::parent();}ordered_index_node_impl*parent()const{return impl_type::parent();}ordered_index_node_impl*&left(){return impl_type::left();}ordered_index_node_impl*left()const{return impl_type::left();}ordered_index_node_impl*&right(){return impl_type::right();}ordered_index_node_impl*right()const{return impl_type::right();}ordered_index_node_impl*impl(){return static_cast<impl_type*>(this);}const ordered_index_node_impl*impl()const{return static_cast<const impl_type*>(this);}static ordered_index_node*from_impl(ordered_index_node_impl*x){return static_cast<ordered_index_node*>(static_cast<impl_type*>(x));}static const ordered_index_node*from_impl(const ordered_index_node_impl*x){return static_cast<const ordered_index_node*>(static_cast<const impl_type*>(x));}static void increment(ordered_index_node*&x){ordered_index_node_impl*xi=x->impl();impl_type::increment(xi);x=from_impl(xi);}static void decrement(ordered_index_node*&x){ordered_index_node_impl*xi=x->impl();impl_type::decrement(xi);x=from_impl(xi);}};
template<typename Node,typename KeyFromValue,typename CompatibleKey,typename CompatibleCompare>inline Node*ordered_index_find(Node*header,const KeyFromValue&key,const CompatibleKey&x,const CompatibleCompare&comp){Node*y=header;Node*z=Node::from_impl(header->parent());while(z){if(!comp(key(z->value()),x)){y=z;z=Node::from_impl(z->left());}else z=Node::from_impl(z->right());}return(y==header||comp(x,key(y->value())))?header:y;}
template<typename Node,typename KeyFromValue,typename CompatibleKey,typename CompatibleCompare>inline Node*ordered_index_lower_bound(Node*header,const KeyFromValue&key,const CompatibleKey&x,const CompatibleCompare&comp){Node*y=header;Node*z=Node::from_impl(header->parent());while(z){if(!comp(key(z->value()),x)){y=z;z=Node::from_impl(z->left());}else z=Node::from_impl(z->right());}return y;}
template<typename Node,typename KeyFromValue,typename CompatibleKey,typename CompatibleCompare>inline Node*ordered_index_upper_bound(Node*header,const KeyFromValue&key,const CompatibleKey&x,const CompatibleCompare&comp){Node*y=header;Node*z=Node::from_impl(header->parent());while(z){if(comp(x,key(z->value()))){y=z;z=Node::from_impl(z->left());}else z=Node::from_impl(z->right());}return y;}
struct unbounded_type{};
template<typename Value,typename KeyFromValue,typename Compare>struct value_comparison;
struct ordered_unique_tag{};
struct ordered_non_unique_tag{};
template<typename KeyFromValue,typename Compare,typename SuperMeta,typename TagList,typename Category>class ordered_index:protected SuperMeta::type{typedef typename SuperMeta::type super;protected:typedef ordered_index_node<typename super::node_type>node_type;public:typedef typename KeyFromValue::result_type key_type;typedef typename node_type::value_type value_type;typedef KeyFromValue key_from_value;typedef Compare key_compare;typedef value_comparison<value_type,KeyFromValue,Compare>value_compare;typedef tuple<key_from_value,key_compare>ctor_args;typedef typename super::final_allocator_type allocator_type;typedef typename allocator_type::reference reference;typedef typename allocator_type::const_reference const_reference;typedef bidir_node_iterator<node_type>iterator;typedef iterator const_iterator;typedef std::size_t size_type;typedef std::ptrdiff_t difference_type;typedef typename allocator_type::pointer pointer;typedef typename allocator_type::const_pointer const_pointer;typedef typename boost::reverse_iterator<iterator>reverse_iterator;typedef typename boost::reverse_iterator<const_iterator>const_reverse_iterator;typedef TagList tag_list;protected:typedef typename super::final_node_type final_node_type;typedef tuples::cons<ctor_args,typename super::ctor_args_list>ctor_args_list;typedef typename mpl::push_front<typename super::index_type_list,ordered_index>::type index_type_list;typedef typename mpl::push_front<typename super::iterator_type_list,iterator>::type iterator_type_list;typedef typename mpl::push_front<typename super::const_iterator_type_list,const_iterator>::type const_iterator_type_list;typedef typename super::copy_map_type copy_map_type;private:typedef typename call_traits<value_type>::param_type value_param_type;typedef typename call_traits<key_type>::param_type key_param_type;public:ordered_index<KeyFromValue,Compare,SuperMeta,TagList,Category>&operator=(const ordered_index<KeyFromValue,Compare,SuperMeta,TagList,Category>&x){this->final()=x.final();return*this;}allocator_type get_allocator()const{return this->final().get_allocator();}iterator begin(){return make_iterator(leftmost());}const_iterator begin()const{return make_iterator(leftmost());}iterator end(){return make_iterator(header());}const_iterator end()const{return make_iterator(header());}reverse_iterator rbegin(){return make_reverse_iterator(end());}const_reverse_iterator rbegin()const{return make_reverse_iterator(end());}reverse_iterator rend(){return make_reverse_iterator(begin());}const_reverse_iterator rend()const{return make_reverse_iterator(begin());}bool empty()const{return this->final_empty_();}size_type size()const{return this->final_size_();}size_type max_size()const{return this->final_max_size_();}std::pair<iterator,bool>insert(value_param_type x){;std::pair<final_node_type*,bool>p=this->final_insert_(x);return std::pair<iterator,bool>(make_iterator(p.first),p.second);}iterator insert(iterator position,value_param_type x){((void)0);;((void)0);;;std::pair<final_node_type*,bool>p=this->final_insert_(x,static_cast<final_node_type*>(position.get_node()));return make_iterator(p.first);}template<typename InputIterator>void insert(InputIterator first,InputIterator last){;iterator hint=end();for(;first!=last;++first)hint=insert(hint,*first);}iterator erase(iterator position){((void)0);;((void)0);;((void)0);;;this->final_erase_(static_cast<final_node_type*>(position++.get_node()));return position;}size_type erase(key_param_type x){;std::pair<iterator,iterator>p=equal_range(x);size_type s=0;while(p.first!=p.second){p.first=erase(p.first);++s;}return s;}iterator erase(iterator first,iterator last){((void)0);;((void)0);;((void)0);;((void)0);;((void)0);;;while(first!=last){first=erase(first);}return first;}bool replace(iterator position,value_param_type x){((void)0);;((void)0);;((void)0);;;return this->final_replace_(x,static_cast<final_node_type*>(position.get_node()));}template<typename Modifier>bool modify(iterator position,Modifier mod){((void)0);;((void)0);;((void)0);;;return this->final_modify_(mod,static_cast<final_node_type*>(position.get_node()));}template<typename Modifier>bool modify_key(iterator position,Modifier mod){((void)0);;((void)0);;((void)0);;;return modify(position,modify_key_adaptor<Modifier,value_type,KeyFromValue>(mod,key));}void swap(ordered_index<KeyFromValue,Compare,SuperMeta,TagList,Category>&x){;this->final_swap_(x.final());}void clear(){;this->final_clear_();}key_from_value key_extractor()const{return key;}key_compare key_comp()const{return comp;}value_compare value_comp()const{return value_compare(key,comp);}template<typename CompatibleKey>iterator find(const CompatibleKey&x)const{return make_iterator(ordered_index_find(header(),key,x,comp));}template<typename CompatibleKey,typename CompatibleCompare>iterator find(const CompatibleKey&x,const CompatibleCompare&comp)const{return make_iterator(ordered_index_find(header(),key,x,comp));}template<typename CompatibleKey>size_type count(const CompatibleKey&x)const{return count(x,comp);}template<typename CompatibleKey,typename CompatibleCompare>size_type count(const CompatibleKey&x,const CompatibleCompare&comp)const{std::pair<iterator,iterator>p=equal_range(x,comp);size_type n=std::distance(p.first,p.second);return n;}template<typename CompatibleKey>iterator lower_bound(const CompatibleKey&x)const{return make_iterator(ordered_index_lower_bound(header(),key,x,comp));}template<typename CompatibleKey,typename CompatibleCompare>iterator lower_bound(const CompatibleKey&x,const CompatibleCompare&comp)const{return make_iterator(ordered_index_lower_bound(header(),key,x,comp));}template<typename CompatibleKey>iterator upper_bound(const CompatibleKey&x)const{return make_iterator(ordered_index_upper_bound(header(),key,x,comp));}template<typename CompatibleKey,typename CompatibleCompare>iterator upper_bound(const CompatibleKey&x,const CompatibleCompare&comp)const{return make_iterator(ordered_index_upper_bound(header(),key,x,comp));}template<typename CompatibleKey>std::pair<iterator,iterator>equal_range(const CompatibleKey&x)const{return equal_range(x,comp);}template<typename CompatibleKey,typename CompatibleCompare>std::pair<iterator,iterator>equal_range(const CompatibleKey&x,const CompatibleCompare&comp)const{return std::pair<iterator,iterator>(lower_bound(x,comp),upper_bound(x,comp));}template<typename LowerBounder,typename UpperBounder>std::pair<iterator,iterator>range(LowerBounder lower,UpperBounder upper)const{std::pair<iterator,iterator>p(lower_range(lower),upper_range(upper));if(p.second!=end()&&(p.first==end()||comp(key(*p.second),key(*p.first)))){p.second=p.first;}return p;}protected:ordered_index(const ctor_args_list&args_list,const allocator_type&al):super(args_list.get_tail(),al),key(tuples::get<0>(args_list.get_head())),comp(tuples::get<1>(args_list.get_head())){empty_initialize();}ordered_index(const ordered_index<KeyFromValue,Compare,SuperMeta,TagList,Category>&x):super(x),key(x.key),comp(x.comp){}~ordered_index(){}iterator make_iterator(node_type*node){return iterator(node);}const_iterator make_iterator(node_type*node)const{return const_iterator(node);}void copy_(const ordered_index<KeyFromValue,Compare,SuperMeta,TagList,Category>&x,const copy_map_type&map){if(!x.root()){empty_initialize();}else{header()->color()=x.header()->color();node_type*root_cpy=map.find(static_cast<final_node_type*>(x.root()));header()->parent()=root_cpy->impl();node_type*leftmost_cpy=map.find(static_cast<final_node_type*>(x.leftmost()));header()->left()=leftmost_cpy->impl();node_type*rightmost_cpy=map.find(static_cast<final_node_type*>(x.rightmost()));header()->right()=rightmost_cpy->impl();typedef typename copy_map_type::const_iterator copy_map_iterator;for(copy_map_iterator it=map.begin(),it_end=map.end();it!=it_end;++it){node_type*org=it->first;node_type*cpy=it->second;cpy->color()=org->color();ordered_index_node_impl*parent_org=org->parent();if(!parent_org)cpy->parent()=0;else{node_type*parent_cpy=map.find(static_cast<final_node_type*>(node_type::from_impl(parent_org)));cpy->parent()=parent_cpy->impl();if(parent_org->left()==org->impl()){parent_cpy->left()=cpy->impl();}else if(parent_org->right()==org->impl()){parent_cpy->right()=cpy->impl();}}if(!org->left())cpy->left()=0;if(!org->right())cpy->right()=0;}}super::copy_(x,map);}node_type*insert_(value_param_type v,node_type*x){link_info inf;if(!link_point(key(v),inf,Category())){return node_type::from_impl(inf.pos);}node_type*res=static_cast<node_type*>(super::insert_(v,x));if(res==x){ordered_index_node_impl::link(x->impl(),inf.side,inf.pos,header()->impl());}return res;}node_type*insert_(value_param_type v,node_type*position,node_type*x){link_info inf;if(!hinted_link_point(key(v),position,inf,Category())){return node_type::from_impl(inf.pos);}node_type*res=static_cast<node_type*>(super::insert_(v,position,x));if(res==x){ordered_index_node_impl::link(x->impl(),inf.side,inf.pos,header()->impl());}return res;}void erase_(node_type*x){ordered_index_node_impl::rebalance_for_erase(x->impl(),header()->parent(),header()->left(),header()->right());super::erase_(x);}void delete_all_nodes_(){delete_all_nodes(root());}void clear_(){super::clear_();empty_initialize();}void swap_(ordered_index<KeyFromValue,Compare,SuperMeta,TagList,Category>&x){std::swap(key,x.key);std::swap(comp,x.comp);super::swap_(x);}bool replace_(value_param_type v,node_type*x){if(in_place(v,x,Category())){return super::replace_(v,x);}node_type*next=x;node_type::increment(next);ordered_index_node_impl::rebalance_for_erase(x->impl(),header()->parent(),header()->left(),header()->right());{try{link_info inf;if(link_point(key(v),inf,Category())&&super::replace_(v,x)){ordered_index_node_impl::link(x->impl(),inf.side,inf.pos,header()->impl());return true;}ordered_index_node_impl::restore(x->impl(),next->impl(),header()->impl());return false;}catch(...){ordered_index_node_impl::restore(x->impl(),next->impl(),header()->impl());throw;;}}}bool modify_(node_type*x){bool b;{try{b=in_place(x->value(),x,Category());}catch(...){erase_(x);throw;;}}if(!b){ordered_index_node_impl::rebalance_for_erase(x->impl(),header()->parent(),header()->left(),header()->right());{try{link_info inf;if(!link_point(key(x->value()),inf,Category())){super::erase_(x);return false;}ordered_index_node_impl::link(x->impl(),inf.side,inf.pos,header()->impl());}catch(...){super::erase_(x);throw;;}}}{try{if(!super::modify_(x)){ordered_index_node_impl::rebalance_for_erase(x->impl(),header()->parent(),header()->left(),header()->right());return false;}else return true;}catch(...){ordered_index_node_impl::rebalance_for_erase(x->impl(),header()->parent(),header()->left(),header()->right());throw;;}}}private:node_type*header()const{return this->final_header();}node_type*root()const{return node_type::from_impl(header()->parent());}node_type*leftmost()const{return node_type::from_impl(header()->left());}node_type*rightmost()const{return node_type::from_impl(header()->right());}void empty_initialize(){header()->color()=red;header()->parent()=0;header()->left()=header()->impl();header()->right()=header()->impl();}struct link_info{ordered_index_side side;ordered_index_node_impl*pos;};bool link_point(key_param_type k,link_info&inf,ordered_unique_tag){node_type*y=header();node_type*x=root();bool c=true;while(x){y=x;c=comp(k,key(x->value()));x=node_type::from_impl(c?x->left():x->right());}node_type*yy=y;if(c){if(yy==leftmost()){inf.side=to_left;inf.pos=y->impl();return true;}else node_type::decrement(yy);}if(comp(key(yy->value()),k)){inf.side=c?to_left:to_right;inf.pos=y->impl();return true;}else{inf.pos=yy->impl();return false;}}bool link_point(key_param_type k,link_info&inf,ordered_non_unique_tag){node_type*y=header();node_type*x=root();bool c=true;while(x){y=x;c=comp(k,key(x->value()));x=node_type::from_impl(c?x->left():x->right());}inf.side=c?to_left:to_right;inf.pos=y->impl();return true;}bool hinted_link_point(key_param_type k,node_type*position,link_info&inf,ordered_unique_tag){if(position->impl()==header()->left()){if(size()>0&&comp(k,key(position->value()))){inf.side=to_left;inf.pos=position->impl();return true;}else return link_point(k,inf,ordered_unique_tag());}else if(position==header()){if(comp(key(rightmost()->value()),k)){inf.side=to_right;inf.pos=rightmost()->impl();return true;}else return link_point(k,inf,ordered_unique_tag());}else{node_type*before=position;node_type::decrement(before);if(comp(key(before->value()),k)&&comp(k,key(position->value()))){if(before->right()==0){inf.side=to_right;inf.pos=before->impl();return true;}else{inf.side=to_left;inf.pos=position->impl();return true;}}else return link_point(k,inf,ordered_unique_tag());}}bool hinted_link_point(key_param_type k,node_type*position,link_info&inf,ordered_non_unique_tag){if(position->impl()==header()->left()){if(size()>0&&!comp(key(position->value()),k)){inf.side=to_left;inf.pos=position->impl();return true;}else return link_point(k,inf,ordered_non_unique_tag());}else if(position==header()){if(!comp(k,key(rightmost()->value()))){inf.side=to_right;inf.pos=rightmost()->impl();return true;}else return link_point(k,inf,ordered_non_unique_tag());}else{node_type*before=position;node_type::decrement(before);if(!comp(k,key(before->value()))&&!comp(key(position->value()),k)){if(before->right()==0){inf.side=to_right;inf.pos=before->impl();return true;}else{inf.side=to_left;inf.pos=position->impl();return true;}}else return link_point(k,inf,ordered_non_unique_tag());}}void delete_all_nodes(node_type*x){if(!x)return;delete_all_nodes(node_type::from_impl(x->left()));delete_all_nodes(node_type::from_impl(x->right()));this->final_delete_node_(static_cast<final_node_type*>(x));}bool in_place(value_param_type v,node_type*x,ordered_unique_tag){node_type*y;if(x!=leftmost()){y=x;node_type::decrement(y);if(!comp(key(y->value()),key(v)))return false;}y=x;node_type::increment(y);return y==header()||comp(key(v),key(y->value()));}bool in_place(value_param_type v,node_type*x,ordered_non_unique_tag){node_type*y;if(x!=leftmost()){y=x;node_type::decrement(y);if(comp(key(v),key(y->value())))return false;}y=x;node_type::increment(y);return y==header()||!comp(key(y->value()),key(v));}template<typename LowerBounder>iterator lower_range(LowerBounder lower)const{node_type*y=header();node_type*z=root();while(z){if(lower(key(z->value()))){y=z;z=node_type::from_impl(z->left());}else z=node_type::from_impl(z->right());}return make_iterator(y);}iterator lower_range(unbounded_type)const{return begin();}template<typename UpperBounder>iterator upper_range(UpperBounder upper)const{node_type*y=header();node_type*z=root();while(z){if(!upper(key(z->value()))){y=z;z=node_type::from_impl(z->left());}else z=node_type::from_impl(z->right());}return make_iterator(y);}iterator upper_range(unbounded_type)const{return end();}key_from_value key;key_compare comp;};
template<typename KeyFromValue1,typename Compare1,typename SuperMeta1,typename TagList1,typename Category1,typename KeyFromValue2,typename Compare2,typename SuperMeta2,typename TagList2,typename Category2>bool operator==(const ordered_index<KeyFromValue1,Compare1,SuperMeta1,TagList1,Category1>&x,const ordered_index<KeyFromValue2,Compare2,SuperMeta2,TagList2,Category2>&y){return x.size()==y.size()&&std::equal(x.begin(),x.end(),y.begin());}
template<typename KeyFromValue1,typename Compare1,typename SuperMeta1,typename TagList1,typename Category1,typename KeyFromValue2,typename Compare2,typename SuperMeta2,typename TagList2,typename Category2>bool operator<(const ordered_index<KeyFromValue1,Compare1,SuperMeta1,TagList1,Category1>&x,const ordered_index<KeyFromValue2,Compare2,SuperMeta2,TagList2,Category2>&y){return std::lexicographical_compare(x.begin(),x.end(),y.begin(),y.end());}
template<typename KeyFromValue1,typename Compare1,typename SuperMeta1,typename TagList1,typename Category1,typename KeyFromValue2,typename Compare2,typename SuperMeta2,typename TagList2,typename Category2>bool operator!=(const ordered_index<KeyFromValue1,Compare1,SuperMeta1,TagList1,Category1>&x,const ordered_index<KeyFromValue2,Compare2,SuperMeta2,TagList2,Category2>&y){return!(x==y);}
template<typename KeyFromValue1,typename Compare1,typename SuperMeta1,typename TagList1,typename Category1,typename KeyFromValue2,typename Compare2,typename SuperMeta2,typename TagList2,typename Category2>bool operator>(const ordered_index<KeyFromValue1,Compare1,SuperMeta1,TagList1,Category1>&x,const ordered_index<KeyFromValue2,Compare2,SuperMeta2,TagList2,Category2>&y){return y<x;}
template<typename KeyFromValue1,typename Compare1,typename SuperMeta1,typename TagList1,typename Category1,typename KeyFromValue2,typename Compare2,typename SuperMeta2,typename TagList2,typename Category2>bool operator>=(const ordered_index<KeyFromValue1,Compare1,SuperMeta1,TagList1,Category1>&x,const ordered_index<KeyFromValue2,Compare2,SuperMeta2,TagList2,Category2>&y){return!(x<y);}
template<typename KeyFromValue1,typename Compare1,typename SuperMeta1,typename TagList1,typename Category1,typename KeyFromValue2,typename Compare2,typename SuperMeta2,typename TagList2,typename Category2>bool operator<=(const ordered_index<KeyFromValue1,Compare1,SuperMeta1,TagList1,Category1>&x,const ordered_index<KeyFromValue2,Compare2,SuperMeta2,TagList2,Category2>&y){return!(x>y);}
template<typename KeyFromValue,typename Compare,typename SuperMeta,typename TagList,typename Category>void swap(ordered_index<KeyFromValue,Compare,SuperMeta,TagList,Category>&x,ordered_index<KeyFromValue,Compare,SuperMeta,TagList,Category>&y){x.swap(y);}
}template<typename Arg1,typename Arg2,typename Arg3>struct ordered_unique;
template<typename Arg1,typename Arg2,typename Arg3>struct ordered_non_unique{typedef detail::ordered_index_args<Arg1,Arg2,Arg3>index_args;typedef typename index_args::tag_list_type::type tag_list_type;typedef typename index_args::key_from_value_type key_from_value_type;typedef typename index_args::compare_type compare_type;template<typename Super>struct node_class{typedef detail::ordered_index_node<Super>type;};template<typename SuperMeta>struct index_class{typedef detail::ordered_index<key_from_value_type,compare_type,SuperMeta,tag_list_type,detail::ordered_non_unique_tag>type;};};
namespace detail{struct hashed_index_node_impl{hashed_index_node_impl*&next(){return next_;}hashed_index_node_impl*next()const{return next_;}static void increment(hashed_index_node_impl*&x,hashed_index_node_impl*bbegin,hashed_index_node_impl*bbend){std::less_equal<hashed_index_node_impl*>leq;x=x->next();if(leq(bbegin,x)&&leq(x,bbend)){do{++x;}while(x->next()==x);x=x->next();}}static void link(hashed_index_node_impl*x,hashed_index_node_impl*pos){x->next()=pos->next();pos->next()=x;};static void unlink(hashed_index_node_impl*x){hashed_index_node_impl*y=x->next();while(y->next()!=x){y=y->next();}y->next()=x->next();}static hashed_index_node_impl*prev(hashed_index_node_impl*x){hashed_index_node_impl*y=x->next();while(y->next()!=x){y=y->next();}return y;}static void unlink_next(hashed_index_node_impl*x){x->next()=x->next()->next();}private:hashed_index_node_impl*next_;};
template<typename Super>struct hashed_index_node_trampoline:hashed_index_node_impl{};
template<typename Super>struct hashed_index_node:Super,hashed_index_node_trampoline<Super>{hashed_index_node_impl*impl(){return static_cast<impl_type*>(this);}const hashed_index_node_impl*impl()const{return static_cast<const impl_type*>(this);}static hashed_index_node*from_impl(hashed_index_node_impl*x){return static_cast<hashed_index_node*>(static_cast<impl_type*>(x));}static const hashed_index_node*from_impl(const hashed_index_node_impl*x){return static_cast<const hashed_index_node*>(static_cast<const impl_type*>(x));}static void increment(hashed_index_node*&x,hashed_index_node_impl*bbegin,hashed_index_node_impl*bend){hashed_index_node_impl*xi=x->impl();impl_type::increment(xi,bbegin,bend);x=from_impl(xi);}private:typedef hashed_index_node_trampoline<Super>impl_type;};
class bucket_array_base:private noncopyable{protected:inline static std::size_t next_prime(std::size_t n){static const std::size_t prime_list[]={53ul,97ul,193ul,389ul,769ul,1543ul,3079ul,6151ul,12289ul,24593ul,49157ul,98317ul,196613ul,393241ul,786433ul,1572869ul,3145739ul,6291469ul,12582917ul,25165843ul,50331653ul,100663319ul,201326611ul,402653189ul,805306457ul,1610612741ul,3221225473ul,4294967291ul};static const std::size_t prime_list_size=sizeof(prime_list)/sizeof(prime_list[0]);std::size_t const*bound=std::lower_bound(prime_list,prime_list+prime_list_size,n);if(bound==prime_list+prime_list_size)bound--;return*bound;}};
template<typename Allocator>class bucket_array:public bucket_array_base{public:bucket_array(const Allocator&al,hashed_index_node_impl*end_,std::size_t size):size_(bucket_array_base::next_prime(size)),spc(al,size_+1){clear();end()->next()=end_;end_->next()=end();}std::size_t size()const{return size_;}std::size_t position(std::size_t hash)const{return hash%size_;}hashed_index_node_impl*begin()const{return&buckets()[0];}hashed_index_node_impl*end()const{return&buckets()[size_];}hashed_index_node_impl*at(std::size_t n)const{return&buckets()[n];}std::size_t first_nonempty(std::size_t n)const{for(;;++n){hashed_index_node_impl*x=at(n);if(x->next()!=x)return n;}}void clear(){for(hashed_index_node_impl*x=begin(),*y=end();x!=y;++x)x->next()=x;}void swap(bucket_array&x){std::swap(size_,x.size_);spc.swap(x.spc);}private:std::size_t size_;auto_space<hashed_index_node_impl,Allocator>spc;hashed_index_node_impl*buckets()const{return spc.data();}};
template<typename Allocator>void swap(bucket_array<Allocator>&x,bucket_array<Allocator>&y){x.swap(y);}
template<typename Node,typename BucketArray,typename Derived=mpl::na>class hashed_index_iterator;
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
template<class It>inline std::size_t hash_range(It first,It last){std::size_t seed=0;for(;first!=last;++first){hash_combine(seed,*first);}return seed;}
template<class It>inline void hash_range(std::size_t&seed,It first,It last){for(;first!=last;++first){hash_combine(seed,*first);}}
template<class T,unsigned N>inline std::size_t hash_value(const T(&array)[N]){return hash_range(array,array+N);}
template<class T,unsigned N>inline std::size_t hash_value(T(&array)[N]){return hash_range(array,array+N);}
template<class Ch,class A>inline std::size_t hash_value(std::basic_string<Ch,std::char_traits<Ch>,A>const&v){return hash_range(v.begin(),v.end());}
inline std::size_t hash_value(float v){return boost::hash_detail::float_hash_value(v);}
inline std::size_t hash_value(double v){return boost::hash_detail::float_hash_value(v);}
inline std::size_t hash_value(long double v){return boost::hash_detail::float_hash_value(v);}
template<class A,class B>std::size_t hash_value(std::pair<A,B>const&v){std::size_t seed=0;hash_combine(seed,v.first);hash_combine(seed,v.second);return seed;}
template<class T,class A>std::size_t hash_value(std::vector<T,A>const&v){return hash_range(v.begin(),v.end());}
template<class T,class A>std::size_t hash_value(std::list<T,A>const&v){return hash_range(v.begin(),v.end());}
template<class T,class A>std::size_t hash_value(std::deque<T,A>const&v){return hash_range(v.begin(),v.end());}
template<class K,class C,class A>std::size_t hash_value(std::set<K,C,A>const&v){return hash_range(v.begin(),v.end());}
template<class K,class C,class A>std::size_t hash_value(std::multiset<K,C,A>const&v){return hash_range(v.begin(),v.end());}
template<class K,class T,class C,class A>std::size_t hash_value(std::map<K,T,C,A>const&v){return hash_range(v.begin(),v.end());}
template<class K,class T,class C,class A>std::size_t hash_value(std::multimap<K,T,C,A>const&v){return hash_range(v.begin(),v.end());}
template<>struct hash<bool>;
template<>struct hash<char>;
template<>struct hash<signed char>;
template<>struct hash<unsigned char>;
template<>struct hash<wchar_t>;
template<>struct hash<short>;
template<>struct hash<unsigned short>;
template<>struct hash<int>;
template<>struct hash<unsigned int>;
template<>struct hash<long>;
template<>struct hash<unsigned long>;
template<>struct hash<float>;
template<>struct hash<double>;
template<>struct hash<long double>;
template<>struct hash<std::string>;
template<>struct hash<std::wstring>;
template<class T>struct hash<T*>:public std::unary_function<T*,std::size_t>{std::size_t operator()(T*v)const{return boost::hash_value(v);}};
template<class T>struct hash;
template<class T>struct hash;
namespace multi_index{namespace detail{template<typename KeyFromValue>struct index_args_default_hash{typedef::boost::hash<typename KeyFromValue::result_type>type;};
template<typename KeyFromValue>struct index_args_default_pred{typedef std::equal_to<typename KeyFromValue::result_type>type;};
template<typename Arg1,typename Arg2,typename Arg3,typename Arg4>struct hashed_index_args{typedef is_tag<Arg1>full_form;typedef typename mpl::if_<full_form,Arg1,tag<> >::type tag_list_type;typedef typename mpl::if_<full_form,Arg2,Arg1>::type key_from_value_type;typedef typename mpl::if_<full_form,Arg3,Arg2>::type supplied_hash_type;typedef typename mpl::eval_if<mpl::is_na<supplied_hash_type>,index_args_default_hash<key_from_value_type>,mpl::identity<supplied_hash_type> >::type hash_type;typedef typename mpl::if_<full_form,Arg4,Arg3>::type supplied_pred_type;typedef typename mpl::eval_if<mpl::is_na<supplied_pred_type>,index_args_default_pred<key_from_value_type>,mpl::identity<supplied_pred_type> >::type pred_type;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(is_tag<tag_list_type>::value)>)>boost_static_assert_typedef_41;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(!mpl::is_na<key_from_value_type>::value)>)>boost_static_assert_typedef_42;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(!mpl::is_na<hash_type>::value)>)>boost_static_assert_typedef_43;typedef::boost::static_assert_test<sizeof(::boost::STATIC_ASSERTION_FAILURE<(bool)(!mpl::is_na<pred_type>::value)>)>boost_static_assert_typedef_44;};
template<typename KeyFromValue,typename Hash,typename Pred,typename SuperMeta,typename TagList,typename Category>class hashed_index;
template<typename KeyFromValue,typename Hash,typename Pred,typename SuperMeta,typename TagList,typename Category>void swap(hashed_index<KeyFromValue,Hash,Pred,SuperMeta,TagList,Category>&x,hashed_index<KeyFromValue,Hash,Pred,SuperMeta,TagList,Category>&y);
}template<typename Arg1,typename Arg2=mpl::na,typename Arg3=mpl::na,typename Arg4=mpl::na>struct hashed_unique;
namespace detail{struct hashed_unique_tag{};
struct hashed_non_unique_tag{};
template<typename KeyFromValue,typename Hash,typename Pred,typename SuperMeta,typename TagList,typename Category>class hashed_index:protected SuperMeta::type{typedef typename SuperMeta::type super;protected:typedef hashed_index_node<typename super::node_type>node_type;typedef bucket_array<typename super::final_allocator_type>bucket_array_type;public:typedef typename KeyFromValue::result_type key_type;typedef typename node_type::value_type value_type;typedef KeyFromValue key_from_value;typedef Hash hasher;typedef Pred key_equal;typedef tuple<std::size_t,key_from_value,hasher,key_equal>ctor_args;typedef typename super::final_allocator_type allocator_type;typedef typename allocator_type::pointer pointer;typedef typename allocator_type::const_pointer const_pointer;typedef typename allocator_type::reference reference;typedef typename allocator_type::const_reference const_reference;typedef std::size_t size_type;typedef std::ptrdiff_t difference_type;typedef hashed_index_iterator<node_type,bucket_array_type>iterator;typedef iterator const_iterator;typedef iterator local_iterator;typedef const_iterator const_local_iterator;typedef TagList tag_list;protected:typedef typename super::final_node_type final_node_type;typedef tuples::cons<ctor_args,typename super::ctor_args_list>ctor_args_list;typedef typename mpl::push_front<typename super::index_type_list,hashed_index>::type index_type_list;typedef typename mpl::push_front<typename super::iterator_type_list,iterator>::type iterator_type_list;typedef typename mpl::push_front<typename super::const_iterator_type_list,const_iterator>::type const_iterator_type_list;typedef typename super::copy_map_type copy_map_type;private:typedef typename call_traits<value_type>::param_type value_param_type;typedef typename call_traits<key_type>::param_type key_param_type;public:hashed_index<KeyFromValue,Hash,Pred,SuperMeta,TagList,Category>&operator=(const hashed_index<KeyFromValue,Hash,Pred,SuperMeta,TagList,Category>&x){this->final()=x.final();return*this;}allocator_type get_allocator()const{return this->final().get_allocator();}bool empty()const{return this->final_empty_();}size_type size()const{return this->final_size_();}size_type max_size()const{return this->final_max_size_();}iterator begin(){return make_iterator(node_type::from_impl(buckets.at(first_bucket)->next()));}const_iterator begin()const{return make_iterator(node_type::from_impl(buckets.at(first_bucket)->next()));}iterator end(){return make_iterator(header());}const_iterator end()const{return make_iterator(header());}std::pair<iterator,bool>insert(value_param_type x){;std::pair<final_node_type*,bool>p=this->final_insert_(x);return std::pair<iterator,bool>(make_iterator(p.first),p.second);}iterator insert(iterator position,value_param_type x){((void)0);;((void)0);;;std::pair<final_node_type*,bool>p=this->final_insert_(x,static_cast<final_node_type*>(position.get_node()));return make_iterator(p.first);}template<typename InputIterator>void insert(InputIterator first,InputIterator last){;iterator hint=end();for(;first!=last;++first)hint=insert(hint,*first);}iterator erase(iterator position){((void)0);;((void)0);;((void)0);;;this->final_erase_(static_cast<final_node_type*>(position++.get_node()));return position;}size_type erase(key_param_type k){;size_type s=0;std::size_t buc=buckets.position(hash(k));hashed_index_node_impl*x=buckets.at(buc);hashed_index_node_impl*y=x->next();while(y!=x){if(eq(k,key(node_type::from_impl(y)->value()))){bool b;do{hashed_index_node_impl*z=y->next();b=z!=x&&eq(key(node_type::from_impl(y)->value()),key(node_type::from_impl(z)->value()));this->final_erase_(static_cast<final_node_type*>(node_type::from_impl(y)));y=z;++s;}while(b);break;}y=y->next();}return s;}iterator erase(iterator first,iterator last){((void)0);;((void)0);;((void)0);;((void)0);;((void)0);;;while(first!=last){first=erase(first);}return first;}bool replace(iterator position,value_param_type x){((void)0);;((void)0);;((void)0);;;return this->final_replace_(x,static_cast<final_node_type*>(position.get_node()));}template<typename Modifier>bool modify(iterator position,Modifier mod){((void)0);;((void)0);;((void)0);;;return this->final_modify_(mod,static_cast<final_node_type*>(position.get_node()));}template<typename Modifier>bool modify_key(iterator position,Modifier mod){((void)0);;((void)0);;((void)0);;;return modify(position,modify_key_adaptor<Modifier,value_type,KeyFromValue>(mod,key));}void clear(){;this->final_clear_();}void swap(hashed_index<KeyFromValue,Hash,Pred,SuperMeta,TagList,Category>&x){;this->final_swap_(x.final());}key_from_value key_extractor()const{return key;}hasher hash_function()const{return hash;}key_equal key_eq()const{return eq;}template<typename CompatibleKey>iterator find(const CompatibleKey&k)const{return find(k,hash,eq);}template<typename CompatibleKey,typename CompatibleHash,typename CompatiblePred>iterator find(const CompatibleKey&k,const CompatibleHash&hash,const CompatiblePred&eq)const{std::size_t buc=buckets.position(hash(k));hashed_index_node_impl*x=buckets.at(buc);hashed_index_node_impl*y=x->next();while(y!=x){if(eq(k,key(node_type::from_impl(y)->value()))){return make_iterator(node_type::from_impl(y));}y=y->next();}return end();}template<typename CompatibleKey>size_type count(const CompatibleKey&k)const{return count(k,hash,eq);}template<typename CompatibleKey,typename CompatibleHash,typename CompatiblePred>size_type count(const CompatibleKey&k,const CompatibleHash&hash,const CompatiblePred&eq)const{size_type res=0;std::size_t buc=buckets.position(hash(k));hashed_index_node_impl*x=buckets.at(buc);hashed_index_node_impl*y=x->next();while(y!=x){if(eq(k,key(node_type::from_impl(y)->value()))){do{++res;y=y->next();}while(y!=x&&eq(k,key(node_type::from_impl(y)->value())));break;}y=y->next();}return res;}template<typename CompatibleKey>std::pair<iterator,iterator>equal_range(const CompatibleKey&k)const{return equal_range(k,hash,eq);}template<typename CompatibleKey,typename CompatibleHash,typename CompatiblePred>std::pair<iterator,iterator>equal_range(const CompatibleKey&k,const CompatibleHash&hash,const CompatiblePred&eq)const{std::size_t buc=buckets.position(hash(k));hashed_index_node_impl*x=buckets.at(buc);hashed_index_node_impl*y=x->next();while(y!=x){if(eq(k,key(node_type::from_impl(y)->value()))){hashed_index_node_impl*y0=y;do{y=y->next();}while(y!=x&&eq(k,key(node_type::from_impl(y)->value())));if(y==x){do{++y;}while(y==y->next());y=y->next();}return std::pair<iterator,iterator>(make_iterator(node_type::from_impl(y0)),make_iterator(node_type::from_impl(y)));}y=y->next();}return std::pair<iterator,iterator>(end(),end());}size_type bucket_count()const{return buckets.size();}size_type max_bucket_count()const{return static_cast<size_type>(-1);}size_type bucket_size(size_type n)const{size_type res=0;hashed_index_node_impl*x=buckets.at(n);hashed_index_node_impl*y=x->next();while(y!=x){++res;y=y->next();}return res;}size_type bucket(key_param_type k)const{return buckets.position(hash(k));}local_iterator begin(size_type n){return const_cast<const hashed_index*>(this)->begin(n);}const_local_iterator begin(size_type n)const{hashed_index_node_impl*x=buckets.at(n);hashed_index_node_impl*y=x->next();if(y==x)return end();return make_iterator(node_type::from_impl(y));}local_iterator end(size_type n){return const_cast<const hashed_index*>(this)->end(n);}const_local_iterator end(size_type n)const{hashed_index_node_impl*x=buckets.at(n);if(x==x->next())return end();do{++x;}while(x==x->next());return make_iterator(node_type::from_impl(x->next()));}float load_factor()const{return static_cast<float>(size())/bucket_count();}float max_load_factor()const{return mlf;}void max_load_factor(float z){mlf=z;calculate_max_load();}void rehash(size_type n){;if(size()<max_load&&n<=bucket_count())return;size_type bc=(std::numeric_limits<size_type>::max)();float fbc=static_cast<float>(1+size()/mlf);if(bc>fbc){bc=static_cast<size_type>(fbc);if(bc<n)bc=n;}unchecked_rehash(bc);}protected:hashed_index(const ctor_args_list&args_list,const allocator_type&al):super(args_list.get_tail(),al),key(tuples::get<1>(args_list.get_head())),hash(tuples::get<2>(args_list.get_head())),eq(tuples::get<3>(args_list.get_head())),buckets(al,header()->impl(),tuples::get<0>(args_list.get_head())),mlf(1.0),first_bucket(buckets.size()){calculate_max_load();}hashed_index(const hashed_index<KeyFromValue,Hash,Pred,SuperMeta,TagList,Category>&x):super(x),key(x.key),hash(x.hash),eq(x.eq),buckets(x.get_allocator(),header()->impl(),x.buckets.size()),mlf(x.mlf),max_load(x.max_load),first_bucket(x.first_bucket){}~hashed_index(){}iterator make_iterator(node_type*node){return iterator(node,&buckets);}const_iterator make_iterator(node_type*node)const{return const_iterator(node,&const_cast<bucket_array_type&>(buckets));}void copy_(const hashed_index<KeyFromValue,Hash,Pred,SuperMeta,TagList,Category>&x,const copy_map_type&map){for(hashed_index_node_impl*begin_org=x.buckets.begin(),*begin_cpy=buckets.begin(),*end_org=x.buckets.end();begin_org!=end_org;++begin_org,++begin_cpy){hashed_index_node_impl*next_org=begin_org->next();hashed_index_node_impl*cpy=begin_cpy;while(next_org!=begin_org){cpy->next()=static_cast<node_type*>(map.find(static_cast<final_node_type*>(node_type::from_impl(next_org))))->impl();next_org=next_org->next();cpy=cpy->next();}cpy->next()=begin_cpy;}super::copy_(x,map);}node_type*insert_(value_param_type v,node_type*x){reserve(size()+1);std::size_t buc=find_bucket(v);hashed_index_node_impl*pos=buckets.at(buc);if(!link_point(v,pos,Category()))return node_type::from_impl(pos);node_type*res=static_cast<node_type*>(super::insert_(v,x));if(res==x){link(x,pos);if(first_bucket>buc)first_bucket=buc;}return res;}node_type*insert_(value_param_type v,node_type*position,node_type*x){reserve(size()+1);std::size_t buc=find_bucket(v);hashed_index_node_impl*pos=buckets.at(buc);if(!link_point(v,pos,Category()))return node_type::from_impl(pos);node_type*res=static_cast<node_type*>(super::insert_(v,position,x));if(res==x){link(x,pos);if(first_bucket>buc)first_bucket=buc;}return res;}void erase_(node_type*x){unlink(x);first_bucket=buckets.first_nonempty(first_bucket);super::erase_(x);}void delete_all_nodes_(){for(hashed_index_node_impl*x=buckets.begin(),*x_end=buckets.end();x!=x_end;++x){hashed_index_node_impl*y=x->next();while(y!=x){hashed_index_node_impl*z=y->next();this->final_delete_node_(static_cast<final_node_type*>(node_type::from_impl(y)));y=z;}}}void clear_(){super::clear_();buckets.clear();first_bucket=buckets.size();}void swap_(hashed_index<KeyFromValue,Hash,Pred,SuperMeta,TagList,Category>&x){std::swap(key,x.key);std::swap(hash,x.hash);std::swap(eq,x.eq);buckets.swap(x.buckets);std::swap(mlf,x.mlf);std::swap(max_load,x.max_load);std::swap(first_bucket,x.first_bucket);super::swap_(x);}bool replace_(value_param_type v,node_type*x){if(eq(key(v),key(x->value()))){return super::replace_(v,x);}hashed_index_node_impl*y=prev(x);unlink_next(y);{try{std::size_t buc=find_bucket(v);hashed_index_node_impl*pos=buckets.at(buc);if(link_point(v,pos,Category())&&super::replace_(v,x)){link(x,pos);if(first_bucket>buc){first_bucket=buc;}else if(first_bucket<buc){first_bucket=buckets.first_nonempty(first_bucket);}return true;}link(x,y);return false;}catch(...){link(x,y);throw;;}}}bool modify_(node_type*x){unlink(x);std::size_t buc;hashed_index_node_impl*pos;{try{buc=find_bucket(x->value());pos=buckets.at(buc);if(!link_point(x->value(),pos,Category())){first_bucket=buckets.first_nonempty(first_bucket);super::erase_(x);return false;}}catch(...){first_bucket=buckets.first_nonempty(first_bucket);super::erase_(x);throw;;}}{try{if(super::modify_(x)){link(x,pos);if(first_bucket>buc){first_bucket=buc;}else if(first_bucket<buc){first_bucket=buckets.first_nonempty(first_bucket);}return true;}first_bucket=buckets.first_nonempty(first_bucket);return false;}catch(...){first_bucket=buckets.first_nonempty(first_bucket);throw;;}}}private:node_type*header()const{return this->final_header();}std::size_t find_bucket(value_param_type v)const{return bucket(key(v));}bool link_point(value_param_type v,hashed_index_node_impl*&pos,hashed_unique_tag){hashed_index_node_impl*x=pos->next();while(x!=pos){if(eq(key(v),key(node_type::from_impl(x)->value()))){pos=x;return false;}x=x->next();}return true;}bool link_point(value_param_type v,hashed_index_node_impl*&pos,hashed_non_unique_tag){hashed_index_node_impl*prev=pos;hashed_index_node_impl*x=pos->next();while(x!=pos){if(eq(key(v),key(node_type::from_impl(x)->value()))){pos=prev;return true;}prev=x;x=x->next();}return true;}void link(node_type*x,hashed_index_node_impl*pos){hashed_index_node_impl::link(x->impl(),pos);};void link(hashed_index_node_impl*x,hashed_index_node_impl*pos){hashed_index_node_impl::link(x,pos);};void unlink(node_type*x){hashed_index_node_impl::unlink(x->impl());};static hashed_index_node_impl*prev(node_type*x){return hashed_index_node_impl::prev(x->impl());}static void unlink_next(hashed_index_node_impl*x){hashed_index_node_impl::unlink_next(x);}void calculate_max_load(){float fml=static_cast<float>(mlf*bucket_count());max_load=(std::numeric_limits<size_type>::max)();if(max_load>fml)max_load=static_cast<size_type>(fml);}void reserve(size_type n){if(n>max_load){size_type bc=(std::numeric_limits<size_type>::max)();float fbc=static_cast<float>(1+n/mlf);if(bc>fbc)bc=static_cast<size_type>(fbc);unchecked_rehash(bc);}}void unchecked_rehash(size_type n){bucket_array_type buckets1(get_allocator(),header()->impl(),n);auto_space<std::size_t,allocator_type>hashes(get_allocator(),size());std::size_t i=0;hashed_index_node_impl*x=buckets.begin();hashed_index_node_impl*x_end=buckets.end();for(;x!=x_end;++x){hashed_index_node_impl*y=x->next();while(y!=x){hashes.data()[i++]=hash(key(node_type::from_impl(y)->value()));y=y->next();}}i=0;x=buckets.begin();for(;x!=x_end;++x){hashed_index_node_impl*y=x->next();while(y!=x){hashed_index_node_impl*z=y->next();std::size_t buc1=buckets1.position(hashes.data()[i++]);hashed_index_node_impl*x1=buckets1.at(buc1);link(y,x1);y=z;}}buckets.swap(buckets1);calculate_max_load();first_bucket=buckets.first_nonempty(0);}key_from_value key;hasher hash;key_equal eq;bucket_array_type buckets;float mlf;size_type max_load;std::size_t first_bucket;};
template<typename KeyFromValue,typename Hash,typename Pred,typename SuperMeta,typename TagList,typename Category>void swap(hashed_index<KeyFromValue,Hash,Pred,SuperMeta,TagList,Category>&x,hashed_index<KeyFromValue,Hash,Pred,SuperMeta,TagList,Category>&y){x.swap(y);}
}template<typename Arg1,typename Arg2,typename Arg3,typename Arg4>struct hashed_unique{typedef typename detail::hashed_index_args<Arg1,Arg2,Arg3,Arg4>index_args;typedef typename index_args::tag_list_type::type tag_list_type;typedef typename index_args::key_from_value_type key_from_value_type;typedef typename index_args::hash_type hash_type;typedef typename index_args::pred_type pred_type;template<typename Super>struct node_class{typedef detail::hashed_index_node<Super>type;};template<typename SuperMeta>struct index_class{typedef detail::hashed_index<key_from_value_type,hash_type,pred_type,SuperMeta,tag_list_type,detail::hashed_unique_tag>type;};};
}template<class T>class reference_wrapper;
namespace multi_index{namespace detail{template<class Class,typename Type,Type Class::*PtrToMember>struct const_member_base;
template<class Class,typename Type,Type Class::*PtrToMember>struct non_const_member_base{typedef Type result_type;template<typename ChainedPtr>typename disable_if<is_convertible<const ChainedPtr&,const Class&>,Type&>::type operator()(const ChainedPtr&x)const{return operator()(*x);}const Type&operator()(const Class&x,int=0)const{return x.*PtrToMember;}Type&operator()(Class&x)const{return x.*PtrToMember;}const Type&operator()(const reference_wrapper<const Class>&x,int=0)const{return operator()(x.get());}Type&operator()(const reference_wrapper<Class>&x)const{return operator()(x.get());}};
}template<class Class,typename Type,Type Class::*PtrToMember>struct member:mpl::if_c<is_const<Type>::value,detail::const_member_base<Class,Type,PtrToMember>,detail::non_const_member_base<Class,Type,PtrToMember> >::type{};
}template<class E>inline void throw_exception(E const&e){throw e;}
class bad_weak_ptr:public std::exception{public:virtual char const*what()const throw(){return"tr1::bad_weak_ptr";}};
namespace detail{class sp_counted_base{private:sp_counted_base(sp_counted_base const&);sp_counted_base&operator=(sp_counted_base const&);long use_count_;long weak_count_;public:sp_counted_base():use_count_(1),weak_count_(1){}virtual~sp_counted_base(){}virtual void dispose()=0;virtual void destroy(){delete this;}virtual void*get_deleter(std::type_info const&ti)=0;void add_ref_copy(){_InterlockedIncrement(&use_count_);}bool add_ref_lock(){for(;;){long tmp=static_cast<long const volatile&>(use_count_);if(tmp==0)return false;if(_InterlockedCompareExchange(&use_count_,tmp+1,tmp)==tmp)return true;}}void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}void weak_add_ref(){_InterlockedIncrement(&weak_count_);}void weak_release(){if(_InterlockedDecrement(&weak_count_)==0){destroy();}}long use_count()const{return static_cast<long const volatile&>(use_count_);}};
template<class X>class sp_counted_impl_p;
template<class P,class D>class sp_counted_impl_pd;
template<class P,class D,class A>class sp_counted_impl_pda;
class weak_count;
class shared_count{private:sp_counted_base*pi_;friend class weak_count;public:shared_count():pi_(0){}template<class Y>explicit shared_count(Y*p):pi_(0){try{pi_=new sp_counted_impl_p<Y>(p);}catch(...){boost::checked_delete(p);throw;}}template<class P,class D>shared_count(P p,D d):pi_(0){try{pi_=new sp_counted_impl_pd<P,D>(p,d);}catch(...){d(p);throw;}}template<class P,class D,class A>shared_count(P p,D d,A a):pi_(0){typedef sp_counted_impl_pda<P,D,A>impl_type;typedef typename A::template rebind<impl_type>::other A2;A2 a2(a);try{pi_=a2.allocate(1,static_cast<impl_type*>(0));new(static_cast<void*>(pi_))impl_type(p,d,a);}catch(...){d(p);if(pi_!=0){a2.deallocate(static_cast<impl_type*>(pi_),1);}throw;}}template<class Y>explicit shared_count(std::auto_ptr<Y>&r):pi_(new sp_counted_impl_p<Y>(r.get())){r.release();}~shared_count(){if(pi_!=0)pi_->release();}shared_count(shared_count const&r):pi_(r.pi_){if(pi_!=0)pi_->add_ref_copy();}explicit shared_count(weak_count const&r);shared_count&operator=(shared_count const&r){sp_counted_base*tmp=r.pi_;if(tmp!=pi_){if(tmp!=0)tmp->add_ref_copy();if(pi_!=0)pi_->release();pi_=tmp;}return*this;}void swap(shared_count&r){sp_counted_base*tmp=r.pi_;r.pi_=pi_;pi_=tmp;}long use_count()const{return pi_!=0?pi_->use_count():0;}bool unique()const{return use_count()==1;}friend inline bool operator==(shared_count const&a,shared_count const&b){return a.pi_==b.pi_;}friend inline bool operator<(shared_count const&a,shared_count const&b){return std::less<sp_counted_base*>()(a.pi_,b.pi_);}void*get_deleter(std::type_info const&ti)const{return pi_?pi_->get_deleter(ti):0;}};
class weak_count{private:sp_counted_base*pi_;friend class shared_count;public:weak_count():pi_(0){}weak_count(shared_count const&r):pi_(r.pi_){if(pi_!=0)pi_->weak_add_ref();}weak_count(weak_count const&r):pi_(r.pi_){if(pi_!=0)pi_->weak_add_ref();}~weak_count(){if(pi_!=0)pi_->weak_release();}weak_count&operator=(shared_count const&r){sp_counted_base*tmp=r.pi_;if(tmp!=0)tmp->weak_add_ref();if(pi_!=0)pi_->weak_release();pi_=tmp;return*this;}weak_count&operator=(weak_count const&r){sp_counted_base*tmp=r.pi_;if(tmp!=0)tmp->weak_add_ref();if(pi_!=0)pi_->weak_release();pi_=tmp;return*this;}void swap(weak_count&r){sp_counted_base*tmp=r.pi_;r.pi_=pi_;pi_=tmp;}long use_count()const{return pi_!=0?pi_->use_count():0;}friend inline bool operator==(weak_count const&a,weak_count const&b){return a.pi_==b.pi_;}friend inline bool operator<(weak_count const&a,weak_count const&b){return std::less<sp_counted_base*>()(a.pi_,b.pi_);}};
inline shared_count::shared_count(weak_count const&r):pi_(r.pi_){if(pi_==0||!pi_->add_ref_lock()){boost::throw_exception(boost::bad_weak_ptr());}}
}template<class T>class weak_ptr;
template<class T>class enable_shared_from_this;
namespace detail{struct static_cast_tag{};
struct const_cast_tag{};
struct dynamic_cast_tag{};
struct polymorphic_cast_tag{};
template<class T>struct shared_ptr_traits{typedef T&reference;};
template<>struct shared_ptr_traits<void>;
template<>struct shared_ptr_traits<void const>;
template<>struct shared_ptr_traits<void volatile>;
template<>struct shared_ptr_traits<void const volatile>;
template<class T,class Y>void sp_enable_shared_from_this(shared_count const&pn,boost::enable_shared_from_this<T>const*pe,Y const*px){if(pe!=0)pe->_internal_weak_this._internal_assign(const_cast<Y*>(px),pn);}
inline void sp_enable_shared_from_this(shared_count const&,...){}
template<class T,class R>struct sp_enable_if_auto_ptr;
template<class T,class R>struct sp_enable_if_auto_ptr<std::auto_ptr<T>,R>;
}template<class T>class shared_ptr{private:typedef shared_ptr<T>this_type;public:typedef T element_type;typedef T value_type;typedef T*pointer;typedef typename boost::detail::shared_ptr_traits<T>::reference reference;shared_ptr():px(0),pn(){}template<class Y>explicit shared_ptr(Y*p):px(p),pn(p){boost::detail::sp_enable_shared_from_this(pn,p,p);}template<class Y,class D>shared_ptr(Y*p,D d):px(p),pn(p,d){boost::detail::sp_enable_shared_from_this(pn,p,p);}template<class Y,class D,class A>shared_ptr(Y*p,D d,A a):px(p),pn(p,d,a){boost::detail::sp_enable_shared_from_this(pn,p,p);}template<class Y>explicit shared_ptr(weak_ptr<Y>const&r):pn(r.pn){px=r.px;}template<class Y>shared_ptr(shared_ptr<Y>const&r):px(r.px),pn(r.pn){}template<class Y>shared_ptr(shared_ptr<Y>const&r,boost::detail::static_cast_tag):px(static_cast<element_type*>(r.px)),pn(r.pn){}template<class Y>shared_ptr(shared_ptr<Y>const&r,boost::detail::const_cast_tag):px(const_cast<element_type*>(r.px)),pn(r.pn){}template<class Y>shared_ptr(shared_ptr<Y>const&r,boost::detail::dynamic_cast_tag):px(dynamic_cast<element_type*>(r.px)),pn(r.pn){if(px==0){pn=boost::detail::shared_count();}}template<class Y>shared_ptr(shared_ptr<Y>const&r,boost::detail::polymorphic_cast_tag):px(dynamic_cast<element_type*>(r.px)),pn(r.pn){if(px==0){boost::throw_exception(std::bad_cast());}}template<class Y>explicit shared_ptr(std::auto_ptr<Y>&r):px(r.get()),pn(){Y*tmp=r.get();pn=boost::detail::shared_count(r);boost::detail::sp_enable_shared_from_this(pn,tmp,tmp);}template<class Ap>explicit shared_ptr(Ap r,typename boost::detail::sp_enable_if_auto_ptr<Ap,int>::type=0):px(r.get()),pn(){typename Ap::element_type*tmp=r.get();pn=boost::detail::shared_count(r);boost::detail::sp_enable_shared_from_this(pn,tmp,tmp);}template<class Y>shared_ptr&operator=(shared_ptr<Y>const&r){px=r.px;pn=r.pn;return*this;}template<class Y>shared_ptr&operator=(std::auto_ptr<Y>&r){this_type(r).swap(*this);return*this;}template<class Ap>typename boost::detail::sp_enable_if_auto_ptr<Ap,shared_ptr&>::type operator=(Ap r){this_type(r).swap(*this);return*this;}void reset(){this_type().swap(*this);}template<class Y>void reset(Y*p){((void)0);this_type(p).swap(*this);}template<class Y,class D>void reset(Y*p,D d){this_type(p,d).swap(*this);}template<class Y,class D,class A>void reset(Y*p,D d,A a){this_type(p,d,a).swap(*this);}reference operator*()const{((void)0);return*px;}T*operator->()const{((void)0);return px;}T*get()const{return px;}typedef T*this_type::*unspecified_bool_type;operator unspecified_bool_type()const{return px==0?0:&this_type::px;}bool operator!()const{return px==0;}bool unique()const{return pn.unique();}long use_count()const{return pn.use_count();}void swap(shared_ptr<T>&other){std::swap(px,other.px);pn.swap(other.pn);}template<class Y>bool _internal_less(shared_ptr<Y>const&rhs)const{return pn<rhs.pn;}void*_internal_get_deleter(std::type_info const&ti)const{return pn.get_deleter(ti);}private:template<class Y>friend class shared_ptr;template<class Y>friend class weak_ptr;T*px;boost::detail::shared_count pn;};
template<class T,class U>inline bool operator==(shared_ptr<T>const&a,shared_ptr<U>const&b){return a.get()==b.get();}
template<class T,class U>inline bool operator!=(shared_ptr<T>const&a,shared_ptr<U>const&b){return a.get()!=b.get();}
template<class T,class U>inline bool operator<(shared_ptr<T>const&a,shared_ptr<U>const&b){return a._internal_less(b);}
template<class T>inline void swap(shared_ptr<T>&a,shared_ptr<T>&b){a.swap(b);}
template<class E,class T,class Y>std::basic_ostream<E,T>&operator<<(std::basic_ostream<E,T>&os,shared_ptr<Y>const&p){os<<p.get();return os;}
template<class D,class T>D*get_deleter(shared_ptr<T>const&p){return static_cast<D*>(p._internal_get_deleter(typeid(D)));}
template<int I>class arg{};
template<int I>bool operator==(arg<I>const&,arg<I>const&){return true;}
}namespace G3D{typedef short int16;
class Vector2int16{private:bool operator<(const Vector2int16&)const;bool operator>(const Vector2int16&)const;bool operator<=(const Vector2int16&)const;bool operator>=(const Vector2int16&)const;public:G3D::int16 x;G3D::int16 y;Vector2int16();Vector2int16(G3D::int16 _x,G3D::int16 _y);Vector2int16(const class Vector2&v);Vector2int16(class BinaryInput&bi);inline G3D::int16&operator[](int i);inline const G3D::int16&operator[](int i)const;inline bool operator==(const Vector2int16&rkVector)const;inline bool operator!=(const Vector2int16&rkVector)const;void serialize(class BinaryOutput&bo)const;void deserialize(class BinaryInput&bi);};
class Vector2;
class Vector3;
class Vector2{private:bool operator<(const Vector2&)const;bool operator>(const Vector2&)const;bool operator<=(const Vector2&)const;bool operator>=(const Vector2&)const;public:float x,y;Vector2();Vector2(class BinaryInput&b);Vector2(float x,float y);Vector2(float coordinate[2]);Vector2(double coordinate[2]);Vector2(const Vector2&rkVector);Vector2(const class Vector2int16&v);void serialize(class BinaryOutput&b)const;void deserialize(class BinaryInput&b);void serialize(class TextOutput&t)const;void deserialize(class TextInput&t);float&operator[](int i);const float&operator[](int i)const;operator float*();operator const float*()const;Vector2&operator=(const Vector2&rkVector);bool operator==(const Vector2&rkVector)const;bool operator!=(const Vector2&rkVector)const;Vector2 operator+(const Vector2&rkVector)const;Vector2 operator-(const Vector2&rkVector)const;Vector2 operator*(float fScalar)const;Vector2 operator*(const Vector2&rkVector)const;Vector2 operator/(const Vector2&rkVector)const;Vector2 operator/(float fScalar)const;Vector2 operator-()const;Vector2&operator+=(const Vector2&rkVector);Vector2&operator-=(const Vector2&rkVector);Vector2&operator*=(float fScalar);Vector2&operator/=(float fScalar);Vector2&operator*=(const Vector2&rkVector);Vector2&operator/=(const Vector2&rkVector);static const Vector2 ZERO;static const Vector2 UNIT_S;static const Vector2 UNIT_T;};



























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
class Vector2int16;
class Vector3;
class Vector3int16;
class CoordinateFrame{public:Matrix3 rotation;Vector3 translation;static const float zLookDirection;inline CoordinateFrame();CoordinateFrame(class BinaryInput&b);void deserialize(class BinaryInput&b);void serialize(class BinaryOutput&b)const;CoordinateFrame(const CoordinateFrame&other);inline~CoordinateFrame(){}class Matrix4 toMatrix4()const;class Ray toObjectSpace(const Ray&r)const;class Box toWorldSpace(const class AABox&b)const;class Box toWorldSpace(const class Box&b)const;class Cylinder toWorldSpace(const class Cylinder&b)const;class Capsule toWorldSpace(const class Capsule&b)const;class Plane toWorldSpace(const class Plane&p)const;class Sphere toWorldSpace(const class Sphere&b)const;class Triangle toWorldSpace(const class Triangle&t)const;class Box toObjectSpace(const AABox&b)const;class Box toObjectSpace(const Box&b)const;class Plane toObjectSpace(const Plane&p)const;class Sphere toObjectSpace(const Sphere&b)const;class Ray lookRay()const;};
}namespace RakNet{class BitStream;
}typedef unsigned short SystemIndex;
typedef unsigned int RakNetTime;
struct SocketDescriptor{SocketDescriptor();SocketDescriptor(unsigned short _port,const char*_hostAddress);unsigned short port;char hostAddress[32];};
struct SystemAddress{unsigned int binaryAddress;unsigned short port;SystemAddress&operator=(const SystemAddress&input);bool operator==(const SystemAddress&right)const;bool operator!=(const SystemAddress&right)const;bool operator>(const SystemAddress&right)const;bool operator<(const SystemAddress&right)const;};
struct NetworkID{static bool peerToPeerMode;SystemAddress systemAddress;unsigned short localSystemAddress;NetworkID&operator=(const NetworkID&input);bool operator==(const NetworkID&right)const;bool operator!=(const NetworkID&right)const;bool operator>(const NetworkID&right)const;bool operator<(const NetworkID&right)const;};
struct Packet{SystemIndex systemIndex;SystemAddress systemAddress;unsigned int length;unsigned int bitSize;unsigned char*data;bool deleteData;};
class RakPeerInterface;
struct RPCParameters{unsigned char*input;unsigned int numberOfBitsOfData;SystemAddress sender;RakPeerInterface*recipient;RakNetTime remoteTimestamp;char*functionName;RakNet::BitStream*replyToSender;};
const SystemAddress UNASSIGNED_SYSTEM_ADDRESS={0xFFFFFFFF,0xFFFF};
namespace RakNet{class BitStream{public:BitStream();BitStream(int initialBytesToAllocate);BitStream(unsigned char*_data,unsigned int lengthInBytes,bool _copyData);~BitStream();void Reset(void);template<class templateType>bool Serialize(bool writeToBitstream,templateType&var);template<class templateType>bool SerializeDelta(bool writeToBitstream,templateType&currentValue,templateType lastValue);template<class templateType>bool SerializeDelta(bool writeToBitstream,templateType&currentValue);template<class templateType>bool SerializeCompressed(bool writeToBitstream,templateType&var);template<class templateType>bool SerializeCompressedDelta(bool writeToBitstream,templateType&currentValue,templateType lastValue);template<class templateType>bool SerializeCompressedDelta(bool writeToBitstream,templateType&currentValue);template<class templateType>bool SerializeNormVector(bool writeToBitstream,templateType&x,templateType&y,templateType&z);template<class templateType>bool SerializeVector(bool writeToBitstream,templateType&x,templateType&y,templateType&z);template<class templateType>bool SerializeNormQuat(bool writeToBitstream,templateType&w,templateType&x,templateType&y,templateType&z);template<class templateType>bool SerializeOrthMatrix(bool writeToBitstream,templateType&m00,templateType&m01,templateType&m02,templateType&m10,templateType&m11,templateType&m12,templateType&m20,templateType&m21,templateType&m22);template<class templateType>void Write(templateType var);template<class templateType>void WriteDelta(templateType currentValue,templateType lastValue);template<class templateType>void WriteDelta(templateType currentValue);template<class templateType>void WriteCompressed(templateType var);template<class templateType>void WriteCompressedDelta(templateType currentValue,templateType lastValue);template<class templateType>void WriteCompressedDelta(templateType currentValue);template<class templateType>bool Read(templateType&var);template<class templateType>bool ReadDelta(templateType&var);template<class templateType>bool ReadCompressed(templateType&var);template<class templateType>bool ReadCompressedDelta(templateType&var);template<class templateType>void WriteNormVector(templateType x,templateType y,templateType z);template<class templateType>void WriteVector(templateType x,templateType y,templateType z);template<class templateType>void WriteNormQuat(templateType w,templateType x,templateType y,templateType z);template<class templateType>void WriteOrthMatrix(templateType m00,templateType m01,templateType m02,templateType m10,templateType m11,templateType m12,templateType m20,templateType m21,templateType m22);template<class templateType>bool ReadNormVector(templateType&x,templateType&y,templateType&z);template<class templateType>bool ReadVector(templateType&x,templateType&y,templateType&z);template<class templateType>bool ReadNormQuat(templateType&w,templateType&x,templateType&y,templateType&z);template<class templateType>bool ReadOrthMatrix(templateType&m00,templateType&m01,templateType&m02,templateType&m10,templateType&m11,templateType&m12,templateType&m20,templateType&m21,templateType&m22);inline int GetNumberOfBytesUsed(void)const{return(((numberOfBitsUsed)+7)>>3);}private:BitStream(const BitStream&invalid);int numberOfBitsUsed;int numberOfBitsAllocated;int readOffset;unsigned char*data;bool copyData;unsigned char stackData[256];};




















































}enum PacketPriority{SYSTEM_PRIORITY,HIGH_PRIORITY,MEDIUM_PRIORITY,LOW_PRIORITY,NUMBER_OF_PRIORITIES};
enum PacketReliability{UNRELIABLE,UNRELIABLE_SEQUENCED,RELIABLE,RELIABLE_ORDERED,RELIABLE_SEQUENCED};
namespace RakNet{class BitStream;
}class NetworkIDManager;
class RakPeerInterface{public:virtual~RakPeerInterface();virtual bool Startup(unsigned short maxConnections,int _threadSleepTimer,SocketDescriptor*socketDescriptors,unsigned socketDescriptorCount)=0;virtual void InitializeSecurity(const char*pubKeyE,const char*pubKeyN,const char*privKeyP,const char*privKeyQ)=0;virtual void DisableSecurity(void)=0;virtual void SetMaximumIncomingConnections(unsigned short numberAllowed)=0;virtual unsigned short GetMaximumIncomingConnections(void)const=0;virtual unsigned short NumberOfConnections(void)const=0;virtual void SetIncomingPassword(const char*passwordData,int passwordDataLength)=0;virtual void GetIncomingPassword(char*passwordData,int*passwordDataLength)=0;virtual bool Connect(const char*host,unsigned short remotePort,const char*passwordData,int passwordDataLength,unsigned connectionSocketIndex=0)=0;virtual void Shutdown(unsigned int blockDuration,unsigned char orderingChannel=0)=0;virtual bool IsActive(void)const=0;virtual bool GetConnectionList(SystemAddress*remoteSystems,unsigned short*numberOfSystems)const=0;virtual bool Send(const char*data,const int length,PacketPriority priority,PacketReliability reliability,char orderingChannel,SystemAddress systemAddress,bool broadcast)=0;virtual bool Send(const RakNet::BitStream*bitStream,PacketPriority priority,PacketReliability reliability,char orderingChannel,SystemAddress systemAddress,bool broadcast)=0;virtual Packet*Receive(void)=0;virtual void DeallocatePacket(Packet*packet)=0;virtual unsigned short GetMaximumNumberOfPeers(void)const=0;virtual void RegisterAsRemoteProcedureCall(const char*uniqueID,void(*functionPointer)(RPCParameters*rpcParms))=0;virtual void RegisterClassMemberRPC(const char*uniqueID,void*functionPointer)=0;virtual void UnregisterAsRemoteProcedureCall(const char*uniqueID)=0;virtual void SetNetworkIDManager(NetworkIDManager*manager)=0;virtual NetworkIDManager*GetNetworkIDManager(void)const=0;virtual bool RPC(const char*uniqueID,const char*data,unsigned int bitLength,PacketPriority priority,PacketReliability reliability,char orderingChannel,SystemAddress systemAddress,bool broadcast,RakNetTime*includedTimestamp,NetworkID networkID,RakNet::BitStream*replyFromTarget)=0;virtual bool RPC(const char*uniqueID,const RakNet::BitStream*bitStream,PacketPriority priority,PacketReliability reliability,char orderingChannel,SystemAddress systemAddress,bool broadcast,RakNetTime*includedTimestamp,NetworkID networkID,RakNet::BitStream*replyFromTarget)=0;virtual void CloseConnection(const SystemAddress target,bool sendDisconnectionNotification,unsigned char orderingChannel=0)=0;virtual bool IsConnected(const SystemAddress systemAddress)=0;virtual int GetIndexFromSystemAddress(const SystemAddress systemAddress)=0;virtual SystemAddress GetSystemAddressFromIndex(int index)=0;virtual void AddToBanList(const char*IP,RakNetTime milliseconds=0)=0;virtual void RemoveFromBanList(const char*IP)=0;virtual void ClearBanList(void)=0;virtual bool IsBanned(const char*IP)=0;virtual void Ping(const SystemAddress target)=0;virtual void Ping(const char*host,unsigned short remotePort,bool onlyReplyOnAcceptingConnections,unsigned connectionSocketIndex=0)=0;virtual int GetAveragePing(const SystemAddress systemAddress)=0;virtual int GetLastPing(const SystemAddress systemAddress)const=0;virtual int GetLowestPing(const SystemAddress systemAddress)const=0;virtual void SetOccasionalPing(bool doPing)=0;virtual void SetOfflinePingResponse(const char*data,const unsigned int length)=0;virtual SystemAddress GetInternalID(const SystemAddress systemAddress=UNASSIGNED_SYSTEM_ADDRESS)const=0;virtual SystemAddress GetExternalID(const SystemAddress target)const=0;virtual void SetTimeoutTime(RakNetTime timeMS,const SystemAddress target)=0;virtual bool SetMTUSize(int size)=0;virtual int GetMTUSize(const SystemAddress target)const=0;};

namespace RBX {class PartInstance {public:const G3D::CoordinateFrame&getCoordinateFrame()const;};class Assembly;class Primitive {public:Assembly*getAssembly()const;};}
struct PhysicsNativeKeyValue {
 boost::shared_ptr<RBX::PartInstance>part;
 double key8;
 G3D::CoordinateFrame frame10;
 float value40;
 int key44;
 float value48;
 PhysicsNativeKeyValue(const PhysicsNativeKeyValue&);
};
struct PhysicsPartKey {typedef RBX::PartInstance*result_type;result_type operator()(const PhysicsNativeKeyValue&v)const{return v.part.get();}};
namespace bmi=boost::multi_index;
typedef boost::multi_index_container<PhysicsNativeKeyValue,bmi::indexed_by<
 bmi::hashed_unique<PhysicsPartKey>,
 bmi::ordered_non_unique<bmi::member<PhysicsNativeKeyValue,double,&PhysicsNativeKeyValue::key8>,std::greater<double> >,
 bmi::ordered_non_unique<bmi::member<PhysicsNativeKeyValue,int,&PhysicsNativeKeyValue::key44> >
> > PhysicsNativeKeys;
typedef PhysicsNativeKeys::nth_index<1>::type PhysicsKey8Index;
typedef PhysicsNativeKeys::nth_index<2>::type PhysicsKey44Index;
struct PhysicsNativeModifier {
 void(*function)(PhysicsNativeKeyValue&);boost::arg<1> argument;
 explicit PhysicsNativeModifier(void(*f)(PhysicsNativeKeyValue&)):function(f){}
 void operator()(PhysicsNativeKeyValue&v)const{function(v);}
};
namespace RBX {class Instance;namespace Network {
class IdSerializer {public:void serializeId(RakNet::BitStream&,const Instance*);};
class Replicator:public IdSerializer {};
class NetworkSettings {public:static NetworkSettings&singleton();};
class PhysicsSender {public:int sendPhysicsPackets(int);bool writePhysicsSnapshot(RakNet::BitStream&,const PhysicsNativeKeyValue&);};
}}
extern float nativePhysicsResetValue;
extern unsigned nativePhysicsTime();
template<class T>inline T&nativePhysicsField(void*p,unsigned off){return *reinterpret_cast<T*>(static_cast<char*>(p)+off);}
static void nativePhysicsReset(PhysicsNativeKeyValue&v){v.frame10=v.part->getCoordinateFrame();v.value40=nativePhysicsResetValue;v.key44=0;}
RakNet::BitStream&operator<<(RakNet::BitStream&,unsigned char);
RakNet::BitStream&operator<<(RakNet::BitStream&,unsigned);
int RBX::Network::PhysicsSender::sendPhysicsPackets(int maxPackets){
 PhysicsNativeKeys&records=nativePhysicsField<PhysicsNativeKeys>(this,4);
 PhysicsKey8Index&index=records.get<1>();
 PhysicsKey8Index::iterator&cursor=nativePhysicsField<PhysicsKey8Index::iterator>(this,0x38);
 Replicator*replicator=nativePhysicsField<Replicator*>(this,0x3c);
 unsigned maxBytes=nativePhysicsField<RakPeerInterface*>(replicator,0x2d50)->GetMTUSize(nativePhysicsField<SystemAddress>(replicator,0x2d54));
 maxBytes+=nativePhysicsField<int>(&NetworkSettings::singleton(),0x144);
 RakNet::BitStream packet(maxBytes);
 int packets=0;bool open=false;
 while(cursor!=index.end()){
  if(!open){
   if(packets>=maxPackets)break;
   packet.Reset();++packets;open=true;
   packet<<(unsigned char)24;packet<<nativePhysicsTime();packet<<(unsigned char)80;
  }
  PhysicsNativeKeyValue snapshot(*cursor);
  if(!writePhysicsSnapshot(packet,snapshot)){++cursor;continue;}
  if(nativePhysicsField<RBX::Primitive>(snapshot.part.get(),0x228).getAssembly()){
   snapshot.value40=nativePhysicsResetValue;
   snapshot.frame10=snapshot.part->getCoordinateFrame();
   index.modify(cursor,PhysicsNativeModifier(&nativePhysicsReset));
   ++cursor;
  }else cursor=index.erase(cursor);
  if((unsigned)packet.GetNumberOfBytesUsed()>maxBytes){
   nativePhysicsField<Replicator*>(this,0x3c)->serializeId(packet,0);
   Replicator*r=nativePhysicsField<Replicator*>(this,0x3c);
   nativePhysicsField<RakPeerInterface*>(r,0x2d50)->Send(&packet,MEDIUM_PRIORITY,RELIABLE_SEQUENCED,0,nativePhysicsField<SystemAddress>(r,0x2d54),false);
   open=false;
  }
 }
 if(open){
  nativePhysicsField<Replicator*>(this,0x3c)->serializeId(packet,0);
  Replicator*r=nativePhysicsField<Replicator*>(this,0x3c);
  nativePhysicsField<RakPeerInterface*>(r,0x2d50)->Send(&packet,MEDIUM_PRIORITY,RELIABLE_SEQUENCED,0,nativePhysicsField<SystemAddress>(r,0x2d54),false);
 }
 return packets;
}