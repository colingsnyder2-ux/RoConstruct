/**
 @file Image.h

  More flexible support than provided by G3D::GImage.

 @maintainer Morgan McGuire, morgan@cs.brown.edu
 @created 2004-10-10
 @edited  2004-10-10
 */
#ifndef G3D_IMAGE_H
#define G3D_IMAGE_H

#include <G3DAll.h>

/**
  Templated image.  There are two type parameters-- the first (@a T) is
  the type operated on by computation and the second (@ Storage) is the type 
  used to store the "pixel" values efficiently.  The T::T(Storage&) constructor
  is used to convert between storage and computation types.
  @a Storage is often an integer version of @a T, for example 
  <code>Image<double, uint8></code>.  By default, the storage type is the computation type.

  The computation type can be any that 
  supports lerp, +, -, *, /, and an empty constructor.

  Assign value:

    im(x, y) = 7;

  Read value:

    debugPrintf("%d", im(x, y));


  Can also sample with nearest neighbor, bilinear, and bicubic
  interpolation.  
  
  Sampling follows OpenGL conventions, where 
  pixel values represent grid points and (0.5, 0.5) is half-way
  between two vertical and two horizontal grid points.  
  To draw an image of dimensions w x h with nearest neighbor
  sampling, render pixels from [0, 0] to [w - 1, h - 1].

  Under the WRAP_CLAMP wrap mode, the value of bilinear interpolation
  becomes constant outside [1, w - 2] horizontally.  Nearest neighbor
  interpolation is constant outside [0, w - 1] and bicubic outside
  [3, w - 4].  The class does not offer quadratic interpolation because
  the interpolation filter could not center over a pixel.
  
  @author Morgan McGuire, morgan@cs.brown.edu
 */
