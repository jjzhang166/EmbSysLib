//*******************************************************************
/*!
\file   devDigital.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _DEV_DIGITAL_H
#define _DEV_DIGITAL_H

//*******************************************************************
#include "Hardware/Common/Port.h"

//*******************************************************************
/*!
\class   cDevDigital

\brief   Access to a digital GPIO port pin

This class is an interface to digital I/O devices.

This class provides some usefull methods to read from or write to an
digital I/O port pin.
The methods \b isSet(), \b isClr(), \b isReleased(), \b isActivated() and
\b isChanged() use the state of the port pin which must be actualized
by calling the \b update() method.
Input and output of all methods are defined by a logical view (true or false).
The corresponding physical level (high or low) can be defined by constructor.

\example cDevDigital.cpp
*/
class cDevDigital
{
  public:
    //---------------------------------------------------------------
    /*! \enum Mode
        \brief Define the operating modes of a GPIO port pin
    */
    typedef enum
    {
      // Input modes
      In    = cHwPort::In,     //!< Input, floating
      InPU  = cHwPort::InPU,   //!< Input, pull-up
      InPD  = cHwPort::InPD,   //!< Input, pull-down

      // Output modes
      Out   = cHwPort::OutPP,  //!< Output, push-pull
      OutOD = cHwPort::OutOD,  //!< Output, open drain
      OutPU = cHwPort::OutPU,  //!< Output, open drain & pull-up
      OutPD = cHwPort::OutPD   //!< Output, open drain & pull-down
    } Mode;

  public:
    //---------------------------------------------------------------
    /*! Initialize a digital port pin
        \param port  Reference to the hardware object
        \param pinId Port pin number
        \param mode  Operating mode
        \param def   Default value: Corresponding physical value
                     (0: low, 1: high), when logical value is
                      false
    */
    cDevDigital( cHwPort &port,
                 BYTE     pinId,
                 Mode     mode,
                 bool     def = 0 );

  public:
   //---------------------------------------------------------------
   // Setter methods
   //---------------------------------------------------------------
    //---------------------------------------------------------------
   /*! Set pin mode (input/output, pull-up/down, ...)
       \param mode Operating mode
       \see cHwPort
    */
    virtual void setMode( Mode mode );

    //---------------------------------------------------------------
    /*! Set digital output
        \param value Logic level of digital output
    */
    virtual void set( bool value );

    //---------------------------------------------------------------
    /*! Set digital output to logic level 'true'
    */
    virtual void set( void )
    {
      set( 1 );
    }

    //---------------------------------------------------------------
    /*! Clear digital output to logic level 'false'
    */
    virtual void clr( void )
    {
      set( 0 );
    }

    //---------------------------------------------------------------
    /*! Invert digital output
    */
    virtual void toggle( void )
    {
      set( !valueOut );
    }

    //---------------------------------------------------------------
    // Getter methods
    //---------------------------------------------------------------
    //---------------------------------------------------------------
    /*! Get the input state
        \return Digital input state (logic level)
    */
    virtual bool get( void );

    //---------------------------------------------------------------
    /*! Read input state, which is used by edge detection.
        This method has to been called before using isSet(), isClr()
        isReleased(), isActivated() or isChanged()
    */
    virtual void update( void )
    {
      valueInLast = valueIn;
      valueIn     = get();
    }

    //---------------------------------------------------------------
    /*! Check, if digital value is set with last call to
        \b update().
        \return true, if input state is true
    */
    virtual bool isSet( void )
    {
      return( valueIn );
    }

    //---------------------------------------------------------------
    /*! Check, if digital value is cleared with last call to
        \b update().
        \return true, if input state is false
    */
    virtual bool isClr( void )
    {
      return( !valueIn );
    }

    //---------------------------------------------------------------
    /*! Check, if digital value has a falling edge (true -> false)
        with last call to \b update().
        \return true, if falling edge is detected
    */
    virtual bool isReleased( void )
    {
       return( !valueIn && valueInLast );
    }

    //---------------------------------------------------------------
    /*! Check, if digital value has a rising edge (false -> true)
        with last call to \b update().
        \return true, if rising edge is detected
    */
    virtual bool isActivated( void )
    {
       return( valueIn && !valueInLast );
    }

    //---------------------------------------------------------------
    /*! Check, if digital value is changed (rising/falling edge) with
        last call to \b update().
        \return true, if falling or rising edge is detected
    */
    virtual bool isChanged( void )
    {
       return( valueIn  != valueInLast );
    }

    //---------------------------------------------------------------
    // Operator
    //---------------------------------------------------------------
    //---------------------------------------------------------------
    /*! Set digital output
        \param value Logic level of digital output
        \return value
    */
    virtual bool operator=( bool value )
    {
      set( value );
      return( value );
    }

    //---------------------------------------------------------------
    /*! Set digital output
        \param x Reference to an object
        \return Logic input level
    */
    virtual bool operator=( cDevDigital &x)
    {
      set( x.get() );
      return( valueOut );
    }

    //---------------------------------------------------------------
    /*! Get the input state
        \return Digital input state (logic level)
    */
    virtual operator bool( void )
    {
      return( get() );
    }


  private:
    //---------------------------------------------------------------
    bool         valueInLast;
    bool         valueIn;
    bool         valueOut;
    bool         pinDefault;
    cHwPort::Pin pin;

}; //cDevDigital

#endif
