//*******************************************************************
/*!
\file   cHwRTOS.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes

*/

//*******************************************************************
#include <stdio.h>

//*******************************************************************
char str[100];

#define NUM_OF_TASKS    3
#define STACKSIZE     500

//*******************************************************************
class myRTOS
{
  public:
    //---------------------------------------------------------------   
    //---------------------------------------------------------------   
    class Task
    {
      public:
        //-----------------------------------------------------------
        Task( BYTE idIn )
        {
          id = idIn;
        }
        
        //-----------------------------------------------------------   
        static DWORD starter( void *ptr )
        {         
          ((myRTOS::Task*)ptr)->update();
          while(1); // The task should never end
        }
        
        //-----------------------------------------------------------   
        virtual void update( void ) = 0;

        //-----------------------------------------------------------   
        char stack[STACKSIZE];
        BYTE id;
        
    }; // class Task
    
  public:
    //---------------------------------------------------------------
    myRTOS( WORD us )
    {
      currentTask = 0;
      nextTask    = 0;
      ptr         = this;      
      
      for( BYTE i=0; i<NUM_OF_TASKS; i++ )
      {
        stackPtrList[i] = 0;
      }     
      cHwRTOS_MCU::init( us/NUM_OF_TASKS, schedule );
    }

    //---------------------------------------------------------------
    void start( Task &task )
    {
      stackPtrList[task.id] = cHwRTOS_MCU::start( task.stack,
                                                  STACKSIZE,
                                                  &task,
                                                  task.starter );
    }
    
    //---------------------------------------------------------------
    void stop( Task &task )
    { 
      stackPtrList[task.id] = 0;
    }
    
    //---------------------------------------------------------------
    BYTE isRunning( Task &task )
    {
      return( stackPtrList[task.id] != 0 );
    }

  private:
    //---------------------------------------------------------------
    unsigned scheduler( unsigned stackPtr, 
                        BYTE     isSysTic )
    {
      stackPtrList[currentTask] = stackPtr;
      currentTask               = 0;
      
      if( isSysTic ) // called by timeout
      {
        nextTask = (nextTask+1) % NUM_OF_TASKS;
        if( stackPtrList[nextTask] )
        {
          currentTask = nextTask;
        }
      }
      return( stackPtrList[currentTask] );
    }
 
    //---------------------------------------------------------------
    static DWORD schedule( DWORD sp, BYTE flag )
    {
      return( ptr->scheduler(sp, flag) );
    }

  private:
    //---------------------------------------------------------------
    BYTE   currentTask;
    BYTE   nextTask;
    DWORD  stackPtrList[NUM_OF_TASKS];
     
    static myRTOS *ptr;

};

myRTOS  * myRTOS::ptr = NULL;
    
//*******************************************************************
class myTask : public myRTOS::Task
{
  public:
    //---------------------------------------------------------------
    myTask( BYTE id )
    : myRTOS::Task( id )
    {
      cnt = 0;
    }

  private:
    //---------------------------------------------------------------
    virtual void update( void )
    {
      while(1)
      {
        cnt++;
        cHwRTOS_MCU::pause();
      }
    }

  public:
    //---------------------------------------------------------------
    DWORD cnt;
    
}; // class myTask

//*******************************************************************
myTask  task1( 1 );
myTask  task2( 2 );
myRTOS  rtos ( 1000/*us*/ );

//*******************************************************************
int main(void)
{
  DWORD cnt = 0;
  DWORD timeout = 1000 /*ms*/;
  
  uart.set( "\r\n\ncHwRTOS,"__DATE__ ","__TIME__"\r\n\n" );
  
  rtos.start( task1 );
  rtos.start( task2 );
  
  while( 1 )
  {
    DWORD time = cHwRTOS_MCU::getSysTime();
       
    if( time >= timeout )
    { 
      sprintf( str, "time:%6u, main:%6u, task1:%6u, task2:%6u\r\n",
                    time, 
                    cnt++, 
                    task1.cnt, 
                    task2.cnt);
      uart.set( str );
      
      timeout += 1000;
      
      if( rtos.isRunning( task1 ) )
      {
        rtos.stop( task1 );
        task1.cnt = 0;
      }
      else
      {  
        rtos.start( task1 );
      }  
    }        
  }
}
