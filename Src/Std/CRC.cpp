//*******************************************************************
/*!
\file   CRC.cpp
\author Thomas Breuer
\date   11.03.2011
*/

//*******************************************************************
#include "CRC.h"

//*******************************************************************
//
// cCRC
//
//*******************************************************************
//-------------------------------------------------------------------
cCRC::cCRC( MODE mode, 
            WORD startCRC_In,
            WORD generatorPolynomIn )
{
  startCRC         = startCRC_In;
  generatorPolynom = generatorPolynomIn;
  
  if( mode == FAST )
  {
    tabArray = new WORD[256];

    for( WORD i = 0; i < 256 && tabArray; i++ )
    {
      tabArray[i] = tabMethod( i );
    }
  }
  else 
  {
    tabArray = NULL;
  }
}

//-------------------------------------------------------------------
cCRC::~cCRC( void )
{
  if( tabArray )
  {
    delete tabArray;
  }
}

//-------------------------------------------------------------------
WORD cCRC::operator()( const BYTE *ptr,
                       const BYTE  size )
{
  WORD crc = startCRC;

  for( BYTE i = 0; i < size; i++ )
  {
    BYTE idx = ( *(ptr++) ) ^ crc;

    if( tabArray )
    {
      crc = (crc>>8) ^ tabArray[idx];
    }
    else
    {
      crc = (crc>>8) ^ tabMethod( idx );
    }
  }
  return( crc );
}

//-------------------------------------------------------------------
inline WORD cCRC::tabMethod( BYTE idx )
{
  WORD crc = 0;

  for( BYTE bit = 0; bit < 8; bit++ )
  {
    if( (crc^idx) & 0x01 )
    {
      crc = (crc>>1) ^ generatorPolynom;
    }
    else
    {
      crc = (crc>>1);
    }
    idx = (idx>>1);
  }
  return( crc );
}

// EOF
