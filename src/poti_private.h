/*
    This file is part of Poti

    Poti is free software: you can redistribute it and/or modify it
    under the terms of the GNU Lesser Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Poti is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser Public License for more details.

    You should have received a copy of the GNU Lesser Public License
    along with Poti. If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __POTI_PRIVATE_H__
#define __POTI_PRIVATE_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <poti.h>
#include <poti_config.h>

typedef int bool;
#define POTI_TRUE 1
#define POTI_FALSE 0
extern int *identifiers;
extern int poti_alias;
extern int disable_comments;
extern FILE *paje_file;
extern int paje_extended;

double paje_event_timestamp(double timestamp);
void _poti_header (int basic, int old_header);

#endif
