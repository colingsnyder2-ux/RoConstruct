#ifndef DECOMP_H
#define DECOMP_H

#ifndef NDEBUG
#undef ENABLE_DECOMP_ASSERTS
#endif

#if defined(ENABLE_DECOMP_ASSERTS)
#define DECOMP_STATIC_ASSERT(V)                                                                                        \
	namespace {                                                                                                        \
	typedef int foo[(V) ? 1 : -1];                                                                                     \
	}
#define DECOMP_SIZE_ASSERT(T, S) DECOMP_STATIC_ASSERT(sizeof(T) == S)
#else
#define DECOMP_STATIC_ASSERT(V)
#define DECOMP_SIZE_ASSERT(T, S)
#endif

#ifndef sizeOfArray
#define sizeOfArray(arr) (sizeof(arr) / sizeof(arr[0]))
#endif

typedef unsigned char undefined;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined4 g_foldingDummyVariable;

#define STUB(val)                                                                                                      \
	do {                                                                                                               \
		g_foldingDummyVariable = val;                                                                                  \
	} while (0)

#define MATCHING(val)                                                                                                  \
	do {                                                                                                               \
		g_foldingDummyVariable = val;                                                                                  \
	} while (0)

#endif // DECOMP_H
