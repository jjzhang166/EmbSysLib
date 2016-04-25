//*******************************************************************
/*!
\file   devMemory.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   18.10.2013, 23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
//
// cDevMemory
//
//*******************************************************************
//-------------------------------------------------------------------
cDevMemory::cDevMemory( cHwMemory &memIn,
                        WORD       addrIn )

: mem( memIn )

{
  addr   = addrIn;
  pos    = 1; // first position is reserved for valid flag
}

//-------------------------------------------------------------------
WORD cDevMemory::allocate( WORD size )
{
  WORD ret = pos;

  pos += size;  //! \todo check, if pos exceeds memory size
  return( ret );
}

//-------------------------------------------------------------------
void cDevMemory::write( BYTE *data,
                        WORD  size,
                        WORD  offs )
{
  for( WORD i = 0; i < size; i++ )
  {
    mem.write( addr+offs+i, data[i] );
  }
}

//-------------------------------------------------------------------
void cDevMemory::read( BYTE *data,
                       WORD  size,
                       WORD  offs )
{
  for( WORD i = 0; i < size; i++ )
  {
    data[i] = mem.read( addr+offs+i );
  }
}

//-------------------------------------------------------------------
void cDevMemory::clear( void )
{
  mem.clear();
}

//-------------------------------------------------------------------
void cDevMemory::setValid( void )
{
  mem.write( addr, 0x55 );
}

//-------------------------------------------------------------------
BYTE cDevMemory::isValid( void )
{
  return( ( mem.read( addr ) == 0x55 ) ? true : false );
}

//EOF
