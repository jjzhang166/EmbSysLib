//*******************************************************************
/*!
\file   devDisplay.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   25.04.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _DEV_DISPLAY_H
#define _DEV_DISPLAY_H

//*******************************************************************
/*!
\class cDevDisplay

\brief Abstract class supporting character and graphic displays

\example cDevDisplayChar.cpp
*/
class cDevDisplay
{
  protected:
    //---------------------------------------------------------------
    // Initialize display
    //
    cDevDisplay( void );

  public:
    //---------------------------------------------------------------
    /*! Clear display
    */
    virtual void clear( void ) = 0;

}; //cDevDisplay

#endif
