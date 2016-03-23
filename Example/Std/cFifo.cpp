//*******************************************************************
/*!
\file   Std/cFifo.cpp
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
    cTest( cHwTimer &timer, cFifo<cData> &fifoIn )
    : fifo( fifoIn )
    {
      timer.add( this );
    }

    //---------------------------------------------------------------
    virtual void update( void )
    {
      //--------
      fifo >> Y;
      //--------
      
      // check, if data ok
      if( Y.dataA != Y.dataB )
      {
        cSystem::reset();
      }
    }

    //---------------------------------------------------------------
    cData         Y;
    cFifo<cData> &fifo;
};

//*******************************************************************
cData        X;
cFifo<cData> fifo(10);
cTest        test( timer, fifo );

//*******************************************************************
int main(void)
{
  com.printf( "\r\n\n" __FILE__ "," __DATE__ "," __TIME__ "\r\n\n" );
  com.printf( "running ...\r\n" );

  while( 1 )
  {
    sys.run();
    
    if( !fifo.isFull() )
    {
      X.dataA = rand();
      X.dataB = X.dataA;
  
      if( com.getString() ) // press ENTER to induce an error
      {
        X.dataA++;
      }
      
      //--------
      fifo << X;
      //--------
    }
  }
}
