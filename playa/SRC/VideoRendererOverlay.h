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

#ifndef VIDEORENDERER_OVERLAY_H
#define VIDEORENDERER_OVERLAY_H
#include <ddraw.h>
/*
 * Base Classes
 */

#include "MediaClasses.h"
#include "Resizer.h"

/*
 * DirectDraw includes
 *
 */



/*
 * Overlay Destination ColorKey
 */

#define DD_OVERLAY_COLORKEY_16BPP      0x00000001 // 16 bpp only
#define DD_OVERLAY_COLORKEY_32BPP      0x0000000F // 24 & 32 bpp
#define DD_OVERLAY_COLORREF            0x000F0000 // 32, 24, and 16 bpp

#define DD_OVERLAY_COLORKEY_FULLSCREEN 0x00000001 // 0x00000000 // 32, 24, and 16 bpp
#define DD_OVERLAY_COLORREF_FULLSCREEN 0x000F0000 // 0x00000000 // 32, 24, and 16 bpp


/*
 * Overlay VideoRenderer Class
 */

class MediaVideoRendererOverlay : public MediaItemVideoRenderer {

private:

	MediaItemSubtitler  *subtitler;
	MediaBuffer         *lastPicture;
	DWORD                invertFlag;

	LPDIRECTDRAW7        lpdd;
	LPDIRECTDRAWSURFACE7 lpddsPrimary;
	LPDIRECTDRAWCLIPPER  lpddClipper;
	LPDIRECTDRAWSURFACE7 lpddsOverlay;

	unsigned int         width;
	unsigned int         height;
	media_video_mode_t   videoMode;

	unsigned int         fullscreenWidth;
	unsigned int         fullscreenHeight;

	DWORD                bpp;
	DWORD                physicalDepth;

	RECT                 fullRects[3];
	HWND                 hwndPlayback;

public:

	MediaVideoRendererOverlay();
	~MediaVideoRendererOverlay();

	/*
	 * Media Item functions
	 */

	media_type_t  GetType();
	char         *GetName();

	MP_RESULT     Connect(MediaItem *item);
	MP_RESULT     ReleaseConnections();

	DWORD         GetCaps();
	MP_RESULT     Configure(HINSTANCE hInstance, HWND hwnd);

	/*
	 * Special Overlay Detection function
	 *
	 */

	BOOL      AreOverlaysSupported();

	/*
	 * Video Renderer Functions
	 */

	MP_RESULT Init(HWND hwnd, unsigned int width, unsigned int height);
	MP_RESULT InitFullscreen(HWND hwnd, unsigned int width, unsigned int height);

	media_video_mode_t GetVideoMode();
	MP_RESULT          Stop();
	RECT              *GetFullscreenRects(); 

	MP_RESULT Draw(MediaBuffer *buffer, RECT *rect, int frameNumber, int invertFlag);
	MP_RESULT DrawFullscreen(MediaBuffer *buffer, int frameNumber, int invertFlag, int desktopMode);

	MP_RESULT Close();
};

#endif