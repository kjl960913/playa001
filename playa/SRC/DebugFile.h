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

/*
 * A 'Debug' Class
 *
 */

#ifndef DEBUG_FILE_H
#define DEBUG_FILE_H

#include <stdio.h>
#include <stdlib.h>

class DebugFile {

private:

	FILE *debugFile;


public:

	DebugFile(char *filename);
	~DebugFile();

	void DebugInt(char *text, int d);
	void DebugFloat(char *text, float d);
};

#endif