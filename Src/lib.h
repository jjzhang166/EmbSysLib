//*******************************************************************
/*!
\file   lib.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.

\brief  Library main include file
*/

//*******************************************************************
#ifndef _LIB_H
#define _LIB_H

//*******************************************************************
// Hardware
//*******************************************************************
#include "Hardware/Hardware.h"

//*******************************************************************
// Std
//*******************************************************************
#include "Std/Std.h"
#include "Std/CRC.h"
#include "Std/List.h"
#include "Std/Fifo.h"
#include "Std/SharedMem.h"
#include "Std/DataPointer.h"
#include "Std/Timer.h"

//*******************************************************************
// Device
//*******************************************************************
#include "Device/Device.h"

//*******************************************************************
// Task
//*******************************************************************
#include "Task/TaskHandler.h"

#endif
