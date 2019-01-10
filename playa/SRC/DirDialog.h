////////////////////////////////////////////////////////////////////////
// DirDialog.h: interface for the CDirDialog class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _CDIR_H
#define _CDIR_H

#include <windows.h>


class CDirDialog
{
  public:
    CDirDialog();
    virtual ~CDirDialog();
    int DoBrowse();

    char *m_strPath;
    char *m_strInitDir;
    char *m_strSelDir;
    char *m_strTitle;
    
	int  m_iImageIndex;
};

#endif 


