//*******************************************************************
/*!
\file   Module/IPC.h
\author Thomas Breuer
\date   11.12.2014, 17.03.2016  
*/

//*******************************************************************
#ifndef _IPC_H
#define _IPC_H

//*******************************************************************
#include "Std/CRC.h"

//*******************************************************************
/*!
\class cIPC

\brief IPC transport base class

This class is the base class for IPC transport objects. Derived 
classes use a communication port to transport IPC data objects.
A 16-bit CRC is used.

To create an IPC data object:
- Define an application specific class with POD subclass named \b 
  'Data'
- This class may have an \b update() method, which is called on 
  data receive
- Instantiate an object from the template class cIPC::Data. 
  The first template parameter is the name of the aplication 
  specific data class. 
  The second parameter must be an unique ID to identify data objects
  
\example cIPC.cpp
*/  
class cIPC
{
  protected:  
    //---------------------------------------------------------------
    class DataInterface : public cList::Item
    {
      public:
        //-----------------------------------------------------------
        virtual void update( void ) {}

      public:
        //-----------------------------------------------------------
        BYTE *dataRef;
        WORD  dataLength;
        BYTE  id;
    }; // cIPC::DataInterface
    //---------------------------------------------------------------

  public:
    //---------------------------------------------------------------
    /*! Template class for IPC data objects
        \param T Used data class
        \param ID Unique identifier
    */
    template <class T, BYTE ID> class Data : DataInterface
    {
      public:
        //-----------------------------------------------------------
        /*! Instantiate an IPC data object
            \param ipcIn Reference to an IPC. The instantiated object 
                         is bound to this IPC transport object 
        */
        Data( cIPC &ipcIn )
        : data( prop.data ),
          ipc ( ipcIn     ) 
          
        {
          dataRef    = (BYTE*)&prop.data;
          dataLength = sizeof( typename T::Data );
          id         = ID;
          flag       = false;
          ipc.list.add( this );
        }

        //-----------------------------------------------------------
        /*! Write an object
        
            The object is written with the IPC transport object 
            defined by Constructor
        */
        void write( void )
        {
          ipc.write( id, dataRef, dataLength );
        }

        //-----------------------------------------------------------
        /*! Ceck, if new data are received
        
            \return
                    - true, if new data are received
                    - false otherwise
        */
        BYTE isNew( void )
        {
          if( flag )
          {
            flag = false;
            return( true );
          }
          else
          {
            return( false );
          }
        }
        
      protected:
        //-----------------------------------------------------------
        virtual void update( void )
        {
          flag = true;
          prop.update();
        }

      public:
        //-----------------------------------------------------------
        typename T::Data &data;
        T                 prop;

      protected:
        //-----------------------------------------------------------
        cIPC  &ipc;
        BYTE   flag;

    }; // cIPC::Data
    //---------------------------------------------------------------

  protected:  
    //---------------------------------------------------------------
    cIPC( cCRC::MODE crcMode );

    //---------------------------------------------------------------
    virtual void update( void ) = 0;

    //---------------------------------------------------------------
    virtual void write( BYTE id, BYTE *data, BYTE size );

    //---------------------------------------------------------------
    virtual void writeStream( BYTE  id, 
                              BYTE *data, 
                              BYTE  size, 
                              WORD  crc ) = 0;

  protected: 
    //---------------------------------------------------------------
    cList    list;
    cCRC     crc;

}; //cIPC

#endif
