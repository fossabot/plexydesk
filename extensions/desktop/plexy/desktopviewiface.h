/*******************************************************************************
* This file is part of PlexyDesk.
*  Maintained by : Siraj Razick <siraj@kde.org>
*  Authored By  :
*
*  PlexyDesk is free software: you can redistribute it and/or modify
*  it under the terms of the GNU Lesser General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  PlexyDesk is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU Lesser General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with PlexyDesk. If not, see <http://www.gnu.org/licenses/lgpl.html>
*******************************************************************************/
#ifndef PLEXY_DESKTOP_VIEW_I
#define PLEXY_DESKTOP_VIEW_I

#include <plexy.h>
#include <pluginloader.h>
#include <desktopviewplugininterface.h>

class DesktopViewInterface : public PlexyDesk::DesktopViewPluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PlexyDesk::DesktopViewPluginInterface)

public:
    virtual ~DesktopViewInterface();
    QSharedPointer<PlexyDesk::DesktopViewPlugin> view();
};

#endif
