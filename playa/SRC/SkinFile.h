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

#ifndef _SKINFILE_H
#define _SKINFILE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

/*
 * Skin config file class
 */

class SkinFile {

private:

	FILE *configFile;

public:

	SkinFile(char *directory);
	~SkinFile();

	int  getColor(char *section);
	void Close();
};

#endif // _SKINFILE_H