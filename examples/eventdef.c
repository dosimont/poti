/*
    This file is part of Poti

    Poti is free software: you can redistribute it and/or modify
    it under the terms of the GNU Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Poti is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Public License for more details.

    You should have received a copy of the GNU Public License
    along with Poti. If not, see <http://www.gnu.org/licenses/>.
*/
#include <poti.h>

/*
 * This example shows you how to define events with extra fields.
 * See the Paje file format documentation for the theory.
 */
int main (int argc, char **argv)
{
  //This is the way you do to declare a DefineContainerType
  //The first parameter is the type, one of these:
  /* PAJE_DefineContainerType, */
  /* PAJE_DefineVariableType, */
  /* PAJE_DefineStateType, */
  /* PAJE_DefineEventType, */
  /* PAJE_DefineLinkType, */
  /* PAJE_DefineEntityValue, */
  /* PAJE_CreateContainer, */
  /* PAJE_DestroyContainer, */
  /* PAJE_SetVariable, */
  /* PAJE_AddVariable, */
  /* PAJE_SubVariable, */
  /* PAJE_SetState, */
  /* PAJE_PushState, */
  /* PAJE_PopState, */
  /* PAJE_ResetState, */
  /* PAJE_StartLink, */
  /* PAJE_EndLink, */
  /* PAJE_NewEvent, */
  //The second parameter indicates a legacy header should be generated.
  //The third parameter indicates a header with alias (if necessary)
  //should be generated The last parameter indicates the number of
  //extra fields (in this case, 0).
  poti_set_alias (0);
  poti_init (stdout);
  poti_header_event (PAJE_DefineContainerType, 0, 0, 0);
  poti_header_event (PAJE_DefineStateType, 0, 0, 0);
  poti_header_event (PAJE_CreateContainer, 0, 0, 0);

  poti_DContainerType ("0", "PROCESS");
  poti_DStateType ("PROCESS", "STATE");
  poti_ECreateContainer (0, "PROCESS", "0", "p1");
  
  //Here we are generate three different events with extra fields
  int pushStateMark = poti_header_event (PAJE_PushState, 0, 0, 1, "Mark string");

  //Each of the above functions return the unique identifier of the
  //event definition.  This unique identifier should be then used in
  //the events section.

  //So, if you are handling with events with extra fields, you should
  //manage these unique identifiers yourself and raise events with
  //these function calls:
  poti_UPushState (pushStateMark, 0.32, "p1", "STATE", "Start", 1, "MyMark");
  return 0;
}
