//*******************************************************************
/*!
\file   Std/cSharedMemory.cpp
\author Thomas Breuer
\date   31.01.2013, 22.03.2016
\brief  Sample
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
class cData
{
  public:
    //---------------------------------------------------------------
    WORD dataA;
    WORD dataB;
};

//*******************************************************************
class cTest : public cList::Item
{
  public:
    //---------------------------------------------------------------
    cTest( cHwTimer &timer, cSharedMem<cData> &shmIn )
    : shm(shmIn)
    {
      timer.add( this );
    }

    //---------------------------------------------------------------
    virtual void update( void )
    {
      //-------
      shm >> Y;
      //-------
      
      // check, if data ok
      if( Y.dataA != Y.dataB )
      {
        cSystem::reset();
      }
    }

    //---------------------------------------------------------------
    cData              Y;
    cSharedMem<cData> &shm;
};

//*******************************************************************
cData             X;
cSharedMem<cData> shm;
cTest             test( timer, shm );

//*******************************************************************
int main(void)
{
  com.printf( "\r\n\n" __FILE__ "," __DATE__ "," __TIME__ "\r\n\n" );
  com.printf( "running ...\r\n" );

  BYTE error = 0;

  while( 1 )
  {
    sys.run();

    if( com.getString() ) // press ENTER to induce an error
    {
      error = 1;
    }
    
    X.dataA = rand();
    X.dataB = X.dataA + error;

    //-------
    shm << X;
    //-------
  }
}
