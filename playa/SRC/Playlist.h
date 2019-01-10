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


#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <windows.h>

/*
 * The playlist item struct
 *
 */

typedef struct playlist_item_s {

	char *filename;

} playlist_item_t;

typedef struct playlist_node_s {

	struct playlist_node_s *next;
	playlist_item_t         item;

} playlist_node_t;

/*
 * The playlist class
 *
 */

class Playlist {

private:

	DWORD            itemCount;
	DWORD            current;
	playlist_node_t *playlist;

public:

	Playlist();
	~Playlist();

	void             Reset();

	void             AddItem(char *filename);
	void             RemoveItemAt(DWORD i);
	
	void             NextItem();
	void             PreviousItem();

	DWORD            GetItemCount();
	playlist_item_t *GetItemAt(DWORD i);

	DWORD            GetCurrentPosition();
	playlist_item_t *GetCurrentItem();
	void             SetCurrentPosition(DWORD pos);
};


#endif // PLAYLIST_H