template<class T, class Storage=T> class Image : public ReferenceCountedObject {
//
// It doesn't make sense to automatically convert from T back to S
// because the rounding rule (and scaling) is application dependent.
// Thus the interpolation methods all return type T.
//
public:

    /**
     WRAP_ERROR generates an out of bounds error when th
     */
    enum WrapMode {WRAP_CLAMP, WRAP_TILE, WRAP_ERROR};

private:

    /** Width, in pixels. */
    uint32              w;

    /** Height, in pixels. */
    uint32              h;

    /** The zero value.  Set by the constructor. */
    T                   ZERO;

    WrapMode            _wrapMode;

    Array<Storage>      data;

    /** Handles the exceptional cases from get */
    Storage& slowGet(int x, int y) {
        switch (_wrapMode) {
        case WRAP_CLAMP:
            return _get(iClamp(x, 0, w - 1), iClamp(y, 0, h - 1));

        case WRAP_TILE:
            return _get(iWrap(x, w), iWrap(y, h));

        case WRAP_ERROR:
            alwaysAssertM(((uint32)x < w) && ((uint32)y < h), 
                format("Index out of bounds: (%d, %d), w = %d, h = %d",
                x, y, w, h));

        default:
            {
                static Storage temp;
                return temp;
            }
        }
    }


    inline Storage& _get(int x, int y) {
        if (((uint32)x < w) && ((uint32)y < h)) {
            return data[x + y * w];
        } else {
            return slowGet(x, y);
        }
    }


    inline const Storage& _get(int x, int y) const {
        if (((uint32)x < w) && ((uint32)y < h)) {
            return data[x + y * w];
        } else {
            return const_cast<Image<T, Storage>*>(this)->slowGet(x, y);
        }
    }


    /** Given four control points and a value on the range [0, 1)
        evaluates the Catmull-rom spline between the times of the
        middle two control points */
    T bicubic(const T* ctrl, double s) const {

        // f = B * S * ctrl'

        // B matrix: Catmull-Rom spline basis
        static const double B[4][4] = {
            { 0.0, -0.5,  1.0, -0.5},
            { 1.0,  0.0, -2.5,  1.5},
            { 0.0,  0.5,  2.0, -1.5},
            { 0.0,  0.0, -0.5,  0.5}}; 

        // S: Powers of the fraction
        double S[4];
        double s2 = s * s;
        S[0] = 1.0;
        S[1] = s;
        S[2] = s2;
        S[3] = s2 * s;

        T sum = ZERO;
        for (int c = 0; c < 4; ++c) {
            double coeff = 0.0;
            for (int power = 0; power < 4; ++power) {
                coeff += B[c][power] * S[power];
            }
            sum += ctrl[c] * coeff;
        }

        return sum;
    }

    Image(int w, int h, WrapMode wrap) : _wrapMode(wrap) {
        resize(w, h);

        // Ensure that the zero value is zero.
        ZERO = ZERO * 0.0; 
    }

public:

    static ImageRef create(int w = 0, int h = 0, WrapMode wrap = WRAP_ERROR) {
        return new Image(w, h, wrap);
    }

    /** Resizes without clearing, leaving garbage.
      */
    void resize(uint32 newW, uint32 newH) {
        if (newW != w || newH != h) {
            w = newW;
            h = newH;
            data.resize(w * h);
        }
    }


    /** Returns a pointer to the underlying row-major data. Be careful-- 
        this will be reallocated during a resize. */
    Storage* getCArray() {
        return data.getCArray();
    }


    const Storage* getCArray() const {
        return data.getCArray();
    }


    /** Note that the type of image(x, y) is 
        the storage type (and can be assigned!), not the computation
        type.  If the constructor promoting Storage to T rescales values
        (as Color3(Color3uint8) does), this will not match the value
        returned by Image::nearest.*/
    Storage& operator()(int x, int y) {
        return _get(x, y);
    }

    const Storage& operator()(int x, int y) const {
        return _get(x, y);
    }


    /** Synonym for operator(), since that syntax is 
        frightening despite its convenience and some may wish
        to avoid it.*/
    const Storage& get(int x, int y) const {
        return _get(x, y)
    }

    void set(int x, int y, const Storage& v) {
        _get(x, y) = v;
    }


    void setAll(const Storage& v) {
        for(int i = 0; i < data.size(); ++i) {
            data[i] = v;
        }
    }


    /** Returns the nearest neighbor.  Pixel values are considered
        to be at the upper left corner. */
    T nearest(double x, double y) const {
        return T((*this)(iRound(x), iRound(y)));
    }


    /** 
      Needs to access elements from (floor(x), floor(y))
      to (floor(x) + 1, floor(y) + 1) and will use
      the wrap mode appropriately (possibly generating 
      out of bounds errors).
      Guaranteed to match nearest(x, y) at integers. */ 
    T bilinear(double x, double y) const {
        i = iFloor(x);
        j = iFloor(y);
    
        double fX = x - i;
        double fY = y - j;

        // Horizontal interpolation, first row
        T t0(get(i, j));
        T t1(get(i + 1, j));
        T A = lerp(t0, t1, fX);

        // Horizontal interpolation, second row
        T t2(get(i, j + 1));
        T t3(get(i + 1, j + 1));
        T B = lerp(t2, t3, fX);

        // Vertical interpolation
        return lerp(A, B, fY);
    }


    /**
     Uses Catmull-Rom splines to interpolate between grid
     values.  Guaranteed to match nearest(x, y) at integers.
     */
    T bicubic(double x, double y) const {
        int i = iFloor(x);
        int j = iFloor(y);
        double fX = x - i;
        double fY = y - j;

        // 'static' prevents constructors from being called
        // every time through this loop.
        static T vsample[4];
        for (int v = 0; v < 4; ++v) {

            // Horizontal interpolation
            static T hsample[4];
            for (int u = 0; u < 4; ++u) {
                hsample[u] = T((*this)(i + u - 1, j + v - 1));
            }
    
            vsample[v] = bicubic(hsample, fX);
        }

        //  Vertical interpolation
        return bicubic(vsample, fY);
    }


    /** Pixel width */
    inline uint32 width() const {
        return w;
    }


    /** Pixel height */
    inline uint32 height() const {
        return h;
    }


    /** Dimensions in pixels */
    Vector2int16 size() const {
        return Vector2int16(w, h);
    }


    /** Number of bytes occupied by the image data and this structure */
    size_t sizeInMemory() const {
        return data.size() * sizeof(Storage) + sizeof(*this);
    }


    WrapMode wrapMode() const {
        return _wrapMode;
    }


    void setWrapMode(WrapMode m) {
        _wrapMode = m;
    }
};

#endif // G3D_IMAGE_H
