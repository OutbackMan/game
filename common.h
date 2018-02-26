#ifndef __common_h__
#define __common_h__

#if __STDC_VERSION__ == 201112L
#define HAVE_C11
#endif

#ifndef HAVE_C11
#error "RGame requires a compiler with C11 capabilities."
#endif

#define 1D_ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))

// min, max, abs, setbit, clearbit, togglebit, getmsb, getlsb

// Other gcc macros

#endif
