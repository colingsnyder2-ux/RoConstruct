// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast /arch:SSE2
// roc-lib: rbxgs-dll roc_claudeM_67d573bf4cce06ae.cpp

// Candidate translation unit (score above; library headers required).
#define NDEBUG 1
#include <assert.h>
#include <windows.h>
#include <GL/gl.h>
static void halve1Dimage_ubyte(GLint components, GLuint width, GLuint height,
			       const GLubyte *dataIn, GLubyte *dataOut,
			       GLint element_size, GLint ysize,
			       GLint group_size)
{
   GLint halfWidth= width / 2;
   GLint halfHeight= height / 2;
   const char *src= (const char *) dataIn;
   GLubyte *dest= dataOut;
   int jj;

   assert(width == 1 || height == 1); /* must be 1D */
   assert(width != height);	/* can't be square */

   if (height == 1) {		/* 1 row */
      assert(width != 1);	/* widthxheight can't be 1x1 */
      halfHeight= 1;

      for (jj= 0; jj< halfWidth; jj++) {
	 int kk;
	 for (kk= 0; kk< components; kk++) {
	    *dest= (*(const GLubyte*)src +
		 *(const GLubyte*)(src+group_size)) / 2;

	    src+= element_size;
	    dest++;
	 }
	 src+= group_size;	/* skip to next 2 */
      }
      {
	 int padBytes= ysize - (width*group_size);
	 src+= padBytes;	/* for assertion only */
      }
   }
   else if (width == 1) {	/* 1 column */
      int padBytes= ysize - (width * group_size);
      assert(height != 1);	/* widthxheight can't be 1x1 */
      halfWidth= 1;
      /* one vertical column with possible pad bytes per row */
      /* average two at a time */

      for (jj= 0; jj< halfHeight; jj++) {
	 int kk;
	 for (kk= 0; kk< components; kk++) {
	    *dest= (*(const GLubyte*)src + *(const GLubyte*)(src+ysize)) / 2;

	    src+= element_size;
	    dest++;
	 }
	 src+= padBytes; /* add pad bytes, if any, to get to end to row */
	 src+= ysize;
      }
   }

   assert(src == &((const char *)dataIn)[ysize*height]);
   assert((char *)dest == &((char *)dataOut)
	  [components * element_size * halfWidth * halfHeight]);
} /* halve1Dimage_ubyte() */

void halveImage_ubyte(GLint components, GLuint width, GLuint height,
			const GLubyte *datain, GLubyte *dataout,
			GLint element_size, GLint ysize, GLint group_size)
{
    int i, j, k;
    int newwidth, newheight;
    GLubyte *s;
    const char *t;

    /* handle case where there is only 1 column/row */
    if (width == 1 || height == 1) {
       assert( !(width == 1 && height == 1) ); /* can't be 1x1 */
       halve1Dimage_ubyte(components,width,height,datain,dataout,
			  element_size,ysize,group_size);
       return;
    }

    newwidth = width / 2;
    newheight = height / 2;
    s = dataout;
    t = (const char *)datain;

    /* Piece o' cake! */
    for (i = 0; i < newheight; i++) {
	for (j = 0; j < newwidth; j++) {
	    for (k = 0; k < components; k++) {
		s[0] = (*(const GLubyte*)t +
			*(const GLubyte*)(t+group_size) +
			*(const GLubyte*)(t+ysize) +
			*(const GLubyte*)(t+ysize+group_size) + 2) / 4;
		s++; t += element_size;
	    }
	    t += group_size;
	}
	t += ysize;
    }
}

/* */
