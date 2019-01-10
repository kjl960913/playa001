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

#ifndef _SKINLIST_H
#define _SKINLIST_H

/*
 * Skin Info Class
 */


class SkinInfo {

public:

	char *directory;
	char *name;
	char *text;

	/*
	 * Creation and Data functions
	 */

	SkinInfo(char *directory);
	~SkinInfo();
};

/*
 * skinlist type
 */

typedef struct _skinlist_t {

	SkinInfo           *info;
	struct _skinlist_t *next;

} skinlist_t;

/*
 * SkinList Class
 */

class SkinList {

public:

	int          totalSkins;
	skinlist_t  *skins;
	char        *skinsDir;

	void Add(SkinInfo *skinInfo);

	SkinList();
	~SkinList();

	int Scan();
	int Reset();

	int SetDir(char *dir);

	int       getNumberOfSkins();
	SkinInfo *getSkinInfo(int position);
};

#endif // _SKINLIST_H