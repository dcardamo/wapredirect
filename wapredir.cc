//----------------------------------------------------------------------------
// Copyright (C) Dan Cardamore
// Website: http://www.hld.ca/opensource/CVSWEB/index.cgi/wapredir/
// Author: Dan Cardamore <dan@hld.ca>
//  
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//  
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//  
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// This program allows you to detect if a user is browsing your site from an
// ordinary web browser like netscape or opera, or if they are using a cell
// phone.  Depeding on which, you can redirect them to different locations.
// Make sure to edit wapURL and htmlURL to suit your website.  Then run
// 'make' to rebuild the executable.
//----------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *wapURL = "http://www.hld.ca/index/";
char *htmlURL = "http://www.hld.ca/index/";

#define NUMAGENTS 2
char *agents[] = {
    "Phone",
    "UP"
};

int main(void)
{
    char *agent = getenv("HTTP_USER_AGENT");
    if (agent == NULL)
    {
        printf("Location: %s\n\n", htmlURL);
        exit(1);
    }
    
    for (int i = 0; i < NUMAGENTS; i++)
        if (strstr(agent, agents[i]) != NULL)
        {
            printf("Location: %s\n\n", wapURL);
            printf("Content-type: text/vnd.wap.wml\n\n");

            exit(0);
        }

    printf("Location: %s\n\n", htmlURL);
    return 0;
}
