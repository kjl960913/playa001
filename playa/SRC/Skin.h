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

#ifndef _SKIN_H
#define _SKIN_H

#include "MediaPlayback.h"
#include "SkinList.h"
#include "SkinFile.h"
#include "Playa.h"

#include <windows.h>
#include <stdio.h>
#include "../build/win32/resource.h"

/*
 * Defines
 */

#define LOGO_WIDTH  265
#define LOGO_HEIGHT 160

/*
 * ENUMS for ACTIONS
 *
 */

enum {

	ACTION_NONE,
	ACTION_CLOSE,
	ACTION_MINIMIZE,
	ACTION_MENU,
	ACTION_REWIND,
	ACTION_STOP,
	ACTION_PLAY,
	ACTION_PAUSE,
	ACTION_FORWARD,
	ACTION_LOAD,
	ACTION_MOVING,
	ACTION_RESIZE,
	ACTION_VOLUME_BAR,
	ACTION_VOLUME_CURSOR,
	ACTION_PROGRESS_BAR,
	ACTION_PROGRESS_CURSOR
};

/*
 * Skin Class, load and 
 * display skin into window.
 *
 */

class Skin {

private:

	HWND    hwnd;

	HBITMAP skin;
	HBITMAP controls;
	HBITMAP logo;
	HBITMAP bottom;

	COLORREF skinColor;
	DWORD    compactMode;

	RECT    menuButton;
	RECT    minimizeButton;
	RECT    closeButton;
	RECT    rewindButton;
	RECT    stopButton;
	RECT    playButton;
	RECT    pauseButton;
	RECT    forwardButton;
	RECT    loadButton;
	RECT    resizeButton;

	RECT    progressBar;
	RECT    progressCursor;
	RECT    volumeBar;
	RECT    volumeCursor;

	RECT    videoRect;
		
	BOOL isInsideRect(int x, int y, RECT rect);

	int SetVolume(HWND hwnd, int volume);
	int SetProgress(HWND hwnd, double progress);

public:

	/*
	 * From 0 to 100
	 */

	int volume;
	double progress;

	Skin(HINSTANCE hIstance, HWND hwnd);
	~Skin();

	int   GetDefaultWidth();
	int   GetDefaultHeight();
	int   GetProgress();
	int   GetVolume();

	RECT *GetVideoRect();

	int   LoadDefault(HINSTANCE hInst, HWND hwnd);
	int   Load(char *directory, HWND hwnd);

	int   Display(HWND hwnd, MediaPlayback *playback);
	int   UpdateSize(HWND hwnd);

	int   SetVolumeCursorX(HWND hwnd, int x);
	int   SetProgressCursorX(HWND hwnd, int x);
	int   SetProgressValue(HWND hwnd, double progress);
	int   SetCompact(int compact);

	int   SetActionStart(HWND hwnd, int action);
	int   SetActionEnd(HWND hwnd, int action);

	int   DisplayFps(HWND hwnd, MediaPlayback *playback);
	int   DrawBufferingState(HWND hwnd, DWORD state);
	int   DrawTime(HWND hwnd, MediaPlayback *playback);

	int   GetAction(int x, int y);
};

#endif