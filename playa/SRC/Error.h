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

#ifndef _ERROR_H
#define _ERROR_H

#include <windows.h>

/*
 * Basic return type
 */

typedef enum {

		MP_RESULT_OK,	
		MP_RESULT_ERROR,
	
} MP_RESULT;

/*
 * Macro for Error reporting
 * 
 */

#define MP_ERROR(A) { \
	MessageBox(GetForegroundWindow(), A, "Error", MB_OK | MB_ICONEXCLAMATION); \
}

#endif //_ERROR_H