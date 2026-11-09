/*
 @file LightingParameters.cpp

 @maintainer Morgan McGuire, matrix@graphics3d.com
 @created 2002-10-05
 @edited  2006-06-28
 */

#include "GLG3D/LightingParameters.h"
#include "G3D/Matrix3.h"
#include "G3D/spline.h"
#include "G3D/GLight.h"
#include <sys/timeb.h>
#include <sys/types.h> 

#ifndef _MSC_VER
   #define _timeb timeb
   #define _ftime ftime
#endif
#ifdef _MSC_VER
#   pragma warning(push)
#   pragma warning(disable : 4305)
#endif

namespace G3D {

static const double sunRiseAndSetTime = HOUR / 2;
static const double solarYear = 365.2564*DAY;
static const double halfSolarYear = 182.6282;
static const double moonPhaseInterval = DAY*29.53;

// Tilt amount from the ecliptic
static const double earthTilt = toRadians(23.5);
static const double moonTilt = toRadians(5);

// (very rough) Initial star offset on Jan 1 1970 midnight
static const double initialStarRot = 1;

// Initial moon phase on Jan 1 1970 midnight
static const double initialMoonPhase = 0.75;

LightingParameters::LightingParameters() {
	physicallyCorrect = true;
	setLatitude(BROWN_UNIVERSITY_LATITUDE);
	setTime(0);
}


LightingParameters::LightingParameters(
    const GameTime              _time,
    bool 						_physicallyCorrect,
	float                       _latitude) {
	physicallyCorrect = _physicallyCorrect;
	setLatitude(_latitude);
	setTime(_time);
}

void LightingParameters::setLatitude(float _latitude) {
	geoLatitude = _latitude;
}

void LightingParameters::setTime(const GameTime _time) {
    // wrap to a 1 day interval
    double time = _time - floor(_time / DAY) * DAY;

    // Calculate starfield coordinate frame
    double starRot = initialStarRot - (2*G3D_PI*(_time - (_time*floor(_time / SIDEREAL_DAY)))/SIDEREAL_DAY);
    float aX, aY, aZ;
    starVec.x = cos(starRot);
    starVec.y = 0;
    starVec.z = sin(starRot);
    
    starFrame.lookAt(starVec, Vector3::unitY());
    trueStarFrame.lookAt(starVec, Vector3::unitY());
	trueStarFrame.rotation.toEulerAnglesXYZ(aX, aY, aZ);
    aX -= geoLatitude;
    trueStarFrame.rotation = Matrix3::fromEulerAnglesXYZ(aX, aY, aZ);
    
    // sunAngle = 0 at midnight
    float sourceAngle = 2 * (float)G3D_PI * time / DAY;
    
    // Calculate fake solar and lunar positions
    sunPosition.x = sin(sourceAngle);
    sunPosition.y = -cos(sourceAngle);
    sunPosition.z = 0;

    moonPosition.x = sin(sourceAngle + (float)G3D_PI);
    moonPosition.y = -cos(sourceAngle + (float)G3D_PI);
    moonPosition.z = 0;

    // Calculate "true" solar and lunar positions
    // These positions will always be somewhat wrong 
	// unless _time is equal to real world GMT time,
    // and the current longitude is equal to zero. Also, 
    // I'm assuming that the equinox-solstice interval 
	// occurs exactly every 90 days, which isn't exactly
	// correct.
	// In addition, the precession of the moon's orbit is
	// not taken into account, but this should only account
	// for a 5 degree margin of error at most.
    
	float dayOfYearOffset = (_time - (_time*floor(_time / solarYear)))/DAY;
    moonPhase = floor(_time / moonPhaseInterval) + initialMoonPhase;

	float latRad = toRadians(geoLatitude);
	float sunOffset = -earthTilt*cos(G3D_PI*(dayOfYearOffset-halfSolarYear)/halfSolarYear) - latRad;
	float moonOffset = ((-earthTilt+moonTilt)*sin(moonPhase*4)) - latRad;
	float curMoonPhase = (moonPhase*G3D_PI*2);

    Matrix3 rotMat = Matrix3::fromAxisAngle(Vector3::unitZ().cross(sunPosition), sunOffset);
    trueSunPosition = rotMat * sunPosition;
    
	Vector3 trueMoon = Vector3(sin(curMoonPhase + sourceAngle), 
			                   -cos(curMoonPhase + sourceAngle), 
							   0);
    rotMat = Matrix3::fromAxisAngle(Vector3::unitZ().cross(trueMoon), moonOffset);
	trueMoonPosition = rotMat * trueMoon;

    // Determine which light source we observe.
    if (!physicallyCorrect) {
        if ((sourceAngle < (G3D_PI / 2)) || (sourceAngle > (3 * G3D_PI / 2))) {
            source = MOON;
            sourceAngle += (float)G3D_PI;
        } else {
            source = SUN;
        }
 
        lightDirection.x = sin(sourceAngle);
        lightDirection.y = -cos(sourceAngle);
        lightDirection.z = 0;
    } else if (trueSunPosition.y > -.3f) {
	    // The sun is always the stronger light source. When using
	    // physically correct parameters, the sun and moon will
	    // occasionally be in the visible sky at the same time.
		source = SUN;
		lightDirection = trueSunPosition;
	} else {
		source = MOON;
		lightDirection = trueMoonPosition;
	}
    
    const Color3 dayAmbient = Color3::white() * .40f;
    const Color3 dayDiffuse = Color3::white() * .75f;

    {
        static const double times[] = {MIDNIGHT,               SUNRISE - HOUR,         SUNRISE,              SUNRISE + sunRiseAndSetTime / 4,  SUNRISE + sunRiseAndSetTime,    SUNSET - sunRiseAndSetTime,     SUNSET - sunRiseAndSetTime / 2, SUNSET,                SUNSET + HOUR/2,       DAY};
        static const Color3 color[] = {Color3(.2f, .2f, .2f),  Color3(.1f, .1, .1),    Color3(0,0,0),        Color3(.6, .6, 0),                dayDiffuse,                     dayDiffuse,                   Color3(.1, .1, .075),           Color3(.1, .05, .05),  Color3(.1, .1, .1), Color3(.2, .2, .2)};
        lightColor = linearSpline(time, times, color, 10);
    }

    {
        static const double times[] = {MIDNIGHT,               SUNRISE - HOUR,         SUNRISE,              SUNRISE + sunRiseAndSetTime / 4, SUNRISE + sunRiseAndSetTime, SUNSET - sunRiseAndSetTime,   SUNSET - sunRiseAndSetTime / 2, SUNSET,   SUNSET + HOUR/2,     DAY};
        static const Color3 color[] = {Color3(0, .1, .3),      Color3(0, .0, .1),      Color3(0,0,0),        Color3(0,0,0),                   dayAmbient,  dayAmbient,   Color3(.5, .2, .2),             Color3(.05, .05, .1),                     Color3(0, .0, .1),   Color3(0, .1, .3)};
        ambient = linearSpline(time, times, color, 10);
    }

    {
        static const double times[] = {MIDNIGHT,               SUNRISE - HOUR,         SUNRISE,              SUNRISE + sunRiseAndSetTime / 2, SUNRISE + sunRiseAndSetTime, SUNSET - sunRiseAndSetTime, SUNSET - sunRiseAndSetTime / 2, SUNSET,               SUNSET + HOUR/2, DAY};
        static const Color3 color[] = {Color3(.2, .2, .3),    Color3(.05, .06, .07),  Color3(.08, .08, .01),  Color3(1,1,1) *.75,              Color3(1,1,1) * .75,         Color3(1,1,1) * .35,        Color3(.5, .2, .2),             Color3(.05, .05, .1),   Color3(.06, .06, .07), Color3(.1, .1, .17)};
        diffuseAmbient = linearSpline(time, times, color, 10);
    }

    {
        static const double times[] = {MIDNIGHT,               SUNRISE - HOUR,         SUNRISE - HOUR/2,      SUNRISE,                       SUNRISE + sunRiseAndSetTime,  SUNSET - sunRiseAndSetTime, SUNSET,                  SUNSET + HOUR/3,     DAY};
        static const Color3 color[] = {Color3(0,0,0),          Color3(0,0,0),          Color3(.2, .15, .01),   Color3(.2, .15, .01),           Color3(1,1,1),                Color3(1,1,1),              Color3(.4, .2, .05),     Color3(0,0,0),       Color3(0,0,0)};
        skyAmbient = linearSpline(time, times, color, 8);
    }

    emissiveScale = Color3::white();
}


GLight LightingParameters::directionalLight() const {
    return GLight::directional(lightDirection, lightColor);
}

}

#ifdef _MSC_VER
#   pragma warning(pop)
#endif

