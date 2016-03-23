//*******************************************************************
/*!
\file   Std/cTimer.cpp
\author Thomas Breuer
\date   31.01.2013, 22.03.2016
\brief  Sample
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
class cTask_Example : public cTaskHandler::Task
{
  public:
    //---------------------------------------------------------------
    cTask_Example( cTaskHandler &taskHandler )

    : Task  ( taskHandler       ),
      timerA( taskHandler       ),
      timerB( taskHandler, 1000 )
      //----------------------------
    {
      cntA = 0;
      cntB = 0;
      timerA.start(100);
    }

  private:
    //---------------------------------------------------------------
    virtual void update( void )
    {
      if( timerA.timeout() )
          //-----------------
      {
        timerA.start(100);
        cntA += 1;
      }
      
      if( timerB.timeout() )
          //-----------------
      {
        cntB += 10;
      }
    }

  private:
    //---------------------------------------------------------------
  cTaskHandler::Timer timerA;
  cTaskHandler::Timer timerB;
    //-------------------

  public:
    //---------------------------------------------------------------
    WORD cntA;
    WORD cntB;
};

//*******************************************************************
cTaskHandler   taskHandler( &timer      );
cTask_Example  task       ( taskHandler );
  
//*******************************************************************
int main(void)
{
  com.printf( "\r\n\n" __FILE__ "," __DATE__ "," __TIME__ "\r\n\n" );

  cTaskHandler::Timer timerMain( taskHandler );

  while( 1 )
  {
    if( timerMain.timeout( 10000 ) )
    {
      task.cntA = 0;
      task.cntB = 0;
    }
    
    com.printf( "cntA,cntB: %3d,%3d\r", task.cntA, task.cntB );
  }
}
