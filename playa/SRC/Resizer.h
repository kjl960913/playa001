/**************************************************************************************
 *                                                                                    *
 * This application contains code from OpenDivX and is released as a "Larger Work"    *
 * under that license. Consistant with that license, this application is released     *
 * under the GNU General Public License.                                              *
 *                                                                                    *
 * The OpenDivX license can be found at: http://www.projectmayo.com/opendivx/docs.php *
 * The GPL can be found at: http://www.gnu.org/copyleft/gpl.html                      *
 *                                                                                    *
 * Copyright (c) 2001 - Project Mayo                                                  *
 *                                                                                    *
 * Authors: Damien Chavarria <adrc at projectmayo.com>                                *
 *                                                                                    *
 **************************************************************************************/

#ifndef _RESIZER_H
#define _RESIZER_H

#include "Playa.h"
#include <windows.h>

/*
 * The type for aspect ratio
 */

typedef struct aspect_ratio_factor_s {

	DWORD xFactor;
	DWORD yFactor;

} aspect_ratio_factors_t;

extern aspect_ratio_factors_t aspectRatios[];

/*
 * The class used to draw
 * the resize frame...
 *
 */

class Resizer {

private:

	POINT lastPt;
	POINT startPt;
	
	DWORD originalWidth;
	DWORD originalHeight;

	void DrawFree(HWND hwnd, POINT *pt1);
	void DrawOriginal(HWND hwnd, POINT *pt1);
	void DrawTV(HWND hwnd, POINT *pt1);
	void DrawWide(HWND hwnd, POINT *pt1);
	void DrawCustom(HWND hwnd, POINT *pt1);

public:

	Resizer();
	~Resizer();

	void Start(POINT *pt, DWORD originalWidth, DWORD originalHeight);
	
	void   Draw(HWND hwnd, POINT *pt, aspect_ratio_t aspectRatio);
	POINT *GetLastPoint();

	void Stop();
};

#endif