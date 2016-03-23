//*******************************************************************
/*!
\file   I2Cmaster.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
//
// cHwI2Cmaster
//
//*******************************************************************
//-------------------------------------------------------------------
cHwI2Cmaster::cHwI2Cmaster( BYTE maskIntrIn )
{
  isHardwareOK = true;
  maskIntr     = maskIntrIn;
}

//-------------------------------------------------------------------
BYTE cHwI2Cmaster::Device::read( void )
{
  BYTE dat = 0;

  isErrorFlag |= i2c.read( hwAddr, NULL, 0, &dat, 1 );

  return( dat );
}

//-------------------------------------------------------------------
BYTE cHwI2Cmaster::Device::read( BYTE addr )
{
  BYTE dat = 0;

  isErrorFlag |= i2c.read( hwAddr, &addr, 1, &dat, 1 );

  return( dat );
}

//-------------------------------------------------------------------
BYTE cHwI2Cmaster::Device::read( WORD addr )
{
  BYTE dat        = 0;
  BYTE addrTmp[2] = { (BYTE)(addr>>8),
                      (BYTE)(addr&0xFF) };

  isErrorFlag |= i2c.read( hwAddr, (BYTE *)&addrTmp, 2, &dat, 1 );

  return( dat );
}

//-------------------------------------------------------------------
void cHwI2Cmaster::Device::read( BYTE *data, BYTE size )
{
  isErrorFlag |= i2c.read( hwAddr, NULL, 0, data, size );
}

//-------------------------------------------------------------------
void cHwI2Cmaster::Device::read( BYTE addr, BYTE *data, BYTE size )
{
  isErrorFlag |= i2c.read( hwAddr, &addr, 1, data, size );
}

//-------------------------------------------------------------------
void cHwI2Cmaster::Device::read( WORD addr, BYTE *data, BYTE size )
{
  BYTE addrTmp[2] = { (BYTE)(addr>>8),
                      (BYTE)(addr&0xFF) };

  isErrorFlag |= i2c.read( hwAddr, addrTmp, 2, data, size );
}

//-------------------------------------------------------------------
void cHwI2Cmaster::Device::write( BYTE data )
{
  isErrorFlag |= i2c.write( hwAddr, &data, 1, NULL, 0 );
}

//-------------------------------------------------------------------
void cHwI2Cmaster::Device::write( BYTE addr, BYTE data )
{
  isErrorFlag |= i2c.write( hwAddr, &addr, 1, &data, 1 );
}

//-------------------------------------------------------------------
void cHwI2Cmaster::Device::write( WORD addr, BYTE data )
{
  BYTE addrTmp[2] = { (BYTE)(addr>>8),
                      (BYTE)(addr&0xFF) };

  isErrorFlag |= i2c.write( hwAddr, (BYTE*)&addrTmp, 2, &data, 1 );
}

//-------------------------------------------------------------------
void cHwI2Cmaster::Device::write( BYTE *data, BYTE size )
{
  isErrorFlag |= i2c.write( hwAddr, data, size, NULL, 0 );
}

//-------------------------------------------------------------------
void cHwI2Cmaster::Device::write( BYTE addr, BYTE *data, BYTE size )
{
  isErrorFlag |= i2c.write( hwAddr, &addr, 1, data, size );
}

//-------------------------------------------------------------------
void cHwI2Cmaster::Device::write( WORD addr, BYTE *data, BYTE size )
{
  BYTE addrTmp[2] = { (BYTE)(addr>>8),
                      (BYTE)(addr&0xFF) };

  isErrorFlag |= i2c.write( hwAddr, addrTmp, 2, data, size );
}

//-------------------------------------------------------------------
BYTE cHwI2Cmaster::Device::isError( void )
{
  BYTE ret = isErrorFlag;

  isErrorFlag = false;

  return( ret );
}

//-------------------------------------------------------------------
BYTE cHwI2Cmaster::write( BYTE  hwAddr,
                          BYTE *adr,
                          BYTE  sizeAdr,
                          BYTE *data,
                          BYTE  sizeData )
{

  BYTE i = 0;
  isHardwareOK = true;

  if( maskIntr )
    cSystem::disableInterrupt();

  if( sizeAdr || sizeData )
  {
    start();
    sendAddr( hwAddr ); // master write
    for( i=0; i< sizeAdr; i++ )
    {
       writeByte( adr[i] );
    }
    for( i=0; i< sizeData; i++ )
    {
       writeByte( data[i] );
    }
  }

  stop();

  if( maskIntr )
    cSystem::enableInterrupt();


  return( !isHardwareOK );
}

//-------------------------------------------------------------------
BYTE cHwI2Cmaster::read( BYTE  hwAddr,
                         BYTE *adr,
                         BYTE  sizeAdr,
                         BYTE *data,
                         BYTE  sizeData )
{
  BYTE i = 0;
  
  isHardwareOK = true;

  if( maskIntr )
    cSystem::disableInterrupt();

  if( sizeAdr )
  {
    start();
    sendAddr( hwAddr ); // master write
    for( i=0; i< sizeAdr; i++ )
    {
       writeByte( adr[i] );
    }
  }

  if( sizeData )
  {
    start();
    sendAddr( hwAddr | 0x01 ); // master read
    for( i=0; i < sizeData - 1; i++ )
    {
      data[i] = readByteAck();
    }
    data[i] = readByteNack();
  }

  stop();

  if( maskIntr )
    cSystem::enableInterrupt();

  return( !isHardwareOK );
}

//EOF
