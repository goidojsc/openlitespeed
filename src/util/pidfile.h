/*****************************************************************************
*    Open LiteSpeed is an open source HTTP server.                           *
*    Copyright (C) 2013 - 2015  LiteSpeed Technologies, Inc.                 *
*                                                                            *
*    This program is free software: you can redistribute it and/or modify    *
*    it under the terms of the GNU General Public License as published by    *
*    the Free Software Foundation, either version 3 of the License, or       *
*    (at your option) any later version.                                     *
*                                                                            *
*    This program is distributed in the hope that it will be useful,         *
*    but WITHOUT ANY WARRANTY; without even the implied warranty of          *
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the            *
*    GNU General Public License for more details.                            *
*                                                                            *
*    You should have received a copy of the GNU General Public License       *
*    along with this program. If not, see http://www.gnu.org/licenses/.      *
*****************************************************************************/
#ifndef PIDFILE_H
#define PIDFILE_H



#include <sys/stat.h>

class PidFile
{
    int             m_fdPid;
    struct stat     m_stPid;

public:

    PidFile();
    ~PidFile();
    int openPidFile(const char *pPidFile);
    int lockPidFile(const char *pPidFile);
    int writePidFile(const char *pPidFile, int pid);
    int writePid(int pid);
    void closePidFile();
    int testAndRelockPidFile(const char *pPidFile, int pid);
    int testAndRemovePidFile(const char *pPidFile);
};

#endif
