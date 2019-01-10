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
 * Authors: Damien Chavarria                                                          *
 *          DivX Advanced Research Center <darc at projectmayo.com>                   *
 *                                                                                    *
 **************************************************************************************/

#ifndef PLAYA_H
#define PLAYA_H

#include <windows.h>

/*
 * Type For options 
 *
 */

typedef enum {

	ASPECT_RATIO_FREE = 0,
	ASPECT_RATIO_ORIGINAL,
	ASPECT_RATIO_TV,
	ASPECT_RATIO_WIDE,
	ASPECT_RATIO_CUSTOM,

} aspect_ratio_t;


#define DEFAULT_SKIN_WIDTH  300 
#define DEFAULT_SKIN_HEIGHT 375

typedef struct _options_t {

	DWORD          loop; 
	DWORD          on_top;
	DWORD          use_bilinear;
	DWORD          change_fullscreen_res;
	aspect_ratio_t aspect_ratio;
	DWORD          disable_screen_saver;
	DWORD          save_pos;
	DWORD          posX;
	DWORD          posY;
	DWORD          postprocessing;
	DWORD          startFullscreen;

} options_t;

extern options_t options;

#endif // PLAYA_H