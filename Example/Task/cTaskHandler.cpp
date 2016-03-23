//*******************************************************************
/*!
\file   cTask.cpp
\author Thomas Breuer
\date   31.01.2013, 19.03.2016
\brief  Sample TaskHandler
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

    : Task( taskHandler )

    {
      cnt = 0;
    }

  private:
    //---------------------------------------------------------------
    virtual void update( void )
    {
      cnt++;
    }

  public:
    //---------------------------------------------------------------
    DWORD cnt;
};


//*******************************************************************
// Create some task handler
cTaskHandler taskHandlerSlow( &timerSlow );
cTaskHandler taskHandlerFast( &timerFast );
cTaskHandler taskHandlerIdle;

//*******************************************************************
// Here are four tasks
cTask_Example taskFast ( taskHandlerFast );
cTask_Example taskSlow0( taskHandlerSlow );
cTask_Example taskSlow1( taskHandlerSlow );
cTask_Example taskIdle ( taskHandlerIdle );

//*******************************************************************
int main(void)
{
  com.printf( "\r\n\n" __FILE__ "," __DATE__ "," __TIME__ "\r\n\n" );
  com.printf( "Idle   Slow0  Slow1  Fast\r\n" );

  while(1)
  {
    taskHandlerIdle.run();

    if( (taskIdle.cnt%10) == 0 )
    {
      com.printf( "%5d  %5d  %5d  %5d \r", taskIdle.cnt, 
                                           taskSlow0.cnt, 
                                           taskSlow1.cnt, 
                                           taskFast.cnt );
    }
  }
}
