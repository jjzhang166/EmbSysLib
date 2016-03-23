//*******************************************************************
/*!
\file   cRTOS.cpp
\author Thomas Breuer
\date   18.03.2016
\brief  RTOS sample code
*/

//*******************************************************************
#include "lib.h"
#include "Module/RTOS.h"
#include "config.h"

//*******************************************************************
class myRtosTask : public cRTOS::Task
{
  public:
    //---------------------------------------------------------------
    myRtosTask(cRTOS &rtosIn )
  
    : cRTOS::Task( rtosIn, 500/* stack size*/ )

  {
      c   = 0;
      t   = 0;
      sec = 0;
      Start();
    }

    //---------------------------------------------------------------
    virtual ~myRtosTask()
    {
    }

    //---------------------------------------------------------------
    virtual void update( )
    {
      while( 1 )
      {
        t++;
        Pause( 10 );
        if( timer.timeout() )
        {
          sec++;
        }
      }
    }

    //---------------------------------------------------------------
    virtual void OnStop(void)
    {
    }

    //---------------------------------------------------------------
    virtual void OnStart(void)
    {
      c++;
      t = 0;
      timer.start( 1000 );
    }

    //---------------------------------------------------------------
    int   t;
    int   sec;
    int   c;
    
    cRTOS::Timer timer;
};


//*******************************************************************
cRTOS_RR<3> rtos( 1000/*time per task [ms]*/ );

myRtosTask  task1( rtos );
myRtosTask  task2( rtos );

//*******************************************************************
int main(void)
{
  com.printf( "\r\n\n" __FILE__ "," __DATE__ "," __TIME__ "\r\n\n" );

  task1.Start();
  task2.Start();

  while( 1 )
  {
    com.printf("Task1:%6d Task2:%6d,%d\r", task1.t, 
                                           task2.t, 
                                           task2.sec );

    if( task1.t > 1000L )
    {
      task1.Stop();
      task1.Start();
    }
  }
}

//EOF
